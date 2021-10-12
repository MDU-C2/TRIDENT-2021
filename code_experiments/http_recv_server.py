'''
A simple custom HTTP server, which can receive data through a POST 
request and store it in a variable recv_route for easy reading afterwards
'''

from http.server import HTTPServer, BaseHTTPRequestHandler
import json

# Default HTTPServer, modded to store the latest received route
# so it can be read as a loop-exit condition and stored for use
class HTTPPOSTServer(HTTPServer):
    def __init__(self, *args, **kwargs):
        super(HTTPPOSTServer, self).__init__(*args, **kwargs)
        self.recv_route = {}
        html_file = open("get_resp.html", 'r')
        self.get_resp = html_file.read().encode("utf-8")
        html_file.close()

# Default SimpleHTTPRequestHandler, modded with POST responses
# so it can receive routes from the ground crew
class HTTPRequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.end_headers()
        self.wfile.write(self.server.get_resp)

    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        body = self.rfile.read(content_length)
        # TODO: check that the received data json and is structured right
        self.server.recv_route = json.loads(body.decode("utf-8"))
        
        # TODO: send non-200 response if data is malformed
        self.send_response(200)
        self.end_headers()
        self.wfile.write(b'Data received!')