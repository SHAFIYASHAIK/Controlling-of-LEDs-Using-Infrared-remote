#include <LiquidCrystal.h> //including the library of Liquid crystal display(LCD)
#include <IRremote.h> //including the library of Infrared remote

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;// the pins where you connect 
								//register select, enable, DB4, DB5, DB6, DB7 pins of LCD.
LiquidCrystal lcd(rs,en,d4,d5,d6,d7); //Initializing library code of LCD 
				//to the pins of Lcd those which are conected  to Arduino.

const int receiver = 7; // the pin where you connect the output pin of IR sensor.
IRrecv receive(receiver); // Initializing library code of IR remote 
			//to Output pin of IR sensor that which connected to Arduino.
decode_results  out; // Decoding buttons of IR remote and storing them in "out" variable.


void setup()     
{     
  	pinMode(10,OUTPUT); //Defining pins as OUTPUT.
  	pinMode(9,OUTPUT);
  	pinMode(8,OUTPUT);
	receive.enableIRIn(); // Enable the receiver.
  	lcd.begin(16,2); // Enable the LCD.
  	lcd.print("Press key 0/1/2:"); // Prints Text on LCD.
}

void loop()     
{  
	if (receive.decode(&out))// Returns 0 if no data ready, 1 if data ready. 
    {	
      switch(out.value)// Here the expression is evaluated
          	//and compares with the each value of case label.
        {	case 16593103:
          		lcd.setCursor(2, 1); // sets the cursor of LCD by providing Coordinates.
          		lcd.print("Red Glows");
          		digitalWrite(9,0);
          		digitalWrite(8,0);
          		digitalWrite(10,1);
       		 	break;
        	case 16582903:
          		lcd.setCursor(2, 1);
          		lcd.print("Blue Glows");
        		digitalWrite(10,0);
        		digitalWrite(8,0);
        		digitalWrite(9,1);
        		break;
        	case 16615543:
          		lcd.setCursor(2, 1);
          		lcd.print("Green Glows");
        		digitalWrite(10,0);
        		digitalWrite(9,0);
        		digitalWrite(8,1);
          		break;
        	default: // If expression not evaluated then execute this by default
       			lcd.setCursor(2,1);
          		lcd.print("Give correctly");
       	}
      receive.resume(); // restart the IR remote
    }
}
