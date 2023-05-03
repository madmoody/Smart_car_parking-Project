#include <Ethernet.h>
#include<SPI.h>
#define trig 5
#define echo 18
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress  ip(192,168,29,241);
EthernetServer server(80);
void setup() 
{
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
digitalWrite(trig,HIGH);
Serial.println("Starting ethernet:");

Ethernet.begin( mac,ip);
Serial.println(Ethernet.localIP());
}
int duration;
int distance;
void loop()
{
  
}
