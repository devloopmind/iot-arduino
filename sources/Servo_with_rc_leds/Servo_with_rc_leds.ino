 
#include <Servo.h> 

Servo myservo;//Objet servo pour controler un servo

int ch1;//Cannaux pour le volant
int ch2;//Canaux pour l'accéléromètre
int pos = 0;//Variable pour conserver la position du servo

int ledVert = 10;
int ledJaune = 9;
int ledRouge = 8;

int pinServo = 7;
int pinAcceleration = 5;
int pinVolant = 6;

int cpt; // compteur (nombre de loop qu'une led était allumée)
int ledAllumee;
const int MAX_LOOP_LED_ALLUMEE = 10;

void setup() 
{ 
  cpt = 0;
  ledAllumee = ledRouge;
  
  pinMode(pinVolant, INPUT);//On attache le volant au pin 5
  pinMode(pinAcceleration, INPUT);//On attache l'accéléromètre au pin 6
  myservo.attach(pinServo);//On attache le servo au pin 9 à l'objet servo

  // initialize digital pin 13 as an output.
  pinMode(ledRouge, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  pinMode(ledVert, OUTPUT);
  
  Serial.begin(9600);
} 
 
void loop() 
{
  digitalWrite(ledAllumee, LOW);
  
  ch1 = pulseIn(pinVolant, HIGH, 25000);//Lecture du ch1 volant (25 ms)
  // acceleration mis en comm car on reçoit tjrs 0
  ch2 = pulseIn(pinAcceleration, HIGH, 25000);//Lecture du ch2 accéléromètre
  /** DEBUG des lectures
  //Affichage de la position du volant
  Serial.print("Ch1 = "); // Afficher les lectures Arduino
  Serial.print(ch1);      

  //Affichage de la position de l'acco
  Serial.print("  Ch2 = ");
  Serial.println(ch2);
  */

  //if(ch1 > 1515 || ch1 < 1485)
  if( ledAllumee == ledVert) {
    myservo.write(ch1);
    Serial.println(ch1);
  } else {
    myservo.write(1500);
  }

  cpt++;
  if( cpt == MAX_LOOP_LED_ALLUMEE ) {
    cpt = 0;
    // change de led
    ledAllumee--;
    if(ledAllumee == ledRouge -1){
      ledAllumee = ledVert;
    }
    // éteint toutes les leds
    for(int i = 8; i<=10; i++) {
      digitalWrite(i, HIGH);
    }
  }
  
  delay(100);
}
