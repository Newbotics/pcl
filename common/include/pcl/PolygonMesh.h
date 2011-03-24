/* Auto-generated by genmsg_cpp for file /work/ros/pkgs-trunk/point_cloud_perception/pcl/msg/PolygonMesh.msg */
#ifndef PCL_MESSAGE_POLYGONMESH_H
#define PCL_MESSAGE_POLYGONMESH_H
#include <string>
#include <vector>
#include <ostream>

// Include the correct Header path here
#include "std_msgs/Header.h"
#include "sensor_msgs/PointCloud2.h"
#include "pcl/Vertices.h"

namespace pcl
{
  template <class ContainerAllocator>
  struct PolygonMesh_ 
  {
    typedef PolygonMesh_<ContainerAllocator> Type;

    PolygonMesh_()
    : header()
    , cloud()
    , polygons()
    {
    }

    PolygonMesh_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , cloud(_alloc)
    , polygons(_alloc)
    {
    }

    typedef ::std_msgs::Header_<ContainerAllocator>  _header_type;
    ::std_msgs::Header_<ContainerAllocator>  header;

    typedef ::sensor_msgs::PointCloud2_<ContainerAllocator>  _cloud_type;
    ::sensor_msgs::PointCloud2_<ContainerAllocator>  cloud;

    typedef std::vector< ::pcl::Vertices_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::pcl::Vertices_<ContainerAllocator> >::other >  _polygons_type;
    std::vector< ::pcl::Vertices_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::pcl::Vertices_<ContainerAllocator> >::other >  polygons;


  public:
    typedef boost::shared_ptr< ::pcl::PolygonMesh_<ContainerAllocator> > Ptr;
    typedef boost::shared_ptr< ::pcl::PolygonMesh_<ContainerAllocator>  const> ConstPtr;
  }; // struct PolygonMesh
  typedef  ::pcl::PolygonMesh_<std::allocator<void> > PolygonMesh;

  typedef boost::shared_ptr< ::pcl::PolygonMesh> PolygonMeshPtr;
  typedef boost::shared_ptr< ::pcl::PolygonMesh const> PolygonMeshConstPtr;

} // namespace pcl

#endif // PCL_MESSAGE_POLYGONMESH_H

