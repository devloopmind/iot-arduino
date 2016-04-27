void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) { // Vérifie qu'il y a qqch à lire
    char lu = Serial.read(); // lit un octet (char ou int pour code ascii)
    Serial.println(lu); // envoie un message dans le port série
  }
  else {
    Serial.println("Rien");
  }
  delay(2000);
}
