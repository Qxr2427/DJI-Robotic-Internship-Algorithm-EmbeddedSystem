; Auto-generated. Do not edit!


(cl:in-package simple_msgs-msg)


;//! \htmlinclude CastleEnergy.msg.html

(cl:defclass <CastleEnergy> (roslisp-msg-protocol:ros-message)
  ((red_energy
    :reader red_energy
    :initarg :red_energy
    :type cl:fixnum
    :initform 0)
   (blue_energy
    :reader blue_energy
    :initarg :blue_energy
    :type cl:fixnum
    :initform 0))
)

(cl:defclass CastleEnergy (<CastleEnergy>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CastleEnergy>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CastleEnergy)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simple_msgs-msg:<CastleEnergy> is deprecated: use simple_msgs-msg:CastleEnergy instead.")))

(cl:ensure-generic-function 'red_energy-val :lambda-list '(m))
(cl:defmethod red_energy-val ((m <CastleEnergy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:red_energy-val is deprecated.  Use simple_msgs-msg:red_energy instead.")
  (red_energy m))

(cl:ensure-generic-function 'blue_energy-val :lambda-list '(m))
(cl:defmethod blue_energy-val ((m <CastleEnergy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:blue_energy-val is deprecated.  Use simple_msgs-msg:blue_energy instead.")
  (blue_energy m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CastleEnergy>) ostream)
  "Serializes a message object of type '<CastleEnergy>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'red_energy)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'blue_energy)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CastleEnergy>) istream)
  "Deserializes a message object of type '<CastleEnergy>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'red_energy)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'blue_energy)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CastleEnergy>)))
  "Returns string type for a message object of type '<CastleEnergy>"
  "simple_msgs/CastleEnergy")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CastleEnergy)))
  "Returns string type for a message object of type 'CastleEnergy"
  "simple_msgs/CastleEnergy")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CastleEnergy>)))
  "Returns md5sum for a message object of type '<CastleEnergy>"
  "9299551f2d90f96de59e7c55bb10e426")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CastleEnergy)))
  "Returns md5sum for a message object of type 'CastleEnergy"
  "9299551f2d90f96de59e7c55bb10e426")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CastleEnergy>)))
  "Returns full string definition for message of type '<CastleEnergy>"
  (cl:format cl:nil "uint8 red_energy~%uint8 blue_energy~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CastleEnergy)))
  "Returns full string definition for message of type 'CastleEnergy"
  (cl:format cl:nil "uint8 red_energy~%uint8 blue_energy~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CastleEnergy>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CastleEnergy>))
  "Converts a ROS message object to a list"
  (cl:list 'CastleEnergy
    (cl:cons ':red_energy (red_energy msg))
    (cl:cons ':blue_energy (blue_energy msg))
))
