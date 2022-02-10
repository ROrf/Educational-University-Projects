<?php
// Reference code retrieved from the "logout.php" file in "3. createUser" directory from Lecture 26 in CS2830. The original creator is Professor Wergeles of the University of Missouri 

	if(!session_start()) {
		header("Location: error.php");
		exit;
	}

	$_SESSION = array();

	if (ini_get("session.use_cookies")) {
		$params = session_get_cookie_params();
		setcookie(session_name(), '', 1,
			$params["path"], $params["domain"],
			$params["secure"], $params["httponly"]
		);
	}

	session_destroy();

	header("Location: index.html");
	exit;
// end of reference code
?>