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
$Comp
L Device:R R1
U 1 1 5C39E631
P 4900 2750
F 0 "R1" V 4693 2750 50  0000 C CNN
F 1 "510" V 4784 2750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4830 2750 50  0001 C CNN
F 3 "~" H 4900 2750 50  0001 C CNN
	1    4900 2750
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5C39E74D
P 4900 3150
F 0 "R2" V 4693 3150 50  0000 C CNN
F 1 "510" V 4784 3150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4830 3150 50  0001 C CNN
F 3 "~" H 4900 3150 50  0001 C CNN
	1    4900 3150
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5C39E7B9
P 4900 3550
F 0 "R3" V 4693 3550 50  0000 C CNN
F 1 "510" V 4784 3550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4830 3550 50  0001 C CNN
F 3 "~" H 4900 3550 50  0001 C CNN
	1    4900 3550
	0    1    1    0   
$EndComp
$Comp
L Device:LED D1
U 1 1 5C39E890
P 5200 2750
F 0 "D1" H 5192 2495 50  0000 C CNN
F 1 "LED" H 5192 2586 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5200 2750 50  0001 C CNN
F 3 "~" H 5200 2750 50  0001 C CNN
	1    5200 2750
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D2
U 1 1 5C39E95C
P 5200 3150
F 0 "D2" H 5192 2895 50  0000 C CNN
F 1 "LED" H 5192 2986 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5200 3150 50  0001 C CNN
F 3 "~" H 5200 3150 50  0001 C CNN
	1    5200 3150
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D3
U 1 1 5C39E9C2
P 5200 3550
F 0 "D3" H 5192 3295 50  0000 C CNN
F 1 "LED" H 5192 3386 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5200 3550 50  0001 C CNN
F 3 "~" H 5200 3550 50  0001 C CNN
	1    5200 3550
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5C39EA68
P 5450 3600
F 0 "#PWR02" H 5450 3350 50  0001 C CNN
F 1 "GND" H 5455 3427 50  0000 C CNN
F 2 "" H 5450 3600 50  0001 C CNN
F 3 "" H 5450 3600 50  0001 C CNN
	1    5450 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2750 5450 2750
Wire Wire Line
	5450 2750 5450 3150
Wire Wire Line
	5350 3550 5450 3550
Connection ~ 5450 3550
Wire Wire Line
	5450 3550 5450 3600
Wire Wire Line
	5350 3150 5450 3150
Connection ~ 5450 3150
Wire Wire Line
	5450 3150 5450 3550
Text GLabel 4750 3550 0    50   Input ~ 0
LED2
Text GLabel 4750 3150 0    50   Input ~ 0
LED1
Text GLabel 4750 2750 0    50   Input ~ 0
LED0
$Comp
L Connector:Conn_01x04_Female J1
U 1 1 5DC8C46D
P 3250 2850
F 0 "J1" H 3277 2826 50  0000 L CNN
F 1 "Conn_01x04_Female" H 3277 2735 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 3250 2850 50  0001 C CNN
F 3 "~" H 3250 2850 50  0001 C CNN
	1    3250 2850
	1    0    0    -1  
$EndComp
Text GLabel 3050 2750 0    50   Output ~ 0
LED0
Text GLabel 3050 2850 0    50   Output ~ 0
LED1
Text GLabel 3050 2950 0    50   Output ~ 0
LED2
$Comp
L power:GND #PWR01
U 1 1 5DC8C568
P 2600 3050
F 0 "#PWR01" H 2600 2800 50  0001 C CNN
F 1 "GND" H 2605 2877 50  0000 C CNN
F 2 "" H 2600 3050 50  0001 C CNN
F 3 "" H 2600 3050 50  0001 C CNN
	1    2600 3050
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5DC8C5AD
P 2950 3050
F 0 "#FLG01" H 2950 3125 50  0001 C CNN
F 1 "PWR_FLAG" H 2950 3223 50  0000 C CNN
F 2 "" H 2950 3050 50  0001 C CNN
F 3 "~" H 2950 3050 50  0001 C CNN
	1    2950 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	2600 3050 2950 3050
Connection ~ 2950 3050
Wire Wire Line
	2950 3050 3050 3050
$EndSCHEMATC
