/*
Control Slider sketch

*/

#include <IRremote.h> // IR remote control library


const int irReceivePin = 10; //pin conectat al sensor de IR
const int numberOfKeys = 20;
long irKeyCodes[numberOfKeys] = {
  0xA05F48B7, //0 key
  0xA05F906F, //1 key
  0xA05F50AF, //2 key
  0xA05FD02F, //3 key
  0xA05F30CF, //4 key
  0xA05FB04F, //5 key
  0xA05F708F, //6 key
  0xA05FF00F, //7 key
  0xA05F08F7, //8 key
  0xA05F8877, //9 key
  0xA05F38C7, //10 key flecha esquerra
  0xA05FB847, //11 key flecha dreta
  0xA05FE817, //12 key flecha dalt
  0xA05F18E7, //13 key flecha baix
  0xA05F6897, //14 key intro
  0xA05F20DF, //15 key +
  0xA05FA05F, //16 key -
  0xA05F40BF, //17 key dalt
  0xA05FC03F, //18 key baix
  0xA05F10EF,//source key
};
IRrecv irrecv(irReceivePin); // create the IR library
decode_results results; // IR data goes here



void setup() {
  Serial.begin(9600);

  pinMode(irReceivePin, INPUT);
  irrecv.enableIRIn(); // Start the IR receiver  
}

void loop(){
  
  int key=-1;
  
  if (irrecv.decode(&results))
  {
    // here if data is received
    irrecv.resume();
    key = convertCodeToKey(results.value);
  }
  switch(key){
    case 11:
       Serial.print("La tecla pulsada es: ");
       Serial.println(key);
    break;
    case 10:
       Serial.print("La tecla pulsada es: ");
       Serial.println(key);
    break;
    case 13:
       Serial.print("La tecla pulsada es: ");
       Serial.println(key);
    break;
    case 16:
       Serial.print("La tecla pulsada es: ");
       Serial.println(key);
    break;
    case 15:
       Serial.print("La tecla pulsada es: ");
       Serial.println(key);
    break;
    
  }
  
}//FINAL DEL LOOP

/* converts a remote protocol code to a logical key code (or -1 if no digit
received)
*/
int convertCodeToKey(long code)
{
  for( int i=0; i < numberOfKeys; i++)
  {
    if( code == irKeyCodes[i])
    {
      return i; // found the key so return it
    }
  }
  return -1;
}

