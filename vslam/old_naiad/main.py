import numpy as np
import cv2


def preprocessing(im):
    dst = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
    dst = cv2.equalizeHist(dst)
    # dst = cv2.cvtColor(dst, cv2.COLOR_GRAY2BGR)
    return dst


filename = 'Naiad_in_trondheim_firstTrial_pt2_2'
cap = cv2.VideoCapture(filename + '.mp4')
w = int(cap.get(3))
h = int(cap.get(4))
# fourcc = int(cap.get(cv2.CAP_PROP_FOURCC))
fourcc = cv2.VideoWriter_fourcc(*"mp4v")
fps = cap.get(cv2.CAP_PROP_FPS)
out = cv2.VideoWriter(filename + '_preprocessing.mp4', fourcc, fps, (w, h), False)

while cap.isOpened():
    ret, img = cap.read()
    if not ret:
        cap.release()
        out.release()
    else:
        res = preprocessing(img)
        out.write(res)

