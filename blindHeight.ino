#define pwmPin  0
int analogInPin = A1;
float basePressure = 0.0;
float voltage = 0.0;
float pressure = 0.0;
void setup(){
pinMode(pwmPin, OUTPUT);
pinMode(analogInPin, INPUT);
 voltage = 3.3*float((analogRead(A1)/1023.0));
 pressure = 5*((voltage - 0.2)/3.3);
basePressure = pressure;
for (int i = 0; i < 4; i++){
digitalWrite(0,HIGH ); // Output analog reading to dimmable LED
delay(20);
digitalWrite(0,LOW);
delay(20);
}
}
void loop(){
 voltage = 3.3*float((analogRead(A1)/1023.0));
 pressure = 5*((voltage - 0.2)/3.3);
 float dong = 10 * (pressure - basePressure);
int counter = map((dong),1,10,1,6);
counter = constrain(counter,1,6);
if (pressure - basePressure > 0.15){
  if(counter < 6){
  int i = 0;
  while(i < counter){
digitalWrite(0,HIGH ); // Output analog reading to dimmable LED
delay(10);
digitalWrite(0,LOW);
delay(10);
i++;
  }
  delay(100);
  } else digitalWrite(0,HIGH);
}
}                                                
