import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import cv2
import os
import math
from numpy.core.fromnumeric import amax
from numpy.lib.function_base import median, mean

im1 = cv2.imread('histeq/20211222_131926.jpg', 0)
im1 = cv2.resize(im1, None, fx=.2, fy=.2)
im1 = im1[50:700, :]

plt.hist(im1.ravel(),256,[0,256])
plt.show()
cv2.imwrite('histeq/im_pre.png', im1)
equ = cv2.equalizeHist(im1)
cv2.imwrite('histeq/im_post.png', equ)
plt.hist(equ.ravel(),256,[0,256])
plt.show()

