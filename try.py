from socket import *

ad = "127.0.0.1"
po = 5400

c = socket(AF_INET, SOCK_STREAM)
c.connect((ad,po))

for i in range(5):
    c.send("1234")
    s = c.recv(1024)
    print s

c.close()