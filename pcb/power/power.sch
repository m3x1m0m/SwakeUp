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
Sheet 1 4
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
S 3006 2394 1044 1306
U 58375294
F0 "RGB LED Driver " 60
F1 "rgbLedDriver.sch" 60
F2 "PWM_G" I L 3006 2650 60 
F3 "LED_G_P" O R 4050 3400 60 
F4 "LED_G_N" O R 4050 3500 60 
F5 "OPAMP_G" O R 4050 3600 60 
F6 "PWM_B" I L 3006 3050 60 
F7 "LED_B_P" O R 4050 3050 60 
F8 "LED_B_N" O R 4050 3150 60 
F9 "OPAMP_B" O R 4050 3250 60 
F10 "PWM_R" I L 3006 3400 60 
F11 "LED_R_P" O R 4050 2650 60 
F12 "LED_R_N" O R 4050 2750 60 
F13 "OPAMP_R" O R 4050 2850 60 
F14 "V20" I L 3006 2500 60 
$EndSheet
$Comp
L LM324QT U1
U 1 1 5838BEE1
P 6250 3050
F 0 "U1" H 6700 2300 60  0000 C CNN
F 1 "LM324QT" H 5950 2300 60  0000 C CNN
F 2 "" H 6250 3050 60  0000 C CNN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/58/13/52/7e/39/8c/4c/ba/CD00000457.pdf/files/CD00000457.pdf/jcr:content/translations/en.CD00000457.pdf" H 6250 3050 60  0001 C CNN
F 4 "497-12005-1-ND" H 6250 3050 60  0001 C CNN "Digikey"
	1    6250 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR1
U 1 1 5838E9B2
P 4750 2550
F 0 "#PWR1" H 4750 2300 50  0001 C CNN
F 1 "GND" H 4750 2400 50  0000 C CNN
F 2 "" H 4750 2550 50  0000 C CNN
F 3 "" H 4750 2550 50  0000 C CNN
	1    4750 2550
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 5838F1C9
P 5300 3450
F 0 "R8" V 5380 3450 50  0000 C CNN
F 1 "120k" V 5300 3450 50  0000 C CNN
F 2 "" V 5230 3450 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5300 3450 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 5300 3450 60  0001 C CNN "Digikey"
	1    5300 3450
	0    1    1    0   
$EndComp
$Comp
L GND #PWR2
U 1 1 5838F3B3
P 4750 3550
F 0 "#PWR2" H 4750 3300 50  0001 C CNN
F 1 "GND" H 4750 3400 50  0000 C CNN
F 2 "" H 4750 3550 50  0000 C CNN
F 3 "" H 4750 3550 50  0000 C CNN
	1    4750 3550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR5
U 1 1 58391691
P 7750 3550
F 0 "#PWR5" H 7750 3300 50  0001 C CNN
F 1 "GND" H 7750 3400 50  0000 C CNN
F 2 "" H 7750 3550 50  0000 C CNN
F 3 "" H 7750 3550 50  0000 C CNN
	1    7750 3550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P1
U 1 1 58392B4F
P 4350 1850
F 0 "P1" H 4350 2100 50  0000 C CNN
F 1 "CONN_01X04" V 4450 1850 50  0000 C CNN
F 2 "" H 4350 1850 50  0000 C CNN
F 3 "http://www.on-shore.com/wp-content/uploads/2015/09/osttcxx2162.pdf" H 4350 1850 50  0001 C CNN
F 4 "ED2611-ND" H 4350 1850 60  0001 C CNN "Digikey"
	1    4350 1850
	0    -1   -1   0   
$EndComp
$Comp
L R R9
U 1 1 58394867
P 7200 2650
F 0 "R9" V 7280 2650 50  0000 C CNN
F 1 "240k" V 7200 2650 50  0000 C CNN
F 2 "" V 7130 2650 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7200 2650 50  0001 C CNN
F 4 "311-240KHRCT-ND" V 7200 2650 60  0001 C CNN "Digikey"
	1    7200 2650
	0    1    1    0   
$EndComp
$Comp
L R R19
U 1 1 58394912
P 7600 2650
F 0 "R19" V 7680 2650 50  0000 C CNN
F 1 "39k" V 7600 2650 50  0000 C CNN
F 2 "" V 7530 2650 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7600 2650 50  0001 C CNN
F 4 "311-39.0KHRCT-ND" V 7600 2650 60  0001 C CNN "Digikey"
	1    7600 2650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR4
U 1 1 58394C0A
P 7750 2750
F 0 "#PWR4" H 7750 2500 50  0001 C CNN
F 1 "GND" H 7750 2600 50  0000 C CNN
F 2 "" H 7750 2750 50  0000 C CNN
F 3 "" H 7750 2750 50  0000 C CNN
	1    7750 2750
	1    0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 58394FC2
P 8100 2950
F 0 "R21" V 8180 2950 50  0000 C CNN
F 1 "47k" V 8100 2950 50  0000 C CNN
F 2 "" V 8030 2950 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8100 2950 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 8100 2950 60  0001 C CNN "Digikey"
	1    8100 2950
	0    1    1    0   
$EndComp
$Comp
L C C10
U 1 1 583951CE
P 8300 3200
F 0 "C10" H 8325 3300 50  0000 L CNN
F 1 "10n" H 8325 3100 50  0000 L CNN
F 2 "" H 8338 3050 50  0000 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 8300 3200 50  0001 C CNN
F 4 "311-1085-1-ND" H 8300 3200 60  0001 C CNN "Digikey"
	1    8300 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR6
U 1 1 58395B51
P 9100 3450
F 0 "#PWR6" H 9100 3200 50  0001 C CNN
F 1 "GND" H 9100 3300 50  0000 C CNN
F 2 "" H 9100 3450 50  0000 C CNN
F 3 "" H 9100 3450 50  0000 C CNN
	1    9100 3450
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 583964BE
P 4900 2450
F 0 "R5" V 4980 2450 50  0000 C CNN
F 1 "3.9k" V 4900 2450 50  0000 C CNN
F 2 "" V 4830 2450 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4900 2450 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 4900 2450 60  0001 C CNN "Digikey"
	1    4900 2450
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 583968F2
P 5300 2450
F 0 "R7" V 5380 2450 50  0000 C CNN
F 1 "120k" V 5300 2450 50  0000 C CNN
F 2 "" V 5230 2450 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5300 2450 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 5300 2450 60  0001 C CNN "Digikey"
	1    5300 2450
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 583969A3
P 7200 3450
F 0 "R10" V 7280 3450 50  0000 C CNN
F 1 "120k" V 7200 3450 50  0000 C CNN
F 2 "" V 7130 3450 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7200 3450 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 7200 3450 60  0001 C CNN "Digikey"
	1    7200 3450
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 58396C86
P 4900 3450
F 0 "R6" V 4980 3450 50  0000 C CNN
F 1 "3.9k" V 4900 3450 50  0000 C CNN
F 2 "" V 4830 3450 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4900 3450 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 4900 3450 60  0001 C CNN "Digikey"
	1    4900 3450
	0    1    1    0   
$EndComp
$Comp
L R R20
U 1 1 58396D3B
P 7600 3450
F 0 "R20" V 7680 3450 50  0000 C CNN
F 1 "3.9k" V 7600 3450 50  0000 C CNN
F 2 "" V 7530 3450 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7600 3450 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 7600 3450 60  0001 C CNN "Digikey"
	1    7600 3450
	0    1    1    0   
$EndComp
$Comp
L R R22
U 1 1 58398205
P 8500 2950
F 0 "R22" V 8580 2950 50  0000 C CNN
F 1 "47k" V 8500 2950 50  0000 C CNN
F 2 "" V 8430 2950 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8500 2950 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 8500 2950 60  0001 C CNN "Digikey"
	1    8500 2950
	0    1    1    0   
$EndComp
$Comp
L R R23
U 1 1 5839829C
P 8900 2950
F 0 "R23" V 8980 2950 50  0000 C CNN
F 1 "47k" V 8900 2950 50  0000 C CNN
F 2 "" V 8830 2950 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8900 2950 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 8900 2950 60  0001 C CNN "Digikey"
	1    8900 2950
	0    1    1    0   
$EndComp
$Comp
L C C11
U 1 1 583984D9
P 8700 3200
F 0 "C11" H 8725 3300 50  0000 L CNN
F 1 "10n" H 8725 3100 50  0000 L CNN
F 2 "" H 8738 3050 50  0000 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 8700 3200 50  0001 C CNN
F 4 "311-1085-1-ND" H 8700 3200 60  0001 C CNN "Digikey"
	1    8700 3200
	1    0    0    -1  
$EndComp
Text GLabel 9350 2950 2    60   Input ~ 0
PWM_OLED
$Comp
L C C12
U 1 1 58399326
P 9100 3200
F 0 "C12" H 9125 3300 50  0000 L CNN
F 1 "10n" H 9125 3100 50  0000 L CNN
F 2 "" H 9138 3050 50  0000 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 9100 3200 50  0001 C CNN
F 4 "311-1085-1-ND" H 9100 3200 60  0001 C CNN "Digikey"
	1    9100 3200
	1    0    0    -1  
$EndComp
$Comp
L USB_B P2
U 1 1 58399DD1
P 5650 5150
F 0 "P2" H 5850 4950 50  0000 C CNN
F 1 "USB_B" H 5600 5350 50  0000 C CNN
F 2 "" V 5600 5050 50  0000 C CNN
F 3 "http://katalog.we-online.de/em/datasheet/632121300001.pdf" V 5600 5050 50  0001 C CNN
F 4 "732-9615-ND" H 5650 5150 60  0001 C CNN "Digikey"
	1    5650 5150
	0    1    1    0   
$EndComp
Text GLabel 5400 3050 0    60   Input ~ 0
V20
$Comp
L GND #PWR3
U 1 1 5839C2CB
P 7150 3050
F 0 "#PWR3" H 7150 2800 50  0001 C CNN
F 1 "GND" H 7150 2900 50  0000 C CNN
F 2 "" H 7150 3050 50  0000 C CNN
F 3 "" H 7150 3050 50  0000 C CNN
	1    7150 3050
	1    0    0    -1  
$EndComp
$Sheet
S 3000 4300 2000 200 
U 583BCCA6
F0 "Bucket Converter for 2.8 V, 100 mA" 60
F1 "V28.sch" 60
F2 "V28" O R 5000 4400 60 
F3 "V20" I L 3000 4400 60 
$EndSheet
Text Notes 7150 2150 0    60   ~ 0
A=(R1+R2)/R1 =7.154\nVin,max=2.8 V\nVout,max=20.031 V
Text Notes 7050 4050 0    60   ~ 0
A=(R1+R2)/R1 =31.769\nVin,max=30 mV\nVout,max=953.077 mV
Wire Wire Line
	5450 2450 5550 2450
Wire Wire Line
	5050 2450 5150 2450
Wire Wire Line
	5100 2450 5100 2650
Wire Wire Line
	5100 2650 5550 2650
Connection ~ 5100 2450
Wire Wire Line
	4750 2450 4750 2550
Wire Wire Line
	4750 3450 4750 3550
Wire Wire Line
	5050 3450 5150 3450
Wire Wire Line
	5450 3450 5550 3450
Wire Wire Line
	5100 3450 5100 3650
Wire Wire Line
	5100 3650 5550 3650
Connection ~ 5100 3450
Wire Wire Line
	4050 3250 5550 3250
Wire Wire Line
	5550 2850 4050 2850
Wire Wire Line
	7350 3450 7450 3450
Wire Wire Line
	7400 3650 7400 3450
Connection ~ 7400 3450
Wire Wire Line
	7750 3450 7750 3550
Wire Wire Line
	4050 3600 4600 3600
Wire Wire Line
	4200 2050 4200 2650
Wire Wire Line
	4200 2650 4050 2650
Wire Wire Line
	4050 3050 4300 3050
Wire Wire Line
	4300 3050 4300 2050
Wire Wire Line
	4050 3400 4400 3400
Wire Wire Line
	4400 3400 4400 2050
Wire Wire Line
	4500 3500 4050 3500
Wire Wire Line
	4500 3150 4050 3150
Connection ~ 4500 3150
Wire Wire Line
	4600 3600 4600 2250
Wire Wire Line
	4600 2250 7850 2250
Wire Wire Line
	7850 2250 7850 3250
Wire Wire Line
	7350 2650 7450 2650
Wire Wire Line
	7750 2650 7750 2750
Wire Wire Line
	7400 2950 7400 2850
Wire Wire Line
	8250 2950 8350 2950
Wire Wire Line
	8650 2950 8750 2950
Wire Wire Line
	7400 2450 7400 2650
Connection ~ 7400 2650
Wire Wire Line
	8300 3400 9100 3400
Wire Wire Line
	8300 3400 8300 3350
Connection ~ 9100 3400
Wire Wire Line
	8700 3350 8700 3400
Connection ~ 8700 3400
Wire Wire Line
	8300 3050 8300 2950
Connection ~ 8300 2950
Wire Wire Line
	8700 3050 8700 2950
Connection ~ 8700 2950
Wire Wire Line
	7400 2950 7950 2950
Wire Wire Line
	9100 3350 9100 3450
Wire Wire Line
	9100 3050 9100 2950
Wire Wire Line
	9050 2950 9350 2950
Connection ~ 9100 2950
Wire Wire Line
	4050 2750 4500 2750
Connection ~ 4500 2750
Wire Wire Line
	4500 2050 4500 3500
Wire Wire Line
	5400 3050 5550 3050
Wire Wire Line
	6950 3650 7400 3650
Wire Wire Line
	6950 3450 7050 3450
Wire Wire Line
	7850 3250 6950 3250
Wire Wire Line
	6950 3050 7150 3050
Wire Wire Line
	7400 2850 6950 2850
Wire Wire Line
	6950 2650 7050 2650
Wire Wire Line
	6950 2450 7400 2450
$Sheet
S 3000 4850 2000 300 
U 583B3084
F0 "Bucket Converter for 5 V,  3 A" 60
F1 "V53A.sch" 60
F2 "V20" I L 3000 4950 60 
F3 "V5" O R 5000 4950 60 
F4 "5V_EN" I L 3000 5050 60 
$EndSheet
Text GLabel 2700 4400 0    60   Input ~ 0
V20
Wire Wire Line
	2700 4400 3000 4400
Wire Wire Line
	2850 4400 2850 4950
Wire Wire Line
	2850 4950 3000 4950
Connection ~ 2850 4400
Wire Wire Line
	5000 4950 5350 4950
$Comp
L GND #PWR?
U 1 1 583B960B
P 5200 5250
F 0 "#PWR?" H 5200 5000 50  0001 C CNN
F 1 "GND" H 5200 5100 50  0000 C CNN
F 2 "" H 5200 5250 50  0000 C CNN
F 3 "" H 5200 5250 50  0000 C CNN
	1    5200 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 5250 5350 5250
$EndSCHEMATC
