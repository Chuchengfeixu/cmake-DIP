#include <iostream> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

using namespace cv;
using namespace std;

    int main(int argc, char* argv[])  
    {
	//放大倍数  
	double x=1.5;

        //读图语句报错
	if ( argc != 2 )
	{
		cout<<"Wrong arguments."<<endl;
		cout<<"Usage:"<<endl;
		cout<<"\t "<<argv[0]<<" Image"<<endl;
		exit(7);
	}

	string image = argv[1];
        Mat src = imread("2.jpg");  
       
	//读图格式报错
	if( imread == 0 )
	{
		cout<<"Can't process this kind of image"<<endl;
		exit(8);
	}

        //显示  
        imshow("src",src);  
      
        //处理长宽  
	int row=src.rows;
	int col=src.cols;
	float nrow=x*(float)row;
	float ncol=x*(float)col;
	
	//创建矩阵
        Mat dst = Mat::zeros(nrow,ncol,CV_8UC3);  
      	int X=0;
	int Y=0;

	//最邻近内插
	for ( int i = 0; i < nrow; i++)
	{
		for(int j = 0; j < ncol; j++)
		{
			X= cvRound ( i / (double)x );
			Y= cvRound ( j / (double)x );
			if( X < row && X >= 0 && Y >= 0 && Y <= col )
			{	
				dst.at<cv::Vec3b>(i,j)[0]=src.at<cv::Vec3b>(X,Y)[0];
				dst.at<cv::Vec3b>(i,j)[1]=src.at<cv::Vec3b>(X,Y)[1];
				dst.at<cv::Vec3b>(i,j)[2]=src.at<cv::Vec3b>(X,Y)[2];
			}
		}
	}        


      
        imshow("dst",dst);  
      
        waitKey(0);  
        return 0;  
    }  



