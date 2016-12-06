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
Date "2016-12-02"
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
Text HLabel 5800 6350 2    60   Output ~ 0
LED_G_N
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
	2600 7050 5600 7050
Wire Wire Line
	2600 7050 2600 6950
Wire Wire Line
	4550 7050 4550 6750
Connection ~ 3750 7050
Connection ~ 4550 7050
Wire Wire Line
	4850 7000 4850 7100
Wire Wire Line
	4450 6200 5800 6200
Wire Wire Line
	3750 5350 3750 6450
Connection ~ 3750 6200
Wire Wire Line
	3600 5350 3750 5350
Wire Wire Line
	5800 6350 4850 6350
Wire Wire Line
	4850 6350 4850 6700
Wire Wire Line
	5100 6650 4850 6650
Connection ~ 4850 6650
Wire Wire Line
	5400 6650 5800 6650
Wire Wire Line
	5600 6650 5600 6700
Connection ~ 4850 7050
Wire Wire Line
	5600 7050 5600 7000
Text HLabel 5800 6650 2    60   Output ~ 0
OPAMP_G
Connection ~ 5600 6650
Text HLabel 950  4550 0    60   Input ~ 0
PWM_B
Text HLabel 5800 4000 2    60   Output ~ 0
LED_B_P
Text HLabel 5800 4150 2    60   Output ~ 0
LED_B_N
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
	2600 4850 5600 4850
Wire Wire Line
	2600 4850 2600 4750
Wire Wire Line
	4550 4850 4550 4550
Connection ~ 3750 4850
Connection ~ 4550 4850
Wire Wire Line
	4850 4800 4850 4900
Wire Wire Line
	4450 4000 5800 4000
Wire Wire Line
	3750 3150 3750 4250
Connection ~ 3750 4000
Wire Wire Line
	3600 3150 3750 3150
Wire Wire Line
	5800 4150 4850 4150
Wire Wire Line
	4850 4150 4850 4500
Wire Wire Line
	5100 4450 4850 4450
Connection ~ 4850 4450
Wire Wire Line
	5400 4450 5800 4450
Wire Wire Line
	5600 4450 5600 4500
Connection ~ 4850 4850
Wire Wire Line
	5600 4850 5600 4800
Text HLabel 5800 4450 2    60   Output ~ 0
OPAMP_B
Connection ~ 5600 4450
$Comp
L Q_PMOS_DGS Q7
U 1 1 5837C3F4
P 3400 1200
F 0 "Q7" V 3600 1100 50  0000 R CNN
F 1 "DMG2305UX" V 3350 1100 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 3600 1300 50  0001 C CNN
F 3 "http://www.diodes.com/_files/datasheets/DMG2305UX.pdf" H 3400 1200 50  0001 C CNN
F 4 "DMG2305UX-13DICT-ND" H 3400 1200 60  0001 C CNN "Digikey"
	1    3400 1200
	0    -1   -1   0   
$EndComp
$Comp
L R R24
U 1 1 5837C403
P 2600 1350
F 0 "R24" V 2680 1350 50  0000 C CNN
F 1 "10k" V 2600 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2530 1350 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1930 2500 50  0001 C CNN
F 3 "https://industrial.panasonic.com/cdbs/www-data/pdf/RDA0000/AOA0000COL70.pdf" H 2000 2500 50  0001 C CNN
F 4 "P20245CT-ND" V 2000 2500 60  0001 C CNN "Digikey"
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
F 3 "http://www.vishay.com/docs/88869/packaging.pdf" H 3750 2350 50  0001 C CNN
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
Text HLabel 5800 2100 2    60   Output ~ 0
LED_R_N
$Comp
L R R27
U 1 1 5837C430
P 4850 2600
F 0 "R27" V 4930 2600 50  0000 C CNN
F 1 "0.1R" V 4850 2600 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" V 4780 2600 50  0001 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RU_Series_ds.pdf" H 4850 2600 50  0001 C CNN
F 4 "1276-6155-1-ND" V 4850 2600 60  0001 C CNN "Digikey"
	1    4850 2600
	1    0    0    -1  
$EndComp
$Comp
L C C18
U 1 1 5837C437
P 5600 2600
F 0 "C18" H 5625 2700 50  0000 L CNN
F 1 "22n" H 5625 2500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5638 2450 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 5600 2600 50  0001 C CNN
F 4 "445-8118-1-ND" H 5600 2600 60  0001 C CNN "Digikey"
	1    5600 2600
	-1   0    0    1   
$EndComp
$Comp
L R R30
U 1 1 5837C43E
P 5250 2400
F 0 "R30" V 5330 2400 50  0000 C CNN
F 1 "4.7k" V 5250 2400 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5180 2400 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5250 2400 50  0001 C CNN
F 4 "311-4.7KGRCT-ND" V 5250 2400 60  0001 C CNN "Digikey"
	1    5250 2400
	0    1    1    0   
$EndComp
Wire Wire Line
	950  1100 3200 1100
Wire Wire Line
	2600 1200 2600 1100
Connection ~ 2600 1100
Wire Wire Line
	2600 1500 2600 2300
Wire Wire Line
	2600 1650 2650 1650
Wire Wire Line
	2950 1450 2950 1100
Connection ~ 2950 1100
Wire Wire Line
	2950 1850 3400 1850
Wire Wire Line
	3400 1400 3400 1900
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
	2600 2800 5600 2800
Wire Wire Line
	2600 2800 2600 2700
Wire Wire Line
	4550 2800 4550 2500
Connection ~ 3750 2800
Connection ~ 4550 2800
Wire Wire Line
	4850 2750 4850 2850
Wire Wire Line
	4450 1950 5800 1950
Wire Wire Line
	3750 1100 3750 2200
Connection ~ 3750 1950
Wire Wire Line
	3600 1100 3750 1100
Wire Wire Line
	5800 2100 4850 2100
Wire Wire Line
	4850 2100 4850 2450
Wire Wire Line
	5100 2400 4850 2400
Connection ~ 4850 2400
Wire Wire Line
	5400 2400 5800 2400
Wire Wire Line
	5600 2400 5600 2450
Connection ~ 4850 2800
Wire Wire Line
	5600 2800 5600 2750
Text HLabel 5800 2400 2    60   Output ~ 0
OPAMP_R
Connection ~ 5600 2400
Connection ~ 1050 1100
Text HLabel 950  1100 0    60   Input ~ 0
V20
Connection ~ 1050 3150
Wire Wire Line
	1050 1100 1050 5350
Text Notes 5850 2800 0    60   ~ 0
Low-Pass Filter\n-----------------------\nfcutt,off=1.539 kHz\nfsample=4 kHz
$Comp
L D D6
U 1 1 583CC52C
P 3400 2050
F 0 "D6" V 3450 1900 50  0000 C CNN
F 1 "1N4148WFL-G" V 3350 1700 50  0000 C CNN
F 2 "Additional:SOD-123F" H 3400 2050 50  0001 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Vishay%20Semiconductors/1N4148WFL-G.pdf" H 3400 2050 50  0001 C CNN
F 4 "1N4148WFL-G3-08GITR-ND" V 3350 1300 60  0001 C CNN "Digikey"
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
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1930 4550 50  0001 C CNN
F 3 "https://industrial.panasonic.com/cdbs/www-data/pdf/RDA0000/AOA0000COL70.pdf" H 2000 4550 50  0001 C CNN
F 4 "P20245CT-ND" V 2000 4550 60  0001 C CNN "Digikey"
	1    2000 4550
	0    1    1    0   
$EndComp
$Comp
L R R23
U 1 1 58417E43
P 2000 6750
F 0 "R23" V 2080 6750 50  0000 C CNN
F 1 "470R" V 2000 6750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1930 6750 50  0001 C CNN
F 3 "https://industrial.panasonic.com/cdbs/www-data/pdf/RDA0000/AOA0000COL70.pdf" H 2000 6750 50  0001 C CNN
F 4 "P20245CT-ND" V 2000 6750 60  0001 C CNN "Digikey"
	1    2000 6750
	0    1    1    0   
$EndComp
$Comp
L R R26
U 1 1 58418FF7
P 2600 5600
F 0 "R26" V 2680 5600 50  0000 C CNN
F 1 "10k" V 2600 5600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2530 5600 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2530 3400 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 2600 3400 50  0001 C CNN
F 4 "311-10KGRCT-ND" V 2600 3400 60  0001 C CNN "Digikey"
	1    2600 3400
	-1   0    0    1   
$EndComp
$Comp
L Q_PMOS_DGS Q8
U 1 1 5841A28D
P 3400 3250
F 0 "Q8" V 3600 3150 50  0000 R CNN
F 1 "DMG2305UX" V 3350 3150 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 3600 3350 50  0001 C CNN
F 3 "http://www.diodes.com/_files/datasheets/DMG2305UX.pdf" H 3400 3250 50  0001 C CNN
F 4 "DMG2305UX-13DICT-ND" H 3400 3250 60  0001 C CNN "Digikey"
	1    3400 3250
	0    -1   -1   0   
$EndComp
$Comp
L Q_PMOS_DGS Q9
U 1 1 5841A571
P 3400 5450
F 0 "Q9" V 3600 5350 50  0000 R CNN
F 1 "DMG2305UX" V 3350 5350 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 3600 5550 50  0001 C CNN
F 3 "http://www.diodes.com/_files/datasheets/DMG2305UX.pdf" H 3400 5450 50  0001 C CNN
F 4 "DMG2305UX-13DICT-ND" H 3400 5450 60  0001 C CNN "Digikey"
	1    3400 5450
	0    -1   -1   0   
$EndComp
$Comp
L Q_NPN_BCE Q4
U 1 1 5837C3ED
P 2850 1650
F 0 "Q4" H 3100 1750 50  0000 R CNN
F 1 "MMBT3904" H 3400 1550 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 3050 1750 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2850 1650 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3550 1600 60  0001 C CNN "Digikey"
	1    2850 1650
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q5
U 1 1 5841AE74
P 2850 3700
F 0 "Q5" H 3100 3800 50  0000 R CNN
F 1 "MMBT3904" H 3400 3600 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 3050 3800 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2850 3700 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3550 3650 60  0001 C CNN "Digikey"
	1    2850 3700
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q6
U 1 1 5841B110
P 2850 5900
F 0 "Q6" H 3100 6000 50  0000 R CNN
F 1 "MMBT3904" H 3400 5800 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 3050 6000 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2850 5900 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3550 5850 60  0001 C CNN "Digikey"
	1    2850 5900
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q1
U 1 1 5841C01A
P 2500 2500
F 0 "Q1" H 2750 2600 50  0000 R CNN
F 1 "MMBT3904" H 3050 2400 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 2700 2600 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2500 2500 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3200 2450 60  0001 C CNN "Digikey"
	1    2500 2500
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q2
U 1 1 5841C212
P 2500 4550
F 0 "Q2" H 2750 4650 50  0000 R CNN
F 1 "MMBT3904" H 3050 4450 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 2700 4650 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2500 4550 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3200 4500 60  0001 C CNN "Digikey"
	1    2500 4550
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q3
U 1 1 5841C4C0
P 2500 6750
F 0 "Q3" H 2750 6850 50  0000 R CNN
F 1 "MMBT3904" H 3050 6650 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 2700 6850 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2500 6750 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3200 6700 60  0001 C CNN "Digikey"
	1    2500 6750
	1    0    0    -1  
$EndComp
$Comp
L D D7
U 1 1 5841D6DF
P 3400 4100
F 0 "D7" V 3450 3950 50  0000 C CNN
F 1 "1N4148WFL-G" V 3350 3750 50  0000 C CNN
F 2 "Additional:SOD-123F" H 3400 4100 50  0001 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Vishay%20Semiconductors/1N4148WFL-G.pdf" H 3400 4100 50  0001 C CNN
F 4 "1N4148WFL-G3-08GITR-ND" V 3350 3350 60  0001 C CNN "Digikey"
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
F 4 "1N4148WFL-G3-08GITR-ND" V 3350 5550 60  0001 C CNN "Digikey"
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
P 4850 4650
F 0 "R28" V 4930 4650 50  0000 C CNN
F 1 "0.1R" V 4850 4650 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" V 4780 4650 50  0001 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RU_Series_ds.pdf" H 4850 4650 50  0001 C CNN
F 4 "1276-6155-1-ND" V 4850 4650 60  0001 C CNN "Digikey"
	1    4850 4650
	1    0    0    -1  
$EndComp
$Comp
L R R29
U 1 1 58425F29
P 4850 6850
F 0 "R29" V 4930 6850 50  0000 C CNN
F 1 "0.1R" V 4850 6850 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" V 4780 6850 50  0001 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RU_Series_ds.pdf" H 4850 6850 50  0001 C CNN
F 4 "1276-6155-1-ND" V 4850 6850 60  0001 C CNN "Digikey"
	1    4850 6850
	1    0    0    -1  
$EndComp
$Comp
L R R32
U 1 1 58426A19
P 5250 6650
F 0 "R32" V 5330 6650 50  0000 C CNN
F 1 "4.7k" V 5250 6650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5180 6650 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5250 6650 50  0001 C CNN
F 4 "311-4.7KGRCT-ND" V 5250 6650 60  0001 C CNN "Digikey"
	1    5250 6650
	0    1    1    0   
$EndComp
$Comp
L R R31
U 1 1 58426AE7
P 5250 4450
F 0 "R31" V 5330 4450 50  0000 C CNN
F 1 "4.7k" V 5250 4450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5180 4450 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5250 4450 50  0001 C CNN
F 4 "311-4.7KGRCT-ND" V 5250 4450 60  0001 C CNN "Digikey"
	1    5250 4450
	0    1    1    0   
$EndComp
$Comp
L C C19
U 1 1 584270BF
P 5600 4650
F 0 "C19" H 5625 4750 50  0000 L CNN
F 1 "22n" H 5625 4550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5638 4500 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 5600 4650 50  0001 C CNN
F 4 "445-8118-1-ND" H 5600 4650 60  0001 C CNN "Digikey"
	1    5600 4650
	-1   0    0    1   
$EndComp
$Comp
L C C20
U 1 1 58427309
P 5600 6850
F 0 "C20" H 5625 6950 50  0000 L CNN
F 1 "22n" H 5625 6750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5638 6700 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 5600 6850 50  0001 C CNN
F 4 "445-8118-1-ND" H 5600 6850 60  0001 C CNN "Digikey"
	1    5600 6850
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR022
U 1 1 584185EC
P 4850 2850
F 0 "#PWR022" H 4850 2600 50  0001 C CNN
F 1 "GND" H 4850 2700 50  0000 C CNN
F 2 "" H 4850 2850 50  0000 C CNN
F 3 "" H 4850 2850 50  0000 C CNN
	1    4850 2850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR023
U 1 1 584188BC
P 4850 7100
F 0 "#PWR023" H 4850 6850 50  0001 C CNN
F 1 "GND" H 4850 6950 50  0000 C CNN
F 2 "" H 4850 7100 50  0000 C CNN
F 3 "" H 4850 7100 50  0000 C CNN
	1    4850 7100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 58418AC2
P 4850 4900
F 0 "#PWR024" H 4850 4650 50  0001 C CNN
F 1 "GND" H 4850 4750 50  0000 C CNN
F 2 "" H 4850 4900 50  0000 C CNN
F 3 "" H 4850 4900 50  0000 C CNN
	1    4850 4900
	1    0    0    -1  
$EndComp
$EndSCHEMATC
