int counter = 10;
void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
 if(digitalRead(3) == HIGH){
  digitalWrite(12, HIGH);
  delay(500);
  counter = counter + 1;
 }
 if(digitalRead(2) == HIGH){
  digitalWrite(11, HIGH);
  delay(500);
  counter = counter + 1;
 }
 if(counter == 15){
  for(int i = 1; i < 20; i++){
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    delay(40);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    delay(40);
  }
  counter = 10;
 }
 else{
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
 }

}



