# Name: Ryan Orf
# Due Date: Friday, October 21, 2022
# Program Description: The idea of this project is to implement a client and server chat room
# utilizing the socket API. Along with communicating back and forth, the client program must
# be able to provide 4 commands: login, newuser, send, and logout. As always, proper coding
# conventions and extensive error checking must be implemented.
# Python Version: 3.9.1

import socket # socket API header required

BUFFER_SIZE = 1024 # global variables (acting like symbolic constant)

def client_program(): # client function
    host = "127.0.0.1" # server IP address requested for project
    port = 18568 # port number requested for project based off personal student ID number

    try: # try loop in case server is not connected

        client_socket = socket.socket()  # instantiate the client socket
        client_socket.connect((host, port))  # connect to the server using provided host and port information

        print("Connection from: ('" + host + "', " + str(port) + ")") # connection message to show the server is connected
    
        print("\nWelcome to ChatRoom Version 2!\nPlease use one of the following commands:\n1.) login UserID Password\n2.) newuser UserID Password\n3.) send message\n4.) logout") # menu i chose to implement to show options

        message = input(" -> ")  # take input with an arrow "cursor" to make it more visually pleasing

        notLoggedIn = True # control variable to ensure a user can't logout before first logging in

        while notLoggedIn or message.lower().strip() != "logout" or (len(message.split()) != 1): # iterating through until the user has logged in and then properly logged out (also implemented on server but just as an extra safeguard)
            client_socket.send(message.encode())  # send message to the server
            data = client_socket.recv(BUFFER_SIZE).decode()  # receive response from the server

            print("Received from server: " + data)  # show message from server in terminal

            if data.split()[0] == "login": # if the server message indicates a successful login
                notLoggedIn = False # flip notLoggedIn to False so that the user can logout in the future

            message = input(" -> ")  # take input again

        client_socket.send(message.encode())  # send message to server once logged in user has logged out
        data = client_socket.recv(BUFFER_SIZE).decode() # receive response from the server upon logout
        print("Received from server: " + data) # show message from server in terminal
        client_socket.close()  # close the connection

    except: # except 
        
        print("Error: Server could not connect. Ensure the server is active.") # print error message to notify user that the server was not connected to
        client_socket.close() # safely close the connection to prevent error


if __name__ == '__main__': # main program for client.py
    client_program() # call to the client function
