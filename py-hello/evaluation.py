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


# fig, ax = plt.subplots(1, 1)
# ax.plot(-gtAngles, temp*150)

# Cumulative error -------------------------------------------------------------------------------------
# cumulativeGTH = [gtPos[0:n,0].sum() for n in range(len(gtPos[:,0]))]
# cumulativeGTV = [gtPos[0:n,1].sum() for n in range(len(gtPos[:,0]))]
# cumulativeH = [estPos[0:n,0].sum() for n in range(len(estPos[:,0]))]
# cumulativeV = [estPos[0:n,1].sum() for n in range(len(estPos[:,1]))]

# cumulativeAngles = [estAngles[0:n].sum()/180 for n in range(len(estAngles))]
# cumulativeH = np.array([estPos[0,1]*np.cos(cumulativeAngles[0]*np.pi/180)])
# cumulativeV = np.array([estPos[0,1]*np.sin(cumulativeAngles[0]*np.pi/180)])

def getCumulative(input):
    # arr = arr.resh
    arr = np.reshape(np.array(input), (input.shape[0], 1))
    cumulativeAngles = np.zeros((arr.shape[0] + 1, 1))
    cumulativeAngles[1] = arr[0]
    cumulativeAngles[2:] = arr[0:-1] + arr[1:]
    for i in range(3, len(cumulativeAngles)):
        cumulativeAngles[i] += cumulativeAngles[i - 2]
    # cumulativeAngles /= 42
    cumulativeAngles *= (np.pi / 180)
    cumulativeAngles += origGtAngles[0]
    # cumulativeAngles = list(np.array(cumulativeAngles)%(2*np.pi))
    cumulativeAngles = [cumulativeAngles[i] - 2 * np.pi if cumulativeAngles[i] > np.pi else cumulativeAngles[i] for i in
                        range(len(cumulativeAngles))]
    return np.array(cumulativeAngles)


cumulativeAngles = getCumulative(estAngles)
# fig, ax = plt.subplots(1, 1)
# ax.plot(origGtAngles, 'r', cumulativeAngles, 'b')
# ax.legend(('gt angles', 'est angles'))
# ax.set_title('absolute rotation estimations')

# est ang vs est horz ------------------------------------------
# fig, ax = plt.subplots(1, 1)
# ax.plot(estAngles, 'r', -estPos[:,0], 'b')
# ax.legend(('Estimated $\Delta$angle', 'Estimated -$\Delta$horizontal'))

plt.show()

# cumulative horz and vert ----------------------------------------------
cumulativeH = np.zeros((1, 1))
cumulativeV = np.zeros((1, 1))
for i in range(1 + len(cumulativeAngles[:-2])):
    # print(i)
    deltaH = estPos[i, 1] * np.cos(cumulativeAngles[i] * np.pi / 180)
    cumulativeH = np.append(cumulativeH, cumulativeH[-1] + deltaH)
    deltaV = estPos[i, 1] * np.sin(cumulativeAngles[i] * np.pi / 180)
    cumulativeV = np.append(cumulativeV, cumulativeV[-1] + deltaV)

# cumulativeH = [estPos[0:n,1]*np.cos(cumulativeAngles[n]) for n in range(len(cumulativeAngles))]
# cumulativeV = [estPos[0:n,1]*np.sin(cumulativeAngles[n]) for n in range(len(cumulativeAngles))]
# print(cumulativeV)

fig, ax = plt.subplots(1, 1)
ax.plot(cumulativeH, 'r', cumulativeV, 'b')
ax.legend(('cumulative H', 'cumulative V'))
ax.set_title('cumulative estimations')

fig, ax = plt.subplots(1, 1)
ax.plot(origGtPos[:,0], 'r', origGtPos[:,1], 'b')
ax.legend(('cumulative H', 'cumulative V'))
ax.set_title('cumulative ground truth')

# Plotting result ---------------------------------------------------------------------------------------
fig, ax = plt.subplots(1, 1)
ax.plot(estAngles, 'r', gtAngles, 'b', estPos[:, 0], 'g', -gtAngles, 'c', estPos[:, 1], 'm', temp * 150, 'k')
ax.legend(('Rotation Estimation', 'Rotation Ground Truth', 'Horizontal Estimation', 'Horizontal Grond Truth',
           'Vertical Estimation', 'Vertical Ground Truth'))
ax.set_ylim(-2, 3)

fig, ax = plt.subplots(1, 1)
ax.plot(estAngles, 'r', gtAngles, 'b', estPos[:, 0], 'g', gtPos[:, 0] * 150, 'c', estPos[:, 1], 'm', gtPos[:, 1] * 150,
        'k')
ax.legend(('Rotation Estimation', 'Rotation Ground Truth', 'Horizontal Estimation', 'Horizontal Grond Truth',
           'Vertical Estimation', 'Vertical Ground Truth'))
ax.set_ylim(-2, 3)

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


plt.show()
