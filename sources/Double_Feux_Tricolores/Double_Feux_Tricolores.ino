int ledVert = 9;
int ledJaune = 8;
int ledRouge = 7;
int ledRouge2 = 6;
int ledJaune2 = 5;
int ledVert2 = 4;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledRouge, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  pinMode(ledVert, OUTPUT);
  pinMode(ledRouge2, OUTPUT);
  pinMode(ledJaune2, OUTPUT);
  pinMode(ledVert2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(ledJaune, HIGH);
  digitalWrite(ledRouge, HIGH);
  digitalWrite(ledJaune2, HIGH);
  digitalWrite(ledVert2, HIGH);
  digitalWrite(ledRouge2, LOW);
  digitalWrite(ledVert, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(ledVert, HIGH);    // turn the LED off by making the voltage LOW
  //delay(1000);
  digitalWrite(ledJaune, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(ledJaune, HIGH);    // turn the LED off by making the voltage LOW
  //delay(1000);
  digitalWrite(ledRouge, LOW);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);              // wait for a second
  //digitalWrite(ledRouge, HIGH);    // turn the LED off by making the voltage LOW
  //delay(1000);              // wait for a second
  digitalWrite(ledRouge2, HIGH);
  digitalWrite(ledVert2, LOW);
  delay(1000);
  digitalWrite(ledVert2, HIGH);
  digitalWrite(ledJaune2, LOW);
  delay(1000);
}
