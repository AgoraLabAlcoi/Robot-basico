/*AgoraLab Alcoi
Programaciò d'un sensor d'ultrasons HC-SR04 per a medir distancies en cm
baix Llicència Creative Commons Attribution-ShareAlike 3.0*/
 
int Pin_echo = 13; 
int Pin_trig = 12;

int duracion, cm;
 
void setup() { 
  Serial.begin (9600); 
  pinMode(Pin_trig, OUTPUT); 
  pinMode(Pin_echo, INPUT); 
} 
 
void loop() { 
  medir();
  Serial.print("Distancia:");
  Serial.print(cm); 
  Serial.println(" cm");

  delay(500); 
}

void medir(){
   
  digitalWrite(Pin_trig, LOW); 
  delayMicroseconds(2); 
  digitalWrite(Pin_trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(Pin_trig, LOW); 
  duracion = pulseIn(Pin_echo, HIGH); 
  cm = duracion / 29 / 2;
}
