file_exists = True
count_applicable = True

try:
    f = open("randomnum.txt", "r")
except:
    print("\nThe file randomnum.txt does not exist on this file path!")
    file_exists = False

if(file_exists):
    count = 0
    print("\nList of random numbers in randomnum.txt:")
    
    for x in f:
        given_line = x.split(" ")
        try:
            random_num = int(given_line[0])
        except:
            print("The provided value in the randomnum.txt file cannot be converted into an integer!")
            count_applicable = False
            break
        else:
            count += 1
            print("%d" % random_num)

    if(count_applicable):
        print("\nRandom number count: %d" % count)

    f.close()
    print("The file randomnum.txt has been closed properly!")
    
    
