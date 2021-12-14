import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import cv2
import os
import math
from tinyquaternion import Quaternion

gtPath = '../../test2/odometry.csv'
resultpath = './opticalFlowResult.csv'
frameSkip = 3

# Evaluate result
est = pd.read_csv(resultpath) 
gt = pd.read_csv(gtPath)
gtSkip = gt.loc[::frameSkip,['wr', 'xr', 'yr', 'zr']]
gtAngles = np.array([(Quaternion(np.array(gtSkip.iloc[i])).axisangle()[1] - Quaternion(np.array(gtSkip.iloc[i-1])).axisangle()[1])*180/math.pi for i in range(1, len(gtSkip))])

estAngles = est.loc[1:,['Rotation']].to_numpy()
print(estAngles.shape)
print(gtAngles.shape)

fig, ax = plt.subplots()
ax.plot(estAngles, 'r', gtAngles, 'b')
ax.legend(('Estimation', 'Ground Truth'))
plt.ylim([-6, 6])
plt.show()