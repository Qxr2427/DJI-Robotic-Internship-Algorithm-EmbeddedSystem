
(cl:in-package :asdf)

(defsystem "simple_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "CastleEnergy" :depends-on ("_package_CastleEnergy"))
    (:file "_package_CastleEnergy" :depends-on ("_package"))
    (:file "GameStatus" :depends-on ("_package_GameStatus"))
    (:file "_package_GameStatus" :depends-on ("_package"))
    (:file "RegionOccupy" :depends-on ("_package_RegionOccupy"))
    (:file "_package_RegionOccupy" :depends-on ("_package"))
  ))