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
Date "2016-12-30"
Rev "1.0"
Comp "Uppsala University"
Comment1 "Project: SwakeUp"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LM324QT U4
U 1 1 58430F92
P 7000 3675
F 0 "U4" H 7450 2825 60  0000 C CNN
F 1 "LM324QT" H 6700 2825 60  0000 C CNN
F 2 "Additional:QFN-16-1EP_3x3mm_Pitch0.5mm" H 7000 3675 60  0001 C CNN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/58/13/52/7e/39/8c/4c/ba/CD00000457.pdf/files/CD00000457.pdf/jcr:content/translations/en.CD00000457.pdf" H 7000 3675 60  0001 C CNN
F 4 "497-12005-1-ND" H 7000 3675 60  0001 C CNN "Digikey"
	1    7000 3675
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 58430FA0
P 5950 4275
F 0 "R9" V 6030 4275 50  0000 C CNN
F 1 "120k" V 5950 4275 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5880 4275 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5950 4275 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 5950 4275 60  0001 C CNN "Digikey"
	1    5950 4275
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 58430FBC
P 8000 3075
F 0 "R12" V 8080 3075 50  0000 C CNN
F 1 "240k" V 8000 3075 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7930 3075 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8000 3075 50  0001 C CNN
F 4 "311-240KHRCT-ND" V 8000 3075 60  0001 C CNN "Digikey"
	1    8000 3075
	0    1    1    0   
$EndComp
$Comp
L R R16
U 1 1 58430FC4
P 8500 3075
F 0 "R16" V 8580 3075 50  0000 C CNN
F 1 "39k" V 8500 3075 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8430 3075 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8500 3075 50  0001 C CNN
F 4 "311-39.0KHRCT-ND" V 8500 3075 60  0001 C CNN "Digikey"
	1    8500 3075
	0    1    1    0   
$EndComp
$Comp
L GND #PWR19
U 1 1 58430FCB
P 8700 3125
F 0 "#PWR19" H 8700 2875 50  0001 C CNN
F 1 "GND" H 8700 2975 50  0000 C CNN
F 2 "" H 8700 3125 50  0000 C CNN
F 3 "" H 8700 3125 50  0000 C CNN
	1    8700 3125
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 58430FD2
P 9250 3475
F 0 "R18" V 9330 3475 50  0000 C CNN
F 1 "47k" V 9250 3475 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 9180 3475 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 9250 3475 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 9250 3475 60  0001 C CNN "Digikey"
	1    9250 3475
	0    1    1    0   
$EndComp
$Comp
L C C9
U 1 1 58430FDA
P 9450 3725
F 0 "C9" H 9475 3825 50  0000 L CNN
F 1 "10n" H 9475 3625 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9488 3575 50  0001 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 9450 3725 50  0001 C CNN
F 4 "311-1085-1-ND" H 9450 3725 60  0001 C CNN "Digikey"
	1    9450 3725
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR21
U 1 1 58430FE1
P 10250 3975
F 0 "#PWR21" H 10250 3725 50  0001 C CNN
F 1 "GND" H 10250 3825 50  0000 C CNN
F 2 "" H 10250 3975 50  0000 C CNN
F 3 "" H 10250 3975 50  0000 C CNN
	1    10250 3975
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 58430FE8
P 5500 3075
F 0 "R8" V 5580 3075 50  0000 C CNN
F 1 "3.9k" V 5500 3075 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5430 3075 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5500 3075 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 5500 3075 60  0001 C CNN "Digikey"
	1    5500 3075
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 58430FF0
P 5900 3075
F 0 "R10" V 5980 3075 50  0000 C CNN
F 1 "120k" V 5900 3075 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5830 3075 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5900 3075 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 5900 3075 60  0001 C CNN "Digikey"
	1    5900 3075
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 58430FF8
P 8000 4275
F 0 "R13" V 8080 4275 50  0000 C CNN
F 1 "120k" V 8000 4275 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7930 4275 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8000 4275 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 8000 4275 60  0001 C CNN "Digikey"
	1    8000 4275
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 58431000
P 5500 4275
F 0 "R7" V 5580 4275 50  0000 C CNN
F 1 "3.9k" V 5500 4275 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5430 4275 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5500 4275 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 5500 4275 60  0001 C CNN "Digikey"
	1    5500 4275
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 58431008
P 8500 4275
F 0 "R14" V 8580 4275 50  0000 C CNN
F 1 "3.9k" V 8500 4275 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8430 4275 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8500 4275 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 8500 4275 60  0001 C CNN "Digikey"
	1    8500 4275
	0    1    1    0   
$EndComp
$Comp
L R R19
U 1 1 58431010
P 9650 3475
F 0 "R19" V 9730 3475 50  0000 C CNN
F 1 "47k" V 9650 3475 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 9580 3475 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 9650 3475 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 9650 3475 60  0001 C CNN "Digikey"
	1    9650 3475
	0    1    1    0   
$EndComp
$Comp
L R R20
U 1 1 58431018
P 10050 3475
F 0 "R20" V 10130 3475 50  0000 C CNN
F 1 "47k" V 10050 3475 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 9980 3475 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 10050 3475 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 10050 3475 60  0001 C CNN "Digikey"
	1    10050 3475
	0    1    1    0   
$EndComp
$Comp
L C C10
U 1 1 58431020
P 9850 3725
F 0 "C10" H 9875 3825 50  0000 L CNN
F 1 "10n" H 9875 3625 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9888 3575 50  0001 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 9850 3725 50  0001 C CNN
F 4 "311-1085-1-ND" H 9850 3725 60  0001 C CNN "Digikey"
	1    9850 3725
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 58431029
P 10250 3725
F 0 "C11" H 10275 3825 50  0000 L CNN
F 1 "10n" H 10275 3625 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 10288 3575 50  0001 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 10250 3725 50  0001 C CNN
F 4 "311-1085-1-ND" H 10250 3725 60  0001 C CNN "Digikey"
	1    10250 3725
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR17
U 1 1 58431031
P 7800 3675
F 0 "#PWR17" H 7800 3425 50  0001 C CNN
F 1 "GND" H 7800 3525 50  0000 C CNN
F 2 "" H 7800 3675 50  0000 C CNN
F 3 "" H 7800 3675 50  0000 C CNN
	1    7800 3675
	1    0    0    -1  
$EndComp
Text Notes 9350 3300 0    60   ~ 0
Non-Invert. Amp.\n-----------------------\nA=(240k + 39k)/39k =7.154\nVin,max=2.8 V\nVout,max=20.031V
Text Notes 4750 5075 0    60   ~ 0
Differential Amp.\n-----------------------\nA=(3.9k+120k)/3.9k =31.769\nVin,max=30 mV\nVout,max=953.077 mV\nVref = 1.0 V
$Comp
L R R11
U 1 1 5843103A
P 8000 2475
F 0 "R11" V 8080 2475 50  0000 C CNN
F 1 "120k" V 8000 2475 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7930 2475 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8000 2475 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 8000 2475 60  0001 C CNN "Digikey"
	1    8000 2475
	0    1    1    0   
$EndComp
$Comp
L R R15
U 1 1 58431042
P 8500 2475
F 0 "R15" V 8580 2475 50  0000 C CNN
F 1 "2.7k" V 8500 2475 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8430 2475 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8500 2475 50  0001 C CNN
F 4 "311-2.70KHRCT-ND" V 8500 2475 60  0001 C CNN "Digikey"
	1    8500 2475
	0    1    1    0   
$EndComp
$Comp
L R R17
U 1 1 5843104A
P 8850 2475
F 0 "R17" V 8930 2475 50  0000 C CNN
F 1 "3.3k" V 8850 2475 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8780 2475 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8850 2475 50  0001 C CNN
F 4 "311-3.30KHRCT-ND" V 8850 2475 60  0001 C CNN "Digikey"
	1    8850 2475
	0    1    1    0   
$EndComp
$Comp
L GND #PWR20
U 1 1 58431051
P 9000 2875
F 0 "#PWR20" H 9000 2625 50  0001 C CNN
F 1 "GND" H 9000 2725 50  0000 C CNN
F 2 "" H 9000 2875 50  0000 C CNN
F 3 "" H 9000 2875 50  0000 C CNN
	1    9000 2875
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 58431061
P 8300 2675
F 0 "C8" H 8325 2775 50  0000 L CNN
F 1 "10u" H 8325 2575 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8338 2525 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 8300 2675 50  0001 C CNN
F 4 "490-12323-1-ND" H 8300 2675 60  0001 C CNN "Digikey"
	1    8300 2675
	0    1    1    0   
$EndComp
Text Notes 7800 1925 0    60   ~ 0
Voltage Divider\n-----------------------\nA=6k/120k = 20\nVin,max=20 V\nVout,max=1 V (reference of ADC)
Text Notes 4000 2300 0    60   ~ 0
LED
Text HLabel 1950 3150 0    60   Input ~ 0
V20
Text HLabel 2100 3300 0    60   Input ~ 0
PWM_R
Text HLabel 2100 3700 0    60   Input ~ 0
PWM_B
Text HLabel 2100 4050 0    60   Input ~ 0
PWM_G
Text HLabel 6050 2675 0    60   Output ~ 0
ADC_R
Text HLabel 6050 3775 0    60   Input ~ 0
V20
Text HLabel 6000 4475 0    60   Output ~ 0
ADC_B
Text HLabel 7950 4475 2    60   Output ~ 0
ADC_G
Text HLabel 10400 3475 2    60   Input ~ 0
PWM_OLED
Text HLabel 8350 2325 2    60   Output ~ 0
ADC_OLED
Text HLabel 8350 2125 2    60   Output ~ 0
VOLED
Text HLabel 4050 2700 1    60   Output ~ 0
LED_R
Text HLabel 4150 2700 1    60   Output ~ 0
LED_B
Text HLabel 4250 2700 1    60   Output ~ 0
LED_G
Text HLabel 4350 2700 1    60   Output ~ 0
LED_GND
$Comp
L C C21
U 1 1 584CBAE2
P 5700 3575
F 0 "C21" V 5750 3625 50  0000 L CNN
F 1 "2.2u" V 5750 3325 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5738 3425 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/partnumbering_e_01.pdf" H 5700 3575 50  0001 C CNN
F 4 "490-7204-1-ND" H 5700 3575 60  0001 C CNN "Digikey"
	1    5700 3575
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR14
U 1 1 584CCA77
P 5175 3625
F 0 "#PWR14" H 5175 3375 50  0001 C CNN
F 1 "GND" H 5175 3475 50  0000 C CNN
F 2 "" H 5175 3625 50  0000 C CNN
F 3 "" H 5175 3625 50  0000 C CNN
	1    5175 3625
	1    0    0    -1  
$EndComp
$Comp
L R R37
U 1 1 5866FDB9
P 8000 3975
F 0 "R37" V 8080 3975 50  0000 C CNN
F 1 "120k" V 8000 3975 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 7930 3975 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8000 3975 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 8000 3975 60  0001 C CNN "Digikey"
	1    8000 3975
	0    1    1    0   
$EndComp
$Comp
L R R38
U 1 1 5866FDC0
P 8500 3975
F 0 "R38" V 8580 3975 50  0000 C CNN
F 1 "3.9k" V 8500 3975 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 8430 3975 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8500 3975 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 8500 3975 60  0001 C CNN "Digikey"
	1    8500 3975
	0    1    1    0   
$EndComp
$Comp
L GND #PWR18
U 1 1 586714EB
P 7850 3975
F 0 "#PWR18" H 7850 3725 50  0001 C CNN
F 1 "GND" H 7850 3825 50  0000 C CNN
F 2 "" H 7850 3975 50  0000 C CNN
F 3 "" H 7850 3975 50  0000 C CNN
	1    7850 3975
	1    0    0    -1  
$EndComp
Text GLabel 3500 3500 2    60   Input ~ 0
OPAMP_R_P
Text GLabel 3500 3600 2    60   Input ~ 0
OPAMP_R_N
Text GLabel 3500 3950 2    60   Input ~ 0
OPAMP_B_P
Text GLabel 3500 4050 2    60   Input ~ 0
OPAMP_B_N
Text GLabel 3500 4400 2    60   Input ~ 0
OPAMP_G_P
Text GLabel 3500 4500 2    60   Input ~ 0
OPAMP_G_N
Text GLabel 8675 3975 2    60   Input ~ 0
OPAMP_G_N
Text GLabel 8675 4275 2    60   Input ~ 0
OPAMP_G_P
$Comp
L R R36
U 1 1 5867CD8C
P 5950 3950
F 0 "R36" V 6030 3950 50  0000 C CNN
F 1 "120k" V 5950 3950 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5880 3950 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5950 3950 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 5950 3950 60  0001 C CNN "Digikey"
	1    5950 3950
	0    1    1    0   
$EndComp
$Comp
L R R34
U 1 1 5867CD99
P 5500 3950
F 0 "R34" V 5580 3950 50  0000 C CNN
F 1 "3.9k" V 5500 3950 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5430 3950 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5500 3950 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 5500 3950 60  0001 C CNN "Digikey"
	1    5500 3950
	0    1    1    0   
$EndComp
$Comp
L GND #PWR16
U 1 1 5867D2A9
P 6100 3950
F 0 "#PWR16" H 6100 3700 50  0001 C CNN
F 1 "GND" H 6100 3800 50  0000 C CNN
F 2 "" H 6100 3950 50  0000 C CNN
F 3 "" H 6100 3950 50  0000 C CNN
	1    6100 3950
	1    0    0    -1  
$EndComp
Text GLabel 5325 3950 0    60   Input ~ 0
OPAMP_B_N
Text GLabel 5325 4275 0    60   Input ~ 0
OPAMP_B_P
$Sheet
S 2256 3044 1144 1856
U 58430F64
F0 "LED Driver 3 Chan. " 60
F1 "rgbLedDriver.sch" 60
F2 "LED_G_P" O R 3400 4200 60 
F3 "LED_G_N" O R 3400 4300 60 
F4 "PWM_B" I L 2256 3700 60 
F5 "LED_B_P" O R 3400 3750 60 
F6 "LED_B_N" O R 3400 3850 60 
F7 "PWM_R" I L 2256 3300 60 
F8 "LED_R_P" O R 3400 3300 60 
F9 "LED_R_N" O R 3400 3400 60 
F10 "V20" I L 2256 3150 60 
F11 "PWM_G" I L 2256 4050 60 
F12 "OPAMP_G_P" O R 3400 4400 60 
F13 "OPAMP_B_P" O R 3400 3950 60 
F14 "OPAMP_R_P" O R 3400 3500 60 
F15 "OPAMP_R_N" O R 3400 3600 60 
F16 "OPAMP_G_N" O R 3400 4500 60 
F17 "OPAMP_B_N" O R 3400 4050 60 
$EndSheet
$Comp
L R R33
U 1 1 5868439D
P 5500 3375
F 0 "R33" V 5580 3375 50  0000 C CNN
F 1 "3.9k" V 5500 3375 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5430 3375 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5500 3375 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 5500 3375 60  0001 C CNN "Digikey"
	1    5500 3375
	0    1    1    0   
$EndComp
$Comp
L R R35
U 1 1 586843A4
P 5900 3375
F 0 "R35" V 5980 3375 50  0000 C CNN
F 1 "120k" V 5900 3375 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 5830 3375 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5900 3375 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 5900 3375 60  0001 C CNN "Digikey"
	1    5900 3375
	0    1    1    0   
$EndComp
Text GLabel 5325 3075 0    60   Input ~ 0
OPAMP_R_P
Text GLabel 5325 3375 0    60   Input ~ 0
OPAMP_R_N
$Comp
L GND #PWR15
U 1 1 58689DF6
P 6050 3375
F 0 "#PWR15" H 6050 3125 50  0001 C CNN
F 1 "GND" H 6050 3225 50  0000 C CNN
F 2 "" H 6050 3375 50  0000 C CNN
F 3 "" H 6050 3375 50  0000 C CNN
	1    6050 3375
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 3475 9500 3475
Wire Wire Line
	9800 3475 9900 3475
Wire Wire Line
	9450 3925 10250 3925
Wire Wire Line
	9450 3925 9450 3875
Connection ~ 10250 3925
Wire Wire Line
	9850 3875 9850 3925
Connection ~ 9850 3925
Wire Wire Line
	9450 3575 9450 3475
Connection ~ 9450 3475
Wire Wire Line
	9850 3575 9850 3475
Connection ~ 9850 3475
Wire Wire Line
	10250 3875 10250 3975
Wire Wire Line
	10250 3575 10250 3475
Wire Wire Line
	10200 3475 10400 3475
Connection ~ 10250 3475
Wire Wire Line
	7700 3275 8250 3275
Wire Wire Line
	8150 2475 8350 2475
Wire Wire Line
	8650 2475 8700 2475
Wire Wire Line
	9000 2475 9000 2875
Wire Wire Line
	2256 3300 2100 3300
Wire Wire Line
	2256 3700 2100 3700
Wire Wire Line
	2100 4050 2256 4050
Wire Wire Line
	2256 3150 1950 3150
Wire Wire Line
	8150 3075 8350 3075
Wire Wire Line
	8250 3275 8250 3075
Connection ~ 8250 3075
Wire Wire Line
	7700 3075 7850 3075
Wire Wire Line
	7850 2475 7800 2475
Wire Wire Line
	7800 2125 7800 3075
Connection ~ 7800 3075
Wire Wire Line
	7700 4275 7850 4275
Wire Wire Line
	7950 4475 7750 4475
Wire Wire Line
	7750 4475 7750 4275
Connection ~ 7750 4275
Wire Wire Line
	6100 4275 6300 4275
Wire Wire Line
	8150 4275 8350 4275
Connection ~ 8250 4275
Wire Wire Line
	5700 4075 6300 4075
Wire Wire Line
	5650 4275 5800 4275
Wire Wire Line
	6000 4475 6200 4475
Wire Wire Line
	6200 4475 6200 4275
Connection ~ 6200 4275
Wire Wire Line
	6050 3075 6300 3075
Wire Wire Line
	5650 3075 5750 3075
Connection ~ 5700 3075
Wire Wire Line
	6250 3075 6250 2675
Connection ~ 6250 3075
Wire Wire Line
	6250 2675 6050 2675
Connection ~ 7800 2475
Wire Wire Line
	8350 2125 7800 2125
Wire Wire Line
	8150 2675 7800 2675
Connection ~ 9000 2675
Connection ~ 7800 2675
Wire Wire Line
	8450 2675 9000 2675
Wire Wire Line
	8350 2325 8250 2325
Wire Wire Line
	8250 2325 8250 2475
Connection ~ 8250 2475
Wire Wire Line
	6300 3675 6200 3675
Wire Wire Line
	6200 3575 6200 3775
Wire Wire Line
	6200 3575 5850 3575
Connection ~ 6200 3675
Wire Wire Line
	5175 3575 5175 3625
Wire Wire Line
	5175 3575 5550 3575
Wire Wire Line
	6200 3775 6050 3775
Wire Wire Line
	8150 3975 8350 3975
Connection ~ 8250 3975
Wire Wire Line
	8250 4075 8250 4275
Wire Wire Line
	7700 3875 8250 3875
Wire Wire Line
	8250 3875 8250 3975
Wire Wire Line
	7700 3675 7800 3675
Wire Wire Line
	3400 4050 3500 4050
Wire Wire Line
	3400 4500 3500 4500
Wire Wire Line
	3400 3300 4050 3300
Wire Wire Line
	4050 3300 4050 2700
Wire Wire Line
	3400 3400 4350 3400
Wire Wire Line
	4350 2700 4350 4300
Wire Wire Line
	3400 3750 4150 3750
Wire Wire Line
	4150 3750 4150 2700
Wire Wire Line
	4350 3850 3400 3850
Connection ~ 4350 3400
Wire Wire Line
	3400 4200 4250 4200
Wire Wire Line
	4250 4200 4250 2700
Wire Wire Line
	4350 4300 3400 4300
Connection ~ 4350 3850
Wire Wire Line
	8675 4275 8650 4275
Wire Wire Line
	8675 3975 8650 3975
Wire Wire Line
	7700 4075 8250 4075
Wire Wire Line
	7700 3475 9100 3475
Connection ~ 5700 4275
Wire Wire Line
	5700 4275 5700 4075
Wire Wire Line
	5650 3950 5800 3950
Wire Wire Line
	6300 3875 5725 3875
Wire Wire Line
	5725 3875 5725 3950
Connection ~ 5725 3950
Wire Wire Line
	5325 3950 5350 3950
Wire Wire Line
	5325 4275 5350 4275
Wire Wire Line
	3400 3500 3500 3500
Wire Wire Line
	3400 3600 3500 3600
Wire Wire Line
	3400 3950 3500 3950
Wire Wire Line
	3500 4400 3400 4400
Wire Wire Line
	8650 3075 8700 3075
Wire Wire Line
	8700 3075 8700 3125
Wire Wire Line
	5650 3375 5750 3375
Connection ~ 5700 3375
Wire Wire Line
	5700 3075 5700 3200
Wire Wire Line
	5700 3300 5700 3375
Wire Wire Line
	5700 3200 6300 3200
Wire Wire Line
	5350 3075 5325 3075
Wire Wire Line
	5350 3375 5325 3375
Wire Wire Line
	5700 3300 6200 3300
Wire Wire Line
	6200 3300 6200 3475
Wire Wire Line
	6200 3475 6300 3475
Wire Wire Line
	6300 3200 6300 3275
$EndSCHEMATC
