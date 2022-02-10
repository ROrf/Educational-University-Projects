<?php
    require_once 'db.conf';

    $connection = new mysqli($dbhost, $dbuser, $dbpass, $dbname);

    if($connection->connect_error){
        die("Connection failed: " . $connection->connect_error);
    }

    $function = empty($_POST['subButton']) ? '' : $_POST['subButton'];

    if($function == "insertBank"){
        echo "For times' sake, not completed";
    }
    
    if($function == "insertDonationSite"){
        echo "For times' sake, not completed";
    }

    if($function == "insertDonor"){
        $donorFName = empty($_POST['donorFName']) ? '' : $_POST['donorFName'];
        $donorMName = empty($_POST['donorMName']) ? '' : $_POST['donorMName'];
        $donorLName = empty($_POST['donorLName']) ? '' : $_POST['donorLName'];
        $donorID = empty($_POST['donorID']) ? '' : $_POST['donorID'];
        $bloodGroup = empty($_POST['bloodGroup']) ? '' : $_POST['bloodGroup'];
        $medicalData = empty($_POST['medicalData']) ? '' : $_POST['medicalData'];
        $donorPhone = empty($_POST['donorPhone']) ? '' : $_POST['donorPhone'];
        $donorAddress = empty($_POST['donorAddress']) ? '' : $_POST['donorAddress'];
        $donorCity = empty($_POST['donorCity']) ? '' : $_POST['donorCity'];
        $donorState = empty($_POST['donorState']) ? '' : $_POST['donorState'];
        $donorZipcode = empty($_POST['donorZipcode']) ? '' : $_POST['donorZipcode'];
        $donationDate = empty($_POST['donationDate']) ? '' : $_POST['donationDate'];
        $siteID = empty($_POST['siteID']) ? '' : $_POST['siteID'];
        $emergencyName = empty($_POST['emergencyName']) ? '' : $_POST['emergencyName'];
        $emergencyNumber = empty($_POST['emergencyNumber']) ? '' : $_POST['emergencyNumber'];
        $relation = empty($_POST['relation']) ? '' : $_POST['relation'];
        $emergencyAddress = empty($_POST['emergencyAddress']) ? '' : $_POST['emergencyAddress'];
        $emergencyCity = empty($_POST['emergencyCity']) ? '' : $_POST['emergencyCity'];
        $emergencyState = empty($_POST['emergencyState']) ? '' : $_POST['emergencyState'];
        $emergencyZipcode = empty($_POST['emergencyZipcode']) ? '' : $_POST['emergencyZipcode'];
        
        $sql = "INSERT INTO `person`(`FirstName`, `MiddleName`, `LastName`, `BloodGroup`, `MedicalData`) 
                 VALUES ($donorFName,$donorMName,$donorLName,$bloodGroup,$medicalData);
 
                 INSERT INTO `donor`(`PersonID`, `DonorPhoneNo`, `StreetAddress`, `City`, `State`, `Zipcode`)
                 VALUES ($donorID,$donorPhone,$donorAddress,$donorCity,$donorState,$donorZipcode);
 
                 INSERT INTO `emergency contact`(`PersonID`, `ContactName`, `ContactPhoneNo`, `Relationship`, `StreetAddress`, `City`, `State`, `Zipcode`)
                 VALUES ($donorID,$emergencyName,$emergencyNumber,$relation,$emergencyAddress,$emergencyCity,$emergencyState,$emergencyZipcode)

                 SELECT SiteID,LocationName,LocationAddress FROM `donationsite` 
 
                 INSERT INTO `donateat`(`PersonID`, `SiteID`, `DonationDate`) VALUES ($donorID,$siteID,$donationDate)";
        
        if($connection->query($sql) === TRUE){
            echo "Insertion successful!";
        }
        else {
            echo "Error: " . $sql . "<br>" . $connection->error;
        }
    }

    if($function == "insertPatient"){
        echo "For times' sake, not completed";
    }

    $connection->close();

?>