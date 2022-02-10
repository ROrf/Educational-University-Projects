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
?>
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
	   <title>Current Records</title>
        <style>
            #dropBox {
                width: 18.75em;
                height: 18.75em;
                line-height: 18.75em;
                margin: 1em auto;
                background-color: #013369;
                color: white;
                font-weight: bold;
                text-align: center;
                border: .5em groove white;
            }
            h5 {
                margin-left: 1.5em;
            }
            #teamName, #teamRecord, #teamPosition {
                float: left;
                font-size: 2em;
                font-weight: bold;
                width: 12em;
            }
            #teamName, #teamPosition {
                margin: 1em 1.5em;
            }
            #teamRecord {
                margin: 1em 0 1em 4em;
            }
            #logos {
                list-style: none;
            }
            #logos > li {
                float: left;
            }
            .logo {
                width: 12.5em;
                height: 12.5em;
                margin: 1em;
            }
            .clear:after {
                content: "";
                display: table;
                clear: both;
            }
        </style>
        <script src="jslibs/jquery-2.1.4.min.js"></script>
        <script src="privateNavBar.js"></script>
        <link href="navBar.css" rel="stylesheet" type="text/css">
        <link href="general.css" rel="stylesheet" type="text/css">
        <link href="jquery-ui-1.12.1.custom/jquery-ui.css" rel="stylesheet">
        <script src="jquery-ui-1.12.1.custom/external/jquery/jquery.js"></script>
        <script src="jquery-ui-1.12.1.custom/jquery-ui.js"></script>
        <!-- Reference code retrieved from the "recordPlayer.html" file from Lecture 23 in CS2830. The original creator is Professor Wergeles of the University of Missouri -->
        <script>
            $(function(){
                $(".logo").draggable();
                $("#dropBox").droppable({
                    drop: function(event, ui){
                        var logo = ui.draggable;
                        var team = logo.prop("alt");
                        switch(team) {
                            case "Bears Logo":
                                $("#teamName").html("Chicago Bears");
                                $("#teamRecord").html("5-7");
                                $("#teamPosition").html("3rd in NFC North");
                                break;
                            case "Lions Logo":  
                                $("#teamName").html("Detroit Lions");
                                $("#teamRecord").html("5-7");
                                $("#teamPosition").html("4th in NFC North");
                                break;
                            case "Packers Logo":
                                $("#teamName").html("Green Bay Packers");
                                $("#teamRecord").html("9-3");
                                $("#teamPosition").html("1st in NFC North");
                                break;
                            case "Vikings Logo":
                                $("#teamName").html("Minnesota Vikings");
                                $("#teamRecord").html("6-6");
                                $("#teamPosition").html("2nd in NFC North");
                                break;
                            case "Falcons Logo":
                                $("#teamName").html("Atlanta Falcons");
                                $("#teamRecord").html("4-8");
                                $("#teamPosition").html("3rd in NFC South");
                                break;
                            case "Panthers Logo":
                                $("#teamName").html("Carolina Panthers");
                                $("#teamRecord").html("4-8");
                                $("#teamPosition").html("4th in NFC South");
                                break;
                            case "Saints Logo":
                                $("#teamName").html("New Orleans Saints");
                                $("#teamRecord").html("10-2");
                                $("#teamPosition").html("1st in NFC South");
                                break;
                            case "Buccaneers Logo":
                                $("#teamName").html("Tampa Bay Buccaneers");
                                $("#teamRecord").html("7-5");
                                $("#teamPosition").html("2nd in NFC South");
                                break;
                            case "Cowboys Logo":
                                $("#teamName").html("Dallas Cowboys");
                                $("#teamRecord").html("3-9");
                                $("#teamPosition").html("4th in NFC East");
                                break;
                            case "Giants Logo":
                                $("#teamName").html("New York Giants");
                                $("#teamRecord").html("5-7");
                                $("#teamPosition").html("1st in NFC East");
                                break;
                            case "Eagles Logo":
                                $("#teamName").html("Philadelphia Eagles");
                                $("#teamRecord").html("3-8-1");
                                $("#teamPosition").html("3rd in NFC East");
                                break;
                            case "Washington Logo":
                                $("#teamName").html("Washington Football Team");
                                $("#teamRecord").html("5-7");
                                $("#teamPosition").html("2nd in NFC East");
                                break;
                            case "Cardinals Logo":
                                $("#teamName").html("Arizona Cardinals");
                                $("#teamRecord").html("6-6");
                                $("#teamPosition").html("3rd in NFC West");
                                break;
                            case "Rams Logo":
                                $("#teamName").html("Los Angeles Rams");
                                $("#teamRecord").html("8-4");
                                $("#teamPosition").html("1st in NFC West");
                                break;
                            case "49ers Logo":
                                $("#teamName").html("San Francisco 49ers");
                                $("#teamRecord").html("5-7");
                                $("#teamPosition").html("4th in NFC West");
                                break;
                            case "Seahawks Logo":
                                $("#teamName").html("Seattle Seahawks");
                                $("#teamRecord").html("8-4");
                                $("#teamPosition").html("2nd in NFC West");
                                break;
                            default:
                                break;
                        }
                        logo.fadeOut();
                    }
                });
            });
        </script>
    </head>
    <body onload="addCurrent('currentRecords')">
        <div id="dropBox">Drag Here!</div>
        <h5>*Updated as of Wednesday, December 9, 2020</h5>
        <div id="teamName" class="clear">Team Name</div>
        <div id="teamRecord" class="clear">Team Record</div>
        <div id="teamPosition" class="clear">Team Position</div>
		<ul id="logos">
            <li><img class="logo clear" src="Logos/bears_logo.jpg" alt="Bears Logo"></li>
            <li><img class="logo clear" src="Logos/lions_logo.jpg" alt="Lions Logo"></li>
            <li><img class="logo clear" src="Logos/packers_logo.jpg" alt="Packers Logo"></li>
            <li><img class="logo clear" src="Logos/vikings_logo.jpg" alt="Vikings Logo"></li>
            <li><img class="logo clear" src="Logos/falcons_logo.jpg" alt="Falcons Logo"></li>
            <li><img class="logo clear" src="Logos/panthers_logo.jpg" alt="Panthers Logo"></li>
            <li><img class="logo clear" src="Logos/saints_logo.jpg" alt="Saints Logo"></li>
            <li><img class="logo clear" src="Logos/buccaneers_logo.jpg" alt="Buccaneers Logo"></li>
            <li><img class="logo clear" src="Logos/cowboys_logo.jpg" alt="Cowboys Logo"></li>
            <li><img class="logo clear" src="Logos/giants_logo.png" alt="Giants Logo"></li>
            <li><img class="logo clear" src="Logos/eagles_logo.jpg" alt="Eagles Logo"></li>
            <li><img class="logo clear" src="Logos/washington_logo.png" alt="Washington Logo"></li>
            <li><img class="logo clear" src="Logos/cardinals_logo.jpg" alt="Cardinals Logo"></li>
            <li><img class="logo clear" src="Logos/rams_logo.jpg" alt="Rams Logo"></li>
            <li><img class="logo clear" src="Logos/49ers_logo.jpg" alt="49ers Logo"></li>
            <li><img class="logo clear" src="Logos/seahawks_logo.jpg" alt="Seahawks Logo"></li>
		</ul>
        <!-- end of reference code (much of this code was in fact my own, however I would still like to give tribute to the original source of code) -->
    </body>
</html>