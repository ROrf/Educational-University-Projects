import random

f = open("randomnum.txt", "w")# there is no need to error handle during a write since open will create a new file if "randomnum.txt" does not exist

while(True):
    try:
        quantity = int(input("\nHow many random numbers do you want? "))
        if(quantity <= 0):
            print("Negative or zero quantities are not permitted!")
            continue
    except:
        print("The entered value is not allowed. Only integer values are permitted!")
    else:
        break

while(True):
    try:
        lower_bound = int(input("\nWhat is the lowest the random number should be: "))
        if(lower_bound <= 0):
            print("Negative or zero lower bounds are not permitted!")
            continue
    except:
        print("The entered value is not allowed. Only integer values are permitted!")
    else:
        break

while(True):
    try:
        upper_bound = int(input("\nWhat is the highest the random number should be: "))
        if(upper_bound <= 0):
            print("Negative or zero upper bounds are not permitted!")
            continue
    except:
        print("The entered value is not allowed. Only integer values are permitted!")
    else:
        break

for x in range(0, quantity):
    f.write(str(random.randint(lower_bound, upper_bound)) + " \n")

print("\nThe random numbers were written to randomnum.txt")
f.close()
print("The file randomnum.txt has been closed properly!")
