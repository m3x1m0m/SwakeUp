$( document ).ready(function() {
	(function worker() {
		$.getJSON('/state', function(data) {
			document.getElementById('counter').textContent = data.counter;
			document.getElementById('weather').textContent = data.weather;
			document.getElementById('city').textContent = data.city;
			document.getElementById('time').textContent = data.time;
			console.log(data);
			setTimeout(worker, 5000);
		});
	})();
});
 
