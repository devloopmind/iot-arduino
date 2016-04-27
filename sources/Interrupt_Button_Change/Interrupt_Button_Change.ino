int ledPin = 7;
volatile int state = LOW; // déclaration d'une variable volatile
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(0, maFonctionBlink, CHANGE); // attache l'interruption externe n°0 (pin 2) à ma fonction
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, state);
  Serial.println(state);
  delay(1000);
}

void maFonctionBlink() {
  state = !state;
}

