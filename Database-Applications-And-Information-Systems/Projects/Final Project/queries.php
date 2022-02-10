<?php
    require_once 'db.conf';

    $connection = new mysqli($dbhost, $dbuser, $dbpass, $dbname);

    if($connection->connect_error){
        die("Connection failed: " . $connection->connect_error);
    }

    $function = empty($_POST['subButton']) ? '' : $_POST['subButton'];
        
    if($function == "mostDonated"){
        $sql = "SELECT TotalDonations,person.FirstName,person.MiddleName,person.LastName FROM (SELECT Counted.PersonID,MAX(Donations) as 'TotalDonations' FROM (SELECT Count(*) as 'Donations',PersonID FROM donateat GROUP BY PersonID ORDER BY COUNT(*) DESC) AS Counted) AS NEW JOIN person where NEW.PersonID = person.PERSONID";
        
        if($result = $mysqli->query($sql)){
            echo "Most Donations: " . $result;
            $result->free_result();
        }
        else {
            echo "Error querying the Most Donations";
        }
    }
    
    if($function == "displayReminder"){
        echo "For times' sake, not completed";
    }

    if($function == "totalDonors"){
        echo "For times' sake, not completed";
    }

    if($function == "averageDonors"){
        $sql = "SELECT AVG(Donations) as 'Average Donations' FROM (SELECT COUNT(*) as 'Donations' FROM Donateat as R1 GROUP BY PersonID ORDER BY COUNT(*) DESC) as sums";
        
        if($result = $mysqli->query($sql)){
            echo "Average Donations Per Donor: " . $result;
            $result->free_result();
        }
        else {
            echo "Error querying the Average Donations Per Donor";
        }
    }

    if($function == "tracking"){
        $personID = empty($_POST['personID']) ? '' : $_POST['personID'];
        
        $sql = "SELECT TrackingNumber FROM `deliversblood` WHERE PersonID = $personID";
        
        if($result = $mysqli->query($sql)){
            echo "Tracking Number: " . $result;
            $result->free_result();
        }
        else {
            echo "Error querying the Tracking Number";
        }
    }

    if($function == "mostRecent"){
        echo "For times' sake, not completed";
    }

    if($function == "possibleDonors"){
        echo "For times' sake, not completed";
    }

    if($function == "possibleRecipients"){
        echo "For times' sake, not completed";
    }

    if($function == "findContact"){
        echo "For times' sake, not completed";
    }

    if($function == "findActiveSites"){
        $sql = "SELECT * FROM `donationsite` WHERE StartDate < CURRENT_DATE && EndDate > CURRENT_DATE";
        
        if($result = $mysqli->query($sql)){
            echo "Active Donation Sites: " . $result;
            $result->free_result();
        }
        else {
            echo "Error querying the Active Donation Sites";
        }
    }

    if($function == "displayDonors"){
        $state = empty($_POST['state']) ? '' : $_POST['state'];
        
        $sql = "SELECT * FROM `donor` where State = $state";
        
        if($result = $mysqli->query($sql)){
            echo "Donors From " . $state . ": " . $result;
            $result->free_result();
        }
        else {
            echo "Error querying the Donors From " . $state;
        }
    }

    $connection->close();

?>