class Player:
    def __init__(self, __name):
        self.__name = __name
        self.__chips = 50 
        self.__wins = 0
        self.__losses = 0
        self.__pushes = 0
        self.__blackjacks = 0

    def get_name(self):
        return self.__name

    def get_chips(self):
        return self.__chips

    def get_wins(self):
        return self.__wins

    def get_losses(self):
        return self.__losses

    def get_pushes(self):
        return self.__pushes

    def get_blackjacks(self):
        return self.__blackjacks

    def inc_chips(self, amount):
        self.__chips = self.__chips + amount

    def dec_chips(self, amount):
        self.__chips = self.__chips - amount

    def inc_wins(self):
        self.__wins = self.__wins + 1

    def inc_losses(self):
        self.__losses = self.__losses + 1

    def inc_pushes(self):
        self.__pushes = self.__pushes + 1

    def inc_blackjacks(self):
        self.__blackjacks = self.__blackjacks + 1
