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
Sheet 5 5
Title "RGB LED Driver "
Date "2016-12-30"
Rev "1.0"
Comp "Uppsala University"
Comment1 "Project: Swakeup"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 950  6750 0    60   Input ~ 0
PWM_G
Text HLabel 5800 6200 2    60   Output ~ 0
LED_G_P
Text HLabel 5800 7050 2    60   Output ~ 0
LED_G_N
Text HLabel 5800 5500 2    60   Output ~ 0
OPAMP_G_P
Text HLabel 950  4550 0    60   Input ~ 0
PWM_B
Text HLabel 5800 4000 2    60   Output ~ 0
LED_B_P
Text HLabel 5800 4850 2    60   Output ~ 0
LED_B_N
Text HLabel 5800 3300 2    60   Output ~ 0
OPAMP_B_P
$Comp
L R R24
U 1 1 5837C403
P 2600 1350
F 0 "R24" V 2680 1350 50  0000 C CNN
F 1 "10k" V 2600 1350 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 2530 1350 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 2600 1350 50  0001 C CNN
F 4 "311-10KGRCT-ND" V 2600 1350 60  0001 C CNN "Digikey"
	1    2600 1350
	-1   0    0    1   
$EndComp
$Comp
L R R21
U 1 1 5837C40A
P 2000 2500
F 0 "R21" V 2080 2500 50  0000 C CNN
F 1 "470R" V 2000 2500 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 1930 2500 50  0001 C CNN
F 3 "https://industrial.panasonic.com/cdbs/www-data/pdf/RDA0000/AOA0000COL70.pdf" H 2000 2500 50  0001 C CNN
F 4 "311-470HRCT-ND " V 2000 2500 60  0001 C CNN "Digikey"
	1    2000 2500
	0    1    1    0   
$EndComp
$Comp
L C C12
U 1 1 5837C411
P 2000 2200
F 0 "C12" H 2025 2300 50  0000 L CNN
F 1 "150p" H 2025 2100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2038 2050 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM033R71E151KA01-01.pdf" H 2000 2200 50  0001 C CNN
F 4 "399-1063-1-ND" H 2000 2200 60  0001 C CNN "Digikey"
	1    2000 2200
	0    1    1    0   
$EndComp
Text HLabel 950  2500 0    60   Input ~ 0
PWM_R
$Comp
L INDUCTOR L3
U 1 1 5837C419
P 4150 1950
F 0 "L3" V 4100 1950 50  0000 C CNN
F 1 "33u" V 4250 1950 50  0000 C CNN
F 2 "Additional:Bourns_SRN3015" H 4150 1950 50  0001 C CNN
F 3 "http://www.bourns.com/docs/Product-Datasheets/SRN3015.pdf" H 4150 1950 50  0001 C CNN
F 4 "SRN3015-330MCT-ND" V 4300 1400 60  0001 C CNN "Digikey"
	1    4150 1950
	0    -1   -1   0   
$EndComp
$Comp
L D_Schottky D9
U 1 1 5837C420
P 3750 2350
F 0 "D9" V 3700 2500 50  0000 C CNN
F 1 "VS-10MQ060NPbF" V 3800 2800 50  0000 C CNN
F 2 "Diodes_SMD:SMA_Handsoldering" H 3750 2350 50  0001 C CNN
F 3 "http://www.vishay.com/docs/94118/vs-10mq060npbf.pdf" H 3750 2350 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" V 3800 2950 60  0001 C CNN "Digikey"
	1    3750 2350
	0    1    1    0   
$EndComp
$Comp
L C C15
U 1 1 5837C427
P 4550 2350
F 0 "C15" H 4575 2450 50  0000 L CNN
F 1 "10u" H 4575 2250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4588 2200 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 4550 2350 50  0001 C CNN
F 4 "490-12323-1-ND" H 4550 2350 60  0001 C CNN "Digikey"
	1    4550 2350
	1    0    0    -1  
$EndComp
Text HLabel 5800 1950 2    60   Output ~ 0
LED_R_P
Text HLabel 5800 2800 2    60   Output ~ 0
LED_R_N
$Comp
L R R27
U 1 1 5837C430
P 5200 1950
F 0 "R27" V 5280 1950 50  0000 C CNN
F 1 "0.1R" V 5200 1950 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5130 1950 50  0001 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RU_Series_ds.pdf" H 5200 1950 50  0001 C CNN
F 4 "1276-6155-1-ND" V 5200 1950 60  0001 C CNN "Digikey"
	1    5200 1950
	0    1    1    0   
$EndComp
$Comp
L C C18
U 1 1 5837C437
P 5200 1450
F 0 "C18" H 5225 1550 50  0000 L CNN
F 1 "22n" H 5225 1350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5238 1300 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 5200 1450 50  0001 C CNN
F 4 "1276-1104-1-ND" H 5200 1450 60  0001 C CNN "Digikey"
	1    5200 1450
	0    -1   -1   0   
$EndComp
$Comp
L R R30
U 1 1 5837C43E
P 4950 1700
F 0 "R30" V 5030 1700 50  0000 C CNN
F 1 "4.7k" V 4950 1700 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4880 1700 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4950 1700 50  0001 C CNN
F 4 "311-4.7KGRCT-ND" V 4950 1700 60  0001 C CNN "Digikey"
	1    4950 1700
	-1   0    0    1   
$EndComp
Text HLabel 5800 1250 2    60   Output ~ 0
OPAMP_R_P
Text HLabel 950  1100 0    60   Input ~ 0
V20
Text Notes 4950 1100 0    60   ~ 0
Low-Pass Filter\n-----------------------\nfcutt,off=1.539 kHz\nfsample=4 kHz
$Comp
L D D6
U 1 1 583CC52C
P 3400 2050
F 0 "D6" V 3450 1900 50  0000 C CNN
F 1 "1N4148WFL-G" V 3350 1700 50  0000 C CNN
F 2 "Additional:SOD-123F" H 3400 2050 50  0001 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Vishay%20Semiconductors/1N4148WFL-G.pdf" H 3400 2050 50  0001 C CNN
F 4 "1621821" V 3350 1300 60  0001 C CNN "Farnell"
	1    3400 2050
	0    -1   -1   0   
$EndComp
$Comp
L C C13
U 1 1 58416D9D
P 2000 4250
F 0 "C13" H 2025 4350 50  0000 L CNN
F 1 "150p" H 2025 4150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2038 4100 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM033R71E151KA01-01.pdf" H 2000 4250 50  0001 C CNN
F 4 "399-1063-1-ND" H 2000 4250 60  0001 C CNN "Digikey"
	1    2000 4250
	0    1    1    0   
$EndComp
$Comp
L C C14
U 1 1 58416E8A
P 2000 6450
F 0 "C14" H 2025 6550 50  0000 L CNN
F 1 "150p" H 2025 6350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2038 6300 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM033R71E151KA01-01.pdf" H 2000 6450 50  0001 C CNN
F 4 "399-1063-1-ND" H 2000 6450 60  0001 C CNN "Digikey"
	1    2000 6450
	0    1    1    0   
$EndComp
$Comp
L R R22
U 1 1 58417A6F
P 2000 4550
F 0 "R22" V 2080 4550 50  0000 C CNN
F 1 "470R" V 2000 4550 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 1930 4550 50  0001 C CNN
F 3 "https://industrial.panasonic.com/cdbs/www-data/pdf/RDA0000/AOA0000COL70.pdf" H 2000 4550 50  0001 C CNN
F 4 "311-470HRCT-ND " V 2000 4550 60  0001 C CNN "Digikey"
	1    2000 4550
	0    1    1    0   
$EndComp
$Comp
L R R23
U 1 1 58417E43
P 2000 6750
F 0 "R23" V 2080 6750 50  0000 C CNN
F 1 "470R" V 2000 6750 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 1930 6750 50  0001 C CNN
F 3 "https://industrial.panasonic.com/cdbs/www-data/pdf/RDA0000/AOA0000COL70.pdf" H 2000 6750 50  0001 C CNN
F 4 "311-470HRCT-ND " V 2000 6750 60  0001 C CNN "Digikey"
	1    2000 6750
	0    1    1    0   
$EndComp
$Comp
L R R26
U 1 1 58418FF7
P 2600 5600
F 0 "R26" V 2680 5600 50  0000 C CNN
F 1 "10k" V 2600 5600 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 2530 5600 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 2600 5600 50  0001 C CNN
F 4 "311-10KGRCT-ND" V 2600 5600 60  0001 C CNN "Digikey"
	1    2600 5600
	-1   0    0    1   
$EndComp
$Comp
L R R25
U 1 1 584192F9
P 2600 3400
F 0 "R25" V 2680 3400 50  0000 C CNN
F 1 "10k" V 2600 3400 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 2530 3400 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 2600 3400 50  0001 C CNN
F 4 "311-10KGRCT-ND" V 2600 3400 60  0001 C CNN "Digikey"
	1    2600 3400
	-1   0    0    1   
$EndComp
$Comp
L D D7
U 1 1 5841D6DF
P 3400 4100
F 0 "D7" V 3450 3950 50  0000 C CNN
F 1 "1N4148WFL-G" V 3350 3750 50  0000 C CNN
F 2 "Additional:SOD-123F" H 3400 4100 50  0001 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Vishay%20Semiconductors/1N4148WFL-G.pdf" H 3400 4100 50  0001 C CNN
F 4 "1621821" V 3350 3350 60  0001 C CNN "Farnell"
	1    3400 4100
	0    -1   -1   0   
$EndComp
$Comp
L D D8
U 1 1 5841DBA5
P 3400 6300
F 0 "D8" V 3450 6150 50  0000 C CNN
F 1 "1N4148WFL-G" V 3350 5950 50  0000 C CNN
F 2 "Additional:SOD-123F" H 3400 6300 50  0001 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Vishay%20Semiconductors/1N4148WFL-G.pdf" H 3400 6300 50  0001 C CNN
F 4 "1621821" V 3350 5550 60  0001 C CNN "Farnell"
	1    3400 6300
	0    -1   -1   0   
$EndComp
$Comp
L D_Schottky D10
U 1 1 5841EC23
P 3750 4400
F 0 "D10" V 3700 4550 50  0000 C CNN
F 1 "VS-10MQ060NPbF" V 3800 4850 50  0000 C CNN
F 2 "Diodes_SMD:SMA_Handsoldering" H 3750 4400 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88869/packaging.pdf" H 3750 4400 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" V 3800 5000 60  0001 C CNN "Digikey"
	1    3750 4400
	0    1    1    0   
$EndComp
$Comp
L D_Schottky D11
U 1 1 5841EE79
P 3750 6600
F 0 "D11" V 3700 6750 50  0000 C CNN
F 1 "VS-10MQ060NPbF" V 3800 7050 50  0000 C CNN
F 2 "Diodes_SMD:SMA_Handsoldering" H 3750 6600 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88869/packaging.pdf" H 3750 6600 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" V 3800 7200 60  0001 C CNN "Digikey"
	1    3750 6600
	0    1    1    0   
$EndComp
$Comp
L INDUCTOR L4
U 1 1 5842003F
P 4150 4000
F 0 "L4" V 4100 4000 50  0000 C CNN
F 1 "33u" V 4250 4000 50  0000 C CNN
F 2 "Additional:Bourns_SRN3015" H 4150 4000 50  0001 C CNN
F 3 "http://www.bourns.com/docs/Product-Datasheets/SRN3015.pdf" H 4150 4000 50  0001 C CNN
F 4 "SRN3015-330MCT-ND" V 4300 3450 60  0001 C CNN "Digikey"
	1    4150 4000
	0    -1   -1   0   
$EndComp
$Comp
L INDUCTOR L5
U 1 1 58420295
P 4150 6200
F 0 "L5" V 4100 6200 50  0000 C CNN
F 1 "33u" V 4250 6200 50  0000 C CNN
F 2 "Additional:Bourns_SRN3015" H 4150 6200 50  0001 C CNN
F 3 "http://www.bourns.com/docs/Product-Datasheets/SRN3015.pdf" H 4150 6200 50  0001 C CNN
F 4 "SRN3015-330MCT-ND" V 4300 5650 60  0001 C CNN "Digikey"
	1    4150 6200
	0    -1   -1   0   
$EndComp
$Comp
L C C16
U 1 1 584220D2
P 4550 4400
F 0 "C16" H 4575 4500 50  0000 L CNN
F 1 "10u" H 4575 4300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4588 4250 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 4550 4400 50  0001 C CNN
F 4 "490-12323-1-ND" H 4550 4400 60  0001 C CNN "Digikey"
	1    4550 4400
	1    0    0    -1  
$EndComp
$Comp
L C C17
U 1 1 584221E0
P 4550 6600
F 0 "C17" H 4575 6700 50  0000 L CNN
F 1 "10u" H 4575 6500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4588 6450 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 4550 6600 50  0001 C CNN
F 4 "490-12323-1-ND" H 4550 6600 60  0001 C CNN "Digikey"
	1    4550 6600
	1    0    0    -1  
$EndComp
$Comp
L R R28
U 1 1 58425BE1
P 5200 4000
F 0 "R28" V 5280 4000 50  0000 C CNN
F 1 "0.1R" V 5200 4000 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5130 4000 50  0001 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RU_Series_ds.pdf" H 5200 4000 50  0001 C CNN
F 4 "1276-6155-1-ND" V 5200 4000 60  0001 C CNN "Digikey"
	1    5200 4000
	0    1    1    0   
$EndComp
$Comp
L R R29
U 1 1 58425F29
P 5200 6200
F 0 "R29" V 5280 6200 50  0000 C CNN
F 1 "0.1R" V 5200 6200 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5130 6200 50  0001 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RU_Series_ds.pdf" H 5200 6200 50  0001 C CNN
F 4 "1276-6155-1-ND" V 5200 6200 60  0001 C CNN "Digikey"
	1    5200 6200
	0    1    1    0   
$EndComp
$Comp
L R R32
U 1 1 58426A19
P 4950 5950
F 0 "R32" V 5030 5950 50  0000 C CNN
F 1 "4.7k" V 4950 5950 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4880 5950 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4950 5950 50  0001 C CNN
F 4 "311-4.7KGRCT-ND" V 4950 5950 60  0001 C CNN "Digikey"
	1    4950 5950
	-1   0    0    1   
$EndComp
$Comp
L R R31
U 1 1 58426AE7
P 4900 3750
F 0 "R31" V 4980 3750 50  0000 C CNN
F 1 "4.7k" V 4900 3750 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4830 3750 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4900 3750 50  0001 C CNN
F 4 "311-4.7KGRCT-ND" V 4900 3750 60  0001 C CNN "Digikey"
	1    4900 3750
	-1   0    0    1   
$EndComp
$Comp
L C C19
U 1 1 584270BF
P 5150 3500
F 0 "C19" H 5175 3600 50  0000 L CNN
F 1 "22n" H 5175 3400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5188 3350 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 5150 3500 50  0001 C CNN
F 4 "1276-1104-1-ND " H 5150 3500 60  0001 C CNN "Digikey"
	1    5150 3500
	0    -1   -1   0   
$EndComp
$Comp
L C C20
U 1 1 58427309
P 5200 5700
F 0 "C20" H 5225 5800 50  0000 L CNN
F 1 "22n" H 5225 5600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5238 5550 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 5200 5700 50  0001 C CNN
F 4 "1276-1104-1-ND " H 5200 5700 60  0001 C CNN "Digikey"
	1    5200 5700
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR025
U 1 1 584188BC
P 4550 7100
F 0 "#PWR025" H 4550 6850 50  0001 C CNN
F 1 "GND" H 4550 6950 50  0000 C CNN
F 2 "" H 4550 7100 50  0000 C CNN
F 3 "" H 4550 7100 50  0000 C CNN
	1    4550 7100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR026
U 1 1 58418AC2
P 4550 4900
F 0 "#PWR026" H 4550 4650 50  0001 C CNN
F 1 "GND" H 4550 4750 50  0000 C CNN
F 2 "" H 4550 4900 50  0000 C CNN
F 3 "" H 4550 4900 50  0000 C CNN
	1    4550 4900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR027
U 1 1 584185EC
P 4550 2850
F 0 "#PWR027" H 4550 2600 50  0001 C CNN
F 1 "GND" H 4550 2700 50  0000 C CNN
F 2 "" H 4550 2850 50  0000 C CNN
F 3 "" H 4550 2850 50  0000 C CNN
	1    4550 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 5350 3200 5350
Wire Wire Line
	2600 5450 2600 5350
Connection ~ 2600 5350
Wire Wire Line
	2600 5750 2600 6550
Wire Wire Line
	2600 5900 2650 5900
Wire Wire Line
	2950 5700 2950 5350
Connection ~ 2950 5350
Wire Wire Line
	2950 6100 3400 6100
Wire Wire Line
	3400 5650 3400 6150
Connection ~ 3400 6100
Wire Wire Line
	3400 6500 3400 6450
Wire Wire Line
	950  6750 1850 6750
Wire Wire Line
	2150 6750 2300 6750
Wire Wire Line
	1850 6450 1800 6450
Wire Wire Line
	1800 6450 1800 6750
Connection ~ 1800 6750
Wire Wire Line
	2150 6450 2200 6450
Wire Wire Line
	2200 6450 2200 6750
Connection ~ 2200 6750
Connection ~ 2600 5900
Wire Wire Line
	2600 6500 3400 6500
Wire Wire Line
	3750 6200 3850 6200
Connection ~ 2600 6500
Wire Wire Line
	4550 6450 4550 6200
Connection ~ 4550 6200
Wire Wire Line
	3750 6750 3750 7050
Wire Wire Line
	2600 7050 2600 6950
Wire Wire Line
	4550 6750 4550 7100
Connection ~ 3750 7050
Connection ~ 4550 7050
Wire Wire Line
	4450 6200 5050 6200
Wire Wire Line
	3750 5350 3750 6450
Connection ~ 3750 6200
Wire Wire Line
	3600 5350 3750 5350
Wire Wire Line
	1050 3150 3200 3150
Wire Wire Line
	2600 3250 2600 3150
Connection ~ 2600 3150
Wire Wire Line
	2600 3550 2600 4350
Wire Wire Line
	2600 3700 2650 3700
Wire Wire Line
	2950 3500 2950 3150
Connection ~ 2950 3150
Wire Wire Line
	2950 3900 3400 3900
Wire Wire Line
	3400 3450 3400 3950
Connection ~ 3400 3900
Wire Wire Line
	3400 4300 3400 4250
Wire Wire Line
	950  4550 1850 4550
Wire Wire Line
	2150 4550 2300 4550
Wire Wire Line
	1850 4250 1800 4250
Wire Wire Line
	1800 4250 1800 4550
Connection ~ 1800 4550
Wire Wire Line
	2150 4250 2200 4250
Wire Wire Line
	2200 4250 2200 4550
Connection ~ 2200 4550
Connection ~ 2600 3700
Wire Wire Line
	2600 4300 3400 4300
Wire Wire Line
	3750 4000 3850 4000
Connection ~ 2600 4300
Wire Wire Line
	4550 4250 4550 4000
Connection ~ 4550 4000
Wire Wire Line
	3750 4550 3750 4850
Wire Wire Line
	2600 4850 5800 4850
Wire Wire Line
	2600 4850 2600 4750
Wire Wire Line
	4550 4550 4550 4900
Connection ~ 3750 4850
Connection ~ 4550 4850
Wire Wire Line
	4450 4000 5050 4000
Wire Wire Line
	3750 3150 3750 4250
Connection ~ 3750 4000
Wire Wire Line
	3600 3150 3750 3150
Wire Wire Line
	2600 1100 2600 1200
Connection ~ 2600 1100
Wire Wire Line
	2600 1500 2600 2300
Wire Wire Line
	2600 1650 2650 1650
Wire Wire Line
	2950 1100 2950 1450
Connection ~ 2950 1100
Wire Wire Line
	2950 1850 3400 1850
Connection ~ 3400 1850
Wire Wire Line
	3400 2250 3400 2200
Wire Wire Line
	950  2500 1850 2500
Wire Wire Line
	2150 2500 2300 2500
Wire Wire Line
	1850 2200 1800 2200
Wire Wire Line
	1800 2200 1800 2500
Connection ~ 1800 2500
Wire Wire Line
	2150 2200 2200 2200
Wire Wire Line
	2200 2200 2200 2500
Connection ~ 2200 2500
Connection ~ 2600 1650
Wire Wire Line
	2600 2250 3400 2250
Wire Wire Line
	3750 1950 3850 1950
Connection ~ 2600 2250
Wire Wire Line
	4550 2200 4550 1950
Connection ~ 4550 1950
Wire Wire Line
	3750 2500 3750 2800
Wire Wire Line
	2600 2800 2600 2700
Wire Wire Line
	4550 2500 4550 2850
Connection ~ 3750 2800
Connection ~ 4550 2800
Wire Wire Line
	3750 1100 3750 2200
Connection ~ 3750 1950
Connection ~ 1050 1100
Connection ~ 1050 3150
Wire Wire Line
	1050 1100 1050 5350
Wire Wire Line
	2600 2800 5800 2800
Wire Wire Line
	4450 1950 5050 1950
Connection ~ 4950 1950
Wire Wire Line
	4950 1250 4950 1550
Wire Wire Line
	4950 1450 5050 1450
Wire Wire Line
	5350 1950 5800 1950
Wire Wire Line
	5350 1450 5800 1450
Connection ~ 5450 1950
Wire Wire Line
	4950 1250 5800 1250
Connection ~ 4950 1450
Text HLabel 5800 1450 2    60   Output ~ 0
OPAMP_R_N
Connection ~ 5450 1450
Wire Wire Line
	5350 4000 5800 4000
Wire Wire Line
	5000 3500 4900 3500
Wire Wire Line
	4900 3300 4900 3600
Wire Wire Line
	5300 3500 5800 3500
Connection ~ 5450 4000
Wire Wire Line
	5450 3500 5450 4000
Wire Wire Line
	4900 3900 4900 4000
Connection ~ 4900 4000
Wire Wire Line
	4950 1850 4950 1950
Wire Wire Line
	5450 1450 5450 1950
Wire Wire Line
	4900 3300 5800 3300
Connection ~ 4900 3500
Text HLabel 5800 3500 2    60   Output ~ 0
OPAMP_B_N
Connection ~ 5450 3500
Wire Wire Line
	5350 6200 5800 6200
Wire Wire Line
	5050 5700 4950 5700
Wire Wire Line
	4950 5500 4950 5800
Wire Wire Line
	4950 6100 4950 6200
Connection ~ 4950 6200
Wire Wire Line
	5350 5700 5800 5700
Wire Wire Line
	5450 5700 5450 6200
Connection ~ 5450 6200
Wire Wire Line
	2600 7050 5800 7050
Text HLabel 5800 5700 2    60   Output ~ 0
OPAMP_G_N
Connection ~ 5450 5700
Wire Wire Line
	5800 5500 4950 5500
Connection ~ 4950 5700
Wire Wire Line
	3600 1100 3750 1100
Wire Wire Line
	950  1100 3200 1100
Wire Wire Line
	3400 1400 3400 1900
$Comp
L MMBT3904 Q4
U 1 1 58A342A6
P 2850 1650
F 0 "Q4" H 3150 1700 50  0000 R CNN
F 1 "MMBT3904" H 3450 1600 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3050 1750 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2850 1650 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 2850 1650 60  0001 C CNN "Digikey"
	1    2850 1650
	1    0    0    -1  
$EndComp
$Comp
L MMBT3904 Q1
U 1 1 58A34880
P 2500 2500
F 0 "Q1" H 2800 2550 50  0000 R CNN
F 1 "MMBT3904" H 3100 2450 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2700 2600 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2500 2500 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 2500 2500 60  0001 C CNN "Digikey"
	1    2500 2500
	1    0    0    -1  
$EndComp
$Comp
L MMBT3904 Q5
U 1 1 58A34B4B
P 2850 3700
F 0 "Q5" H 3150 3750 50  0000 R CNN
F 1 "MMBT3904" H 3450 3650 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3050 3800 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2850 3700 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 2850 3700 60  0001 C CNN "Digikey"
	1    2850 3700
	1    0    0    -1  
$EndComp
$Comp
L MMBT3904 Q2
U 1 1 58A34E03
P 2500 4550
F 0 "Q2" H 2800 4600 50  0000 R CNN
F 1 "MMBT3904" H 3100 4500 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2700 4650 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2500 4550 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 2500 4550 60  0001 C CNN "Digikey"
	1    2500 4550
	1    0    0    -1  
$EndComp
$Comp
L MMBT3904 Q6
U 1 1 58A34FB5
P 2850 5900
F 0 "Q6" H 3150 5950 50  0000 R CNN
F 1 "MMBT3904" H 3450 5850 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3050 6000 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2850 5900 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 2850 5900 60  0001 C CNN "Digikey"
	1    2850 5900
	1    0    0    -1  
$EndComp
$Comp
L MMBT3904 Q3
U 1 1 58A35080
P 2500 6750
F 0 "Q3" H 2800 6800 50  0000 R CNN
F 1 "MMBT3904" H 3100 6700 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2700 6850 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2500 6750 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 2500 6750 60  0001 C CNN "Digikey"
	1    2500 6750
	1    0    0    -1  
$EndComp
$Comp
L DMG2305UX Q8
U 1 1 58A4969E
P 3400 3250
F 0 "Q8" V 3575 3450 50  0000 R CNN
F 1 "DMG2305UX" V 3375 3825 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3600 3350 50  0001 C CNN
F 3 "http://www.diodes.com/_files/datasheets/DMG2305UX.pdf" H 3400 3250 50  0001 C CNN
F 4 "-" H 3400 3250 60  0001 C CNN "Digikey"
	1    3400 3250
	0    1    -1   0   
$EndComp
$Comp
L DMG2305UX Q7
U 1 1 58A4A801
P 3400 1200
F 0 "Q7" V 3575 1400 50  0000 R CNN
F 1 "DMG2305UX" V 3375 1775 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3600 1300 50  0001 C CNN
F 3 "http://www.diodes.com/_files/datasheets/DMG2305UX.pdf" H 3400 1200 50  0001 C CNN
F 4 "-" H 3400 1200 60  0001 C CNN "Digikey"
	1    3400 1200
	0    1    -1   0   
$EndComp
$Comp
L DMG2305UX Q9
U 1 1 58A4AA57
P 3400 5450
F 0 "Q9" V 3575 5650 50  0000 R CNN
F 1 "DMG2305UX" V 3375 6025 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3600 5550 50  0001 C CNN
F 3 "http://www.diodes.com/_files/datasheets/DMG2305UX.pdf" H 3400 5450 50  0001 C CNN
F 4 "-" H 3400 5450 60  0001 C CNN "Digikey"
	1    3400 5450
	0    1    -1   0   
$EndComp
$EndSCHEMATC
