#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z) {
    // TODO: Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    client.call(srv);
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;
    int img_width = img.step;

    float lin_x = 7.7;
    float ang_z = 7.7;
    
    bool white_ball_presence = false;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
    for(int i = 0; i < img.height * img.step; i++) {
        if(img.data[i] == white_pixel) {

            //i % width -> will give you the relative position of i to the width
            if(i % img_width < img_width/3) {
                drive_robot(lin_x, ang_z);
                white_ball_presence = true;
                break;
                //by putting a break, we can make the overall process faster, instead of waiting for the entire for loop to end even after the ball was found
            }else if(i % img_width >= img_width/3 && i % img_width <= (2*img_width)/3) {
                drive_robot(lin_x, 0);
                white_ball_presence = true;
                break;
            }else if(i % img_width > 2*img_width/3) {
                drive_robot(lin_x, -ang_z);
                white_ball_presence = true;
                break;
            }
        }
    }
    
    if(white_ball_presence == false) {
        drive_robot(0, 0);
    }
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}