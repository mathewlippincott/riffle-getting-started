
// on the Riffle, pin 9 is connected to an on-board LED.

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(9, OUTPUT); 
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
