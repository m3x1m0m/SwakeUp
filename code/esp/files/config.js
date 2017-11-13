function get_config() {
	$.getJSON('/config.json',
			function(data) {
				console.log(data);
				$.each(data, function(key, value){
					console.log("Key: " + key + " Value: " + value);
					document.getElementById(key).value = value;
					if (data.StaEnable == 1) {
						document.getElementById('StaEnable').checked = true;
					} else
						document.getElementById('StaEnable').checked = false;
					});
            });
}

function post_citycfg(event) {
	event.preventDefault();
	var formData = {
			'StaCITY'					:	document.getElementById('StaCITY').value,
			'StaUNIT'					:	(document.getElementById('radioCelsius').checked ? "Celsius" : document.getElementById('radioKelvin').checked ? "Kelvin" : "Fahrenheit")
			};
			radioCelsius
			console.log(document.getElementById('radioCelsius').checked);
	console.log(JSON.stringify(formData));
	$.ajax({
        type        : 'POST',
        url         : '/',
        contentType	: 'application/json; charset=utf-8',
        data        : JSON.stringify(formData),
        dataType	: 'json'
    })
}


function post_netcfg(event) {
	event.preventDefault();
	var formData = {
			'StaSSID'					:	document.getElementById('StaSSID').value,
			'StaPassword'				:	document.getElementById('StaPassword').value,
			'StaEnable'					:	(document.getElementById('StaEnable').checked ? 1 : 0)
			};
	$.ajax({
        type        : 'POST',
        url         : '/config',
        contentType	: 'application/json; charset=utf-8',
        data        : JSON.stringify(formData),
        dataType	: 'json'
    })
}

function post_alarm(event) {
	event.preventDefault();
	var formData = {
			'StaAlarmTime'				:	document.getElementById('alarm_time').value,
			'StaAlarmMon'				:	(document.getElementById('checkMon').checked ? 1 : 0),
			'StaAlarmTue'				:	(document.getElementById('checkTue').checked ? 1 : 0),
			'StaAlarmWed'				:	(document.getElementById('checkWed').checked ? 1 : 0),
			'StaAlarmThu'				:	(document.getElementById('checkThu').checked ? 1 : 0),
			'StaAlarmFri'				:	(document.getElementById('checkFri').checked ? 1 : 0),
			'StaAlarmSat'				:	(document.getElementById('checkSat').checked ? 1 : 0),
			'StaAlarmSun'				:	(document.getElementById('checkSun').checked ? 1 : 0)
			};
	console.log(JSON.stringify(formData));
	$.ajax({
        type        : 'POST',
        url         : '/alarm',
        contentType	: 'application/json; charset=utf-8',
        data        : JSON.stringify(formData),
        dataType	: 'json'
    })
}


$( document ).ready(function() {
	get_config();
	document.getElementById('form_citycfg').addEventListener('submit', post_citycfg);
	document.getElementById('form_netcfg').addEventListener('submit', post_netcfg);
	document.getElementById('form_addalarm').addEventListener('submit', post_alarm);
	
	// document.getElementById('netcfg_cancel').addEventListener('click', get_config);
});