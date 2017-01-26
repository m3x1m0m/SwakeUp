EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:coolLib
LIBS:power-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
Title "Test Points"
Date "2016-12-02"
Rev "1.0"
Comp "Uppsala University"
Comment1 "Project: Swakeup"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L TEST_1P W8
U 1 1 584302F8
P 6400 3650
F 0 "W8" H 6400 3920 50  0000 C CNN
F 1 "TEST_1P" H 6400 3850 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 6600 3650 50  0001 C CNN
F 3 "" H 6600 3650 50  0000 C CNN
	1    6400 3650
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W9
U 1 1 584302FF
P 6400 4000
F 0 "W9" H 6400 4270 50  0000 C CNN
F 1 "TEST_1P" H 6400 4200 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 6600 4000 50  0001 C CNN
F 3 "" H 6600 4000 50  0000 C CNN
	1    6400 4000
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W7
U 1 1 58430306
P 6400 3300
F 0 "W7" H 6400 3570 50  0000 C CNN
F 1 "TEST_1P" H 6400 3500 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 6600 3300 50  0001 C CNN
F 3 "" H 6600 3300 50  0000 C CNN
	1    6400 3300
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W6
U 1 1 5843030D
P 6400 2950
F 0 "W6" H 6400 3220 50  0000 C CNN
F 1 "TEST_1P" H 6400 3150 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 6600 2950 50  0001 C CNN
F 3 "" H 6600 2950 50  0000 C CNN
	1    6400 2950
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W3
U 1 1 58430314
P 5100 3650
F 0 "W3" H 5100 3920 50  0000 C CNN
F 1 "TEST_1P" H 5100 3850 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 5300 3650 50  0001 C CNN
F 3 "" H 5300 3650 50  0000 C CNN
	1    5100 3650
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W4
U 1 1 5843031B
P 5100 4000
F 0 "W4" H 5100 4270 50  0000 C CNN
F 1 "TEST_1P" H 5100 4200 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 5300 4000 50  0001 C CNN
F 3 "" H 5300 4000 50  0000 C CNN
	1    5100 4000
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W2
U 1 1 58430322
P 5100 3300
F 0 "W2" H 5100 3570 50  0000 C CNN
F 1 "TEST_1P" H 5100 3500 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 5300 3300 50  0001 C CNN
F 3 "" H 5300 3300 50  0000 C CNN
	1    5100 3300
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W1
U 1 1 58430329
P 5100 2950
F 0 "W1" H 5100 3220 50  0000 C CNN
F 1 "TEST_1P" H 5100 3150 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 5300 2950 50  0001 C CNN
F 3 "" H 5300 2950 50  0000 C CNN
	1    5100 2950
	0    -1   -1   0   
$EndComp
Text Notes 5200 4350 2    60   ~ 0
Test Points for the FBs.\nCan be left out in a later version!
Text Notes 7200 4350 2    60   ~ 0
Test Points for the PWM signals.\nCan be left out in a later version!
$Comp
L TEST_1P W5
U 1 1 5843033A
P 5775 3500
F 0 "W5" H 5775 3770 50  0000 C CNN
F 1 "TEST_1P" H 5775 3700 50  0000 C CNN
F 2 "Additional:GND_PROBE" H 5975 3500 50  0001 C CNN
F 3 "" H 5975 3500 50  0000 C CNN
	1    5775 3500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR1
U 1 1 58430341
P 5775 3500
F 0 "#PWR1" H 5775 3250 50  0001 C CNN
F 1 "GND" H 5775 3350 50  0000 C CNN
F 2 "" H 5775 3500 50  0000 C CNN
F 3 "" H 5775 3500 50  0000 C CNN
	1    5775 3500
	1    0    0    -1  
$EndComp
Text HLabel 5100 2950 2    60   Input ~ 0
ADC_OLED
Text HLabel 5100 3300 2    60   Input ~ 0
ADC_R
Text HLabel 5100 4000 2    60   Input ~ 0
ADC_B
Text HLabel 5100 3650 2    60   Input ~ 0
ADC_G
Text HLabel 6400 2950 2    60   Input ~ 0
PWM_OLED
Text HLabel 6400 3300 2    60   Input ~ 0
PWM_R
Text HLabel 6400 4000 2    60   Input ~ 0
PWM_B
Text HLabel 6400 3650 2    60   Input ~ 0
PWM_G
$Comp
L TEST_1P W10
U 1 1 58476E23
P 7200 3450
F 0 "W10" H 7200 3720 50  0000 C CNN
F 1 "TEST_1P" H 7200 3650 50  0000 C CNN
F 2 "Additional:GND_PROBE" H 7400 3450 50  0001 C CNN
F 3 "" H 7400 3450 50  0000 C CNN
	1    7200 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 58476E29
P 7200 3450
F 0 "#PWR2" H 7200 3200 50  0001 C CNN
F 1 "GND" H 7200 3300 50  0000 C CNN
F 2 "" H 7200 3450 50  0000 C CNN
F 3 "" H 7200 3450 50  0000 C CNN
	1    7200 3450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
