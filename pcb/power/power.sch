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
Sheet 1 5
Title "Power Board "
Date "2016-12-30"
Rev "1.0"
Comp "Uppsala University"
Comment1 "Project: Swakeup"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X04 P2
U 1 1 583C3625
P 1250 5550
F 0 "P2" H 1250 5800 50  0000 C CNN
F 1 "CONN_01X04" V 1350 5550 50  0000 C CNN
F 2 "Additional:ESQ-104-12-G-S-LL" H 1250 5550 50  0001 C CNN
F 3 "https://www.samtec.com/products/esq" H 1250 5550 50  0001 C CNN
F 4 "ESQ-104-12-G-S-LL" H 1250 5550 60  0001 C CNN "Samtec"
	1    1250 5550
	0    1    1    0   
$EndComp
$Comp
L BARREL_JACK CON1
U 1 1 583C4079
P 1350 3550
F 0 "CON1" H 1350 3800 50  0000 C CNN
F 1 "BARREL_JACK" H 1350 3350 50  0000 C CNN
F 2 "Additional:PJ-047BH_BARREL_JACK" H 1350 3550 50  0001 C CNN
F 3 "http://www.cui.com/product/resource/digikeypdf/pj-047bh.pdf" H 1350 3550 50  0001 C CNN
F 4 "CP-047BH-ND" H 1350 3550 60  0001 C CNN "Digikey"
	1    1350 3550
	1    0    0    -1  
$EndComp
Text Notes 1200 5800 2    60   ~ 0
ADC
Text Notes 1500 1200 2    60   ~ 0
PWM
Text Notes 10150 1160 0    60   ~ 0
SCREEN
Text GLabel 5400 3450 0    60   Input ~ 0
PWM_OLED
Text GLabel 5400 3300 0    60   Input ~ 0
PWM_G
Text GLabel 5400 3200 0    60   Input ~ 0
PWM_B
Text GLabel 5400 3100 0    60   Input ~ 0
PWM_R
$Comp
L GND #PWR4
U 1 1 583EB242
P 9900 1550
F 0 "#PWR4" H 9900 1300 50  0001 C CNN
F 1 "GND" H 9900 1400 50  0000 C CNN
F 2 "" H 9900 1550 50  0000 C CNN
F 3 "" H 9900 1550 50  0000 C CNN
	1    9900 1550
	1    0    0    1   
$EndComp
Text GLabel 1200 5350 1    60   Input ~ 0
ADC_G
Text GLabel 1300 5350 1    60   Input ~ 0
ADC_B
Text GLabel 1400 5350 1    60   Input ~ 0
ADC_R
Text GLabel 1100 5350 1    60   Input ~ 0
ADC_OLED
Text GLabel 10350 1550 3    60   Input ~ 0
VOLED
$Comp
L LED D1
U 1 1 583D79A8
P 2300 3700
F 0 "D1" H 2300 3800 50  0000 C CNN
F 1 "LED" H 2300 3600 50  0000 C CNN
F 2 "LEDs:LED_0603" H 2300 3700 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic0/00167682_0.pdf" H 2300 3700 50  0001 C CNN
F 4 "475-3118-1-ND" H 2300 3700 60  0001 C CNN "Digikey"
	1    2300 3700
	0    -1   -1   0   
$EndComp
Text Notes 2700 3850 0    60   ~ 0
Debugging Diode\n-----------------------\nDiode: 1.7 V, 2 mA\nP=33.489 mW\nCan be left out in a later version!
$Comp
L CONN_01X03 P6
U 1 1 583EC068
P 10250 1350
F 0 "P6" H 10250 1550 50  0000 C CNN
F 1 "CONN_01X03" V 10350 1350 50  0000 C CNN
F 2 "Additional:ESQ-103-12-G-S-LL" H 10250 1350 50  0001 C CNN
F 3 "https://www.samtec.com/products/esq" H 10250 1350 50  0001 C CNN
F 4 "ESQ-103-12-G-S-LL" H 10250 1350 60  0001 C CNN "Samtec"
	1    10250 1350
	0    1    -1   0   
$EndComp
Wire Wire Line
	1650 3550 1650 4350
Wire Wire Line
	1650 3450 2450 3450
Wire Wire Line
	2300 3950 2300 3900
Connection ~ 1650 3650
Wire Wire Line
	2300 3350 2300 3500
Connection ~ 2300 3450
Wire Wire Line
	2300 4300 2300 4250
Wire Wire Line
	1650 4300 2300 4300
Connection ~ 1650 4300
Wire Wire Line
	9900 1600 9900 1550
Wire Wire Line
	10250 1600 9900 1600
Wire Wire Line
	10250 1600 10250 1550
Wire Wire Line
	10150 1550 10150 1600
Connection ~ 10150 1600
$Comp
L CONN_01X04 P1
U 1 1 5841F1E1
P 1250 1400
F 0 "P1" H 1250 1650 50  0000 C CNN
F 1 "CONN_01X04" V 1350 1400 50  0000 C CNN
F 2 "Additional:ESQ-104-12-G-S-LL" H 1250 1400 50  0001 C CNN
F 3 "https://www.samtec.com/products/esq" H 1250 1400 50  0001 C CNN
F 4 "ESQ-104-12-G-S-LL" H 1250 1400 60  0001 C CNN "Samtec"
	1    1250 1400
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR1
U 1 1 583C8E04
P 1650 4350
F 0 "#PWR1" H 1650 4100 50  0001 C CNN
F 1 "GND" H 1650 4200 50  0000 C CNN
F 2 "" H 1650 4350 50  0000 C CNN
F 3 "" H 1650 4350 50  0000 C CNN
	1    1650 4350
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 58429064
P 2300 4100
F 0 "R1" V 2380 4100 50  0000 C CNN
F 1 "10k" V 2300 4100 50  0000 C CNN
F 2 "Additional:R_0603_HandSoldering_Same_As_C" V 2230 4100 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 2300 4100 50  0001 C CNN
F 4 " 311-10.0KHRCT-ND" V 2300 4100 60  0001 C CNN "Digikey"
	1    2300 4100
	1    0    0    -1  
$EndComp
Text GLabel 2450 3450 2    60   Output ~ 0
V20
$Comp
L PWR_FLAG #FLG2
U 1 1 58428672
P 2300 3350
F 0 "#FLG2" H 2300 3445 50  0001 C CNN
F 1 "PWR_FLAG" H 2300 3530 50  0000 C CNN
F 2 "" H 2300 3350 50  0000 C CNN
F 3 "" H 2300 3350 50  0000 C CNN
	1    2300 3350
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG1
U 1 1 5842A47B
P 1950 4200
F 0 "#FLG1" H 1950 4295 50  0001 C CNN
F 1 "PWR_FLAG" H 1950 4380 50  0000 C CNN
F 2 "" H 1950 4200 50  0000 C CNN
F 3 "" H 1950 4200 50  0000 C CNN
	1    1950 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 4200 1950 4300
Connection ~ 1950 4300
Text Notes 1150 3000 0    60   ~ 0
PWR_FLAG: No driver needed (done by ext. device).
$Sheet
S 5550 1200 1750 1050
U 5842E74F
F0 "Bucket Converters" 60
F1 "bucketConvs.sch" 60
F2 "V20" I L 5550 1350 60 
F3 "5V_EN" I L 5550 1550 60 
F4 "V5" O R 7300 1350 60 
F5 "V28" O R 7300 1550 60 
F6 "DM1" O R 7300 1750 60 
F7 "DP1" O R 7300 1900 60 
$EndSheet
$Sheet
S 5550 4650 1750 1050
U 58430075
F0 "Measuring Points for Probes" 60
F1 "measurePoints.sch" 60
F2 "ADC_OLED" I L 5550 4800 60 
F3 "ADC_R" I L 5550 4900 60 
F4 "ADC_B" I L 5550 5000 60 
F5 "ADC_G" I L 5550 5100 60 
F6 "PWM_OLED" I L 5550 5200 60 
F7 "PWM_R" I L 5550 5300 60 
F8 "PWM_B" I L 5550 5400 60 
F9 "PWM_G" I L 5550 5500 60 
$EndSheet
$Sheet
S 5550 2750 1750 1350
U 584304A2
F0 "LEDs" 60
F1 "leds.sch" 60
F2 "V20" I L 5550 2900 60 
F3 "PWM_R" I L 5550 3100 60 
F4 "PWM_B" I L 5550 3200 60 
F5 "PWM_G" I L 5550 3300 60 
F6 "ADC_R" O R 7300 3100 60 
F7 "ADC_B" O R 7300 3200 60 
F8 "ADC_G" O R 7300 3300 60 
F9 "PWM_OLED" I L 5550 3450 60 
F10 "ADC_OLED" O R 7300 3450 60 
F11 "VOLED" O R 7300 3550 60 
F12 "LED_R" O R 7300 3700 60 
F13 "LED_B" O R 7300 3800 60 
F14 "LED_G" O R 7300 3900 60 
F15 "LED_GND" O R 7300 4000 60 
$EndSheet
$Comp
L USB_A P4
U 1 1 584373B8
P 10050 3450
F 0 "P4" H 10250 3250 50  0000 C CNN
F 1 "USB_A" H 10000 3650 50  0000 C CNN
F 2 "Connect:USB_A" V 10000 3350 50  0001 C CNN
F 3 "http://portal.fciconnect.com/Comergent//fci/drawing/87520.pdf" V 10000 3350 50  0001 C CNN
F 4 "609-1045-ND" H 10050 3450 60  0001 C CNN "Digikey"
	1    10050 3450
	0    1    1    0   
$EndComp
Text Notes 10450 5710 2    60   ~ 0
Power for µC\n
$Comp
L CONN_01X03 P5
U 1 1 584384F7
P 10150 5450
F 0 "P5" H 10150 5650 50  0000 C CNN
F 1 "CONN_01X03" V 10250 5450 50  0000 C CNN
F 2 "Additional:ESQ-103-12-G-S-LL" H 10150 5450 50  0001 C CNN
F 3 "https://www.samtec.com/products/esq" H 10150 5450 50  0001 C CNN
F 4 "ESQ-103-12-G-S-LL" H 10150 5450 60  0001 C CNN "Samtec"
	1    10150 5450
	0    -1   1    0   
$EndComp
Text GLabel 10150 5250 1    60   Output ~ 0
5V_EN
Text GLabel 5350 1350 0    60   Input ~ 0
V20
Wire Wire Line
	5350 1350 5550 1350
Text GLabel 5400 1550 0    60   Input ~ 0
5V_EN
Wire Wire Line
	5400 1550 5550 1550
Text GLabel 5400 2900 0    60   Input ~ 0
V20
Wire Wire Line
	5400 2900 5550 2900
Wire Wire Line
	5400 3100 5550 3100
Wire Wire Line
	5400 3200 5550 3200
Wire Wire Line
	5400 3300 5550 3300
Wire Wire Line
	5400 3450 5550 3450
Text GLabel 1400 1600 3    60   Output ~ 0
PWM_OLED
Text GLabel 1300 1600 3    60   Output ~ 0
PWM_G
Text GLabel 1200 1600 3    60   Output ~ 0
PWM_B
Text GLabel 1100 1600 3    60   Output ~ 0
PWM_R
Text GLabel 5400 5100 0    60   Input ~ 0
ADC_G
Text GLabel 5400 5000 0    60   Input ~ 0
ADC_B
Text GLabel 5400 4900 0    60   Input ~ 0
ADC_R
Text GLabel 5400 4800 0    60   Input ~ 0
ADC_OLED
Wire Wire Line
	5400 4800 5550 4800
Wire Wire Line
	5400 4900 5550 4900
Wire Wire Line
	5400 5000 5550 5000
Wire Wire Line
	5400 5100 5550 5100
Text GLabel 5400 5200 0    60   Input ~ 0
PWM_OLED
Wire Wire Line
	5400 5200 5550 5200
Text GLabel 5400 5500 0    60   Input ~ 0
PWM_G
Text GLabel 5400 5400 0    60   Input ~ 0
PWM_B
Text GLabel 5400 5300 0    60   Input ~ 0
PWM_R
Wire Wire Line
	5400 5300 5550 5300
Wire Wire Line
	5400 5400 5550 5400
Wire Wire Line
	5400 5500 5550 5500
$Comp
L GND #PWR3
U 1 1 58444C94
P 9800 5250
F 0 "#PWR3" H 9800 5000 50  0001 C CNN
F 1 "GND" H 9800 5100 50  0000 C CNN
F 2 "" H 9800 5250 50  0000 C CNN
F 3 "" H 9800 5250 50  0000 C CNN
	1    9800 5250
	1    0    0    1   
$EndComp
Wire Wire Line
	10050 5250 9800 5250
Text GLabel 10250 5250 1    60   Input ~ 0
V28
Text GLabel 7500 1550 2    60   Output ~ 0
V28
Text GLabel 7500 1350 2    60   Output ~ 0
V5
Text GLabel 9750 3250 0    60   Input ~ 0
V5
$Comp
L GND #PWR2
U 1 1 58446B04
P 9750 3800
F 0 "#PWR2" H 9750 3550 50  0001 C CNN
F 1 "GND" H 9750 3650 50  0000 C CNN
F 2 "" H 9750 3800 50  0000 C CNN
F 3 "" H 9750 3800 50  0000 C CNN
	1    9750 3800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9750 3550 9750 3800
Wire Wire Line
	9750 3750 10150 3750
Connection ~ 9750 3750
Text GLabel 7500 3100 2    60   Output ~ 0
ADC_R
Text GLabel 7500 3200 2    60   Output ~ 0
ADC_B
Text GLabel 7500 3300 2    60   Output ~ 0
ADC_G
Text GLabel 7500 3450 2    60   Output ~ 0
ADC_OLED
Text GLabel 7500 3550 2    60   Output ~ 0
VOLED
Wire Wire Line
	7300 3550 7500 3550
Wire Wire Line
	7500 3450 7300 3450
Wire Wire Line
	7300 3300 7500 3300
Wire Wire Line
	7500 3200 7300 3200
Wire Wire Line
	7300 3100 7500 3100
Text Notes 3100 1200 0    60   ~ 0
LED
Text GLabel 7500 3700 2    60   Output ~ 0
LED_R
Text GLabel 7500 3800 2    60   Output ~ 0
LED_B
Text GLabel 7500 3900 2    60   Output ~ 0
LED_G
Wire Wire Line
	7300 3700 7500 3700
Wire Wire Line
	7300 3800 7500 3800
Wire Wire Line
	7300 3900 7500 3900
Text GLabel 7500 4000 2    60   Output ~ 0
LED_GND
Wire Wire Line
	7500 4000 7300 4000
Text GLabel 3450 1600 3    60   Input ~ 0
LED_R
Text GLabel 3350 1600 3    60   Input ~ 0
LED_B
Text GLabel 3250 1600 3    60   Input ~ 0
LED_G
Text GLabel 3150 1600 3    60   Input ~ 0
LED_GND
$Comp
L CONN_01X04 P3
U 1 1 58452B47
P 3300 1400
F 0 "P3" H 3300 1650 50  0000 C CNN
F 1 "CONN_01X04" V 3400 1400 50  0000 C CNN
F 2 "Additional:LED_CONN_1.25_PITCH" H 3300 1400 50  0001 C CNN
F 3 "" H 3300 1400 50  0001 C CNN
	1    3300 1400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7500 1350 7300 1350
Wire Wire Line
	7300 1550 7500 1550
Text GLabel 7500 1750 2    60   Output ~ 0
D-
Text GLabel 7500 1900 2    60   Output ~ 0
D+
Wire Wire Line
	7300 1900 7500 1900
Wire Wire Line
	7300 1750 7500 1750
Text GLabel 9750 3350 0    60   Input ~ 0
D-
Text GLabel 9750 3450 0    60   Input ~ 0
D+
$EndSCHEMATC
