import math
do_estimate = True
while(do_estimate):

    while(True):
        try:
            wall_square_footage = float(input("\nEnter the square feet of wall space that needs to be painted: "))
            if(wall_square_footage <= 0):
                print("Negative or zero square footage values are not permitted!")
                continue
        except ValueError:
            print("The entered value is not allowed. Only numerical values are permitted!")
        else:
            break

    while(True):
        try:
            price_per_gallon = float(input("Enter the price of the paint per gallon: "))
            if(price_per_gallon <= 0):
                print("Negative or zero square footage values are not permitted!")
                continue
        except ValueError:
            print("The entered value is not allowed. Only numerical values are permitted!")
        else:
            break

    paint_gallons_required = math.ceil(wall_square_footage/350)
    hours_of_labor = (6/350) * wall_square_footage
    total_paint_cost = paint_gallons_required * price_per_gallon
    labor_charges = 62.25 * hours_of_labor
    total_job_cost = total_paint_cost + labor_charges

    print("\nThis job requires %d" % paint_gallons_required + " gallon(s) of paint.")
    print("This job requires %.1f" % hours_of_labor + " hour(s) of labor.")
    print("This job will cost $%.2f" % total_paint_cost + " in paint.")
    print("This job will cost $%.2f" % labor_charges + " in labor charges.")
    print("The total cost of this paint job is $%.2f" % total_job_cost + ".")
    
    if(input("\nWould you like to do another estimate? (y/n): ") != "y"):
        do_estimate = False
