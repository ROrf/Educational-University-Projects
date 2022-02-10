#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream> //these 2 headers are required to use the LABEL Matrix with my implementation
#include <vector>

using namespace std;
using namespace cv;

#define SIZE 2001 //allows for size of PARENT[] to be altered easily (still not dynamically) throughout the program if conditions were to change, and for computational ease, although it is more inefficient, I am extending the size to 2001 to skip index 0

typedef vector< vector<int> > Matrix;

Mat invertImage(Mat image, int invert);
int createCCL(Mat image, int PARENT[], int parentSize, Matrix& LABEL, int numRows, int numCols);
int unionComponents(int X, int Y, int PARENT[], int parentSize);
int findComponents(int X, int PARENT[], int parentSize);
int combineCCL(int PARENT[], int parentSize, Matrix& LABEL, int numRows, int numCols);
void getComponents(int COMPONENTS[], int componentsSize, int PARENT[], int parentSize);
void getAreas(Matrix& LABEL, int numRows, int numCols, int componentAreas[], int COMPONENTS[], int countComponents);
void getCentroids(Matrix& LABEL, int numRows, int numCols, int componentAreas[], double componentRCentroids[], double componentCCentroids[], int COMPONENTS[], int countComponents);
void getCovariances(Matrix& LABEL, int numRows, int numCols, int componentAreas[], double componentRCentroids[], double componentCCentroids[], double componentVRCovariances[], double componentVCCovariances[], double componentVRCCovariances[], int COMPONENTS[], int countComponents);
Mat colorizeImage(Mat image, Mat outputImage, int numRows, int numCols, Matrix& LABEL, int COMPONENTS[], int countComponents);

int main(int argc, char** argv )
{
    if ( argc != 3 && argc != 4 )
    {
        printf("Error: The CCL function requires 3 (or optionally 4) arguments: the file to run, [the optional invert flag that accepts either 0 or 1], the input image filename, and the output image filename!\n");
        return -1;
    }
    Mat image, outputImage;
    if(argc == 3)
    {
        image = imread(argv[1], 1);
        outputImage = imread(argv[1], 1);
        if (!image.data || !outputImage.data)
        {
            printf("No image data\n");
            return -1;
        }
        cvtColor(image, image, COLOR_RGB2GRAY); //this is in case images are not already binarized. Since images are opened in color, they are first converted to grayscale, and then the image is converted to binary using 128 as a threshold value
        threshold(image, image, 128, 255, THRESH_BINARY);
    }
    else
    {
        image = imread(argv[2], 1);
        outputImage = imread(argv[2], 1);
        if (!image.data || !outputImage.data)
        {
            printf("No image data\n");
            return -1;
        }
        cvtColor(image, image, COLOR_RGB2GRAY);
        threshold(image, image, 128, 255, THRESH_BINARY);
        int invertFlag = atoi(argv[1]);
        if(invertFlag != 0){
            image = invertImage(image, invertFlag);
        }
    }
    int PARENT[SIZE];
    int numRows = image.rows;
    int numCols = image.cols;
    Matrix LABEL( numRows,vector<int>(numCols,0)); //initializes all LABEL Matrix values to 0
    for(int i = 0; i < SIZE; i++)
    {
        PARENT[i] = -1;
    }
    int countIML = createCCL(image, PARENT, SIZE, LABEL, numRows, numCols);
    int countComponents = combineCCL(PARENT, SIZE, LABEL, numRows, numCols);
    int COMPONENTS[countComponents];
    getComponents(COMPONENTS, countComponents, PARENT, SIZE);
    int componentAreas[countComponents];
    double componentRCentroids[countComponents], componentCCentroids[countComponents], componentVRCovariances[countComponents], componentVCCovariances[countComponents], componentVRCCovariances[countComponents];
    for(int i = 0; i < countComponents; i++)
    {
        componentAreas[i] = 0;
        componentRCentroids[i] = 0.0;
        componentCCentroids[i] = 0.0;
        componentVRCovariances[i] = 0.0;
        componentVCCovariances[i] = 0.0;
        componentVRCCovariances[i] = 0.0;
    }
    getAreas(LABEL, numRows, numCols, componentAreas, COMPONENTS, countComponents);
    getCentroids(LABEL, numRows, numCols, componentAreas, componentRCentroids, componentCCentroids, COMPONENTS, countComponents);
    getCovariances(LABEL, numRows, numCols, componentAreas, componentRCentroids, componentCCentroids, componentVRCovariances, componentVCCovariances, componentVRCCovariances, COMPONENTS, countComponents);
    int iterator = countComponents;
    if(countComponents > 10)
    {
        iterator = 10;
    }
    for(int i = 0; i < iterator - 1; i++)
    {
        for(int j = 0; j < iterator - i - 1; j++)
        {
            if(componentAreas[j] < componentAreas[j+1])
            {
                int tempArea = componentAreas[j];
                double tempRCentroid = componentRCentroids[j];
                double tempCCentroid = componentCCentroids[j];
                double tempVR = componentVRCovariances[j];
                double tempVC = componentVCCovariances[j];
                double tempVRC = componentVRCCovariances[j];
                componentAreas[j] = componentAreas[j+1];
                componentRCentroids[j] = componentRCentroids[j+1];
                componentCCentroids[j] = componentCCentroids[j+1];
                componentVRCovariances[j] = componentVRCovariances[j+1];
                componentVCCovariances[j] = componentVCCovariances[j+1];
                componentVRCCovariances[j] = componentVRCCovariances[j+1];
                componentAreas[j+1] = tempArea;
                componentRCentroids[j+1] = tempRCentroid;
                componentCCentroids[j+1] = tempCCentroid;
                componentVRCovariances[j+1] = tempVR;
                componentVCCovariances[j+1] = tempVC;
                componentVRCCovariances[j+1] = tempVRC;
            }
        }
    }
    cout << "Number of Components = " << countComponents << ", Number of Intermediate Labels = " << countIML << "\n";
    cout << "The object statistics are sorted in decreasing area, so object statistics may not appear in the same order as displayed\n";
    for(int i = 0; i < iterator; i++)
    {
        cout << "\nObject label " << i+1 << " is :\n";
        cout << "Area : " << componentAreas[i] << "\n";
        cout << "Centroid (r,c) : " << componentRCentroids[i] << "," << componentCCentroids[i] << "\n";
        cout << "Covariance (2x2 Matrix) (vr vrc vrc vc) : " << componentVRCovariances[i] << " " << componentVRCCovariances[i] << " " << componentVRCCovariances[i] << " " << componentVCCovariances[i] << "\n";
    }
    outputImage = colorizeImage(image, outputImage, numRows, numCols, LABEL, COMPONENTS, countComponents);
    if(argc == 3)
    {
        imwrite(argv[2], outputImage);
        namedWindow(argv[2], WINDOW_AUTOSIZE);
        imshow(argv[2], outputImage);
    }
    else
    {
        imwrite(argv[3], outputImage);
        namedWindow(argv[3], WINDOW_AUTOSIZE);
        imshow(argv[3], outputImage);
    }
    waitKey(0);
    return 0;
}

Mat invertImage(Mat image, int invert)
{
    int rows = image.rows;
    int columns = image.cols;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(image.at<uint8_t>(i,j) == 0)
            {
                image.at<uint8_t>(i,j) = 255;
            }
            else
            {
                image.at<uint8_t>(i,j) = 0;
            }
        }
    }
    return image;
}

int createCCL(Mat image, int PARENT[], int parentSize, Matrix& LABEL, int numRows, int numCols)
{
    int currentLabel = 0;
    for(int r = 0; r < numRows; r++)
    {
        for(int c = 0; c < numCols; c++)
        {
            if(image.at<uint8_t>(r,c) == 255)
            {
                int labelToBeAssigned = 0;
                if(r == 0)
                {
                    if(c == 0)
                    {
                        ++currentLabel;
                        labelToBeAssigned = currentLabel;
                        PARENT[labelToBeAssigned] = 0;
                    }
                    if(c != 0 && image.at<uint8_t>(r,c-1) == 0)
                    {
                        ++currentLabel;
                        labelToBeAssigned = currentLabel;
                        PARENT[labelToBeAssigned] = 0;
                    }
                    if(c != 0 && image.at<uint8_t>(r,c-1) == 255)
                    {
                        labelToBeAssigned = LABEL[r][c-1];
                    }
                }
                if(c == 0 && r != 0)
                {
                    if(image.at<uint8_t>(r-1,c) == 0 && image.at<uint8_t>(r-1,c+1) == 0)
                    {
                        ++currentLabel;
                        labelToBeAssigned = currentLabel;
                        PARENT[labelToBeAssigned] = 0;
                    }
                    if(image.at<uint8_t>(r-1,c) == 255)
                    {
                        labelToBeAssigned = LABEL[r-1][c];
                    }
                    if(image.at<uint8_t>(r-1,c) == 0 && image.at<uint8_t>(r-1, c+1) == 255)
                    {
                        labelToBeAssigned = LABEL[r-1][c+1];
                    }
                }
                if(c == (numCols-1) && r != 0)
                {
                    if(image.at<uint8_t>(r,c-1) == 0 && image.at<uint8_t>(r-1,c-1) == 0 && image.at<uint8_t>(r-1,c) == 0)
                    {
                        ++currentLabel;
                        labelToBeAssigned = currentLabel;
                        PARENT[labelToBeAssigned] = 0;
                    }
                    if(image.at<uint8_t>(r-1,c) == 255)
                    {
                        labelToBeAssigned = LABEL[r-1][c];
                    }
                    if(image.at<uint8_t>(r-1,c-1) == 255 && image.at<uint8_t>(r-1,c) == 0)
                    {
                        labelToBeAssigned = LABEL[r-1][c-1];
                    }
                    if(image.at<uint8_t>(r,c-1) == 255 && image.at<uint8_t>(r-1,c-1) == 0 && image.at<uint8_t>(r-1, c) == 0)
                    {
                        labelToBeAssigned = LABEL[r][c-1];
                    }
                }
                if(r != 0 && c != 0 && c != (numCols-1)) //pixels that are not on edges that may cause indexing out of bounds
                {
                    if(image.at<uint8_t>(r,c-1) == 0 && image.at<uint8_t>(r-1,c-1) == 0 && image.at<uint8_t>(r-1,c) == 0 && image.at<uint8_t>(r-1,c+1) == 0)//case 1
                    {
                        ++currentLabel;
                        labelToBeAssigned = currentLabel;
                        PARENT[labelToBeAssigned] = 0;
                    }
                    if(image.at<uint8_t>(r-1,c) == 255) //cases 5, 6, 7, 8, 13, 14, 15, 16
                    {
                        labelToBeAssigned = LABEL[r-1][c];
                    }
                    if(image.at<uint8_t>(r-1,c-1) == 255 && image.at<uint8_t>(r-1,c+1) == 255 && image.at<uint8_t>(r-1,c) == 0) //cases 11 and 12
                    {
                        labelToBeAssigned = unionComponents(LABEL[r-1][c-1], LABEL[r-1][c+1], PARENT, parentSize);
                    }
                    if(image.at<uint8_t>(r-1,c+1) == 255 && image.at<uint8_t>(r,c-1) == 255 && image.at<uint8_t>(r-1,c-1) == 0 && image.at<uint8_t>(r-1,c) == 0) //case 10
                    {
                        labelToBeAssigned = unionComponents(LABEL[r-1][c+1], LABEL[r][c-1], PARENT, parentSize);
                    }
                    if(image.at<uint8_t>(r-1,c-1) == 255 && image.at<uint8_t>(r-1,c) == 0 && image.at<uint8_t>(r-1,c+1) == 0) //cases 3 and 4
                    {
                        labelToBeAssigned = LABEL[r-1][c-1];
                    }
                    if(image.at<uint8_t>(r-1,c+1) == 255 && image.at<uint8_t>(r-1,c-1) == 0 && image.at<uint8_t>(r-1,c) == 0 && image.at<uint8_t>(r,c-1) == 0) //case 9
                    {
                        labelToBeAssigned = LABEL[r-1][c+1];
                    }
                    if(image.at<uint8_t>(r,c-1) == 255 && image.at<uint8_t>(r-1,c-1) == 0 && image.at<uint8_t>(r-1,c) == 0 && image.at<uint8_t>(r-1,c+1) == 0) //case 2
                    {
                        labelToBeAssigned = LABEL[r][c-1];
                    }
                }
                LABEL[r][c] = labelToBeAssigned;
            }
        }
    }
    return currentLabel;
}

int unionComponents(int X, int Y, int PARENT[], int parentSize)
{
    int j = findComponents(X, PARENT, parentSize);
    int k = findComponents(Y, PARENT, parentSize);
    if(j != k)
    {
        PARENT[k] = j;
    }
    return j;
}

int findComponents(int X, int PARENT[], int parentSize)
{
    int j = X;
    while(PARENT[j] != 0)
    {
        j = PARENT[j];
    }
    return j;
}

int combineCCL(int PARENT[], int parentSize, Matrix& LABEL, int numRows, int numCols)
{
    for(int i = 1; i < parentSize; i++)
    {
        int j = PARENT[i];
        while(PARENT[j] != 0 && PARENT[j] != -1)
        {
            j = PARENT[j];
        }
        PARENT[i] = j;
    }
    for(int r = 0; r < numRows; r++)
    {
        for(int c = 0; c < numCols; c++)
        {
            LABEL[r][c] = findComponents(LABEL[r][c], PARENT, parentSize);
        }
    }
    int countComponents = 0, index = 1;
    while(PARENT[index] != -1 && index < parentSize)
    {
        if(PARENT[index] == 0)
        {
            ++countComponents;
        }
        ++index;
    }
    return countComponents;
}

void getComponents(int COMPONENTS[], int componentsSize, int PARENT[], int parentSize)
{
    int componentCount = 0, index = 1;
    while(PARENT[index] != -1 && index < parentSize)
    {
        if(PARENT[index] == 0)
        {
            COMPONENTS[componentCount] = index;
            ++componentCount;
        }
        ++index;
    }
}

void getAreas(Matrix& LABEL, int numRows, int numCols, int componentAreas[], int COMPONENTS[], int countComponents)
{
    for(int r = 0; r < numRows; r++)
    {
        for(int c = 0; c < numCols; c++)
        {
            if(LABEL[r][c] > 0)
            {
                int index = 0;
                while(LABEL[r][c] != COMPONENTS[index])
                {
                    ++index;
                }
                componentAreas[index] += 1;
            }
        }
    }
}

void getCentroids(Matrix& LABEL, int numRows, int numCols, int componentAreas[], double componentRCentroids[], double componentCCentroids[], int COMPONENTS[], int countComponents)
{
    for(int r = 0; r < numRows; r++)
    {
        for(int c = 0; c < numCols; c++)
        {
            if(LABEL[r][c] > 0)
            {
                int index = 0;
                while(LABEL[r][c] != COMPONENTS[index])
                {
                    ++index;
                }
                componentRCentroids[index] += c;
                componentCCentroids[index] += r;
            }
        }
    }
    for(int i = 0; i < countComponents; i++)
    {
        componentRCentroids[i] = componentRCentroids[i] / componentAreas[i];
        componentCCentroids[i] = componentCCentroids[i] / componentAreas[i];
    }
}

void getCovariances(Matrix& LABEL, int numRows, int numCols, int componentAreas[], double componentRCentroids[], double componentCCentroids[], double componentVRCovariances[], double componentVCCovariances[], double componentVRCCovariances[], int COMPONENTS[], int countComponents)
{
    for(int r = 0; r < numRows; r++)
    {
        for(int c = 0; c < numCols; c++)
        {
            if(LABEL[r][c] > 0)
            {
                int index = 0;
                while(LABEL[r][c] != COMPONENTS[index])
                {
                    ++index;
                }
                componentVRCovariances[index] += ((c - componentRCentroids[index])*(c - componentRCentroids[index]));
                componentVCCovariances[index] += ((r - componentCCentroids[index])*(r - componentCCentroids[index]));
                componentVRCCovariances[index] += ((c - componentRCentroids[index])*(r - componentCCentroids[index]));
            }
        }
    }
    for(int i = 0; i < countComponents; i++)
    {
        componentVRCovariances[i] = componentVRCovariances[i] / componentAreas[i];
        componentVCCovariances[i] = componentVCCovariances[i] / componentAreas[i];
        componentVRCCovariances[i] = componentVRCCovariances[i] / componentAreas[i];
    }
}

Mat colorizeImage(Mat image, Mat outputImage, int numRows, int numCols, Matrix& LABEL, int COMPONENTS[], int countComponents)
{
    int blue[20], green[20], red[20];
    srand(time(NULL));
    for(int i = 0; i < 20; i++)
    {
        blue[i] = rand() % 256;
        green[i] = rand() % 256;
        red[i] = rand() % 256;
    }
    for(int r = 0; r < numRows; r++)
    {
        for(int c = 0; c < numCols; c++)
        {
            if(image.at<uint8_t>(r,c) == 255)
            {
                int componentIndex = LABEL[r][c] % 20;
                outputImage.at<Vec3b>(r,c)[0] = blue[componentIndex];
                outputImage.at<Vec3b>(r,c)[1] = green[componentIndex];
                outputImage.at<Vec3b>(r,c)[2] = red[componentIndex];
            }
            else
            {
                outputImage.at<Vec3b>(r,c)[0] = 0;
                outputImage.at<Vec3b>(r,c)[1] = 0;
                outputImage.at<Vec3b>(r,c)[2] = 0;
            }
        }
    }
    return outputImage;
}
