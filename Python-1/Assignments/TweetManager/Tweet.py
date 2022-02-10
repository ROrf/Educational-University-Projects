import time

class Tweet:
    def __init__(self, __author, __text):
        self.__author = __author
        self.__text = __text
        self.__age = time.time()

    def get_author(self):
        return self.__author

    def get_text(self):
        return self.__text

    def get_age(self):
        new_age = time.time() - self.__age
        if(new_age >= 60 and new_age < 3600):
            return str(int(new_age//60)) + "m"
        elif(new_age >= 3600):
            return str(int(new_age//3600)) + "h"
        return str(int(new_age)) + "s"
        
