<?php
    require_once 'db.conf';

    $connection = new mysqli($dbhost, $dbuser, $dbpass, $dbname);

    if($connection->connect_error){
        die("Connection failed: " . $connection->connect_error);
    }

    $function = empty($_POST['subButton']) ? '' : $_POST['subButton'];

    if($function == "deleteBank"){
        echo "For times' sake, not completed";
    }
    
    if($function == "deleteDonationSite"){
        echo "For times' sake, not completed";
    }

    if($function == "deleteDonor"){
        echo "For times' sake, not completed";
    }

    if($function == "deletePatient"){
        $patientID = empty($_POST['patientID']) ? '' : $_POST['patientID'];
        
        $sql = "DELETE FROM `deliversblood` WHERE PersonID=$patientID
                 DELETE FROM `patient` WHERE PersonID = $patientID 
                 DELETE FROM `person` WHERE PersonID = $patientID";
        
        if($connection->query($sql) === TRUE){
            echo "Deletion successful!";
        }
        else {
            echo "Error: " . $sql . "<br>" . $connection->error;
        }
    }

    $connection->close();

?>