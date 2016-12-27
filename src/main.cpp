#include "ardrone/ardrone.h"
#include <string>
#include <sstream>



// AR.Drone class
ARDrone ardrone;

// Infomation font init

void infoShow(cv::String,cv::Mat);


int main(int argc, char *argv[])
{
    std::cout<<"Connecting to drone\n";

    // Initialize
    if (!ardrone.open()) {
        std::cout << "Failed to initialize." << std::endl;
        return -1;
    }

    // Battery
    std::cout << "Battery = " << ardrone.getBatteryPercentage() << "[%]" << std::endl;

    // Instructions
    std::cout << "***************************************" << std::endl;
    std::cout << "*       CV Drone sample program       *" << std::endl;
    std::cout << "*           - How to play -           *" << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "*                                     *" << std::endl;
    std::cout << "* - Controls -                        *" << std::endl;
    std::cout << "*    'Space' -- Takeoff/Landing       *" << std::endl;
    std::cout << "*    'Up'    -- Move forward          *" << std::endl;
    std::cout << "*    'Down'  -- Move backward         *" << std::endl;
    std::cout << "*    'Left'  -- Turn left             *" << std::endl;
    std::cout << "*    'Right' -- Turn right            *" << std::endl;
    std::cout << "*    'Q'     -- Move upward           *" << std::endl;
    std::cout << "*    'A'     -- Move downward         *" << std::endl;
    std::cout << "*                                     *" << std::endl;
    std::cout << "* - Others -                          *" << std::endl;
    std::cout << "*    'C'     -- Change camera         *" << std::endl;
    std::cout << "*    'Esc'   -- Exit                  *" << std::endl;
    std::cout << "*                                     *" << std::endl;
    std::cout << "***************************************" << std::endl;


    while (1) {
        // Key input
        int key = cv::waitKey(33);
        if (key == 0x1b) break;

        // Get an image
        cv::Mat image = ardrone.getImage();

        // Take off / Landing 
        if (key == ' ') {
            if (ardrone.onGround()) ardrone.takeoff();
            else                    ardrone.landing();
        }

        // Move
        double vx = 0.0, vy = 0.0, vz = 0.0, vr = 0.0;
        if (key == 'w' || key == CV_VK_UP)    vx =  1.0;
        if (key == 's' || key == CV_VK_DOWN)  vx = -1.0;
        if (key == 'q' || key == CV_VK_LEFT)  vr =  1.0;
        if (key == 'e' || key == CV_VK_RIGHT) vr = -1.0;
        if (key == 'a') vy =  1.0;
        if (key == 'd') vy = -1.0;
        if (key == 'i') vz =  1.0;
        if (key == 'k') vz = -1.0;
        ardrone.move3D(vx, vy, vz, vr);

        // Change camera
        static int mode = 0;
        if (key == 'c') ardrone.setCamera(++mode % 4);

        // Display the image
//        cv::imshow("camera", image);
        infoShow("camera",image);

    }

    ardrone.close();

    return 0;
}













void infoShow(cv::String windowName, cv::Mat displayImg) {
    using  namespace std;
    CvFont infoFont;
    cvInitFont(&infoFont,CV_FONT_HERSHEY_SIMPLEX,0.5,0.5,0,1,8);
    CvMat resultImg = displayImg;
    stringstream ss;
    int hight = 20;
    double vx,vy,vz;
    double x,y,z;
    ardrone.getPosition(&x,&y,&z);
    ardrone.getVelocity(&vx,&vy,&vz);
    double pitch = ardrone.getPitch();
    double yaw = ardrone.getYaw();
    double roll = ardrone.getRoll();

    ss<<"Battery:"<<ardrone.getBatteryPercentage()<<"%";
    string infostring = ss.str();
    cvPutText(&resultImg,infostring.data(),cvPoint(20,hight),&infoFont,cvScalar(255,0,0));
    hight += 20;
    ss.clear();
    ss.str("");

    ss<<"Altitude:"<<ardrone.getAltitude();
    infostring = ss.str();
    cvPutText(&resultImg,infostring.data(),cvPoint(20,hight),&infoFont,cvScalar(255,0,0));
    hight += 20;
    ss.clear();
    ss.str("");

    ss<<"Velocity:("<<vx<<","<<vy<<","<<vz<<")";
    infostring = ss.str();
    cvPutText(&resultImg,infostring.data(),cvPoint(20,hight),&infoFont,cvScalar(255,0,0));
    hight += 20;
    ss.clear();
    ss.str("");

    ss<<"Position:("<<x<<","<<y<<","<<z<<")";
    infostring = ss.str();
    cvPutText(&resultImg,infostring.data(),cvPoint(20,hight),&infoFont,cvScalar(255,0,0));
    hight += 20;
    ss.clear();
    ss.str("");

    ss<<"Pitch:"<<pitch;
    infostring = ss.str();
    cvPutText(&resultImg,infostring.data(),cvPoint(20,hight),&infoFont,cvScalar(255,0,0));
    hight += 20;
    ss.clear();
    ss.str("");

    ss<<"Yaw:"<<yaw;
    infostring = ss.str();
    cvPutText(&resultImg,infostring.data(),cvPoint(20,hight),&infoFont,cvScalar(255,0,0));
    hight += 20;
    ss.clear();
    ss.str("");

    ss<<"Roll:"<<roll;
    infostring = ss.str();
    cvPutText(&resultImg,infostring.data(),cvPoint(20,hight),&infoFont,cvScalar(255,0,0));
    ss.clear();
    ss.str("");

    cvPutText(&resultImg,infostring.data(),cvPoint(20,20),&infoFont,cvScalar(255,0,0));
    cv::imshow(windowName,displayImg);
}


