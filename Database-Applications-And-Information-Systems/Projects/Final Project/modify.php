<?php
    require_once 'db.conf';

    $connection = new mysqli($dbhost, $dbuser, $dbpass, $dbname);

    if($connection->connect_error){
        die("Connection failed: " . $connection->connect_error);
    }

    $personID = empty($_POST['personID']) ? '' : $_POST['personID'];
    $data = empty($_POST['data']) ? '' : $_POST['data'];

    sql = "UPDATE `person` SET `MedicalData` = $data WHERE `person`.`PersonID` = $personID";

    if($connection->query($sql) === TRUE){
        echo "Update successful!";
    }
    else {
        echo "Error: " . $sql . "<br>" . $connection->error;
    }

    $connection->close();

?>