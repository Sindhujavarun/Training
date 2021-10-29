import socket
from threading import Thread

def acceptConnections():
    while(True):
        client, clientAddress = SERVER.accept()
        print("%s:%s has connected." % clientAddress)
        client.send(bytes("Type your name and press enter!", "utf8"))
        addresses[client] = clientAddress
        Thread(target = handleClient, args = (client,)).start()

def handleClient(client):
    clientName = client.recv(1024).decode("utf8")
    welcomeMessage = 'Welcome %s! If you ever want to quit, type "quit" to exit.' % clientName
    client.send(bytes(welcomeMessage, "utf8"))
    message = "%s has joined the chat!" % clientName
    broadcastMessage(bytes(message, "utf8"))
    clients[client] = clientName

    while(True):
        message = client.recv(1024)
        if message != bytes("quit", "utf8"):
            broadcastMessage(message, clientName + ": ")
        else:
            client.send(bytes("quit", "utf8"))
            client.close()
            del clients[client]
            broadcastMessage(bytes("%s has left the chat." % clientName, "utf8"))
            break

def broadcastMessage(message, prefix = ""):
    for sock in clients:
        sock.send(bytes(prefix, "utf8") + message)

        
clients = {}
addresses = {}
HOST = "165.22.14.77"
PORT = 12346
SERVER = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
SERVER.bind((HOST, PORT))

if __name__ == "__main__":
    SERVER.listen(5)
    print("Waiting for connection...")
    thread = Thread(target = acceptConnections)
    thread.start()
    thread.join()
    SERVER.close()