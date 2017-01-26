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
Sheet 3 4
Title "Bucket Converter for 2.8 V "
Date "2016-11-26"
Rev "v1.0"
Comp "Uppsala University"
Comment1 "Drain up to 100 mA."
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LM2840 U2
U 1 1 583BD90D
P 5050 3450
F 0 "U2" H 5350 3200 60  0000 C CNN
F 1 "LM2840" H 4850 3200 60  0000 C CNN
F 2 "" H 5050 3450 60  0000 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2841.pdf" H 5050 3450 60  0001 C CNN
F 4 "LM2840XMK-ADJL/NOPBTR-ND" H 5050 3450 60  0001 C CNN "Digikey"
	1    5050 3450
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky D7
U 1 1 583BD91C
P 6400 3550
F 0 "D7" H 6400 3650 50  0000 C CNN
F 1 "VS-10MQ060NPbF" H 6400 3450 50  0000 C CNN
F 2 "" H 6400 3550 50  0000 C CNN
F 3 "http://www.vishay.com/docs/94118/vs-10mq060npbf.pdf" H 6400 3550 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" H 6400 3550 60  0001 C CNN "Digikey"
	1    6400 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	5550 3300 6450 3300
$Comp
L C C13
U 1 1 583BD926
P 5050 3000
F 0 "C13" H 5075 3100 50  0000 L CNN
F 1 "0.1u" H 5075 2900 50  0000 L CNN
F 2 "" H 5088 2850 50  0000 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 5050 3000 50  0001 C CNN
F 4 "311-1088-1-ND" H 5050 3000 60  0001 C CNN "Digikey"
	1    5050 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	4550 3300 4550 3000
Wire Wire Line
	4550 3000 4900 3000
Wire Wire Line
	5200 3000 5600 3000
Wire Wire Line
	5600 3000 5600 3300
Connection ~ 5600 3300
Wire Wire Line
	6400 2850 6400 3400
Connection ~ 6400 3300
Wire Wire Line
	7050 3300 7400 3300
Wire Wire Line
	7100 3300 7100 3400
Wire Wire Line
	7100 3750 6400 3750
Wire Wire Line
	6400 3750 6400 3700
Connection ~ 7100 3300
Wire Wire Line
	5550 3450 5900 3450
$Comp
L GND #PWR10
U 1 1 583BD949
P 4450 3450
F 0 "#PWR10" H 4450 3200 50  0001 C CNN
F 1 "GND" H 4450 3300 50  0000 C CNN
F 2 "" H 4450 3450 50  0000 C CNN
F 3 "" H 4450 3450 50  0000 C CNN
	1    4450 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 3450 4550 3450
Wire Wire Line
	5550 3600 5650 3600
Wire Wire Line
	5650 3600 5650 3450
Connection ~ 5650 3450
$Comp
L C C14
U 1 1 583BD954
P 5750 3750
F 0 "C14" H 5775 3850 50  0000 L CNN
F 1 "2.2u" H 5775 3650 50  0000 L CNN
F 2 "" H 5788 3600 50  0000 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/partnumbering_e_01.pdf" H 5750 3750 50  0001 C CNN
F 4 "490-7204-1-ND" H 5750 3750 60  0001 C CNN "Digikey"
	1    5750 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR11
U 1 1 583BD95B
P 5750 4500
F 0 "#PWR11" H 5750 4250 50  0001 C CNN
F 1 "GND" H 5750 4350 50  0000 C CNN
F 2 "" H 5750 4500 50  0000 C CNN
F 3 "" H 5750 4500 50  0000 C CNN
	1    5750 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3900 5750 4500
Wire Wire Line
	5750 3600 5750 3450
Connection ~ 5750 3450
$Comp
L R R24
U 1 1 583BD965
P 4200 3650
F 0 "R24" V 4280 3650 50  0000 C CNN
F 1 "27k" V 4200 3650 50  0000 C CNN
F 2 "" V 4130 3650 50  0000 C CNN
F 3 "http://industrial.panasonic.com/www-cgi/jvcr13pz.cgi?E+PZ+3+AOA0002+ERJ3EKF2702V+7+WW" H 4200 3650 50  0001 C CNN
F 4 "P27.0KHCT-ND" V 4200 3650 60  0001 C CNN "Digikey"
	1    4200 3650
	0    1    1    0   
$EndComp
$Comp
L R R25
U 1 1 583BD96C
P 4550 3850
F 0 "R25" V 4630 3850 50  0000 C CNN
F 1 "10k" V 4550 3850 50  0000 C CNN
F 2 "" V 4480 3850 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4550 3850 50  0001 C CNN
F 4 " 311-10.0KHRCT-ND" V 4550 3850 60  0001 C CNN "Digikey"
	1    4550 3850
	1    0    0    -1  
$EndComp
$Comp
L R R26
U 1 1 583BD973
P 4550 4200
F 0 "R26" V 4630 4200 50  0000 C CNN
F 1 "150" V 4550 4200 50  0000 C CNN
F 2 "" V 4480 4200 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4550 4200 50  0001 C CNN
F 4 "311-150HRCT-ND" V 4550 4200 60  0001 C CNN "Digikey"
	1    4550 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 4050 4550 4000
Wire Wire Line
	4550 3600 4550 3700
Wire Wire Line
	4550 3650 4350 3650
Connection ~ 4550 3650
Wire Wire Line
	3950 3650 3950 2850
Wire Wire Line
	3950 2850 6400 2850
Wire Wire Line
	3950 3650 4050 3650
Wire Wire Line
	7100 4450 4550 4450
Connection ~ 5750 4450
Connection ~ 7100 3750
Wire Wire Line
	4550 4450 4550 4350
Text Notes 3950 4700 0    60   ~ 0
V_OUT = 0.765 V (1 + (R1 / R2))\nR1/R2 = 2.66
Text HLabel 7400 3300 2    60   Output ~ 0
V28
Text HLabel 5900 3450 2    60   Input ~ 0
V20
$Comp
L INDUCTOR L4
U 1 1 583C4B66
P 6750 3300
F 0 "L4" V 6700 3300 50  0000 C CNN
F 1 "33u" V 6850 3300 50  0000 C CNN
F 2 "" H 6750 3300 50  0000 C CNN
F 3 "http://www.bourns.com/docs/Product-Datasheets/SRN3015.pdf" H 6750 3300 50  0001 C CNN
F 4 "SRN3015-330MCT-ND" V 6900 2750 60  0001 C CNN "Digikey"
	1    6750 3300
	0    -1   -1   0   
$EndComp
$Comp
L C C15
U 1 1 583C4EC3
P 7100 3550
F 0 "C15" H 7125 3650 50  0000 L CNN
F 1 "10u" H 7125 3450 50  0000 L CNN
F 2 "" H 7138 3400 50  0000 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 7100 3550 50  0001 C CNN
F 4 "490-12323-1-ND" H 7100 3550 60  0001 C CNN "Digikey"
	1    7100 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 3700 7100 4450
$EndSCHEMATC
