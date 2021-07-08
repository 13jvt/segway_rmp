#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include <sensor_msgs/Joy.h>

struct InputConfig
{
  int axis;
  double scale;
  double max;
  double min;

  double clamp(double val);
};

double InputConfig::clamp(double val)
{
  return (val < min) ? min : (val > max) ? max : val;
}

class TeleopJoy
{
public:
  TeleopJoy();

private:
  InputConfig linear;
  InputConfig angular;

  int safety;

  ros::NodeHandle nh;

  ros::Publisher vel_pub;
  ros::Subscriber joy_sub;

  void joy_callback(const sensor_msgs::Joy::ConstPtr& joy);
};

TeleopJoy::TeleopJoy()
{
  nh.param("/axis_linear", linear.axis, 1);
  nh.param("/scale_linear", linear.scale, 1.0);
  nh.param("/max_linear", linear.max, 0.5);
  nh.param("/min_linear", linear.min, -0.5);

  nh.param("/axis_angular", angular.axis, 3);
  nh.param("/scale_angular", angular.scale, 1.0);
  nh.param("/max_angular", angular.max, 0.5);
  nh.param("/min_angular", angular.min, -0.5);

  nh.param("/button_safety", safety, 5);

  vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
  joy_sub = nh.subscribe<sensor_msgs::Joy>("/joy", 10, &TeleopJoy::joy_callback, this);
}

void TeleopJoy::joy_callback(const sensor_msgs::Joy::ConstPtr& joy)
{
  geometry_msgs::Twist twist;

  if (joy->buttons[safety])
  {
    twist.linear.x = linear.clamp(linear.scale * joy->axes[linear.axis]);
    twist.angular.z = angular.clamp(angular.scale * joy->axes[angular.axis]);
  }
  vel_pub.publish(twist);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_joy");
  TeleopJoy teleop_joy;

  ros::spin();
}
