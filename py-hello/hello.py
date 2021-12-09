import matplotlib.pyplot as plt
import numpy as np
import cv2
import os
import math

from numpy.lib.function_base import median, mean


def plot_quiver(ax, flow, colourmap, margin=0, **kwargs):
    """Plots less dense quiver field.

    Args:
        ax: Matplotlib axis
        flow: motion vectors
        spacing: space (px) between each arrow in grid
        margin: width (px) of enclosing region without arrows
        kwargs: quiver kwargs (default: angles="xy", scale_units="xy")
    """
    h, w, *_ = flow[0].shape

    x = np.linspace(margin, w - margin, w - margin, dtype=np.int64)
    y = np.linspace(margin, h - margin, h - margin, dtype=np.int64)

    # flow = flow[np.ix_(y, x)]
    u = flow[0]
    v = flow[1]

    kwargs = {**dict(angles="xy", scale_units="xy"), **kwargs}
    ax.quiver(x, y, u, v, colourmap, **kwargs)

    ax.set_ylim(sorted(ax.get_ylim(), reverse=True))
    ax.set_aspect("equal")


def norm(im):
    return (im - np.amin(im)) / (np.amax(im) - np.amin(im))


def printImages(frame, hsv, hor, ver, mag, ang):
    col1 = np.concatenate((norm(frame), hsv), axis=0)
    col2 = np.concatenate((cv2.cvtColor(hor, cv2.COLOR_GRAY2BGR), cv2.cvtColor(ver, cv2.COLOR_GRAY2BGR)), axis=0)
    col3 = np.concatenate((cv2.cvtColor(mag, cv2.COLOR_GRAY2BGR), cv2.cvtColor(ang, cv2.COLOR_GRAY2BGR)), axis=0)
    return np.concatenate((col1, col2, col3), axis=1)


def getLine(img):
    # print('Inside getLine')
    # ----------- MORPHOLOGY FOR CENTER LOCALISATION ---------------------------
    im = (img > 0).astype(np.float32)
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(30,30))
    closing = cv2.morphologyEx(im, cv2.MORPH_CLOSE, kernel)
    # cv2.imshow('morphology', np.concatenate((im, closing), axis=1))

    # ------------- FIND LINE ------------------------------------------------
    edges = cv2.Canny(closing.astype(np.uint8),50,150,apertureSize = 7)
    lines = cv2.HoughLines(edges,1,np.pi/180, 30)
    # cv2.imshow('edges', norm(edges))
    if lines is not None:
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

        print('Lines were found')
        # cv2.imshow('lines found', closing)
        return [[x1, y1], [x2, y2]]
    else:
        print('No lines were found')
        return None
    

def getIntersection(line1, line2):
    xdiff = (line1[0][0] - line1[1][0], line2[0][0] - line2[1][0])
    ydiff = (line1[0][1] - line1[1][1], line2[0][1] - line2[1][1])

    def det(a, b):
        return a[0] * b[1] - a[1] * b[0]

    div = det(xdiff, ydiff)
    if div == 0:
        raise Exception('lines do not intersect')

    d = (det(*line1), det(*line2))
    x = int(det(d, xdiff) / div)
    y = int(det(d, ydiff) / div)
    return x, y


def getAngle(angle, magnitude, center, n):
    # n is the root of the number of samples that will be taken for the rotation calculation
    # rotation is given in degrees
    (r,c) = angle.shape
    rotations = []
    nr = 0
    nc = 0
    print(r)
    print(c)
    for init_r in range(int(r/(n*2)), int(r-r/(n*2)+1), int(r/n)):      # +1 for rounding errors
        # print('init_r = ' + str(init_r))
        nr += 1
        print(init_r)
        for init_c in range(int(c/(n*2)), int(c-c/(n*2)+1), int(c/n)): 
            nc += 1
            # print('init_c = ' + str(init_c))
            # print('sample angle = ' + str(angle[init_r, init_c]*360))
            goal_r = init_r + magnitude[init_r, init_c] * math.cos(angle[init_r, init_c]*2*np.pi)       # (angle*360) * (2*pi/360)
            # print('goal_r = ' + str(goal_r))
            goal_c = init_c + magnitude[init_r, init_c] * math.sin(angle[init_r, init_c]*2*np.pi)
            # print('goal_c = ' + str(goal_c))
            alpha = math.atan2(center[0]-goal_r, center[1]-goal_c) * 180 / np.pi
            beta = math.atan2(center[0]-init_r, center[1]-init_c) * 180 / np.pi
            rotations.append(beta - alpha)
    print('rotations = ' + str(rotations))
    print('nr = ' + str(nr) + ', nc = ' + str(nc))
    return mean(rotations)


# ------------ VIDEO CAP START ----------------------------------------
cap = cv2.VideoCapture('../optical_flow_test/Naiad_in_trondheim_firstTrial_pt1_2.mp4')
ret, frame = cap.read()
prev = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

# --------- QUIVER PREP --------------------------------------------
# X, Y = np.meshgrid(np.arange(0, prev.shape[1], dtype = np.dtype('float32')), np.arange(0, prev.shape[0], dtype = np.dtype('float32')))
# fig1, ax1 = plt.subplots()
# ax1.set_title('Quiver plot')

while(cap.isOpened()):
    ret, frame = cap.read()
    next = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    # print(grey.dtype)
    flow = np.zeros((prev.shape[0], prev.shape[1], 2), dtype = np.dtype('float32'))
    magn = np.zeros((prev.shape[0], prev.shape[1]), dtype = np.dtype('float32'))
    ang = np.zeros((prev.shape[0], prev.shape[1]), dtype = np.dtype('float32'))
    hsv = np.ones((prev.shape[0], prev.shape[1], 3), dtype = np.dtype('float32'))
    
    # ------------ OPTICAL FLOW ----------------------------------
    cv2.calcOpticalFlowFarneback(prev, next, flow, 0.5, 3, 15, 3, 5, 1.2, 0)
    (horz, vert) = cv2.split(flow)
    cv2.cartToPolar(horz, vert, magn, ang, True)

    # ---------- CREATE HSV ---------------------------------------
    # cv2.normalize(magn, magn)
    # horz = norm(horz)
    # vert = norm(vert)
    magnNorm = np.empty(magn.shape)
    cv2.normalize(magn, magnNorm, 0, 1, cv2.NORM_MINMAX)
    # ang = norm(ang)
    ang /= 360
    hsv[:,:,0] = norm(ang)*255
    hsv[:,:,2] = magnNorm*2
    hsv = cv2.merge((hsv[:,:,0], hsv[:,:,1], hsv[:,:,2]))
    hsv = hsv.astype(np.uint8)
    hsv = cv2.cvtColor(hsv, cv2.COLOR_HSV2BGR)
    
    # ------- PLOTTING -------------------------------------------
    # cv2.imshow("result", printImages(frame, hsv, horz, vert, magn, ang))
    # cv2.waitKey(0)

    # ---------- QUIVER -------------------------------------------
    # print(X.shape)
    # print(Y.shape)
    # print(horz.shape)
    # print(vert.shape)
    # Q = ax1.quiver(X, Y, horz, vert, units='width')
    # print(Q)
    # plt.show()
    
    # print('1')
    # fig, ax = plt.subplots()

    # fig = plt.figure(frameon = False)
    # fig.set_size_inches(8.544,4.806)
    # ax = plt.Axes(fig, [0., 0., 1., 1.], )
    # ax.set_axis_off()
    # fig.add_axes(ax)
    
    # print('2')
    # plot_quiver(ax, (horz, vert), ang, scale=10)     # color="#ff44ff"
    # print('3')

    # plt.savefig('quiver.png', dpi = 56.25)
    # im = cv2.imread('quiver.png')
    # # os.remove('quiver.png')
    # print('4')
    # print(frame.shape)
    # print(hsv.shape)
    # print(im.shape)
    # cv2.imshow('temp', im)
    # cv2.waitKey(0)
    # cv2.imshow('frame, hsv, quiver', np.concatenate((frame, hsv, im), axis=1))

    # plt.show()
    # cv2.waitKey(0)

    # ----------- CALCULATING ROTATION WITHOUT QUIVER ---------------------------------


    horzLine = getLine(horz)
    vertLine = getLine(vert)
    

    # if lines could be found in both horizontal and vertical images
    if (horzLine and vertLine) is not None:
        intersection = getIntersection(horzLine, vertLine)
        cv2.circle(frame, intersection, radius=20, color=(255, 0, 255), thickness=-1)
        
        n = 3
        rot = getAngle(ang, magn, intersection, n)
    else:
        ang = np.zeros(ang.shape, ang.dtype)
        rot = 0.0
    
    print('rotation angle = ' + str(rot))
    
    cv2.imshow('video', frame)
    cv2.imshow('angle', ang)
    cv2.imshow('magnitude', norm(magn))
    # cv2.imshow("result", printImages(frame, hsv, horz, vert, magn, ang))
    cv2.waitKey(15)

    if abs(rot) > 0.0005:
        cv2.waitKey(0)
    

    # if cv2.waitKey(1) & 0xFF == ord('q'):
    #     break
    # cv2.waitKey(0)
    prev = next

cap.release()
cv2.destroyAllWindows()


plt.show()