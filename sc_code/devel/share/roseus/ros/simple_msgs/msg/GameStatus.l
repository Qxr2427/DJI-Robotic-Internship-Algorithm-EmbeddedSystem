;; Auto-generated. Do not edit!


(when (boundp 'simple_msgs::GameStatus)
  (if (not (find-package "SIMPLE_MSGS"))
    (make-package "SIMPLE_MSGS"))
  (shadow 'GameStatus (find-package "SIMPLE_MSGS")))
(unless (find-package "SIMPLE_MSGS::GAMESTATUS")
  (make-package "SIMPLE_MSGS::GAMESTATUS"))

(in-package "ROS")
;;//! \htmlinclude GameStatus.msg.html


(defclass simple_msgs::GameStatus
  :super ros::object
  :slots (_region_occupy _castle_energy _red_position _blue_position _red_step_move _blue_step_move _red_score _blue_score _round_remain_tick _round_remain_cnt _round_team ))

(defmethod simple_msgs::GameStatus
  (:init
   (&key
    ((:region_occupy __region_occupy) (let (r) (dotimes (i 0) (push (instance simple_msgs::RegionOccupy :init) r)) r))
    ((:castle_energy __castle_energy) (let (r) (dotimes (i 0) (push (instance simple_msgs::CastleEnergy :init) r)) r))
    ((:red_position __red_position) 0)
    ((:blue_position __blue_position) 0)
    ((:red_step_move __red_step_move) 0)
    ((:blue_step_move __blue_step_move) 0)
    ((:red_score __red_score) 0)
    ((:blue_score __blue_score) 0)
    ((:round_remain_tick __round_remain_tick) 0)
    ((:round_remain_cnt __round_remain_cnt) 0)
    ((:round_team __round_team) 0)
    )
   (send-super :init)
   (setq _region_occupy __region_occupy)
   (setq _castle_energy __castle_energy)
   (setq _red_position (round __red_position))
   (setq _blue_position (round __blue_position))
   (setq _red_step_move (round __red_step_move))
   (setq _blue_step_move (round __blue_step_move))
   (setq _red_score (round __red_score))
   (setq _blue_score (round __blue_score))
   (setq _round_remain_tick (round __round_remain_tick))
   (setq _round_remain_cnt (round __round_remain_cnt))
   (setq _round_team (round __round_team))
   self)
  (:region_occupy
   (&rest __region_occupy)
   (if (keywordp (car __region_occupy))
       (send* _region_occupy __region_occupy)
     (progn
       (if __region_occupy (setq _region_occupy (car __region_occupy)))
       _region_occupy)))
  (:castle_energy
   (&rest __castle_energy)
   (if (keywordp (car __castle_energy))
       (send* _castle_energy __castle_energy)
     (progn
       (if __castle_energy (setq _castle_energy (car __castle_energy)))
       _castle_energy)))
  (:red_position
   (&optional __red_position)
   (if __red_position (setq _red_position __red_position)) _red_position)
  (:blue_position
   (&optional __blue_position)
   (if __blue_position (setq _blue_position __blue_position)) _blue_position)
  (:red_step_move
   (&optional __red_step_move)
   (if __red_step_move (setq _red_step_move __red_step_move)) _red_step_move)
  (:blue_step_move
   (&optional __blue_step_move)
   (if __blue_step_move (setq _blue_step_move __blue_step_move)) _blue_step_move)
  (:red_score
   (&optional __red_score)
   (if __red_score (setq _red_score __red_score)) _red_score)
  (:blue_score
   (&optional __blue_score)
   (if __blue_score (setq _blue_score __blue_score)) _blue_score)
  (:round_remain_tick
   (&optional __round_remain_tick)
   (if __round_remain_tick (setq _round_remain_tick __round_remain_tick)) _round_remain_tick)
  (:round_remain_cnt
   (&optional __round_remain_cnt)
   (if __round_remain_cnt (setq _round_remain_cnt __round_remain_cnt)) _round_remain_cnt)
  (:round_team
   (&optional __round_team)
   (if __round_team (setq _round_team __round_team)) _round_team)
  (:serialization-length
   ()
   (+
    ;; simple_msgs/RegionOccupy[] _region_occupy
    (apply #'+ (send-all _region_occupy :serialization-length)) 4
    ;; simple_msgs/CastleEnergy[] _castle_energy
    (apply #'+ (send-all _castle_energy :serialization-length)) 4
    ;; uint8 _red_position
    1
    ;; uint8 _blue_position
    1
    ;; uint8 _red_step_move
    1
    ;; uint8 _blue_step_move
    1
    ;; int16 _red_score
    2
    ;; int16 _blue_score
    2
    ;; uint8 _round_remain_tick
    1
    ;; uint8 _round_remain_cnt
    1
    ;; uint8 _round_team
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; simple_msgs/RegionOccupy[] _region_occupy
     (write-long (length _region_occupy) s)
     (dolist (elem _region_occupy)
       (send elem :serialize s)
       )
     ;; simple_msgs/CastleEnergy[] _castle_energy
     (write-long (length _castle_energy) s)
     (dolist (elem _castle_energy)
       (send elem :serialize s)
       )
     ;; uint8 _red_position
       (write-byte _red_position s)
     ;; uint8 _blue_position
       (write-byte _blue_position s)
     ;; uint8 _red_step_move
       (write-byte _red_step_move s)
     ;; uint8 _blue_step_move
       (write-byte _blue_step_move s)
     ;; int16 _red_score
       (write-word _red_score s)
     ;; int16 _blue_score
       (write-word _blue_score s)
     ;; uint8 _round_remain_tick
       (write-byte _round_remain_tick s)
     ;; uint8 _round_remain_cnt
       (write-byte _round_remain_cnt s)
     ;; uint8 _round_team
       (write-byte _round_team s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; simple_msgs/RegionOccupy[] _region_occupy
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _region_occupy (let (r) (dotimes (i n) (push (instance simple_msgs::RegionOccupy :init) r)) r))
     (dolist (elem- _region_occupy)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; simple_msgs/CastleEnergy[] _castle_energy
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _castle_energy (let (r) (dotimes (i n) (push (instance simple_msgs::CastleEnergy :init) r)) r))
     (dolist (elem- _castle_energy)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; uint8 _red_position
     (setq _red_position (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _blue_position
     (setq _blue_position (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _red_step_move
     (setq _red_step_move (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _blue_step_move
     (setq _blue_step_move (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int16 _red_score
     (setq _red_score (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _blue_score
     (setq _blue_score (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _round_remain_tick
     (setq _round_remain_tick (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _round_remain_cnt
     (setq _round_remain_cnt (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _round_team
     (setq _round_team (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get simple_msgs::GameStatus :md5sum-) "3c1a9bf389a73be248100bdba5d1e8fd")
(setf (get simple_msgs::GameStatus :datatype-) "simple_msgs/GameStatus")
(setf (get simple_msgs::GameStatus :definition-)
      "RegionOccupy[] region_occupy
CastleEnergy[] castle_energy
uint8 red_position
uint8 blue_position
uint8 red_step_move
uint8 blue_step_move
int16 red_score
int16 blue_score
uint8 round_remain_tick
uint8 round_remain_cnt
uint8 round_team

================================================================================
MSG: simple_msgs/RegionOccupy
uint8 status
uint8 belong

================================================================================
MSG: simple_msgs/CastleEnergy
uint8 red_energy
uint8 blue_energy

")



(provide :simple_msgs/GameStatus "3c1a9bf389a73be248100bdba5d1e8fd")


