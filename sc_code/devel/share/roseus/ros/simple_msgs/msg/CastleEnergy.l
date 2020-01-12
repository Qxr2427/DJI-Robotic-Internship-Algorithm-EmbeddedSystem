;; Auto-generated. Do not edit!


(when (boundp 'simple_msgs::CastleEnergy)
  (if (not (find-package "SIMPLE_MSGS"))
    (make-package "SIMPLE_MSGS"))
  (shadow 'CastleEnergy (find-package "SIMPLE_MSGS")))
(unless (find-package "SIMPLE_MSGS::CASTLEENERGY")
  (make-package "SIMPLE_MSGS::CASTLEENERGY"))

(in-package "ROS")
;;//! \htmlinclude CastleEnergy.msg.html


(defclass simple_msgs::CastleEnergy
  :super ros::object
  :slots (_red_energy _blue_energy ))

(defmethod simple_msgs::CastleEnergy
  (:init
   (&key
    ((:red_energy __red_energy) 0)
    ((:blue_energy __blue_energy) 0)
    )
   (send-super :init)
   (setq _red_energy (round __red_energy))
   (setq _blue_energy (round __blue_energy))
   self)
  (:red_energy
   (&optional __red_energy)
   (if __red_energy (setq _red_energy __red_energy)) _red_energy)
  (:blue_energy
   (&optional __blue_energy)
   (if __blue_energy (setq _blue_energy __blue_energy)) _blue_energy)
  (:serialization-length
   ()
   (+
    ;; uint8 _red_energy
    1
    ;; uint8 _blue_energy
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _red_energy
       (write-byte _red_energy s)
     ;; uint8 _blue_energy
       (write-byte _blue_energy s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _red_energy
     (setq _red_energy (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _blue_energy
     (setq _blue_energy (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get simple_msgs::CastleEnergy :md5sum-) "9299551f2d90f96de59e7c55bb10e426")
(setf (get simple_msgs::CastleEnergy :datatype-) "simple_msgs/CastleEnergy")
(setf (get simple_msgs::CastleEnergy :definition-)
      "uint8 red_energy
uint8 blue_energy

")



(provide :simple_msgs/CastleEnergy "9299551f2d90f96de59e7c55bb10e426")


