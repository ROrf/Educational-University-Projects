<?php
    if(!session_start()) {
		header("Location: error.php");
		exit;
	}
	
	$loggedIn = empty($_SESSION['loggedin']) ? false : $_SESSION['loggedin'];
	if (!$loggedIn) {
		header("Location: login.php");
		exit;
	}

    $action = empty($_GET['action']) ? '' : $_GET['action'];

    if ($action == 'do_survey') {
        handle_survey();
    } else {
        survey_form();
    }

    function handle_survey() {
        $favorite = empty($_GET['favorite']) ? '' : $_GET['favorite'];
        $playoffTeams = empty($_GET['playoffs']) ? '' : $_GET['playoffs'];
        if($favorite != "Chicago Bears" && $favorite != "Detroit Lions" && $favorite != "Green Bay Packers" && $favorite != "Minnesota Vikings" && $favorite != "Atlanta Falcons" && $favorite != "Carolina Panthers" && $favorite != "New Orleans Saints" && $favorite != "Tampa Bay Buccaneers" && $favorite != "Dallas Cowboys" && $favorite != "New York Giants" && $favorite != "Philadelphia Eagles" && $favorite != "Washington Football Team" && $favorite != "Arizona Cardinals" && $favorite != "Los Angeles Rams" && $favorite != "San Francisco 49ers" && $favorite != "Seattle Seahawks") {
                echo "That is not a valid team. Please try again!\n<br>";
                survey_form();
            }
            else {
                echo "Your favorite team is the " . $favorite . "!\n<br>";
            }
        echo "You believe these teams will make the playoffs:\n<br>";
        foreach($playoffTeams as $key => $value) {
            if($key >= 7) {
                echo "Unfortunately you have typed in too many teams. Try Again!\n<br>";
                survey_form();
            }
            if($value != "Chicago Bears" && $value != "Detroit Lions" && $value != "Green Bay Packers" && $value != "Minnesota Vikings" && $value != "Atlanta Falcons" && $value != "Carolina Panthers" && $value != "New Orleans Saints" && $value != "Tampa Bay Buccaneers" && $value != "Dallas Cowboys" && $value != "New York Giants" && $value != "Philadelphia Eagles" && $value != "Washington Football Team" && $value != "Arizona Cardinals" && $value != "Los Angeles Rams" && $value != "San Francisco 49ers" && $value != "Seattle Seahawks") {
                echo "That is not a valid team. Please try again!\n<br>";
                survey_form();
            }
            else {
                echo $value . "\n<br>";
            }
        }
    }

    function survey_form() {
        $favorite = "";
        $playoffTeams = "";
        require "survey_form.php";
        exit;
    }
?>
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
	    <title>Survey Results</title>
        <script src="jslibs/jquery-2.1.4.min.js"></script>
        <script src="privateNavBar.js"></script>
        <link href="navBar.css" rel="stylesheet" type="text/css">
        <link href="general.css" rel="stylesheet" type="text/css">
    </head>
    <body>
        <h4>Click a tab on the nav bar to go back to another page!</h4>
    </body>
</html>