#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{
    if ( argc != 5 )
    {
        printf("\nError: The command needs 5 arguments: the file to run, the input image filename, the output image filename, the threshold value, and the input ground truth image filename!\n\nIf you receive this error frequently, you may need to make sure you have all of the desired images copied into the 'src' folder (as of submission they reside in the 'Images' folder)!\n");
        return -1;
    }
    Mat image;
    image = imread( argv[1], IMREAD_GRAYSCALE);
    Mat gt_image = imread( argv[4], IMREAD_GRAYSCALE);
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    if( !gt_image.data){
        printf("No ground truth image data \n");
        return -1;
    }
    int rows = image.rows;
    int columns = image.cols;
    int tp = 0;
    int tn = 0;
    int fp = 0;
    int fn = 0;
    int thresholdValue = atoi(argv[3]);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(image.at<uchar>(i,j) >= thresholdValue){
                image.at<uchar>(i,j) = 255;
                if(gt_image.at<uchar>(i,j) == 255){
                    tp++;
                }
                else{
                    fp++;
                }
            }
            else{
                image.at<uchar>(i,j) = 0;
                if(gt_image.at<uchar>(i,j) == 0){
                    tn++;
                }
                else{
                    fn++;
                }
            }
        }
    }
    printf("Number of True Positives: %d\nNumber of True Negatives: %d\nNumber of False Positives: %d\nNumber of False Negatves: %d\n", tp, tn, fp, fn );
    namedWindow(argv[2], WINDOW_AUTOSIZE );
    namedWindow(argv[4], WINDOW_AUTOSIZE);
    imwrite(argv[2], image);
    imshow(argv[2], image);
    imshow(argv[4], gt_image);
    waitKey(0);
    return 0;
}
