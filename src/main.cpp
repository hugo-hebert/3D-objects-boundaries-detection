#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <exception>
#include <QRegExp>

#include "linefinding.cpp"

/**
 * @brief FileReader function that reads a txt file to convert it to a pcl::PointCloud
 * @param pathname path of the txt file to parse & convert to a pcl::PointCloud
 * @return ptr to pcl::PointCloud<pcl::PointXYZ>
 */
pcl::PointCloud<pcl::PointXYZ>::Ptr FileReader(std::string pathname){
    //creating a new pointcloud & a QFile from the pathname
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    QFile file (QString(pathname.c_str()) );

    //if we can read the file
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream (&file);
        QString line;
        std::vector<float> px;
        std::vector<float> py;
        std::vector<float> pz;
        //while we still have lines to read
        while(!stream.atEnd()){
            line = stream.readLine();
            QStringList temp = line.split(QRegExp("\\s")); //split using the space char
            std::string test = temp.at(0).toStdString();
            std::string test1 = temp.at(1).toStdString();
            std::string test2 = temp.at(2).toStdString();
            if(!(temp.size() >= 3)){
                //only works with XYZ point clouds
                std::cout << "Problem while reading the file" << endl;
                break;
            }else{
                QString r = temp.at(0);
                px.push_back(r.toFloat());

                r = temp.at(1);
                py.push_back(r.toFloat());

                r = temp.at(2);
                pz.push_back(r.toFloat());
            }
        }
        file.close();

        cloud->clear();
        for(int i=0; i<px.size(); i++){
            pcl::PointXYZ p;
            p.x = px.at(i);
            p.y = py.at(i);
            p.z = pz.at(i);
            cloud->push_back(p);
        }
    }
    std::cout << cloud->size() << std::endl;
    return cloud;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = FileReader("C:\\table.txt");
    lineFindingAlgo(cloud);
    std::cout << cloud->size() << std::endl;
    return a.exec();
}
