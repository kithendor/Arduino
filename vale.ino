
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192,168,1,110 };//ip arduino
byte serverip[] = { 192,168,1,155 };//ip server
EthernetClient client;

float sen = 7;//dokimastiki timi

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
}

void loop()
{
  char entoli = Serial.read();  
  if(entoli == 'a')
  {
     if (client.connect(serverip, 80)) {
    Serial.println("connected");
    client.print("GET /ar/vale.php?se=");
    client.println(sen);
    
    Serial.print("ok");
    Serial.println(sen);
    client.stop();

  }
  else {
    Serial.println("connection failed");
  }
  }
}

