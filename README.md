# Simulating Robot Modules

# Synopsis

There are two folders in this branch:
1. mybot_ws - [1st Part of Moore's Robots Tutorial](http://moorerobots.com/blog/post/1)
2. mybot_ws2 -[2nd Part of Moore's Robots Tutorial](http://moorerobots.com/blog/post/2)

mybot_ws runs well but the second one still needs work. Refer to Camera_Simulation for the more complete code.

# Motivation
This is supposed to be a tutorial to get a simulated robot running on Gazebo and rviz using an URDF model. 

# Installation

Clone this repository into your `catkin` workspace, then run `catkin build`. Optionally, run `catkin config --install` followed by `catkin build` to install the package to your `catkin` workspace.

Run `catkin init` followed by `catkin build`. 

Run `echo "source ~/mybot_ws/devel/setup.bash" >> ~/.bashrc` so that the terminal can autocomplete and find the ros packages

Gazebo is the 3D Simulation software which allows you to see the robot model.

# Running

`roslaunch mybot_gazebo mybot_world.launch` launches the Gazebo window

Run this on a seperate terminal: `roslaunch mybot_description mybot_rviz.launch` to launch rviz

The following command would publish the velocity message to Gazebo and rviz and you should see the robor moving in a circle.

`rostopic pub /cmd_vel geometry_msgs/Twist "linear:
  x: 0.2
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.1"
  `
  
  You can change the x, y, z values and move the robot differently too!

### Contributors
Moore Robotics, richardw05, Elton Lin, Sunny Wang, and Ashwin Saxena

