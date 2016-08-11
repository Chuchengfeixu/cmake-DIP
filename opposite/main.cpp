#include <iostream> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
using namespace cv;
using namespace std;

int main(int argc, char* argv[]) 
{ 
if ( argc != 2 )
	{
		cout<<"Wrong arguments."<<endl;
		cout<<"Usage:"<<endl;
		cout<<"\t "<<argv[0]<<" Image"<<endl;
		exit(7);
	}

  	string image = argv[1];
        Mat src = imread(image);

 	imshow("原图",src);
	int rowNumber=src.rows;
	int colNumber=src.cols*src.channels();
	
	 for (int i=0;i<rowNumber;i++)
         {
                  for(int j=0;j<colNumber;j++)
                  {
                          src.at<uchar>(i,j)=255-src.at<uchar>(i,j);
                  }
         }


	imshow("反转图像",src);
  	waitKey(0); 
  	return 0;
}
