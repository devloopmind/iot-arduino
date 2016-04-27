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

  analogWrite(ledJaune, 255);
  analogWrite(ledRouge, 255);
  analogWrite(ledVert, 0);   // en fonction du nombre la LED est plus ou moins lumineuse 
  delay(1000);
  analogWrite(ledVert, 255);
  
  analogWrite(ledJaune, 0);
  delay(1000);
  analogWrite(ledJaune, 255);

  analogWrite(ledRouge, 0);
  delay(1000);
  analogWrite(ledRouge, 255);
}
