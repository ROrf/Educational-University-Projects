from Animal import Animal
from Animal import Mammal
from Animal import Bird
 
def create_animal():
    animal_number = 0
    improper_input = True
    while(improper_input):
        try:
            animal_number = int(input("\nWould you like to create a mammal or bird?\n1. Mammal\n2. Bird\nWhich would you like to create? "))
            if(animal_number != 1 and animal_number != 2):
                print("Error: You must enter either a 1 or a 2. Please try again")
                continue
            else:
                improper_input = False
        except:
            print("Error: Input must be an integer, specifically 1 or 2")
    if(animal_number == 1):
        animal_type = str(input("\nWhat type of mammal would you like to create? "))
        animal_name = str(input("What is the mammal's name? "))
        animal_hair_color = str(input("What color is the mammal's hair? "))
        animal = Mammal(animal_type, animal_name, "mood", animal_hair_color)
    else:
        animal_type = str(input("\nWhat type of bird would you like to create? "))
        animal_name = str(input("What is the bird's name? "))
        animal_can_fly = str(input("Can the bird fly? "))
        animal = Bird(animal_type, animal_name, "mood", animal_can_fly)
        print(animal)
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
