#include <WiFi.h>
#include <Wire.h> 
#include "time.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define BMP_SDA 21
#define BMP_SCL 22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define LED 2 
#define Button 5

const char* ssid     = "Zeno_Modiff";              
const char* password = "UFMTRBRR"; 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_BMP280 bmp280;
WiFiClient client;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void setup() 
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  timeClient.begin();
  timeClient.setTimeOffset(19786);
  
  pinMode(LED, OUTPUT);
  pinMode(Button, INPUT);

 if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
 Serial.println(F("SSD1306 allocation failed"));
 for(;;);
  }

  boolean status = bmp280.begin(0x76);
  if (!status) {
    Serial.println("Not connected");
  }
}
void loop() {

  int ButtonState = digitalRead(Button);
  
  timeClient.update();    
  unsigned long epochTime = timeClient.getEpochTime();
  String formattedTime = timeClient.getFormattedTime();
  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();
  int currentSecond = timeClient.getSeconds(); 
  String weekDay = weekDays[timeClient.getDay()];
  struct tm *ptm = gmtime ((time_t *)&epochTime); 
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon+1;
  int currentYear = ptm->tm_year+1900;
  String currentDate = String(monthDay) + "-" + String(currentMonth) + "-" + String(currentYear);
  String currentMonthName = months[currentMonth-1];
  String currentTime = String(currentHour) + ":" + String(currentMinute) + ":" + String(currentSecond);
  String currentMonthnameyear = String(currentMonthName) + "-" + String(currentYear);
  
  if(ButtonState == HIGH) 
  {
    
  digitalWrite(LED,LOW); 
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("TIME");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 11);
  display.println(currentTime);
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 36);
  display.println("DATE");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 46);
  display.println(currentDate);
  display.display(); 
  
  }
  else
  {
  float temp = bmp280.readTemperature();
  float pres = (bmp280.readPressure());
  float alti =  (bmp280.readAltitude(1013.25)); 

  digitalWrite(LED,HIGH);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Pressure");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 11);
  display.println(pres);
  display.setTextSize(1);
  display.setCursor(107, 18);
  display.println(" PA");
  display.display(); 

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 36);
  display.println("Altitude");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 46);
  display.println(alti);
  display.setTextSize(1);
  display.setCursor(60, 52);
  display.println(" M");
  display.display(); 
  
  delay(1000);
  }
}
