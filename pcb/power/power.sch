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
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title "Power Board For SwakeUp"
Date "2016-11-26"
Rev "1.0"
Comp "Uppsala University"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3556 2544 1044 1306
U 58375294
F0 "RGB LED Driver " 60
F1 "rgbLedDriver.sch" 60
F2 "PWM_G" I L 3556 2800 60 
F3 "LED_G_P" O R 4600 3550 60 
F4 "LED_G_N" O R 4600 3650 60 
F5 "OPAMP_G" O R 4600 3750 60 
F6 "PWM_B" I L 3556 3200 60 
F7 "LED_B_P" O R 4600 3200 60 
F8 "LED_B_N" O R 4600 3300 60 
F9 "OPAMP_B" O R 4600 3400 60 
F10 "PWM_R" I L 3556 3550 60 
F11 "LED_R_P" O R 4600 2800 60 
F12 "LED_R_N" O R 4600 2900 60 
F13 "OPAMP_R" O R 4600 3000 60 
$EndSheet
$Comp
L LM324QT U1
U 1 1 5838BEE1
P 6800 3200
F 0 "U1" H 7300 2450 60  0000 C CNN
F 1 "LM324QT" H 6450 2450 60  0000 C CNN
F 2 "" H 6800 3200 60  0000 C CNN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/58/13/52/7e/39/8c/4c/ba/CD00000457.pdf/files/CD00000457.pdf/jcr:content/translations/en.CD00000457.pdf" H 6800 3200 60  0001 C CNN
F 4 "497-12005-1-ND" H 6800 3200 60  0001 C CNN "Digikey"
	1    6800 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR1
U 1 1 5838E9B2
P 5300 2700
F 0 "#PWR1" H 5300 2450 50  0001 C CNN
F 1 "GND" H 5300 2550 50  0000 C CNN
F 2 "" H 5300 2700 50  0000 C CNN
F 3 "" H 5300 2700 50  0000 C CNN
	1    5300 2700
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 5838F1C9
P 5850 3600
F 0 "R8" V 5930 3600 50  0000 C CNN
F 1 "120k" V 5850 3600 50  0000 C CNN
F 2 "" V 5780 3600 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5850 3600 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 5850 3600 60  0001 C CNN "Digikey"
	1    5850 3600
	0    1    1    0   
$EndComp
$Comp
L GND #PWR2
U 1 1 5838F3B3
P 5300 3700
F 0 "#PWR2" H 5300 3450 50  0001 C CNN
F 1 "GND" H 5300 3550 50  0000 C CNN
F 2 "" H 5300 3700 50  0000 C CNN
F 3 "" H 5300 3700 50  0000 C CNN
	1    5300 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 58391691
P 8300 3700
F 0 "#PWR4" H 8300 3450 50  0001 C CNN
F 1 "GND" H 8300 3550 50  0000 C CNN
F 2 "" H 8300 3700 50  0000 C CNN
F 3 "" H 8300 3700 50  0000 C CNN
	1    8300 3700
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P1
U 1 1 58392B4F
P 4900 2000
F 0 "P1" H 4900 2250 50  0000 C CNN
F 1 "CONN_01X04" V 5000 2000 50  0000 C CNN
F 2 "" H 4900 2000 50  0000 C CNN
F 3 "http://www.on-shore.com/wp-content/uploads/2015/09/osttcxx2162.pdf" H 4900 2000 50  0001 C CNN
F 4 "ED2611-ND" H 4900 2000 60  0001 C CNN "Digikey"
	1    4900 2000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6000 2600 6100 2600
Wire Wire Line
	5600 2600 5700 2600
Wire Wire Line
	5650 2600 5650 2800
Wire Wire Line
	5650 2800 6100 2800
Connection ~ 5650 2600
Wire Wire Line
	5300 2600 5300 2700
Wire Wire Line
	5300 3600 5300 3700
Wire Wire Line
	5600 3600 5700 3600
Wire Wire Line
	6000 3600 6100 3600
Wire Wire Line
	5650 3600 5650 3800
Wire Wire Line
	5650 3800 6100 3800
Connection ~ 5650 3600
Wire Wire Line
	4600 3400 6100 3400
Wire Wire Line
	6100 3000 4600 3000
Wire Wire Line
	7500 3600 7600 3600
Wire Wire Line
	7900 3600 8000 3600
Wire Wire Line
	7500 3800 7950 3800
Wire Wire Line
	7950 3800 7950 3600
Connection ~ 7950 3600
Wire Wire Line
	8300 3600 8300 3700
Wire Wire Line
	4600 3750 5150 3750
Wire Wire Line
	4750 2200 4750 2800
Wire Wire Line
	4750 2800 4600 2800
Wire Wire Line
	4600 3200 4850 3200
Wire Wire Line
	4850 3200 4850 2200
Wire Wire Line
	4600 3550 4950 3550
Wire Wire Line
	4950 3550 4950 2200
Wire Wire Line
	5050 3650 4600 3650
Wire Wire Line
	4600 3300 5050 3300
Connection ~ 5050 3300
Wire Wire Line
	5150 3750 5150 2400
Wire Wire Line
	5150 2400 8400 2400
Wire Wire Line
	7500 3400 8400 3400
Wire Wire Line
	8400 3400 8400 2400
$Comp
L R R9
U 1 1 58394867
P 7750 2800
F 0 "R9" V 7830 2800 50  0000 C CNN
F 1 "240k" V 7750 2800 50  0000 C CNN
F 2 "" V 7680 2800 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7750 2800 50  0001 C CNN
F 4 "311-240KHRCT-ND" V 7750 2800 60  0001 C CNN "Digikey"
	1    7750 2800
	0    1    1    0   
$EndComp
$Comp
L R R19
U 1 1 58394912
P 8150 2800
F 0 "R19" V 8230 2800 50  0000 C CNN
F 1 "39k" V 8150 2800 50  0000 C CNN
F 2 "" V 8080 2800 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8150 2800 50  0001 C CNN
F 4 "311-39.0KHRCT-ND" V 8150 2800 60  0001 C CNN "Digikey"
	1    8150 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	7500 2800 7600 2800
Wire Wire Line
	7900 2800 8000 2800
$Comp
L GND #PWR3
U 1 1 58394C0A
P 8300 2900
F 0 "#PWR3" H 8300 2650 50  0001 C CNN
F 1 "GND" H 8300 2750 50  0000 C CNN
F 2 "" H 8300 2900 50  0000 C CNN
F 3 "" H 8300 2900 50  0000 C CNN
	1    8300 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 2800 8300 2900
$Comp
L R R21
U 1 1 58394FC2
P 8650 3100
F 0 "R21" V 8730 3100 50  0000 C CNN
F 1 "47k" V 8650 3100 50  0000 C CNN
F 2 "" V 8580 3100 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8650 3100 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 8650 3100 60  0001 C CNN "Digikey"
	1    8650 3100
	0    1    1    0   
$EndComp
$Comp
L C C10
U 1 1 583951CE
P 8850 3350
F 0 "C10" H 8875 3450 50  0000 L CNN
F 1 "10n" H 8875 3250 50  0000 L CNN
F 2 "" H 8888 3200 50  0000 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 8850 3350 50  0001 C CNN
F 4 "311-1085-1-ND" H 8850 3350 60  0001 C CNN "Digikey"
	1    8850 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 3100 7950 3000
Wire Wire Line
	7950 3000 7500 3000
Wire Wire Line
	8800 3100 8900 3100
Wire Wire Line
	9200 3100 9300 3100
$Comp
L GND #PWR5
U 1 1 58395B51
P 9650 3600
F 0 "#PWR5" H 9650 3350 50  0001 C CNN
F 1 "GND" H 9650 3450 50  0000 C CNN
F 2 "" H 9650 3600 50  0000 C CNN
F 3 "" H 9650 3600 50  0000 C CNN
	1    9650 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 2600 7950 2600
Wire Wire Line
	7950 2600 7950 2800
Connection ~ 7950 2800
$Comp
L R R5
U 1 1 583964BE
P 5450 2600
F 0 "R5" V 5530 2600 50  0000 C CNN
F 1 "3.9k" V 5450 2600 50  0000 C CNN
F 2 "" V 5380 2600 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5450 2600 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 5450 2600 60  0001 C CNN "Digikey"
	1    5450 2600
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 583968F2
P 5850 2600
F 0 "R7" V 5930 2600 50  0000 C CNN
F 1 "120k" V 5850 2600 50  0000 C CNN
F 2 "" V 5780 2600 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5850 2600 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 5850 2600 60  0001 C CNN "Digikey"
	1    5850 2600
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 583969A3
P 7750 3600
F 0 "R10" V 7830 3600 50  0000 C CNN
F 1 "120k" V 7750 3600 50  0000 C CNN
F 2 "" V 7680 3600 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7750 3600 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 7750 3600 60  0001 C CNN "Digikey"
	1    7750 3600
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 58396C86
P 5450 3600
F 0 "R6" V 5530 3600 50  0000 C CNN
F 1 "3.9k" V 5450 3600 50  0000 C CNN
F 2 "" V 5380 3600 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5450 3600 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 5450 3600 60  0001 C CNN "Digikey"
	1    5450 3600
	0    1    1    0   
$EndComp
$Comp
L R R20
U 1 1 58396D3B
P 8150 3600
F 0 "R20" V 8230 3600 50  0000 C CNN
F 1 "3.9k" V 8150 3600 50  0000 C CNN
F 2 "" V 8080 3600 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8150 3600 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 8150 3600 60  0001 C CNN "Digikey"
	1    8150 3600
	0    1    1    0   
$EndComp
Wire Wire Line
	8850 3550 9650 3550
Wire Wire Line
	8850 3550 8850 3500
Connection ~ 9650 3550
Wire Wire Line
	9250 3500 9250 3550
Connection ~ 9250 3550
Wire Wire Line
	8850 3200 8850 3100
Connection ~ 8850 3100
Wire Wire Line
	9250 3200 9250 3100
Connection ~ 9250 3100
Wire Wire Line
	7950 3100 8500 3100
$Comp
L R R22
U 1 1 58398205
P 9050 3100
F 0 "R22" V 9130 3100 50  0000 C CNN
F 1 "47k" V 9050 3100 50  0000 C CNN
F 2 "" V 8980 3100 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 9050 3100 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 9050 3100 60  0001 C CNN "Digikey"
	1    9050 3100
	0    1    1    0   
$EndComp
$Comp
L R R23
U 1 1 5839829C
P 9450 3100
F 0 "R23" V 9530 3100 50  0000 C CNN
F 1 "47k" V 9450 3100 50  0000 C CNN
F 2 "" V 9380 3100 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 9450 3100 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 9450 3100 60  0001 C CNN "Digikey"
	1    9450 3100
	0    1    1    0   
$EndComp
$Comp
L C C11
U 1 1 583984D9
P 9250 3350
F 0 "C11" H 9275 3450 50  0000 L CNN
F 1 "10n" H 9275 3250 50  0000 L CNN
F 2 "" H 9288 3200 50  0000 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 9250 3350 50  0001 C CNN
F 4 "311-1085-1-ND" H 9250 3350 60  0001 C CNN "Digikey"
	1    9250 3350
	1    0    0    -1  
$EndComp
Text GLabel 9900 3100 2    60   Input ~ 0
PWM_OLED
Wire Wire Line
	9650 3500 9650 3600
$Comp
L C C12
U 1 1 58399326
P 9650 3350
F 0 "C12" H 9675 3450 50  0000 L CNN
F 1 "10n" H 9675 3250 50  0000 L CNN
F 2 "" H 9688 3200 50  0000 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 9650 3350 50  0001 C CNN
F 4 "311-1085-1-ND" H 9650 3350 60  0001 C CNN "Digikey"
	1    9650 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 3200 9650 3100
Wire Wire Line
	9600 3100 9900 3100
Connection ~ 9650 3100
$Comp
L USB_B P?
U 1 1 58399DD1
P 6800 4950
F 0 "P?" H 7000 4750 50  0000 C CNN
F 1 "USB_B" H 6750 5150 50  0000 C CNN
F 2 "" V 6750 4850 50  0000 C CNN
F 3 "http://katalog.we-online.de/em/datasheet/632121300001.pdf" V 6750 4850 50  0001 C CNN
F 4 "732-9615-ND" H 6800 4950 60  0001 C CNN "Digikey"
	1    6800 4950
	0    1    1    0   
$EndComp
$Comp
L LM3578 U?
U 1 1 5839A804
P 4100 4900
F 0 "U?" H 4250 5350 50  0000 C CNN
F 1 "LM3578" H 4350 4450 50  0000 C CNN
F 2 "" H 4100 4900 50  0000 C CNN
F 3 "" H 4100 4900 50  0000 C CNN
	1    4100 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2900 5050 2900
Connection ~ 5050 2900
Wire Wire Line
	5050 3650 5050 2200
Text GLabel 5950 3200 0    60   Input ~ 0
V20
Wire Wire Line
	5950 3200 6100 3200
$Comp
L GND #PWR?
U 1 1 5839C2CB
P 7700 3200
F 0 "#PWR?" H 7700 2950 50  0001 C CNN
F 1 "GND" H 7700 3050 50  0000 C CNN
F 2 "" H 7700 3200 50  0000 C CNN
F 3 "" H 7700 3200 50  0000 C CNN
	1    7700 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 3200 7700 3200
$Comp
L GND #PWR?
U 1 1 5839CA1C
P 3100 5200
F 0 "#PWR?" H 3100 4950 50  0001 C CNN
F 1 "GND" H 3100 5050 50  0000 C CNN
F 2 "" H 3100 5200 50  0000 C CNN
F 3 "" H 3100 5200 50  0000 C CNN
	1    3100 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 5200 3250 5200
$EndSCHEMATC
