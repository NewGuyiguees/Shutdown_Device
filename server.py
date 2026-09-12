from http.server import BaseHTTPRequestHandler, HTTPServer
from urllib.parse import urlparse, parse_qs
import subprocess

HOST = "0.0.0.0"
PORT = 5000

SECRET = "SECRET_KEY"


class Handler(BaseHTTPRequestHandler):
    def do_GET(self):
        parsed = urlparse(self.path)
        params = parse_qs(parsed.query)
        token = params.get("token", [None])[0]

        if parsed.path == "/shutdown" and token == SECRET:
            print("VALID SHUTDOWN REQUEST RECEIVED")
            
            self.send_response(200)
            self.end_headers()
            self.wfile.write(b"Shutdown command accepted")

            # Shut down Windows after 5 seconds
            subprocess.Popen(["shutdown", "/s", "/t", "5"])

        else:
            print("Rejected request:", self.path)
            self.send_response(403)
            self.end_headers()
            self.wfile.write(b"Forbidden")


server = HTTPServer((HOST, PORT), Handler)

print(f"Server listening on port {PORT}...")
server.serve_forever()