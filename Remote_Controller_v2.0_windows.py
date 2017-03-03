from tkinter import *
import socket,time,threading

host="127.0.0.1"
port=9959
so=''
addr=''

# ******* Connection setup ******* #
def setUpConnection(event):
    global so,addr
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((host,port))
    s.listen(5)
    print('Waiting for connection...')
    
    so,addr = s.accept()  
    print('Accept new connection from %s:%s...' % addr)
    so.send(('Welcome!').encode())
    var.set("Connected")

def releaseConnection(event):
    global so,addr
    so.send(('release').encode())
    so.close()
    print('Connection from %s:%s closed.' % addr)
    var.set("Disconnected")
    
root = Tk()
root.title('Controller')

var = StringVar()

topFrame = Frame(root)
topFrame.pack()
bottomFrame = Frame(root)
bottomFrame.pack(side=BOTTOM)

# ******** Button **** #
button1 = Button(topFrame, text = "Forward",width = '10',height = '5')
button2 = Button(topFrame, text = "Left",width = '10',height = '5')
button3 = Button(topFrame, text = "Backward",width = '10',height = '5')
button4 = Button(topFrame, text = "Right",width = '10',height = '5')
button5 = Button(topFrame, text = "Stop",width = '10',height = '5')

def fw(event):
    print("forward")
    so.send(('Forward').encode())

def bw(event):
    print("backward")
    so.send(('backward').encode())

def left(event):
    print("left")
    so.send(('left').encode())

def right(event):
    print("right")
    so.send(('right').encode())

def stop(event):
    print("stop")
    so.send(('stop').encode())

# ***** keyboard control *******#
topFrame.bind('<KeyPress-Up>',fw)
topFrame.bind('<KeyPress-Left>',left)
topFrame.bind('<KeyPress-Down>',bw)
topFrame.bind('<KeyPress-Right>',right)
topFrame.bind('<KeyRelease-Up>',stop)
topFrame.bind('<KeyRelease-Left>',stop)
topFrame.bind('<KeyRelease-Right>';,stop)
topFrame.bind('<KeyRelease-Down>',stop)
topFrame.focus_set()

# ****** mouse control ****** #
button1.bind('<Button-1>',fw)
button2.bind('<Button-1>',left)
button3.bind('<Button-1>',bw)
button4.bind('<Button-1>',right)
button5.bind('<Button-1>',stop)

# ****** arrange grid ******* #
button1.grid(row=0,column=1)
button2.grid(row=1,column=0)
button3.grid(row=2,column=1)
button4.grid(row=1,column=2)
button5.grid(row=1,column=1)

# ******* status bar ******* #
var.set("Waiting for connection")
status = Label(bottomFrame, textvariable=var,bd=1,relief=SUNKEN,anchor=W)
status.pack(side=BOTTOM,fill=X)

# ******* connection management ******* #
button6 = Button(topFrame, text = "Connect",width = '10',height = '5')
button6.grid(row=3,column=0)
button6.bind('<Button-1>',setUpConnection)

button7 = Button(topFrame, text = "Disconnect",width = '10',height = '5')
button7.grid(row=3,column=2)
button7.bind('<Button-1>',releaseConnection)

root.mainloop()


    