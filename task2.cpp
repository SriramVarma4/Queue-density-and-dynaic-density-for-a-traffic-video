#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc,char* argv[]){
	VideoCapture cap(argv[1]);
	if (!cap.isOpened()){
		cout<<"\nerror reading the video\n";
		return 0;
	}
	Mat imgdiff;
	//Mat back_image = imread("empty.png", IMREAD_GRAYSCALE);
    Mat back_image = imread("empty.png");
    if ( back_image.empty() ) 
    { 
        cout << "Error loading the image" << endl;
        return -1; 
    }
    vector<Point2f> pts_src;
    pts_src.push_back(Point2f(925, 220));//left up
    pts_src.push_back(Point2f(225, 1004));//left bottom
    pts_src.push_back(Point2f(1552, 1004));//right bottom
    pts_src.push_back(Point2f(1295, 220));//right up

    vector<Point2f> pts_dst;
    pts_dst.push_back(Point2f(0, 0));//left up
    pts_dst.push_back(Point2f(0, 800));//left bottom
    pts_dst.push_back(Point2f(400, 800));//right bottom
    pts_dst.push_back(Point2f(400, 0));//right up

    Mat h = findHomography(pts_src, pts_dst);
    //warped image
    Mat warp_back;
    // Warp source image to destination based on homography
    warpPerspective(back_image, warp_back, h, back_image.size());
    // Display image
    //Mat im_out = Mat(900,1300,0);
	Mat back_crop = warp_back(Rect(0, 0, 400, 800));
	//imshow("bc", back_crop);
	int fm_count = 1;
	int rows = back_crop.rows;
	int cols = back_crop.cols;

	Mat f_crop;
	cout<<"executing\n";
	//new
	Ptr<BackgroundSubtractor> pBackSub;
	pBackSub = createBackgroundSubtractorMOG2();
	Mat fgmask;
	Mat frame;
