int Modulationfrequency = 10; // Set modulation frequency
#define Frequencyratio 100 // Set ratio between modulation and carrier frequency 
int Carrierfrequency = Modulationfrequency * Frequencyratio; // calculate carrier frequency
// Timings and voltages for 1 modulation cycle
int Ta[Frequencyratio];
int Tb[Frequencyratio];
float Vout[Frequencyratio];
float Vhigh = 4.0;
float Vlow = -4.0;



void setup() {
  // Initialise output pins
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  // Calculate aplitude and mid voltage
  float Aplitude = (Vhigh-Vlow)/2;
  float Vmid = (Vhigh+Vlow)/2;
  // Calculate voltages for sine wave
  for(int i = 0; i<Frequencyratio; i++)
  {
      Vout[i]= Vmid+sin(2*PI*i/Frequencyratio)*Aplitude;
  }
  // Calculating Duty cycle from voltage and timings in microseconds
  for(int i = 0; i<Frequencyratio; i++)
  {
    float Duty = ((Vout[i]/5)+1)/2;
    Ta[i] = 1000000/Carrierfrequency * Duty;
    Tb[i] = 1000000/Carrierfrequency * (1 - Duty); 
  }
}


void loop() {
  // Generate output from timings
  for(int i = 0;i<Frequencyratio;i++)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(1, HIGH); 
    digitalWrite(4, HIGH);
    delayMicroseconds(Ta[i]);                    
    digitalWrite(1, LOW);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH);  
    delayMicroseconds(Tb[i]);
  }
}

  
