<?php
    if($_SERVER['REQUEST_METHOD'] === 'GET'){
        /* array_key_exists() function retrieved from:
            https://www.w3schools.com/php/func_array_key_exists.asp*/
        if(array_key_exists("firstName", $_GET) && array_key_exists("lastName", $_GET))
            // end of reference code
        {
            $firstName = $_GET['firstName'];
            $lastName = $_GET['lastName'];
            print "Hello $firstName $lastName, welcome to my PHP playground, designed to simulate the value of server-side development and use in web development!";
        }
        else if(array_key_exists("hamNum", $_GET)){
            $hamNum = $_GET['hamNum'];
            if($hamNum%2 == 0 || $hamNum%3 == 0 || $hamNum%5 == 0){
                print "The provided number is a Hamming Number!";
            }
            else {
                print "The provided number is not a Hamming Number!";
            }
        }
        else if(array_key_exists("firstValue", $_GET) && array_key_exists("lastValue", $_GET)){
            $firstValue = $_GET['firstValue'];
            $lastValue = $_GET['lastValue'];
            /* ord() function retrieved from:
                https://www.w3schools.com/php/func_string_ord.asp#:~:text=The%20ord()%20function%20returns,first%20character%20of%20a%20string.*/
            $first = ord($firstValue);
            $last = ord($lastValue);
            // end of reference code
            print "[ ";
            if($first < $last){
                for($i = $first; $i <= $last; $i++) {
                    /* format for printing ascii characters retrieved from:
                        https://stackoverflow.com/questions/40440136/how-to-print-a-list-of-all-ascii-characters-with-php*/
                    echo utf8_encode(chr($i));
                    // end of reference code
                    if($i == $last) {
                        print "]";
                    }
                    else {
                        print ", ";
                    }
                }
            }
            else if($first > $last){
                for($i = $first; $i >= $last; $i--) {
                    echo utf8_encode(chr($i));
                    if($i == $last) {
                        print "]";
                    }
                    else {
                        print ", ";
                    }
                }
            }
            else {
                echo utf8_encode(chr($first));
                print "]";
            }

        }
        else if(array_key_exists("radius", $_GET) && array_key_exists("height", $_GET)){
            $radius = $_GET['radius'];
            $height = $_GET['height'];
            $sa = 2*3.14159265*$radius*$height + 2*3.14159265*$radius*$radius;
            print "Surface Area = ";
            /* Printing format retrieved from:
                https://stackoverflow.com/questions/4483540/show-a-number-to-two-decimal-places#:~:text=Use%20the%20PHP%20number_format()%20function.&text=This%20will%20display%20exactly%20two,for%20int%2C%20then%20use%20this.*/
            echo sprintf("%.2f", $sa);
            // end of reference code
        }
        else {
            print "Error: No function found";
        }
    }
    else if($_SERVER['REQUEST_METHOD'] === 'POST'){
       // print $_POST['username'];
        if(array_key_exists("username", $_POST) && array_key_exists("password", $_POST)){
            $username = $_POST['username'];
            $password = $_POST['password'];
            if($username !== "test-user" || $password !== "test-password"){
                print "Username or password is incorrect";
            }
            else {
                print "Credentials validated with POST";
            }
        }
        else {
            print "Error: No function found";
        }
    }
    else {
        print "Error: No GET or POST method found";
    }
?>