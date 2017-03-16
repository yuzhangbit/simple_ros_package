#include <ros/console.h>
#include <ros/ros.h>
#include <tf/transform_datatypes.h>
#include <geometry_msgs/PoseStamped.h>
#include "simple_ros_package/simple_node.hpp"


int main(int argc, char **argv) {
    // Initialize node and publisher.
    ros::init(argc, argv, "simple_node_template");
    ros::NodeHandle nh("~");
    ros::Publisher publisher =
            nh.advertise<geometry_msgs::PoseStamped>("pose_publisher", 1, true);

    // Publisher in a loop.
    ros::Rate rate(10.0);
    unsigned int count = 0;
    while (nh.ok()) {
        // Add data to grid map.
        ros::Time time = ros::Time::now();
        geometry_msgs::PoseStamped pose_msg;
        pose_msg.header.frame_id = "base_link";
        pose_msg.header.stamp = time;
        pose_msg.header.seq = count;
        count++;
        pose_msg.pose.position.x = 10.0;
        pose_msg.pose.position.y = 0;
        pose_msg.pose.position.z = 0;
        pose_msg.pose.orientation = tf::createQuaternionMsgFromYaw(0.0);

        // Publish grid map.
        publisher.publish(pose_msg);
        ROS_INFO_THROTTLE(10, "ROS pose (timestamp %f) published.",
                          pose_msg.header.stamp.toSec());

        // Wait for next cycle.
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}

