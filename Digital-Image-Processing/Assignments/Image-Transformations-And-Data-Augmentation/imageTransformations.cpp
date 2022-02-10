/* Note: Since this assignment allows for and uses many built-in functions, I have included references to the websites where I obtained knowledge on the functions and how to implement them so as to avoid plagiarism. */
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

#define REGIONS 3 /* I use a symbolic constant here in case the desired number of regions to be erased was altered. */

Mat translateImg(Mat image, Mat translateImage);
Mat cropScaleImg(Mat image, Mat cropScaleImage);
Mat flipImg(Mat image, Mat flipImage, int axis);
Mat rotateImg(Mat image, Mat rotateImage);
Mat randomEraseImg(Mat image, Mat randomEraseImage, int numRegions);
Mat randomIntensityImg(Mat image, Mat randomIntensityImage);
Mat blurImg(Mat image, Mat blurredImage);

int main(int argc, char** argv ){
    if ( argc != 2 ){
        printf("Error: The command needs 2 arguments: the command to run and the input image filename!\n");
        return -1;
    }
    Mat image, translateImage, cropScaleImage, verticalFlipImage, horizontalFlipImage, rotateImage, randomEraseImage, randomIntensityImage, blurredImage;
    image = imread( argv[1], 1);
    translateImage = imread( argv[1], 1);
    cropScaleImage = imread( argv[1], 1);
    verticalFlipImage = imread( argv[1], 1);
    horizontalFlipImage = imread( argv[1], 1);
    rotateImage = imread( argv[1], 1);
    randomEraseImage = imread( argv[1], 1);
    randomIntensityImage = imread( argv[1], 1);
    blurredImage = imread( argv[1], 1);
    if( !image.data || !translateImage.data || !cropScaleImage.data || !verticalFlipImage.data || !horizontalFlipImage.data || !rotateImage.data || !randomEraseImage.data || !randomIntensityImage.data || !blurredImage.data){
        printf("No image data \n");
        return -1;
    }
    srand(time(NULL));
    
    translateImage = translateImg(image, translateImage);
    
    cropScaleImage = cropScaleImg(image, cropScaleImage);
    
    verticalFlipImage = flipImg(image, verticalFlipImage, 0);
    
    horizontalFlipImage = flipImg(image, horizontalFlipImage, 1);
    
    rotateImage = rotateImg(image, rotateImage);
    
    randomEraseImage = randomEraseImg(image, randomEraseImage, REGIONS);
    
    randomIntensityImage = randomIntensityImg(image, randomIntensityImage);
    
    blurredImage = blurImg(image, blurredImage);
    
    namedWindow("OriginalImage.jpg", WINDOW_AUTOSIZE );
    imshow("OriginalImage.jpg", image);
    
    namedWindow("TranslatedImage.jpg", WINDOW_AUTOSIZE );
    imshow("TranslatedImage.jpg", translateImage);
    
    namedWindow("CroppedAndScaledImage.jpg", WINDOW_AUTOSIZE );
    imshow("CroppedAndScaledImage.jpg", cropScaleImage);
    
    namedWindow("VerticallyFlippedImage.jpg", WINDOW_AUTOSIZE );
    imshow("VerticallyFlippedImage.jpg", verticalFlipImage);
    
    namedWindow("HorizontallyFlippedImage.jpg", WINDOW_AUTOSIZE );
    imshow("HorizontallyFlippedImage.jpg", horizontalFlipImage);
    
    namedWindow("RotatedImage.jpg", WINDOW_AUTOSIZE );
    imshow("RotatedImage.jpg", rotateImage);
    
    namedWindow("RandomlyErasedImage.jpg", WINDOW_AUTOSIZE );
    imshow("RandomlyErasedImage.jpg", randomEraseImage);

    namedWindow("RandomlyStretchedImage.jpg", WINDOW_AUTOSIZE );
    imshow("RandomlyStretchedImage.jpg", randomIntensityImage);
    
    namedWindow("BlurredImage.jpg", WINDOW_AUTOSIZE );
    imshow("BlurredImage.jpg", blurredImage);
    
    waitKey(0);
    return 0;
}

Mat translateImg(Mat image, Mat translateImage) /*websites of reference: https://learnopencv.com/image-rotation-and-translation-using-opencv/#image-translation
    https://stackoverflow.com/questions/19068085/shift-image-content-with-opencv */
{
    int tx = rand() % image.cols;
    int ty = rand() % image.rows;
    Mat translation_matrix = (Mat_<double>(2,3) << 1, 0, tx, 0, 1, ty);
    warpAffine(image, translateImage, translation_matrix, image.size());
    return translateImage;
}

Mat cropScaleImg(Mat image, Mat cropScaleImage) /* websites of reference: https://learnopencv.com/cropping-an-image-using-opencv/
    https://learnopencv.com/image-resizing-with-opencv/ */
{
    int xCoordinate = rand() % image.cols;
    int yCoordinate = rand() % image.rows;
    int xTraversal = (rand() % image.cols) + xCoordinate;
    int yTraversal = (rand() % image.rows) + yCoordinate;
    if(xTraversal >= image.cols)
    {
        xTraversal = image.cols - 1;
    }
    if(yTraversal >= image.rows)
    {
        yTraversal = image.rows - 1;
    }
    cropScaleImage = image(Range(xCoordinate, xTraversal), Range(yCoordinate, yTraversal));
    resize(cropScaleImage, cropScaleImage, Size(image.rows, image.cols), INTER_LINEAR);
    return cropScaleImage;
}

Mat flipImg(Mat image, Mat flipImage, int axis) /* website of reference: http://opencv-tutorials-hub.blogspot.com/2015/11/flip-image-in-opencv-by-using-flip-function-opencv-hub-cplusplus-code.html */
{
    flip(image, flipImage, axis);
    return flipImage;
}

Mat rotateImg(Mat image, Mat rotateImage) /* website of reference: https://learnopencv.com/image-rotation-and-translation-using-opencv/#image-translation */
{
    Point2f center((image.cols-1) / 2.0, (image.rows - 1) / 2.0); //this calculation of the center and Point2f data type were also retrieved from the same website as referenced in the rotateImg() function
    double angle = rand() % 181;
    if((rand() % 2) == 1)
    {
        angle *= (-1);
    }
    Mat rotation_matrix = getRotationMatrix2D(center, angle, 1.0);
    warpAffine(image, rotateImage, rotation_matrix, image.size());
    return rotateImage;
}

Mat randomEraseImg(Mat image, Mat randomEraseImage, int numRegions)
{
    for(int i = 0; i < numRegions; i++)
    {
        int xCoordinate = rand() % randomEraseImage.cols;
        int yCoordinate = rand() % randomEraseImage.rows;
        int xTraversal = (rand() % 50) + xCoordinate; /* I made the random number up to 50 that way it will feasibly be big enough to see, but it will not erase a large section of the image. */
        int yTraversal = (rand() % 50) + yCoordinate;
        if(xTraversal >= randomEraseImage.cols)
        {
            xTraversal = randomEraseImage.cols - 1;
        }
        if(yTraversal >= randomEraseImage.rows)
        {
            yTraversal = randomEraseImage.rows - 1;
        }
        for(int r = yCoordinate; r <= yTraversal; r++)
        {
            for(int c = xCoordinate; c <= xTraversal; c++)
            {
                randomEraseImage.at<Vec3b>(r,c)[0] = 0;
                randomEraseImage.at<Vec3b>(r,c)[1] = 0;
                randomEraseImage.at<Vec3b>(r,c)[2] = 0;
            }
        }
    }
    return randomEraseImage;
}

Mat randomIntensityImg(Mat image, Mat randomIntensityImage)
{
    int imageType = rand() % 2;
    if(imageType == 1)
    {
        cvtColor(randomIntensityImage, randomIntensityImage, COLOR_BGR2GRAY);
        int min = rand() % 256;
        int max = rand() % 256;
        for(int r = 0; r < randomIntensityImage.rows; r++)
        {
            for(int c = 0; c < randomIntensityImage.cols; c++)
            {
                int temp = 255*(randomIntensityImage.at<uint8_t>(r,c) - min)/(max-min);
                if(temp > 255){
                    temp = 255;
                }
                else if(temp < 0){
                    temp = 0;
                }
                randomIntensityImage.at<uint8_t>(r,c) = temp;
            }
        }
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            int min = rand() % 256;
            int max = rand() % 256;
            for(int r = 0; r < randomIntensityImage.rows; r++)
            {
                for(int c = 0; c < randomIntensityImage.cols; c++)
                {
                    int temp = 255*(randomIntensityImage.at<Vec3b>(r,c)[i] - min)/(max-min);
                    if(temp > 255)
                    {
                        temp = 255;
                    }
                    else if(temp < 0)
                    {
                        temp = 0;
                    }
                    randomIntensityImage.at<Vec3b>(r,c)[i] = temp;
                }
            }
        }
    }
    return randomIntensityImage;
}

Mat blurImg(Mat image, Mat blurredImage)
{
    int sizeDetermination = rand() % 4;
    int change = 0;
    if(sizeDetermination == 1)
    {
        sizeDetermination = 5;
        change = 2;
    }
    else if(sizeDetermination == 2)
    {
        sizeDetermination = 7;
        change = 3;
    }
    else
    {
        sizeDetermination = 3;
        change = 1;
    }
    float blurMatrix[sizeDetermination][sizeDetermination];
    for(int i = 0; i < sizeDetermination; i++)
    {
        for(int j = 0; j < sizeDetermination; j++)
        {
            blurMatrix[i][j] = 1.0 / ((float)(sizeDetermination*sizeDetermination));
        }
    }
    for(int r = change; r < blurredImage.rows - change; r++)
    {
        for(int c = change; c < blurredImage.cols - change; c++)
        {
            float bluePixel = 0.0, greenPixel = 0.0, redPixel = 0.0;
            for(int u = (change*-1); u < (change+1); u++)
            {
                for(int v = (change*-1); v < (change+1); v++)
                {
                    bluePixel += (blurMatrix[u+change][v+change] * (float)blurredImage.at<Vec3b>(r+u,c+v)[0]);
                    greenPixel += (blurMatrix[u+change][v+change] * (float)blurredImage.at<Vec3b>(r+u,c+v)[1]);
                    redPixel += (blurMatrix[u+change][v+change] * (float)blurredImage.at<Vec3b>(r+u,c+v)[2]);
                }
            }
            blurredImage.at<Vec3b>(r,c)[0] = (int)bluePixel;
            blurredImage.at<Vec3b>(r,c)[1] = (int)greenPixel;
            blurredImage.at<Vec3b>(r,c)[2] = (int)redPixel;
        }
    }
    return blurredImage;
}
