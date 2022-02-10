#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv ){
    if ( argc != 5 ){
        printf("\nError: The command needs 5 arguments: the file to run, the minimum value, the maximum value, the input image filename, and the output image filename!\n\nIf you receive this error frequently, you may need to make sure you have all of the desired images copied into the 'src' folder (as of submission they reside in the 'Images' folder)!\n");
        return -1;
    }
    if(atoi(argv[1]) < 0 || atoi(argv[1]) > 255){
        printf("\nError: Minimum values for pixels can only range from 0 to 255!\n");
    }
    if(atoi(argv[2]) < 0 || atoi(argv[2]) > 255){
        printf("\nError: Maximum values for pixels can only range from 0 to 255!\n");
    }
    Mat image;
    image = imread( argv[3], IMREAD_GRAYSCALE);
    if( !image.data ){
        printf("No image data \n");
        return -1;
    }
    int rows = image.rows;
    int columns = image.cols;
    int minValue = atoi(argv[1]);
    int maxValue = atoi(argv[2]);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            int temp = 255*(image.at<uint8_t>(i,j) - minValue)/(maxValue-minValue);
            if(temp > 255){
                temp = 255;
            }
            else if(temp < 0){
                temp = 0;
            }
            image.at<uint8_t>(i,j) = temp;
        }
    }
    namedWindow(argv[4], WINDOW_AUTOSIZE );
    imwrite(argv[4], image);
    imshow(argv[4], image);
    waitKey(0);
    return 0;
}
