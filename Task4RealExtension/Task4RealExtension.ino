int Modulationfrequency = 10;
#define Frequencyratio 100
int Carrierfrequency = Modulationfrequency * Frequencyratio;
int Ta[Frequencyratio];
int Tb[Frequencyratio];
float Vout[Frequencyratio];
float Vhigh = 4.0;
float Vlow = -4.0;



void setup() {
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  float Aplitude = (Vhigh-Vlow)/2;
  float Vmid = (Vhigh+Vlow)/2;
  for(int i = 0; i<Frequencyratio; i++)
  {
      Vout[i]= Vmid+sin(2*PI*i/Frequencyratio)*Aplitude;
  }
  for(int i = 0; i<Frequencyratio; i++)
  {
    float Duty = ((Vout[i]/5)+1)/2;
    Ta[i] = 1000000/Carrierfrequency * Duty;
    Tb[i] = 1000000/Carrierfrequency * (1 - Duty); 
  }
}


void loop() {
  for(int i = 0;i<Frequencyratio;i++)
  {
    float value = analogRead(A1);
    float multiplier = 0.5+value/1024;
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(1, HIGH); 
    digitalWrite(4, HIGH);
    delayMicroseconds(Ta[i]*multiplier);                    
    digitalWrite(1, LOW);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH);  
    delayMicroseconds(Tb[i]*multiplier);
  }
}

  
