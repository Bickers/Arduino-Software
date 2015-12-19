boolean test = false;
int counter = 10;
int a = 5;
void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
     while((digitalRead(3) == LOW) && digitalRead(2) == LOW)
    {delay(10);}
  if(digitalRead(3) == HIGH){
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    while((digitalRead(3) == LOW) && digitalRead(2) == LOW)
    {delay(10);}
  if(digitalRead(2) == HIGH){
     digitalWrite(11, HIGH);
     delay(500);
     digitalWrite(11, LOW);
     while((digitalRead(3) == LOW) && digitalRead(2) == LOW)
    {delay(10);}
     if(digitalRead(2) == HIGH){
        digitalWrite(11, HIGH);
        delay(500);
        digitalWrite(11, LOW);
        while((digitalRead(3) == LOW) && digitalRead(2) == LOW)
         {delay(10);}
        if(digitalRead(2) == HIGH){
            digitalWrite(11, HIGH);
            delay(500);
            digitalWrite(11, LOW);
            while((digitalRead(3) == LOW) && digitalRead(2) == LOW)
             {delay(10);}
            if(digitalRead(3) == HIGH){
               digitalWrite(12, HIGH);
              delay(500);
              digitalWrite(12, LOW);
              digitalWrite(12, HIGH);
              digitalWrite(11, HIGH);
              for(int i = 1; i > 0; i++){
                delay(10);}
            }
          else{
        test = true;
      }
          
          }
          else{
        test = true;
      }
        }
        else{
        test = true;
      }
      }
      else{
        test = true;
      }
    }
    else{
        test = true;
      }
    if(test == true){
    for(int i = 1; i < 20; i++){
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    delay(40);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    delay(40);
    test = false;
    }
  }
}
 


