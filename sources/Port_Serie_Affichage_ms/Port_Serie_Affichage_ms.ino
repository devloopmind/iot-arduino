unsigned long time_deb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  time_deb = millis(); // On stocke le début du lancement du prgramme
  while(!Serial) {
    
  }
  Serial.println(" OK init finish");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) { // Si on a reçu le message nous signalant d'envoyer le nombre
    while(Serial.available()) {
      // boucle qui me permet d'attendre qu'il n'y a plus de caractères à lire
      Serial.read();
    }
    unsigned long time = millis();
    Serial.print(" $$> ");
    Serial.println(time - time_deb);
  }
  
  delay(500);
}
