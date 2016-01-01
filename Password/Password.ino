boolean incorrect = false;

int lightA = 12;  //output light pins
int lightB = 11;

int option[] = {3,2,2,2,2,3,3,2}; 
int numoptions = 8;

int buttonA = 3;  //input button pins
int buttonB = 2;
int buttonC = 4;

int flashDelay = 500; //delays in the code
int waitDelay = 10;

void setup() {
  pinMode(lightA, OUTPUT);  //assign pins
  pinMode(lightB, OUTPUT);
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
}

void(*resetFunc)(void) = 0;

void loop() 
{
  for(int i = 0; i < numoptions; i++)
  {
    while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW) && (digitalRead(buttonC) == LOW)) //while loop continuosly delays until a button is pressed
    {
      delay(waitDelay);
    }
    if(digitalRead(option[i]) == HIGH)  //if buttonA is pressed
    {
     delay(500); 
    }
    else
    {
      incorrect = true; 
    }
    if(digitalRead(buttonC) == HIGH)
    {
    digitalWrite(lightB, HIGH); 
    delay(flashDelay);
    digitalWrite(lightB, LOW);
    resetFunc();
    }
  }
  while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW) && (digitalRead(buttonC) == LOW)) //while loop continuosly delays until a button is pressed
  {
    delay(waitDelay);
  }
  if((digitalRead(buttonC) == HIGH) && (incorrect == false))
  {
    digitalWrite(lightA, HIGH);
    for(int i = 1; i > 0; i++)  //infinate loop
    {
      delay(10);
    }
  }
  delay(500);
  while(digitalRead(buttonC) == LOW) 
   {
      delay(waitDelay);
   }
  if(digitalRead(buttonC) == HIGH)
  {
    digitalWrite(lightB, HIGH); 
    delay(flashDelay);
    digitalWrite(lightB, LOW);
    resetFunc();
  }
}
 


