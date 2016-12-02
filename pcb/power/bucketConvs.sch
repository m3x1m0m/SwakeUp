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
Sheet 2 5
Title "Bucket Converters for 5 V and 2.8 V"
Date "2016-12-02"
Rev "1.0"
Comp "Uppsala University"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LM2840 U1
U 1 1 5842EC3B
P 2300 2550
F 0 "U1" H 2600 2300 60  0000 C CNN
F 1 "LM2840" H 2100 2300 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-6" H 2300 2550 60  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2841.pdf" H 2300 2550 60  0001 C CNN
F 4 "LM2840XMK-ADJL/NOPBTR-ND" H 2300 2550 60  0001 C CNN "Digikey"
	1    2300 2550
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5842EC43
P 2300 2100
F 0 "C2" H 2325 2200 50  0000 L CNN
F 1 "0.1u" H 2325 2000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2338 1950 50  0001 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 2300 2100 50  0001 C CNN
F 4 "311-1088-1-ND" H 2300 2100 60  0001 C CNN "Digikey"
	1    2300 2100
	0    1    1    0   
$EndComp
$Comp
L GND #PWR07
U 1 1 5842EC4A
P 1700 2550
F 0 "#PWR07" H 1700 2300 50  0001 C CNN
F 1 "GND" H 1700 2400 50  0000 C CNN
F 2 "" H 1700 2550 50  0000 C CNN
F 3 "" H 1700 2550 50  0000 C CNN
	1    1700 2550
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 5842EC51
P 3000 2850
F 0 "C3" H 3025 2950 50  0000 L CNN
F 1 "2.2u" H 3025 2750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3038 2700 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/partnumbering_e_01.pdf" H 3000 2850 50  0001 C CNN
F 4 "490-7204-1-ND" H 3000 2850 60  0001 C CNN "Digikey"
	1    3000 2850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5842EC58
P 3000 3600
F 0 "#PWR08" H 3000 3350 50  0001 C CNN
F 1 "GND" H 3000 3450 50  0000 C CNN
F 2 "" H 3000 3600 50  0000 C CNN
F 3 "" H 3000 3600 50  0000 C CNN
	1    3000 3600
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5842EC5F
P 1450 2750
F 0 "R2" V 1530 2750 50  0000 C CNN
F 1 "27k" V 1450 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1380 2750 50  0001 C CNN
F 3 "http://industrial.panasonic.com/www-cgi/jvcr13pz.cgi?E+PZ+3+AOA0002+ERJ3EKF2702V+7+WW" H 1450 2750 50  0001 C CNN
F 4 "P27.0KHCT-ND" V 1450 2750 60  0001 C CNN "Digikey"
	1    1450 2750
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 5842EC67
P 1800 2950
F 0 "R3" V 1880 2950 50  0000 C CNN
F 1 "10k" V 1800 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1730 2950 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 1800 2950 50  0001 C CNN
F 4 " 311-10.0KHRCT-ND" V 1800 2950 60  0001 C CNN "Digikey"
	1    1800 2950
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5842EC6F
P 1800 3300
F 0 "R4" V 1880 3300 50  0000 C CNN
F 1 "150" V 1800 3300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1730 3300 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 1800 3300 50  0001 C CNN
F 4 "311-150HRCT-ND" V 1800 3300 60  0001 C CNN "Digikey"
	1    1800 3300
	1    0    0    -1  
$EndComp
Text Notes 1200 1900 0    60   ~ 0
2.8 V for µC\n---------------------------\nVout=0.765 V (1 + (27k/ 10.15k))=2.8 V\n27k/10.15k= 2.66
$Comp
L INDUCTOR L1
U 1 1 5842EC78
P 4000 2400
F 0 "L1" V 3950 2400 50  0000 C CNN
F 1 "33u" V 4100 2400 50  0000 C CNN
F 2 "Additional:Bourns_SRN3015" H 4000 2400 50  0001 C CNN
F 3 "http://www.bourns.com/docs/Product-Datasheets/SRN3015.pdf" H 4000 2400 50  0001 C CNN
F 4 "SRN3015-330MCT-ND" V 4150 1850 60  0001 C CNN "Digikey"
	1    4000 2400
	0    -1   -1   0   
$EndComp
$Comp
L C C5
U 1 1 5842EC80
P 4350 2650
F 0 "C5" H 4375 2750 50  0000 L CNN
F 1 "10u" H 4375 2550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4388 2500 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 4350 2650 50  0001 C CNN
F 4 "490-12323-1-ND" H 4350 2650 60  0001 C CNN "Digikey"
	1    4350 2650
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 5842EC88
P 4800 2650
F 0 "D3" H 4800 2750 50  0000 C CNN
F 1 "LED" H 4800 2550 50  0000 C CNN
F 2 "LEDs:LED_0603" H 4800 2650 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic0/00167682_0.pdf" H 4800 2650 50  0001 C CNN
F 4 "475-3118-1-ND" H 4800 2650 60  0001 C CNN "Digikey"
	1    4800 2650
	0    -1   -1   0   
$EndComp
$Comp
L R R5
U 1 1 5842EC90
P 4800 3050
F 0 "R5" V 4880 3050 50  0000 C CNN
F 1 "560R" V 4800 3050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4730 3050 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4800 3050 50  0001 C CNN
F 4 "311-560GRCT-ND" V 4800 3050 60  0001 C CNN "Digikey"
	1    4800 3050
	1    0    0    -1  
$EndComp
Text Notes 4250 4150 0    60   ~ 0
Debugging Diode\n-----------------------\nDiode: 1.7 V, 2 mA\nP=2.161 mW\nCan be left out in a later version!
Wire Wire Line
	2800 2400 3700 2400
Wire Wire Line
	1800 2400 1800 2100
Wire Wire Line
	1800 2100 2150 2100
Wire Wire Line
	2450 2100 2850 2100
Wire Wire Line
	2850 2100 2850 2400
Connection ~ 2850 2400
Wire Wire Line
	3650 1950 3650 2500
Connection ~ 3650 2400
Wire Wire Line
	4350 2400 4350 2500
Wire Wire Line
	4350 2850 3650 2850
Wire Wire Line
	3650 2850 3650 2800
Connection ~ 4350 2400
Wire Wire Line
	1700 2550 1800 2550
Wire Wire Line
	2800 2700 2900 2700
Wire Wire Line
	2900 2700 2900 2550
Connection ~ 2900 2550
Wire Wire Line
	3000 3000 3000 3600
Wire Wire Line
	3000 2550 3000 2700
Wire Wire Line
	1800 3150 1800 3100
Wire Wire Line
	1800 2700 1800 2800
Wire Wire Line
	1800 2750 1600 2750
Connection ~ 1800 2750
Wire Wire Line
	1200 2750 1200 1950
Wire Wire Line
	1200 1950 3650 1950
Wire Wire Line
	1200 2750 1300 2750
Connection ~ 3000 3550
Connection ~ 4350 2850
Wire Wire Line
	1800 3550 1800 3450
Wire Wire Line
	4350 3550 4350 2800
Wire Wire Line
	2800 2550 3150 2550
Wire Wire Line
	4800 2900 4800 2850
Wire Wire Line
	4800 3550 4800 3200
Wire Wire Line
	4800 2400 4800 2450
Connection ~ 4350 3550
$Comp
L D_Schottky D2
U 1 1 5842ECC9
P 3650 2650
F 0 "D2" H 4100 2400 50  0000 C CNN
F 1 "VS-10MQ060NPbF" H 3800 2500 50  0000 C CNN
F 2 "Diodes_SMD:SMA_Handsoldering" H 3650 2650 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88869/packaging.pdf" H 3650 2650 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" V 3700 3250 60  0001 C CNN "Digikey"
	1    3650 2650
	0    1    1    0   
$EndComp
Connection ~ 3000 2550
$Comp
L GND #PWR09
U 1 1 5842F8AB
P 1800 5650
F 0 "#PWR09" H 1800 5400 50  0001 C CNN
F 1 "GND" H 1800 5500 50  0000 C CNN
F 2 "" H 1800 5650 50  0000 C CNN
F 3 "" H 1800 5650 50  0000 C CNN
	1    1800 5650
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 5842F8B2
P 5750 5650
F 0 "C6" H 5775 5750 50  0000 L CNN
F 1 "22u" H 5775 5550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5788 5500 50  0001 C CNN
F 3 "http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2016/08/18/S_CL10A226MQ8NRNC.pdf" H 5750 5650 50  0001 C CNN
F 4 "1276-1193-1-ND" H 5750 5650 60  0001 C CNN "Digikey"
	1    5750 5650
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR L2
U 1 1 5842F8BA
P 5250 5400
F 0 "L2" V 5200 5400 50  0000 C CNN
F 1 "4.7u" V 5350 5400 50  0000 C CNN
F 2 "Additional:Taiyo_Yuden_NRS8030_IND" H 5250 5400 50  0001 C CNN
F 3 "http://www.yuden.co.jp/productdata/catalog/en/wound04_e.pdf" H 5250 5400 50  0001 C CNN
F 4 "587-2969-1-ND " V 5250 5400 60  0001 C CNN "Digikey"
	1    5250 5400
	0    -1   -1   0   
$EndComp
$Comp
L C C1
U 1 1 5842F8C2
P 1800 5400
F 0 "C1" H 1825 5500 50  0000 L CNN
F 1 "10u" H 1825 5300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1838 5250 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 1800 5400 50  0001 C CNN
F 4 "490-12323-1-ND" H 1800 5400 60  0001 C CNN "Digikey"
	1    1800 5400
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 5842F8CA
P 4250 5600
F 0 "C4" H 4275 5700 50  0000 L CNN
F 1 "22n" H 4275 5500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4288 5450 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 4250 5600 50  0001 C CNN
F 4 "445-8118-1-ND" H 4250 5600 60  0001 C CNN "Digikey"
	1    4250 5600
	0    -1   -1   0   
$EndComp
$Comp
L C C7
U 1 1 5842F8D2
P 6200 5650
F 0 "C7" H 6225 5750 50  0000 L CNN
F 1 "22u" H 6225 5550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6238 5500 50  0001 C CNN
F 3 "http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2016/08/18/S_CL10A226MQ8NRNC.pdf" H 6200 5650 50  0001 C CNN
F 4 "1276-1193-1-ND" H 6200 5650 60  0001 C CNN "Digikey"
	1    6200 5650
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky D4
U 1 1 5842F8DA
P 4850 5650
F 0 "D4" V 4800 5800 50  0000 C CNN
F 1 "VS-10MQ060NPbF" V 4900 6100 50  0000 C CNN
F 2 "Diodes_SMD:SMA_Handsoldering" H 4850 5650 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88869/packaging.pdf" H 4850 5650 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" V 4900 6250 60  0001 C CNN "Digikey"
	1    4850 5650
	0    1    1    0   
$EndComp
$Comp
L LED D5
U 1 1 5842F8E3
P 6600 5650
F 0 "D5" H 6600 5750 50  0000 C CNN
F 1 "LED" H 6600 5550 50  0000 C CNN
F 2 "LEDs:LED_0603" H 6600 5650 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic0/00167682_0.pdf" H 6600 5650 50  0001 C CNN
F 4 "475-3118-1-ND" H 6600 5650 60  0001 C CNN "Digikey"
	1    6600 5650
	0    -1   -1   0   
$EndComp
$Comp
L R R6
U 1 1 5842F8EB
P 6600 6100
F 0 "R6" V 6680 6100 50  0000 C CNN
F 1 "1.5k" V 6600 6100 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" V 6530 6100 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 6600 6100 50  0001 C CNN
F 4 "311-1.5KGRCT-ND " V 6600 6100 60  0001 C CNN "Digikey"
	1    6600 6100
	1    0    0    -1  
$EndComp
Text Notes 4750 7050 0    60   ~ 0
Debugging Diode\n-----------------------\nDiode: 1.7 V, 2 mA\nP=7.26 mW\nCan be left out in a later version!
Wire Wire Line
	1800 5250 1800 5200
Connection ~ 1800 5200
Wire Wire Line
	1800 5550 1800 5650
Connection ~ 1800 5600
Wire Wire Line
	3900 5400 4950 5400
Connection ~ 5750 5400
Wire Wire Line
	4850 5500 4850 5400
Connection ~ 4850 5400
Wire Wire Line
	5750 5250 5750 5500
Wire Wire Line
	6200 5400 6200 5500
Wire Wire Line
	4850 5800 4850 6300
Wire Wire Line
	6200 6300 6200 5800
Wire Wire Line
	5750 5800 5750 6300
Connection ~ 5750 6300
Wire Wire Line
	1650 5200 2300 5200
Wire Wire Line
	2300 5400 2000 5400
Wire Wire Line
	2000 5400 2000 5600
Wire Wire Line
	2000 5600 1800 5600
Wire Wire Line
	3900 5600 4100 5600
Connection ~ 4550 5400
Wire Wire Line
	2300 5600 2150 5600
Wire Wire Line
	2150 5600 2150 6300
Wire Wire Line
	4700 6300 4700 5400
Connection ~ 4700 5400
Connection ~ 6200 5400
Wire Wire Line
	4100 5800 3900 5800
Wire Wire Line
	4550 5600 4400 5600
Wire Wire Line
	6600 5850 6600 5950
Wire Wire Line
	6600 5400 6600 5450
$Comp
L TS30012 U2
U 1 1 5842F919
P 3050 5500
F 0 "U2" H 3700 5050 60  0000 C CNN
F 1 "TS30012" H 2650 5050 60  0000 C CNN
F 2 "Additional:QFN-16-1EP_3x3mm_Pitch0.5mm" H 3200 5500 60  0001 C CNN
F 3 "http://www.semtech.com/images/datasheet/ts30011_12_13.pdf" H 3200 5500 60  0001 C CNN
F 4 "TS30012-M050QFNRCT-ND " H 3050 5500 60  0001 C CNN "Digikey"
	1    3050 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 6300 6600 6250
Connection ~ 6200 6300
Wire Wire Line
	3900 5200 4100 5200
Text Notes 1400 4900 0    60   ~ 0
5V for Mobile Phone\n-----------------------\nVout,max=5 V\nAout,max = 2A
$Comp
L GND #PWR010
U 1 1 5842F92D
P 3100 6050
F 0 "#PWR010" H 3100 5800 50  0001 C CNN
F 1 "GND" H 3100 5900 50  0000 C CNN
F 2 "" H 3100 6050 50  0000 C CNN
F 3 "" H 3100 6050 50  0000 C CNN
	1    3100 6050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 5842F939
P 4100 5200
F 0 "#PWR011" H 4100 4950 50  0001 C CNN
F 1 "GND" H 4100 5050 50  0000 C CNN
F 2 "" H 4100 5200 50  0000 C CNN
F 3 "" H 4100 5200 50  0000 C CNN
	1    4100 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 5400 4550 5600
$Comp
L PWR_FLAG #FLG012
U 1 1 5842F941
P 5750 5250
F 0 "#FLG012" H 5750 5345 50  0001 C CNN
F 1 "PWR_FLAG" H 5750 5430 50  0000 C CNN
F 2 "" H 5750 5250 50  0000 C CNN
F 3 "" H 5750 5250 50  0000 C CNN
	1    5750 5250
	1    0    0    -1  
$EndComp
Text HLabel 3150 2550 2    60   Input ~ 0
V20
Text HLabel 1650 5200 0    60   Input ~ 0
V20
Text HLabel 4100 5800 2    60   Input ~ 0
5V_EN
Wire Wire Line
	5550 5400 6850 5400
Text HLabel 6850 5400 2    60   Output ~ 0
V5
Wire Wire Line
	2150 6300 4700 6300
Wire Wire Line
	4850 6300 6600 6300
Wire Wire Line
	1800 3550 4800 3550
Wire Wire Line
	4300 2400 5150 2400
Connection ~ 6600 5400
Text HLabel 5150 2400 2    60   Output ~ 0
V28
Connection ~ 4800 2400
$EndSCHEMATC
