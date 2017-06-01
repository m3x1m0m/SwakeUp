%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Plot values of the PID controller controlled output. 
%
% Author:       	Maximilian Stiefel
% Lat modification:	23.05.2017
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Variables 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
freq = 100; 				% Frequency in Hz of the controller
file = "pid_100Hz.log";

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Action 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
output_vals = dlmread(file);
time = linspace(0,length(output_vals),length(output_vals));
time = time/freq;
plot(time, output_vals);
title("PID Controlled ADC Value- Setpoint: 1017, KP: 1.5, KI: 1.0, KD: 0.25");
xlabel("t/s");
ylabel("ADC Counts");
grid on;
