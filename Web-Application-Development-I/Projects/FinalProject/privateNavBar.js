$(document).ready(function(){
    var container = document.createElement("div");
    container.setAttribute("id", "navBar");
    container.setAttribute("class", "clear");
    document.body.appendChild(container);
    $("#navBar").html("<a href='teamInfo.php' class='privatePages' id='teamInfo'>Team Info</a> <a href='nfcCreation.php' class='privatePages' id='nfcCreation'>Creation</a> <a href='currentRecords.php' class='privatePages' id='currentRecords'>Current Records</a> <a href='survey_form.php' class='privatePages' id='survey'>Survey</a> <span id='logInStatus'> <a href='logout.php' class='publicPages' id='logOut'>Log Out</a> <img id='knownUserIcon' src='KnownUser.jpg' alt='KnownUser'> </span>");
});

function addCurrent(tabId){
    document.getElementById("teamInfo").classList.remove("current");
    document.getElementById("nfcCreation").classList.remove("current");
    document.getElementById("currentRecords").classList.remove("current");
    document.getElementById("survey").classList.remove("current");
    document.getElementById(tabId).classList.add("current");
    if(tabId=="teamInfo"){
        getTeams();
    }
}

function getTeams() {
    var xmlHttp = new XMLHttpRequest();
		
    xmlHttp.onload = function() {
        if (xmlHttp.status == 200) {
            var xmlDoc = xmlHttp.responseXML;		
            teamNames = xmlDoc.getElementsByTagName('name');
            teamCities = xmlDoc.getElementsByTagName('city');
            teamDivisions = xmlDoc.getElementsByTagName('division');
            teamYears = xmlDoc.getElementsByTagName('year');
            teamStadiums = xmlDoc.getElementsByTagName('stadium');
            teamSuperBowls = xmlDoc.getElementsByTagName('superbowls');
            teamCoaches = xmlDoc.getElementsByTagName('coach');
            teamGMs = xmlDoc.getElementsByTagName('gm');
            teamOwners = xmlDoc.getElementsByTagName('owner');
            for(i = 0; i < teamNames.length; i++){
            $("tbody").append("<tr><td>" + teamNames[i].childNodes[0].nodeValue + "</td><td>" + teamCities[i].childNodes[0].nodeValue + "</td><td>" + teamDivisions[i].childNodes[0].nodeValue + "</td><td>" + teamYears[i].childNodes[0].nodeValue + "</td><td>" + teamStadiums[i].childNodes[0].nodeValue + "</td><td>" + teamSuperBowls[i].childNodes[0].nodeValue + "</td><td>" + teamCoaches[i].childNodes[0].nodeValue + "</td><td>" + teamGMs[i].childNodes[0].nodeValue + "</td><td>" + teamOwners[i].childNodes[0].nodeValue + "</td></tr>");
            }
        }
    }
    xmlHttp.open("GET", "teams.xml", true);
    xmlHttp.send();
}



