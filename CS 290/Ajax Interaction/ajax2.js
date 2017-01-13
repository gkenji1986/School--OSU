document.addEventListener('DOMContentLoaded', bindButtons);
	
function bindButtons()
{
	document.getElementById('textSubmit').addEventListener('click', function(event){
	var req = new XMLHttpRequest();
	var payload = {textInput:null};
    payload.textInput = document.getElementById('textInput').value;
	req.open('POST', 'http://httpbin.org/post', true);
	req.setRequestHeader('Content-Type', 'application/json');
	req.addEventListener('load', function(){
		if(req.status >= 200 && req.status < 400)
		{
			var response = JSON.parse(req.responseText);
			document.getElementById('data').textContent = response.data;
		}
		else
		{
			console.log("Error in network request: " + request.statusText);
		}});	
	req.send(JSON.stringify(payload));
    event.preventDefault();
	})
}