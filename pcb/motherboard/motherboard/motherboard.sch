EESchema Schematic File Version 4
LIBS:motherboard-cache
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
L ESP8266:RobotDyn_NodeMCU U1
U 1 1 5BA67355
P 6400 3300
F 0 "U1" H 6400 4387 60  0000 C CNN
F 1 "RobotDyn_NodeMCU" H 6400 4281 60  0000 C CNN
F 2 "" H 5800 2450 60  0000 C CNN
F 3 "" H 5800 2450 60  0000 C CNN
	1    6400 3300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 5BA67579
P 7700 1850
F 0 "J3" H 7620 1425 50  0000 C CNN
F 1 "Display_01x04" H 7620 1516 50  0000 C CNN
F 2 "" H 7700 1850 50  0001 C CNN
F 3 "~" H 7700 1850 50  0001 C CNN
	1    7700 1850
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5BA6807A
P 4950 2150
F 0 "J2" H 5030 2192 50  0000 L CNN
F 1 "Sensor_Conn_01x03" H 5030 2101 50  0000 L CNN
F 2 "" H 4950 2150 50  0001 C CNN
F 3 "~" H 4950 2150 50  0001 C CNN
	1    4950 2150
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5BA6825B
P 4800 4350
F 0 "J1" H 4880 4342 50  0000 L CNN
F 1 "Power_Conn_01x02" H 4880 4251 50  0000 L CNN
F 2 "" H 4800 4350 50  0001 C CNN
F 3 "~" H 4800 4350 50  0001 C CNN
	1    4800 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 2900 4850 2900
$Comp
L Device:R R1
U 1 1 5BABD5E1
P 4850 3200
F 0 "R1" H 4780 3154 50  0000 R CNN
F 1 "47k" H 4780 3245 50  0000 R CNN
F 2 "" V 4780 3200 50  0001 C CNN
F 3 "~" H 4850 3200 50  0001 C CNN
	1    4850 3200
	-1   0    0    1   
$EndComp
Wire Wire Line
	4800 4150 4800 4000
Wire Wire Line
	4800 4000 5400 4000
Wire Wire Line
	4700 4150 4700 3900
Wire Wire Line
	4700 3900 5100 3900
Wire Wire Line
	4850 2350 4850 2900
Wire Wire Line
	5600 3600 5150 3600
Wire Wire Line
	4850 3600 4850 3350
Wire Wire Line
	4850 3050 4850 2900
Connection ~ 4850 2900
Wire Wire Line
	7600 2050 7600 2600
Wire Wire Line
	7600 2600 7200 2600
Wire Wire Line
	7700 2050 7700 2700
Wire Wire Line
	7700 2700 7200 2700
Wire Wire Line
	4950 2350 4950 2600
Wire Wire Line
	4950 2600 5150 2600
Wire Wire Line
	5150 2600 5150 3600
Connection ~ 5150 3600
Wire Wire Line
	5150 3600 4850 3600
Wire Wire Line
	5050 2350 5300 2350
Wire Wire Line
	5300 2350 5300 3900
Connection ~ 5300 3900
Wire Wire Line
	5300 3900 5600 3900
NoConn ~ 5600 2600
NoConn ~ 5600 2700
NoConn ~ 5600 2800
NoConn ~ 5600 3000
NoConn ~ 5600 3100
NoConn ~ 5600 3200
NoConn ~ 5600 3300
NoConn ~ 5600 3400
NoConn ~ 5600 3500
NoConn ~ 5600 3700
NoConn ~ 5600 3800
Text Label 6700 2550 0    50   ~ 0
диспллей_питаеться_от_5_надо_преобразователь_уровней
Wire Wire Line
	7900 2050 7900 4350
Wire Wire Line
	7900 4350 5100 4350
Wire Wire Line
	5100 4350 5100 3900
Connection ~ 5100 3900
Wire Wire Line
	5100 3900 5300 3900
Wire Wire Line
	7800 2050 7800 4250
Wire Wire Line
	7800 4250 5400 4250
Wire Wire Line
	5400 4250 5400 4000
Connection ~ 5400 4000
Wire Wire Line
	5400 4000 5600 4000
$EndSCHEMATC
