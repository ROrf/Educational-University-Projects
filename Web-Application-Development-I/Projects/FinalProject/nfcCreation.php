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
	    <title>Creation</title>
        <script src="jslibs/jquery-2.1.4.min.js"></script>
        <script src="privateNavBar.js"></script>
        <link href="navBar.css" rel="stylesheet" type="text/css">
        <link href="general.css" rel="stylesheet" type="text/css">
        <style>
            #creationTitle {
                text-align: center;
                font-size: 3em;
                text-decoration: underline;
            }
            #videoContainer {
                float: left;
                position: relative;
                left: 50%;
            }
            #fixContainer {
                float: left;
                position: relative;
                left: -50%;
            }
            iframe {
                width: 37.5em;
                height: 25em;
            }
            #explanation {
                margin-top: 30em;
            }
            .photoElements {
                float: left;
                width: 25em;
                height: 25em;
                margin: 2em 10em;
            }
            .clear:after {
                content: "";
                display: table;
                clear: both;
            }
        </style>
    </head>
    <body onload="addCurrent('nfcCreation')">
        <h1 id="creationTitle">The Creation of the NFC</h1>
        <div id="videoContainer">
            <div id="fixContainer">
                <!-- Reference code retrieved from: https://www.w3schools.com/html/html_youtube.asp -->
                <iframe class="clear" src="https://www.youtube.com/embed/m9BenQBkngU"></iframe>
                <!-- end of reference code -->
            </div>
        </div>
        <!-- This information comes from a combination of my own brain and paraphrased from the following website: https://en.wikipedia.org/wiki/AFL%E2%80%93NFL_merger --->
        <h3 id="explanation">Before we had the National Football League as we know it today, there existed 2 major leagues in the United States: the National Football League, and the American Football League. The National Football League had existed without a serious threat to their legacy since the 1920s. However, in the 1960s, a new, popular league emerged: the American Football League. Through the 1960s, the NFL and AFL competed fiercely, both trying to attract great prospects to join their league. In 1966, the NFL and AFL discussed and announced a merger of the 2 leagues. When the 2 leagues merged in 1970, the National Football Conference and the American Football Conference were formed. Each conference would comprise of 13 teams, the AFC actually receiving 3 teams from the NFC to even out the conferences. Pete Rozelle, the commissioner of the former NFL, would remain commissioner of the new NFL. Over time, the conferences would be realigned and additional teams would be added to each conference. This is how the NFC, and AFC, were created!</h3>
        <!-- end of reference code -->
        <div class="photoElements" id="originalNFC">
            <h2>The NFC and AFC in 1970</h2>
            <img src="nfcMerger.gif" alt="NFL Merger">
        </div>
        <div class="photoElements" id="commissioner">
            <h2>Commissioner Pete Rozelle</h2>
            <img src="commissioner.jpg" alt="Commissioner Pete Rozelle">
        </div>
    </body>
</html>