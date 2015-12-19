boolean incorrect = false;  //for detecting an error

int lightA = 12;  //output light pins
int lightB = 11;

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

void loop() {
  while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW)) //while loop continuosly delays until a button is pressed
  {
    delay(waitDelay);
  }
  if(digitalRead(buttonA) == HIGH)  //if buttonA is pressed
  {
    digitalWrite(lightA, HIGH); //blink lightA
    delay(flashDelay);
    digitalWrite(lightA, LOW);
    while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW)) //waits again until a button is pressed
    {
      delay(waitDelay);
    }
    if(digitalRead(buttonB) == HIGH)  //this time if buttonB is pressed. This if is within the other if, meaning they both have to occur in the right order
    {
      digitalWrite(lightB, HIGH); //flash lightB
      delay(flashDelay);
      digitalWrite(lightB, LOW);
      while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW)) //does the cycle again with different buttons/lights
      {
        delay(waitDelay);
      }
      if(digitalRead(buttonB) == HIGH)
      {
        digitalWrite(lightB, HIGH);
        delay(flashDelay);
        digitalWrite(lightB, LOW);
        while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW))
        {
          delay(waitDelay);
        }
        if(digitalRead(buttonB) == HIGH)
        {
          digitalWrite(lightB, HIGH);
          delay(flashDelay);
          digitalWrite(lightB, LOW);
          while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW))
          {
            delay(waitDelay);
          }
          if(digitalRead(buttonA) == HIGH)
          {
            digitalWrite(lightA, HIGH);
            delay(flashDelay);
            digitalWrite(lightA, LOW);
            delay(100);
            digitalWrite(lightA, HIGH); //once enough if's have been accepted, both lights will turn on
            digitalWrite(lightB, HIGH);
            for(int i = 1; i > 0; i++)  //infinate loop
            {
              delay(10);
            }
          }
          else  //all the of the elses are linked to previous if statements. if any ifs are not true, then they will end up in one of these
          {
            incorrect = true; //indicates that the user has made an error for later coding
          }
        }
        else
        {
          incorrect = true;
        }
      }
      else
      {
        incorrect = true;
      }
    }
    else
    {
      incorrect = true;
    }
  }
  else
  {
    incorrect = true;
  }
  if(incorrect == true) //if the user has made an error, or an if statement is not true
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
    incorrect = false;  //resets the incorrect if statements
  }
}
 


