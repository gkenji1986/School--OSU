var apikey = '2de143494c0b295cca9337e1e96b00e0';
document.addEventListener('DOMContentLoaded', bindButtons);

function bindButtons()
{
	document.getElementById('textSubmit').addEventListener('click', function(event){
	var req = new XMLHttpRequest();
	var payload = {textInput:null};
    payload.textInput = document.getElementById('textInput').value;
	if(isString(payload.textInput) === false)
	{
		req.open('GET', 'http://api.openweathermap.org/data/2.5/weather?zip=' + payload.textInput + ',us&appid=' + apikey, false);
	}
	else
	{
		req.open('GET', 'http://api.openweathermap.org/data/2.5/weather?q=' + payload.textInput + '&appid=' + apikey, false);
	}
	req.send(null);
	console.log(JSON.parse(req.responseText));
	var response = JSON.parse(req.responseText);
	document.getElementById('lat').textContent = response.coord.lat;
	document.getElementById('lon').textContent = response.coord.lon;
	document.getElementById('descrip').textContent = response.weather[0].description;
	document.getElementById('temp').textContent = response.main.temp;
	document.getElementById('humid').textContent = response.main.humidity;
	document.getElementById('name').textContent = response.name;
	document.getElementById('tempMax').textContent = response.main.temp_max;
	document.getElementById('tempMin').textContent = response.main.temp_min;
	document.getElementById('sea').textContent = response.main.sea_level;
	document.getElementById('pressure').textContent = response.main.pressure;
	document.getElementById('windDeg').textContent = response.wind.deg;
	document.getElementById('windSpeed').textContent = response.wind.speed;

	
    event.preventDefault();

	})
}
function isString(inputString)
{
	if(isNaN(inputString) === false)
	{
		return false;
	}
	else
	{
		return true;
	}
}