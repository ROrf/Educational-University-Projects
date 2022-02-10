cipher_key = ("0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "+", "<", ">", "?", "=")

def encrypt_string(decrypted):
    encrypted = ""
    for character in decrypted:
        conversion_element = ord(character) - 97
        if(conversion_element >= 0 and conversion_element < len(cipher_key)):
            encrypted = encrypted + cipher_key[conversion_element]
        else:
            encrypted = encrypted + character
    return encrypted

def decrypt_string(encrypted):
    decrypted = ""
    for character in encrypted:
        decrypted_character = ""
        for element in range(0, len(cipher_key)):
            if(character == cipher_key[element]):
                decrypted_character = chr(element+97)
                break
        if(decrypted_character == ""):
            decrypted = decrypted + character
        else:
            decrypted = decrypted + decrypted_character
    return decrypted

def main():
    option_selection = 1
    while(option_selection == 1 or option_selection == 2):
        print("\nWelcome to the Secret Message Encoder/Decoder\n1. Encode a message\n2. Decode a message\n3. Exit")
        improper_input = True
        while(improper_input):
            try:
                option_selection = int(input("\nWhat would you like to do? "))
                if(option_selection < 1 or option_selection > 3):
                    print("Error: You must enter either a 1, 2, or 3. Please try again!")
                    continue
                else:
                    improper_input = False
            except:
                print("Error: Input must be an integer, specifically 1, 2, or 3")
        if(option_selection == 1):
            message = input("\nEnter a message to encode: ")
            message = encrypt_string(message)
            print("Encoded message: " + message)
        elif(option_selection == 2):
            message = input("\nEnter a message to decode: ")
            message = decrypt_string(message)
            print("Decoded message: " + message)
        else:
            print("\nThank you!")

main()
