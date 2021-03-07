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
