[![Build Status](https://travis-ci.org/segwayrmp/segway-rmp-ros-pkg.png?branch=master)](https://travis-ci.org/segwayrmp/segway-rmp-ros-pkg)

## About

Fork of the segway_rmp ROS package repo for use with ROS melodic, with additional joystick support out of the box. Requires accompanying [libsegwayrmp](https://github.com/jvont/libsegwayrmp) (ported to ROS melodic as well) to be installed. See [wiki](https://wiki.ros.org/segway_rmp) for more details.

## Installation

To install, simply clone the git repo into a catkin workspace (make sure that [libsegwayrmp](https://github.com/jvont/libsegwayrmp) has been properly installed from source):

```bash
mkdir -p catkin_ws/src
cd catkin_ws/src
git clone git@github.com:jvont/segway_rmp.git
cd ..
catkin_make
```

Add `90-segway.rules` found in `rules/` to your computer's udev rules folder (usually found at `/etc/udev/rules.d`). This allows our `segway_rmp.launch` file to find the segway via usb connection. If two segways are used, additional rules may be added to distinguish each based on serial number/model.

## Usage

Setup ROS environment:

```bash
source /opt/ros/melodic/setup.bash
source /path/to/catkin_ws/devel/setup.bash
```

To launch the segway platform:

```bash
roslaunch segway_rmp segway_rmp.launch
```

To use joystick teleoperation:

```bash
roslaunch segway_rmp teleop_joy.launch
```
