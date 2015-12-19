boolean incorrect = false;

int lightA = 12;
int lightB = 11;

int buttonA = 3;
int buttonB = 2;

void setup() {
  pinMode(lightA, OUTPUT);
  pinMode(lightB, OUTPUT);
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
}

void loop() {
  while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW))
  {
    delay(10);
  }
  if(digitalRead(buttonA) == HIGH)
  {
    digitalWrite(lightA, HIGH);
    delay(500);
    digitalWrite(lightA, LOW);
    while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW))
    {
      delay(10);
    }
    if(digitalRead(buttonB) == HIGH)
    {
      digitalWrite(lightB, HIGH);
      delay(500);
      digitalWrite(lightB, LOW);
      while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW))
      {
        delay(10);
      }
      if(digitalRead(buttonB) == HIGH)
      {
        digitalWrite(lightB, HIGH);
        delay(500);
        digitalWrite(lightB, LOW);
        while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW))
        {
          delay(10);
        }
        if(digitalRead(buttonB) == HIGH)
        {
          digitalWrite(lightB, HIGH);
          delay(500);
          digitalWrite(lightB, LOW);
          while((digitalRead(buttonA) == LOW) && (digitalRead(buttonB) == LOW))
          {
            delay(10);
          }
          if(digitalRead(buttonA) == HIGH)
          {
            digitalWrite(lightA, HIGH);
            delay(500);
            digitalWrite(lightA, LOW);
            delay(100);
            digitalWrite(lightA, HIGH);
            digitalWrite(lightB, HIGH);
            for(int i = 1; i > 0; i++)
            {
              delay(10);
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
  }
  else
  {
    incorrect = true;
  }
  if(incorrect == true)
  {
    for(int i = 1; i < 20; i++)
    {
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      delay(40);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      delay(40);
      incorrect = false;
    }
  }
}
 


