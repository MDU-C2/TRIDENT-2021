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


gtPath = '../test2/odometry.csv'
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
origGtPos = gtPos

gtPos = gtPos[1:] - gtPos[:-1]
temp = np.sqrt(np.power(gtPos[:, 0], 2) + np.power(gtPos[:, 1], 2))

origGtAngles = gtAngles

gtAngles = gtAngles[1:] - gtAngles[:-1]
gtAngles *= (180 / math.pi)

estAngles = est.loc[1:, ['Rotation']].to_numpy()
estPos = est.loc[1:, ['# Horizontal Translation', 'Vertical Translation']].to_numpy()

# Distance travelled tests --------------------------------------------------------
tempGt = np.sqrt(np.power(gtPos[:, 0], 2) + np.power(gtPos[:, 1], 2))

fig, ax = plt.subplots()
ax.plot(estPos[:,1], 'r', tempGt*150, 'b')
ax.legend(('Estimated $\Delta$ vertical movement', 'Ground truth $\Delta$ absolute movement *150'))

plt.show()

# Error plots -------------------------------------------------------
fig, ax = plt.subplots()
ax.plot(estAngles, 'r', gtAngles, 'b')
ax.legend(('Estimated $\Delta$angle', 'Ground truth $\Delta$angle'))
ax.set_ylim(-2, 2)

# fig, ax = plt.subplots(1, 1)
# ax.plot(-gtAngles, temp*150)

# est ang vs est horz ------------------------------------------
# fig, ax = plt.subplots(1, 1)
# ax.plot(estAngles, 'r', -estPos[:,0], 'b')
# ax.legend(('Estimated $\Delta$angle', 'Estimated -$\Delta$horizontal'))


plt.show()
