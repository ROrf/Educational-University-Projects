import cv2 as cv
import numpy as np
from sklearn import svm

def main():

    # Dynamic Line Haar Feature Kernel
    k1_2x2 = np.array([[-1,1],[1,-1]])
    k1_4x4 = np.array([[-1,-1,1,1],[-1,-1,1,1],[1,1,-1,-1],[1,1,-1,-1]])
    k1_8x8 = np.array([[-1,-1,-1,-1,1,1,1,1],[-1,-1,-1,-1,1,1,1,1],[-1,-1,-1,-1,1,1,1,1],[-1,-1,-1,-1,1,1,1,1],[1,1,1,1,-1,-1,-1,-1],[1,1,1,1,-1,-1,-1,-1],[1,1,1,1,-1,-1,-1,-1],[1,1,1,1,-1,-1,-1,-1]])
    k1_16x16 = np.zeros((16,16), int)
    for r in range(16):
        for c in range(16):
            if((r < 8 and c > 7) or (r > 7 and c < 8)):
                k1_16x16[r,c] = 1
            else:
                k1_16x16[r,c] = -1
    k1_32x32 = np.zeros((32,32), int)
    for r in range(32):
        for c in range(32):
            if((r < 16 and c > 15) or (r > 15 and c < 16)):
                k1_32x32[r,c] = 1
            else:
                k1_32x32[r,c] = -1

    # Dyanmic Edge Haar Feature Kernel
    k2_2x2 = np.array([[1,-1],[1,-1]])
    k2_4x4 = np.array([[1,1,-1,-1],[1,1,-1,-1],[1,1,-1,-1],[1,1,-1,-1]])
    k2_8x8 = np.array([[1,1,1,1,-1,-1,-1,-1],[1,1,1,1,-1,-1,-1,-1],[1,1,1,1,-1,-1,-1,-1],[1,1,1,1,-1,-1,-1,-1],[1,1,1,1,-1,-1,-1,-1],[1,1,1,1,-1,-1,-1,-1],[1,1,1,1,-1,-1,-1,-1],[1,1,1,1,-1,-1,-1,-1]])
    k2_16x16 = np.zeros((16,16), int)
    for r in range(16):
        for c in range(16):
            if(c < 8):
                k2_16x16[r,c] = 1
            else:
                k2_16x16[r,c] = -1
    k2_32x32 = np.zeros((32,32), int)
    for r in range(32):
        for c in range(32):
            if(c < 16):
                k2_32x32[r,c] = 1
            else:
                k2_32x32[r,c] = -1

    # Secondary Dynamic Edge Haar Feature Kernel
    k3_2x2 = np.array([[1,1],[-1,-1]])
    k3_4x4 = np.array([[1,1,1,1],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1]])
    k3_8x8 = np.array([[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1,-1]])
    k3_16x16 = np.zeros((16,16), int)
    for r in range(16):
        for c in range(16):
            if(r > 7):
                k3_16x16[r,c] = 1
            else:
                k3_16x16[r,c] = -1
    k3_32x32 = np.zeros((32,32), int)
    for r in range(32):
        for c in range(32):
            if(r > 15):
                k3_32x32[r,c] = 1
            else:
                k3_32x32[r,c] = -1

    # Third Dynamic Edge Haar Feature Kernel
    k4_4x4 = np.array([[1,-1,-1,1],[1,-1,-1,1],[1,-1,-1,1],[1,-1,-1,1]])
    k4_8x8 = np.array([[1,1,-1,-1,-1,-1,1,1],[1,1,-1,-1,-1,-1,1,1],[1,1,-1,-1,-1,-1,1,1],[1,1,-1,-1,-1,-1,1,1],[1,1,-1,-1,-1,-1,1,1],[1,1,-1,-1,-1,-1,1,1],[1,1,-1,-1,-1,-1,1,1],[1,1,-1,-1,-1,-1,1,1]])
    k4_16x16 = np.zeros((16,16), int)
    for r in range(16):
        for c in range(16):
            if(c < 4 or c > 11):
                k4_16x16[r,c] = 1
            else:
                k4_16x16[r,c] = -1
    k4_32x32 = np.zeros((32,32), int)
    for r in range(32):
        for c in range(32):
            if(c < 8 or c > 23):
                k4_32x32[r,c] = 1
            else:
                k4_32x32[r,c] = -1

    # Training Set Pictures
    imageFileNames = ["FacingForwardObama.jpg", "RandomFace1.jpg", "RandomFace2.jpg", "RandomFace3.jpg", "RandomFace4.jpg", "RandomFace5.jpg", "RandomFace6.jpg", "RandomFace7.jpg", "RandomFace8.jpg"]

    # Determining the Size of the Training Set Inputs
    trainingSetSize = 0

    for imageFileName in imageFileNames:
        imageNotRead = True
        while(imageNotRead):
            image = cv.imread(imageFileName, 0)
            if image is None:
                print("Error: Image data not found. Program will now terminate!\n")
                return -1
            else:
                imageNotRead = False

        # Shrinking Image, as Scikit's SVC has Performance Issues with Large Numbers of Pixels (> 10,000)
        scale_percent = 11
        width = int(image.shape[1] * scale_percent / 100)
        height = int(image.shape[0] * scale_percent / 100)
        dim = (width, height)

        image = cv.resize(image, dim, interpolation = cv.INTER_AREA)
        
        rows, columns = image.shape
        trainingSetSize = trainingSetSize + (rows*columns)

    trainingData = np.zeros((trainingSetSize, 19), int) 
    trainingTarget = np.zeros(trainingSetSize, int)

    # Looping Through All the Training Images
    index = 0
    for imageFileName in imageFileNames:

        # Reading Each Image in Grayscale
        imageNotRead = True
        while(imageNotRead):
            image = cv.imread(imageFileName, 0)
            if image is None:
                print("Error: Image data not found. Program will now terminate!\n")
                return -1
            else:
                imageNotRead = False

        # Shrinking Image, to Match Previous Calculated Values
        scale_percent = 11
        width = int(image.shape[1] * scale_percent / 100)
        height = int(image.shape[0] * scale_percent / 100)
        dim = (width, height)

        image = cv.resize(image, dim, interpolation = cv.INTER_AREA)
        
        # Convolving All the Kernels with the Selected Image
        out1 = cv.filter2D(image, -1, k1_2x2)
        out2 = cv.filter2D(image, -1, k1_4x4)
        out3 = cv.filter2D(image, -1, k1_8x8)
        out4 = cv.filter2D(image, -1, k1_16x16)
        out5 = cv.filter2D(image, -1, k1_32x32)
        out6 = cv.filter2D(image, -1, k2_2x2)
        out7 = cv.filter2D(image, -1, k2_4x4)
        out8 = cv.filter2D(image, -1, k2_8x8)
        out9 = cv.filter2D(image, -1, k2_16x16)
        out10 = cv.filter2D(image, -1, k2_32x32)
        out11 = cv.filter2D(image, -1, k3_2x2)
        out12 = cv.filter2D(image, -1, k3_4x4)
        out13 = cv.filter2D(image, -1, k3_8x8)
        out14 = cv.filter2D(image, -1, k3_16x16)
        out15 = cv.filter2D(image, -1, k3_32x32)
        out16 = cv.filter2D(image, -1, k4_4x4)
        out17 = cv.filter2D(image, -1, k4_8x8)
        out18 = cv.filter2D(image, -1, k4_16x16)
        out19 = cv.filter2D(image, -1, k4_32x32)

        # Obtaining the 'Ground Truth' Data for the Image
        faceCascade = cv.CascadeClassifier(cv.data.haarcascades + "haarcascade_frontalface_alt.xml")
        detectedFaces = faceCascade.detectMultiScale(image)
        rows, columns = image.shape
        pixelIsFace = np.zeros((rows, columns), int)
        for (column, row, width, height) in detectedFaces:
            for r in range(row, height+1):
                for c in range(column, width+1):
                    pixelIsFace[r,c] = 1

        # Looping Through Each Pixel to Obtain Features
        for r in range(0, rows):
            for c in range(0, columns-1):
                f1 = out1[r,c]
                f2 = out2[r,c]
                f3 = out3[r,c]
                f4 = out4[r,c]
                f5 = out5[r,c]
                f6 = out6[r,c]
                f7 = out7[r,c]
                f8 = out8[r,c]
                f9 = out9[r,c]
                f10 = out10[r,c]
                f11 = out11[r,c]
                f12 = out12[r,c]
                f13 = out13[r,c]
                f14 = out14[r,c]
                f15 = out15[r,c]
                f16 = out16[r,c]
                f17 = out17[r,c]
                f18 = out18[r,c]
                f19 = out19[r,c]

                # Sets the Appropriate Values in the Training Set Input Arrays
                intermediateFeatureArray = [f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19]
                for i in range(0, 19):
                    trainingData[index, i] = intermediateFeatureArray[i]
                trainingTarget[index] = pixelIsFace[r,c]
                
                # Increment the Index of the Arrays
                index = index + 1
            index = index + 1

    # Training the Data Set of Images
    print("Starting training...")
    clf = svm.SVC(gamma=0.001, C = 100.)
    clf.fit(trainingData, trainingTarget)
    print("Finished training!")

    # Read in Individual Image to be Processed
    imageNotRead = True
    while(imageNotRead):
        filename = input("Please provide an image filename:\n")
        img = cv.imread(filename, 1)
        copyImg = cv.imread(filename, 1)
        grayImg = cv.imread(filename, 0)
        if img is None or grayImg is None or copyImg is None:
            print("Error: Image data not found. Please try again!\n")
        else:
            imageNotRead = False

    # Shrinking Image to Match Input Training Images
    scale_percent = 11
    width = int(grayImg.shape[1] * scale_percent / 100)
    height = int(grayImg.shape[0] * scale_percent / 100)
    dim = (width, height)

    grayImg = cv.resize(grayImg, dim, interpolation = cv.INTER_AREA)
    #img = cv.resize(img, dim, interpolation = cv.INTER_AREA)

    # Create Input for Prediction
    rows, columns = grayImg.shape
    predictionImage = np.zeros((rows*columns, 19), int) 
    
    out1 = cv.filter2D(grayImg, -1, k1_2x2)
    out2 = cv.filter2D(grayImg, -1, k1_4x4)
    out3 = cv.filter2D(grayImg, -1, k1_8x8)
    out4 = cv.filter2D(grayImg, -1, k1_16x16)
    out5 = cv.filter2D(grayImg, -1, k1_32x32)
    out6 = cv.filter2D(grayImg, -1, k2_2x2)
    out7 = cv.filter2D(grayImg, -1, k2_4x4)
    out8 = cv.filter2D(grayImg, -1, k2_8x8)
    out9 = cv.filter2D(grayImg, -1, k2_16x16)
    out10 = cv.filter2D(grayImg, -1, k2_32x32)
    out11 = cv.filter2D(grayImg, -1, k3_2x2)
    out12 = cv.filter2D(grayImg, -1, k3_4x4)
    out13 = cv.filter2D(grayImg, -1, k3_8x8)
    out14 = cv.filter2D(grayImg, -1, k3_16x16)
    out15 = cv.filter2D(grayImg, -1, k3_32x32)
    out16 = cv.filter2D(grayImg, -1, k4_4x4)
    out17 = cv.filter2D(grayImg, -1, k4_8x8)
    out18 = cv.filter2D(grayImg, -1, k4_16x16)
    out19 = cv.filter2D(grayImg, -1, k4_32x32)

    index = 0
    for r in range(0, rows):
        for c in range(0, columns-1):
            f1 = out1[r,c]
            f2 = out2[r,c]
            f3 = out3[r,c]
            f4 = out4[r,c]
            f5 = out5[r,c]
            f6 = out6[r,c]
            f7 = out7[r,c]
            f8 = out8[r,c]
            f9 = out9[r,c]
            f10 = out10[r,c]
            f11 = out11[r,c]
            f12 = out12[r,c]
            f13 = out13[r,c]
            f14 = out14[r,c]
            f15 = out15[r,c]
            f16 = out16[r,c]
            f17 = out17[r,c]
            f18 = out18[r,c]
            f19 = out19[r,c]

            intermediateFeatureArray = [f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16, f17, f18, f19]
            for i in range(0, 19):
                predictionImage[index, i] = intermediateFeatureArray[i]
                
            index = index + 1
        index = index + 1

    # Creates Prediction

    facePredictions = clf.predict(predictionImage)

    r_scale = int(img.shape[0] / height)
    c_scale = int(img.shape[1] / width)
    index = 0
    for r in range(0, rows):
        for c in range(0, columns-1):
            r_index = int(r * 100 / scale_percent)
            c_index = int(c * 100 / scale_percent)
            if(facePredictions[index] == 1):
                copyImg[r_index:(r_index+r_scale+1), c_index:(c_index+c_scale+1)] = [0,0,255]

            index = index + 1
        index = index + 1

    rows = img.shape[0]
    columns = img.shape[1]
    for r in range(0,rows):
        for c in range(0,columns-1):
            if((r < (rows-1)) and (r > 0) and (copyImg[r+1,c, 2] == 255) and (copyImg[r-1,c,2] != 255)):
                img[r,c] = [0,0,255]
            if((r < (rows-1)) and (r > 0) and (copyImg[r-1,c, 2] == 255) and (copyImg[r+1,c,2] != 255)):
                img[r,c] = [0,0,255]
            if((c < (columns-2)) and (c > 0) and (copyImg[r,c+1, 2] == 255) and (copyImg[r,c-1,2] != 255)):
                img[r,c] = [0,0,255]
            if((c < (columns-2)) and (c > 0) and (copyImg[r,c-1, 2] == 255) and (copyImg[r,c+1,2] != 255)):
                img[r,c] = [0,0,255]

    cv.imshow("Intermediate Faces", copyImg)
    cv.imshow("Detected Faces Image", img)
    cv.waitKey(10000) 
    cv.destroyAllWindows()
    

main()
