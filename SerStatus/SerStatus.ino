static int ledStatus;

void setup(){
  //serial monitor need to set at 1200 baud
  Serial.begin(9600);
  Serial.println("ledStatus");
  pinMode(16, INPUT);
  pinMode(11, OUTPUT);
  
  ledStatus = LOW;
  digitalWrite(11, ledStatus);
}

void loop(){
  int switchStatus = digitalRead(16);
  if(switchStatus == HIGH){
    ledStatus = ledStatus == HIGH ? LOW : HIGH;
    digitalWrite(11, ledStatus);
  }
  Serial.println("ledStatus");
  Serial.println();
}
