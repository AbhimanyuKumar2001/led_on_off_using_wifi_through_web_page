#include<ESP8266WiFi.h>
#define ssid "your wifi name"
#define password "your wifi password"
WiFiServer server(80); 
void setup() {
  pinMode(D4,HIGH);
  Serial.begin(115200);
 WiFi.begin(ssid,password);
 Serial.println("Connecting to Network......");
 while(WiFi.status()!=WL_CONNECTED){
    delay(400);
    Serial.print(".");
   }
 Serial.println("");
 Serial.println("Connected to Network");
 server.begin();
 Serial.println("Use this IP to Acess the page: ");
 Serial.print(WiFi.localIP());
}
void loop() { 
   WiFiClient client=server.available();
   if(!client){
    return;
   }
   String request=client.readStringUntil('\r');
   if(request.indexOf("/on")!=-1)
       digitalWrite(D4,1);
   if(request.indexOf("/off")!=-1)
       digitalWrite(D4,0);
  client.print("<!DOCTYPE html>\n");
client.print("<html>\n");
client.print("<head>\n");
client.print("\t<title>My Dashboard</title>\n");
client.print("</head>\n");
client.print("<body><center>\n");
client.print("\t<h3>Welcome to ABHI Automations</h3>\n");
client.print("\t<div style=\"margin top: 50px;  margin-bottom:50px \"></div>\n");
client.print("    <a href=\"on\"><button >Light ON</button></a>\n");
client.print("    <a href=\"off\"><button>Light off</button></a>\n");
client.print("</center>\n");
client.print("\n");
client.print("</body>\n");
client.print("</html>");

}
