#define BTN0 12 
#define LED0 11 

#define BTN1 10 
#define LED1 9 

#define BTN2 8 
#define LED2 7 

#define BTN3 6 
#define LED3 5

#define BTN4 4 
#define LED4 3  

boolean wasPressed= false, showingLights=true;
int i = 0, k = 0, temp = 5;

int secuencia[6] = {0,1,2,3,4,0};
int leds[5] = {LED0, LED1, LED2, LED3, LED4};
int inputUsuario[sizeof(secuencia)/sizeof(secuencia[1])] = {5};

boolean equal(int n, int arr1[], int arr[]){
  for(int i=0; i<n; i++){
    if(arr1[i] != arr[i])
     return false; 
  }
  return true;
}


void setup()
{
  for(int i = 0; i < (sizeof(leds)/sizeof(leds[0])); i++){
   pinMode(leds[i], OUTPUT); 
  }
  for(int i = 4; i<=12; i+=2){
   pinMode(i, INPUT); 
  }
  Serial.begin(9600);
  randomSeed(analogRead(0));
}



void loop()
{
  
 if(digitalRead(BTN0) == HIGH){
      wasPressed = true;
      temp = 0;
      delay(100);
  }
  else if(digitalRead(BTN1) == HIGH){
      wasPressed = true;
      temp = 1;
      delay(100);
  }
  else if(digitalRead(BTN2) == HIGH){
      wasPressed = true;
      temp = 2;
      delay(100);
  }
  else if(digitalRead(BTN3) == HIGH){
      wasPressed = true;
      temp = 3;
      delay(100);
  }
  else if(digitalRead(BTN4) == HIGH){
      wasPressed = true;
      temp = 4;
      delay(100);
  }

  else{

    //Si ninguno se presiona, entra aquí y no hace nada, a menos que se haya presionado alguno anteriormente.
    
    if(wasPressed){
      //Si se presionó alguno, entra aquí

      //WIN CONDITION
      if(i == sizeof(secuencia)/sizeof(secuencia[0])-1){
        
        for(int i = 0; i < sizeof(leds)/sizeof(leds[0]); i++){
          digitalWrite(leds[i], HIGH);
          delay(50);
        }
        
        for(int i = 0; i < sizeof(leds)/sizeof(leds[0]); i++){
          digitalWrite(leds[i], LOW);
          delay(20);
        } 
        
        Serial.println("HA GANADO!");
        //Genera nuevos random y limpia variables
        for(int j = 0; j < sizeof(secuencia)/sizeof(secuencia[0]); j++){
          secuencia[i] = random(0, 4);
          Serial.print(secuencia[i]);
        }
        i = 0;
        k = 0;
        delay(1000);
        
        
      }
  
      else if(temp == secuencia[i]){

        Serial.print("REALLY?");
        for(int i=0; i< 6; i++){
          Serial.print(secuencia[i]);
        }
        Serial.println();
        
        inputUsuario[i] = temp;
        i++;
        
        if(equal(k, inputUsuario, secuencia) && k+1 == i){
          i = 0;
          k++;
          
        }
        //BUZZ
        delay(500);
      }

      
      else{
        Serial.println("HA PERDIDO!");
        //Genera nuevos random y limpia variables
        for(int j = 0; j < sizeof(secuencia)/sizeof(secuencia[0]); j++){
          secuencia[i] = random(0, 4);
          Serial.print(secuencia[i]);
        }
        i = 0;
        k = 0;
        
        delay(1000);
      }
      
      showingLights = i == 0? true : false;
      //Después de hacer la acción se vuelve falso, y ya no entrará aquí infinitamente.
      wasPressed = false;
      
    }


    if(showingLights == true){
          //PRENDIDO DE LUCES
          for(int j = 0; j < k+1; j++){
            digitalWrite(leds[secuencia[j]], HIGH);
            delay(300);
            digitalWrite(leds[secuencia[j]], LOW);
            delay(200);
          }
          showingLights = false;
   }

    
  }

  
}
