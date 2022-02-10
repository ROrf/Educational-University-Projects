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
	    <title>Survey</title>
        <link href="jquery-ui-1.12.1.custom/jquery-ui.min.css" rel="stylesheet" type="text/css">
        <script src="jquery-ui-1.12.1.custom/external/jquery/jquery.js"></script>
        <script src="jquery-ui-1.12.1.custom/jquery-ui.min.js"></script>
        <script src="jslibs/jquery-2.1.4.min.js"></script>
        <script src="privateNavBar.js"></script>
        <link href="navBar.css" rel="stylesheet" type="text/css">
        <link href="general.css" rel="stylesheet" type="text/css">
        <script>
        $(function(){
            $("input[type=submit]").button();
        });
        </script>
        <style>
            .ui-widget-header {
                text-align: center;
            }
            #surveyWidget {
                width: 40em;
                margin: 2em auto;
            }
            #surveyWidget form {
                background-color: white;
                border: 1px solid #013369;
                padding: 1em 0;
                border-radius: 2em;
            }
            #surveyWidget div.stack {
                margin: 1em auto;
                text-align: center;
            }
        </style>
    </head>
    <body onload="addCurrent('survey')">
        <div id="surveyWidget" class="ui-widget">
        <h1 class="ui-widget-header">NFC Teams Survey</h1>
        
        <?php
            if ($error) {
                print "<div class=\"ui-state-error\">$error</div>\n";
            }
        ?>
        
        <form action="survey.php" method="GET">
            
            <input type="hidden" name="action" value="do_survey">
            
            <div id="favoriteContainer" class="stack">
                <p>Choose Your Favorite NFC Team:</p>
                <input type="radio" id="bearsFan" name="favorite" value="Chicago Bears" required>
                <label for="bearsFan">Chicago Bears</label><br>
                <input type="radio" id="lionsFan" name="favorite" value="Detroit Lions">
                <label for="lionsFan">Detroit Lions</label><br>
                <input type="radio" id="packersFan" name="favorite" value="Green Bay Packers" checked>
                <label for="packersFan">Green Bay Packers</label><br>
                <input type="radio" id="vikingsFan" name="favorite" value="Minnesota Vikings">
                <label for="vikingsFan">Minnesota Vikings</label><br>
                <input type="radio" id="falconsFan" name="favorite" value="Atlanta Falcons">
                <label for="falconsFan">Atlanta Falcons</label><br>
                <input type="radio" id="panthersFan" name="favorite" value="Carolina Panthers">
                <label for="panthersFan">Carolina Panthers</label><br>
                <input type="radio" id="saintsFan" name="favorite" value="New Orleans Saints">
                <label for="saintsFan">New Orleans Saints</label><br>
                <input type="radio" id="buccaneersFan" name="favorite" value="Tampa Bay Buccaneers">
                <label for="buccaneersFan">Tampa Bay Buccaneers</label><br>
                <input type="radio" id="cowboysFan" name="favorite" value="Dallas Cowboys">
                <label for="cowboysFan">Dallas Cowboys</label><br>
                <input type="radio" id="giantsFan" name="favorite" value="New York Giants">
                <label for="giantsFan">New York Giants</label><br>
                <input type="radio" id="eaglesFan" name="favorite" value="Philadelphia Eagles">
                <label for="eaglesFan">Philadelphia Eagles</label><br>
                <input type="radio" id="washingtonFan" name="favorite" value="Washington Football Team">
                <label for="washingtonFan">Washington Football Team</label><br>
                <input type="radio" id="cardinalsFan" name="favorite" value="Arizona Cardinals">
                <label for="cardinalsFan">Arizona Cardinals</label><br>
                <input type="radio" id="ramsFan" name="favorite" value="Los Angeles Rams">
                <label for="ramsFan">Los Angeles Rams</label><br>
                <input type="radio" id="ninersFan" name="favorite" value="San Francisco 49ers">
                <label for="ninersFan">San Francisco 49ers</label><br>
                <input type="radio" id="seahawksFan" name="favorite" value="Seattle Seahawks">
                <label for="seahawksFan">Seattle Seahawks</label><br>
            </div>
            
            <div id="playoffContainer" class="stack">
                <p>Choose Up To 7 Teams That You Think Will Make the Playoffs:</p>
                <input type="checkbox" id="bearsBeliever" class="checkbox" name="playoffs[]" value="Chicago Bears">
                <label for="bearsBeliever">Chicago Bears</label><br>
                <input type="checkbox" id="lionsBeliever" class="checkbox" name="playoffs[]" value="Detroit Lions">
                <label for="lionsBeliever">Detroit Lions</label><br>
                <input type="checkbox" id="packersBeliever" class="checkbox" name="playoffs[]" value="Green Bay Packers">
                <label for="packersBeliever">Green Bay Packers</label><br>
                <input type="checkbox" id="vikingsBeliever" class="checkbox" name="playoffs[]" value="Minnesota Vikings">
                <label for="vikingsBeliever">Minnesota Vikings</label><br>
                <input type="checkbox" id="falconsBeliever" class="checkbox" name="playoffs[]" value="Atlanta Falcons">
                <label for="falconsBeliever">Atlanta Falcons</label><br>
                <input type="checkbox" id="panthersBeliever" class="checkbox" name="playoffs[]" value="Carolina Panthers">
                <label for="panthersBeliever">Carolina Panthers</label><br>
                <input type="checkbox" id="saintsBeliever" class="checkbox" name="playoffs[]" value="New Orleans Saints">
                <label for="saintsBeliever">New Orleans Saints</label><br>
                <input type="checkbox" id="buccaneersBeliever" class="checkbox" name="playoffs[]" value="Tampa Bay Buccaneers">
                <label for="buccaneersBeliever">Tampa Bay Buccaneers</label><br>
                <input type="checkbox" id="cowboysBeliever" class="checkbox" name="playoffs[]" value="Dallas Cowboys">
                <label for="cowboysBeliever">Dallas Cowboys</label><br>
                <input type="checkbox" id="giantsBeliever" class="checkbox" name="playoffs[]" value="New York Giants">
                <label for="giantsBeliever">New York Giants</label><br>
                <input type="checkbox" id="eaglesBeliever" class="checkbox" name="playoffs[]" value="Philadelphia Eagles">
                <label for="eaglesBeliever">Philadelphia Eagles</label><br>
                <input type="checkbox" id="washingtonBeliever" class="checkbox" name="playoffs[]" value="Washington Football Team">
                <label for="washingtonBeliever">Washington Football Team</label><br>
                <input type="checkbox" id="cardinalsBeliever" class="checkbox" name="playoffs[]" value="Arizona Cardinals">
                <label for="cardinalsBeliever">Arizona Cardinals</label><br>
                <input type="checkbox" id="ramsBeliever" class="checkbox" name="playoffs[]" value="Los Angeles Rams">
                <label for="ramsBeliever">Los Angeles Rams</label><br>
                <input type="checkbox" id="ninersBeliever" class="checkbox" name="playoffs[]" value="San Francisco 49ers">
                <label for="ninersBeliever">San Francisco 49ers</label><br>
                <input type="checkbox" id="seahawksBeliever" class="checkbox" name="playoffs[]" value="Seattle Seahawks">
                <label for="seahawksBeliever">Seattle Seahawks</label><br>
            </div>
            
            <div class="stack" id="submitButton">
                <input type="submit" value="Submit">
            </div>
        </form>
        <br>
    </div>
    <script>
        // Reference code retrieved from: https://stackoverflow.com/questions/19001844/how-to-limit-the-number-of-selected-checkboxes
        $('input.checkbox').on('click', function (evt) {
           if($('.checkbox:checked').length > 7) {
               alert("You can only select 7 teams!");
               this.checked = false;
           } 
        });
        // end of reference code
    </script>
    </body>
</html>