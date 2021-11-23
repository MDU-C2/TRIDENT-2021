# vision

## openvslam dependencies

* [Openvslam installation instruction](https://openvslam-community.readthedocs.io/en/latest/installation.html), make sure to install every library on your computer with `sudo make install`.

## opencv optical flow

* [opencv contrib](https://github.com/opencv/opencv_contrib), this is needed for the optical flow algorithms. Install according to the instructions. This requires a local opencv repo.

## run slam

***not fully implemented***
```
ros2 run vision run_slam  -v src/openvslam/config/orb_vocab.fbow -c src/openvslam/config/config.yaml
```

## run optical flow

***not implemented***
```
ros2 run vision run_optflow
```
