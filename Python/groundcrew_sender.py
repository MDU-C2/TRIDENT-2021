'''
A simple sender program. This should preferably be replaced with a GUI later on
'''

import requests
import json

import random
example_route = {"depth": 100, "points": []}
for i in range(100):
	example_route["points"].append([random.random(), random.random()])
example_route_json = json.dumps(example_route)

response = requests.post("http://127.0.0.1:4000",
                         data=example_route_json.encode("utf-8"))
print(response.status_code)
print(response.text)
