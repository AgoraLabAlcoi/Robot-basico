
  
  #include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);	// Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
    vw_set_rx_pin(2);
    vw_rx_start();       // Start the receiver PLL running

pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
}

void loop()
{
  
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
	int i;

        digitalWrite(13, true); // Flash a light to show received good message
	// Message with a good checksum received, dump it.
	Serial.print("Got: ");
	
	for (i = 0; i < buflen; i++)
	{
	    Serial.print(buf[i]);
        if(buf[i] == '1'){digitalWrite(8, HIGH);}
        if(buf[i] == '2'){digitalWrite(9, HIGH);}
        if(buf[i] == '3'){digitalWrite(10, HIGH);}
        if(buf[i] == '4'){digitalWrite(11, HIGH);}
	    Serial.print(" ");
	}
	Serial.println("");
        digitalWrite(13, false);

   }
}
