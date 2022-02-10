<?php
// Reference code retrieved from the "login.php" file in "3. createUser" directory from Lecture 26 in CS2830. The original creator is Professor Wergeles of the University of Missouri
    
	if(!session_start()) {
		header("Location: error.php");
		exit;
	}

	$loggedIn = empty($_SESSION['loggedin']) ? false : $_SESSION['loggedin'];
	
	if ($loggedIn) {
		header("Location: teamInfo.php");
		exit;
	}
	
	
	$action = empty($_POST['action']) ? '' : $_POST['action'];
	
	if ($action == 'do_login') {
		handle_login();
	} else {
		login_form();
	}
	
	function handle_login() {
		$username = empty($_POST['username']) ? '' : $_POST['username'];
		$password = empty($_POST['password']) ? '' : $_POST['password'];

        require_once 'db.conf';

        $mysqli = new mysqli($dbhost, $dbuser, $dbpass, $dbname);

        if ($mysqli->connect_error) {
            $error = 'Error: ' . $mysqli->connect_errno . ' ' . $mysqli->connect_error;
			require "login_form.php";
            exit;
        }

        $username = $mysqli->real_escape_string($username);
        $password = $mysqli->real_escape_string($password);

        $password = sha1($password); 

		$query = "SELECT id FROM users WHERE username = '$username' AND userPassword = '$password'";

		$mysqliResult = $mysqli->query($query);

        if ($mysqliResult) {
            $match = $mysqliResult->num_rows;
            $mysqliResult->close();
            $mysqli->close();

  		    if ($match == 1) {
                $_SESSION['loggedin'] = $username;
                header("Location: teamInfo.php");
                exit;
            }
            else {
                $error = 'Error: The username or passwored is incorrect';
                require "login_form.php";
                exit;
            }
        }

        else {
          $error = 'Login Error: Please talk to an administrator.';
          require "login_form.php";
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