function selectFxn(menu) {
    /* Method for selecting menu item retrieved from:
    https://www.aspsnippets.com/Articles/Get-selected-Text-and-Value-of-DropDownList-in-OnChange-event-using-JavaScript-and-jQuery.aspx#:~:text=The%20HTML%20Select%20DropDownList%20has%20been%20assigned%20a%20jQuery%20OnChange,in%20JavaScript%20alert%20message%20box. */
    var fxn = menu.options[menu.selectedIndex].innerHTML;
    /* end of reference code */
    loadForm(fxn);
}
function loadForm(fxn)
{
    $(".form").remove();
    var form = document.createElement("div");
    form.setAttribute("class", "form");
    document.getElementById("wrapper").appendChild(form);
    if(fxn === "Name") {
        $(".form").html("<form action='RconzcChallenge8.php' method='GET'>Name Function:<br><input type='text' name='firstName' placeholder='First Name' maxlength='20' value='' class='textBox' id='text1'><input type='text' name='lastName' placeholder='Last Name' maxlength='20' value='' class='textBox' id='text2'><br><button type='submit' value='submit' class='button' id='sub' onclick='checkInput(0)'>Submit</button><button type='button' value='clear' class='button' id='del' onclick='clearFxn()'>Clear</button></form>");
    }
    else if(fxn === "Hamming Number") {
        $(".form").html("<form action='RconzcChallenge8.php' method='GET'>Hamming Number Function:<br><input type='text' name='hamNum' placeholder='Provide a Number' maxlength='20' value='' class='textBox' id='text1'><br><button type='submit' value='submit' class='button' id='sub' onclick='checkInput(1)'>Submit</button><button type='button' value='clear' class='button' id='del' onclick='clearFxn()'>Clear</button></form>");
    }
    else if(fxn === "Password Simulation") {
        $(".form").html("<form action='RconzcChallenge8.php' method='POST'>Sign-In Simulation:<br><input type='text' name='username' placeholder='Username' maxlength='20' value='' class='textBox' id='text1'><input type='password' name='password' placeholder='Password' maxlength='20' value='' class='textBox' id='text2'><br><button type='submit' value='submit' class='button' id='sub' onclick='checkInput(0)'>Submit</button><button type='button' value='clear' class='button' id='del' onclick='clearFxn()'>Clear</button></form>");
    }
    else if(fxn === "List Creator") {
        $(".form").html("<form action='RconzcChallenge8.php' method='GET'>List Creator:<br><input type='text' name='firstValue' placeholder='First singular value' maxlength='1' value='' class='textBox' id='text1'><input type='text' name='lastValue' placeholder='Second singular value' maxlength='1' value='' class='textBox' id='text2'><br><button type='submit' value='submit' class='button' id='sub' onclick='checkInput(0)'>Submit</button><button type='button' value='clear' class='button' id='del' onclick='clearFxn()'>Clear</button></form>");
    }
    else if(fxn === "Cylinder Surface Area") {
        $(".form").html("<form action='RconzcChallenge8.php' method='GET'>Cylinder Surface Area:<br><input type='text' name='radius' placeholder='Enter Radius' maxlength='20' value='' class='textBox' id='text1'><input type='text' name='height' placeholder='Enter Height' maxlength='20' value='' class='textBox' id='text2'><br><button type='submit' value='submit' class='button' id='sub' onclick='checkInput(2)'>Submit</button><button type='button' value='clear' class='button' id='del' onclick='clearFxn()'>Clear</button></form>");
    }
    else {
        alert("Error: A proper form type was not selected");
    }
    $(".form").css({"position": "relative", "width": "70%", "height": "10em", "margin": "1em auto auto auto", "background-color": "white", "color": "black", "font-family": "cursive, serif", "font-size": ".8em"});
    $(".textBox").css({"position": "relativie", "margin": "3em", "border": "1px solid black"});
    $(".button").css({"margin": "2em"});
    $("#sub").css({"color": "blue", "border": "1px solid blue", "background-color": "white", "margin-right": "8em"});
    $("#del").css({"color": "red", "border": "1px solid red", "background-color": "white", "margin-left": "8em"});
}
function clearFxn(){
    $(".textBox").val("");
}
function checkInput(fxnType){
    var t1 = $("#text1").val();
    if(fxnType == 0){
        var t2 = $("#text2").val();
        if(t1 == "" || t2 == ""){
            alert("Error: Input is missing");
            $("#text1").val("D");
            $("#text2").val("T");
        }
    }
    else if(fxnType == 1){
        /* isNumeric function retrieved from:
            https://www.tutorialrepublic.com/faq/how-to-check-whether-a-value-is-numeric-or-not-in-jquery.php#:~:text=Answer%3A%20Use%20the%20jQuery.,numbers%2C%20otherwise%20it%20returns%20false%20.*/
        if($.isNumeric(t1) == false || t1 < 1){
            // end of reference code
            alert("Error: Input is not a number greater than or equal to 1");
            $("#text1").val("1");
        }
    }
    else if(fxnType == 2){
        var t2 = $("#text2").val();
        if($.isNumeric(t1) == false || $.isNumeric(t2) == false){
            alert("Error: Input is not a number");
            $("#text1").val("0");
            $("#text2").val("0");
        }
    }
}