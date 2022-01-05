import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


def print_trajectory(traj, colour, label):
    ax = fig.gca(projection='3d')
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_zlabel('z')
    ax.set_title('Title')
    ax.plot(traj[1], traj[2], traj[3], colour, label=label)
    ax.legend()


grey = pd.read_csv('pt1_2_gray/frame_trajectory.txt', sep=" ", header=None)
pre = pd.read_csv('pt1_2_pre/frame_trajectory.txt', sep=" ", header=None)

fig = plt.figure()
print_trajectory(grey, 'b', 'greyscale')
print_trajectory(pre, 'r', 'preprocessed')
plt.show()
