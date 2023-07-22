# Go-Chase-It-!
Welcome to the ROS Gazebo Simulation for the Autonomous Robot Ball Tracker project! This repository showcases an exciting robotics simulation that demonstrates a robot's ability to autonomously locate a white ball in its environment using its camera and laser scan sensor. Through this simulation, we explore the fascinating world of Robotics Operating System (ROS) and Gazebo, two powerful tools that enable the development and testing of advanced robotic systems.

https://github.com/jwShalom/My-Gazebo-World/assets/124924697/f0a7b1f7-94a8-4a08-bc57-cf50a7bea90f

## Purpose
The purpose of the ROS Gazebo Simulation for Autonomous Robot Ball Tracker project extends far beyond the impressive capability of a robot locating and navigating towards a white ball. Throughout this project, we have achieved several key objectives, honing our skills and expertise in the world of Robotics Operating System (ROS), Gazebo simulation, and robot control. Below are the core aspects and valuable insights we have gained:

1. **ROS Package Development**: This project provided a hands-on experience in creating multiple ROS packages, each serving specific functionalities. By modularizing the system into distinct packages, we learned how to design a well-structured and maintainable robot architecture.

2. **Launch File Configuration**: The project taught us how to create an efficient launch file that orchestrates the execution of multiple ROS packages and nodes simultaneously. This skill is essential for seamlessly running complex robot systems with multiple components.

3. **URDF Robot Model Creation**: Leveraging the Unified Robot Description Format (URDF), we crafted a detailed robot model that emulates the physical characteristics of our autonomous robot. This included integrating a camera and a laser scanner, allowing us to visualize the robot's perspective through RVIZ.

4. **C++ Node Development**: The creation of two C++ nodes was a significant achievement in this project. The first node, acting as a service server, enabled us to control the robot's movements by adjusting its linear and angular velocities. The second node, functioning as a subscriber, demonstrated the power of image analysis as it processed camera images to detect the position of the white ball.

5. **Service-Client Interaction**: Understanding the interaction between a service server and a client was crucial for enabling seamless communication between different nodes. The client node's ability to request the service server to navigate the robot based on the ball's position showcased the potential of ROS for building complex, interactive robotic systems.

6. **Computer Vision Algorithm**: We explored the basic realm of computer vision algorithms to detect and analyze the position of the white ball within the robot's visual input. This experience broadened our understanding of image processing and object recognition, key skills for many robotic applications.

7. **Simulated Robotics with Gazebo**: The project leveraged the Gazebo simulator to create a realistic 3D environment for our robot. This simulation environment allowed us to test and validate our robot's behavior without the need for expensive physical hardware, saving time and resources.

## Directory
```bash
.Go-Chase-It-                      # Go Chase It Project
├── my_robot                       # my_robot package
│   ├── launch                     # launch folder for launch files
│   │   ├── robot_description.launch
│   │   ├── world.launch
│   ├── meshes                     # meshes folder for sensors
│   │   ├── hokuyo.dae
│   ├── urdf                       # urdf folder for xarco files
│   │   ├── my_robot.gazebo
│   │   ├── my_robot.xacro
│   ├── world                      # world folder for world files
│   │   ├── naegok.world
│   ├── CMakeLists.txt             # compiler instructions
│   ├── package.xml                # package info
├── ball_chaser                    # ball_chaser package
│   ├── launch                     # launch folder for launch files
│   │   ├── ball_chaser.launch
│   ├── src                        # source folder for C++ scripts
│   │   ├── drive_bot.cpp
│   │   ├── ball_chaser.cpp
│   ├── srv                        # service folder for ROS services
│   │   ├── DriveToTarget.srv
│   ├── CMakeLists.txt             # compiler instructions
│   ├── package.xml                # package info
└──
```
my_robot: This package contains a the virtual world that the robot will explore, a white ball that a robot will chase and the robot.
ball_chaser:This package contains two ROS nodes. 
  - drive_bot.cpp: In charge of moving robot through controlling x linear-velocity and z angular-velocity 
  - ball_chaser.cpp: In charge of determining the location of the white (left, middle, right) and send its velocity commands to drive_bot.cpp

## Setup

1. Update and upgrade the Workspace image
```bash
$ sudo apt-get update && sudo apt-get upgrade -y
```
2. Clone the project folder in your workspace
```bash
$ cd /home/<name of your workspace: workspace (for example)>/
$ git clone https://github.com/jwShalom/Go-Chase-It-/
```
3. Compile the code
```bash
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```
4. Open another terminal and launch ball_chaser package
```bash
$ source devel/setup.bash
$ roslaunch ball_chaser ball_chaser.launch
```
5. Play Around by moving a robot and a ball (in the camera view)! The robot will 'Go-Chase-It!'
