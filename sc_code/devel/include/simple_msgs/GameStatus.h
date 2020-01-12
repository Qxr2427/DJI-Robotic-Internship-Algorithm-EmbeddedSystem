// Generated by gencpp from file simple_msgs/GameStatus.msg
// DO NOT EDIT!


#ifndef SIMPLE_MSGS_MESSAGE_GAMESTATUS_H
#define SIMPLE_MSGS_MESSAGE_GAMESTATUS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <simple_msgs/RegionOccupy.h>
#include <simple_msgs/CastleEnergy.h>

namespace simple_msgs
{
template <class ContainerAllocator>
struct GameStatus_
{
  typedef GameStatus_<ContainerAllocator> Type;

  GameStatus_()
    : region_occupy()
    , castle_energy()
    , red_position(0)
    , blue_position(0)
    , red_step_move(0)
    , blue_step_move(0)
    , red_score(0)
    , blue_score(0)
    , round_remain_tick(0)
    , round_remain_cnt(0)
    , round_team(0)  {
    }
  GameStatus_(const ContainerAllocator& _alloc)
    : region_occupy(_alloc)
    , castle_energy(_alloc)
    , red_position(0)
    , blue_position(0)
    , red_step_move(0)
    , blue_step_move(0)
    , red_score(0)
    , blue_score(0)
    , round_remain_tick(0)
    , round_remain_cnt(0)
    , round_team(0)  {
  (void)_alloc;
    }



   typedef std::vector< ::simple_msgs::RegionOccupy_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::simple_msgs::RegionOccupy_<ContainerAllocator> >::other >  _region_occupy_type;
  _region_occupy_type region_occupy;

   typedef std::vector< ::simple_msgs::CastleEnergy_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::simple_msgs::CastleEnergy_<ContainerAllocator> >::other >  _castle_energy_type;
  _castle_energy_type castle_energy;

   typedef uint8_t _red_position_type;
  _red_position_type red_position;

   typedef uint8_t _blue_position_type;
  _blue_position_type blue_position;

   typedef uint8_t _red_step_move_type;
  _red_step_move_type red_step_move;

   typedef uint8_t _blue_step_move_type;
  _blue_step_move_type blue_step_move;

   typedef int16_t _red_score_type;
  _red_score_type red_score;

   typedef int16_t _blue_score_type;
  _blue_score_type blue_score;

   typedef uint8_t _round_remain_tick_type;
  _round_remain_tick_type round_remain_tick;

   typedef uint8_t _round_remain_cnt_type;
  _round_remain_cnt_type round_remain_cnt;

   typedef uint8_t _round_team_type;
  _round_team_type round_team;





  typedef boost::shared_ptr< ::simple_msgs::GameStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::simple_msgs::GameStatus_<ContainerAllocator> const> ConstPtr;

}; // struct GameStatus_

typedef ::simple_msgs::GameStatus_<std::allocator<void> > GameStatus;

typedef boost::shared_ptr< ::simple_msgs::GameStatus > GameStatusPtr;
typedef boost::shared_ptr< ::simple_msgs::GameStatus const> GameStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::simple_msgs::GameStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::simple_msgs::GameStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace simple_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'simple_msgs': ['/home/robomaster/robomaster/sc_code/src/simple_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::simple_msgs::GameStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::simple_msgs::GameStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simple_msgs::GameStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simple_msgs::GameStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simple_msgs::GameStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simple_msgs::GameStatus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::simple_msgs::GameStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3c1a9bf389a73be248100bdba5d1e8fd";
  }

  static const char* value(const ::simple_msgs::GameStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3c1a9bf389a73be2ULL;
  static const uint64_t static_value2 = 0x48100bdba5d1e8fdULL;
};

template<class ContainerAllocator>
struct DataType< ::simple_msgs::GameStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "simple_msgs/GameStatus";
  }

  static const char* value(const ::simple_msgs::GameStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::simple_msgs::GameStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "RegionOccupy[] region_occupy\n\
CastleEnergy[] castle_energy\n\
uint8 red_position\n\
uint8 blue_position\n\
uint8 red_step_move\n\
uint8 blue_step_move\n\
int16 red_score\n\
int16 blue_score\n\
uint8 round_remain_tick\n\
uint8 round_remain_cnt\n\
uint8 round_team\n\
\n\
================================================================================\n\
MSG: simple_msgs/RegionOccupy\n\
uint8 status\n\
uint8 belong\n\
\n\
================================================================================\n\
MSG: simple_msgs/CastleEnergy\n\
uint8 red_energy\n\
uint8 blue_energy\n\
";
  }

  static const char* value(const ::simple_msgs::GameStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::simple_msgs::GameStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.region_occupy);
      stream.next(m.castle_energy);
      stream.next(m.red_position);
      stream.next(m.blue_position);
      stream.next(m.red_step_move);
      stream.next(m.blue_step_move);
      stream.next(m.red_score);
      stream.next(m.blue_score);
      stream.next(m.round_remain_tick);
      stream.next(m.round_remain_cnt);
      stream.next(m.round_team);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GameStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::simple_msgs::GameStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::simple_msgs::GameStatus_<ContainerAllocator>& v)
  {
    s << indent << "region_occupy[]" << std::endl;
    for (size_t i = 0; i < v.region_occupy.size(); ++i)
    {
      s << indent << "  region_occupy[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::simple_msgs::RegionOccupy_<ContainerAllocator> >::stream(s, indent + "    ", v.region_occupy[i]);
    }
    s << indent << "castle_energy[]" << std::endl;
    for (size_t i = 0; i < v.castle_energy.size(); ++i)
    {
      s << indent << "  castle_energy[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::simple_msgs::CastleEnergy_<ContainerAllocator> >::stream(s, indent + "    ", v.castle_energy[i]);
    }
    s << indent << "red_position: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.red_position);
    s << indent << "blue_position: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.blue_position);
    s << indent << "red_step_move: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.red_step_move);
    s << indent << "blue_step_move: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.blue_step_move);
    s << indent << "red_score: ";
    Printer<int16_t>::stream(s, indent + "  ", v.red_score);
    s << indent << "blue_score: ";
    Printer<int16_t>::stream(s, indent + "  ", v.blue_score);
    s << indent << "round_remain_tick: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.round_remain_tick);
    s << indent << "round_remain_cnt: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.round_remain_cnt);
    s << indent << "round_team: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.round_team);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SIMPLE_MSGS_MESSAGE_GAMESTATUS_H
