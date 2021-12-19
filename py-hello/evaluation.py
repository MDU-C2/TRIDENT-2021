import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import cv2
import os
import math
import sys
from squaternion import Quaternion

# FUTURE WORK
# clean up
# double check transformation between coordinate systems
# track cumulative position, see what the positional error is over time


gtPath = '..//test2/odometry.csv'
resultpath = './opticalFlowResult.csv'
frameSkip = 1


def getQuatAngle(loc):
    return Quaternion(loc[0], loc[1], loc[2], loc[3]).to_euler(degrees=False)[2]


# Evaluate result
est = pd.read_csv(resultpath)
gt = pd.read_csv(gtPath)
gtAngles = gt.loc[::frameSkip, ['wr', 'xr', 'yr', 'zr']]
gtAngles = np.array([getQuatAngle(gtAngles.iloc[i]) for i in range(len(gtAngles))])
gtPos = gt.loc[::frameSkip, ['xp', 'yp']].to_numpy()

# print(gtPos)
gtPos = gtPos[1:] - gtPos[:-1]
temp = np.sqrt(np.power(gtPos[:, 0], 2) + np.power(gtPos[:, 1], 2))
# gtPos[:, 0] = gtPos[:, 0] * np.cos(gtAngles[1:]) - gtPos[:, 1] * np.sin(gtAngles[1:])
# gtPos[:, 1] = gtPos[:, 0] * np.sin(gtAngles[1:]) + gtPos[:, 1] * np.cos(gtAngles[1:])
# print(gtPos)

# gtAngles = np.array([getQuatAngle(gtAngles.iloc[i]) - getQuatAngle(gtAngles.iloc[i-1]) for i in range(1, len(gtAngles))])
gtAngles = gtAngles[1:] - gtAngles[:-1]
gtAngles *= (180 / math.pi)

estAngles = est.loc[1:, ['Rotation']].to_numpy()
estPos = est.loc[1:, ['# Horizontal Translation', 'Vertical Translation']].to_numpy()
# print(estPos.shape)
# print(gtPos.shape)

fig, ax = plt.subplots(1, 1)
ax.plot(estAngles, 'r', gtAngles, 'b', estPos[:, 0], 'g', -gtAngles, 'c', estPos[:, 1], 'm', temp*150, 'k')
ax.legend(('Rotation Estimation', 'Rotation Ground Truth', 'Horizontal Estimation', 'Horizontal Grond Truth', 'Vertical Estimation', 'Vertical Ground Truth'))
ax.set_ylim(-2, 3)
ax.set_title('Rotation')

# Plotting result
# fig, ax = plt.subplots(1, 1)
# lim = 2.2
# ax.plot(estAngles, 'r', gtAngles, 'b')
# ax.legend(('Estimation', 'Ground Truth'))
# ax.set_ylim(-lim, lim)
# ax.set_title('Rotation')

# fig, ax = plt.subplots(1, 1)
# ax.plot(estPos[:, 1], 'r', temp*150, 'g')
# ax.legend(('Vertical Translation estiamtion', 'Ground truth x150'))
# ax.set_ylim(-0.1, 3)

# fig, ax = plt.subplots(1, 1)
# lim = 2.2
# ax.plot(-estPos[:, 0], 'r', estAngles, 'g')
# ax.legend(('Horizontal Translation Estimation', 'Rotation Estimation'))
# ax.set_ylim(-lim, lim)

# fig, ax = plt.subplots(1, 1)
# lim = 2.2
# ax.plot(estAngles[:, 0] + estPos[:, 0], 'c')
# ax.set_ylim(-lim, lim)
# ax.set_title('Horizontal Translation and Rotation diff')



# scale = 300
# ax[1].plot(estPos[:,0], 'r', gtPos[:,0]*scale, 'b')
# ax[1].legend(('Estimation', 'Ground Truth'))
# ax[1].set_ylim(-lim, lim)
# ax[1].set_title('Horizontal')

# ax[2].plot(estPos[:,1], 'r', gtPos[:,1]*scale, 'b')
# ax[2].legend(('Estimation', 'Ground Truth'))
# ax[2].set_ylim(-lim, lim)
# ax[2].set_title('Vertical')

plt.show()
