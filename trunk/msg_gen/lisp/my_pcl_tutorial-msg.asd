
(cl:in-package :asdf)

(defsystem "my_pcl_tutorial-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "GroundPlaneCoeff" :depends-on ("_package_GroundPlaneCoeff"))
    (:file "_package_GroundPlaneCoeff" :depends-on ("_package"))
  ))