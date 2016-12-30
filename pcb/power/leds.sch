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
Sheet 4 5
Title "LEDs "
Date "2016-12-02"
Rev "1.0"
Comp "Uppsala University"
Comment1 "Project: SwakeUp"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 2656 3044 1044 1256
U 58430F64
F0 "LED Driver 3 Chan. " 60
F1 "rgbLedDriver.sch" 60
F2 "LED_G_P" O R 3700 4050 60 
F3 "LED_G_N" O R 3700 4150 60 
F4 "OPAMP_G" O R 3700 4250 60 
F5 "PWM_B" I L 2656 3700 60 
F6 "LED_B_P" O R 3700 3700 60 
F7 "LED_B_N" O R 3700 3800 60 
F8 "OPAMP_B" O R 3700 3900 60 
F9 "PWM_R" I L 2656 3300 60 
F10 "LED_R_P" O R 3700 3300 60 
F11 "LED_R_N" O R 3700 3400 60 
F12 "OPAMP_R" O R 3700 3500 60 
F13 "V20" I L 2656 3150 60 
F14 "PWM_G" I L 2656 4050 60 
$EndSheet
$Comp
L LM324QT U4
U 1 1 58430F92
P 6100 3700
F 0 "U4" H 6550 2850 60  0000 C CNN
F 1 "LM324QT" H 5800 2850 60  0000 C CNN
F 2 "Additional:QFN-16-1EP_3x3mm_Pitch0.5mm" H 6100 3700 60  0001 C CNN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/58/13/52/7e/39/8c/4c/ba/CD00000457.pdf/files/CD00000457.pdf/jcr:content/translations/en.CD00000457.pdf" H 6100 3700 60  0001 C CNN
F 4 "497-12005-1-ND" H 6100 3700 60  0001 C CNN "Digikey"
	1    6100 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR16
U 1 1 58430F99
P 4600 3200
F 0 "#PWR16" H 4600 2950 50  0001 C CNN
F 1 "GND" H 4600 3050 50  0000 C CNN
F 2 "" H 4600 3200 50  0000 C CNN
F 3 "" H 4600 3200 50  0000 C CNN
	1    4600 3200
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 58430FA0
P 5050 4300
F 0 "R9" V 5130 4300 50  0000 C CNN
F 1 "120k" V 5050 4300 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4980 4300 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5050 4300 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 5050 4300 60  0001 C CNN "Digikey"
	1    5050 4300
	0    1    1    0   
$EndComp
$Comp
L GND #PWR15
U 1 1 58430FA7
P 4450 4400
F 0 "#PWR15" H 4450 4150 50  0001 C CNN
F 1 "GND" H 4450 4250 50  0000 C CNN
F 2 "" H 4450 4400 50  0000 C CNN
F 3 "" H 4450 4400 50  0000 C CNN
	1    4450 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR19
U 1 1 58430FAD
P 7700 4350
F 0 "#PWR19" H 7700 4100 50  0001 C CNN
F 1 "GND" H 7700 4200 50  0000 C CNN
F 2 "" H 7700 4350 50  0000 C CNN
F 3 "" H 7700 4350 50  0000 C CNN
	1    7700 4350
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 58430FBC
P 7100 3100
F 0 "R12" V 7180 3100 50  0000 C CNN
F 1 "240k" V 7100 3100 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7030 3100 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7100 3100 50  0001 C CNN
F 4 "311-240KHRCT-ND" V 7100 3100 60  0001 C CNN "Digikey"
	1    7100 3100
	0    1    1    0   
$EndComp
$Comp
L R R16
U 1 1 58430FC4
P 7600 3100
F 0 "R16" V 7680 3100 50  0000 C CNN
F 1 "39k" V 7600 3100 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7530 3100 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7600 3100 50  0001 C CNN
F 4 "311-39.0KHRCT-ND" V 7600 3100 60  0001 C CNN "Digikey"
	1    7600 3100
	0    1    1    0   
$EndComp
$Comp
L GND #PWR20
U 1 1 58430FCB
P 7750 3400
F 0 "#PWR20" H 7750 3150 50  0001 C CNN
F 1 "GND" H 7750 3250 50  0000 C CNN
F 2 "" H 7750 3400 50  0000 C CNN
F 3 "" H 7750 3400 50  0000 C CNN
	1    7750 3400
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 58430FD2
P 8100 3650
F 0 "R18" V 8180 3650 50  0000 C CNN
F 1 "47k" V 8100 3650 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8030 3650 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8100 3650 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 8100 3650 60  0001 C CNN "Digikey"
	1    8100 3650
	0    1    1    0   
$EndComp
$Comp
L C C9
U 1 1 58430FDA
P 8300 3900
F 0 "C9" H 8325 4000 50  0000 L CNN
F 1 "10n" H 8325 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8338 3750 50  0001 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 8300 3900 50  0001 C CNN
F 4 "311-1085-1-ND" H 8300 3900 60  0001 C CNN "Digikey"
	1    8300 3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR22
U 1 1 58430FE1
P 9100 4150
F 0 "#PWR22" H 9100 3900 50  0001 C CNN
F 1 "GND" H 9100 4000 50  0000 C CNN
F 2 "" H 9100 4150 50  0000 C CNN
F 3 "" H 9100 4150 50  0000 C CNN
	1    9100 4150
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 58430FE8
P 4750 3100
F 0 "R8" V 4830 3100 50  0000 C CNN
F 1 "3.9k" V 4750 3100 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4680 3100 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4750 3100 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 4750 3100 60  0001 C CNN "Digikey"
	1    4750 3100
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 58430FF0
P 5150 3100
F 0 "R10" V 5230 3100 50  0000 C CNN
F 1 "120k" V 5150 3100 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5080 3100 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5150 3100 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 5150 3100 60  0001 C CNN "Digikey"
	1    5150 3100
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 58430FF8
P 7100 4300
F 0 "R13" V 7180 4300 50  0000 C CNN
F 1 "120k" V 7100 4300 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7030 4300 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7100 4300 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 7100 4300 60  0001 C CNN "Digikey"
	1    7100 4300
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 58431000
P 4600 4300
F 0 "R7" V 4680 4300 50  0000 C CNN
F 1 "3.9k" V 4600 4300 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 4530 4300 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4600 4300 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 4600 4300 60  0001 C CNN "Digikey"
	1    4600 4300
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 58431008
P 7550 4300
F 0 "R14" V 7630 4300 50  0000 C CNN
F 1 "3.9k" V 7550 4300 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7480 4300 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7550 4300 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 7550 4300 60  0001 C CNN "Digikey"
	1    7550 4300
	0    1    1    0   
$EndComp
$Comp
L R R19
U 1 1 58431010
P 8500 3650
F 0 "R19" V 8580 3650 50  0000 C CNN
F 1 "47k" V 8500 3650 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8430 3650 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8500 3650 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 8500 3650 60  0001 C CNN "Digikey"
	1    8500 3650
	0    1    1    0   
$EndComp
$Comp
L R R20
U 1 1 58431018
P 8900 3650
F 0 "R20" V 8980 3650 50  0000 C CNN
F 1 "47k" V 8900 3650 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8830 3650 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8900 3650 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 8900 3650 60  0001 C CNN "Digikey"
	1    8900 3650
	0    1    1    0   
$EndComp
$Comp
L C C10
U 1 1 58431020
P 8700 3900
F 0 "C10" H 8725 4000 50  0000 L CNN
F 1 "10n" H 8725 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8738 3750 50  0001 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 8700 3900 50  0001 C CNN
F 4 "311-1085-1-ND" H 8700 3900 60  0001 C CNN "Digikey"
	1    8700 3900
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 58431029
P 9100 3900
F 0 "C11" H 9125 4000 50  0000 L CNN
F 1 "10n" H 9125 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9138 3750 50  0001 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 9100 3900 50  0001 C CNN
F 4 "311-1085-1-ND" H 9100 3900 60  0001 C CNN "Digikey"
	1    9100 3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR18
U 1 1 58431031
P 7000 3700
F 0 "#PWR18" H 7000 3450 50  0001 C CNN
F 1 "GND" H 7000 3550 50  0000 C CNN
F 2 "" H 7000 3700 50  0000 C CNN
F 3 "" H 7000 3700 50  0000 C CNN
	1    7000 3700
	1    0    0    -1  
$EndComp
Text Notes 8300 4950 0    60   ~ 0
Non-Invert. Amp.\n-----------------------\nA=(240k + 39k)/39k =7.154\nVin,max=2.8 V\nVout,max=20.031V
Text Notes 4400 5250 0    60   ~ 0
Non-Inv. Amp.\n-----------------------\nA=(3.9k+120k)/3.9k =31.769\nVin,max=30 mV\nVout,max=953.077 mV\nVref = 1.0 V
$Comp
L R R11
U 1 1 5843103A
P 7100 2500
F 0 "R11" V 7180 2500 50  0000 C CNN
F 1 "120k" V 7100 2500 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7030 2500 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7100 2500 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 7100 2500 60  0001 C CNN "Digikey"
	1    7100 2500
	0    1    1    0   
$EndComp
$Comp
L R R15
U 1 1 58431042
P 7600 2500
F 0 "R15" V 7680 2500 50  0000 C CNN
F 1 "2.7k" V 7600 2500 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7530 2500 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7600 2500 50  0001 C CNN
F 4 "311-2.70KHRCT-ND" V 7600 2500 60  0001 C CNN "Digikey"
	1    7600 2500
	0    1    1    0   
$EndComp
$Comp
L R R17
U 1 1 5843104A
P 7950 2500
F 0 "R17" V 8030 2500 50  0000 C CNN
F 1 "3.3k" V 7950 2500 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7880 2500 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7950 2500 50  0001 C CNN
F 4 "311-3.30KHRCT-ND" V 7950 2500 60  0001 C CNN "Digikey"
	1    7950 2500
	0    1    1    0   
$EndComp
$Comp
L GND #PWR21
U 1 1 58431051
P 8100 2900
F 0 "#PWR21" H 8100 2650 50  0001 C CNN
F 1 "GND" H 8100 2750 50  0000 C CNN
F 2 "" H 8100 2900 50  0000 C CNN
F 3 "" H 8100 2900 50  0000 C CNN
	1    8100 2900
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 58431061
P 7400 2700
F 0 "C8" H 7425 2800 50  0000 L CNN
F 1 "10u" H 7425 2600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7438 2550 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 7400 2700 50  0001 C CNN
F 4 "490-12323-1-ND" H 7400 2700 60  0001 C CNN "Digikey"
	1    7400 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 3100 4600 3200
Wire Wire Line
	4450 4300 4450 4400
Wire Wire Line
	7700 4300 7700 4350
Wire Wire Line
	3850 2700 3850 3300
Wire Wire Line
	3850 3300 3700 3300
Wire Wire Line
	3700 3700 3950 3700
Wire Wire Line
	3950 3700 3950 2700
Wire Wire Line
	3700 4050 4050 4050
Wire Wire Line
	4050 4050 4050 2700
Wire Wire Line
	4150 4150 3700 4150
Wire Wire Line
	4150 3800 3700 3800
Connection ~ 4150 3800
Wire Wire Line
	4300 2900 4300 4250
Wire Wire Line
	7850 2900 7850 3900
Wire Wire Line
	7750 3100 7750 3400
Wire Wire Line
	8250 3650 8350 3650
Wire Wire Line
	8650 3650 8750 3650
Wire Wire Line
	8300 4100 9100 4100
Wire Wire Line
	8300 4100 8300 4050
Connection ~ 9100 4100
Wire Wire Line
	8700 4050 8700 4100
Connection ~ 8700 4100
Wire Wire Line
	8300 3750 8300 3650
Connection ~ 8300 3650
Wire Wire Line
	8700 3750 8700 3650
Connection ~ 8700 3650
Wire Wire Line
	7250 3650 7950 3650
Wire Wire Line
	9100 4050 9100 4150
Wire Wire Line
	9100 3750 9100 3650
Wire Wire Line
	9050 3650 9250 3650
Connection ~ 9100 3650
Wire Wire Line
	3700 3400 4150 3400
Connection ~ 4150 3400
Wire Wire Line
	4150 2700 4150 4150
Wire Wire Line
	7850 3900 6800 3900
Wire Wire Line
	6800 3700 7000 3700
Wire Wire Line
	7250 3500 6800 3500
Wire Wire Line
	6800 3300 7350 3300
Wire Wire Line
	7250 2500 7450 2500
Wire Wire Line
	7750 2500 7800 2500
Wire Wire Line
	8100 2500 8100 2900
Wire Wire Line
	2656 3300 2500 3300
Wire Wire Line
	2656 3700 2500 3700
Wire Wire Line
	2500 4050 2656 4050
Wire Wire Line
	2656 3150 2350 3150
Wire Wire Line
	7250 3100 7450 3100
Wire Wire Line
	7350 3300 7350 3100
Connection ~ 7350 3100
Wire Wire Line
	6800 3100 6950 3100
Wire Wire Line
	6950 2500 6900 2500
Wire Wire Line
	6900 2150 6900 3100
Connection ~ 6900 3100
Wire Wire Line
	7250 3500 7250 3650
Wire Wire Line
	6800 4300 6950 4300
Wire Wire Line
	7050 4500 6850 4500
Wire Wire Line
	6850 4500 6850 4300
Connection ~ 6850 4300
Wire Wire Line
	5200 4300 5400 4300
Wire Wire Line
	7250 4300 7400 4300
Wire Wire Line
	6800 4100 7350 4100
Wire Wire Line
	7350 4100 7350 4300
Connection ~ 7350 4300
Wire Wire Line
	4800 4300 4800 4100
Wire Wire Line
	4800 4100 5400 4100
Connection ~ 4800 4300
Wire Wire Line
	4750 4300 4900 4300
Wire Wire Line
	5100 4500 5300 4500
Wire Wire Line
	5300 4500 5300 4300
Connection ~ 5300 4300
Wire Wire Line
	4300 2900 7850 2900
Wire Wire Line
	4950 3300 5400 3300
Wire Wire Line
	5300 3100 5400 3100
Wire Wire Line
	4900 3100 5000 3100
Wire Wire Line
	4950 3100 4950 3300
Connection ~ 4950 3100
Wire Wire Line
	5350 3100 5350 2700
Connection ~ 5350 3100
Wire Wire Line
	5350 2700 5150 2700
Connection ~ 6900 2500
Wire Wire Line
	7450 2150 6900 2150
Wire Wire Line
	3700 3900 5400 3900
Wire Wire Line
	3700 3500 5400 3500
Wire Wire Line
	4300 4250 3700 4250
Wire Wire Line
	7250 2700 6900 2700
Connection ~ 8100 2700
Connection ~ 6900 2700
Wire Wire Line
	7550 2700 8100 2700
Wire Wire Line
	7450 2350 7350 2350
Wire Wire Line
	7350 2350 7350 2500
Connection ~ 7350 2500
Text Notes 6900 1950 0    60   ~ 0
Voltage Divider\n-----------------------\nA=6k/120k = 20\nVin,max=20 V\nVout,max=1 V (reference of ADC)
Text Notes 3800 2300 0    60   ~ 0
LED
Text HLabel 2350 3150 0    60   Input ~ 0
V20
Text HLabel 2500 3300 0    60   Input ~ 0
PWM_R
Text HLabel 2500 3700 0    60   Input ~ 0
PWM_B
Text HLabel 2500 4050 0    60   Input ~ 0
PWM_G
Text HLabel 5150 2700 0    60   Output ~ 0
ADC_R
Text HLabel 5150 3800 0    60   Input ~ 0
V20
Text HLabel 5100 4500 0    60   Output ~ 0
ADC_B
Text HLabel 7050 4500 2    60   Output ~ 0
ADC_G
Text HLabel 9250 3650 2    60   Input ~ 0
PWM_OLED
Text HLabel 7450 2350 2    60   Output ~ 0
ADC_OLED
Text HLabel 7450 2150 2    60   Output ~ 0
VOLED
Text HLabel 3850 2700 1    60   Output ~ 0
LED_R
Text HLabel 3950 2700 1    60   Output ~ 0
LED_B
Text HLabel 4050 2700 1    60   Output ~ 0
LED_G
Text HLabel 4150 2700 1    60   Output ~ 0
LED_GND
$Comp
L C C21
U 1 1 584CBAE2
P 5100 3600
F 0 "C21" V 5150 3650 50  0000 L CNN
F 1 "2.2u" V 5150 3350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5138 3450 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/partnumbering_e_01.pdf" H 5100 3600 50  0001 C CNN
F 4 "490-7204-1-ND" H 5100 3600 60  0001 C CNN "Digikey"
	1    5100 3600
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR17
U 1 1 584CCA77
P 4700 3650
F 0 "#PWR17" H 4700 3400 50  0001 C CNN
F 1 "GND" H 4700 3500 50  0000 C CNN
F 2 "" H 4700 3650 50  0000 C CNN
F 3 "" H 4700 3650 50  0000 C CNN
	1    4700 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3700 5300 3700
Wire Wire Line
	5300 3600 5300 3800
Wire Wire Line
	5300 3600 5250 3600
Connection ~ 5300 3700
Wire Wire Line
	4700 3650 4700 3600
Wire Wire Line
	4700 3600 4950 3600
Wire Wire Line
	5300 3800 5150 3800
$EndSCHEMATC
