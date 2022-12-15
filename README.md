# traffic_light
### This is 221 MPU_MCU assignment
  - HCMUT - Ho Chi Minh University of Technology - VNU-HCM
  - Author:
    * Nguyen Phuc Dang - 2012968
    * Nguyen Kim Ngoc Vy - 2015118
### Timers informations: 
	* timer1: count down for exiting Pedestrian MODE.
	* timer2: sending UART about Lights counters value.
	* timer3: counter of 1st Traffic Light in AUTO MODE.
	* timer4: counter of 2nd Traffic Light.
	* timer5: counter for turning on Buzzer.
	* timer6: counter for turning off Buzzer.
	* timer7: counter for toggle LED in TUNING MODE.
	* timer8: count down for exiting MANUAL MODE or count down for exiting TUNING MODE.
	* timer9: toggle LED and sending UART about TUNING information. 

### Buttons informations:
	* Button 0: PEDESTRIAN button. Just in AUTO MODE, press this button to turn on PEDESTRIAN FSM.
	* Button 1: MANUAL button. Whenever in AUTO MODE or MANUAL MODE, press this button to switch to corresponding MANUAL MODE states.
	* Button 2: TUNING button, Whenever in AUTO MODE or MANUAL MODE, press this button to switch to RED state of TUNING FSM.
	* Button 3: used to set timer for LEDs in corresponding state in TUNING FSM. Press to increase and hold for 1 second to decrease the timer value. 

# END
