
int Modulationfrequency = 30;
#define Frequencyratio 100
int Carrierfrequency = Modulationfrequency * Frequencyratio;
int Ta[Frequencyratio];
int Tb[Frequencyratio];
float Vout[Frequencyratio];
float Vhigh = 1.5;
float Vlow = -1.5;



void setup() {
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  for(int i = 0; i<Frequencyratio/2; i++)
  {
      Vout[i]= Vout[Frequencyratio-i]= Vlow+i*(Vhigh-Vlow)/(Frequencyratio/2);
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
  
