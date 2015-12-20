boolean incorrect = false;  //for detecting an error

int lightA = 12;  //output light pins
int lightB = 11;

int option[] = {3, 2, 2, 2, 3};

int buttonA = 3;  //input button pins
int buttonB = 2;

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
  for(int i = 0; i < 5; i++)
  {
    while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW)) //while loop continuosly delays until a button is pressed
    {
      delay(waitDelay);
    }
    if(digitalRead(option[i]) == HIGH)  //if buttonA is pressed
    {
      digitalWrite((option[i] + 9), HIGH); //blink lightA
      delay(flashDelay);
      digitalWrite((option[i] + 9), LOW);
    }
    else
    {
      for(int i = 1; i < 20; i++) //for loop, running 20 times
      {
        digitalWrite(lightA, HIGH);//blinks both lights quickly 20 times
        digitalWrite(lightB, HIGH);
        delay(40);
        digitalWrite(lightA, LOW);
        digitalWrite(lightB, LOW);
        delay(40);
      }
      resetFunc();
    }
  }  
  digitalWrite(lightA, HIGH); //once enough if's have been accepted, both lights will turn on
  digitalWrite(lightB, HIGH);
  for(int i = 1; i > 0; i++)  //infinate loop
  {
    delay(10);
  }
}
 


