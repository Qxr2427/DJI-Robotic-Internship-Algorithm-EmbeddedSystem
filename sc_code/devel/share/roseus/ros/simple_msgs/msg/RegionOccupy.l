;; Auto-generated. Do not edit!


(when (boundp 'simple_msgs::RegionOccupy)
  (if (not (find-package "SIMPLE_MSGS"))
    (make-package "SIMPLE_MSGS"))
  (shadow 'RegionOccupy (find-package "SIMPLE_MSGS")))
(unless (find-package "SIMPLE_MSGS::REGIONOCCUPY")
  (make-package "SIMPLE_MSGS::REGIONOCCUPY"))

(in-package "ROS")
;;//! \htmlinclude RegionOccupy.msg.html


(defclass simple_msgs::RegionOccupy
  :super ros::object
  :slots (_status _belong ))

(defmethod simple_msgs::RegionOccupy
  (:init
   (&key
    ((:status __status) 0)
    ((:belong __belong) 0)
    )
   (send-super :init)
   (setq _status (round __status))
   (setq _belong (round __belong))
   self)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:belong
   (&optional __belong)
   (if __belong (setq _belong __belong)) _belong)
  (:serialization-length
   ()
   (+
    ;; uint8 _status
    1
    ;; uint8 _belong
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _status
       (write-byte _status s)
     ;; uint8 _belong
       (write-byte _belong s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _status
     (setq _status (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _belong
     (setq _belong (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get simple_msgs::RegionOccupy :md5sum-) "b93e8ad8a0004ce2f2e8a04d9cfaa53a")
(setf (get simple_msgs::RegionOccupy :datatype-) "simple_msgs/RegionOccupy")
(setf (get simple_msgs::RegionOccupy :definition-)
      "uint8 status
uint8 belong

")



(provide :simple_msgs/RegionOccupy "b93e8ad8a0004ce2f2e8a04d9cfaa53a")


