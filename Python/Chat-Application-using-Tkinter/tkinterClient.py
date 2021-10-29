import socket
import tkinter
from threading import Thread

def receiveMessages():
    while(True):
        try:
            message = clientSocket.recv(1024).decode("utf8")
            messages.insert(tkinter.END, message)
        except OSError:
            break

def sendMessages(event = None):
    message = myMessage.get()
    myMessage.set("")
    clientSocket.send(bytes(message, "utf8"))
    if message == "quit":
        clientSocket.close()
        top.quit()

def closeWindow(event = None):
    myMessage.set("quit")
    sendMessages()

top = tkinter.Tk()
top.title("Chatroom")

messageFrame = tkinter.Frame(top)
myMessage = tkinter.StringVar()
scrollbar = tkinter.Scrollbar(messageFrame)
messages = tkinter.Listbox(messageFrame, height = 15, width = 50, yscrollcommand = scrollbar.set)
scrollbar.pack(side = tkinter.RIGHT, fill = tkinter.Y)
messages.pack(side = tkinter.LEFT, fill = tkinter.BOTH)
messages.pack()
messageFrame.pack()

entryMessage = tkinter.Entry(top, textvariable = myMessage)
entryMessage.bind("<Return>", sendMessages)
entryMessage.pack()
sendButton = tkinter.Button(top, text="Send", command=sendMessages)
sendButton.pack()

top.protocol("WM_DELETE_WINDOW", closeWindow)

HOST = '165.22.14.77'
PORT = 17253
clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect((HOST, PORT))
thread = Thread(target = receiveMessages)
thread.start()
tkinter.mainloop()