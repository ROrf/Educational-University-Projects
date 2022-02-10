while(True):
    try:
        initial_x_position = float(input("Enter the initial x position as a decimal value: "))
        initial_velocity = float(input("Enter the initial velocity as a decimal value: "))
        acceleration = float(input("Enter the acceleration as a decimal value: "))
        time = float(input("Enter the time as a decimal value: "))
        if(time < 0):
            print("Elapsed time must be a non-negative numerical value!")
            continue
    except ValueError:
        print("The value you entered is not an accepted numerical value!")
    else:
        final_x_position = initial_x_position + (initial_velocity * time) + (0.5 * acceleration * (time ** 2))
        print("The final position of x given these input values is: %f" % final_x_position)
        if(input("Would you like to perform another calculation (y/n)? ") != 'y'):
            break
