#include <SPI.h>
#include <WiFi101.h>

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = "your SECRET_SSID";        // your network SSID (name)
char pass[] = "your SECRET_PASS";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)
String s="";
String s1="";
String s2="";
int status = WL_IDLE_STATUS;

char server[] = "your server s url";  //from google cloud

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 5 seconds for connection:
    delay(5000);
  }
  Serial.println("Connected to wifi");
  printWiFiStatus();

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial
  //to check your connection with the server.
  if (client.connect(server, 80)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    client.println("GET "your server s url"/?name1005=name2 HTTP/1.1");
 
    client.println("Connection: close");
    client.println();
  }
}

void loop() {
  // to empty the serial buffer
    while(Serial.available() > 0) {
    char t = Serial.read();
  }
  
  Serial.setTimeout(20000L) ;     // wait until 20 seconds for input from serial
  // Ask personal data: Family name
    Serial.println(F("Type action to do #"));
s1=Serial.readStringUntil('#');
if(s1=="")return;

if(s1!="read"){
  
  Serial.println(F("Type First name, ending with #"));
s1=Serial.readStringUntil('#');
   Serial.println(F("Type Last name, ending with #"));
 s2=Serial.readStringUntil('#');
 if((s1=="")||(s2==""))return;
    if (client.connect(server, 80)) {
    
      
          s1=s1.substring(1,s1.length()) ;
          s2=s2.substring(1,s2.length()) ;
          s="GET "your server s url"/?write=";
          s += s1+"=";
          s += s2+" HTTP/1.1"; 
      Serial.println("Connected to firestore");
 //  Serial.println(s);
    client.println(s);
     client.println("Connection: close");
    client.println();
    Serial.println("data sent to firestore");
     }
    
    s2="";
  


}else{
 
  if (client.connect(server, 80)) {
    
      
          
s="GET "your server s url"/?read=mohamed=glaoui HTTP/1.1";

      Serial.println("Connected to firestore");
   
    client.println(s);
     client.println("Connection: close");
    client.println();
     delay(500);
client.println(s);
     client.println("Connection: close");
    client.println();
     
  s="";

}
  

  while (client.available()) {
  
    char c = client.read();
    s+=c;
 
  }
   int labelStart = s.indexOf("@");
   int labelStart_1 = s.indexOf("@", labelStart+1); 
  int contentEnd = s.indexOf("$", labelStart);

  
  s1 = s.substring(labelStart+1 , labelStart_1);
  s2 = s.substring(labelStart_1+1);
  Serial.println("First_name: "+s2);
  Serial.println("Last_name: "+s1);
  s="";
  
}    
}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
