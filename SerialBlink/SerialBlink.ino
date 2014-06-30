/*
This Program will recieve data from the computer over serial 
and process it as different commands depending on the leading byte
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int state;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(9600); 
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0) {
    if (Serial.peek() == 'c') { //check for the character that signifies that this will be a command
      Serial.read(); //remove the character that signifies this is a command from the serial buffer
      state = Serial.parseInt(); //store our expected integer into state
      digitalWrite(led,state); // set the state of the LED
    }
    while (Serial.available() > 0){ //Discard everything that we didn't expect
      Serial.read();
    }
  }
}
