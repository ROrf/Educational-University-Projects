import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
import math

def main():
    imageNotRead = True
    while(imageNotRead):
        filename = input("Please provide an image filename:\n")
        img = cv.imread(filename)
        grayImg = cv.imread(filename, 0)
        if img is None or grayImg is None:
            print("Error: Image data not found. Please try again!\n")
        else:
            imageNotRead = False

    sobelGx = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]]) 
    sobelGy = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])  

    if(len(img.shape) == 3):
        rows, columns, channels = img.shape 
        imgIx = np.zeros((rows, columns, channels))
        imgIy = np.zeros((rows, columns, channels))
        imgEx = np.zeros((rows, columns, channels))
        imgEy = np.zeros((rows, columns, channels))
        magnitude = np.zeros((rows, columns, channels))

        for channel in range(channels):
            for r in range(0, rows-1):
                for c in range(0,columns-1):
                    imgIx[r,c,channel] = (sobelGx[0,0]*img[r-1,c-1,channel]) + (sobelGx[0,1]*img[r-1,c,channel]) + (sobelGx[0,2]*img[r-1,c+1,channel]) + (sobelGx[1,0]*img[r,c-1,channel]) + (sobelGx[1,1]*img[r,c,channel]) + (sobelGx[1,2]*img[r,c+1,channel]) + (sobelGx[2,0]*img[r+1,c-1,channel]) + (sobelGx[2,1]*img[r+1,c,channel]) + (sobelGx[2,2]*img[r+1,c+1,channel])
                    imgEx[r,c,channel] = ((imgIx[r-1,c-1,channel] + 255)/510)*255
                    imgIy[r,c,channel] = (sobelGy[0,0]*img[r-1,c-1,channel]) + (sobelGy[0,1]*img[r-1,c,channel]) + (sobelGy[0,2]*img[r-1,c+1,channel]) + (sobelGy[1,0]*img[r,c-1,channel]) + (sobelGy[1,1]*img[r,c,channel]) + (sobelGy[1,2]*img[r,c+1,channel]) + (sobelGy[2,0]*img[r+1,c-1,channel]) + (sobelGy[2,1]*img[r+1,c,channel]) + (sobelGy[2,2]*img[r+1,c+1,channel])
                    imgEy[r,c,channel] = ((imgIy[r-1,c-1,channel] + 255)/510)*255
                    magnitude[r,c,channel] = np.sqrt(pow(imgIx[r-1,c-1,channel], 2.0) + pow(imgIy[r-1,c-1,channel], 2.0))

        outputImgEx = imgEx[:,:,0] + imgEx[:,:,1] + imgEx[:,:,2]
        outputImgEy = imgEy[:,:,0] + imgEy[:,:,1] + imgEy[:,:,2]
        outputMagnitude = magnitude[:,:,0] + magnitude[:,:,1] + magnitude[:,:,2]
        plt.figure()
        plt.title(filename + " Ex")
        plt.imshow(outputImgEx)
        plt.show()
        plt.figure()
        plt.title(filename + " Ey")
        plt.imshow(outputImgEy)
        plt.show()
        plt.figure()
        plt.title(filename + " Magnitude")
        plt.imshow(outputMagnitude)
        plt.show()
        
                    
    else:
        rows, columns = img.shape
        imgIx = np.zeros((rows, columns))
        imgIy = np.zeros((rows, columns))
        imgEx = np.zeros((rows, columns))
        imgEy = np.zeros((rows, columns))
        magnitude = np.zeros((rows, columns))

        for r in range(0, rows-1):
            for c in range(0, columns-1):
                imgIx[r,c] = (sobelGx[0,0]*img[r-1,c-1]) + (sobelGx[0,1]*img[r-1,c]) + (sobelGx[0,2]*img[r-1,c+1]) + (sobelGx[1,0]*img[r,c-1]) + (sobelGx[1,1]*img[r,c]) + (sobelGx[1,2]*img[r,c+1]) + (sobelGx[2,0]*img[r+1,c-1]) + (sobelGx[2,1]*img[r+1,c]) + (sobelGx[2,2]*img[r+1,c+1])
                imgEx[r,c] = ((imgIx[r-1,c-1] + 255)/510)*255
                imgIy[r,c] = (sobelGy[0,0]*img[r-1,c-1]) + (sobelGy[0,1]*img[r-1,c]) + (sobelGy[0,2]*img[r-1,c+1]) + (sobelGy[1,0]*img[r,c-1]) + (sobelGy[1,1]*img[r,c]) + (sobelGy[1,2]*img[r,c+1]) + (sobelGy[2,0]*img[r+1,c-1]) + (sobelGy[2,1]*img[r+1,c]) + (sobelGy[2,2]*img[r+1,c+1])
                imgEy[r,c] = ((imgIy[r-1,c-1] + 255)/510)*255
                magnitude[r,c] = np.sqrt(pow(imgIx[r-1,c-1], 2.0) + pow(imgIy[r-1,c-1], 2.0))
                
        
        outputImgEx = imgEx
        outputImgEy = imgEy
        outputMagnitude = magnitude
        plt.figure()
        plt.title(filename + " Ex")
        plt.imshow(outputImgEx, cmap="gray")
        plt.show()
        plt.figure()
        plt.title(filename + " Ey")
        plt.imshow(outputImgEy, cmap="gray")
        plt.show()
        plt.figure()
        plt.title(filename + " Magnitude")
        plt.imshow(outputMagnitude, cmap="gray")
        plt.show()

    grayImgIx = np.zeros((rows, columns))
    grayImgIy = np.zeros((rows, columns))
    if(len(img.shape) == 3):
        for r in range(0, rows-1):
            for c in range(0, columns-1):
                grayImgIx[r,c] = (sobelGx[0,0]*grayImg[r-1,c-1]) + (sobelGx[0,1]*grayImg[r-1,c]) + (sobelGx[0,2]*grayImg[r-1,c+1]) + (sobelGx[1,0]*grayImg[r,c-1]) + (sobelGx[1,1]*grayImg[r,c]) + (sobelGx[1,2]*grayImg[r,c+1]) + (sobelGx[2,0]*grayImg[r+1,c-1]) + (sobelGx[2,1]*grayImg[r+1,c]) + (sobelGx[2,2]*grayImg[r+1,c+1])
                grayImgIy[r,c] = (sobelGy[0,0]*grayImg[r-1,c-1]) + (sobelGy[0,1]*grayImg[r-1,c]) + (sobelGy[0,2]*grayImg[r-1,c+1]) + (sobelGy[1,0]*grayImg[r,c-1]) + (sobelGy[1,1]*grayImg[r,c]) + (sobelGy[1,2]*grayImg[r,c+1]) + (sobelGy[2,0]*grayImg[r+1,c-1]) + (sobelGy[2,1]*grayImg[r+1,c]) + (sobelGy[2,2]*grayImg[r+1,c+1])
    else:
        grayImgIx = imgIx
        grayImgIy = imgIy
        
    angle = np.zeros((rows, columns))
    
    for r in range(0, rows-1):
        for c in range(0, columns-1):
            if(grayImgIx[r,c] == 0 and grayImgIy[r,c] == 0):
                angle[r,c] = 0
            else:
                angle[r,c] = math.atan2(grayImgIy[r,c], grayImgIx[r,c])
                angle[r,c] = ((angle[r,c]/math.pi)+1)*180

    plt.figure()
    plt.title(filename + " Orientation")
    plt.imshow(angle, cmap="jet")
    plt.colorbar()
    plt.show()
                
    
main()
