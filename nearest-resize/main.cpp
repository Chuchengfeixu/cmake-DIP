#include <iostream> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])  
    {  
        //导入图像
	if ( argc != 2 )
	{
		cout<<"Wrong arguments."<<endl;
		cout<<"Usage:"<<endl;
		cout<<"\t "<<argv[0]<<" Image"<<endl;
		exit(7);
	}


	string image = argv[1];
        Mat src = imread(image);  
      
        //显示  
        imshow("src",src);  
      
	Mat dst;
	resize(src,dst,Size(),2,2,INTER_NEAREST);        

      
        imshow("dst",dst);  
      
        waitKey(0);  
        return 0;  
    }  



