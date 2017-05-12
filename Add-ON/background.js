chrome.runtime.onMessage.addListener(function(response, sender, sendResponse){
	console.log("found that");
	alert (response);
	var data=response;
   //var url = "http://codefundof9.esy.es/cs299/nb2/get_text.php";//your url to the server side file that will receive the data.
	 var url = "http://home.iitj.ac.in/~sah.1/CS299/nb2/get_text.php";//your url to the server side file that will receive the data.
   var http = new XMLHttpRequest();
   http.open("POST", url, true);
   var params="data="+data;
   //Send the proper header information along with the request
   http.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
   // http.setRequestHeader("Content-length", params.length);
   // http.setRequestHeader("Connection", "close");

   http.onreadystatechange = function() {//Call a function when the state changes.
       if(http.readyState == 4 && http.status == 200) {
           alert(http.responseText);//check if the data was received successfully.
       }
   }
   http.send(params);
   alert("Package sent");
})