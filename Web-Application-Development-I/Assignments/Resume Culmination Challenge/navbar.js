$(document).ready(function(){
    var container = document.createElement("div");
    container.setAttribute("id", "navbar");
    container.setAttribute("class", "clear");
    document.body.appendChild(container);
    $("#navbar").html("<a href='RconzcWebServersF20.html' class='name' id='portfolio'>Ryan Orf</a> <a href='RconzcColumnsF20.html' class='name' id='skills'>Skills</a> <a href='RconzcTablesF20.html' class='name' id='tables'>Classes Taken</a> <a href='RconzcProjectsF20.html' class='name' id='projects'>Projects</a>");
});

function addCurrent(tabId){
    document.getElementById("portfolio").classList.remove("current");
    document.getElementById("skills").classList.remove("current");
    document.getElementById("tables").classList.remove("current");
    document.getElementById("projects").classList.remove("current");
    document.getElementById(tabId).classList.add("current");
}