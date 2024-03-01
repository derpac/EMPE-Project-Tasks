
// Initialise frequency and duty cycle
int Frequency = 80;     
float Duty =  0.5;

// Calculate Timing in microseconds
long Ta = 1000000/Frequency * Duty;
long Tb = 1000000/Frequency * (1 - Duty);   

void setup() {
  // initialize output pins
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // Outputs for Ta
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(1, HIGH); 
  digitalWrite(4, HIGH);
  delayMicroseconds(Ta);  
  // Outputs for Tb                  
  digitalWrite(1, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH); 
  digitalWrite(3, HIGH);  
  delayMicroseconds(Tb);                 
}
