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
LIBS:tinkerforge
LIBS:client-cache
EELAYER 25 0
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
L SW_Push SW1
U 1 1 5B096A2C
P 4800 2150
F 0 "SW1" H 4850 2250 50  0000 L CNN
F 1 "SW_Set" H 4800 2050 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h9.5mm" H 4800 2350 50  0001 C CNN
F 3 "" H 4800 2350 50  0001 C CNN
	1    4800 2150
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW2
U 1 1 5B096A9D
P 4800 2500
F 0 "SW2" H 4850 2600 50  0000 L CNN
F 1 "SW_Plus" H 4800 2440 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h9.5mm" H 4800 2700 50  0001 C CNN
F 3 "" H 4800 2700 50  0001 C CNN
	1    4800 2500
	1    0    0    -1  
$EndComp
$Comp
L TM1637 U1
U 1 1 5B772CB8
P 4850 3800
F 0 "U1" H 4500 4250 60  0000 C CNN
F 1 "TM1637" H 5000 3050 60  0000 C CNN
F 2 "SparkFun-DigitalIC:SOP20" H 4850 3800 60  0001 C CNN
F 3 "" H 4850 3800 60  0000 C CNN
	1    4850 3800
	-1   0    0    -1  
$EndComp
$Comp
L CA56-12SEKWA U2
U 1 1 5B772D58
P 9000 3900
F 0 "U2" H 8050 4350 50  0000 C CNN
F 1 "CA56-12SEKWA" H 9760 4350 50  0000 C CNN
F 2 "Displays_7-Segment:CA56-12SEKWA" H 9000 3300 50  0001 C CNN
F 3 "" H 8620 3930 50  0001 C CNN
	1    9000 3900
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5B77349C
P 3000 4150
F 0 "R1" V 3080 4150 50  0000 C CNN
F 1 "10K" V 3000 4150 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2930 4150 50  0001 C CNN
F 3 "" H 3000 4150 50  0001 C CNN
	1    3000 4150
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5B773778
P 2550 4250
F 0 "C1" H 2575 4350 50  0000 L CNN
F 1 "100P" H 2575 4150 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 2588 4100 50  0001 C CNN
F 3 "" H 2550 4250 50  0001 C CNN
	1    2550 4250
	-1   0    0    1   
$EndComp
$Comp
L C C2
U 1 1 5B77380F
P 2800 4250
F 0 "C2" H 2825 4350 50  0000 L CNN
F 1 "100P" H 2825 4150 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 2838 4100 50  0001 C CNN
F 3 "" H 2800 4250 50  0001 C CNN
	1    2800 4250
	-1   0    0    1   
$EndComp
$Comp
L C C4
U 1 1 5B773846
P 3500 5650
F 0 "C4" H 3525 5750 50  0000 L CNN
F 1 "104" H 3525 5550 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 3538 5500 50  0001 C CNN
F 3 "" H 3500 5650 50  0001 C CNN
	1    3500 5650
	1    0    0    -1  
$EndComp
$Comp
L CP C3
U 1 1 5B773877
P 3150 5650
F 0 "C3" H 3175 5750 50  0000 L CNN
F 1 "100uF" H 3175 5550 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Hand" H 3188 5500 50  0001 C CNN
F 3 "" H 3150 5650 50  0001 C CNN
	1    3150 5650
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW3
U 1 1 5B096B3E
P 4800 2800
F 0 "SW3" H 4850 2900 50  0000 L CNN
F 1 "SW_Minus" H 4800 2740 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h9.5mm" H 4800 3000 50  0001 C CNN
F 3 "" H 4800 3000 50  0001 C CNN
	1    4800 2800
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5B777BAA
P 3250 4150
F 0 "R2" V 3330 4150 50  0000 C CNN
F 1 "10K" V 3250 4150 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3180 4150 50  0001 C CNN
F 3 "" H 3250 4150 50  0001 C CNN
	1    3250 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 3600 5600 3600
Wire Wire Line
	5450 3700 5650 3700
Wire Wire Line
	5450 3800 5700 3800
Wire Wire Line
	4200 4300 4200 5000
Wire Wire Line
	4200 4300 4300 4300
Wire Wire Line
	4050 4200 4050 5150
Wire Wire Line
	4050 4200 4300 4200
Wire Wire Line
	4000 4100 4000 5300
Wire Wire Line
	4000 4100 4300 4100
Wire Wire Line
	3950 4000 3950 5450
Wire Wire Line
	3950 4000 4300 4000
Wire Wire Line
	4600 2150 4600 2800
Connection ~ 4600 2500
Connection ~ 4600 2800
Wire Wire Line
	4600 2500 4200 2500
Wire Wire Line
	4200 2500 4200 3600
Wire Wire Line
	4200 3600 4300 3600
Wire Wire Line
	5000 2800 5600 2800
Wire Wire Line
	5600 2800 5600 3600
Connection ~ 5600 3600
Wire Wire Line
	5000 2500 5650 2500
Wire Wire Line
	5650 2500 5650 3700
Connection ~ 5650 3700
Wire Wire Line
	5000 2150 5700 2150
Wire Wire Line
	5700 2150 5700 3800
Connection ~ 5700 3800
Wire Wire Line
	2100 3700 4300 3700
Wire Wire Line
	2100 3800 4300 3800
Wire Wire Line
	2100 3900 4300 3900
$Comp
L VCC #PWR01
U 1 1 5B778169
P 3300 5100
F 0 "#PWR01" H 3300 4950 50  0001 C CNN
F 1 "VCC" H 3300 5250 50  0000 C CNN
F 2 "" H 3300 5100 50  0001 C CNN
F 3 "" H 3300 5100 50  0001 C CNN
	1    3300 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 5500 3150 5250
Wire Wire Line
	3150 5250 3500 5250
Wire Wire Line
	3500 5250 3500 5500
Wire Wire Line
	3150 5800 3150 5900
Wire Wire Line
	3150 5900 3500 5900
Wire Wire Line
	3500 5900 3500 5800
Wire Wire Line
	5450 3000 5450 3500
NoConn ~ 5450 4400
NoConn ~ 4300 4400
NoConn ~ 4300 3500
Wire Wire Line
	3300 5100 3300 5250
Connection ~ 3300 5250
$Comp
L VCC #PWR02
U 1 1 5B78A2F0
P 3700 4350
F 0 "#PWR02" H 3700 4200 50  0001 C CNN
F 1 "VCC" H 3700 4500 50  0000 C CNN
F 2 "" H 3700 4350 50  0001 C CNN
F 3 "" H 3700 4350 50  0001 C CNN
	1    3700 4350
	-1   0    0    1   
$EndComp
Wire Wire Line
	3700 3900 3700 4350
Connection ~ 3700 3900
$Comp
L GNDREF #PWR03
U 1 1 5B794BC6
P 3300 6100
F 0 "#PWR03" H 3300 5850 50  0001 C CNN
F 1 "GNDREF" H 3300 5950 50  0000 C CNN
F 2 "" H 3300 6100 50  0001 C CNN
F 3 "" H 3300 6100 50  0001 C CNN
	1    3300 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 5900 3300 6100
Connection ~ 3300 5900
$Comp
L GNDREF #PWR04
U 1 1 5B794DAB
P 2650 4700
F 0 "#PWR04" H 2650 4450 50  0001 C CNN
F 1 "GNDREF" H 2650 4550 50  0000 C CNN
F 2 "" H 2650 4700 50  0001 C CNN
F 3 "" H 2650 4700 50  0001 C CNN
	1    2650 4700
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR05
U 1 1 5B794E61
P 5150 3050
F 0 "#PWR05" H 5150 2800 50  0001 C CNN
F 1 "GNDREF" H 5150 2900 50  0000 C CNN
F 2 "" H 5150 3050 50  0001 C CNN
F 3 "" H 5150 3050 50  0001 C CNN
	1    5150 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 3000 5150 3000
Wire Wire Line
	5150 3000 5150 3050
$Comp
L PWR_FLAG #FLG06
U 1 1 5B794FF8
P 2550 4600
F 0 "#FLG06" H 2550 4675 50  0001 C CNN
F 1 "PWR_FLAG" H 2550 4750 50  0000 C CNN
F 2 "" H 2550 4600 50  0001 C CNN
F 3 "" H 2550 4600 50  0001 C CNN
	1    2550 4600
	0    -1   -1   0   
$EndComp
$Comp
L PWR_FLAG #FLG07
U 1 1 5B795471
P 3750 4350
F 0 "#FLG07" H 3750 4425 50  0001 C CNN
F 1 "PWR_FLAG" H 3750 4500 50  0000 C CNN
F 2 "" H 3750 4350 50  0001 C CNN
F 3 "" H 3750 4350 50  0001 C CNN
	1    3750 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 4350 3750 4350
Wire Wire Line
	2800 4100 2800 3700
Connection ~ 2800 3700
Wire Wire Line
	2550 4100 2550 3800
Connection ~ 2550 3800
Wire Wire Line
	2550 4400 2800 4400
Wire Wire Line
	2400 4000 2400 4500
Wire Wire Line
	2400 4500 2650 4500
Wire Wire Line
	2650 4400 2650 4700
Connection ~ 2650 4400
Connection ~ 2650 4500
Wire Wire Line
	2650 4600 2550 4600
Connection ~ 2650 4600
Connection ~ 3250 3800
Connection ~ 3000 3700
Wire Wire Line
	3000 4300 3700 4300
Connection ~ 3700 4300
Connection ~ 3250 4300
Wire Wire Line
	3250 3800 3250 4000
Wire Wire Line
	3000 3700 3000 4000
$Comp
L Conn_01x04_Male J1
U 1 1 5B7DADC8
P 1900 3800
F 0 "J1" H 1900 4000 50  0000 C CNN
F 1 "Conn_01x04_Male" H 1900 3500 50  0000 C CNN
F 2 "Connector_JST_2:JST_PH_B4B-PH-SM4-TB_1x04-1MP_P2.00mm_Vertical" H 1900 3800 50  0001 C CNN
F 3 "" H 1900 3800 50  0001 C CNN
	1    1900 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 4000 2100 4000
$Comp
L R R8
U 1 1 5B85A150
P 6850 4100
F 0 "R8" V 6930 4100 50  0000 C CNN
F 1 "0" V 6850 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 4100 50  0001 C CNN
F 3 "" H 6850 4100 50  0001 C CNN
	1    6850 4100
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 5B85A2C6
P 6850 4250
F 0 "R9" V 6930 4250 50  0000 C CNN
F 1 "0" V 6850 4250 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 4250 50  0001 C CNN
F 3 "" H 6850 4250 50  0001 C CNN
	1    6850 4250
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 5B85A304
P 6850 4400
F 0 "R10" V 6930 4400 50  0000 C CNN
F 1 "0" V 6850 4400 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 4400 50  0001 C CNN
F 3 "" H 6850 4400 50  0001 C CNN
	1    6850 4400
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 5B85A345
P 6850 3950
F 0 "R7" V 6930 3950 50  0000 C CNN
F 1 "0" V 6850 3950 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 3950 50  0001 C CNN
F 3 "" H 6850 3950 50  0001 C CNN
	1    6850 3950
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5B85A38F
P 6850 3800
F 0 "R6" V 6930 3800 50  0000 C CNN
F 1 "0" V 6850 3800 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 3800 50  0001 C CNN
F 3 "" H 6850 3800 50  0001 C CNN
	1    6850 3800
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 5B85A3DC
P 6850 3650
F 0 "R5" V 6930 3650 50  0000 C CNN
F 1 "0" V 6850 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 3650 50  0001 C CNN
F 3 "" H 6850 3650 50  0001 C CNN
	1    6850 3650
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 5B85A440
P 6850 3500
F 0 "R4" V 6930 3500 50  0000 C CNN
F 1 "0" V 6850 3500 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 3500 50  0001 C CNN
F 3 "" H 6850 3500 50  0001 C CNN
	1    6850 3500
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 5B85A4A2
P 6850 3350
F 0 "R3" V 6930 3350 50  0000 C CNN
F 1 "0" V 6850 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 3350 50  0001 C CNN
F 3 "" H 6850 3350 50  0001 C CNN
	1    6850 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	7900 4300 7600 4300
Wire Wire Line
	7600 4300 7600 4400
Wire Wire Line
	7600 4400 7000 4400
Wire Wire Line
	7000 4250 7550 4250
Wire Wire Line
	7550 4250 7550 4200
Wire Wire Line
	7550 4200 7900 4200
Wire Wire Line
	7900 4100 7000 4100
Wire Wire Line
	7000 3950 7500 3950
Wire Wire Line
	7500 3950 7500 4000
Wire Wire Line
	7500 4000 7900 4000
Wire Wire Line
	7900 3900 7550 3900
Wire Wire Line
	7550 3900 7550 3800
Wire Wire Line
	7550 3800 7000 3800
Wire Wire Line
	7000 3650 7600 3650
Wire Wire Line
	7600 3650 7600 3800
Wire Wire Line
	7600 3800 7900 3800
Wire Wire Line
	7900 3700 7700 3700
Wire Wire Line
	7700 3700 7700 3600
Wire Wire Line
	7700 3600 7150 3600
Wire Wire Line
	7150 3600 7150 3500
Wire Wire Line
	7150 3500 7000 3500
Wire Wire Line
	7900 3600 7800 3600
Wire Wire Line
	7800 3600 7800 3500
Wire Wire Line
	7800 3500 7300 3500
Wire Wire Line
	7300 3500 7300 3350
Wire Wire Line
	7300 3350 7000 3350
Wire Wire Line
	6700 4400 6050 4400
Wire Wire Line
	6050 4400 5950 4300
Wire Wire Line
	5950 4300 5450 4300
Wire Wire Line
	6700 4250 6100 4250
Wire Wire Line
	6100 4250 6000 4200
Wire Wire Line
	6000 4200 5450 4200
Wire Wire Line
	6700 4100 5450 4100
Wire Wire Line
	6700 3950 6100 3950
Wire Wire Line
	6100 3950 6050 4000
Wire Wire Line
	6050 4000 5450 4000
Wire Wire Line
	5450 3900 6000 3900
Wire Wire Line
	6000 3900 6150 3800
Wire Wire Line
	6150 3800 6700 3800
Wire Wire Line
	6700 3650 5950 3650
Wire Wire Line
	5950 3650 5700 3800
Wire Wire Line
	6700 3500 6000 3500
Wire Wire Line
	6000 3500 5650 3700
Wire Wire Line
	6700 3350 6000 3350
Wire Wire Line
	6000 3350 5600 3600
$Comp
L R R11
U 1 1 5B85BCFF
P 6850 5000
F 0 "R11" V 6930 5000 50  0000 C CNN
F 1 "0" V 6850 5000 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 5000 50  0001 C CNN
F 3 "" H 6850 5000 50  0001 C CNN
	1    6850 5000
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 5B85BD78
P 6850 5150
F 0 "R12" V 6930 5150 50  0000 C CNN
F 1 "0" V 6850 5150 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 5150 50  0001 C CNN
F 3 "" H 6850 5150 50  0001 C CNN
	1    6850 5150
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 5B85BDF4
P 6850 5300
F 0 "R13" V 6930 5300 50  0000 C CNN
F 1 "0" V 6850 5300 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 5300 50  0001 C CNN
F 3 "" H 6850 5300 50  0001 C CNN
	1    6850 5300
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 5B85BE62
P 6850 5450
F 0 "R14" V 6930 5450 50  0000 C CNN
F 1 "0" V 6850 5450 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6780 5450 50  0001 C CNN
F 3 "" H 6850 5450 50  0001 C CNN
	1    6850 5450
	0    1    1    0   
$EndComp
Wire Wire Line
	10200 4300 10200 5000
Wire Wire Line
	10200 5000 7000 5000
Wire Wire Line
	4200 5000 6700 5000
Wire Wire Line
	10200 4200 10300 4200
Wire Wire Line
	10300 4200 10300 5150
Wire Wire Line
	10300 5150 7000 5150
Wire Wire Line
	4050 5150 6700 5150
Wire Wire Line
	10200 4100 10450 4100
Wire Wire Line
	10450 4100 10450 5350
Wire Wire Line
	10450 5350 10200 5300
Wire Wire Line
	10200 5300 7000 5300
Wire Wire Line
	4000 5300 6700 5300
Wire Wire Line
	10200 4000 10550 4000
Wire Wire Line
	10550 4000 10550 5450
Wire Wire Line
	10550 5450 7000 5450
Wire Wire Line
	3950 5450 6700 5450
$EndSCHEMATC
