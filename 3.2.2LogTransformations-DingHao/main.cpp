#include <iostream>
#include　<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;


int main()
{
	Mat src=imread("1.jpg");
	if(!src.data)
	{
		printf("Can not load image\n");
	}
	{
	Mat std;
	logtrans(src,std)
	imshow("src",src);
}
