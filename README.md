# WN-2021-Controls
Instructions to create a URDF model with camera sensorin the Gazebo simulator that is accessible by ROS. 
# Package Structure
**mybot_description** specifies the entire robot structure as links and joints and can launch the model in rviz.

**mybot_gazebo** launches the model in the gazebo environment and contains different simulation worlds.

**mybot_control** (not used) enable control over joints of our model so that it can move around.

# Installation

First, we have to create a catkin workspace. We can do this by running the following commands:

`cd ~`

`mkdir mybot_ws`

`cd mybot_ws`

`catkin init`

`mkdir src`

`catkin build`

`echo "source ~/mybot_ws/devel/setup.bash" >> ~/.bashrc # Adds workspace to search path`

# Running the Model

To run the model, we use both Gazebo and Rviz. Gazebo is a 3D simulator while Rviz is a robot visualization tool that will help with the implementation of sensors such as a camera. 

Load both programs through the following commands in seperate terminals:

`roslaunch mybot_gazebo mybot_world.launch`

`roslaunch mybot_description mybot_rviz.launch`

The following commands will cause the model to start moving within Gazebo and Rviz:

`rostopic pub /cmd_vel geometry_msgs/Twist "linear:
  x: 0.2
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.1"`
  
# Camera Module Simulation

After running the model in Gazebo, we can run the following command to view the camera data:

`rosrun image_view image_view image:=/mybot/camera1/image_raw`

In Gazebo, we can add an object to test the camera view. After launching rviz, add the camera in the sensors tab to see the view of the camera.
  
