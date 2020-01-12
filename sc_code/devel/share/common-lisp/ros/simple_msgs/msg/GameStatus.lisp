; Auto-generated. Do not edit!


(cl:in-package simple_msgs-msg)


;//! \htmlinclude GameStatus.msg.html

(cl:defclass <GameStatus> (roslisp-msg-protocol:ros-message)
  ((region_occupy
    :reader region_occupy
    :initarg :region_occupy
    :type (cl:vector simple_msgs-msg:RegionOccupy)
   :initform (cl:make-array 0 :element-type 'simple_msgs-msg:RegionOccupy :initial-element (cl:make-instance 'simple_msgs-msg:RegionOccupy)))
   (castle_energy
    :reader castle_energy
    :initarg :castle_energy
    :type (cl:vector simple_msgs-msg:CastleEnergy)
   :initform (cl:make-array 0 :element-type 'simple_msgs-msg:CastleEnergy :initial-element (cl:make-instance 'simple_msgs-msg:CastleEnergy)))
   (red_position
    :reader red_position
    :initarg :red_position
    :type cl:fixnum
    :initform 0)
   (blue_position
    :reader blue_position
    :initarg :blue_position
    :type cl:fixnum
    :initform 0)
   (red_step_move
    :reader red_step_move
    :initarg :red_step_move
    :type cl:fixnum
    :initform 0)
   (blue_step_move
    :reader blue_step_move
    :initarg :blue_step_move
    :type cl:fixnum
    :initform 0)
   (red_score
    :reader red_score
    :initarg :red_score
    :type cl:fixnum
    :initform 0)
   (blue_score
    :reader blue_score
    :initarg :blue_score
    :type cl:fixnum
    :initform 0)
   (round_remain_tick
    :reader round_remain_tick
    :initarg :round_remain_tick
    :type cl:fixnum
    :initform 0)
   (round_remain_cnt
    :reader round_remain_cnt
    :initarg :round_remain_cnt
    :type cl:fixnum
    :initform 0)
   (round_team
    :reader round_team
    :initarg :round_team
    :type cl:fixnum
    :initform 0))
)

(cl:defclass GameStatus (<GameStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GameStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GameStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simple_msgs-msg:<GameStatus> is deprecated: use simple_msgs-msg:GameStatus instead.")))

(cl:ensure-generic-function 'region_occupy-val :lambda-list '(m))
(cl:defmethod region_occupy-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:region_occupy-val is deprecated.  Use simple_msgs-msg:region_occupy instead.")
  (region_occupy m))

(cl:ensure-generic-function 'castle_energy-val :lambda-list '(m))
(cl:defmethod castle_energy-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:castle_energy-val is deprecated.  Use simple_msgs-msg:castle_energy instead.")
  (castle_energy m))

(cl:ensure-generic-function 'red_position-val :lambda-list '(m))
(cl:defmethod red_position-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:red_position-val is deprecated.  Use simple_msgs-msg:red_position instead.")
  (red_position m))

(cl:ensure-generic-function 'blue_position-val :lambda-list '(m))
(cl:defmethod blue_position-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:blue_position-val is deprecated.  Use simple_msgs-msg:blue_position instead.")
  (blue_position m))

(cl:ensure-generic-function 'red_step_move-val :lambda-list '(m))
(cl:defmethod red_step_move-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:red_step_move-val is deprecated.  Use simple_msgs-msg:red_step_move instead.")
  (red_step_move m))

(cl:ensure-generic-function 'blue_step_move-val :lambda-list '(m))
(cl:defmethod blue_step_move-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:blue_step_move-val is deprecated.  Use simple_msgs-msg:blue_step_move instead.")
  (blue_step_move m))

(cl:ensure-generic-function 'red_score-val :lambda-list '(m))
(cl:defmethod red_score-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:red_score-val is deprecated.  Use simple_msgs-msg:red_score instead.")
  (red_score m))

(cl:ensure-generic-function 'blue_score-val :lambda-list '(m))
(cl:defmethod blue_score-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:blue_score-val is deprecated.  Use simple_msgs-msg:blue_score instead.")
  (blue_score m))

(cl:ensure-generic-function 'round_remain_tick-val :lambda-list '(m))
(cl:defmethod round_remain_tick-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:round_remain_tick-val is deprecated.  Use simple_msgs-msg:round_remain_tick instead.")
  (round_remain_tick m))

(cl:ensure-generic-function 'round_remain_cnt-val :lambda-list '(m))
(cl:defmethod round_remain_cnt-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:round_remain_cnt-val is deprecated.  Use simple_msgs-msg:round_remain_cnt instead.")
  (round_remain_cnt m))

(cl:ensure-generic-function 'round_team-val :lambda-list '(m))
(cl:defmethod round_team-val ((m <GameStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:round_team-val is deprecated.  Use simple_msgs-msg:round_team instead.")
  (round_team m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GameStatus>) ostream)
  "Serializes a message object of type '<GameStatus>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'region_occupy))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'region_occupy))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'castle_energy))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'castle_energy))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'red_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'blue_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'red_step_move)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'blue_step_move)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'red_score)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'blue_score)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'round_remain_tick)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'round_remain_cnt)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'round_team)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GameStatus>) istream)
  "Deserializes a message object of type '<GameStatus>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'region_occupy) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'region_occupy)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'simple_msgs-msg:RegionOccupy))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'castle_energy) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'castle_energy)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'simple_msgs-msg:CastleEnergy))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'red_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'blue_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'red_step_move)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'blue_step_move)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'red_score) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'blue_score) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'round_remain_tick)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'round_remain_cnt)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'round_team)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GameStatus>)))
  "Returns string type for a message object of type '<GameStatus>"
  "simple_msgs/GameStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GameStatus)))
  "Returns string type for a message object of type 'GameStatus"
  "simple_msgs/GameStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GameStatus>)))
  "Returns md5sum for a message object of type '<GameStatus>"
  "3c1a9bf389a73be248100bdba5d1e8fd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GameStatus)))
  "Returns md5sum for a message object of type 'GameStatus"
  "3c1a9bf389a73be248100bdba5d1e8fd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GameStatus>)))
  "Returns full string definition for message of type '<GameStatus>"
  (cl:format cl:nil "RegionOccupy[] region_occupy~%CastleEnergy[] castle_energy~%uint8 red_position~%uint8 blue_position~%uint8 red_step_move~%uint8 blue_step_move~%int16 red_score~%int16 blue_score~%uint8 round_remain_tick~%uint8 round_remain_cnt~%uint8 round_team~%~%================================================================================~%MSG: simple_msgs/RegionOccupy~%uint8 status~%uint8 belong~%~%================================================================================~%MSG: simple_msgs/CastleEnergy~%uint8 red_energy~%uint8 blue_energy~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GameStatus)))
  "Returns full string definition for message of type 'GameStatus"
  (cl:format cl:nil "RegionOccupy[] region_occupy~%CastleEnergy[] castle_energy~%uint8 red_position~%uint8 blue_position~%uint8 red_step_move~%uint8 blue_step_move~%int16 red_score~%int16 blue_score~%uint8 round_remain_tick~%uint8 round_remain_cnt~%uint8 round_team~%~%================================================================================~%MSG: simple_msgs/RegionOccupy~%uint8 status~%uint8 belong~%~%================================================================================~%MSG: simple_msgs/CastleEnergy~%uint8 red_energy~%uint8 blue_energy~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GameStatus>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'region_occupy) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'castle_energy) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     1
     1
     1
     1
     2
     2
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GameStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'GameStatus
    (cl:cons ':region_occupy (region_occupy msg))
    (cl:cons ':castle_energy (castle_energy msg))
    (cl:cons ':red_position (red_position msg))
    (cl:cons ':blue_position (blue_position msg))
    (cl:cons ':red_step_move (red_step_move msg))
    (cl:cons ':blue_step_move (blue_step_move msg))
    (cl:cons ':red_score (red_score msg))
    (cl:cons ':blue_score (blue_score msg))
    (cl:cons ':round_remain_tick (round_remain_tick msg))
    (cl:cons ':round_remain_cnt (round_remain_cnt msg))
    (cl:cons ':round_team (round_team msg))
))
