#!/usr/bin/env python

import pynotify
import subprocess
import socket

REMOTE_SERVER = "www.google.com"
pynotify.init("Connection")
subprocess.call(['speech-dispatcher'])
connected_status = pynotify.Notification("Connection Status", " Internet Is Available!")
disconnected_status = pynotify.Notification("Connection Status", " Internet Is Not Available!")
connectionflag = 2

while True:
	try:
		host = socket.gethostbyname(REMOTE_SERVER)
		s = socket.create_connection((host,80),2)
		if connectionflag != 1:
			connected_status.show()
			subprocess.call(['spd-say', '"Internet, is, available!"'])
			connectionflag = 1			
	except:
		if connectionflag != 0:
			disconnected_status.show()
			subprocess.call(['spd-say', '"Internet, is, not, available!"'])
			connectionflag = 0
