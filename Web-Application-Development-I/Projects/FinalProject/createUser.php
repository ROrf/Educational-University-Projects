<?php
// Reference code retrieved from the "createUser.php" file in "3. createUser" directory from Lecture 26 in CS2830. The original creator is Professor Wergeles of the University of Missouri

	if(!session_start()) {
		header("Location: error.php");
		exit;
	}

	$loggedIn = empty($_SESSION['loggedin']) ? false : $_SESSION['loggedin'];
	
	if ($loggedIn) {
		header("Location: index.html");
		exit;
	}
	
	
	$action = empty($_POST['action']) ? '' : $_POST['action'];
	
	if ($action == 'do_create') {
		create_user();
	} else {
		login_form();
	}
	
	function create_user() {
		$firstName = empty($_POST['firstName']) ? '' : $_POST['firstName'];
        $lastName = empty($_POST['lastName']) ? '' : $_POST['lastName'];
		$username = empty($_POST['username']) ? '' : $_POST['username'];
		$password = empty($_POST['password']) ? '' : $_POST['password'];
        $confirmPass = empty($_POST['confirmPass']) ? '' : $_POST['confirmPass'];
        $birthday = empty($_POST['birthday']) ? '' : $_POST['birthday'];
        $email = empty($_POST['email']) ? '' : $_POST['email'];
        
        if(strcmp($password, $confirmPass) == 0){
            require_once 'db.conf';

            $mysqli = new mysqli($dbhost, $dbuser, $dbpass, $dbname);

            if ($mysqli->connect_error) {
                $error = 'Error: ' . $mysqli->connect_errno . ' ' . $mysqli->connect_error;
                require "login_form.php";
                exit;
            }

            $firstName = $mysqli->real_escape_string($firstName);
            $lastName = $mysqli->real_escape_string($lastName);
            $username = $mysqli->real_escape_string($username);
            $password = $mysqli->real_escape_string($password);
            $birthday = $mysqli->real_escape_string($birthday);
            $email = $mysqli->real_escape_string($email);

            $query = "INSERT INTO users (firstName, lastName, username, userPassword, email, birthday) VALUES ('$firstName', '$lastName', '$username', sha1('$password'), '$email', STR_TO_DATE('$birthday', '%Y-%m-%d'))";

            if ($mysqli->query($query) === TRUE) {
                    $error = 'You are now a More NFC Info member!';
                    require "login_form.php";
            }

            else {
            $error = 'Insert Error: ' . $query . '<br>' . $mysqli->error;
            require "createUser_form.php";
            }
            
            $mysqli->close();
            exit;
        }
        else {
            $error = "Error: Not the same password!";
            require "createUser_form.php";
            exit;
        }
	}
	
	function login_form() {
		$username = "";
		$error = "";
		require "login_form.php";
        exit;
	}
// end of reference code
?>