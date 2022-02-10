var photoArray = [];
var cameraOptions = [];
var link = "https://api.nasa.gov/mars-photos/api/v1/manifests/curiosity";
var api_key = "FRLLbTvAHEVYTFvfiQcCkkNNtGYo6LLGG9ilZIBA";
var slideIndex = 1;

function getManifest() {
    var manifestLink = link + "?api_key=" + api_key;
    $.getJSON(manifestLink, function(data){
        for(var i = 0; i < data.photo_manifest.photos.length; i++) {
            photoArray[i] = data.photo_manifest.photos[i];
        }
    });
    getRoverInfo();
}


function getRoverInfo() {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.onload = function() {
        if(xmlHttp.status == 200) {
            var xmlDoc = xmlHttp.responseXML;
            var names = xmlDoc.getElementsByTagName("name");
            var launchDate = xmlDoc.getElementsByTagName("launch_date");
            var description = xmlDoc.getElementsByTagName("description");
            for(var i = 0; i < names.length; i++) {
                var output = "<div class='rover' id='" + names[i].childNodes[0].nodeValue + "'><p>Name: " + names[i].childNodes[0].nodeValue + "</p><p>Launch Date: " + launchDate[i].childNodes[0].nodeValue + "</p><p>Description: " + description[i].childNodes[0].nodeValue + "</p><br></div>";
                $("#roverInfo").append(output);
            }
        }
    };
    xmlHttp.open("GET", "https://www.professorwergeles.com/webService.php?content=data&format=xml", true);
    xmlHttp.send();
}

function checkSol() {
    $(".selection").remove();
    var solExists = 0;
    for(var i = 0; i < cameraOptions.length; i++) {
        cameraOptions[i] = "";
    }
    for(var i = 0; i < photoArray.length; i++) {
        if($("#martianSol").val() == photoArray[i].sol) {
            for(var j = 0; j < photoArray[i].cameras.length; j++){
                cameraOptions[j] = photoArray[i].cameras[j];
            }
            solExists = 1;
            break;
        }
    }
    if(solExists == 0) {
        alert("No photos available for the selected Martian Sol. Please select a different Sol");
    }
    else {
        var fhaz = 0;
        var rhaz = 0;
        var mast = 0;
        var chemcam = 0;
        var mahli = 0;
        var mardi = 0;
        var navcam = 0;
        for(var i = 0; i < cameraOptions.length; i++) {
            switch(cameraOptions[i]) {
                case "FHAZ":
                    if(fhaz == 0) {
                        $("#camera").append("<option value='FHAZ' class='selection'>Front Hazard Avoidance Camera</option>");
                        fhaz = 1;
                    }
                    break;
                case "RHAZ":
                    if(rhaz == 0) {
                        $("#camera").append("<option value='RHAZ' class='selection'>Rear Hazard Avoidance Camera</option>");
                        rhaz = 1;
                    }
                    break;
                case "MAST":
                    if(mast == 0){
                        $("#camera").append("<option value='MAST' class='selection'>Mast Camera</option>");
                        mast = 1;
                    }
                    break;
                case "CHEMCAM":
                    if(chemcam == 0) {
                        $("#camera").append("<option value='CHEMCAM' class='selection'>Chemistry and Camera Complex</option>");
                        chemcam = 1;
                    }
                    break;
                case "MAHLI":
                    if(mahli == 0) {
                        $("#camera").append("<option value='MAHLI' class='selection'>Mars Hand Lens Imager</option>");
                        mahli = 1;
                    }
                    break;
                case "MARDI":
                    if(mardi == 0) {
                        $("#camera").append("<option value='MARDI' class='selection'>Mars Descent Imager</option>");
                        mardi = 1;
                    }
                    break;
                case "NAVCAM":
                    if(navcam == 0) {
                        $("#camera").append("<option value='NAVCAM' class='selection'>Navigation Camera</option>");
                        navcam = 1;
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

function getPictures() {
    var options = {
      "sol": $("#martianSol").val(),
      "api_key": api_key
    };
    $("img").remove(".pictures");
    displayLoad(1);
    $.get("https://api.nasa.gov/mars-photos/api/v1/rovers/curiosity/photos", options, function(data){
       var pictureList = data.photos;
       for(var i = 0; i < pictureList.length; i++) {
           if(pictureList[i].camera.name == $("#camera").val()) {
               var marsImage = "<img class='pictures' style='display:none' src='" + pictureList[i].img_src + "'/>";
               $("#picDisplay").append(marsImage);
           }
       }
       showSlides(slideIndex);
    });
}

/* reference code retrieved from: 
   https://www.w3schools.com/howto/howto_js_slideshow_gallery.asp */

function plusSlides(n) {
    showSlides(slideIndex += n);
}

function showSlides(n) {
    var i;
    var slides = document.getElementsByClassName("pictures");
    if (n > slides.length) {
        slideIndex = 1;
    }
    if (n < 1) {
        slideIndex = slides.length;
    }
    for(var i=0; i < slides.length; i++)
    {
        slides[i].style.display="none";
    }
    displayLoad(0);
    slides[slideIndex-1].style.display = "block";
    slides[slideIndex-1].style.position = "relative";
    slides[slideIndex-1].style.maxWidth = "100%";
    slides[slideIndex-1].style.maxHeight = "100%";
    slides[slideIndex-1].style.margin = "auto";
}
/* end of reference code */
/* loading icon heavily influenced by:
   loadingFeedback.html from the ajax-basics folder of Lecture 20*/
var tick = 1;
setInterval(function(){
    var loadCircles = document.querySelectorAll(".loadCircle");
    if(tick==1) {
            backgroundColors = ["navy", "lightgoldenrodyellow", "navy", "navy"];
        tick = 2;
    }
    else if(tick==2) {
        backgroundColors = ["navy", "navy", "lightgoldenrodyellow", "navy"];
        tick = 3;
    }
    else if(tick==3) {
        backgroundColors = ["navy", "navy", "navy", "lightgoldenrodyellow"];
        tick = 4;
    }
    else {
        backgroundColors = ["lightgoldenrodyellow", "navy", "navy", "navy"];
        tick = 1;
    }
    loadCircles[0].style.backgroundColor = backgroundColors[0];
    loadCircles[1].style.backgroundColor = backgroundColors[1];
    loadCircles[2].style.backgroundColor = backgroundColors[2];
    loadCircles[3].style.backgroundColor = backgroundColors[3];
}, 100);
/* end of reference code */
function displayLoad(n) {
    if(n==1) {
        $("#loadingIcon").css("display", "inline-block");
    }
    else {
        $("#loadingIcon").css("display", "none");
    }
}