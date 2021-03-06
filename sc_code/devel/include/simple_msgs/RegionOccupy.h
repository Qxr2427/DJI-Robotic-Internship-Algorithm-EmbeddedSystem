// Generated by gencpp from file simple_msgs/RegionOccupy.msg
// DO NOT EDIT!


#ifndef SIMPLE_MSGS_MESSAGE_REGIONOCCUPY_H
#define SIMPLE_MSGS_MESSAGE_REGIONOCCUPY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace simple_msgs
{
template <class ContainerAllocator>
struct RegionOccupy_
{
  typedef RegionOccupy_<ContainerAllocator> Type;

  RegionOccupy_()
    : status(0)
    , belong(0)  {
    }
  RegionOccupy_(const ContainerAllocator& _alloc)
    : status(0)
    , belong(0)  {
  (void)_alloc;
    }



   typedef uint8_t _status_type;
  _status_type status;

   typedef uint8_t _belong_type;
  _belong_type belong;





  typedef boost::shared_ptr< ::simple_msgs::RegionOccupy_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::simple_msgs::RegionOccupy_<ContainerAllocator> const> ConstPtr;

}; // struct RegionOccupy_

typedef ::simple_msgs::RegionOccupy_<std::allocator<void> > RegionOccupy;

typedef boost::shared_ptr< ::simple_msgs::RegionOccupy > RegionOccupyPtr;
typedef boost::shared_ptr< ::simple_msgs::RegionOccupy const> RegionOccupyConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::simple_msgs::RegionOccupy_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::simple_msgs::RegionOccupy_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace simple_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'simple_msgs': ['/home/robomaster/robomaster/sc_code/src/simple_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::simple_msgs::RegionOccupy_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::simple_msgs::RegionOccupy_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simple_msgs::RegionOccupy_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simple_msgs::RegionOccupy_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simple_msgs::RegionOccupy_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simple_msgs::RegionOccupy_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::simple_msgs::RegionOccupy_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b93e8ad8a0004ce2f2e8a04d9cfaa53a";
  }

  static const char* value(const ::simple_msgs::RegionOccupy_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb93e8ad8a0004ce2ULL;
  static const uint64_t static_value2 = 0xf2e8a04d9cfaa53aULL;
};

template<class ContainerAllocator>
struct DataType< ::simple_msgs::RegionOccupy_<ContainerAllocator> >
{
  static const char* value()
  {
    return "simple_msgs/RegionOccupy";
  }

  static const char* value(const ::simple_msgs::RegionOccupy_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::simple_msgs::RegionOccupy_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 status\n\
uint8 belong\n\
";
  }

  static const char* value(const ::simple_msgs::RegionOccupy_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::simple_msgs::RegionOccupy_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.status);
      stream.next(m.belong);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RegionOccupy_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::simple_msgs::RegionOccupy_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::simple_msgs::RegionOccupy_<ContainerAllocator>& v)
  {
    s << indent << "status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.status);
    s << indent << "belong: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.belong);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SIMPLE_MSGS_MESSAGE_REGIONOCCUPY_H
