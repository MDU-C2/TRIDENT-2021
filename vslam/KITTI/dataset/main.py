import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


def quaternion_rotation_matrix(SLAM_row):
    """
    Covert a quaternion into a rotation matrix.

    Input
    :param  SLAM_output: An 8 element array representing the timestamp, translation,
            and quaternion (ts,tx,ty,tz,q0,q1,q2,q3)

    Output
    :return: A 1x12 element matrix representing the full 3D transformation matrix, in row major form.
             This transformation matrix converts a point in the local reference
             frame to a point in the global reference frame.
    """
    # Extract the values from Q
    tx = SLAM_row[1] * 22
    ty = SLAM_row[2] * 22
    tz = SLAM_row[3] * 22
    q0 = SLAM_row[4]
    q1 = SLAM_row[5]
    q2 = SLAM_row[6]
    q3 = SLAM_row[7]

    # First row of the rotation matrix
    r00 = 2 * (q0 * q0 + q1 * q1) - 1
    r01 = 2 * (q1 * q2 - q0 * q3)
    r02 = 2 * (q1 * q3 + q0 * q2)

    # Second row of the rotation matrix
    r10 = 2 * (q1 * q2 + q0 * q3)
    r11 = 2 * (q0 * q0 + q2 * q2) - 1
    r12 = 2 * (q2 * q3 - q0 * q1)

    # Third row of the rotation matrix
    r20 = 2 * (q1 * q3 - q0 * q2)
    r21 = 2 * (q2 * q3 + q0 * q1)
    r22 = 2 * (q0 * q0 + q3 * q3) - 1

    # 3x3 rotation matrix
    trans_matrix = np.array([r00, r01, r02, tx,
                             r10, r11, r12, ty,
                             r20, r21, r22, tz])
    trans_matrix = ' '.join(map(str, trans_matrix))
    # trans_matrix = np.array2string(trans_matrix, max_line_width=200)
    # print(trans_matrix)

    return trans_matrix


def convert_output_format_print(SLAM_output, n_seq, gt_len, slam_len):
    file = open('../../openvslam/build/kitti_seq' + n_seq + '/frame_trajectory_' + n_seq + '_reformatted.txt', 'w')
    [file.write(quaternion_rotation_matrix(SLAM_output.iloc[i]) + '\n') for i in range(slam_len)]
    [file.write('0 0 0 0 0 0 0 0 0 0 0 0\n') for i in range(gt_len-slam_len)]
    file.close()


def print_trajectories(t1, t2):
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_zlabel('z')
    ax.set_title('KITTI, sequence')
    ax.plot(t1[3], t1[7], t1[11], 'b', label='Ground Truth')
    k = 10   # used to be 22
    ax.plot(t2[1] * 7, t2[2] * k, t2[3] * k, 'r', label='OpenVSLAM')
    ax.legend()
    plt.show()


def print_trajectory(traj):
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_zlabel('z')
    ax.set_title('KITTI, sequence')
    ax.plot(traj[3], traj[7], traj[11], 'b', label='Trajectory')
    ax.legend()
    plt.show()


# 06, 07, 08!
seq = '08'
gt = pd.read_csv('poses/' + seq + '.txt', sep=" ", header=None)
est = pd.read_csv('../../openvslam/build/kitti_seq' + seq + '/frame_trajectory.txt', sep=" ", header=None)

convert_output_format_print(est, seq, gt.__len__(), est.__len__())

# print_trajectory(gt)
print_trajectories(gt, est)

x = np.linspace(0, gt.shape[0]-1, gt.shape[0]-1)
# fig, axs = plt.subplots(3)
# fig.suptitle('GT, KITTI sequence 00')
# [axs[int((i-3)/4)].plot(x, gt[i]) for i in range(3, 12, 4)]
#
# x2 = np.linspace(0, est.shape[0], est.shape[0])
# fig2, axs2 = plt.subplots(3)
# fig2.suptitle('OpenVSLAM, KITTI sequence 00')
# [axs2[i-1].plot(x2, est[i]) for i in range(1, 4, 1)]

# fig, axs = plt.subplots(3)
# axs[0].plot(x, gt[3][0:4070]/est[1][0:4070])
# axs[0].set_title('x')
# axs[1].plot(x, gt[7][0:4070]/est[2][0:4070])
# axs[1].set_title('y')
# axs[2].plot(x, gt[11][0:4070]/est[3][0:4070])
# axs[2].set_title('z')
# # ax[2].set_ylim(-30, 30)
# plt.show()
