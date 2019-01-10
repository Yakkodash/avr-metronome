EESchema Schematic File Version 4
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
Text GLabel 4150 1250 2    50   Input ~ 0
SPI_MOSI
Text GLabel 4150 1150 2    50   Input ~ 0
SPI_NSS
Text GLabel 4150 1450 2    50   Input ~ 0
SPI_SCK
Text GLabel 4150 1550 2    50   Input ~ 0
OSC1
Text GLabel 4150 1650 2    50   Input ~ 0
OSC2
Text GLabel 4150 3150 2    50   Input ~ 0
SOUND_OUT
$Comp
L power:GND #PWR?
U 1 1 5C36DEA9
P 6350 1150
F 0 "#PWR?" H 6350 900 50  0001 C CNN
F 1 "GND" H 6350 1000 50  0000 C CNN
F 2 "" H 6350 1150 50  0000 C CNN
F 3 "" H 6350 1150 50  0000 C CNN
	1    6350 1150
	1    0    0    -1  
$EndComp
Text GLabel 6100 1000 2    50   Input ~ 0
SPI_MOSI
Text GLabel 4150 1350 2    50   Input ~ 0
SPI_MISO
Text GLabel 5600 1000 0    50   Input ~ 0
SPI_SCK
Text GLabel 5600 900  0    50   Input ~ 0
SPI_MISO
Text GLabel 4150 2450 2    50   Input ~ 0
NRST
Text GLabel 5600 1100 0    50   Input ~ 0
NRST
$Comp
L power:GND #PWR?
U 1 1 5C36EC35
P 1750 6500
F 0 "#PWR?" H 1750 6250 50  0001 C CNN
F 1 "GND" H 1750 6350 50  0000 C CNN
F 2 "" H 1750 6500 50  0000 C CNN
F 3 "" H 1750 6500 50  0000 C CNN
	1    1750 6500
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 5C36ECAC
P 6450 2450
F 0 "SW?" H 6450 2710 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 6450 2190 50  0000 C CNN
F 2 "" H 6350 2610 50  0001 C CNN
F 3 "" H 6450 2710 50  0001 C CNN
	1    6450 2450
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U?
U 1 1 5C375D75
P 3550 2150
F 0 "U?" H 2909 2196 50  0000 R CNN
F 1 "ATmega328P-PU" H 2909 2105 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 3550 2150 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 3550 2150 50  0001 C CNN
	1    3550 2150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J?
U 1 1 5C37646D
P 5800 1000
F 0 "J?" H 5850 1317 50  0000 C CNN
F 1 "Conn_02x03_Odd_Even" H 5850 1226 50  0000 C CNN
F 2 "" H 5800 1000 50  0001 C CNN
F 3 "~" H 5800 1000 50  0001 C CNN
	1    5800 1000
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:CC56-12SRWA U?
U 1 1 5C376772
P 3550 5700
F 0 "U?" H 3550 6367 50  0000 C CNN
F 1 "CC56-12SRWA" H 3550 6276 50  0000 C CNN
F 2 "Display_7Segment:CA56-12SRWA" H 3550 5100 50  0001 C CNN
F 3 "http://www.kingbrightusa.com/images/catalog/SPEC/CC56-12SRWA.pdf" H 3120 5730 50  0001 C CNN
	1    3550 5700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U?
U 1 1 5C376C3D
P 8300 1800
F 0 "U?" H 8300 2117 50  0000 C CNN
F 1 "74HC14" H 8300 2026 50  0000 C CNN
F 2 "" H 8300 1800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 8300 1800 50  0001 C CNN
	1    8300 1800
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U?
U 2 1 5C376D50
P 8300 3300
F 0 "U?" H 8300 3617 50  0000 C CNN
F 1 "74HC14" H 8300 3526 50  0000 C CNN
F 2 "" H 8300 3300 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 8300 3300 50  0001 C CNN
	2    8300 3300
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U?
U 3 1 5C376E45
P 8300 2550
F 0 "U?" H 8300 2867 50  0000 C CNN
F 1 "74HC14" H 8300 2776 50  0000 C CNN
F 2 "" H 8300 2550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 8300 2550 50  0001 C CNN
	3    8300 2550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U?
U 4 1 5C376EB6
P 8300 4050
F 0 "U?" H 8300 4367 50  0000 C CNN
F 1 "74HC14" H 8300 4276 50  0000 C CNN
F 2 "" H 8300 4050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 8300 4050 50  0001 C CNN
	4    8300 4050
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U?
U 5 1 5C376F2B
P 8300 4800
F 0 "U?" H 8300 5117 50  0000 C CNN
F 1 "74HC14" H 8300 5026 50  0000 C CNN
F 2 "" H 8300 4800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 8300 4800 50  0001 C CNN
	5    8300 4800
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U?
U 6 1 5C376FA8
P 8300 5550
F 0 "U?" H 8300 5867 50  0000 C CNN
F 1 "74HC14" H 8300 5776 50  0000 C CNN
F 2 "" H 8300 5550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 8300 5550 50  0001 C CNN
	6    8300 5550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U?
U 7 1 5C377023
P 9800 1900
F 0 "U?" V 9433 1900 50  0000 C CNN
F 1 "74HC14" V 9524 1900 50  0000 C CNN
F 2 "" H 9800 1900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 9800 1900 50  0001 C CNN
	7    9800 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 5400 2450 5400
Wire Wire Line
	2150 5500 2450 5500
Wire Wire Line
	2150 5600 2450 5600
Wire Wire Line
	2150 5700 2450 5700
Wire Wire Line
	2150 5800 2450 5800
Wire Wire Line
	2150 5900 2450 5900
Wire Wire Line
	2150 6000 2450 6000
Wire Wire Line
	2150 6100 2450 6100
NoConn ~ 2150 6300
$Comp
L 74xx:74HC595 U?
U 1 1 5C37799C
P 1750 5800
F 0 "U?" H 1750 6578 50  0000 C CNN
F 1 "74HC595" H 1750 6487 50  0000 C CNN
F 2 "" H 1750 5800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 1750 5800 50  0001 C CNN
	1    1750 5800
	1    0    0    -1  
$EndComp
Text GLabel 1350 5400 0    50   Input ~ 0
SPI_MOSI
Text GLabel 1350 5600 0    50   Input ~ 0
SPI_SCK
Text GLabel 1350 5900 0    50   Input ~ 0
SPI_NSS
Connection ~ 1750 6500
$Comp
L power:+5V #PWR?
U 1 1 5C377D18
P 1350 5150
F 0 "#PWR?" H 1350 5000 50  0001 C CNN
F 1 "+5V" H 1365 5323 50  0000 C CNN
F 2 "" H 1350 5150 50  0001 C CNN
F 3 "" H 1350 5150 50  0001 C CNN
	1    1350 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  5700 1350 5700
Wire Wire Line
	900  5150 1350 5150
Text GLabel 4150 950  2    50   Input ~ 0
ENC_A
Text GLabel 4150 1050 2    50   Input ~ 0
ENC_B
$Comp
L power:GND #PWR?
U 1 1 5C379793
P 6150 2450
F 0 "#PWR?" H 6150 2200 50  0001 C CNN
F 1 "GND" V 6155 2322 50  0000 R CNN
F 2 "" H 6150 2450 50  0001 C CNN
F 3 "" H 6150 2450 50  0001 C CNN
	1    6150 2450
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5C37A7D6
P 7750 2700
F 0 "C?" H 7865 2746 50  0000 L CNN
F 1 "0.1u" H 7865 2655 50  0000 L CNN
F 2 "" H 7788 2550 50  0001 C CNN
F 3 "~" H 7750 2700 50  0001 C CNN
	1    7750 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C37A852
P 7750 2850
F 0 "#PWR?" H 7750 2600 50  0001 C CNN
F 1 "GND" H 7755 2677 50  0000 C CNN
F 2 "" H 7750 2850 50  0001 C CNN
F 3 "" H 7750 2850 50  0001 C CNN
	1    7750 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 2550 8000 2550
$Comp
L Device:R R?
U 1 1 5C37ACFD
P 7500 2550
F 0 "R?" V 7293 2550 50  0000 C CNN
F 1 "10k" V 7384 2550 50  0000 C CNN
F 2 "" V 7430 2550 50  0001 C CNN
F 3 "~" H 7500 2550 50  0001 C CNN
	1    7500 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 2550 7750 2550
Connection ~ 7750 2550
$Comp
L Device:R R?
U 1 1 5C37BBBD
P 7150 2400
F 0 "R?" H 7220 2446 50  0000 L CNN
F 1 "10k" H 7220 2355 50  0000 L CNN
F 2 "" V 7080 2400 50  0001 C CNN
F 3 "~" H 7150 2400 50  0001 C CNN
	1    7150 2400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C37BF08
P 7150 2250
F 0 "#PWR?" H 7150 2100 50  0001 C CNN
F 1 "+5V" H 7165 2423 50  0000 C CNN
F 2 "" H 7150 2250 50  0001 C CNN
F 3 "" H 7150 2250 50  0001 C CNN
	1    7150 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C37C8AA
P 6750 2350
F 0 "#PWR?" H 6750 2100 50  0001 C CNN
F 1 "GND" V 6755 2222 50  0000 R CNN
F 2 "" H 6750 2350 50  0001 C CNN
F 3 "" H 6750 2350 50  0001 C CNN
	1    6750 2350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6750 2550 7150 2550
Connection ~ 7150 2550
Wire Wire Line
	7150 2550 7350 2550
Text GLabel 8600 2550 2    50   Input ~ 0
ENC_BUTTON
Wire Wire Line
	6150 2550 6000 2550
Wire Wire Line
	6150 2350 6000 2350
$Comp
L Device:R R?
U 1 1 5C37E464
P 7150 3150
F 0 "R?" H 7220 3196 50  0000 L CNN
F 1 "10k" H 7220 3105 50  0000 L CNN
F 2 "" V 7080 3150 50  0001 C CNN
F 3 "~" H 7150 3150 50  0001 C CNN
	1    7150 3150
	1    0    0    -1  
$EndComp
Connection ~ 7150 3300
Wire Wire Line
	7150 3300 7300 3300
$Comp
L Device:R R?
U 1 1 5C37E4D0
P 7150 1650
F 0 "R?" H 7220 1696 50  0000 L CNN
F 1 "10k" H 7220 1605 50  0000 L CNN
F 2 "" V 7080 1650 50  0001 C CNN
F 3 "~" H 7150 1650 50  0001 C CNN
	1    7150 1650
	1    0    0    -1  
$EndComp
Connection ~ 7150 1800
Wire Wire Line
	7150 1800 7350 1800
$Comp
L Device:R R?
U 1 1 5C37E56E
P 7500 1800
F 0 "R?" V 7707 1800 50  0000 C CNN
F 1 "10k" V 7616 1800 50  0000 C CNN
F 2 "" V 7430 1800 50  0001 C CNN
F 3 "~" H 7500 1800 50  0001 C CNN
	1    7500 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7650 1800 7750 1800
$Comp
L Device:R R?
U 1 1 5C37E695
P 7450 3300
F 0 "R?" V 7243 3300 50  0000 C CNN
F 1 "10k" V 7334 3300 50  0000 C CNN
F 2 "" V 7380 3300 50  0001 C CNN
F 3 "~" H 7450 3300 50  0001 C CNN
	1    7450 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	7600 3300 7750 3300
$Comp
L Device:C C?
U 1 1 5C37E724
P 7750 1950
F 0 "C?" H 7865 1996 50  0000 L CNN
F 1 "0.1u" H 7865 1905 50  0000 L CNN
F 2 "" H 7788 1800 50  0001 C CNN
F 3 "~" H 7750 1950 50  0001 C CNN
	1    7750 1950
	1    0    0    -1  
$EndComp
Connection ~ 7750 1800
Wire Wire Line
	7750 1800 8000 1800
$Comp
L Device:C C?
U 1 1 5C37E7A8
P 7750 3450
F 0 "C?" H 7865 3496 50  0000 L CNN
F 1 "0.1u" H 7865 3405 50  0000 L CNN
F 2 "" H 7788 3300 50  0001 C CNN
F 3 "~" H 7750 3450 50  0001 C CNN
	1    7750 3450
	1    0    0    -1  
$EndComp
Connection ~ 7750 3300
Wire Wire Line
	7750 3300 8000 3300
$Comp
L power:+5V #PWR?
U 1 1 5C37E838
P 7150 1500
F 0 "#PWR?" H 7150 1350 50  0001 C CNN
F 1 "+5V" H 7165 1673 50  0000 C CNN
F 2 "" H 7150 1500 50  0001 C CNN
F 3 "" H 7150 1500 50  0001 C CNN
	1    7150 1500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C37E92C
P 7150 3000
F 0 "#PWR?" H 7150 2850 50  0001 C CNN
F 1 "+5V" H 7165 3173 50  0000 C CNN
F 2 "" H 7150 3000 50  0001 C CNN
F 3 "" H 7150 3000 50  0001 C CNN
	1    7150 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C37E98D
P 7750 2100
F 0 "#PWR?" H 7750 1850 50  0001 C CNN
F 1 "GND" H 7755 1927 50  0000 C CNN
F 2 "" H 7750 2100 50  0001 C CNN
F 3 "" H 7750 2100 50  0001 C CNN
	1    7750 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C37E9D9
P 7750 3600
F 0 "#PWR?" H 7750 3350 50  0001 C CNN
F 1 "GND" H 7755 3427 50  0000 C CNN
F 2 "" H 7750 3600 50  0001 C CNN
F 3 "" H 7750 3600 50  0001 C CNN
	1    7750 3600
	1    0    0    -1  
$EndComp
Text GLabel 8600 1800 2    50   Input ~ 0
ENC_A
Text GLabel 8600 3300 2    50   Input ~ 0
ENC_B
Text GLabel 4150 3350 2    50   Input ~ 0
ENC_BUTTON
$Comp
L power:GND #PWR?
U 1 1 5C37F171
P 9250 1950
F 0 "#PWR?" H 9250 1700 50  0001 C CNN
F 1 "GND" H 9255 1777 50  0000 C CNN
F 2 "" H 9250 1950 50  0001 C CNN
F 3 "" H 9250 1950 50  0001 C CNN
	1    9250 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+5C #PWR?
U 1 1 5C37F203
P 10350 1850
F 0 "#PWR?" H 10350 1700 50  0001 C CNN
F 1 "+5C" H 10365 2023 50  0000 C CNN
F 2 "" H 10350 1850 50  0001 C CNN
F 3 "" H 10350 1850 50  0001 C CNN
	1    10350 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 1950 9250 1900
Wire Wire Line
	9250 1900 9300 1900
Wire Wire Line
	10300 1900 10350 1900
Wire Wire Line
	10350 1900 10350 1850
Wire Wire Line
	6000 2550 6000 3300
Wire Wire Line
	6000 3300 7150 3300
Wire Wire Line
	6000 2350 6000 1800
Wire Wire Line
	6000 1800 7150 1800
$Comp
L Switch:SW_Push SW?
U 1 1 5C382339
P 6800 4800
F 0 "SW?" H 6800 5085 50  0000 C CNN
F 1 "SW_Push" H 6800 4994 50  0000 C CNN
F 2 "" H 6800 5000 50  0001 C CNN
F 3 "" H 6800 5000 50  0001 C CNN
	1    6800 4800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5C3823D2
P 6800 4050
F 0 "SW?" H 6800 4335 50  0000 C CNN
F 1 "SW_Push" H 6800 4244 50  0000 C CNN
F 2 "" H 6800 4250 50  0001 C CNN
F 3 "" H 6800 4250 50  0001 C CNN
	1    6800 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4050 7150 4050
Wire Wire Line
	7000 4800 7150 4800
$Comp
L Device:C C?
U 1 1 5C3851A0
P 7750 4200
F 0 "C?" H 7865 4246 50  0000 L CNN
F 1 "0.1u" H 7865 4155 50  0000 L CNN
F 2 "" H 7788 4050 50  0001 C CNN
F 3 "~" H 7750 4200 50  0001 C CNN
	1    7750 4200
	1    0    0    -1  
$EndComp
Connection ~ 7750 4050
Wire Wire Line
	7750 4050 8000 4050
$Comp
L Device:C C?
U 1 1 5C385226
P 7750 4950
F 0 "C?" H 7865 4996 50  0000 L CNN
F 1 "0.1u" H 7865 4905 50  0000 L CNN
F 2 "" H 7788 4800 50  0001 C CNN
F 3 "~" H 7750 4950 50  0001 C CNN
	1    7750 4950
	1    0    0    -1  
$EndComp
Connection ~ 7750 4800
Wire Wire Line
	7750 4800 8000 4800
$Comp
L Device:R R?
U 1 1 5C38547F
P 7450 4050
F 0 "R?" V 7657 4050 50  0000 C CNN
F 1 "10k" V 7566 4050 50  0000 C CNN
F 2 "" V 7380 4050 50  0001 C CNN
F 3 "~" H 7450 4050 50  0001 C CNN
	1    7450 4050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7600 4050 7750 4050
$Comp
L Device:R R?
U 1 1 5C38554C
P 7450 4800
F 0 "R?" V 7243 4800 50  0000 C CNN
F 1 "10k" V 7334 4800 50  0000 C CNN
F 2 "" V 7380 4800 50  0001 C CNN
F 3 "~" H 7450 4800 50  0001 C CNN
	1    7450 4800
	0    1    1    0   
$EndComp
Wire Wire Line
	7600 4800 7750 4800
Text GLabel 8600 4050 2    50   Input ~ 0
BUTTON0
Text GLabel 8600 4800 2    50   Input ~ 0
BUTTON1
$Comp
L Device:R R?
U 1 1 5C3858E9
P 7150 3900
F 0 "R?" H 7220 3946 50  0000 L CNN
F 1 "10k" H 7220 3855 50  0000 L CNN
F 2 "" V 7080 3900 50  0001 C CNN
F 3 "~" H 7150 3900 50  0001 C CNN
	1    7150 3900
	1    0    0    -1  
$EndComp
Connection ~ 7150 4050
Wire Wire Line
	7150 4050 7300 4050
$Comp
L Device:R R?
U 1 1 5C3859D5
P 7150 4650
F 0 "R?" H 7220 4696 50  0000 L CNN
F 1 "10k" H 7220 4605 50  0000 L CNN
F 2 "" V 7080 4650 50  0001 C CNN
F 3 "~" H 7150 4650 50  0001 C CNN
	1    7150 4650
	1    0    0    -1  
$EndComp
Connection ~ 7150 4800
Wire Wire Line
	7150 4800 7300 4800
$Comp
L power:+5V #PWR?
U 1 1 5C385A67
P 7150 3750
F 0 "#PWR?" H 7150 3600 50  0001 C CNN
F 1 "+5V" H 7165 3923 50  0000 C CNN
F 2 "" H 7150 3750 50  0001 C CNN
F 3 "" H 7150 3750 50  0001 C CNN
	1    7150 3750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C385AC3
P 7150 4500
F 0 "#PWR?" H 7150 4350 50  0001 C CNN
F 1 "+5V" H 7165 4673 50  0000 C CNN
F 2 "" H 7150 4500 50  0001 C CNN
F 3 "" H 7150 4500 50  0001 C CNN
	1    7150 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C385C39
P 7750 4350
F 0 "#PWR?" H 7750 4100 50  0001 C CNN
F 1 "GND" H 7755 4177 50  0000 C CNN
F 2 "" H 7750 4350 50  0001 C CNN
F 3 "" H 7750 4350 50  0001 C CNN
	1    7750 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C385C95
P 7750 5100
F 0 "#PWR?" H 7750 4850 50  0001 C CNN
F 1 "GND" H 7755 4927 50  0000 C CNN
F 2 "" H 7750 5100 50  0001 C CNN
F 3 "" H 7750 5100 50  0001 C CNN
	1    7750 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C385EA4
P 6500 4350
F 0 "#PWR?" H 6500 4100 50  0001 C CNN
F 1 "GND" H 6505 4177 50  0000 C CNN
F 2 "" H 6500 4350 50  0001 C CNN
F 3 "" H 6500 4350 50  0001 C CNN
	1    6500 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C385F00
P 6500 5100
F 0 "#PWR?" H 6500 4850 50  0001 C CNN
F 1 "GND" H 6505 4927 50  0000 C CNN
F 2 "" H 6500 5100 50  0001 C CNN
F 3 "" H 6500 5100 50  0001 C CNN
	1    6500 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 4800 6600 4800
Wire Wire Line
	6500 4800 6500 5100
Wire Wire Line
	6500 4050 6600 4050
Wire Wire Line
	6500 4050 6500 4350
Text GLabel 4150 2850 2    50   Input ~ 0
BUTTON0
Text GLabel 4150 2950 2    50   Input ~ 0
BUTTON1
$Comp
L Switch:SW_SPDT SW?
U 1 1 5C38BFDD
P 8400 1000
F 0 "SW?" H 8400 1285 50  0000 C CNN
F 1 "SW_SPDT" H 8400 1194 50  0000 C CNN
F 2 "" H 8400 1000 50  0001 C CNN
F 3 "" H 8400 1000 50  0001 C CNN
	1    8400 1000
	1    0    0    -1  
$EndComp
Text GLabel 8600 1100 2    50   Input ~ 0
SWITCH0
$Comp
L power:GND #PWR?
U 1 1 5C38DFD3
P 8600 900
F 0 "#PWR?" H 8600 650 50  0001 C CNN
F 1 "GND" V 8605 772 50  0000 R CNN
F 2 "" H 8600 900 50  0001 C CNN
F 3 "" H 8600 900 50  0001 C CNN
	1    8600 900 
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C38E158
P 8100 950
F 0 "#PWR?" H 8100 800 50  0001 C CNN
F 1 "+5V" H 8115 1123 50  0000 C CNN
F 2 "" H 8100 950 50  0001 C CNN
F 3 "" H 8100 950 50  0001 C CNN
	1    8100 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 950  8100 1000
Wire Wire Line
	8100 1000 8200 1000
Text GLabel 4150 2250 2    50   Input ~ 0
SWITCH0
$Comp
L Device:CP1 C?
U 1 1 5C38F202
P 5000 2350
F 0 "C?" V 5252 2350 50  0000 C CNN
F 1 "47u" V 5161 2350 50  0000 C CNN
F 2 "" H 5000 2350 50  0001 C CNN
F 3 "~" H 5000 2350 50  0001 C CNN
	1    5000 2350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C38F2B1
P 4700 2350
F 0 "R?" V 4493 2350 50  0000 C CNN
F 1 "1k" V 4584 2350 50  0000 C CNN
F 2 "" V 4630 2350 50  0001 C CNN
F 3 "~" H 4700 2350 50  0001 C CNN
	1    4700 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	4150 2350 4550 2350
Wire Wire Line
	5150 2350 5400 2350
Wire Wire Line
	5400 2350 5400 2400
$Comp
L power:GND #PWR?
U 1 1 5C38F4CE
P 5400 2400
F 0 "#PWR?" H 5400 2150 50  0001 C CNN
F 1 "GND" H 5405 2227 50  0000 C CNN
F 2 "" H 5400 2400 50  0001 C CNN
F 3 "" H 5400 2400 50  0001 C CNN
	1    5400 2400
	1    0    0    -1  
$EndComp
Text GLabel 4150 2650 2    50   Input ~ 0
LED0
Text GLabel 4150 2750 2    50   Input ~ 0
LED1
Text GLabel 4150 3050 2    50   Input ~ 0
LED2
$Comp
L Device:R R?
U 1 1 5C39E631
P 9600 2900
F 0 "R?" V 9393 2900 50  0000 C CNN
F 1 "510" V 9484 2900 50  0000 C CNN
F 2 "" V 9530 2900 50  0001 C CNN
F 3 "~" H 9600 2900 50  0001 C CNN
	1    9600 2900
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C39E74D
P 9600 3300
F 0 "R?" V 9393 3300 50  0000 C CNN
F 1 "510" V 9484 3300 50  0000 C CNN
F 2 "" V 9530 3300 50  0001 C CNN
F 3 "~" H 9600 3300 50  0001 C CNN
	1    9600 3300
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C39E7B9
P 9600 3700
F 0 "R?" V 9393 3700 50  0000 C CNN
F 1 "510" V 9484 3700 50  0000 C CNN
F 2 "" V 9530 3700 50  0001 C CNN
F 3 "~" H 9600 3700 50  0001 C CNN
	1    9600 3700
	0    1    1    0   
$EndComp
$Comp
L Device:LED D?
U 1 1 5C39E890
P 9900 2900
F 0 "D?" H 9892 2645 50  0000 C CNN
F 1 "LED" H 9892 2736 50  0000 C CNN
F 2 "" H 9900 2900 50  0001 C CNN
F 3 "~" H 9900 2900 50  0001 C CNN
	1    9900 2900
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D?
U 1 1 5C39E95C
P 9900 3300
F 0 "D?" H 9892 3045 50  0000 C CNN
F 1 "LED" H 9892 3136 50  0000 C CNN
F 2 "" H 9900 3300 50  0001 C CNN
F 3 "~" H 9900 3300 50  0001 C CNN
	1    9900 3300
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D?
U 1 1 5C39E9C2
P 9900 3700
F 0 "D?" H 9892 3445 50  0000 C CNN
F 1 "LED" H 9892 3536 50  0000 C CNN
F 2 "" H 9900 3700 50  0001 C CNN
F 3 "~" H 9900 3700 50  0001 C CNN
	1    9900 3700
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C39EA68
P 10150 3750
F 0 "#PWR?" H 10150 3500 50  0001 C CNN
F 1 "GND" H 10155 3577 50  0000 C CNN
F 2 "" H 10150 3750 50  0001 C CNN
F 3 "" H 10150 3750 50  0001 C CNN
	1    10150 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 2900 10150 2900
Wire Wire Line
	10150 2900 10150 3300
Wire Wire Line
	10050 3700 10150 3700
Connection ~ 10150 3700
Wire Wire Line
	10150 3700 10150 3750
Wire Wire Line
	10050 3300 10150 3300
Connection ~ 10150 3300
Wire Wire Line
	10150 3300 10150 3700
Text GLabel 9450 2900 0    50   Input ~ 0
LED0
Text GLabel 9450 3300 0    50   Input ~ 0
LED1
Text GLabel 9450 3700 0    50   Input ~ 0
LED2
Text GLabel 4150 1850 2    50   Input ~ 0
DIG0
Text GLabel 4150 1950 2    50   Input ~ 0
DIG1
Text GLabel 4150 2050 2    50   Input ~ 0
DIG2
Text GLabel 4150 2150 2    50   Input ~ 0
DIG3
$Comp
L Device:R R?
U 1 1 5C3A4A47
P 5050 5500
F 0 "R?" V 4843 5500 50  0000 C CNN
F 1 "330" V 4934 5500 50  0000 C CNN
F 2 "" V 4980 5500 50  0001 C CNN
F 3 "~" H 5050 5500 50  0001 C CNN
	1    5050 5500
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C3A4BCB
P 5050 5800
F 0 "R?" V 4843 5800 50  0000 C CNN
F 1 "330" V 4934 5800 50  0000 C CNN
F 2 "" V 4980 5800 50  0001 C CNN
F 3 "~" H 5050 5800 50  0001 C CNN
	1    5050 5800
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C3A4C2B
P 5050 6100
F 0 "R?" V 4843 6100 50  0000 C CNN
F 1 "330" V 4934 6100 50  0000 C CNN
F 2 "" V 4980 6100 50  0001 C CNN
F 3 "~" H 5050 6100 50  0001 C CNN
	1    5050 6100
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C3A4C8D
P 5050 6400
F 0 "R?" V 4843 6400 50  0000 C CNN
F 1 "330" V 4934 6400 50  0000 C CNN
F 2 "" V 4980 6400 50  0001 C CNN
F 3 "~" H 5050 6400 50  0001 C CNN
	1    5050 6400
	0    1    1    0   
$EndComp
Text GLabel 5200 5500 2    50   Input ~ 0
DIGSEL0
Text GLabel 5200 5800 2    50   Input ~ 0
DIGSEL1
Text GLabel 5200 6100 2    50   Input ~ 0
DIGSEL2
Text GLabel 5200 6400 2    50   Input ~ 0
DIGSEL3
Wire Wire Line
	4650 5800 4750 5800
Wire Wire Line
	4750 5800 4750 5500
Wire Wire Line
	4750 5500 4900 5500
Wire Wire Line
	4650 5900 4800 5900
Wire Wire Line
	4800 5900 4800 5800
Wire Wire Line
	4800 5800 4900 5800
Wire Wire Line
	4650 6000 4800 6000
Wire Wire Line
	4800 6000 4800 6100
Wire Wire Line
	4800 6100 4900 6100
Wire Wire Line
	4650 6100 4750 6100
Wire Wire Line
	4750 6100 4750 6400
Wire Wire Line
	4750 6400 4900 6400
$Comp
L power:+5V #PWR?
U 1 1 5C3BC022
P 6350 850
F 0 "#PWR?" H 6350 700 50  0001 C CNN
F 1 "+5V" H 6365 1023 50  0000 C CNN
F 2 "" H 6350 850 50  0001 C CNN
F 3 "" H 6350 850 50  0001 C CNN
	1    6350 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 900  6350 900 
Wire Wire Line
	6350 900  6350 850 
Wire Wire Line
	6100 1100 6350 1100
Wire Wire Line
	6350 1100 6350 1150
$Comp
L Connector:Conn_01x02_Male J?
U 1 1 5C3C1027
P 5900 1450
F 0 "J?" H 6006 1628 50  0000 C CNN
F 1 "Conn_01x02_Male" H 6006 1537 50  0000 C CNN
F 2 "" H 5900 1450 50  0001 C CNN
F 3 "~" H 5900 1450 50  0001 C CNN
	1    5900 1450
	1    0    0    -1  
$EndComp
Text GLabel 6100 1450 2    50   Input ~ 0
SPI_MOSI
Text GLabel 4150 3250 2    50   Input ~ 0
FREE_PIN
Text GLabel 6100 1550 2    50   Input ~ 0
FREE_PIN
$Comp
L power:GND #PWR?
U 1 1 5C3C5B22
P 3550 3650
F 0 "#PWR?" H 3550 3400 50  0001 C CNN
F 1 "GND" H 3555 3477 50  0000 C CNN
F 2 "" H 3550 3650 50  0001 C CNN
F 3 "" H 3550 3650 50  0001 C CNN
	1    3550 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 5200 1750 5150
Wire Wire Line
	1750 5150 1350 5150
Connection ~ 1350 5150
Wire Wire Line
	900  5150 900  5700
Wire Wire Line
	1350 6000 1300 6000
Wire Wire Line
	1300 6000 1300 6500
Wire Wire Line
	1300 6500 1750 6500
NoConn ~ 8600 5550
NoConn ~ 8000 5550
Wire Wire Line
	2950 950  2900 950 
Wire Wire Line
	2900 950  2900 600 
Wire Wire Line
	2900 600  3550 600 
Wire Wire Line
	3650 600  3650 650 
Wire Wire Line
	3550 600  3550 650 
Connection ~ 3550 600 
Wire Wire Line
	3550 600  3650 600 
$EndSCHEMATC
