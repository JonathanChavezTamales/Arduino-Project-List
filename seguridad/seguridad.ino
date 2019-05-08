#define SEC0 12
#define SEC1 11
#define SEC2 10
#define RESET_BTN 9
#define RESET_JUMP 8
#define INT1 7
#define INT2 6
#define INT3 5
#define BLOCKED 4
#define OPEN 3
#define CLOSED 2

int password[] = {0, 1, 2, 0};

void setup()
{
  for(int i = 2; i<=8; i++){
   pinMode(i, OUTPUT); 
  }
  for(int i = 8; i<=12; i++){
   pinMode(i, INPUT); 
  }
  Serial.begin(9600);
  digitalWrite(CLOSED, HIGH);
  digitalWrite(RESET_JUMP, HIGH);
  
}

boolean equal(int arr1[], int arr[]){
  for(int i=0; i<4; i++){
    if(arr1[i] != arr[i])
     return false; 
  }
  return true;
}



int i = 0;
boolean wasPressed= false, led1 = false, led2 = false;
int sequence[4] = {4};
int temp;

void loop()
{

  
 if(digitalRead(SEC0) == HIGH){
      temp = 0;
      wasPressed = true;
  }
  else if(digitalRead(SEC1) == HIGH){
      temp=1;
      wasPressed = true;
  }
  else if(digitalRead(SEC2) == HIGH){
      temp = 2;
      wasPressed = true;
  }
  else if(digitalRead(RESET_BTN) == HIGH){
      sequence[4] = {4};
      i=0;
      led1 = false;
      led2 = false;
      digitalWrite(INT1, LOW);
      digitalWrite(INT2, LOW);
      digitalWrite(INT3, LOW);
      digitalWrite(BLOCKED, LOW);
      digitalWrite(OPEN, LOW);
      digitalWrite(CLOSED, HIGH);
  }

  else{
    if(wasPressed == true){
      sequence[i] = temp;
      
      i++;

      Serial.print(temp);
      
   
      if(i == 4 && !led1){
          Serial.println("primer intento");
          if(equal(sequence, password)){
          Serial.println("CORRECTO");
          digitalWrite(OPEN, HIGH);
          digitalWrite(CLOSED, LOW);
          return 0;
          }else{
          Serial.println("NELPROO");
          digitalWrite(INT1, HIGH);
          i=0;
          led1 = true;
          }
      }
      if(i == 4 && led1 && !led2){
        Serial.println("segundo intento");
        if(equal(sequence, password)){
          Serial.println("CORRECTO");
          digitalWrite(OPEN, HIGH);
          digitalWrite(CLOSED, LOW);
          return 0;
        }else{
        Serial.println("NELPROO");
        digitalWrite(INT2, HIGH);
        i = 0;
        led2 = true;
        }
      }
      if(i == 4 && led2){
        Serial.println("BLOCK");
        if(equal(sequence, password)){
          Serial.println("CORRECTO");
          digitalWrite(OPEN, HIGH);
          digitalWrite(CLOSED, LOW);
          return 0;
        }else{
        digitalWrite(INT3, HIGH);
        delay(1000);
        digitalWrite(INT1, LOW);
        delay(300);
        digitalWrite(INT2, LOW);
        delay(300);
        digitalWrite(INT3, LOW);
        delay(300);
        digitalWrite(BLOCKED, HIGH);
        }
      }
      wasPressed = false;
    }
  }

  
}
