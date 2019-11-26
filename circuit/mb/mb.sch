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
Text GLabel 2800 1600 2    50   Output ~ 0
SPI_MOSI
Text GLabel 2500 1500 2    50   Output ~ 0
SPI_NSS
Text GLabel 2500 1800 2    50   Output ~ 0
SPI_SCK
Text GLabel 2500 3600 2    50   Output ~ 0
SOUND_OUT
$Comp
L power:GND #PWR012
U 1 1 5C36DEA9
P 5350 1350
F 0 "#PWR012" H 5350 1100 50  0001 C CNN
F 1 "GND" H 5350 1200 50  0000 C CNN
F 2 "" H 5350 1350 50  0000 C CNN
F 3 "" H 5350 1350 50  0000 C CNN
	1    5350 1350
	1    0    0    -1  
$EndComp
Text GLabel 5000 1250 2    50   Input ~ 0
SPI_MOSI
Text GLabel 2500 1700 2    50   Output ~ 0
SPI_MISO
Text GLabel 4050 1250 0    50   Input ~ 0
SPI_SCK
Text GLabel 4050 1150 0    50   Input ~ 0
SPI_MISO
Text GLabel 4550 2800 1    50   Input ~ 0
NRST
Text GLabel 4050 1350 0    50   Input ~ 0
NRST
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J4
U 1 1 5C37646D
P 4700 1250
F 0 "J4" H 4750 1567 50  0000 C CNN
F 1 "Conn_02x03_Odd_Even" H 4750 1476 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 4700 1250 50  0001 C CNN
F 3 "~" H 4700 1250 50  0001 C CNN
	1    4700 1250
	1    0    0    -1  
$EndComp
Text GLabel 2500 1400 2    50   Input ~ 0
ENC_A
Text GLabel 2500 1300 2    50   Input ~ 0
ENC_B
Text GLabel 3200 3700 2    50   Input ~ 0
ENC_BUTTON
Text GLabel 2500 3200 2    50   Input ~ 0
BUTTON1
Text GLabel 3150 3100 2    50   Input ~ 0
BUTTON2
Text GLabel 3050 2600 2    50   Input ~ 0
SWITCH0
Text GLabel 2500 2300 2    50   Output ~ 0
DIG0
Text GLabel 2500 2400 2    50   Output ~ 0
DIG1
Text GLabel 2500 2500 2    50   Output ~ 0
DIG2
Text GLabel 2500 2200 2    50   Output ~ 0
DIG3
$Comp
L power:+5V #PWR011
U 1 1 5C3BC022
P 5250 1100
F 0 "#PWR011" H 5250 950 50  0001 C CNN
F 1 "+5V" H 5265 1273 50  0000 C CNN
F 2 "" H 5250 1100 50  0001 C CNN
F 3 "" H 5250 1100 50  0001 C CNN
	1    5250 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 1150 5250 1150
Wire Wire Line
	5250 1150 5250 1100
$Comp
L power:GND #PWR01
U 1 1 5C3C5B22
P 1900 4450
F 0 "#PWR01" H 1900 4200 50  0001 C CNN
F 1 "GND" H 1905 4277 50  0000 C CNN
F 2 "" H 1900 4450 50  0001 C CNN
F 3 "" H 1900 4450 50  0001 C CNN
	1    1900 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 1300 1250 1300
Wire Wire Line
	2000 950  2000 1000
$Comp
L Transistor_BJT:BC337 Q1
U 1 1 5C3B53C5
P 1900 5250
F 0 "Q1" H 2091 5296 50  0000 L CNN
F 1 "BC337" H 2091 5205 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 2100 5175 50  0001 L CIN
F 3 "http://www.nxp.com/documents/data_sheet/BC817_BC817W_BC337.pdf" H 1900 5250 50  0001 L CNN
	1    1900 5250
	1    0    0    -1  
$EndComp
Text GLabel 1050 5250 0    50   Input ~ 0
SOUND_OUT
$Comp
L Device:Speaker LS1
U 1 1 5C3B63DB
P 3950 4850
F 0 "LS1" H 4120 4846 50  0000 L CNN
F 1 "Speaker" H 4120 4755 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3950 4650 50  0001 C CNN
F 3 "~" H 3940 4800 50  0001 C CNN
	1    3950 4850
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPDT SW1
U 1 1 5C3D95EC
P 3500 5250
F 0 "SW1" H 3500 4925 50  0000 C CNN
F 1 "SW_SPDT" H 3500 5016 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3500 5250 50  0001 C CNN
F 3 "" H 3500 5250 50  0001 C CNN
	1    3500 5250
	-1   0    0    1   
$EndComp
$Comp
L Connector:Barrel_Jack_Switch J3
U 1 1 5C3F1F8D
P 4100 6550
F 0 "J3" H 4155 6867 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 4155 6776 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4150 6510 50  0001 C CNN
F 3 "~" H 4150 6510 50  0001 C CNN
	1    4100 6550
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BT1
U 1 1 5C3F2211
P 5000 6550
F 0 "BT1" V 5245 6550 50  0000 C CNN
F 1 "9V" V 5154 6550 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" V 5000 6610 50  0001 C CNN
F 3 "~" V 5000 6610 50  0001 C CNN
	1    5000 6550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5250 6450 5250 6550
Wire Wire Line
	5250 6550 5200 6550
$Comp
L power:GND #PWR09
U 1 1 5C3F89BE
P 4700 6450
F 0 "#PWR09" H 4700 6200 50  0001 C CNN
F 1 "GND" H 4705 6277 50  0000 C CNN
F 2 "" H 4700 6450 50  0001 C CNN
F 3 "" H 4700 6450 50  0001 C CNN
	1    4700 6450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPDT SW2
U 1 1 5C3F8B10
P 4700 7100
F 0 "SW2" H 4700 6775 50  0000 C CNN
F 1 "SW_SPDT" H 4700 6866 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4700 7100 50  0001 C CNN
F 3 "" H 4700 7100 50  0001 C CNN
	1    4700 7100
	-1   0    0    1   
$EndComp
Wire Wire Line
	4400 6650 4450 6650
NoConn ~ 4500 7200
$Comp
L power:+9V #PWR010
U 1 1 5C4039AB
P 5000 7100
F 0 "#PWR010" H 5000 6950 50  0001 C CNN
F 1 "+9V" H 5015 7273 50  0000 C CNN
F 2 "" H 5000 7100 50  0001 C CNN
F 3 "" H 5000 7100 50  0001 C CNN
	1    5000 7100
	1    0    0    -1  
$EndComp
Connection ~ 5000 7100
$Comp
L Device:CP1 C4
U 1 1 5C403A94
P 5250 6950
F 0 "C4" H 5135 6904 50  0000 R CNN
F 1 "100u" H 5135 6995 50  0000 R CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P2.00mm" H 5250 6950 50  0001 C CNN
F 3 "~" H 5250 6950 50  0001 C CNN
	1    5250 6950
	-1   0    0    1   
$EndComp
Wire Wire Line
	5250 6550 5250 6800
Connection ~ 5250 6550
Wire Wire Line
	5000 7100 5250 7100
$Comp
L Regulator_Linear:L7805 U2
U 1 1 5C40B362
P 5700 7100
F 0 "U2" H 5700 7342 50  0000 C CNN
F 1 "L7805" H 5700 7251 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 5725 6950 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 5700 7050 50  0001 C CNN
	1    5700 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 7100 5400 7100
Connection ~ 5250 7100
$Comp
L power:GND #PWR013
U 1 1 5C40F01B
P 5700 7400
F 0 "#PWR013" H 5700 7150 50  0001 C CNN
F 1 "GND" H 5705 7227 50  0000 C CNN
F 2 "" H 5700 7400 50  0001 C CNN
F 3 "" H 5700 7400 50  0001 C CNN
	1    5700 7400
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C5
U 1 1 5C41AE20
P 6200 6950
F 0 "C5" H 6085 6904 50  0000 R CNN
F 1 "2200u" H 6085 6995 50  0000 R CNN
F 2 "Capacitor_THT:CP_Axial_L29.0mm_D13.0mm_P35.00mm_Horizontal" H 6200 6950 50  0001 C CNN
F 3 "~" H 6200 6950 50  0001 C CNN
	1    6200 6950
	-1   0    0    1   
$EndComp
Connection ~ 5250 6450
$Comp
L power:+5V #PWR014
U 1 1 5C422E83
P 6300 7100
F 0 "#PWR014" H 6300 6950 50  0001 C CNN
F 1 "+5V" V 6315 7228 50  0000 L CNN
F 2 "" H 6300 7100 50  0001 C CNN
F 3 "" H 6300 7100 50  0001 C CNN
	1    6300 7100
	0    1    1    0   
$EndComp
Text GLabel 2800 3500 2    50   Output ~ 0
LED2
Text GLabel 2800 3400 2    50   Output ~ 0
LED1
Text GLabel 2500 3000 2    50   Output ~ 0
LED0
$Comp
L power:+5V #PWR02
U 1 1 5C4672B2
P 2000 950
F 0 "#PWR02" H 2000 800 50  0001 C CNN
F 1 "+5V" H 2015 1123 50  0000 C CNN
F 2 "" H 2000 950 50  0001 C CNN
F 3 "" H 2000 950 50  0001 C CNN
	1    2000 950 
	0    1    1    0   
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 5C4E518C
P 3200 1950
F 0 "Y1" V 3154 2081 50  0000 L CNN
F 1 "16M" V 3245 2081 50  0000 L CNN
F 2 "Crystal:Resonator-2Pin_W10.0mm_H5.0mm" H 3200 1950 50  0001 C CNN
F 3 "~" H 3200 1950 50  0001 C CNN
	1    3200 1950
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 5C4E53AD
P 3650 1700
F 0 "C1" V 3398 1700 50  0000 C CNN
F 1 "22p" V 3489 1700 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 3688 1550 50  0001 C CNN
F 3 "~" H 3650 1700 50  0001 C CNN
	1    3650 1700
	0    1    1    0   
$EndComp
$Comp
L Device:C C2
U 1 1 5C4E5529
P 3650 2200
F 0 "C2" V 3398 2200 50  0000 C CNN
F 1 "22p" V 3489 2200 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 3688 2050 50  0001 C CNN
F 3 "~" H 3650 2200 50  0001 C CNN
	1    3650 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	2950 1900 2950 1800
Wire Wire Line
	2950 1800 3200 1800
Wire Wire Line
	3200 1800 3400 1800
Connection ~ 3200 1800
Wire Wire Line
	2950 2000 2950 2100
Wire Wire Line
	2950 2100 3200 2100
Wire Wire Line
	3200 2100 3400 2100
Connection ~ 3200 2100
$Comp
L power:GND #PWR08
U 1 1 5C50007C
P 4250 1900
F 0 "#PWR08" H 4250 1650 50  0001 C CNN
F 1 "GND" H 4255 1727 50  0000 C CNN
F 2 "" H 4250 1900 50  0001 C CNN
F 3 "" H 4250 1900 50  0001 C CNN
	1    4250 1900
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5C51373D
P 5000 7100
F 0 "#FLG02" H 5000 7175 50  0001 C CNN
F 1 "PWR_FLAG" H 5000 7273 50  0000 C CNN
F 2 "" H 5000 7100 50  0001 C CNN
F 3 "~" H 5000 7100 50  0001 C CNN
	1    5000 7100
	-1   0    0    1   
$EndComp
Wire Wire Line
	4800 6550 4800 6700
Wire Wire Line
	4800 6700 4500 6700
Wire Wire Line
	4500 6700 4500 6550
Wire Wire Line
	4500 6550 4400 6550
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5C51865A
P 4700 6450
F 0 "#FLG01" H 4700 6525 50  0001 C CNN
F 1 "PWR_FLAG" H 4700 6624 50  0000 C CNN
F 2 "" H 4700 6450 50  0001 C CNN
F 3 "~" H 4700 6450 50  0001 C CNN
	1    4700 6450
	1    0    0    -1  
$EndComp
Connection ~ 4700 6450
Wire Wire Line
	4700 6450 5250 6450
Wire Wire Line
	4400 6450 4700 6450
Wire Wire Line
	2500 1900 2950 1900
Wire Wire Line
	2500 2000 2950 2000
Text GLabel 2500 3300 2    50   Input ~ 0
BUTTON0
Wire Wire Line
	4450 7000 4500 7000
Wire Wire Line
	4450 6650 4450 7000
Wire Wire Line
	4900 7100 5000 7100
Connection ~ 6200 7100
Wire Wire Line
	6200 7100 6300 7100
Wire Wire Line
	5250 6450 6200 6450
Wire Wire Line
	6000 7100 6200 7100
Wire Wire Line
	3500 2200 3400 2200
Wire Wire Line
	3400 2200 3400 2100
Wire Wire Line
	3400 1800 3400 1700
Wire Wire Line
	3400 1700 3500 1700
$Comp
L Device:R R6
U 1 1 5DC16C34
P 4650 3000
F 0 "R6" H 4720 3046 50  0000 L CNN
F 1 "10k" H 4720 2955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4580 3000 50  0001 C CNN
F 3 "~" H 4650 3000 50  0001 C CNN
	1    4650 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5DC24A93
P 7750 1950
F 0 "#PWR018" H 7750 1700 50  0001 C CNN
F 1 "GND" V 7750 1750 50  0000 C CNN
F 2 "" H 7750 1950 50  0001 C CNN
F 3 "" H 7750 1950 50  0001 C CNN
	1    7750 1950
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR019
U 1 1 5DC2496C
P 7750 2250
F 0 "#PWR019" H 7750 2100 50  0001 C CNN
F 1 "+5V" V 7750 2450 50  0000 C CNN
F 2 "" H 7750 2250 50  0001 C CNN
F 3 "" H 7750 2250 50  0001 C CNN
	1    7750 2250
	0    1    1    0   
$EndComp
Text GLabel 7150 2150 2    50   Input ~ 0
SPI_SCK
Text GLabel 7750 2050 2    50   Input ~ 0
SPI_NSS
Text GLabel 7150 1850 2    50   Input ~ 0
SPI_MOSI
$Comp
L Connector:Conn_01x05_Male J9
U 1 1 5DC23572
P 6950 2050
F 0 "J9" H 7056 2428 50  0000 C CNN
F 1 "Conn_01x05_Male" H 7056 2337 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 6950 2050 50  0001 C CNN
F 3 "~" H 6950 2050 50  0001 C CNN
	1    6950 2050
	1    0    0    -1  
$EndComp
Text GLabel 6200 2150 2    50   Input ~ 0
DIG3
Text GLabel 6200 2050 2    50   Input ~ 0
DIG0
Text GLabel 6200 1950 2    50   Input ~ 0
DIG1
Text GLabel 6200 1850 2    50   Input ~ 0
DIG2
$Comp
L Connector:Conn_01x04_Male J6
U 1 1 5DC22A24
P 6000 1950
F 0 "J6" H 6106 2228 50  0000 C CNN
F 1 "Conn_01x04_Male" H 6106 2137 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6000 1950 50  0001 C CNN
F 3 "~" H 6000 1950 50  0001 C CNN
	1    6000 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5DC5692C
P 1200 5250
F 0 "R1" V 993 5250 50  0000 C CNN
F 1 "2.2k" V 1084 5250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1130 5250 50  0001 C CNN
F 3 "~" H 1200 5250 50  0001 C CNN
	1    1200 5250
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5DC56A41
P 1500 5000
F 0 "R2" H 1570 5046 50  0000 L CNN
F 1 "100k" H 1570 4955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1430 5000 50  0001 C CNN
F 3 "~" H 1500 5000 50  0001 C CNN
	1    1500 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5DC56B81
P 1500 5450
F 0 "R3" H 1570 5496 50  0000 L CNN
F 1 "100k" H 1570 5405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1430 5450 50  0001 C CNN
F 3 "~" H 1500 5450 50  0001 C CNN
	1    1500 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 5250 1500 5250
Wire Wire Line
	1500 5150 1500 5250
Connection ~ 1500 5250
Wire Wire Line
	1500 5250 1700 5250
Wire Wire Line
	1500 5250 1500 5300
Wire Wire Line
	1500 4850 2000 4850
Wire Wire Line
	2000 4850 2000 5050
$Comp
L power:GND #PWR03
U 1 1 5DC78670
P 2000 5950
F 0 "#PWR03" H 2000 5700 50  0001 C CNN
F 1 "GND" H 2005 5777 50  0000 C CNN
F 2 "" H 2000 5950 50  0001 C CNN
F 3 "" H 2000 5950 50  0001 C CNN
	1    2000 5950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5DC78BED
P 2400 5450
F 0 "R4" H 2470 5496 50  0000 L CNN
F 1 "10" H 2470 5405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2330 5450 50  0001 C CNN
F 3 "~" H 2400 5450 50  0001 C CNN
	1    2400 5450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 5DC78D1C
P 2400 5900
F 0 "#PWR04" H 2400 5750 50  0001 C CNN
F 1 "+5V" H 2415 6073 50  0000 C CNN
F 2 "" H 2400 5900 50  0001 C CNN
F 3 "" H 2400 5900 50  0001 C CNN
	1    2400 5900
	-1   0    0    1   
$EndComp
$Comp
L Diode:1N4001 D1
U 1 1 5DCF165C
P 2700 5000
F 0 "D1" V 2654 5079 50  0000 L CNN
F 1 "1N4001" V 2745 5079 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2700 4825 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 2700 5000 50  0001 C CNN
	1    2700 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	2550 5050 2550 5150
Wire Wire Line
	2550 5150 2700 5150
Wire Wire Line
	2700 5150 3000 5150
Wire Wire Line
	3000 5150 3000 5400
Connection ~ 2700 5150
Wire Wire Line
	2700 4850 2900 4850
Wire Wire Line
	2900 4850 2900 5400
Connection ~ 2900 4850
Wire Wire Line
	2900 4850 3750 4850
Wire Wire Line
	3700 4950 3750 4950
$Comp
L power:GND #PWR06
U 1 1 5DD480F0
P 3300 5400
F 0 "#PWR06" H 3300 5150 50  0001 C CNN
F 1 "GND" H 3305 5227 50  0000 C CNN
F 2 "" H 3300 5400 50  0001 C CNN
F 3 "" H 3300 5400 50  0001 C CNN
	1    3300 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 5250 3700 4950
Wire Wire Line
	3300 5150 3000 5150
Connection ~ 3000 5150
Wire Wire Line
	3300 5350 3300 5400
Wire Wire Line
	2000 4850 2400 4850
Connection ~ 2000 4850
Connection ~ 2700 4850
Connection ~ 2400 4850
Wire Wire Line
	2400 4850 2700 4850
$Comp
L Device:R R5
U 1 1 5DC0D191
P 3350 2700
F 0 "R5" V 3143 2700 50  0000 C CNN
F 1 "1k" V 3234 2700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3280 2700 50  0001 C CNN
F 3 "~" H 3350 2700 50  0001 C CNN
	1    3350 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	2500 2700 2900 2700
$Comp
L Device:CP C3
U 1 1 5DC17396
P 3650 2700
F 0 "C3" V 3905 2700 50  0000 C CNN
F 1 "47u" V 3814 2700 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P2.00mm" H 3688 2550 50  0001 C CNN
F 3 "~" H 3650 2700 50  0001 C CNN
	1    3650 2700
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5DC17532
P 3800 2700
F 0 "#PWR07" H 3800 2450 50  0001 C CNN
F 1 "GND" H 3805 2527 50  0000 C CNN
F 2 "" H 3800 2700 50  0001 C CNN
F 3 "" H 3800 2700 50  0001 C CNN
	1    3800 2700
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J5
U 1 1 5DC8F5E1
P 5950 1250
F 0 "J5" H 6056 1528 50  0000 C CNN
F 1 "Conn_01x04_Male" H 6056 1437 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5950 1250 50  0001 C CNN
F 3 "~" H 5950 1250 50  0001 C CNN
	1    5950 1250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Male J8
U 1 1 5DC8F68F
P 6950 1350
F 0 "J8" H 7056 1728 50  0000 C CNN
F 1 "Conn_01x05_Male" H 7056 1637 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 6950 1350 50  0001 C CNN
F 3 "~" H 6950 1350 50  0001 C CNN
	1    6950 1350
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J1
U 1 1 5DC8F73E
P 2200 5050
F 0 "J1" H 2350 5450 50  0000 C CNN
F 1 "Conn_01x03_Male" H 2350 5350 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2200 5050 50  0001 C CNN
F 3 "~" H 2200 5050 50  0001 C CNN
	1    2200 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 4850 2400 4950
Wire Wire Line
	2400 5050 2550 5050
Wire Wire Line
	2400 5150 2400 5300
Text GLabel 6150 1350 2    50   Output ~ 0
BUTTON0
Text GLabel 6150 1250 2    50   Output ~ 0
BUTTON1
Text GLabel 6150 1150 2    50   Output ~ 0
BUTTON2
Text GLabel 6150 1450 2    50   Output ~ 0
ENC_BUTTON
Text GLabel 7150 1150 2    50   Output ~ 0
SWITCH0
Text GLabel 7150 1250 2    50   Output ~ 0
ENC_A
Text GLabel 7150 1350 2    50   Output ~ 0
ENC_B
$Comp
L power:GND #PWR016
U 1 1 5DC988AB
P 7550 1450
F 0 "#PWR016" H 7550 1200 50  0001 C CNN
F 1 "GND" V 7555 1322 50  0000 R CNN
F 2 "" H 7550 1450 50  0001 C CNN
F 3 "" H 7550 1450 50  0001 C CNN
	1    7550 1450
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR017
U 1 1 5DC9898C
P 8150 1550
F 0 "#PWR017" H 8150 1400 50  0001 C CNN
F 1 "+5V" V 8165 1678 50  0000 L CNN
F 2 "" H 8150 1550 50  0001 C CNN
F 3 "" H 8150 1550 50  0001 C CNN
	1    8150 1550
	0    1    1    0   
$EndComp
Wire Wire Line
	7150 1450 7550 1450
$Comp
L Connector:Conn_01x04_Male J7
U 1 1 5DCA8105
P 6000 2600
F 0 "J7" H 6106 2878 50  0000 C CNN
F 1 "Conn_01x04_Male" H 6106 2787 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6000 2600 50  0001 C CNN
F 3 "~" H 6000 2600 50  0001 C CNN
	1    6000 2600
	1    0    0    -1  
$EndComp
Text GLabel 6850 2500 2    50   Input ~ 0
LED0
Text GLabel 6850 2600 2    50   Input ~ 0
LED1
Text GLabel 6950 2700 2    50   Input ~ 0
LED2
$Comp
L power:GND #PWR015
U 1 1 5DCB76E8
P 6450 2800
F 0 "#PWR015" H 6450 2550 50  0001 C CNN
F 1 "GND" V 6455 2672 50  0000 R CNN
F 2 "" H 6450 2800 50  0001 C CNN
F 3 "" H 6450 2800 50  0001 C CNN
	1    6450 2800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6200 2800 6450 2800
Text Notes 2850 6050 0    50   ~ 0
Audio jack\nMust be isolated from the chassis\n
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5DC8A83C
P 2900 5600
F 0 "J2" V 3053 5413 50  0000 R CNN
F 1 "Conn_01x02_Male" V 2962 5413 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2900 5600 50  0001 C CNN
F 3 "~" H 2900 5600 50  0001 C CNN
	1    2900 5600
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R8
U 1 1 5DC8FDEC
P 2650 1600
F 0 "R8" V 2443 1600 50  0000 C CNN
F 1 "0" V 2534 1600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2580 1600 50  0001 C CNN
F 3 "~" H 2650 1600 50  0001 C CNN
	1    2650 1600
	0    1    1    0   
$EndComp
$Comp
L Device:R R9
U 1 1 5DC8FF20
P 7500 2050
F 0 "R9" V 7600 2050 50  0000 C CNN
F 1 "0" V 7500 2050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7430 2050 50  0001 C CNN
F 3 "~" H 7500 2050 50  0001 C CNN
	1    7500 2050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7150 2050 7350 2050
Wire Wire Line
	7650 2050 7750 2050
$Comp
L Device:R R11
U 1 1 5DCA1421
P 1900 850
F 0 "R11" H 1830 804 50  0000 R CNN
F 1 "0" H 1830 895 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1830 850 50  0001 C CNN
F 3 "~" H 1900 850 50  0001 C CNN
	1    1900 850 
	-1   0    0    1   
$EndComp
Wire Wire Line
	2000 950  2000 700 
Wire Wire Line
	2000 700  1900 700 
Connection ~ 2000 950 
Wire Wire Line
	1900 700  1700 700 
Wire Wire Line
	1250 700  1250 1300
Connection ~ 1900 700 
$Comp
L power:+5V #PWR0101
U 1 1 5DCABA56
P 1700 700
F 0 "#PWR0101" H 1700 550 50  0001 C CNN
F 1 "+5V" H 1715 873 50  0000 C CNN
F 2 "" H 1700 700 50  0001 C CNN
F 3 "" H 1700 700 50  0001 C CNN
	1    1700 700 
	-1   0    0    1   
$EndComp
Connection ~ 1700 700 
Wire Wire Line
	1700 700  1250 700 
$Comp
L Device:R R16
U 1 1 5DCBF145
P 7900 1550
F 0 "R16" V 7693 1550 50  0000 C CNN
F 1 "0" V 7784 1550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7830 1550 50  0001 C CNN
F 3 "~" H 7900 1550 50  0001 C CNN
	1    7900 1550
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5DCBF5A2
P 7650 1550
F 0 "#PWR0102" H 7650 1400 50  0001 C CNN
F 1 "+5V" H 7665 1723 50  0000 C CNN
F 2 "" H 7650 1550 50  0001 C CNN
F 3 "" H 7650 1550 50  0001 C CNN
	1    7650 1550
	-1   0    0    1   
$EndComp
Wire Wire Line
	7150 1550 7650 1550
Connection ~ 7650 1550
Wire Wire Line
	7650 1550 7750 1550
Wire Wire Line
	8050 1550 8150 1550
$Comp
L Device:R R18
U 1 1 5DCCA542
P 3050 2700
F 0 "R18" V 2843 2700 50  0000 C CNN
F 1 "0" V 2934 2700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2980 2700 50  0001 C CNN
F 3 "~" H 3050 2700 50  0001 C CNN
	1    3050 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	4100 2200 4100 1900
Wire Wire Line
	4100 1900 4250 1900
Wire Wire Line
	3800 2200 4100 2200
Wire Wire Line
	4250 1700 4250 1900
Wire Wire Line
	3800 1700 4250 1700
Wire Wire Line
	7150 1950 7300 1950
Wire Wire Line
	7150 2250 7300 2250
$Comp
L power:+5V #PWR0105
U 1 1 5DCDF123
P 7300 2250
F 0 "#PWR0105" H 7300 2100 50  0001 C CNN
F 1 "+5V" H 7315 2423 50  0000 C CNN
F 2 "" H 7300 2250 50  0001 C CNN
F 3 "" H 7300 2250 50  0001 C CNN
	1    7300 2250
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5DCDF209
P 7300 1950
F 0 "#PWR0106" H 7300 1700 50  0001 C CNN
F 1 "GND" H 7305 1777 50  0000 C CNN
F 2 "" H 7300 1950 50  0001 C CNN
F 3 "" H 7300 1950 50  0001 C CNN
	1    7300 1950
	1    0    0    -1  
$EndComp
Connection ~ 7300 1950
$Comp
L Device:R R23
U 1 1 5DCDF7F3
P 2800 2600
F 0 "R23" V 2593 2600 50  0000 C CNN
F 1 "0" V 2684 2600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P20.32mm_Horizontal" V 2730 2600 50  0001 C CNN
F 3 "~" H 2800 2600 50  0001 C CNN
	1    2800 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	2950 2600 3050 2600
Wire Wire Line
	2500 2600 2650 2600
Wire Wire Line
	6200 6450 6200 6800
Wire Wire Line
	2400 5600 2400 5900
Wire Wire Line
	7300 1950 7750 1950
Wire Wire Line
	4050 1150 4500 1150
Wire Wire Line
	4050 1250 4500 1250
Connection ~ 4250 1900
$Comp
L Device:R R7
U 1 1 5DD2DA4C
P 4350 1350
F 0 "R7" V 4143 1350 50  0000 C CNN
F 1 "0" V 4234 1350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4280 1350 50  0001 C CNN
F 3 "~" H 4350 1350 50  0001 C CNN
	1    4350 1350
	0    1    1    0   
$EndComp
Wire Wire Line
	4050 1350 4200 1350
$Comp
L Device:R R10
U 1 1 5DD30D64
P 7500 2250
F 0 "R10" V 7293 2250 50  0000 C CNN
F 1 "0" V 7384 2250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7430 2250 50  0001 C CNN
F 3 "~" H 7500 2250 50  0001 C CNN
	1    7500 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	7300 2250 7350 2250
Connection ~ 7300 2250
Wire Wire Line
	7650 2250 7750 2250
$Comp
L Device:R R12
U 1 1 5DD37235
P 2650 3700
F 0 "R12" V 2443 3700 50  0000 C CNN
F 1 "0" V 2534 3700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2580 3700 50  0001 C CNN
F 3 "~" H 2650 3700 50  0001 C CNN
	1    2650 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	2800 3700 3200 3700
$Comp
L Device:R R13
U 1 1 5DD3A89F
P 3000 3100
F 0 "R13" V 2793 3100 50  0000 C CNN
F 1 "0" V 2884 3100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 2930 3100 50  0001 C CNN
F 3 "~" H 3000 3100 50  0001 C CNN
	1    3000 3100
	0    1    1    0   
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U1
U 1 1 5C375D75
P 1900 2500
F 0 "U1" H 1259 2546 50  0000 R CNN
F 1 "ATmega328P-PU" H 1259 2455 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm_Socket" H 1900 2500 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 1900 2500 50  0001 C CNN
	1    1900 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R15
U 1 1 5DD41F27
P 2650 3400
F 0 "R15" V 2443 3400 50  0000 C CNN
F 1 "0" V 2534 3400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2580 3400 50  0001 C CNN
F 3 "~" H 2650 3400 50  0001 C CNN
	1    2650 3400
	0    1    1    0   
$EndComp
$Comp
L Device:R R17
U 1 1 5DD4236A
P 1900 4300
F 0 "R17" H 1970 4346 50  0000 L CNN
F 1 "0" H 1970 4255 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1830 4300 50  0001 C CNN
F 3 "~" H 1900 4300 50  0001 C CNN
	1    1900 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5DD4264A
P 1900 4050
F 0 "#PWR0103" H 1900 3800 50  0001 C CNN
F 1 "GND" V 1905 3922 50  0000 R CNN
F 2 "" H 1900 4050 50  0001 C CNN
F 3 "" H 1900 4050 50  0001 C CNN
	1    1900 4050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1900 4000 1900 4050
Connection ~ 1900 4050
Wire Wire Line
	1900 4050 1900 4150
$Comp
L Device:R R19
U 1 1 5DD45D73
P 2000 5600
F 0 "R19" H 2070 5646 50  0000 L CNN
F 1 "0" H 2070 5555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1930 5600 50  0001 C CNN
F 3 "~" H 2000 5600 50  0001 C CNN
	1    2000 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 5600 1500 5750
Wire Wire Line
	1500 5750 2000 5750
Wire Wire Line
	2000 5950 2000 5750
Connection ~ 2000 5750
$Comp
L power:GND #PWR0104
U 1 1 5DD4C752
P 2000 5450
F 0 "#PWR0104" H 2000 5200 50  0001 C CNN
F 1 "GND" V 2005 5322 50  0000 R CNN
F 2 "" H 2000 5450 50  0001 C CNN
F 3 "" H 2000 5450 50  0001 C CNN
	1    2000 5450
	0    -1   -1   0   
$EndComp
Connection ~ 2000 5450
$Comp
L Device:R R20
U 1 1 5DD4CBEE
P 5200 1350
F 0 "R20" V 4993 1350 50  0000 C CNN
F 1 "0" V 5084 1350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5130 1350 50  0001 C CNN
F 3 "~" H 5200 1350 50  0001 C CNN
	1    5200 1350
	0    1    1    0   
$EndComp
Wire Wire Line
	5000 1350 5050 1350
$Comp
L power:GND #PWR0107
U 1 1 5DD5023E
P 5050 1350
F 0 "#PWR0107" H 5050 1100 50  0001 C CNN
F 1 "GND" H 5055 1177 50  0000 C CNN
F 2 "" H 5050 1350 50  0001 C CNN
F 3 "" H 5050 1350 50  0001 C CNN
	1    5050 1350
	1    0    0    -1  
$EndComp
Connection ~ 5050 1350
$Comp
L Device:R R21
U 1 1 5DD5030A
P 5500 1350
F 0 "R21" V 5293 1350 50  0000 C CNN
F 1 "0" V 5384 1350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5430 1350 50  0001 C CNN
F 3 "~" H 5500 1350 50  0001 C CNN
	1    5500 1350
	0    1    1    0   
$EndComp
Connection ~ 5350 1350
$Comp
L power:GND #PWR0108
U 1 1 5DD503E9
P 5650 1350
F 0 "#PWR0108" H 5650 1100 50  0001 C CNN
F 1 "GND" H 5655 1177 50  0000 C CNN
F 2 "" H 5650 1350 50  0001 C CNN
F 3 "" H 5650 1350 50  0001 C CNN
	1    5650 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R22
U 1 1 5DD50C9B
P 6550 2500
F 0 "R22" V 6343 2500 50  0000 C CNN
F 1 "0" V 6434 2500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 6480 2500 50  0001 C CNN
F 3 "~" H 6550 2500 50  0001 C CNN
	1    6550 2500
	0    1    1    0   
$EndComp
$Comp
L Device:R R24
U 1 1 5DD50D5E
P 6550 2600
F 0 "R24" V 6343 2600 50  0000 C CNN
F 1 "0" V 6434 2600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 6480 2600 50  0001 C CNN
F 3 "~" H 6550 2600 50  0001 C CNN
	1    6550 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 2500 6400 2500
Wire Wire Line
	6200 2600 6400 2600
Wire Wire Line
	6700 2500 6850 2500
Wire Wire Line
	6700 2600 6850 2600
$Comp
L Device:R R25
U 1 1 5DD5DD90
P 6400 2700
F 0 "R25" V 6607 2700 50  0000 C CNN
F 1 "0" V 6516 2700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6330 2700 50  0001 C CNN
F 3 "~" H 6400 2700 50  0001 C CNN
	1    6400 2700
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R26
U 1 1 5DD64783
P 6800 2700
F 0 "R26" V 6593 2700 50  0000 C CNN
F 1 "0" V 6684 2700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P25.40mm_Horizontal" V 6730 2700 50  0001 C CNN
F 3 "~" H 6800 2700 50  0001 C CNN
	1    6800 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 2700 6250 2700
Wire Wire Line
	6550 2700 6650 2700
Wire Wire Line
	2500 3500 2800 3500
$Comp
L power:+5V #PWR0109
U 1 1 5DD3D59B
P 4450 2850
F 0 "#PWR0109" H 4450 2700 50  0001 C CNN
F 1 "+5V" H 4465 3023 50  0000 C CNN
F 2 "" H 4450 2850 50  0001 C CNN
F 3 "" H 4450 2850 50  0001 C CNN
	1    4450 2850
	0    -1   -1   0   
$EndComp
Text GLabel 4550 1500 3    50   Input ~ 0
NRST
Wire Wire Line
	4550 1500 4550 1350
Wire Wire Line
	4550 1350 4500 1350
Connection ~ 4500 1350
$Comp
L Device:R R14
U 1 1 5DD45D47
P 4450 3000
F 0 "R14" H 4520 3046 50  0000 L CNN
F 1 "0" H 4520 2955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4380 3000 50  0001 C CNN
F 3 "~" H 4450 3000 50  0001 C CNN
	1    4450 3000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 5DD45DEB
P 4450 3150
F 0 "#PWR0110" H 4450 3000 50  0001 C CNN
F 1 "+5V" V 4465 3278 50  0000 L CNN
F 2 "" H 4450 3150 50  0001 C CNN
F 3 "" H 4450 3150 50  0001 C CNN
	1    4450 3150
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x03_Male J10
U 1 1 5DDB39D5
P 4550 3350
F 0 "J10" H 4523 3280 50  0000 R CNN
F 1 "Conn_01x03_Male" V 4523 3371 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4550 3350 50  0001 C CNN
F 3 "~" H 4550 3350 50  0001 C CNN
	1    4550 3350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5DDC0B53
P 4650 2850
F 0 "#PWR0111" H 4650 2600 50  0001 C CNN
F 1 "GND" V 4655 2722 50  0000 R CNN
F 2 "" H 4650 2850 50  0001 C CNN
F 3 "" H 4650 2850 50  0001 C CNN
	1    4650 2850
	0    -1   -1   0   
$EndComp
Connection ~ 4450 3150
Wire Wire Line
	4550 3150 4550 2800
Wire Wire Line
	2500 2800 4550 2800
Wire Wire Line
	2500 3100 2850 3100
$EndSCHEMATC
