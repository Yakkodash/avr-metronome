EESchema Schematic File Version 4
LIBS:display-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR02
U 1 1 5C36EC35
P 4200 4550
F 0 "#PWR02" H 4200 4300 50  0001 C CNN
F 1 "GND" H 4200 4400 50  0000 C CNN
F 2 "" H 4200 4550 50  0000 C CNN
F 3 "" H 4200 4550 50  0000 C CNN
	1    4200 4550
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:CC56-12SRWA U2
U 1 1 5C376772
P 6000 3750
F 0 "U2" H 6000 4417 50  0000 C CNN
F 1 "CC56-12SRWA" H 6000 4326 50  0000 C CNN
F 2 "Display_7Segment:CA56-12SRWA" H 6000 3150 50  0001 C CNN
F 3 "http://www.kingbrightusa.com/images/catalog/SPEC/CC56-12SRWA.pdf" H 5570 3780 50  0001 C CNN
	1    6000 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 3450 4900 3450
Wire Wire Line
	4600 3650 4900 3650
Wire Wire Line
	4600 3750 4900 3750
Wire Wire Line
	4600 3850 4900 3850
Wire Wire Line
	4600 4150 4900 4150
NoConn ~ 4600 4350
$Comp
L 74xx:74HC595 U1
U 1 1 5C37799C
P 4200 3850
F 0 "U1" H 4200 4628 50  0000 C CNN
F 1 "74HC595" H 4200 4537 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 4200 3850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 4200 3850 50  0001 C CNN
	1    4200 3850
	1    0    0    -1  
$EndComp
Text GLabel 3800 3450 0    50   Input ~ 0
SPI_MOSI
Text GLabel 3800 3650 0    50   Input ~ 0
SPI_SCK
Text GLabel 3800 3950 0    50   Input ~ 0
SPI_NSS
Connection ~ 4200 4550
$Comp
L power:+5V #PWR01
U 1 1 5C377D18
P 3800 3200
F 0 "#PWR01" H 3800 3050 50  0001 C CNN
F 1 "+5V" H 3815 3373 50  0000 C CNN
F 2 "" H 3800 3200 50  0001 C CNN
F 3 "" H 3800 3200 50  0001 C CNN
	1    3800 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 3750 3800 3750
Wire Wire Line
	3350 3200 3800 3200
$Comp
L Device:R R4
U 1 1 5C3A4A47
P 7500 3550
F 0 "R4" V 7293 3550 50  0000 C CNN
F 1 "330" V 7384 3550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7430 3550 50  0001 C CNN
F 3 "~" H 7500 3550 50  0001 C CNN
	1    7500 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5C3A4BCB
P 7500 3850
F 0 "R5" V 7293 3850 50  0000 C CNN
F 1 "330" V 7384 3850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7430 3850 50  0001 C CNN
F 3 "~" H 7500 3850 50  0001 C CNN
	1    7500 3850
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5C3A4C2B
P 7500 4150
F 0 "R6" V 7293 4150 50  0000 C CNN
F 1 "330" V 7384 4150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7430 4150 50  0001 C CNN
F 3 "~" H 7500 4150 50  0001 C CNN
	1    7500 4150
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 5C3A4C8D
P 7500 4450
F 0 "R7" V 7293 4450 50  0000 C CNN
F 1 "330" V 7384 4450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7430 4450 50  0001 C CNN
F 3 "~" H 7500 4450 50  0001 C CNN
	1    7500 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	7100 3850 7200 3850
Wire Wire Line
	7200 3850 7200 3550
Wire Wire Line
	7200 3550 7350 3550
Wire Wire Line
	7100 3950 7250 3950
Wire Wire Line
	7250 3950 7250 3850
Wire Wire Line
	7250 3850 7350 3850
Wire Wire Line
	7100 4050 7250 4050
Wire Wire Line
	7250 4050 7250 4150
Wire Wire Line
	7250 4150 7350 4150
Wire Wire Line
	7100 4150 7200 4150
Wire Wire Line
	7200 4150 7200 4450
Wire Wire Line
	7200 4450 7350 4450
Wire Wire Line
	4200 3250 4200 3200
Wire Wire Line
	4200 3200 3800 3200
Connection ~ 3800 3200
Wire Wire Line
	3350 3200 3350 3750
Wire Wire Line
	3800 4050 3750 4050
Wire Wire Line
	3750 4050 3750 4550
Wire Wire Line
	3750 4550 4200 4550
Text GLabel 7650 3550 2    50   Input Italic 0
DIG0
Text GLabel 7650 3850 2    50   Input Italic 0
DIG1
Text GLabel 7650 4150 2    50   Input Italic 0
DIG2
Text GLabel 7650 4450 2    50   Input Italic 0
DIG3
Text GLabel 6800 5400 0    50   Output ~ 0
SPI_MOSI
Text GLabel 6800 5700 0    50   Output ~ 0
SPI_SCK
Text GLabel 6800 5600 0    50   Output ~ 0
SPI_NSS
Text GLabel 8000 5500 2    50   Output ~ 0
DIG0
Text GLabel 8000 5600 2    50   Output ~ 0
DIG1
Text GLabel 8000 5700 2    50   Output ~ 0
DIG2
Text GLabel 8000 5400 2    50   Output ~ 0
DIG3
$Comp
L Connector:Conn_01x04_Male J2
U 1 1 5DB30AED
P 7800 5500
F 0 "J2" H 7906 5778 50  0000 C CNN
F 1 "Conn_01x04_Male" H 7906 5687 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7800 5500 50  0001 C CNN
F 3 "~" H 7800 5500 50  0001 C CNN
	1    7800 5500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Male J1
U 1 1 5DB32951
P 7000 5600
F 0 "J1" H 7250 5200 50  0000 R CNN
F 1 "Conn_01x05_Male" H 7550 5300 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 7000 5600 50  0001 C CNN
F 3 "~" H 7000 5600 50  0001 C CNN
	1    7000 5600
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5DB33DBE
P 6200 5800
F 0 "#FLG02" H 6200 5875 50  0001 C CNN
F 1 "PWR_FLAG" H 6200 5973 50  0000 C CNN
F 2 "" H 6200 5800 50  0001 C CNN
F 3 "~" H 6200 5800 50  0001 C CNN
	1    6200 5800
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5DB33E10
P 6200 5500
F 0 "#FLG01" H 6200 5575 50  0001 C CNN
F 1 "PWR_FLAG" H 6200 5674 50  0000 C CNN
F 2 "" H 6200 5500 50  0001 C CNN
F 3 "~" H 6200 5500 50  0001 C CNN
	1    6200 5500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 5DB34C1D
P 5900 5800
F 0 "#PWR04" H 5900 5650 50  0001 C CNN
F 1 "+5V" H 5915 5973 50  0000 C CNN
F 2 "" H 5900 5800 50  0001 C CNN
F 3 "" H 5900 5800 50  0001 C CNN
	1    5900 5800
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5DB34C74
P 5900 5500
F 0 "#PWR03" H 5900 5250 50  0001 C CNN
F 1 "GND" H 5905 5327 50  0000 C CNN
F 2 "" H 5900 5500 50  0001 C CNN
F 3 "" H 5900 5500 50  0001 C CNN
	1    5900 5500
	-1   0    0    1   
$EndComp
Wire Wire Line
	5900 5500 6200 5500
Connection ~ 6200 5500
Wire Wire Line
	6200 5500 6800 5500
Wire Wire Line
	5900 5800 6200 5800
Connection ~ 6200 5800
Wire Wire Line
	6200 5800 6800 5800
$Comp
L Device:R R1
U 1 1 5DB5C04C
P 4750 3550
F 0 "R1" V 4543 3550 50  0000 C CNN
F 1 "0" V 4634 3550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 3550 50  0001 C CNN
F 3 "~" H 4750 3550 50  0001 C CNN
	1    4750 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5DB5C610
P 4750 3950
F 0 "R2" V 4543 3950 50  0000 C CNN
F 1 "0" V 4634 3950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4680 3950 50  0001 C CNN
F 3 "~" H 4750 3950 50  0001 C CNN
	1    4750 3950
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5DB5C67D
P 4750 4050
F 0 "R3" V 4543 4050 50  0000 C CNN
F 1 "0" V 4634 4050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4680 4050 50  0001 C CNN
F 3 "~" H 4750 4050 50  0001 C CNN
	1    4750 4050
	0    1    1    0   
$EndComp
$EndSCHEMATC
