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
Sheet 1 2
Title "Power Board "
Date "2016-12-02"
Rev "1.0"
Comp "Uppsala University"
Comment1 "Project: Swakeup"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 2306 3594 1044 1256
U 58375294
F0 "RGB LED Driver " 60
F1 "rgbLedDriver.sch" 60
F2 "LED_G_P" O R 3350 4600 60 
F3 "LED_G_N" O R 3350 4700 60 
F4 "OPAMP_G" O R 3350 4800 60 
F5 "PWM_B" I L 2306 4250 60 
F6 "LED_B_P" O R 3350 4250 60 
F7 "LED_B_N" O R 3350 4350 60 
F8 "OPAMP_B" O R 3350 4450 60 
F9 "PWM_R" I L 2306 3850 60 
F10 "LED_R_P" O R 3350 3850 60 
F11 "LED_R_N" O R 3350 3950 60 
F12 "OPAMP_R" O R 3350 4050 60 
F13 "V20" I L 2306 3700 60 
F14 "PWM_G" I L 2306 4600 60 
$EndSheet
$Comp
L LM324QT U2
U 1 1 5838BEE1
P 5750 4250
F 0 "U2" H 6200 3400 60  0000 C CNN
F 1 "LM324QT" H 5450 3400 60  0000 C CNN
F 2 "Additional:QFN-16-1EP_3x3mm_Pitch0.5mm" H 5750 4250 60  0001 C CNN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/58/13/52/7e/39/8c/4c/ba/CD00000457.pdf/files/CD00000457.pdf/jcr:content/translations/en.CD00000457.pdf" H 5750 4250 60  0001 C CNN
F 4 "497-12005-1-ND" H 5750 4250 60  0001 C CNN "Digikey"
	1    5750 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5838E9B2
P 4250 3750
F 0 "#PWR01" H 4250 3500 50  0001 C CNN
F 1 "GND" H 4250 3600 50  0000 C CNN
F 2 "" H 4250 3750 50  0000 C CNN
F 3 "" H 4250 3750 50  0000 C CNN
	1    4250 3750
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5838F1C9
P 4700 4850
F 0 "R4" V 4780 4850 50  0000 C CNN
F 1 "120k" V 4700 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4630 4850 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4700 4850 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 4700 4850 60  0001 C CNN "Digikey"
	1    4700 4850
	0    1    1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 5838F3B3
P 4100 4950
F 0 "#PWR02" H 4100 4700 50  0001 C CNN
F 1 "GND" H 4100 4800 50  0000 C CNN
F 2 "" H 4100 4950 50  0000 C CNN
F 3 "" H 4100 4950 50  0000 C CNN
	1    4100 4950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 58391691
P 7350 4900
F 0 "#PWR03" H 7350 4650 50  0001 C CNN
F 1 "GND" H 7350 4750 50  0000 C CNN
F 2 "" H 7350 4900 50  0000 C CNN
F 3 "" H 7350 4900 50  0000 C CNN
	1    7350 4900
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P3
U 1 1 58392B4F
P 3650 3050
F 0 "P3" H 3650 3300 50  0000 C CNN
F 1 "CONN_01X04" V 3750 3050 50  0000 C CNN
F 2 "Connect:PINHEAD1-3" H 3650 3050 50  0001 C CNN
F 3 "http://www.on-shore.com/wp-content/uploads/2015/09/ostvnxxa150.pdf" H 3650 3050 50  0001 C CNN
F 4 "ED10563-ND" H 3650 3050 60  0001 C CNN "Digikey"
	1    3650 3050
	0    -1   -1   0   
$EndComp
$Comp
L R R8
U 1 1 58394867
P 6750 3650
F 0 "R8" V 6830 3650 50  0000 C CNN
F 1 "240k" V 6750 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6680 3650 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 6750 3650 50  0001 C CNN
F 4 "311-240KHRCT-ND" V 6750 3650 60  0001 C CNN "Digikey"
	1    6750 3650
	0    1    1    0   
$EndComp
$Comp
L R R15
U 1 1 58394912
P 7250 3650
F 0 "R15" V 7330 3650 50  0000 C CNN
F 1 "39k" V 7250 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7180 3650 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7250 3650 50  0001 C CNN
F 4 "311-39.0KHRCT-ND" V 7250 3650 60  0001 C CNN "Digikey"
	1    7250 3650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR04
U 1 1 58394C0A
P 7400 3950
F 0 "#PWR04" H 7400 3700 50  0001 C CNN
F 1 "GND" H 7400 3800 50  0000 C CNN
F 2 "" H 7400 3950 50  0000 C CNN
F 3 "" H 7400 3950 50  0000 C CNN
	1    7400 3950
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 58394FC2
P 7750 4200
F 0 "R17" V 7830 4200 50  0000 C CNN
F 1 "47k" V 7750 4200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7680 4200 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7750 4200 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 7750 4200 60  0001 C CNN "Digikey"
	1    7750 4200
	0    1    1    0   
$EndComp
$Comp
L C C7
U 1 1 583951CE
P 7950 4450
F 0 "C7" H 7975 4550 50  0000 L CNN
F 1 "10n" H 7975 4350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7988 4300 50  0001 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 7950 4450 50  0001 C CNN
F 4 "311-1085-1-ND" H 7950 4450 60  0001 C CNN "Digikey"
	1    7950 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 58395B51
P 8750 4700
F 0 "#PWR05" H 8750 4450 50  0001 C CNN
F 1 "GND" H 8750 4550 50  0000 C CNN
F 2 "" H 8750 4700 50  0000 C CNN
F 3 "" H 8750 4700 50  0000 C CNN
	1    8750 4700
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 583964BE
P 4400 3650
F 0 "R3" V 4480 3650 50  0000 C CNN
F 1 "3.9k" V 4400 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4330 3650 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4400 3650 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 4400 3650 60  0001 C CNN "Digikey"
	1    4400 3650
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 583968F2
P 4800 3650
F 0 "R5" V 4880 3650 50  0000 C CNN
F 1 "120k" V 4800 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4730 3650 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4800 3650 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 4800 3650 60  0001 C CNN "Digikey"
	1    4800 3650
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 583969A3
P 6750 4850
F 0 "R9" V 6830 4850 50  0000 C CNN
F 1 "120k" V 6750 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6680 4850 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 6750 4850 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 6750 4850 60  0001 C CNN "Digikey"
	1    6750 4850
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 58396C86
P 4250 4850
F 0 "R2" V 4330 4850 50  0000 C CNN
F 1 "3.9k" V 4250 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4180 4850 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4250 4850 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 4250 4850 60  0001 C CNN "Digikey"
	1    4250 4850
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 58396D3B
P 7200 4850
F 0 "R13" V 7280 4850 50  0000 C CNN
F 1 "3.9k" V 7200 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7130 4850 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7200 4850 50  0001 C CNN
F 4 "311-3.90KHRCT-ND" V 7200 4850 60  0001 C CNN "Digikey"
	1    7200 4850
	0    1    1    0   
$EndComp
$Comp
L R R18
U 1 1 58398205
P 8150 4200
F 0 "R18" V 8230 4200 50  0000 C CNN
F 1 "47k" V 8150 4200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8080 4200 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8150 4200 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 8150 4200 60  0001 C CNN "Digikey"
	1    8150 4200
	0    1    1    0   
$EndComp
$Comp
L R R19
U 1 1 5839829C
P 8550 4200
F 0 "R19" V 8630 4200 50  0000 C CNN
F 1 "47k" V 8550 4200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8480 4200 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 8550 4200 50  0001 C CNN
F 4 "311-47.0KHRCT-ND" V 8550 4200 60  0001 C CNN "Digikey"
	1    8550 4200
	0    1    1    0   
$EndComp
$Comp
L C C9
U 1 1 583984D9
P 8350 4450
F 0 "C9" H 8375 4550 50  0000 L CNN
F 1 "10n" H 8375 4350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8388 4300 50  0001 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 8350 4450 50  0001 C CNN
F 4 "311-1085-1-ND" H 8350 4450 60  0001 C CNN "Digikey"
	1    8350 4450
	1    0    0    -1  
$EndComp
Text GLabel 8900 4200 2    60   Input ~ 0
PWM_OLED
$Comp
L C C10
U 1 1 58399326
P 8750 4450
F 0 "C10" H 8775 4550 50  0000 L CNN
F 1 "10n" H 8775 4350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8788 4300 50  0001 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 8750 4450 50  0001 C CNN
F 4 "311-1085-1-ND" H 8750 4450 60  0001 C CNN "Digikey"
	1    8750 4450
	1    0    0    -1  
$EndComp
Text GLabel 4900 4250 0    60   Input ~ 0
V20
$Comp
L GND #PWR06
U 1 1 5839C2CB
P 6650 4250
F 0 "#PWR06" H 6650 4000 50  0001 C CNN
F 1 "GND" H 6650 4100 50  0000 C CNN
F 2 "" H 6650 4250 50  0000 C CNN
F 3 "" H 6650 4250 50  0000 C CNN
	1    6650 4250
	1    0    0    -1  
$EndComp
Text Notes 7650 4100 0    60   ~ 0
Non-Invert. Amp.\n-----------------------\nA=(240k + 39k)/39k =7.154\nVin,max=2.8 V\nVout,max=20.031V
Text Notes 4050 5750 0    60   ~ 0
Non-Inv. Amp.\n-----------------------\nA=(3.9k+120k)/3.9k =31.769\nVin,max=30 mV\nVout,max=953.077 mV\nVref = 1.0 V
NoConn ~ 6300 6300
NoConn ~ 6300 6400
$Comp
L CONN_01X04 P2
U 1 1 583C3625
P 1100 1050
F 0 "P2" H 1100 1300 50  0000 C CNN
F 1 "CONN_01X04" V 1200 1050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 1100 1050 50  0001 C CNN
F 3 "http://www.sullinscorp.com/drawings/78_P(N)PxCxxxLFBN-RC,_10492-H.pdf" H 1100 1050 50  0001 C CNN
F 4 "S7002-ND " H 1100 1050 60  0001 C CNN "Digikey"
	1    1100 1050
	0    -1   -1   0   
$EndComp
$Comp
L BARREL_JACK CON1
U 1 1 583C4079
P 3100 1450
F 0 "CON1" H 3100 1700 50  0000 C CNN
F 1 "BARREL_JACK" H 3100 1250 50  0000 C CNN
F 2 "Additional:PJ-047BH_BARREL_JACK" H 3100 1450 50  0001 C CNN
F 3 "http://www.cui.com/product/resource/digikeypdf/pj-047bh.pdf" H 3100 1450 50  0001 C CNN
F 4 "CP-047BH-ND" H 3100 1450 60  0001 C CNN "Digikey"
	1    3100 1450
	1    0    0    -1  
$EndComp
Text Notes 900  850  0    60   ~ 0
ADC
Text Notes 800  3300 0    60   ~ 0
PWM
Text Notes 10300 4300 2    60   ~ 0
SCREEN
Text Notes 10200 1000 0    60   ~ 0
Power for µC\n
$Comp
L R R7
U 1 1 583CB81C
P 6750 3050
F 0 "R7" V 6830 3050 50  0000 C CNN
F 1 "120k" V 6750 3050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6680 3050 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 6750 3050 50  0001 C CNN
F 4 "311-120KHRCT-ND" V 6750 3050 60  0001 C CNN "Digikey"
	1    6750 3050
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 583CC0A2
P 7250 3050
F 0 "R14" V 7330 3050 50  0000 C CNN
F 1 "2.7k" V 7250 3050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7180 3050 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7250 3050 50  0001 C CNN
F 4 "311-2.70KHRCT-ND" V 7250 3050 60  0001 C CNN "Digikey"
	1    7250 3050
	0    1    1    0   
$EndComp
$Comp
L R R16
U 1 1 583CC264
P 7600 3050
F 0 "R16" V 7680 3050 50  0000 C CNN
F 1 "3.3k" V 7600 3050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7530 3050 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7600 3050 50  0001 C CNN
F 4 "311-3.30KHRCT-ND" V 7600 3050 60  0001 C CNN "Digikey"
	1    7600 3050
	0    1    1    0   
$EndComp
$Comp
L GND #PWR07
U 1 1 583CC537
P 7750 3450
F 0 "#PWR07" H 7750 3200 50  0001 C CNN
F 1 "GND" H 7750 3300 50  0000 C CNN
F 2 "" H 7750 3450 50  0000 C CNN
F 3 "" H 7750 3450 50  0000 C CNN
	1    7750 3450
	1    0    0    -1  
$EndComp
Text GLabel 1200 2850 1    60   Output ~ 0
PWM_OLED
Text GLabel 1100 2850 1    60   Output ~ 0
PWM_G
Text GLabel 1000 2850 1    60   Output ~ 0
PWM_B
Text GLabel 900  2850 1    60   Output ~ 0
PWM_R
Text GLabel 2150 3850 0    60   Input ~ 0
PWM_R
Text GLabel 2150 4250 0    60   Input ~ 0
PWM_B
Text GLabel 2150 4600 0    60   Input ~ 0
PWM_G
Text GLabel 2000 3700 0    60   Input ~ 0
V20
Text GLabel 7100 2900 2    60   Output ~ 0
ADC_OLED
Text GLabel 6700 5050 2    60   Output ~ 0
ADC_G
Text GLabel 4750 5050 0    60   Output ~ 0
ADC_B
Text GLabel 4800 3250 0    60   Output ~ 0
ADC_R
$Comp
L GND #PWR08
U 1 1 583EB242
P 10550 3850
F 0 "#PWR08" H 10550 3600 50  0001 C CNN
F 1 "GND" H 10550 3700 50  0000 C CNN
F 2 "" H 10550 3850 50  0000 C CNN
F 3 "" H 10550 3850 50  0000 C CNN
	1    10550 3850
	-1   0    0    -1  
$EndComp
Text GLabel 7100 2700 2    60   Output ~ 0
VOLED
Text GLabel 1150 1250 3    60   Input ~ 0
ADC_G
Text GLabel 1050 1250 3    60   Input ~ 0
ADC_B
Text GLabel 950  1250 3    60   Input ~ 0
ADC_R
Text GLabel 1250 1250 3    60   Input ~ 0
ADC_OLED
Text GLabel 10100 3850 1    60   Input ~ 0
VOLED
$Comp
L GND #PWR09
U 1 1 58404317
P 1150 6450
F 0 "#PWR09" H 1150 6200 50  0001 C CNN
F 1 "GND" H 1150 6300 50  0000 C CNN
F 2 "" H 1150 6450 50  0000 C CNN
F 3 "" H 1150 6450 50  0000 C CNN
	1    1150 6450
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 5840431E
P 5100 6450
F 0 "C3" H 5125 6550 50  0000 L CNN
F 1 "22u" H 5125 6350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5138 6300 50  0001 C CNN
F 3 "http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2016/08/18/S_CL10A226MQ8NRNC.pdf" H 5100 6450 50  0001 C CNN
F 4 "1276-1193-1-ND" H 5100 6450 60  0001 C CNN "Digikey"
	1    5100 6450
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR L1
U 1 1 58404326
P 4600 6200
F 0 "L1" V 4550 6200 50  0000 C CNN
F 1 "4.7u" V 4700 6200 50  0000 C CNN
F 2 "Additional:Taiyo_Yuden_NRS8030_IND" H 4600 6200 50  0001 C CNN
F 3 "http://www.yuden.co.jp/productdata/catalog/en/wound04_e.pdf" H 4600 6200 50  0001 C CNN
F 4 "587-2969-1-ND " V 4600 6200 60  0001 C CNN "Digikey"
	1    4600 6200
	0    -1   -1   0   
$EndComp
$Comp
L C C1
U 1 1 58404357
P 1150 6200
F 0 "C1" H 1175 6300 50  0000 L CNN
F 1 "10u" H 1175 6100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1188 6050 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 1150 6200 50  0001 C CNN
F 4 "490-12323-1-ND" H 1150 6200 60  0001 C CNN "Digikey"
	1    1150 6200
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5840435F
P 3600 6400
F 0 "C2" H 3625 6500 50  0000 L CNN
F 1 "22n" H 3625 6300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3638 6250 50  0001 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 3600 6400 50  0001 C CNN
F 4 "445-8118-1-ND" H 3600 6400 60  0001 C CNN "Digikey"
	1    3600 6400
	0    -1   -1   0   
$EndComp
$Comp
L C C4
U 1 1 58404368
P 5500 6450
F 0 "C4" H 5525 6550 50  0000 L CNN
F 1 "22u" H 5525 6350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5538 6300 50  0001 C CNN
F 3 "http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2016/08/18/S_CL10A226MQ8NRNC.pdf" H 5500 6450 50  0001 C CNN
F 4 "1276-1193-1-ND" H 5500 6450 60  0001 C CNN "Digikey"
	1    5500 6450
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky D2
U 1 1 58404370
P 4200 6450
F 0 "D2" V 4150 6600 50  0000 C CNN
F 1 "VS-10MQ060NPbF" V 4250 6900 50  0000 C CNN
F 2 "Diodes_SMD:SMA_Handsoldering" H 4200 6450 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88869/packaging.pdf" H 4200 6450 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" V 4250 7050 60  0001 C CNN "Digikey"
	1    4200 6450
	0    1    1    0   
$EndComp
Text GLabel 1000 6000 0    60   Input ~ 0
V20
$Comp
L LM2840 U3
U 1 1 584064D4
P 7650 1550
F 0 "U3" H 7950 1300 60  0000 C CNN
F 1 "LM2840" H 7450 1300 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-6" H 7650 1550 60  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2841.pdf" H 7650 1550 60  0001 C CNN
F 4 "LM2840XMK-ADJL/NOPBTR-ND" H 7650 1550 60  0001 C CNN "Digikey"
	1    7650 1550
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 584064E5
P 7650 1100
F 0 "C6" H 7675 1200 50  0000 L CNN
F 1 "0.1u" H 7675 1000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7688 950 50  0001 C CNN
F 3 "http://www.yageo.com/documents/recent/UPY-GPHC_X7R_6.3V-to-50V_15.pdf" H 7650 1100 50  0001 C CNN
F 4 "311-1088-1-ND" H 7650 1100 60  0001 C CNN "Digikey"
	1    7650 1100
	0    1    1    0   
$EndComp
$Comp
L GND #PWR010
U 1 1 584064F9
P 7050 1550
F 0 "#PWR010" H 7050 1300 50  0001 C CNN
F 1 "GND" H 7050 1400 50  0000 C CNN
F 2 "" H 7050 1550 50  0000 C CNN
F 3 "" H 7050 1550 50  0000 C CNN
	1    7050 1550
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 58406504
P 8350 1850
F 0 "C8" H 8375 1950 50  0000 L CNN
F 1 "2.2u" H 8375 1750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8388 1700 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/partnumbering_e_01.pdf" H 8350 1850 50  0001 C CNN
F 4 "490-7204-1-ND" H 8350 1850 60  0001 C CNN "Digikey"
	1    8350 1850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 5840650B
P 8350 2600
F 0 "#PWR011" H 8350 2350 50  0001 C CNN
F 1 "GND" H 8350 2450 50  0000 C CNN
F 2 "" H 8350 2600 50  0000 C CNN
F 3 "" H 8350 2600 50  0000 C CNN
	1    8350 2600
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 58406515
P 6800 1750
F 0 "R10" V 6880 1750 50  0000 C CNN
F 1 "27k" V 6800 1750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6730 1750 50  0001 C CNN
F 3 "http://industrial.panasonic.com/www-cgi/jvcr13pz.cgi?E+PZ+3+AOA0002+ERJ3EKF2702V+7+WW" H 6800 1750 50  0001 C CNN
F 4 "P27.0KHCT-ND" V 6800 1750 60  0001 C CNN "Digikey"
	1    6800 1750
	0    1    1    0   
$EndComp
$Comp
L R R11
U 1 1 5840651D
P 7150 1950
F 0 "R11" V 7230 1950 50  0000 C CNN
F 1 "10k" V 7150 1950 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7080 1950 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7150 1950 50  0001 C CNN
F 4 " 311-10.0KHRCT-ND" V 7150 1950 60  0001 C CNN "Digikey"
	1    7150 1950
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 58406525
P 7150 2300
F 0 "R12" V 7230 2300 50  0000 C CNN
F 1 "150" V 7150 2300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7080 2300 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 7150 2300 50  0001 C CNN
F 4 "311-150HRCT-ND" V 7150 2300 60  0001 C CNN "Digikey"
	1    7150 2300
	1    0    0    -1  
$EndComp
Text Notes 6550 900  0    60   ~ 0
2.8 V for µC\n---------------------------\nVout=0.765 V (1 + (27k/ 10.15k))=2.8 V\n27k/10.15k= 2.66
$Comp
L INDUCTOR L2
U 1 1 5840653B
P 9350 1400
F 0 "L2" V 9300 1400 50  0000 C CNN
F 1 "33u" V 9450 1400 50  0000 C CNN
F 2 "Additional:Bourns_SRN3015" H 9350 1400 50  0001 C CNN
F 3 "http://www.bourns.com/docs/Product-Datasheets/SRN3015.pdf" H 9350 1400 50  0001 C CNN
F 4 "SRN3015-330MCT-ND" V 9500 850 60  0001 C CNN "Digikey"
	1    9350 1400
	0    -1   -1   0   
$EndComp
$Comp
L C C11
U 1 1 58406543
P 9700 1650
F 0 "C11" H 9725 1750 50  0000 L CNN
F 1 "10u" H 9725 1550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9738 1500 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 9700 1650 50  0001 C CNN
F 4 "490-12323-1-ND" H 9700 1650 60  0001 C CNN "Digikey"
	1    9700 1650
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 583CBBD3
P 5900 6450
F 0 "D3" H 5900 6550 50  0000 C CNN
F 1 "LED" H 5900 6350 50  0000 C CNN
F 2 "LEDs:LED_0603" H 5900 6450 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic0/00167682_0.pdf" H 5900 6450 50  0001 C CNN
F 4 "475-3118-1-ND" H 5900 6450 60  0001 C CNN "Digikey"
	1    5900 6450
	0    -1   -1   0   
$EndComp
$Comp
L R R6
U 1 1 583CBD96
P 5900 6900
F 0 "R6" V 5980 6900 50  0000 C CNN
F 1 "1.5k" V 5900 6900 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" V 5830 6900 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5900 6900 50  0001 C CNN
F 4 "311-1.5KGRCT-ND " V 5900 6900 60  0001 C CNN "Digikey"
	1    5900 6900
	1    0    0    -1  
$EndComp
Text Notes 5700 6100 0    60   ~ 0
Debugging Diode\n-----------------------\nDiode: 1.7 V, 2 mA\nP=7.26 mW\nCan be left out in a later version!
$Comp
L LED D5
U 1 1 583D31A7
P 10150 1650
F 0 "D5" H 10150 1750 50  0000 C CNN
F 1 "LED" H 10150 1550 50  0000 C CNN
F 2 "LEDs:LED_0603" H 10150 1650 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic0/00167682_0.pdf" H 10150 1650 50  0001 C CNN
F 4 "475-3118-1-ND" H 10150 1650 60  0001 C CNN "Digikey"
	1    10150 1650
	0    -1   -1   0   
$EndComp
$Comp
L R R20
U 1 1 583D31AD
P 10150 2050
F 0 "R20" V 10230 2050 50  0000 C CNN
F 1 "560R" V 10150 2050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 10080 2050 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 10150 2050 50  0001 C CNN
F 4 "311-560GRCT-ND" V 10150 2050 60  0001 C CNN "Digikey"
	1    10150 2050
	1    0    0    -1  
$EndComp
Text Notes 9450 3050 0    60   ~ 0
Debugging Diode\n-----------------------\nDiode: 1.7 V, 2 mA\nP=2.161 mW\nCan be left out in a later version!
$Comp
L LED D1
U 1 1 583D79A8
P 4050 1600
F 0 "D1" H 4050 1700 50  0000 C CNN
F 1 "LED" H 4050 1500 50  0000 C CNN
F 2 "LEDs:LED_0603" H 4050 1600 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic0/00167682_0.pdf" H 4050 1600 50  0001 C CNN
F 4 "475-3118-1-ND" H 4050 1600 60  0001 C CNN "Digikey"
	1    4050 1600
	0    -1   -1   0   
$EndComp
Text Notes 4450 1750 0    60   ~ 0
Debugging Diode\n-----------------------\nDiode: 1.7 V, 2 mA\nP=33.489 mW\nCan be left out in a later version!
$Comp
L CONN_01X03 P5
U 1 1 583EC068
P 10200 4050
F 0 "P5" H 10200 4250 50  0000 C CNN
F 1 "CONN_01X03" V 10300 4050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 10200 4050 50  0001 C CNN
F 3 "http://www.sullinscorp.com/drawings/78_P(N)PxCxxxLFBN-RC,_10492-H.pdf" H 10200 4050 50  0001 C CNN
F 4 "S7036-ND " H 10200 4050 60  0001 C CNN "Digikey"
	1    10200 4050
	0    -1   1    0   
$EndComp
Text GLabel 3450 6600 2    60   Input ~ 0
5V_EN
Text GLabel 10500 1400 3    60   Output ~ 0
5V_EN
$Comp
L C C5
U 1 1 5840706B
P 7050 3250
F 0 "C5" H 7075 3350 50  0000 L CNN
F 1 "10u" H 7075 3150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7088 3100 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 7050 3250 50  0001 C CNN
F 4 "490-12323-1-ND" H 7050 3250 60  0001 C CNN "Digikey"
	1    7050 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 3650 4250 3750
Wire Wire Line
	4100 4850 4100 4950
Wire Wire Line
	7350 4850 7350 4900
Wire Wire Line
	3500 3250 3500 3850
Wire Wire Line
	3500 3850 3350 3850
Wire Wire Line
	3350 4250 3600 4250
Wire Wire Line
	3600 4250 3600 3250
Wire Wire Line
	3350 4600 3700 4600
Wire Wire Line
	3700 4600 3700 3250
Wire Wire Line
	3800 4700 3350 4700
Wire Wire Line
	3800 4350 3350 4350
Connection ~ 3800 4350
Wire Wire Line
	3950 3450 3950 4800
Wire Wire Line
	7500 3450 7500 4450
Wire Wire Line
	7400 3650 7400 3950
Wire Wire Line
	7900 4200 8000 4200
Wire Wire Line
	8300 4200 8400 4200
Wire Wire Line
	7950 4650 8750 4650
Wire Wire Line
	7950 4650 7950 4600
Connection ~ 8750 4650
Wire Wire Line
	8350 4600 8350 4650
Connection ~ 8350 4650
Wire Wire Line
	7950 4300 7950 4200
Connection ~ 7950 4200
Wire Wire Line
	8350 4300 8350 4200
Connection ~ 8350 4200
Wire Wire Line
	6900 4200 7600 4200
Wire Wire Line
	8750 4600 8750 4700
Wire Wire Line
	8750 4300 8750 4200
Wire Wire Line
	8700 4200 8900 4200
Connection ~ 8750 4200
Wire Wire Line
	3350 3950 3800 3950
Connection ~ 3800 3950
Wire Wire Line
	3800 3250 3800 4700
Wire Wire Line
	4900 4250 5050 4250
Wire Wire Line
	7500 4450 6450 4450
Wire Wire Line
	6450 4250 6650 4250
Wire Wire Line
	6900 4050 6450 4050
Wire Wire Line
	6450 3850 7000 3850
Wire Wire Line
	3400 1450 3400 2250
Wire Wire Line
	3400 1350 4200 1350
Wire Wire Line
	6900 3050 7100 3050
Wire Wire Line
	7400 3050 7450 3050
Wire Wire Line
	7750 3050 7750 3450
Wire Wire Line
	2306 3850 2150 3850
Wire Wire Line
	2306 4250 2150 4250
Wire Wire Line
	2150 4600 2306 4600
Wire Wire Line
	2306 3700 2000 3700
Wire Wire Line
	6900 3650 7100 3650
Wire Wire Line
	7000 3850 7000 3650
Connection ~ 7000 3650
Wire Wire Line
	6450 3650 6600 3650
Wire Wire Line
	6600 3050 6550 3050
Wire Wire Line
	6550 2700 6550 3650
Connection ~ 6550 3650
Wire Wire Line
	6900 4050 6900 4200
Wire Wire Line
	6450 4850 6600 4850
Wire Wire Line
	6700 5050 6500 5050
Wire Wire Line
	6500 5050 6500 4850
Connection ~ 6500 4850
Wire Wire Line
	4850 4850 5050 4850
Wire Wire Line
	6900 4850 7050 4850
Wire Wire Line
	6450 4650 7000 4650
Wire Wire Line
	7000 4650 7000 4850
Connection ~ 7000 4850
Wire Wire Line
	4450 4850 4450 4650
Wire Wire Line
	4450 4650 5050 4650
Connection ~ 4450 4850
Wire Wire Line
	4400 4850 4550 4850
Wire Wire Line
	4750 5050 4950 5050
Wire Wire Line
	4950 5050 4950 4850
Connection ~ 4950 4850
Wire Wire Line
	3950 3450 7500 3450
Wire Wire Line
	4600 3850 5050 3850
Wire Wire Line
	4950 3650 5050 3650
Wire Wire Line
	4550 3650 4650 3650
Wire Wire Line
	4600 3650 4600 3850
Connection ~ 4600 3650
Wire Wire Line
	5000 3650 5000 3250
Connection ~ 5000 3650
Wire Wire Line
	5000 3250 4800 3250
Connection ~ 6550 3050
Wire Wire Line
	10600 2550 10600 1400
Wire Wire Line
	7100 2700 6550 2700
Wire Wire Line
	3350 4450 5050 4450
Wire Wire Line
	3350 4050 5050 4050
Wire Wire Line
	3950 4800 3350 4800
Wire Wire Line
	1150 6050 1150 6000
Connection ~ 1150 6000
Wire Wire Line
	1150 6350 1150 6450
Connection ~ 1150 6400
Wire Wire Line
	3250 6200 4300 6200
Connection ~ 5100 6200
Wire Wire Line
	4200 6300 4200 6200
Connection ~ 4200 6200
Wire Wire Line
	5100 6050 5100 6300
Wire Wire Line
	5500 6200 5500 6300
Wire Wire Line
	4200 6600 4200 7100
Wire Wire Line
	4200 7100 6300 7100
Wire Wire Line
	5500 7100 5500 6600
Wire Wire Line
	5100 6600 5100 7100
Connection ~ 5100 7100
Wire Wire Line
	1000 6000 1650 6000
Wire Wire Line
	1650 6200 1350 6200
Wire Wire Line
	1350 6200 1350 6400
Wire Wire Line
	1350 6400 1150 6400
Wire Wire Line
	3250 6400 3450 6400
Connection ~ 3900 6200
Wire Wire Line
	1650 6400 1500 6400
Wire Wire Line
	1500 6400 1500 7100
Wire Wire Line
	1500 7100 4050 7100
Wire Wire Line
	4050 7100 4050 6200
Connection ~ 4050 6200
Connection ~ 5500 6200
Wire Wire Line
	3450 6600 3250 6600
Wire Wire Line
	3900 6400 3750 6400
Wire Wire Line
	8150 1400 9050 1400
Wire Wire Line
	7150 1400 7150 1100
Wire Wire Line
	7150 1100 7500 1100
Wire Wire Line
	7800 1100 8200 1100
Wire Wire Line
	8200 1100 8200 1400
Connection ~ 8200 1400
Wire Wire Line
	9000 950  9000 1500
Connection ~ 9000 1400
Wire Wire Line
	9650 1400 10400 1400
Wire Wire Line
	9700 1400 9700 1500
Wire Wire Line
	9700 1850 9000 1850
Wire Wire Line
	9000 1850 9000 1800
Connection ~ 9700 1400
Wire Wire Line
	7050 1550 7150 1550
Wire Wire Line
	8150 1700 8250 1700
Wire Wire Line
	8250 1700 8250 1550
Connection ~ 8250 1550
Wire Wire Line
	8350 2000 8350 2600
Wire Wire Line
	8350 1550 8350 1700
Wire Wire Line
	7150 2150 7150 2100
Wire Wire Line
	7150 1700 7150 1800
Wire Wire Line
	7150 1750 6950 1750
Connection ~ 7150 1750
Wire Wire Line
	6550 1750 6550 950 
Wire Wire Line
	6550 950  9000 950 
Wire Wire Line
	6550 1750 6650 1750
Wire Wire Line
	7150 2550 10600 2550
Connection ~ 8350 2550
Connection ~ 9700 1850
Wire Wire Line
	7150 2550 7150 2450
Wire Wire Line
	9700 1800 9700 2550
Wire Wire Line
	6300 6500 6300 7200
Wire Wire Line
	8150 1550 8500 1550
Wire Wire Line
	6300 6700 6700 6700
Connection ~ 6300 6700
Connection ~ 6300 7100
Wire Wire Line
	5900 6650 5900 6750
Wire Wire Line
	5900 6250 5900 6200
Connection ~ 5900 6200
Wire Wire Line
	10150 1900 10150 1850
Wire Wire Line
	10150 2200 10150 2550
Wire Wire Line
	10150 1450 10150 1400
Connection ~ 10150 1400
Wire Wire Line
	4050 1850 4050 1800
Connection ~ 3400 1550
Wire Wire Line
	4050 1250 4050 1400
Connection ~ 4050 1350
Wire Wire Line
	4050 2150 4050 2200
Wire Wire Line
	4050 2200 3400 2200
Connection ~ 3400 2200
Wire Wire Line
	10550 3800 10550 3850
Wire Wire Line
	10200 3800 10550 3800
Wire Wire Line
	10200 3800 10200 3850
Wire Wire Line
	10300 3850 10300 3800
Connection ~ 10300 3800
Wire Wire Line
	6900 3250 6550 3250
Connection ~ 7750 3250
Connection ~ 6550 3250
Wire Wire Line
	7200 3250 7750 3250
Wire Wire Line
	7100 2900 7000 2900
Wire Wire Line
	7000 2900 7000 3050
Connection ~ 7000 3050
Text Notes 4800 3100 0    60   ~ 0
Voltage Divider\n-----------------------\nA=6k/120k = 20\nVin,max=20 V\nVout,max=1 V (reference of ADC)
Text Notes 3450 2850 0    60   ~ 0
LED
$Comp
L TS30012 U1
U 1 1 5840CF93
P 2400 6300
F 0 "U1" H 3050 5850 60  0000 C CNN
F 1 "TS30012" H 2000 5850 60  0000 C CNN
F 2 "Additional:QFN-16-1EP_3x3mm_Pitch0.5mm" H 2550 6300 60  0001 C CNN
F 3 "http://www.semtech.com/images/datasheet/ts30011_12_13.pdf" H 2550 6300 60  0001 C CNN
F 4 "TS30012-M050QFNRCT-ND " H 2400 6300 60  0001 C CNN "Digikey"
	1    2400 6300
	1    0    0    -1  
$EndComp
$Comp
L USB_A P4
U 1 1 5840F0EF
P 6600 6400
F 0 "P4" H 6800 6200 50  0000 C CNN
F 1 "USB_A" H 6550 6600 50  0000 C CNN
F 2 "Connect:USB_A" V 6550 6300 50  0001 C CNN
F 3 "http://portal.fciconnect.com/Comergent//fci/drawing/87520.pdf" V 6550 6300 50  0001 C CNN
F 4 "609-1045-ND" H 6600 6400 60  0001 C CNN "Digikey"
	1    6600 6400
	0    1    1    0   
$EndComp
Wire Wire Line
	5900 7050 5900 7100
Connection ~ 5900 7100
Connection ~ 5500 7100
Wire Wire Line
	3250 6000 3450 6000
Text Notes 2100 7550 0    60   ~ 0
5V for Mobile Phone\n-----------------------\nVout,max=5 V\nAout,max = 2A
Connection ~ 9700 2550
Connection ~ 10150 2550
$Comp
L CONN_01X04 P1
U 1 1 5841F1E1
P 1050 3050
F 0 "P1" H 1050 3300 50  0000 C CNN
F 1 "CONN_01X04" V 1150 3050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 1050 3050 50  0001 C CNN
F 3 "http://www.sullinscorp.com/drawings/78_P(N)PxCxxxLFBN-RC,_10492-H.pdf" H 1050 3050 50  0001 C CNN
F 4 "S7002-ND " H 1050 3050 60  0001 C CNN "Digikey"
	1    1050 3050
	0    1    1    0   
$EndComp
$Comp
L CONN_01X03 P6
U 1 1 58420A2F
P 10500 1200
F 0 "P6" H 10500 1400 50  0000 C CNN
F 1 "CONN_01X03" V 10600 1200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 10500 1200 50  0001 C CNN
F 3 "http://www.sullinscorp.com/drawings/78_P(N)PxCxxxLFBN-RC,_10492-H.pdf" H 10500 1200 50  0001 C CNN
F 4 "S7036-ND " H 10500 1200 60  0001 C CNN "Digikey"
	1    10500 1200
	0    1    -1   0   
$EndComp
$Comp
L D_Schottky D4
U 1 1 58425BA4
P 9000 1650
F 0 "D4" H 9450 1400 50  0000 C CNN
F 1 "VS-10MQ060NPbF" H 9150 1500 50  0000 C CNN
F 2 "Diodes_SMD:SMA_Handsoldering" H 9000 1650 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88869/packaging.pdf" H 9000 1650 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" V 9050 2250 60  0001 C CNN "Digikey"
	1    9000 1650
	0    1    1    0   
$EndComp
$Comp
L TEST_1P W9
U 1 1 5842D585
P 10050 6150
F 0 "W9" H 10050 6420 50  0000 C CNN
F 1 "TEST_1P" H 10050 6350 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 10250 6150 50  0001 C CNN
F 3 "" H 10250 6150 50  0000 C CNN
	1    10050 6150
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR012
U 1 1 583C8E04
P 3400 2250
F 0 "#PWR012" H 3400 2000 50  0001 C CNN
F 1 "GND" H 3400 2100 50  0000 C CNN
F 2 "" H 3400 2250 50  0000 C CNN
F 3 "" H 3400 2250 50  0000 C CNN
	1    3400 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 58417117
P 2450 6850
F 0 "#PWR013" H 2450 6600 50  0001 C CNN
F 1 "GND" H 2450 6700 50  0000 C CNN
F 2 "" H 2450 6850 50  0000 C CNN
F 3 "" H 2450 6850 50  0000 C CNN
	1    2450 6850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 584178EB
P 6300 7200
F 0 "#PWR014" H 6300 6950 50  0001 C CNN
F 1 "GND" H 6300 7050 50  0000 C CNN
F 2 "" H 6300 7200 50  0000 C CNN
F 3 "" H 6300 7200 50  0000 C CNN
	1    6300 7200
	1    0    0    -1  
$EndComp
$Comp
L TEST_1P W8
U 1 1 584207DF
P 10050 5800
F 0 "W8" H 10050 6070 50  0000 C CNN
F 1 "TEST_1P" H 10050 6000 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 10250 5800 50  0001 C CNN
F 3 "" H 10250 5800 50  0000 C CNN
	1    10050 5800
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W7
U 1 1 584208E1
P 10050 5450
F 0 "W7" H 10050 5720 50  0000 C CNN
F 1 "TEST_1P" H 10050 5650 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 10250 5450 50  0001 C CNN
F 3 "" H 10250 5450 50  0000 C CNN
	1    10050 5450
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W6
U 1 1 58420BC8
P 10050 5100
F 0 "W6" H 10050 5370 50  0000 C CNN
F 1 "TEST_1P" H 10050 5300 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 10250 5100 50  0001 C CNN
F 3 "" H 10250 5100 50  0000 C CNN
	1    10050 5100
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W5
U 1 1 58420E26
P 8750 6150
F 0 "W5" H 8750 6420 50  0000 C CNN
F 1 "TEST_1P" H 8750 6350 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 8950 6150 50  0001 C CNN
F 3 "" H 8950 6150 50  0000 C CNN
	1    8750 6150
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W4
U 1 1 58420E2C
P 8750 5800
F 0 "W4" H 8750 6070 50  0000 C CNN
F 1 "TEST_1P" H 8750 6000 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 8950 5800 50  0001 C CNN
F 3 "" H 8950 5800 50  0000 C CNN
	1    8750 5800
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W3
U 1 1 58420E32
P 8750 5450
F 0 "W3" H 8750 5720 50  0000 C CNN
F 1 "TEST_1P" H 8750 5650 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 8950 5450 50  0001 C CNN
F 3 "" H 8950 5450 50  0000 C CNN
	1    8750 5450
	0    -1   -1   0   
$EndComp
$Comp
L TEST_1P W2
U 1 1 58420E38
P 8750 5100
F 0 "W2" H 8750 5370 50  0000 C CNN
F 1 "TEST_1P" H 8750 5300 50  0000 C CNN
F 2 "Additional:TP_PROBE" H 8950 5100 50  0001 C CNN
F 3 "" H 8950 5100 50  0000 C CNN
	1    8750 5100
	0    -1   -1   0   
$EndComp
Text GLabel 8750 5450 2    60   Input ~ 0
ADC_G
Text GLabel 8750 5800 2    60   Input ~ 0
ADC_B
Text GLabel 8750 6150 2    60   Input ~ 0
ADC_R
Text GLabel 8750 5100 2    60   Input ~ 0
ADC_OLED
Text GLabel 10050 6150 2    60   Input ~ 0
PWM_OLED
Text GLabel 10050 5800 2    60   Input ~ 0
PWM_G
Text GLabel 10050 5450 2    60   Input ~ 0
PWM_B
Text GLabel 10050 5100 2    60   Input ~ 0
PWM_R
Text Notes 8850 6500 2    60   ~ 0
Test Points for the FBs.\nCan be left out in a later version!
Text Notes 10850 6500 2    60   ~ 0
Test Points for the PWM signals.\nCan be left out in a later version!
$Comp
L TEST_1P W1
U 1 1 584271DF
P 7900 5650
F 0 "W1" H 7900 5920 50  0000 C CNN
F 1 "TEST_1P" H 7900 5850 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Big" H 8100 5650 50  0001 C CNN
F 3 "" H 8100 5650 50  0000 C CNN
	1    7900 5650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5842733C
P 7900 5650
F 0 "#PWR015" H 7900 5400 50  0001 C CNN
F 1 "GND" H 7900 5500 50  0000 C CNN
F 2 "" H 7900 5650 50  0000 C CNN
F 3 "" H 7900 5650 50  0000 C CNN
	1    7900 5650
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 58429064
P 4050 2000
F 0 "R1" V 4130 2000 50  0000 C CNN
F 1 "10k" V 4050 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3980 2000 50  0001 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 4050 2000 50  0001 C CNN
F 4 " 311-10.0KHRCT-ND" V 4050 2000 60  0001 C CNN "Digikey"
	1    4050 2000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 5842DB84
P 3450 6000
F 0 "#PWR016" H 3450 5750 50  0001 C CNN
F 1 "GND" H 3450 5850 50  0000 C CNN
F 2 "" H 3450 6000 50  0000 C CNN
F 3 "" H 3450 6000 50  0000 C CNN
	1    3450 6000
	1    0    0    -1  
$EndComp
Text GLabel 8500 1550 2    60   Input ~ 0
V20
Connection ~ 8350 1550
Text GLabel 4200 1350 2    60   Output ~ 0
V20
Wire Wire Line
	3900 6200 3900 6400
Wire Wire Line
	6300 6200 4900 6200
$Comp
L PWR_FLAG #FLG017
U 1 1 58428672
P 4050 1250
F 0 "#FLG017" H 4050 1345 50  0001 C CNN
F 1 "PWR_FLAG" H 4050 1430 50  0000 C CNN
F 2 "" H 4050 1250 50  0000 C CNN
F 3 "" H 4050 1250 50  0000 C CNN
	1    4050 1250
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG018
U 1 1 584291FF
P 5100 6050
F 0 "#FLG018" H 5100 6145 50  0001 C CNN
F 1 "PWR_FLAG" H 5100 6230 50  0000 C CNN
F 2 "" H 5100 6050 50  0000 C CNN
F 3 "" H 5100 6050 50  0000 C CNN
	1    5100 6050
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG019
U 1 1 5842A47B
P 3700 2100
F 0 "#FLG019" H 3700 2195 50  0001 C CNN
F 1 "PWR_FLAG" H 3700 2280 50  0000 C CNN
F 2 "" H 3700 2100 50  0000 C CNN
F 3 "" H 3700 2100 50  0000 C CNN
	1    3700 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 2100 3700 2200
Connection ~ 3700 2200
Text Notes 2900 900  0    60   ~ 0
PWR_FLAG: No driver needed (done by ext. device).
$EndSCHEMATC
