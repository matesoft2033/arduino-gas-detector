#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SoftwareSerial.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET   -1

int           gasValue;
unsigned long lastTime = 0;
const long    interval = 1000;

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

SoftwareSerial bluetooth(10, 11);

void updateDisplay();

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  bluetooth.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastTime >= interval) {
    lastTime = currentTime;
    gasValue = analogRead(A0);
    updateDisplay();

    bluetooth.print(gasValue);
    bluetooth.print(" - ");
    if (gasValue > 120) {
      bluetooth.println("DANGER!");
    } else {
      bluetooth.println("SAFE");
    }
  }

  if (gasValue > 120) {
    digitalWrite(7, LOW);
  } else {
    digitalWrite(7, HIGH);
  }
}

void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(gasValue);
  if (gasValue > 120) {
    display.println("DANGER!");
  } else {
    display.println("SAFE");
  }
  display.display();
}