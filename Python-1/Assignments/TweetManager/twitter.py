from Tweet import Tweet
import pickle

def make_a_tweet():
    name = input("\nWhat is your name? ")
    tweet_length = 150
    while(tweet_length > 140):
        message = input("What would you like to tweet? ")
        tweet_length = len(message)
        if(tweet_length > 140):
            print("\nTweets can only be 140 characters!\n")
    tweet = Tweet(name, message)
    print(name + ", your tweet has been saved.")
    return tweet

def view_recent_tweets(tweets):
    print("\nRecent Tweets\n-----")
    if(len(tweets) == 0):
        print("There are no recent tweets.")
    else:
        tweets.reverse()
        count = 0
        for tweet in tweets:
            print("\n" + tweet.get_author() + " - " + tweet.get_age() + "\n" + tweet.get_text())
            count += 1
            if(count > 4):
                  break
        tweets.reverse()

def search_tweets(tweets, keyword):
    print("\nSearch Results\n-----")
    if(len(tweets) == 0):
        print("There are no recent tweets.")
    else:
        contains = 0
        for tweet in tweets:
            message = tweet.get_text()
            if keyword in message:
                print("\n" + tweet.get_author() + " - " + tweet.get_age() + "\n" + message)
                contains = 1
        if(contains == 0):
            print("No tweets contained " + keyword)

def main():
    more_tweets = True
    try:
        f = open("tweets.dat", "rb")
        tweets = pickle.load(f)
        f.close()
    except:
        tweets = []
    while(more_tweets):
        print("\nTweet Menu\n-----\n1. Make a Tweet\n2. View Recent Tweets\n3. Search Tweets\n4. Quit")
        improper_selection = True
        while(improper_selection):
            try:
                menu_choice = int(input("\nWhat would you like to do? "))
                if(menu_choice < 1 or menu_choice > 4):
                    print("Please select a valid option")
                    continue
                else:
                    improper_selection = False
            except:
                print("Please enter a numeric value.")
        if(menu_choice == 1):
            tweets.append(make_a_tweet())
        elif(menu_choice == 2):
            view_recent_tweets(tweets)
        elif(menu_choice == 3):
            keyword = input("What would you like to search for? ")
            search_tweets(tweets, keyword)
        else:
            print("Thank you for using the Tweet Manager!")
            more_tweets = False
    with open('tweets.dat', 'wb') as f:
        pickle.dump(tweets, f)
        f.close()

main()
