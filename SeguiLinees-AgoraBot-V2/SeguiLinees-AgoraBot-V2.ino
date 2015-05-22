 #include <Servo.h>
 Servo myservoIzq;
 Servo myservoDer;
 
  
 void setup() {  
   Serial.begin (9600);  
   
   myservoIzq.attach(9);
   myservoDer.attach(10); 
   
   
 }  
   
 void loop() {  
   
    //int valorIzq =  map(analogRead(A1), 40, 900, 135, 75);
    //int valorDer =  map(analogRead(A0), 40, 800, 0, 60);
    
    int valorIzq =  analogRead(A1);
    int valorDer =  analogRead(A0);
    delay(500);
     
    myservoIzq.write(valorIzq);
    myservoDer.write(valorDer);
    
    
     Serial.print("Sensor llum Izq: "); 
     Serial.print(valorIzq);
     Serial.print(" Sensor llum Der: ");  
     Serial.println(valorDer); 
     
     
     
  
     
   
 } 

 void avant(){
    myservoIzq.write(255);
    myservoDer.write(0);
   }
   
 void girarDer(){
    myservoIzq.write(255);
    myservoDer.write(55);
   }
   
  void girarIzq(){
    myservoIzq.write(75);
    myservoDer.write(0);
   }
 
 void parar(){
    myservoIzq.write(67);
    myservoDer.write(68);
   }
