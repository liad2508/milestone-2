from socket import *
from random import *
import logging
import argparse
from threading import Thread, Event, Lock
import time
DEFAULT_SLEEP_TIME = 0.1

def createMat(n):
    mat = []
    for i in range(n):
        line = []
        for j in range(n):
            line += [(str(randint(-1, 30)))]
        mat += [",".join(line)]
    mat += ["0,0"]
    mat += [str(n - 1) + "," + str(n - 1)]
    mat += ["end"]
    print mat
    return mat


def server(port):
    ad = "127.0.0.1"
    po = port

    list = [10, 15, 20, 25, 30, 35, 40, 45, 50]

    for n in list:
        for i in range(10):
            c = socket(AF_INET, SOCK_STREAM)
            c.connect((ad, po))
            msg = createMat(n)

            for m in msg:
                c.send(m)
                time.sleep(DEFAULT_SLEEP_TIME)

            s = c.recv(1024)
            print s
            c.close()


server(5400)