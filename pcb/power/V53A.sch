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
Sheet 4 4
Title "Bucket Converter for 5V, 3A"
Date "2016-11-27"
Rev "v1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L TS30013 U3
U 1 1 583B345B
P 4450 3200
F 0 "U3" H 5100 2750 60  0000 C CNN
F 1 "TS30013" H 4050 2750 60  0000 C CNN
F 2 "" H 4550 3200 60  0000 C CNN
F 3 "http://www.semtech.com/images/datasheet/ts30011_12_13.pdf" H 4550 3200 60  0001 C CNN
F 4 "TS30013-M050QFNRCT-ND" H 4450 3200 60  0001 C CNN "Digikey"
	1    4450 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR12
U 1 1 583B3462
P 5500 2900
F 0 "#PWR12" H 5500 2650 50  0001 C CNN
F 1 "GND" H 5500 2750 50  0000 C CNN
F 2 "" H 5500 2900 50  0000 C CNN
F 3 "" H 5500 2900 50  0000 C CNN
	1    5500 2900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR10
U 1 1 583B3468
P 3200 3350
F 0 "#PWR10" H 3200 3100 50  0001 C CNN
F 1 "GND" H 3200 3200 50  0000 C CNN
F 2 "" H 3200 3350 50  0000 C CNN
F 3 "" H 3200 3350 50  0000 C CNN
	1    3200 3350
	1    0    0    -1  
$EndComp
$Comp
L C C18
U 1 1 583B3476
P 7150 3350
F 0 "C18" H 7175 3450 50  0000 L CNN
F 1 "22u" H 7175 3250 50  0000 L CNN
F 2 "" H 7188 3200 50  0000 C CNN
F 3 "http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2016/08/18/S_CL10A226MQ8NRNC.pdf" H 7150 3350 50  0001 C CNN
F 4 "1276-1193-1-ND" H 7150 3350 60  0001 C CNN "Digikey"
	1    7150 3350
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR L5
U 1 1 583B3484
P 6650 3100
F 0 "L5" V 6600 3100 50  0000 C CNN
F 1 "4.7u" V 6750 3100 50  0000 C CNN
F 2 "" H 6650 3100 50  0000 C CNN
F 3 "http://www.yuden.co.jp/productdata/catalog/en/wound04_e.pdf" H 6650 3100 50  0001 C CNN
F 4 "587-2969-1-ND " V 6650 3100 60  0001 C CNN "Digikey"
	1    6650 3100
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR11
U 1 1 583B3492
P 4500 3800
F 0 "#PWR11" H 4500 3550 50  0001 C CNN
F 1 "GND" H 4500 3650 50  0000 C CNN
F 2 "" H 4500 3800 50  0000 C CNN
F 3 "" H 4500 3800 50  0000 C CNN
	1    4500 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 2950 3200 2900
Connection ~ 3200 2900
Wire Wire Line
	3200 3250 3200 3350
Connection ~ 3200 3300
Wire Wire Line
	5300 3100 6350 3100
Wire Wire Line
	6950 3100 7800 3100
Connection ~ 7150 3100
Wire Wire Line
	6250 3200 6250 3100
Connection ~ 6250 3100
Wire Wire Line
	7150 3100 7150 3200
Wire Wire Line
	7550 3100 7550 3200
Wire Wire Line
	6250 3500 6250 3600
Wire Wire Line
	6250 3600 7550 3600
Wire Wire Line
	7550 3600 7550 3500
Wire Wire Line
	7150 3500 7150 3600
Connection ~ 7150 3600
Wire Wire Line
	3050 2900 3700 2900
Wire Wire Line
	3700 3100 3400 3100
Wire Wire Line
	3400 3100 3400 3300
Wire Wire Line
	3400 3300 3200 3300
Wire Wire Line
	4500 3750 4500 3800
Wire Wire Line
	5300 2900 5500 2900
Wire Wire Line
	5300 3300 5500 3300
Connection ~ 5950 3100
Wire Wire Line
	3700 3300 3550 3300
Wire Wire Line
	3550 3300 3550 4000
Wire Wire Line
	3550 4000 6100 4000
Wire Wire Line
	6100 4000 6100 3100
Connection ~ 6100 3100
Wire Wire Line
	5950 3300 5950 3100
Text HLabel 3050 2900 0    60   Input ~ 0
V20
Text HLabel 7800 3100 2    60   Output ~ 0
V5
Connection ~ 7550 3100
Text HLabel 5500 3500 2    60   Input ~ 0
5V_EN
Wire Wire Line
	5500 3500 5300 3500
$Comp
L C C16
U 1 1 583C14BA
P 3200 3100
F 0 "C16" H 3225 3200 50  0000 L CNN
F 1 "10u" H 3225 3000 50  0000 L CNN
F 2 "" H 3238 2950 50  0000 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 3200 3100 50  0001 C CNN
F 4 "490-12323-1-ND" H 3200 3100 60  0001 C CNN "Digikey"
	1    3200 3100
	1    0    0    -1  
$EndComp
$Comp
L C C17
U 1 1 583C19B4
P 5650 3300
F 0 "C17" H 5675 3400 50  0000 L CNN
F 1 "22n" H 5675 3200 50  0000 L CNN
F 2 "" H 5688 3150 50  0000 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 5650 3300 50  0001 C CNN
F 4 "445-8118-1-ND" H 5650 3300 60  0001 C CNN "Digikey"
	1    5650 3300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5800 3300 5950 3300
$Comp
L C C19
U 1 1 583C1DEC
P 7550 3350
F 0 "C19" H 7575 3450 50  0000 L CNN
F 1 "22u" H 7575 3250 50  0000 L CNN
F 2 "" H 7588 3200 50  0000 C CNN
F 3 "http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2016/08/18/S_CL10A226MQ8NRNC.pdf" H 7550 3350 50  0001 C CNN
F 4 "1276-1193-1-ND" H 7550 3350 60  0001 C CNN "Digikey"
	1    7550 3350
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky D?
U 1 1 583C3D85
P 6250 3350
F 0 "D?" V 6200 3500 50  0000 C CNN
F 1 "VS-10MQ060NPbF" V 6300 3800 50  0000 C CNN
F 2 "" H 6250 3350 50  0000 C CNN
F 3 "http://www.vishay.com/docs/88869/packaging.pdf" H 6250 3350 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" V 6300 3950 60  0001 C CNN "Digikey"
	1    6250 3350
	0    1    1    0   
$EndComp
$EndSCHEMATC
