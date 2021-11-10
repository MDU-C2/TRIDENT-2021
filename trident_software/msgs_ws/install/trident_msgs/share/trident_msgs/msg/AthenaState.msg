# State for Athena will be the following
# x y heading dx dy dheading

# The x y coords are in meters, relative to 59.6175336,16.5605033
# (the position of C2 according to google maps),
# with x going north and y going east. Heading is relative to north.
# Rotation is in radians. The change variables (those starting with d*) are in
# local coordinates, and are in base unit per second, while the others are global.

float64 x
float64 y

float32 heading

float32 velx
float32 vely

float32 velheading