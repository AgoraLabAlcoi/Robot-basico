int const boto = 12;

int estatBoto = 0;
int estatBotoAnterior = 0;

boolean robotEnable = false;

void setup() {
  
  pinMode(13, OUTPUT);
  pinMode(boto, INPUT);

}

void loop() {
  estatBoto = digitalRead(boto);
  delay(1);
  
  if(estatBoto != estatBotoAnterior){
      if(estatBoto == HIGH){
          robotEnable = !robotEnable;  
          
      }
  }
  
  if (robotEnable == true){
    digitalWrite(13, HIGH);
    }else{
      digitalWrite(13, LOW);
    }
  estatBotoAnterior = estatBoto;
}
