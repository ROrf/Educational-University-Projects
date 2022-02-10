from Animal import Animal
 
def create_animal():

    animal_type = str(input("\nWhat type of animal would you like to create? "))
    animal_name = str(input("What is the animal's name? "))
    #originally I had error checked these inputs, until I remembered input() defaults the input as a string value

    animal = Animal(animal_type, animal_name, "mood")
    return animal

def list_animals(animals):
    print("\nAnimal List:")
    for animal in animals:
        print(animal.get_name() + " the " + animal.get_animal_type() + " is " + animal.check_mood())

def main():
    more_animals = True
    animals = []
    print("\nWelcome to the animal generator!\nThis program creates Animal objects.")
    while(more_animals):
        animals.append(create_animal())
        if(input("\nWould you like to add more animals (y/n)? ") != "y"):
            more_animals = False
    list_animals(animals)

main()
