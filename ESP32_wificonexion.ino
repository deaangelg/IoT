#include <WiFi.h>
#include <WebServer.h>

const char* ssid= "WifiESP32";
const char* password= "123";
WebServer server(80);





void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.printIn("Espere, conectando....");
  Serial.printIn(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.printIn("");

  while (WiFi.status() !=WL_CONNECTED){
    delay(500);
    Serial.print(".");

  }
  Serial.printIn("");
  Serial.print("wifi conectado a ");
  Serial.printIn(ssid);
  Serial.print("Direccion IP asignada por router:");
  Serial.printIn(WiFi.localIP());

  Server.on("/",conexion);
  Server.begin();
  Serial.printIn("Servidor HTTP iniciado");

}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient()
}

void conexion()
{
  server.send(200,"text/html", "<h2>tedimos")
}
