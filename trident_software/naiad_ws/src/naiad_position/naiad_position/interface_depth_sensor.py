import ctypes
import numpy as np

so_file = "../../../../install/naiad_pressure_sensor/lib/libi2cdepth.so"

class depth_sensor:
	def __init__(self):
		self.my_functions = ctypes.CDLL(so_file)
		self.my_functions.request_calc_values.argtypes = []
		self.my_functions.request_calc_values.restype = ctypes.c_void_p
		self.my_functions.freeBuf.argtypes = [ctypes.c_void_p]
		self.my_functions.freeBuf.restype = None
		self.my_functions.init()

    # returns a numpy float array of [Temperature (C), Pressure (mbar), Depth (m)]
	def read_sensor(self):
		sensor_values_p = self.my_functions.request_calc_values()
		data = ctypes.cast(sensor_values_p, ctypes.c_char_p).value
		self.my_functions.freeBuf(sensor_values_p)
		data = np.array(data.split(','))
		return data.astype(np.float)

if __name__ == "__main__":
	print("Testing reading values from the depth sensor:")
	sensor = depth_sensor()
	print(sensor.read_sensor())

