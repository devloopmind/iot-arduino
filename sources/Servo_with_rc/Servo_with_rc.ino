 
#include <Servo.h> 

Servo myservo;//Objet servo pour controler un servo

int ch1;//Cannaux pour le volant
int ch2;//Canaux pour l'accéléromètre
int pos = 0;//Variable pour conserver la position du servo

void setup() 
{ 
  pinMode(5, INPUT);//On attache le volant au pin 5
  pinMode(6, INPUT);//On attache l'accéléromètre au pin 6
  myservo.attach(9);//On attache le servo au pin 9 à l'objet servo
  Serial.begin(9600);
} 
 
void loop() 
{ 
  ch1 = pulseIn(5, HIGH, 25000);//Lecture du ch1 volant (25 ms)
  ch2 = pulseIn(6, HIGH, 25000);//Lecture du ch2 accéléromètre
  
  //Affichage de la position du volant
  Serial.print("Ch1 = "); // Afficher les lectures Arduino
  Serial.print(ch1);      

  //Affichage de la position de l'acco
  Serial.print("  Ch2 = ");
  Serial.println(ch2);

  //if(ch1 > 1515 || ch1 < 1485)
  myservo.write(ch1);
  
  delay(100);
}
