import random

class Animal:
    def __init__(self, __animal_type, __name, __mood):
        self.__animal_type = __animal_type
        self.__name = __name
        mood = random.randint(1,3)
        if(mood == 1):
            self.__mood = "happy"
        elif(mood == 2):
            self.__mood = "hungry"
        else:
            self.__mood = "sleepy"

    def get_animal_type(self):
        return self.__animal_type

    def get_name(self):
        return self.__name

    def check_mood(self):
        return self.__mood
