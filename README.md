[![Build Status](https://travis-ci.org/segwayrmp/segway-rmp-ros-pkg.png?branch=master)](https://travis-ci.org/segwayrmp/segway-rmp-ros-pkg)

## About

Fork of the segway_rmp ROS package repo for use with ROS melodic. Requires accompanying [libsegwayrmp](https://github.com/jvont/libsegwayrmp) (ported to ROS melodic as well) to be installed.

## Usage

To use, simply clone the git repo into a catkin workspace:

```bash
mkdir -p catkin_ws/src
cd catkin_ws/src
git clone git@github.com:jvont/segway_rmp.git
cd ..
catkin_make
```
