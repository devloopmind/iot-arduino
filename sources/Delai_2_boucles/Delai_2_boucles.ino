
unsigned long tempsDepart; //variable pour noter le temps final
  void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long  tempsFin=micros(); //variable du temps de départ initialisée au temps actuel
  //bloc à tester
  Serial.println(tempsFin-tempsDepart); // on affiche la différence en microsecondes
  tempsDepart=micros(); //on récupère à nouveau le temps actuel
}
