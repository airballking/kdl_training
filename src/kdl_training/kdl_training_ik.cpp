#include <kdl_training/kdl_transform_ik.hpp>

int main(int argc, char **argv)
{
	ros::init(argc, argv,"kdl_ik");
    	ros::NodeHandle nh;
	kdl_training::Transform_ik my_transform(nh);

	try
        {
     	   	my_transform.start();
        }
        catch (const std::exception& ex)
        {
       		ROS_ERROR("%s",ex.what());
		return 0;
        }

	ros::spin();

    return 0;
}

