

int Frequency = 80;
float Duty =  0.5;

long Ta = 1000000/Frequency * Duty;
long Tb = 1000000/Frequency * (1 - Duty);




void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}


void loop() {
  float value = analogRead(A1);
  float multiplier = 0.5+value/1024;
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(1, HIGH); 
  digitalWrite(4, HIGH);
  delayMicroseconds(Ta*multiplier);                    
  digitalWrite(1, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH); 
  digitalWrite(3, HIGH);  
  delayMicroseconds(Tb*multiplier);                 
}
