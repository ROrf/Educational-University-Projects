#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{
    if ( argc != 3 )
    {
        printf("\nError: The command needs 3 arguments: the file to run, the input image filename, and the output image filename!\n\nIf you receive this error frequently, you may need to make sure you have all of the desired images copied into the 'src' folder (as of submission they reside in the 'Images' folder)!\n");
        return -1;
    }
    Mat image;
    image = imread( argv[1], 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    Mat grayImage(image.size(), CV_8UC1);
    int rows = image.rows;
    int columns = image.cols;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            Vec3b colors = image.at<Vec3b>(i,j);
            int blue = colors.val[0];
            int green = colors.val[1];
            int red = colors.val[2];
            grayImage.at<uchar>(i,j)=.2989* + .5871*green + .1140*blue;
        }
    }
    namedWindow(argv[1], WINDOW_AUTOSIZE );
    namedWindow(argv[2], WINDOW_AUTOSIZE);
    imwrite(argv[2], grayImage);
    imshow(argv[1], image);
    imshow(argv[2], grayImage);
    waitKey(0);
    return 0;
}
