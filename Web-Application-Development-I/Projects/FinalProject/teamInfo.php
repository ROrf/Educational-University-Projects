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
        <!-- Required meta tag for Bootstrap CSS retrieved from the link:
        https://getbootstrap.com/docs/4.0/getting-started/introduction/#starter-template
        -->
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <!-- end of reference code -->
	   <title>Team Info</title>
        <script src="jslibs/jquery-2.1.4.min.js"></script>
        <script src="privateNavBar.js"></script>
        <link href="navBar.css" rel="stylesheet" type="text/css">
        <!-- Bootstrap CSS retrieved from the document "bootstrap-template.html" provided on Canvas for the Tables Challenge, which was retrieved from the link:
        https://getbootstrap.com/docs/4.0/getting-started/introduction/#css
        -->
        <link rel="stylesheet" 
              href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" 
              integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" 
              crossorigin="anonymous">
        <!-- end of reference code -->
        <style>
            table {
                margin-top: 3em;
            }
            th, td{
                text-align: center;
                color: #6C8E68;
            }
            .title {
                font-size: 2.5em;
                color: #013369;
            }
        </style>
    </head>
    <body onload="addCurrent('teamInfo')">
        <!-- All Bootstrap CSS table classes retrieved from the link: 
        https://getbootstrap.com/docs/4.0/content/tables/
        -->
        <div class="table-responsive">
            <table class="table table-hover table-bordered table-dark table-sm">
            <!-- end of reference code -->
                <thead>
                    <tr>
                        <th colspan="9" class="title">NFC Teams</th>
                    </tr>
                    <tr>
                        <th>Name</th>
                        <th>City</th>
                        <th>Division</th>
                        <th>Year Founded</th>
                        <th>Stadium</th>
                        <th>Number of Superbowls</th>
                        <th>Current Head Coach</th>
                        <th>Current General Manager</th>
                        <th>Current Owner</th>
                    </tr>
                </thead>
                <tbody>
                
                </tbody>
            </table>
        </div>
    </body>
</html>