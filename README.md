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
# Contributors

