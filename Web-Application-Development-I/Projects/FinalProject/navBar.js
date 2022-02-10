$(document).ready(function(){
    var container = document.createElement("div");
    container.setAttribute("id", "navBar");
    container.setAttribute("class", "clear");
    document.body.appendChild(container);
    $("#navBar").html("<a href='index.html' class='publicPages' id='homePage'>Home Page</a> <span id='logInStatus'> <a href='login_form.php' class='publicPages' id='logInPage'>Log In</a> <img id='unknownUserIcon' src='UnknownUser.jpg' alt='UnknownUser'> </span>");
});

function addCurrent(tabId){
    document.getElementById("homePage").classList.remove("current");
    document.getElementById("logInPage").classList.remove("current");
    document.getElementById(tabId).classList.add("current");
}
