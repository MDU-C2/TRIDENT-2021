'''
The main program which handles controlling the NAIAD.

I've intentionally tried to keep it as simple and understandable as I 
could, to make it easy to change the operation if need be.

Please document any changes in the program flowchart and leave a lot of 
comments describing function and purpose of everything added.

    --A. Makila
'''

'''import motorsubproc
import trilatsubproc'''
import http_recv_server as recvserv

'''motorsubproc.Start()
trilatsubproc.Start()

#Sends the NAIAD to water surface, letting it communicate
motorsubproc.SetDepth(0.0)'''

#Receives the route from the ground crew
httpd = recvserv.HTTPPOSTServer(("localhost", 4000), recvserv.HTTPRequestHandler)
route = {}
while route == {}:
    httpd.handle_request()
    route = httpd.recv_route
print(route)
