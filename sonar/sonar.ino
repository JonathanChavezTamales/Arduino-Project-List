#include <NewPing.h>
#define TRIGGER 3
#define ECHO 2
#define MAXDISTANCE 200
#define LED1 8
#define LED2 9
#define LED3 10
#define BUTTON 5

NewPing sonar(TRIGGER, ECHO, MAXDISTANCE);

void setup() {
  Serial.begin(9600);
    pinMode(LED1 , OUTPUT); 
    pinMode(LED2 , OUTPUT); 
    pinMode(LED3 , OUTPUT); 
    pinMode(BUTTON, INPUT);

}

void loop() {
  delay(100);

  if(digitalRead(BUTTON) == 1){
    
    
    
    unsigned int distance = sonar.ping_cm();
  
    if(distance > 30){
      digitalWrite(LED3, HIGH);
      digitalWrite(LED2 , LOW);
      digitalWrite(LED1 , LOW);
    
      
    }
    
    else if(distance < 10){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2 , LOW);
      digitalWrite(LED3 , LOW);
    
      
      
    }
    
    else if(distance >= 20){
      digitalWrite(LED2, HIGH);
      digitalWrite(LED1 , LOW);
    digitalWrite(LED3 , LOW);
    
    }

  }
}
