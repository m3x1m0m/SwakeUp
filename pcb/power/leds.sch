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
LIBS:myOpAmps
LIBS:myMOSFETs
LIBS:power-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
Title "LEDs "
Date "2016-12-30"
Rev "1.0"
Comp "Uppsala University"
Comment1 "Project: SwakeUp"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R19
U 1 1 58431010
P 8200 2300
F 0 "R19" V 8280 2300 50  0000 C CNN
F 1 "10k" V 8200 2300 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8130 2300 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 8200 2300 50  0001 C CNN
F 4 "2141505" V 8200 2300 60  0001 C CNN "Farnell"
	1    8200 2300
	0    1    1    0   
$EndComp
Text Notes 8850 1300 0    60   ~ 0
Non-Invert. Amp.\n-----------------------\nA=(30k + 120k)/30k =5\nVin,max=3.3 V\nVout,max=16.5
Text Notes 3425 2000 0    60   ~ 0
Differential Amp.\n-----------------------\nA=(20k+120k)/20k = 6\nVin,max=300 mV\nVout,max=1.98 V\nVref = 3.3V/1.6
$Comp
L C C8
U 1 1 58431061
P 9100 6250
F 0 "C8" H 9125 6350 50  0000 L CNN
F 1 "10u" H 9125 6150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9138 6100 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 9100 6250 50  0001 C CNN
F 4 "490-12323-1-ND" H 9100 6250 60  0001 C CNN "Digikey"
	1    9100 6250
	0    1    1    0   
$EndComp
Text Notes 6750 1200 0    60   ~ 0
Voltage divider\n-----------------------\nVin,max = 16.5 V\nVout,max = 1.5 V \nVref = (3.3V/1.6)
Text HLabel 1400 5400 0    60   Input ~ 0
V20
Text HLabel 1550 5550 0    60   Input ~ 0
PWM_R
Text HLabel 1550 5950 0    60   Input ~ 0
PWM_B
Text HLabel 1550 6300 0    60   Input ~ 0
PWM_G
Text HLabel 9875 6025 0    60   Output ~ 0
ADC_B
Text HLabel 10125 5650 2    60   Output ~ 0
ADC_G
Text HLabel 9200 2300 2    60   Input ~ 0
PWM_OLED
Text HLabel 7750 6250 2    60   Output ~ 0
ADC_OLED
Text HLabel 6575 6425 2    60   Output ~ 0
VOLED
Text HLabel 3500 4950 1    60   Output ~ 0
LED_R
Text HLabel 3600 4950 1    60   Output ~ 0
LED_B
Text HLabel 3700 4950 1    60   Output ~ 0
LED_G
Text HLabel 3800 4950 1    60   Output ~ 0
LED_GND
$Comp
L C C21
U 1 1 584CBAE2
P 9325 5600
F 0 "C21" V 9375 5650 50  0000 L CNN
F 1 "2.2u" V 9375 5350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9363 5450 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/partnumbering_e_01.pdf" H 9325 5600 50  0001 C CNN
F 4 "490-7204-1-ND" H 9325 5600 60  0001 C CNN "Digikey"
	1    9325 5600
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR021
U 1 1 584CCA77
P 10125 4825
F 0 "#PWR021" H 10125 4575 50  0001 C CNN
F 1 "GND" H 10125 4675 50  0000 C CNN
F 2 "" H 10125 4825 50  0000 C CNN
F 3 "" H 10125 4825 50  0000 C CNN
	1    10125 4825
	1    0    0    -1  
$EndComp
Text GLabel 2950 5750 2    60   Input ~ 0
OPAMP_R_P
Text GLabel 2950 5850 2    60   Input ~ 0
OPAMP_R_N
Text GLabel 2950 6200 2    60   Input ~ 0
OPAMP_B_P
Text GLabel 2950 6300 2    60   Input ~ 0
OPAMP_B_N
Text GLabel 2950 6650 2    60   Input ~ 0
OPAMP_G_P
Text GLabel 2950 6750 2    60   Input ~ 0
OPAMP_G_N
Text GLabel 10450 5900 2    60   Input ~ 0
OPAMP_G_N
Text GLabel 10200 6175 2    60   Input ~ 0
OPAMP_G_P
$Comp
L GND #PWR023
U 1 1 5867D2A9
P 8750 5925
F 0 "#PWR023" H 8750 5675 50  0001 C CNN
F 1 "GND" H 8750 5775 50  0000 C CNN
F 2 "" H 8750 5925 50  0000 C CNN
F 3 "" H 8750 5925 50  0000 C CNN
	1    8750 5925
	1    0    0    -1  
$EndComp
Text GLabel 7275 6125 0    60   Input ~ 0
OPAMP_B_N
Text GLabel 8300 5850 0    60   Input ~ 0
OPAMP_B_P
$Sheet
S 1706 5294 1144 1856
U 58430F64
F0 "LED Driver 3 Chan. " 60
F1 "rgbLedDriver.sch" 60
F2 "LED_G_P" O R 2850 6450 60 
F3 "LED_G_N" O R 2850 6550 60 
F4 "PWM_B" I L 1706 5950 60 
F5 "LED_B_P" O R 2850 6000 60 
F6 "LED_B_N" O R 2850 6100 60 
F7 "PWM_R" I L 1706 5550 60 
F8 "LED_R_P" O R 2850 5550 60 
F9 "LED_R_N" O R 2850 5650 60 
F10 "V20" I L 1706 5400 60 
F11 "PWM_G" I L 1706 6300 60 
F12 "OPAMP_G_P" O R 2850 6650 60 
F13 "OPAMP_B_P" O R 2850 6200 60 
F14 "OPAMP_R_P" O R 2850 5750 60 
F15 "OPAMP_R_N" O R 2850 5850 60 
F16 "OPAMP_G_N" O R 2850 6750 60 
F17 "OPAMP_B_N" O R 2850 6300 60 
$EndSheet
Text GLabel 4000 2850 0    60   Input ~ 0
OPAMP_R_P
Text GLabel 4000 2350 0    60   Input ~ 0
OPAMP_R_N
$Comp
L GND #PWR024
U 1 1 58689DF6
P 5350 2925
F 0 "#PWR024" H 5350 2675 50  0001 C CNN
F 1 "GND" H 5350 2775 50  0000 C CNN
F 2 "" H 5350 2925 50  0000 C CNN
F 3 "" H 5350 2925 50  0000 C CNN
	1    5350 2925
	1    0    0    -1  
$EndComp
$Comp
L LM324QT U?
U 1 1 59158B03
P 6575 2950
F 0 "U?" H 7025 2150 60  0000 C CNN
F 1 "LM324QT" H 6225 2150 60  0000 C CNN
F 2 "" H 6575 2950 60  0000 C CNN
F 3 "" H 6575 2950 60  0000 C CNN
	1    6575 2950
	1    0    0    -1  
$EndComp
Text HLabel 8100 5225 0    60   Input ~ 0
V19
$Comp
L R R?
U 1 1 59163CBB
P 8600 2300
F 0 "R?" V 8680 2300 50  0000 C CNN
F 1 "10k" V 8600 2300 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8530 2300 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 8600 2300 50  0001 C CNN
F 4 "2141505" V 8600 2300 60  0001 C CNN "Farnell"
	1    8600 2300
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 59164915
P 4275 2350
F 0 "R?" V 4355 2350 50  0000 C CNN
F 1 "20k" V 4275 2350 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4205 2350 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1716707.pdf" H 4275 2350 50  0001 C CNN
F 4 "2073421" V 4275 2350 60  0001 C CNN "Farnell"
	1    4275 2350
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 591650E7
P 4975 2350
F 0 "R?" V 5055 2350 50  0000 C CNN
F 1 "120k" V 4975 2350 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4905 2350 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 4975 2350 50  0001 C CNN
F 4 "2141505" V 4975 2350 60  0001 C CNN "Farnell"
	1    4975 2350
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 59165E13
P 8400 2550
F 0 "C?" H 8425 2650 50  0000 L CNN
F 1 "47n" H 8425 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8438 2400 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1901289.pdf" H 8400 2550 50  0001 C CNN
F 4 "1759011" H 8400 2550 60  0001 C CNN "Farnell"
	1    8400 2550
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5916688A
P 4975 2850
F 0 "R?" V 5055 2850 50  0000 C CNN
F 1 "120k" V 4975 2850 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4905 2850 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 4975 2850 50  0001 C CNN
F 4 "2141505" V 4975 2850 60  0001 C CNN "Farnell"
	1    4975 2850
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 591669D4
P 4275 2850
F 0 "R?" V 4355 2850 50  0000 C CNN
F 1 "20k" V 4275 2850 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4205 2850 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1716707.pdf" H 4275 2850 50  0001 C CNN
F 4 "2073421" V 4275 2850 60  0001 C CNN "Farnell"
	1    4275 2850
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 59167D4D
P 1800 1300
F 0 "R?" V 1880 1300 50  0000 C CNN
F 1 "47k" V 1800 1300 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 1730 1300 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 1800 1300 50  0001 C CNN
F 4 "9331255" V 1800 1300 60  0001 C CNN "Farnell"
	1    1800 1300
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 59167EAB
P 1500 1550
F 0 "C?" H 1525 1650 50  0000 L CNN
F 1 "22nF" H 1525 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1538 1400 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1901289.pdf" H 1500 1550 50  0001 C CNN
F 4 "1759027" H 1500 1550 60  0001 C CNN "Farnell"
	1    1500 1550
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 59168635
P 1500 1775
F 0 "#PWR?" H 1500 1525 50  0001 C CNN
F 1 "GND" H 1500 1625 50  0000 C CNN
F 2 "" H 1500 1775 50  0000 C CNN
F 3 "" H 1500 1775 50  0000 C CNN
	1    1500 1775
	1    0    0    -1  
$EndComp
Text Notes 825  975  0    60   ~ 0
Low-pass filter\n-----------------------\nf3dB = 153.9 Hz
Text HLabel 1150 1300 0    60   Output ~ 0
ADC_R
$Comp
L R R?
U 1 1 5916BDEA
P 1825 2225
F 0 "R?" V 1905 2225 50  0000 C CNN
F 1 "47k" V 1825 2225 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 1755 2225 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 1825 2225 50  0001 C CNN
F 4 "9331255" V 1825 2225 60  0001 C CNN "Farnell"
	1    1825 2225
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5916BDF9
P 1525 2700
F 0 "#PWR?" H 1525 2450 50  0001 C CNN
F 1 "GND" H 1525 2550 50  0000 C CNN
F 2 "" H 1525 2700 50  0000 C CNN
F 3 "" H 1525 2700 50  0000 C CNN
	1    1525 2700
	1    0    0    -1  
$EndComp
Text HLabel 1175 2225 0    60   Output ~ 0
ADC_B
$Comp
L R R?
U 1 1 5916C0E4
P 1825 3175
F 0 "R?" V 1905 3175 50  0000 C CNN
F 1 "47k" V 1825 3175 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 1755 3175 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 1825 3175 50  0001 C CNN
F 4 "9331255" V 1825 3175 60  0001 C CNN "Farnell"
	1    1825 3175
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5916C0F3
P 1525 3650
F 0 "#PWR?" H 1525 3400 50  0001 C CNN
F 1 "GND" H 1525 3500 50  0000 C CNN
F 2 "" H 1525 3650 50  0000 C CNN
F 3 "" H 1525 3650 50  0000 C CNN
	1    1525 3650
	1    0    0    -1  
$EndComp
Text HLabel 1175 3175 0    60   Output ~ 0
ADC_G
$Comp
L C C?
U 1 1 5916D604
P 1525 2475
F 0 "C?" H 1550 2575 50  0000 L CNN
F 1 "22nF" H 1550 2375 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1563 2325 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1901289.pdf" H 1525 2475 50  0001 C CNN
F 4 "1759027" H 1525 2475 60  0001 C CNN "Farnell"
	1    1525 2475
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 5916D802
P 1525 3425
F 0 "C?" H 1550 3525 50  0000 L CNN
F 1 "22nF" H 1550 3325 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1563 3275 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1901289.pdf" H 1525 3425 50  0001 C CNN
F 4 "1759027" H 1525 3425 60  0001 C CNN "Farnell"
	1    1525 3425
	-1   0    0    1   
$EndComp
Text GLabel 4000 3050 0    60   Input ~ 0
OPAMP_B_P
Text GLabel 4000 3550 0    60   Input ~ 0
OPAMP_B_N
$Comp
L R R?
U 1 1 59171CA2
P 4275 3550
F 0 "R?" V 4175 3550 50  0000 C CNN
F 1 "20k" V 4275 3550 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4205 3550 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1716707.pdf" H 4275 3550 50  0001 C CNN
F 4 "2073421" V 4275 3550 60  0001 C CNN "Farnell"
	1    4275 3550
	0    1    -1   0   
$EndComp
$Comp
L R R?
U 1 1 59171CA9
P 4975 3550
F 0 "R?" V 4875 3550 50  0000 C CNN
F 1 "120k" V 4975 3550 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4905 3550 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 4975 3550 50  0001 C CNN
F 4 "2141505" V 4975 3550 60  0001 C CNN "Farnell"
	1    4975 3550
	0    1    -1   0   
$EndComp
$Comp
L R R?
U 1 1 59171CB0
P 4975 3050
F 0 "R?" V 4875 3050 50  0000 C CNN
F 1 "120k" V 4975 3050 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4905 3050 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 4975 3050 50  0001 C CNN
F 4 "2141505" V 4975 3050 60  0001 C CNN "Farnell"
	1    4975 3050
	0    1    -1   0   
$EndComp
$Comp
L R R?
U 1 1 59171CB7
P 4275 3050
F 0 "R?" V 4175 3050 50  0000 C CNN
F 1 "20k" V 4275 3050 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4205 3050 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1716707.pdf" H 4275 3050 50  0001 C CNN
F 4 "2073421" V 4275 3050 60  0001 C CNN "Farnell"
	1    4275 3050
	0    1    -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 591734F6
P 7800 2925
F 0 "#PWR?" H 7800 2675 50  0001 C CNN
F 1 "GND" H 7800 2775 50  0000 C CNN
F 2 "" H 7800 2925 50  0000 C CNN
F 3 "" H 7800 2925 50  0000 C CNN
	1    7800 2925
	-1   0    0    -1  
$EndComp
Text GLabel 9150 3050 2    60   Input ~ 0
OPAMP_B_P
Text GLabel 9150 3550 2    60   Input ~ 0
OPAMP_B_N
$Comp
L R R?
U 1 1 59173500
P 8875 3550
F 0 "R?" V 8775 3550 50  0000 C CNN
F 1 "20k" V 8875 3550 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8805 3550 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1716707.pdf" H 8875 3550 50  0001 C CNN
F 4 "2073421" V 8875 3550 60  0001 C CNN "Farnell"
	1    8875 3550
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 59173507
P 8175 3550
F 0 "R?" V 8075 3550 50  0000 C CNN
F 1 "120k" V 8175 3550 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8105 3550 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 8175 3550 50  0001 C CNN
F 4 "2141505" V 8175 3550 60  0001 C CNN "Farnell"
	1    8175 3550
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5917350E
P 8175 3050
F 0 "R?" V 8075 3050 50  0000 C CNN
F 1 "120k" V 8175 3050 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8105 3050 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 8175 3050 50  0001 C CNN
F 4 "2141505" V 8175 3050 60  0001 C CNN "Farnell"
	1    8175 3050
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 59173515
P 8875 3050
F 0 "R?" V 8775 3050 50  0000 C CNN
F 1 "20k" V 8875 3050 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8805 3050 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1716707.pdf" H 8875 3050 50  0001 C CNN
F 4 "2073421" V 8875 3050 60  0001 C CNN "Farnell"
	1    8875 3050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8350 2300 8400 2300
Wire Wire Line
	8400 2300 8450 2300
Wire Wire Line
	8400 2850 8400 2700
Wire Wire Line
	8400 2400 8400 2300
Connection ~ 8400 2300
Wire Wire Line
	1706 5550 1550 5550
Wire Wire Line
	1706 5950 1550 5950
Wire Wire Line
	1550 6300 1706 6300
Wire Wire Line
	1706 5400 1400 5400
Wire Wire Line
	2850 6300 2950 6300
Wire Wire Line
	2850 6750 2950 6750
Wire Wire Line
	2850 5550 3500 5550
Wire Wire Line
	3500 5550 3500 4950
Wire Wire Line
	2850 5650 3800 5650
Wire Wire Line
	3800 4950 3800 5650
Wire Wire Line
	3800 5650 3800 6100
Wire Wire Line
	3800 6100 3800 6550
Wire Wire Line
	2850 6000 3600 6000
Wire Wire Line
	3600 6000 3600 4950
Wire Wire Line
	3800 6100 2850 6100
Connection ~ 3800 5650
Wire Wire Line
	2850 6450 3700 6450
Wire Wire Line
	3700 6450 3700 4950
Wire Wire Line
	3800 6550 2850 6550
Connection ~ 3800 6100
Wire Wire Line
	2850 5750 2950 5750
Wire Wire Line
	2850 5850 2950 5850
Wire Wire Line
	2850 6200 2950 6200
Wire Wire Line
	2950 6650 2850 6650
Wire Wire Line
	8750 2300 9200 2300
Wire Wire Line
	4425 2350 4625 2350
Wire Wire Line
	4625 2350 4825 2350
Connection ~ 4625 2350
Wire Wire Line
	4425 2850 4625 2850
Wire Wire Line
	4625 2850 4825 2850
Wire Wire Line
	4000 2350 4125 2350
Wire Wire Line
	4000 2850 4125 2850
Wire Wire Line
	1500 1400 1500 1300
Wire Wire Line
	1150 1300 1500 1300
Wire Wire Line
	1500 1300 1650 1300
Wire Wire Line
	1500 1700 1500 1775
Connection ~ 1500 1300
Wire Wire Line
	1950 1300 2175 1300
Wire Wire Line
	1525 2325 1525 2225
Wire Wire Line
	1175 2225 1525 2225
Wire Wire Line
	1525 2225 1675 2225
Wire Wire Line
	1525 2625 1525 2700
Connection ~ 1525 2225
Wire Wire Line
	1975 2225 2200 2225
Wire Wire Line
	1525 3275 1525 3175
Wire Wire Line
	1175 3175 1525 3175
Wire Wire Line
	1525 3175 1675 3175
Wire Wire Line
	1525 3575 1525 3650
Connection ~ 1525 3175
Wire Wire Line
	1975 3175 2200 3175
Wire Wire Line
	4625 2750 5875 2750
Wire Wire Line
	4625 2750 4625 2850
Connection ~ 4625 2850
Wire Wire Line
	4625 2550 5875 2550
Wire Wire Line
	4625 2350 4625 2550
Wire Wire Line
	5125 2350 5650 2350
Wire Wire Line
	5650 2350 5875 2350
Wire Wire Line
	5525 2150 5650 2150
Wire Wire Line
	5650 2150 5650 2350
Connection ~ 5650 2350
Wire Wire Line
	4425 3550 4625 3550
Wire Wire Line
	4625 3550 4825 3550
Connection ~ 4625 3550
Wire Wire Line
	4425 3050 4625 3050
Wire Wire Line
	4625 3050 4825 3050
Wire Wire Line
	4000 3550 4125 3550
Wire Wire Line
	4000 3050 4125 3050
Wire Wire Line
	4625 3150 5875 3150
Wire Wire Line
	4625 3150 4625 3050
Connection ~ 4625 3050
Wire Wire Line
	4625 3350 5875 3350
Wire Wire Line
	4625 3550 4625 3350
Wire Wire Line
	5125 3550 5650 3550
Wire Wire Line
	5650 3550 5875 3550
Wire Wire Line
	5525 3750 5650 3750
Wire Wire Line
	5650 3750 5650 3550
Connection ~ 5650 3550
Wire Wire Line
	5125 2850 5200 2850
Wire Wire Line
	5200 2850 5350 2850
Wire Wire Line
	5350 2850 5350 2925
Wire Wire Line
	5125 3050 5200 3050
Wire Wire Line
	5200 3050 5200 2850
Connection ~ 5200 2850
Wire Wire Line
	8325 3550 8525 3550
Wire Wire Line
	8525 3550 8725 3550
Connection ~ 8525 3550
Wire Wire Line
	8325 3050 8525 3050
Wire Wire Line
	8525 3050 8725 3050
Wire Wire Line
	9150 3550 9025 3550
Wire Wire Line
	9150 3050 9025 3050
Wire Wire Line
	8525 3150 7275 3150
Wire Wire Line
	8525 3150 8525 3050
Connection ~ 8525 3050
Wire Wire Line
	8525 3350 7275 3350
Wire Wire Line
	8525 3550 8525 3350
Wire Wire Line
	7275 3550 7500 3550
Wire Wire Line
	7500 3550 8025 3550
Wire Wire Line
	7625 3750 7500 3750
Wire Wire Line
	7500 3750 7500 3550
Connection ~ 7500 3550
Wire Wire Line
	7950 3050 8025 3050
Wire Wire Line
	7800 2925 7800 2850
Wire Wire Line
	7275 2750 7750 2750
Wire Wire Line
	7750 2750 7750 2300
Wire Wire Line
	7750 2300 7950 2300
Wire Wire Line
	7950 2300 8050 2300
Wire Wire Line
	7950 2400 7950 2300
Connection ~ 7950 2300
Text GLabel 5525 3750 0    60   Output ~ 0
OPAMP_B_OUT
Text GLabel 5525 2150 0    60   Output ~ 0
OPAMP_R_OUT
Text GLabel 2200 2225 2    60   Input ~ 0
OPAMP_B_OUT
Text GLabel 2200 3175 2    60   Input ~ 0
OPAMP_G_OUT
Text GLabel 2175 1300 2    60   Input ~ 0
OPAMP_R_OUT
Text GLabel 7625 3750 2    60   Output ~ 0
OPAMP_G_OUT
$Comp
L C C9
U 1 1 58430FDA
P 7950 2550
F 0 "C9" H 7975 2650 50  0000 L CNN
F 1 "47n" H 7975 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7988 2400 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1901289.pdf" H 7950 2550 50  0001 C CNN
F 4 "1759011" H 7950 2550 60  0001 C CNN "Farnell"
	1    7950 2550
	1    0    0    -1  
$EndComp
Connection ~ 7950 2850
Wire Wire Line
	7950 2700 7950 2850
Wire Wire Line
	7950 2850 7950 3050
$Comp
L R R?
U 1 1 5917A30B
P 7925 1950
F 0 "R?" V 8005 1950 50  0000 C CNN
F 1 "120k" V 7925 1950 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7855 1950 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 7925 1950 50  0001 C CNN
F 4 "2141505" V 7925 1950 60  0001 C CNN "Farnell"
	1    7925 1950
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 5917A759
P 8600 1950
F 0 "R?" V 8680 1950 50  0000 C CNN
F 1 "30k" V 8600 1950 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8530 1950 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 8600 1950 50  0001 C CNN
F 4 "9330984" V 8600 1950 60  0001 C CNN "Farnell"
	1    8600 1950
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5917AF3B
P 9000 2025
F 0 "#PWR?" H 9000 1775 50  0001 C CNN
F 1 "GND" H 9000 1875 50  0000 C CNN
F 2 "" H 9000 2025 50  0000 C CNN
F 3 "" H 9000 2025 50  0000 C CNN
	1    9000 2025
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7375 1950 7775 1950
Wire Wire Line
	8075 1950 8225 1950
Wire Wire Line
	8225 1950 8450 1950
Wire Wire Line
	8750 1950 9000 1950
Wire Wire Line
	9000 1950 9000 2025
Wire Wire Line
	8225 1950 8225 2175
Wire Wire Line
	8225 2175 7525 2175
Wire Wire Line
	7525 2175 7525 2550
Wire Wire Line
	7525 2550 7275 2550
Connection ~ 8225 1950
Wire Wire Line
	7275 2350 7375 2350
Wire Wire Line
	7375 2350 7375 1950
Wire Wire Line
	7800 2850 7950 2850
Wire Wire Line
	7950 2850 8400 2850
Text GLabel 7275 2950 2    60   UnSpc ~ 0
V-
Text GLabel 5875 2950 0    60   UnSpc ~ 0
V+
Text GLabel 6250 4100 0    60   UnSpc ~ 0
V+
Text GLabel 6925 4100 0    60   UnSpc ~ 0
V-
Text HLabel 6350 4100 2    60   Input ~ 0
V20
Wire Wire Line
	6250 4100 6350 4100
$Comp
L GND #PWR?
U 1 1 5917EE06
P 7050 4100
F 0 "#PWR?" H 7050 3850 50  0001 C CNN
F 1 "GND" H 7050 3950 50  0000 C CNN
F 2 "" H 7050 4100 50  0000 C CNN
F 3 "" H 7050 4100 50  0000 C CNN
	1    7050 4100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6925 4100 7050 4100
$Comp
L R R?
U 1 1 59181A59
P 7925 1650
F 0 "R?" V 8005 1650 50  0000 C CNN
F 1 "120k" V 7925 1650 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7855 1650 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 7925 1650 50  0001 C CNN
F 4 "2141505" V 7925 1650 60  0001 C CNN "Farnell"
	1    7925 1650
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 59181C7D
P 8600 1650
F 0 "R?" V 8680 1650 50  0000 C CNN
F 1 "120k" V 8600 1650 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8530 1650 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf" H 8600 1650 50  0001 C CNN
F 4 "2141505" V 8600 1650 60  0001 C CNN "Farnell"
	1    8600 1650
	0    1    1    0   
$EndComp
$EndSCHEMATC
