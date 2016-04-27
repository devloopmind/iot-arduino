int ledVert = 9;
int ledJaune = 8;
int ledRouge = 7;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledRouge, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  pinMode(ledVert, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(ledJaune, HIGH);
  digitalWrite(ledRouge, HIGH);
  digitalWrite(ledVert, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(ledVert, HIGH);    // turn the LED off by making the voltage LOW
  //delay(1000);
  digitalWrite(ledJaune, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(ledJaune, HIGH);    // turn the LED off by making the voltage LOW
  //delay(1000);
  digitalWrite(ledRouge, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(ledRouge, HIGH);    // turn the LED off by making the voltage LOW
  //delay(1000);              // wait for a second

}
