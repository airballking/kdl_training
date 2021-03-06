#include <ros/ros.h>
#include <tf/transform_broadcaster.h>


int main(int argc, char** argv){
	ros::init(argc, argv, "world_tf");
	ros::NodeHandle node;

	tf::TransformBroadcaster br;
	tf::Transform transform;

	tf::TransformBroadcaster br1;
	tf::Transform transform1;

	tf::TransformBroadcaster br2;
	tf::Transform transform2;

	tf::TransformBroadcaster br3;
	tf::Transform transform3;

	tf::TransformBroadcaster br4;
	tf::Transform transform4;

	ros::Rate rate(10.0);

	while (node.ok())
	{	
		transform.setOrigin(tf::Vector3(0.0, 0.0, 0.0));
		tf::Quaternion q;
		q.setRPY(0, 0, 0);
		transform.setRotation(q);
		br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", "base_footprint"));

		transform1.setOrigin(tf::Vector3(0.8, 0, 0.6));
		tf::Quaternion q1;
		q1.setRPY(0, 0, 0);
		transform1.setRotation(q1);
		br1.sendTransform(tf::StampedTransform(transform1, ros::Time::now(), "map", "table_frame"));
		rate.sleep();

		transform2.setOrigin(tf::Vector3(0.1, -0.4, 0));
		tf::Quaternion q2;
		q2.setRPY(0, 0, 0);
		transform2.setRotation(q2);
		br2.sendTransform(tf::StampedTransform(transform2, ros::Time::now(), "table_frame", "bottle_frame"));
		rate.sleep();

		transform3.setOrigin(tf::Vector3(0.0, 0.0, 0.075));
		tf::Quaternion q3;
		q3.setRPY(0, 0, 0);
		transform2.setRotation(q3);
		br3.sendTransform(tf::StampedTransform(transform3, ros::Time::now(), "bottle_frame", "bottle_low_frame"));
		rate.sleep();

		transform4.setOrigin(tf::Vector3(0.0, 0.0, 0.095));
		tf::Quaternion q4;
		q4.setRPY(0, 0, 0);
		transform4.setRotation(q4);
		br4.sendTransform(tf::StampedTransform(transform4, ros::Time::now(), "bottle_low_frame", "bottle_high_frame"));
		rate.sleep();
	}
	return 0;
};
