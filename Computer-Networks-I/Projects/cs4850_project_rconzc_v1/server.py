# Name: Ryan Orf
# Due Date: Friday, October 21, 2022
# Program Description: The idea of this project is to implement a client and server chat room
# utilizing the socket API. Along with communicating back and forth, the client program must
# be able to provide 4 commands: login, newuser, send, and logout. As always, proper coding
# conventions and extensive error checking must be implemented.
# Python Version: 3.9.1

import socket # socket API header required

BUFFER_SIZE = 1024 # global variables (BUFFER_SIZE and USERS_FILE act like symbolic constants)
USERS = []
USERS_FILE = "users.txt"

def login(username, password): # login function
    
    for user, pswd in USERS: # iterate through list of known users
        
        if((user == username) and (pswd == password)): # if the user exists
            return True # return true to server function
        
    return False # return false to server function

def newuser(username, password): # newuser function
    
    global USERS # need to access USERS to append as necessary

    if(username == "server"): # condition I implemented so that the user can't be named "server"
        return "Denied. User name cannot be server." # return message to server function

    elif((len(username) < 3) or (len(username) > 32)): # condition to check if username has a valid amount of characters
        return "Denied. User name must be between 3 and 32 characters." # return message to server function

    elif((len(password) < 4) or (len(password) > 8)): # condition to check if password has a valid amount of characters
        return "Denied. Password must be between 4 and 8 characters." # return message to server function 

    else: # username and password provided passes preliminary checks

        for user, pswd in USERS: # iterate through list of known users

            if(user == username): # if the user already exists
                return "Denied. User account already exists." # return message to server function

        with open(USERS_FILE, "a") as fp: # open file pointer to USERS_file with the append flag to add user

            fp.write("\n(" + username + ", " + password + ")") # write new user to file in the same format. Given the provided text file, the new line must come at the start, since the cursor ends on the same line as the user Beth. I would assume the same .txt file will be used, but please ensure this when testing.
            fp.close() # close the file pointer

        USERS = USERS + [(username, password)] # append known users list to add new user
        print("New user account created.") # notify on server end that the new account has been created
        return "New user account created. Please login." # return successful message to server function
        
    return "Denied. Please try again." # return message to server function
    
# Future note: could include more error-checking with try/excepts, but for the purposes of this project, this should more than suffice
def server_program(): # server function

    global USERS # need to access USERS to append as necessary

    translation_table = dict.fromkeys(map(ord, '()\n'), None) # create a translation table to remove tuple characters when the list of users is read in
    
    fp = open(USERS_FILE) # open file pointer to USERS_FILE
    if(fp): # check to ensure file exists and was opened properly
        user = fp.readline() # read in the first line of users
        while user: # while there are users/lines in the file
            user = user.translate(translation_table) # translate users using translation table to remove tuple characters
            account = tuple(user.split(", ")) # split the provided info into their own tuple that solely consist of the username and password
            USERS.append((account[0], account[1])) # append to the list of known users the validated user from the file
            user = fp.readline() # read the next line of users

        fp.close() # close the file pointer
    
        host = "127.0.0.1" # server IP address requested for project
        port = 18568 # port number requested for project based off personal student ID number

        username = '' # variable to keep track of the current user's username
        password = '' # variable to keep track of the current user's password

        server_socket = socket.socket() # instantiate the server socket
        server_socket.bind((host, port)) # assigns the server ip address and port number to the new server socket

        while True: # server needs to persist after a client logs out, so a while True is implemented until the server admin manually kills the program

            server_socket.listen(10) # listen for client connection requests
            conn, address = server_socket.accept() # accept client connection request
            print("Connection from: " + str(address)) # connection message to show the client is connected
    
            connectedPort = True # variable to keep track of the client being connected
    
            notLoggedIn = True # variable to keep track of whether the client has already logged in
    
            data = conn.recv(BUFFER_SIZE).decode() # receive response from the client
        
            while connectedPort: # while the client is connected
        
                if not data: # if no response is detected from the client
                    break # break out of this client connection and continue to listen for the next

                while notLoggedIn: # condition check to ensure user logs in before trying commands, including logout, that they should not

                    if len(data.split()) != 3: # ensures the provided argument has 3 arguments, since login and newuser both include exactly three arguments
                        data = "Denied. These commands require exactly 3 arguments." # error message to send back to the client
                        conn.send(data.encode()) # send message to the client
                        data = conn.recv(BUFFER_SIZE).decode() # receive response from the client
                        continue

                    while len(data.split()) != 3 or data.lower().split()[0] != "login": # conditional check to, once again, ensure the number of arguments is 3 AND to ensure the login command was selected
                    
                        if data.lower().split()[0] == "newuser": # if login was not selected but newuser was
                        
                            if len(data.split()) == 3: # ensuring the number of arguments provided was in fact 3
                                username = data.split()[1] # obtain the username from the second argument
                                password = data.split()[2] # obtain the password from the third argument
                                newuserReturn = newuser(username, password) # call newuser function to see if the newuser can be created
                                conn.send(newuserReturn.encode()) # send message to the client
                            
                            else: # if newuser was not the command requested (the only other exceptional command at this stage besides login)
                                data = "Denied. newuser command needs to have exactly 3 arguments." # error message to send back to the client
                                conn.send(data.encode()) # send message to the client

                        else: # if the provided command has less or more than 3 arguments
                            data = "Denied. Please login first." # error message to send back to the client
                            conn.send(data.encode()) # send message to the client

                        data = conn.recv(BUFFER_SIZE).decode() # receive response from the client

                    if len(data.split()) == 3 and data.lower().split()[0] == "login": # if the login command was prompted with the valid number of arguments
                    
                        username = data.split()[1] # obtain the username from the second argument
                        password = data.split()[2] # obtain the password from the third argument
                        loginPermitted = login(username, password) # call login function to see if the client can be logged in
                
                        if(loginPermitted): # if login returned true, i.e. the client can be logged in
                            notLoggedIn = False # switch the control variable to indicate the client is now logged in
                            data = "login confirmed" # success message to send back to the client
                            print(username + " login.") # notify on server end that the client has logged in
                            conn.send(data.encode()) # send message to the client
                            continue # continue through to the next iteration of the while, which will now fail since notLoggedIn is now false
                    
                        else: # if login was unsuccessful
                            data = "Denied. User name or password is incorrect." # error message to send back to the client
                            conn.send(data.encode()) # send message to the client
                            data = conn.recv(BUFFER_SIZE).decode() # receieve response from the client

                data = conn.recv(BUFFER_SIZE).decode() # receive response from the client

                if data.lower().split()[0] == "logout": # if the command provided was logout

                    if(len(data.split()) == 1): # if the logout command was given without other arguments
                        data = username + " left." # success message to send back to the client
                        print(data) # notify on server end that the client is now logged out
                        conn.send(data.encode()) # send message to the client
                        conn.close() # close the connection with the client
                        connectedPort = False # switch the control variable to indicate the client is now logged out
                    
                    else: # if logout was provided with additional arguments
                        data = "Denied. logout command should be followed by no arguments" # error message to send back to the client
                        conn.send(data.encode()) # send message to the client
        
                elif data.lower().split()[0] == "send": # if the command provided was send 
                
                    if(len(data.split()) > 1): # if a message was sent along with the send command as argument(s)
                        messageSent = username + ": " # create a string of the proper formatting with the given user
                        wordsFromMessage = " ".join(data.split()[1:]) # join all of the words from the message, minus the first argument (send)
                        messageSent += wordsFromMessage # append the message to send to the client with the client's message
                        print(messageSent) # notify on server end the client's message
                        conn.send(messageSent.encode()) # send message to the client
                    
                    else: # if the send command was requested without a message
                        messageSent = "Denied. send command requires a message to be sent." # error message to send back to the client
                        conn.send(messageSent.encode()) # send message to the client
            
                else: # if any other sort of command is given
                    data = "Denied. Provide a valid command." # error message to send back to the client
                    conn.send(data.encode()) # send message to the client

    else:
        print "Error: Users file not found!\n"


if __name__ == '__main__': # main program for server.py
    server_program() # call to the server function
