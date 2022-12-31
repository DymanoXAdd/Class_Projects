import socket

#Conection Link
Server = socket.socket()
Host = "192.168.1.34"
port = 80
Server.bind((Host,port))
Server.listen()
print(Host)
print("Waiting for any incoming connections...")
Connection, Address = Server.accept()
print(Address, "Connection has been made!")

#File Transfer
Transfer = input(str("Please enter the file: "))
File = open(Transfer, 'rb')
File_type = File.read(1024)
Connection.send(File_type)
print("File Sent!!!")