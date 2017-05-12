//alert(document.getElementById(':k3').innerHTML);
// var script = document.createElement('script');
// script.src = 'https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js';
// script.type = 'text/javascript';
// document.getElementsByTagName('head')[0].appendChild(script);
// $(window).bind('hashchange', function() {
// 	alert(document.URL);
// 	chrome.runtime.sendMessage(document.getElementsByClassName('ng_mail_text').innerHTML);
// });
//chrome.runtime.sendMessage(document.URL);
//document.write(document.URL);
//chrome.runtime.sendMessage(document.getElementsByClassName('ng_mail_text').innerHTML);
//chrome.runtime.sendMessage(document.getElementsByClassName('bodyDecrypted email').innerText);
//console.log(Object.keys(document));
// window.addEventListener('load', (function(){
//  if (("onhashchange" in window)) {
//          window.onhashchange = function () {
//               alert(window.location.hash);
//               //chrome.runtime.sendMessage(document.getElementsByTagName('ng_mail_text').innerHTML);
//               //chrome.runtime.sendMessage(document.getElementsByClassName('ng_mail_text')[0].textContent);
//               //alert(document.getElementsByTagName('title')[0].innerHTML);
//               console.log(document.getElementsByClassName('ng_mail_text').length);
//               console.log(Object.keys(document));
//               console.log(JSON.stringify(document));
//               console.log((document));
//               console.log(document.getElementsByClassName('ng_mail_text').item(0));
//               alert(document.getElementsByClassName('ng_mail_text')[0].textContent);
//          }
//          // Or $(window).bind( 'hashchange',function(e) {
//          //       alert(window.location.hash);
//          //   });
//     }
//     else {
//         var prevHash = window.location.hash;
//         window.setInterval(function () {
//            if (window.location.hash != prevHash) {
//               prevHash = window.location.hash;
//               alert(window.location.hash);
//            }
//         }, 10);
//     }

// }));
window.addEventListener('hashchange', (function(){
              //alert(window.location.hash);
              alert(document.URL);
              var classname=window.location.hash;
              //alert(classname);
              console.log(classname);
              var x="a3s aXjCH m";//15b44946a80f865f"
              classname=classname.slice(7);
              //alert(x+classname);
              console.log(x+classname);
              alert(document.getElementsByClassName(x+classname)[0].textContent);
              var data = document.getElementsByClassName(x+classname)[0].textContent;
              chrome.runtime.sendMessage(document.getElementsByClassName(x+classname)[0].textContent);
               
               console.log(data);
               // this is your data that you want to pass to the server (could be json)
              //next you would initiate a XMLHTTPRequest as following (could be more advanced):
          
}));