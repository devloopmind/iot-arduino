import processing.serial.*;
import cc.arduino.*;
Arduino arduino;
int ledPin = 13;

int circleX, circleY;  // Position of circle button
int circleSize = 93;   // Diameter of circle
color circleColor, baseColor;
color circleHighlight;
color currentColor;
boolean circleOver = false;

void setup() {
  size(640, 360);
  circleColor = color(255);
  circleHighlight = color(204);
  baseColor = color(102);
  currentColor = baseColor;
  circleX = width/2+circleSize/2+10;
  circleY = height/2;
  ellipseMode(CENTER);
  
  arduino = new Arduino(this, Arduino.list()[1], 57600); // j'ai trouvé le 2 grâce à la section Instructions ici : http://playground.arduino.cc/interfacing/processing
  arduino.pinMode(ledPin, Arduino.OUTPUT);
  arduino.digitalWrite(ledPin, Arduino.HIGH);
}

void draw() {
  update(mouseX, mouseY);
  circleOver = true;
  background(currentColor);
  
  stroke(255);
  
  if (circleOver) {
    fill(circleHighlight);
  } else {
    fill(circleColor);
  }
  stroke(0);
  ellipse(circleX, circleY, circleSize, circleSize);
}

void update(int x, int y) {
  if ( overCircle(circleX, circleY, circleSize) ) {
    circleOver = true;
  } else {
    circleOver = false;
  }
}

void mousePressed() {
  println("mousePressed");
  if (circleOver) {
    arduino.digitalWrite(ledPin, Arduino.LOW);
    delay(1000);
    arduino.digitalWrite(ledPin, Arduino.HIGH);
    delay(1000);
    
    println("apres clignotement");
  }
}

boolean overCircle(int x, int y, int diameter) {
  float disX = x - mouseX;
  float disY = y - mouseY;
  if (sqrt(sq(disX) + sq(disY)) < diameter/2 ) {
    return true;
  } else {
    return false;
  }
}