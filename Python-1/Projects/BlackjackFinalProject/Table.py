from Player import Player
import pickle, random, sys, math

deck = ["Ace of Clubs", "Ace of Hearts", "Ace of Diamonds", "Ace of Spades", "2 of Clubs", "2 of Hearts", "2 of Diamonds", "2 of Spades",
        "3 of Clubs", "3 of Hearts", "3 of Diamonds", " 3 of Spades", "4 of Clubs", "4 of Hearts", "4 of Diamonds", "4 of Spades",
        "5 of Clubs", "5 of Hearts", "5 of Diamonds", "5 of Spades", "6 of Clubs", "6 of Hearts", "6 of Diamonds", "6 of Spades",
        "7 of Clubs", "7 of Hearts", "7 of Diamonds", "7 of Spades", "8 of Clubs", "8 of Hearts", "8 of Diamonds", "8 of Spades",
        "9 of Clubs", "9 of Hearts", "9 of Diamonds", "9 of Spades", "10 of Clubs", "10 of Hearts", "10 0f Diamonds", "10 of Spades",
        "Jack of Clubs", "Jack of Hearts", "Jack of Diamonds", "Jack of Spades", "Queen of Clubs", "Queen of Hearts", "Queen of Diamonds", "Queen of Spades",
        "King of Clubs", "King of Hearts", "King of Diamonds", "King of Spades"]
values = [11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
discarded = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0]
count = 0 

def initialMenu():
    unacceptable = True
    final_selection = 0
    while(unacceptable):
        try:
            selection = int(input("\nWelcome to the Virtual Ruby Python!\nBlackjack pays 3 to 2\nWe do not play with Splits\nWould you like to step up to the table?\n\n1. Yes\n2. No\n\n"))
            if(selection != 1 and selection != 2):
                print("I'm sorry, but the only available options are 1 or 2.")
                continue
            else:
                unacceptable = False
        except:
            print("Unfortuantely you did not select a valid option. Please select 1 or 2.")
    if(selection == 1):
        unacceptable = True
        while(unacceptable):
            try:
                final_selection = int(input("\nAre you a returning Player?\n1. Yes\n2. No\n\n"))
                if(final_selection != 1 and final_selection != 2):
                    print("It's really a simple question. The only valid options are 1 or 2.")
                    continue
                else:
                    unacceptable = False
            except:
                print("Please provide us with a valid answer. Either select 1 or 2.")
    return final_selection

def blackjackMenu():
    unacceptable = True
    while(unacceptable):
        try:
            selection = int(input("\nWhat action would you like to perform?\n\n1. Play a Hand\n2. View Player Profile\n3. Walk Away\n\n"))
            if(selection != 1 and selection != 2 and selection != 3):
                print("Excuse me, only 1, 2, or 3 are acceptable options.")
                continue
            else:
                unacceptable = False
        except:
            print("You must only enter a 1, 2, or 3.")
    return selection

def viewProfile(player):
    print("\nName: " + player.get_name() + "\nChips: " + str(player.get_chips()) +
          "\nWins: " + str(player.get_wins()) + "\nLosses: " + str(player.get_losses()) +
          "\nPushes: " + str(player.get_pushes()) + "\nBlackjacks: " + str(player.get_blackjacks()))
    if(player.get_losses() == 0):
        if(player.get_wins() == 0):
            ratio = 1.0
        else:
            ratio = float('inf')
    else:
        ratio = float(player.get_wins())/float(player.get_losses())
        print("Win/Loss Ratio: %.2f" % ratio)

def reshuffle():
    global discarded
    global count
    for index in range(52):
        discarded[index] = 0
    count = 0
        
def play(player):
    bad_bet = True
    while(bad_bet):
        try:
            bet = int(input("\nPlease place a bet. Minimum bet is 5 chips.\n\n"))
            if(bet < 5 or bet > player.get_chips()):
                print("I'm sorry, but that is not an acceptable bet. You have to bet at least 5 chips, and you cannot bet more than what you have.")
                continue
            else:
                bad_bet = False
        except:
            print("You must bet a valid amount of chips.")

    hit = True
    dealer_hit = True

    player_hand = 0
    dealer_hand = 0
    outcome = 0
    
    player_hand = drawCard(1, player_hand)
    dealer_hand = drawCard(0, dealer_hand)
    player_hand = drawCard(1, player_hand)
    dealer_hand = drawCard(2, dealer_hand)

    if(player_hand == 21 and dealer_hand != 21):
        print("\nCongrats! You won with a Blackjack!")
        player.inc_wins()
        player.inc_blackjacks()
        player.inc_chips(math.ceil(bet*1.5))
        hit = False
        dealer_hit = False
        outcome = 1

    if(player_hand != 21 and dealer_hand == 21):
        print("\nUnlucky! The Dealer won with a Blackjack!")
        player.inc_losses()
        player.dec_chips(bet)
        hit = False
        dealer_hit = False
        outcome = 1

    if(player_hand == 21 and dealer_hand == 21):
        print("\nWhat a rarity! Both you and the Dealer got a Blackjack!")
        player.inc_pushes()
        hit = False
        dealer_hit = False
        outcome = 1

    if(hit and dealer_hit):
        unacceptable = True
        while(unacceptable):
            try:
                turn = int(input("\nWhat would you like to do?\n\n1. Hit\n2. Stand\n3. Double Down\n4. Surrender\n\n"))
                if(turn < 1 or turn > 4):
                    print("You must submit a valid answer.")
                    continue
                else:
                    unacceptable = False
                    break
            except:
                print("There are only 4 options available.")
        if(turn == 2):
            print("\nYou have chosen to stand.")
            hit = False
        if(turn == 3):
            print("\nYou have chosen to double down. You will now receive one more card.")
            bet *= 2
            player_hand = drawCard(1, player_hand)
            hit = False
        if(turn == 4):
            print("\nYou have chosen to surrender. You will lose half of your original bet.")
            player.inc_losses()
            player.dec_chips(math.ceil(bet/2))
            hit = False
            dealer_hit = False
            outcome = 1
        if(turn == 1):
            player_hand = drawCard(1, player_hand)
            if(player_hand > 21):
                print("\nYou have busted! You automatically lose to the Dealer.")
                player.inc_losses()
                player.dec_chips(bet)
                hit = False
                dealer_hit = False
                outcome = 1

    while(hit):
        unacceptable = True
        while(unacceptable):
            try:
                turn = int(input("\nWhat would you like to do?\n\n1. Hit\n2. Stand\n\n"))
                if(turn != 1 and turn != 2):
                    print("You can only either hit or stand.")
                    continue
                else:
                    unacceptable = False
                    break
            except:
                print("There are only the options to hit or stand now.")
        if(turn == 2):
            print("\nYou have chosen to stand.")
            hit = False
            break
        player_hand = drawCard(1, player_hand)
        if(player_hand > 21):
            print("\nYou have busted! You automatically lose to the Dealer.")
            player.inc_losses()
            player.dec_chips(bet)
            hit = False
            dealer_hit = False
            outcome = 1

    if(dealer_hand >= 17 and dealer_hand <= 21 and outcome == 0):
        print("\nThe Dealer has reached at least 17 and therefore must stand.")
        dealer_hit = False

    while(dealer_hit):
        dealer_hand = drawCard(2, dealer_hand)
        if(dealer_hand >= 17 and dealer_hand <= 21):
            print("\nThe Dealer has reached at least 17 and therefore must stand.")
            dealer_hit = False
            break
        if(dealer_hand > 21):
            print("\nThe Dealer has busted! You automatially win.")
            player.inc_wins()
            player.inc_chips(bet)
            dealer_hit = False
            outcome = 1
            break

    if(outcome == 0):
        if(player_hand > dealer_hand):
            print("\nYou have " + str(player_hand) + ". The Dealer has " + str(dealer_hand) + ". You win!")
            player.inc_wins()
            player.inc_chips(bet)
        if(player_hand < dealer_hand):
            print("\nYou have " + str(player_hand) + ". The Dealer has " + str(dealer_hand) + ". You lose!")
            player.inc_losses()
            player.dec_chips(bet)
        if(player_hand == dealer_hand):
            print("\nBoth you and the Dealer have " + str(player_hand) + ". That results in a push!")
            player.inc_pushes()
                
    return player
    
def drawCard(show, hand):
    global count
    global discarded
    count += 1
    draw = True
    while(draw):
        card = random.randint(0, 51)
        if(discarded[card] < 2):
            draw = False
            break
    discarded[card] += 1
    value = values[math.floor(card/4)]
    
    if(show == 0):
        print("\nThe Dealer has drawn their first card.")
        
    if(show == 1):
        print("\nYou have drawn the " + deck[card] + ".")
        if(value == 11):
            unacceptable = True
            while(unacceptable):
                try:
                    ace = int(input("\nSince you have drawn an Ace, would you like your Ace to count as a 1 or 11?\n(Unlike traditional Blackjack, at the Virtual Ruby Python, you must choose as soon as the Ace is drawn.\n\n"))
                    if(ace != 1 and ace != 11):
                        print("You can only assign values of 1 or 11 to an Ace.")
                        continue
                    else:
                        unacceptable = False
                        break
                except:
                    print("You may only have a 1 or 11 for an Ace.")
            if(ace == 1):
                value = 1
        print("\nHand value: " + str(hand + value))

    if(show == 2):
        print("\nThe Dealer has drawn the " + deck[card] + ".")
        if((hand + value) > 21 and value == 11):
            value = 1

    return (hand + value)
    

def main():
    initial_choice = initialMenu()
    if(initial_choice == 0):
        print("\nThanks for stopping by. Have a good day!")
        sys.exit()
    name = input("\nWhat is your name, Player?\n\n")
    if(initial_choice == 1):
        try:
            file = open(name + ".bj", "rb")
            player = pickle.load(file)
            file.close()
            print("\nWelcome back " + name + ". Let's play!")
        except:
            print("\n" + name + ", your game could not be found.")
            sys.exit()
    else:
        player = Player(name)
        print("\nHello " + name + ". Let's play!")

    playing = True
    while(playing):
        action = blackjackMenu()
        if(action == 3):
            playing = False
            break
        if(action == 1):
            if(player.get_chips() < 5):
                print("\nI apologize " + name + ", but you do not have the minimum number of chips required to play a hand of Blackjack.")
                playing = False
                break
            if(count >= 70):
                print("\nGive us a moment to reshuffle our deck, as we do not support card counting.")
                reshuffle()
            player = play(player)
        else:
            viewProfile(player)
    
    with open(name + ".bj", "wb") as file:
        try:
            pickle.dump(player, file)
            print("\n" + name + ", your profile has been saved.")
        except:
            print("\nSorry " + name + ", the profile could not be saved.\n")
    file.close()
    

main()

