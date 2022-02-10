<!DOCTYPE html>
<!-- Reference code retrieved from the "login_form.php" file in "3. createUser" directory from Lecture 26 in CS2830. The original creator is Professor Wergeles of the University of Missouri -->
<html>
<head>
	<title>Log In Page</title>
	<link href="app.css" rel="stylesheet" type="text/css">
    <link href="jquery-ui-1.12.1.custom/jquery-ui.min.css" rel="stylesheet" type="text/css">
    <script src="jquery-ui-1.12.1.custom/external/jquery/jquery.js"></script>
    <script src="jquery-ui-1.12.1.custom/jquery-ui.min.js"></script>
    <script src="jslibs/jquery-2.1.4.min.js"></script>
    <script src="navBar.js"></script>
    <link href="navBar.css" rel="stylesheet" type="text/css">
    <link href="general.css" rel="stylesheet" type="text/css">
    <script>
        $(function(){
            $("input[type=submit]").button();
        });
    </script>
</head>
<body onload="addCurrent('logInPage')">
    <div id="loginWidget" class="ui-widget">
        <h1 class="ui-widget-header">Login</h1>
        
        <?php
            if ($error) {
                print "<div class=\"ui-state-error\">$error</div>\n";
            }
        ?>
        
        <form action="login.php" method="POST">
            
            <input type="hidden" name="action" value="do_login">
            
            <div class="stack">
                <label for="username">Username:</label>
                <input type="text" id="username" name="username" class="ui-widget-content ui-corner-all" autofocus value="<?php print $username; ?>">
            </div>
            
            <div class="stack">
                <label for="password">Password:</label>
                <input type="password" id="password" name="password" class="ui-widget-content ui-corner-all">
            </div>
            
            <div class="stack">
                <input type="submit" value="Submit">
            </div>
        </form>
        <br>
        <a href="createUser_form.php">Need an account? Click here to make one!</a>
        <h4>If you believe you are already logged in, try clicking "Submit"!</h4>
    </div>
</body>
<!-- end of reference code -->
</html>