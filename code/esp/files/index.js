function post_console(event) {
	event.preventDefault(); 
	var formData = {
		'console_in'					:	document.getElementById('console_in').value
	};
	console.log(JSON.stringify(formData));
	document.getElementById('console_in').value = "";
	$.ajax({
        type        : 'POST',
        url         : '/console',
        contentType	: 'application/json; charset=utf-8',
        data        : JSON.stringify(formData),
        dataType	: 'json'
    })
}

$( document ).ready(function() {
	(function worker() {
		$.getJSON('/state', function(data) {
			document.getElementById('weather').textContent = data.weather;
			document.getElementById('city').textContent = data.city;
			document.getElementById('time').textContent = data.time;
			console.log(data);
			setTimeout(worker, 5000);
		});
	})();
	
	document.getElementById('form_console').addEventListener('submit', post_console);
});
 
