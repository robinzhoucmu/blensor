#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <string>

using namespace std;


int
 main (int argc, char** argv)
{
  bool binary = false;

  pcl::PointCloud<pcl::PointXYZ> *cloud1(new  pcl::PointCloud<pcl::PointXYZ>());
  pcl::PointCloud<pcl::PointXYZ> cloud2;
  pcl::PointCloud<pcl::PointXYZ> outputCloud;
  pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud1_ptr(cloud1);



  pcl::PCDReader reader;
  reader.read(string(argv[1]),*cloud1);
  reader.read(string(argv[2]),cloud2);
  if (argc > 3)
  {
    if (string(argv[3]) == "binary") binary = true;
  } 


  *cloud1 += cloud2;

  
  pcl::PCDWriter writer;
  cout << "Writing to " << argv[3] << endl;
  writer.write(string(argv[3]), *cloud1, binary);
  cout << "Finished"<<endl;
  return (0);
}
