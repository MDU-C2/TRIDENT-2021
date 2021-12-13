import matplotlib.pyplot as plt
import numpy as np
import cv2
import os
import math
from numpy.core.fromnumeric import amax
from numpy.lib.function_base import median, mean
from numpy.lib.npyio import savetxt


# Normalises the input
# img - image, any number of channels
# out - normalised image
def norm(img):
    return (img - np.amin(img)) / (np.amax(img) - np.amin(img))


# For visualisation and debugging, merges 6 images together which can be printed
# im1-2 - 3ch 
# im3-6 - 1ch
# out - concatenation of the 6 input images
def printImages(im1, im2, im3, im4, im5, im6):
    col1 = np.concatenate((im1, im2), axis=0)
    col2 = np.concatenate((cv2.cvtColor(im3, cv2.COLOR_GRAY2BGR), cv2.cvtColor(im4, cv2.COLOR_GRAY2BGR)), axis=0)
    col3 = np.concatenate((cv2.cvtColor(im5, cv2.COLOR_GRAY2BGR), cv2.cvtColor(im6, cv2.COLOR_GRAY2BGR)), axis=0)
    return np.concatenate((col1, col2, col3), axis=1)


# Finds primary line in greyscale image
# img - horizontal or vertical image from optical flow output
# out - [[rStart, cStart], [rEnd, cEnd]] lines
def getLine(img):
    # ----------- MORPHOLOGY FOR CENTER LOCALISATION ---------------------------
    im = (img > 0).astype(np.float32)
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(30,30))
    closing = cv2.morphologyEx(im, cv2.MORPH_CLOSE, kernel)

    # ------------- FIND LINE ------------------------------------------------
    edges = cv2.Canny(closing.astype(np.uint8),50,150,apertureSize = 7)
    lines = cv2.HoughLines(edges,1,np.pi/180, 30)
    if lines is not None:
        # Magic math stuff
        r = lines[0][0][0]
        theta = lines[0][0][1]
        a = np.cos(theta)
        b = np.sin(theta)
        x0 = a*r
        y0 = b*r
        x1 = int(x0 + 1000*(-b))
        y1 = int(y0 + 1000*(a))
        x2 = int(x0 - 1000*(-b))
        y2 = int(y0 - 1000*(a))
        
        cv2.line(closing,(x1,y1), (x2,y2), .5, 2)

        if showPrints:
            print('Lines were found')
        return [[x1, y1], [x2, y2]]
    else:
        if showPrints:
            print('No lines were found')
        return None
    

# Calculates intersection between the lines
# line1-2 - [[rStart, cStart], [rEnd, cEnd]] lines
# out - (r, c) coordinates of intersection
def getIntersection(line1, line2):
    # Magic math stuff
    xdiff = (line1[0][0] - line1[1][0], line2[0][0] - line2[1][0])
    ydiff = (line1[0][1] - line1[1][1], line2[0][1] - line2[1][1])

    def det(a, b):
        return a[0] * b[1] - a[1] * b[0]

    div = det(xdiff, ydiff)
    # if denominator will be zero
    if div == 0:
        return None

    d = (det(*line1), det(*line2))
    x = int(det(d, xdiff) / div)
    y = int(det(d, ydiff) / div)
    return x, y


# Calculates rotation angle (only works when the rotation center is within image)
# angle - angle each pt is moving in since last frame, created from output from optical flow
# magnitude - magnitude of which each pt has moved since last frame, created from output from optical flow
# center - coordinates of rotation center
# n - the root of the number of samples that will be taken for the rotation calculation, 3 works fine
# frame - the current image in the video stream, only there for visualisation purposes
# out - angle of rotation in degrees, + -> cw Naiad movement, - -> ccw Naiad movement
def getAngle(angle, magnitude, center, n, frame):
    # rotation is given in degrees
    (r,c) = angle.shape
    magMax = amax(magnitude)
    rotations = []
    for init_r in range(int(r/(n*2)), int(r-r/(n*2)+1), int(r/n)):      # +1 for rounding errors
        # print('init_r = ' + str(init_r))
        for init_c in range(int(c/(n*2)), int(c-c/(n*2)+1), int(c/n)): 
            # print('init_c = ' + str(init_c))
            # print('sample angle = ' + str(angle[init_r, init_c]*360))

            if magnitude[init_r, init_c] < 0.1 * magMax:
                continue

            goal_r = int(init_r + magnitude[init_r, init_c] * math.cos(np.pi/2 - angle[init_r, init_c]*2*np.pi))       # (angle*360) * (2*pi/360)
            # print('angle = ' + str(angle[init_r, init_c]*360) + ', magnitude = ' + str(magnitude[init_r, init_c]) )
            # print('goal_r = ' + str(goal_r))
            goal_c = int(init_c + magnitude[init_r, init_c] * math.sin(np.pi/2 - angle[init_r, init_c]*2*np.pi))
            # print('goal_c = ' + str(goal_c))
            alpha = math.atan2(center[0]-goal_r, center[1]-goal_c) * 180 / np.pi
            beta = math.atan2(center[0]-init_r, center[1]-init_c) * 180 / np.pi
            rotations.append(beta - alpha)

            # -------- VISUALISATION -------------------
            colour = (np.random.rand(3)*255).astype(np.int).tolist()
            if drawPts:
                cv2.circle(frame, (init_c, init_r), radius=4, color=colour, thickness=-1)
                cv2.circle(frame, (goal_c, goal_r), radius=4, color=[255,255,255], thickness=-1)
    # print('rotations = ' + str(rotations))
    return median(rotations)


# ----------- INPUTS -------------------------------------------------------------
videopath = '../optical_flow_test/Naiad_in_trondheim_firstTrial_pt1_2.mp4'
resultpath = './opticalFlowResult.txt'
drawPts = True
showImages = False
showPrints = False


# ------------ VIDEO CAP START ----------------------------------------
cap = cv2.VideoCapture(videopath)
ret, frame = cap.read()
prev = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
result = np.empty((1,3))

while(cap.isOpened()):
    # Read next frame 
    ret, frame = cap.read()
    if not ret:
        print('End of video, exiting loop')
        break
    
    # Initialisations
    next = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    flow = np.zeros((prev.shape[0], prev.shape[1], 2), dtype = np.dtype('float32'))
    magn = np.zeros((prev.shape[0], prev.shape[1]), dtype = np.dtype('float32'))
    ang = np.zeros((prev.shape[0], prev.shape[1]), dtype = np.dtype('float32'))
    
    # ------------ OPTICAL FLOW ----------------------------------
    cv2.calcOpticalFlowFarneback(prev, next, flow, 0.5, 3, 15, 3, 5, 1.2, 0)
    (horz, vert) = cv2.split(flow)
    meanH = mean(horz)
    meanV = mean(vert)
    cv2.cartToPolar(horz, vert, magn, ang, True)
    ang /= 360
    
    # ----------- CALCULATING ROTATION ---------------------------------
    # define drawPts to draw center of rotation and points for the rotation calculations

    horzLine = getLine(horz)
    vertLine = getLine(vert)

    # if lines could be found in both horizontal and vertical images
    if (horzLine and vertLine) is not None:
        intersection = getIntersection(horzLine, vertLine)
        if intersection is None:
            rot = 0
        else:
            if drawPts:
                cv2.circle(frame, intersection, radius=20, color=(255, 0, 255), thickness=-1)
            
            n = 3       # n is the number of quadrants for which a central rotation will be calculated, shouldn't make too much difference
            rot = getAngle(ang, magn, intersection, n, frame)
    else:
        ang = np.zeros(ang.shape, ang.dtype)
        rot = 0.0
    
    # Final estimated rotation
    if showPrints:
        print('rotation angle = ' + str(rot))
    
    # Show resulting images
    if showImages:
        cv2.imshow('video', frame)
        cv2.imshow('angle', ang)
        cv2.imshow('horz', norm(horz))
        cv2.imshow('vert', norm(vert))
        cv2.imshow('magnitude', norm(magn))
        cv2.waitKey(15)
        
        if abs(rot) > 0.0005:
            cv2.waitKey(0)

    # Save values to file
    result = np.append(result, [[meanH, meanV, rot]], axis=0)

    prev = next

savetxt(resultpath, result, fmt='%.5f', delimiter=',', header='Horizontal Translation, Vertical Translation, Rotation')
cap.release()
cv2.destroyAllWindows()
