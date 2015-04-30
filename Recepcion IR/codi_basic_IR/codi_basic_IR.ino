#include <NECIRrcv.h>
#define IRPIN 4    // Pin en el que s'ha conectat el sensor IR

NECIRrcv ir(IRPIN) ; // creem i declarem l'objecte ir

const int nombreTecles = 10;
long irTeclesCodis[nombreTecles] = {
  0xE916FA05, //0 Tecla
  0xE31CFA05, //1 Tecla
  0xE21DFA05, //2 Tecla
  0xE817FA05, //3 Tecla
  0xE718FA05, //4 Tecla
  0xA05FB04F, //5 Tecla
  0xA05F708F, //6 Tecla
  0xA05FF00F, //7 Tecla
  0xA05F08F7, //8 Tecla
  0xA05F8877, //9 Tecla

};
void setup()
{
  Serial.begin(9600) ;
  Serial.println("recepciò del còdic NEC IR") ;
  ir.begin() ;
}

void loop()
{
  int key=-1;
  unsigned long ircode ;
  
  while (ir.available()) {
    ircode = ir.read() ;
    Serial.print("ha arribat el codi: 0x") ;
    Serial.println(ircode,HEX) ;
    
    key = convertCodeToKey(ircode);
    
    Serial.print("que correspon a la tecla: ") ;
    Serial.println(key) ;
  }
  
  

}

int convertCodeToKey(long codi)
{
  for( int i=0; i < nombreTecles; i++)
  {
    if( codi == irTeclesCodis[i])
    {
      return i; // found the key so return it
    }
  }
  return -1;
}
