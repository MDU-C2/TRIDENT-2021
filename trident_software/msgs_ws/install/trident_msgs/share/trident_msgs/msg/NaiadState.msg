# State for NAIAD will be the following
# x y z roll pitch heading dx dy dz droll dpitch dheading

# The x y coords are in meters, relative to 59.6175336,16.5605033
# (the position of C2 according to google maps) and sea level,
# with x going north, y going east, and z going down.
# roll and pitch are relative to down, and heading is relative to north.
# all rotations are in radians. The change variables (those starting with d*) are in
# local coordinates, and are in base unit per second, while the others are global.

float64 x
float64 y
float64 z

float32 roll
float32 pitch
float32 heading

float32 velx
float32 vely
float32 velz

float32 velroll
float32 velpitch
float32 velheading