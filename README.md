# WN-2021-Controls-Navigation

# Steps for controlling a turtlesim with a defined path:

## Step 1: Start ROS
In the first terminal, run `roscore`

## Step 2: Start the turtlesim
In a separate terminal, run `rosrun turtlesim turtlesim_node`. After this has been run successfully, you will see a window with yout turtle robot at the center of the scene.
![Alt text](/Turtle.png?raw=true "Optional Title")

## Step 3: Start the path_generator
In another terminal, run `rosrun path_generator path_generator_node`. This will create a new topic `/turtle1/target`, which outputs the current target on the path, and it will be subscribed by the controller node later.

## Step 4: Publish your path to the path_generator
In yet another terminal, type `rostopic pub /turtle1/path nav_msgs/Path`, and hit tab. You will see an auto-fill of the format of the path you are publishing. You can modify the position of your point by changing the pose element at the bottom of the path variable. If you want add more points, move your cursor to the end of the word `poses` and hit tab. 

Make sure to remove the `"` notation after any line `w: 0.0` except the last one.

## Step 5: Run the controller and see the result
In another terminal, run `rosrun controller controller_node` to start the simulation, make sure to hit Ctrl + C when you think the turtle has achieved its desired last position. 

# Ways to check the path

run `rostopic echo /turtle1/path` to check the path currently publishing

run `rostopic echo /turtle1/target` to check the current target
