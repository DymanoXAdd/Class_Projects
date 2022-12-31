import socket

Server = socket.socket()
Host = "192.168.1.34"
port = 80
Server.connect((Host,port))
print("Connected...")

Tranfser = input(str("Please enter the name of file that is incoming: "))
File = open(Tranfser, 'wb')
File_Type = Server.recv(1024)
File.write(File_Type)
File.close()
print("File has been received!!!")