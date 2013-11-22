/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(0, OUTPUT);  
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);    
  pinMode(8, OUTPUT);  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);  
  pinMode(14, OUTPUT);  
  pinMode(15, OUTPUT);  
  pinMode(16, OUTPUT);
  pinMode(18, OUTPUT);  
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {

  digitalWrite(18, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(18, LOW); 
  delay(200);               // wait for a second

  digitalWrite(19, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(19, LOW); 
  delay(200);               // wait for a second

  digitalWrite(8, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(8, LOW); 
  delay(200);               // wait for a second

  digitalWrite(10, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(10, LOW); 
  delay(200);               // wait for a second
  
  digitalWrite(14, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(14, LOW); 
  delay(200);               // wait for a second

  digitalWrite(20, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(20, LOW); 
  delay(200);               // wait for a second
  
  digitalWrite(9, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(9, LOW); 
  delay(200);               // wait for a second
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(200);               // wait for a second
  
  digitalWrite(0, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(0, LOW); 
  delay(200);               // wait for a second
  
  digitalWrite(1, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(1, LOW); 
  delay(200);               // wait for a second

  digitalWrite(2, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(2, LOW); 
  delay(200);               // wait for a second
  
  digitalWrite(3, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(3, LOW); 
  delay(200);               // wait for a second

  digitalWrite(6, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(6, LOW); 
  delay(200);               // wait for a second

  digitalWrite(5, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(5, LOW); 
  delay(200);               // wait for a second

  digitalWrite(15, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(15, LOW); 
  delay(200);               // wait for a second

  digitalWrite(16, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(16, LOW); 
  delay(200);               // wait for a second

  digitalWrite(7, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(7, LOW); 
  delay(200);               // wait for a second

  digitalWrite(4, HIGH);   
  delay(200);               // wait for a second
  digitalWrite(4, LOW); 
  delay(200);               // wait for a second
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(200);               // wait for a second
}
