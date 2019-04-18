from time import sleep

import serial
import keyboard
import os

ser = serial.Serial('/dev/ttyACM0', 9600) # Establish the connection on a specific port
os.system("stty -echo")

previous_status = "0"
previous_message = ""

def write_serial(status, printed):
    global previous_status
    if status != previous_status:
        os.system('clear')	
        print(printed)
        ser.write(str(status))
        previous_status = status
        
def sys_message(message):
    global previous_message
    if message != previous_message:
        os.system('clear')
        print(message)
        previous_message = message        

while True:
    if keyboard.is_pressed('q'): 	
        write_serial(2, "KEYBOARD KEY [Q] PRESSED!")
    elif keyboard.is_pressed('w'): 	
        write_serial(3, "KEYBOARD KEY [W] PRESSED!")
    elif keyboard.is_pressed('e'): 	
        write_serial(4, "KEYBOARD KEY [E] PRESSED!")   
    elif keyboard.is_pressed('r'): 	
        write_serial(5, "KEYBOARD KEY [R] PRESSED!") 
    elif keyboard.is_pressed('a'): 	
        write_serial(6, "KEYBOARD KEY [A] PRESSED!") 
    elif keyboard.is_pressed('s'): 	
        write_serial(7, "KEYBOARD KEY [S] PRESSED!")
    elif keyboard.is_pressed('d'): 	
        write_serial(8, "KEYBOARD KEY [D] PRESSED!")
    elif keyboard.is_pressed('f'): 	
        write_serial(9, "KEYBOARD KEY [F] PRESSED!")
    elif keyboard.is_pressed('z'): 	
        write_serial(11, "KEYBOARD KEY [Z] PRESSED!")
    elif keyboard.is_pressed('x'): 	
        write_serial(12, "KEYBOARD KEY [X] PRESSED!")         
    elif keyboard.is_pressed('o'): 	
        write_serial(10, "POSITIONS RESET!")                                               
    elif keyboard.is_pressed('p'):
        write_serial(1, "DONE.")	
        sleep(1)
        os.system('stty echo')                
        os.system('clear')
        exit()
    else:		
        sys_message("WAITING FOR USER INPUT! (TRY Q,W,E,R,T,A,S,D,F)")   
