; Auto-generated. Do not edit!


(cl:in-package simple_msgs-msg)


;//! \htmlinclude RegionOccupy.msg.html

(cl:defclass <RegionOccupy> (roslisp-msg-protocol:ros-message)
  ((status
    :reader status
    :initarg :status
    :type cl:fixnum
    :initform 0)
   (belong
    :reader belong
    :initarg :belong
    :type cl:fixnum
    :initform 0))
)

(cl:defclass RegionOccupy (<RegionOccupy>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RegionOccupy>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RegionOccupy)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simple_msgs-msg:<RegionOccupy> is deprecated: use simple_msgs-msg:RegionOccupy instead.")))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <RegionOccupy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:status-val is deprecated.  Use simple_msgs-msg:status instead.")
  (status m))

(cl:ensure-generic-function 'belong-val :lambda-list '(m))
(cl:defmethod belong-val ((m <RegionOccupy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_msgs-msg:belong-val is deprecated.  Use simple_msgs-msg:belong instead.")
  (belong m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RegionOccupy>) ostream)
  "Serializes a message object of type '<RegionOccupy>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'belong)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RegionOccupy>) istream)
  "Deserializes a message object of type '<RegionOccupy>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'belong)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RegionOccupy>)))
  "Returns string type for a message object of type '<RegionOccupy>"
  "simple_msgs/RegionOccupy")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RegionOccupy)))
  "Returns string type for a message object of type 'RegionOccupy"
  "simple_msgs/RegionOccupy")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RegionOccupy>)))
  "Returns md5sum for a message object of type '<RegionOccupy>"
  "b93e8ad8a0004ce2f2e8a04d9cfaa53a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RegionOccupy)))
  "Returns md5sum for a message object of type 'RegionOccupy"
  "b93e8ad8a0004ce2f2e8a04d9cfaa53a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RegionOccupy>)))
  "Returns full string definition for message of type '<RegionOccupy>"
  (cl:format cl:nil "uint8 status~%uint8 belong~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RegionOccupy)))
  "Returns full string definition for message of type 'RegionOccupy"
  (cl:format cl:nil "uint8 status~%uint8 belong~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RegionOccupy>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RegionOccupy>))
  "Converts a ROS message object to a list"
  (cl:list 'RegionOccupy
    (cl:cons ':status (status msg))
    (cl:cons ':belong (belong msg))
))
