import cv2 as cv
import numpy as np
import time

def main():
    imageNotRead = True
    while(imageNotRead):
        filename = input("Please provide an image filename:\n")
        img = cv.imread(filename)
        if (len(img.shape) == 3):
            img = cv.imread(filename, 0)
        if img is None:
            print("Error: Image data not found. Please try again!\n")
        else:
            imageNotRead = False

    rows, columns = img.shape
    s = 3
    sMax = 21
    
    padding = sMax//2

    for i in range(s, sMax+2, 2):

        img_w_padding = np.zeros((rows + 2*padding, columns + 2*padding)).astype(np.uint8)
        img_w_padding[padding: -padding, padding: -padding] = img

        img_filtered = np.zeros(img_w_padding.shape).astype(np.uint8)

        start_time = time.time()
        
        for r in range(padding, rows+padding+1):
            for c in range(padding, columns+padding+1):
                img_filtered[r,c] = StageA(img_w_padding, r, c, i, sMax)

        print("The window size of %i" % i + " took %s seconds" % (time.time() - start_time))

        cv.namedWindow("Adaptive Median Filtered Image of Window Size %i" % i, cv.WINDOW_NORMAL)
        cv.imshow("Adaptive Median Filtered Image of Window Size %i" % i, img_filtered[padding: -padding, padding: -padding])

        cv.waitKey(20000)
        cv.destroyAllWindows()
        

def StageA(mat, x, y, s, sMax):
    window = mat[x - (s//2): x + (s//2) + 1, y - (s//2): y + (s//2) + 1]
    Zmin = np.min(window)
    Zmed = np.median(window)
    Zmax = np.max(window)

    A1 = int(Zmed) - int(Zmin)
    A2 = int(Zmed) - int(Zmax)

    if A1 > 0 and A2 < 0:
        return StageB(window)
    else:
        s += 2
        if s <= sMax:
            return StageA(mat, x, y, s, sMax)
        else:
            return Zmed

def StageB(window):
    rows, columns = window.shape
    Zmin = np.min(window)
    Zmed = np.median(window)
    Zmax = np.max(window)

    Zxy = window[rows//2, columns//2]
    B1 = int(Zxy) - int(Zmin)
    B2 = int(Zxy) - int(Zmax)

    if B1 > 0 and B2 < 0:
        return Zxy
    else:
        return Zmed
    
main()
