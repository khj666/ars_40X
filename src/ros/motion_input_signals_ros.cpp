//
// Created by shivesh on 9/14/19.
//

#include <continental_radar/ros/motion_input_signals_ros.hpp>

namespace continental_radar
{
MotionInputSignalsROS::MotionInputSignalsROS(ros::NodeHandle& nh, ContinentalRadarCAN * continental_radar_can) :
  continental_radar_can_(continental_radar_can), yaw_vel_prev_(0.0)
{
  speed_information_ = continental_radar_can_->get_speed_information();
  yaw_rate_information_ = continental_radar_can_->get_yaw_rate_information();
  odom_sub_ = nh.subscribe("odom", 10, &MotionInputSignalsROS::odom_callback, this);
}

MotionInputSignalsROS::~MotionInputSignalsROS()
{
}

void MotionInputSignalsROS::odom_callback(nav_msgs::Odometry msg) {
  double speed = msg.twist.twist.linear.x;
  speed_information_->set_speed(std::abs(speed));
  if (speed < 0.0) {
    speed_information_->set_speed_direction(motion_input_signals::BACKWARD);
  } else if (speed > 0.0) {
    speed_information_->set_speed_direction(motion_input_signals::FORWARD);
  } else {
    speed_information_->set_speed_direction(motion_input_signals::STANDSTILL);
  }
  continental_radar_can_->send_radar_data(can_messages::SpeedInformation);

  double yaw_rate = msg.twist.twist.angular.z - yaw_vel_prev_;
  yaw_rate /= (msg.header.stamp.toSec() - yaw_vel_time_prev_);
  yaw_rate_information_->set_yaw_rate(yaw_rate);
  continental_radar_can_->send_radar_data(can_messages::YawRateInformation);
  yaw_vel_prev_ = msg.twist.twist.angular.z;
  yaw_vel_time_prev_ = msg.header.stamp.toSec();
}
}
