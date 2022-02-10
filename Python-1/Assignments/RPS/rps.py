import pickle, random

def playGame(stats):
    roundNo = stats[1] + stats[2] + stats[3] + 1
    gameOptions = ["Rock", "Paper", "Scissors"]
    
    unacceptable_option = True
    while(unacceptable_option):

        try:
            decision = int(input("\nRound " + str(roundNo) + "\n\n1. Rock\n2. Paper\n3. Scissors\n\nWhat will it be? "))
            if(decision != 1 and decision != 2 and decision != 3):
                print("Error: You must select Rock, Paper, or Scissors!")
                continue
            else:
                unacceptable_option = False
        except:
            print("Error: Input must be an integer between 1 and 3!")

    computer_decision = random.randint(1, 3)

    if(decision == computer_decision + 1 or decision == computer_decision - 2):
        print("\nYou chose " + gameOptions[decision-1] + ". The computer chose " + gameOptions[computer_decision-1] + ". You win!")
        stats[1] = stats[1] + 1
    elif(decision == computer_decision - 1 or decision == computer_decision + 2):
        print("\nYou chose " + gameOptions[decision-1] + ". The computer chose " + gameOptions[computer_decision-1] + ". You lose!")
        stats[2] = stats[2] + 1
    else:
        print("\nYou chose " + gameOptions[decision-1] + ". The computer chose " + gameOptions[computer_decision-1] + ". You tied!")
        stats[3] = stats[3] + 1
    return stats

def viewStats(stats):
    if(stats[2] == 0):
        if(stats[1] == 0):
            ratio = 1.0
        else:
            ratio = float('inf')
    else:
        ratio = float(stats[1])/float(stats[2])
    print(stats[0] + ", here are your game play statistics...\nWins: " + str(stats[1]) + "\nLosses: " + str(stats[2]) + "\nTies: " + str(stats[3]) + "\nWin/Loss Ratio: %.2f" % ratio)

def main():
    unacceptable_menu_choice = True
    while(unacceptable_menu_choice):
        
        try:
            menu_choice = int(input("Welcome to Rock, Paper, Scissors!\n\n1. Start New Game\n2. Load Game\n3. Quit\n\nEnter choice: "))
            if(menu_choice != 1 and menu_choice != 2 and menu_choice != 3):
                print("Error: Input must either be 1, 2, or 3!")
                continue
            else:
                unacceptable_menu_choice = False
        except:
            print("Error: Input must be an integer between 1 and 3!")
            
    if(menu_choice == 3):
        exit
        
    else:
        name = input("What is your name? ")
        stats = [name, 0, 0, 0]
        if(menu_choice == 1):
            print("Hello " + name + ". Let's play!")
        else:
             try:
                 file = open(name + ".rps", "rb")
                 stats = pickle.load(file)
                 file.close()
                 print("Wecome back " + name + ". Let's play!")
             except:
                 print(name + ", your game could not be found.")

        stats = playGame(stats)
            
        still_playing = True
        while(still_playing):
            unacceptable_menu_choice = True
            while(unacceptable_menu_choice):

                try:
                    menu_choice = int(input("\nWhat would you like to do?\n\n1. Play Again\n2. View Statistics\n3. Quit\n\nEnter choice: "))
                    if(menu_choice != 1 and menu_choice != 2 and menu_choice != 3):
                        print("Error: Input must be either 1, 2, or 3!")
                        continue
                    else:
                        unacceptable_menu_choice = False
                except:
                    print("Error: Input must be an integer between 1 and 3!")

            if(menu_choice == 3):
                still_playing = False
                break

            if(menu_choice == 1):
                stats = playGame(stats)

            else:
                viewStats(stats)

        with open(name + ".rps", "wb") as file:
            try:
                pickle.dump(stats, file)
                print(name + ", your game has been saved.")
            except Exception as e:
                print("Sorry " + name + ", the game could not be saved.\n" + str(e))
        file.close()
            
main()
