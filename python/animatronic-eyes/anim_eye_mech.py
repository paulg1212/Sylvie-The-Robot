from time import sleep

import serial
import keyboard
import os

ser = serial.Serial('/dev/ttyACM0', 9600) # Establish the connection on a specific port
os.system("stty -echo")

previous_status = 0

def write_serial(status, printed):
    global previous_status
    if status != previous_status:
        os.system('clear')	
        print(printed)
        ser.write(str(status))
        previous_status = status    

while True:
    if keyboard.is_pressed('q'): 	
        write_serial(2, "KEYBOARD KEY [Q] PRESSED!")
    elif keyboard.is_pressed('w'): 	
        write_serial(3, "KEYBOARD KEY [W] PRESSED!")
    elif keyboard.is_pressed('e'): 	
        write_serial(4, "KEYBOARD KEY [E] PRESSED!")   
    elif keyboard.is_pressed('r'): 	
        write_serial(5, "KEYBOARD KEY [R] PRESSED!")                       
    elif keyboard.is_pressed('p'):
        write_serial(1, "DONE.")	
        os.system('stty echo')                
        os.system('clear')
        exit()
    else:		
        write_serial(0, "WAITING FOR USER INPUT (PRESS Q, W, E or R)!")
