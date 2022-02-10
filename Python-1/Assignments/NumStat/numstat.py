do_calculations = True

while(do_calculations):

    file_exists = False
    file_sum = 0
    file_count = 0
    file_average = 0
    file_maximum = 0
    file_minimum = 10000000000000000000
    file_range = 0

    file_name = input("\nWhat is the name of the file you would like us to evaluate? ")

    try:
        f = open(file_name, "r")
        file_exists = True
    except:
        print("\nThe provided file could not be found along this file path!")

    if(file_exists):
        try:
            for x in f:
                file_count += 1
                number = int(x)
                file_sum += number
                if(number > file_maximum):
                    file_maximum = number
                if(number < file_minimum):
                    file_minimum = number
                    
            print("Sum: %d" % file_sum)
            print("Count: %d" % file_count)
            print("Average: %.1f" % (file_sum / file_count))
            print("Maximum: %d" % file_maximum)
            print("Minimum: %d" % file_minimum)
            print("Range: %d" % (file_maximum - file_minimum))
        
        except:
            print("\nAn error occured while reading in numbers from the given file!")

        f.close()
        print("\nThe file " + file_name + " has been closed properly!")
    
    if(input("Would you like to evaluate another file? (y/n): ") != "y"):
        do_calculations = False
