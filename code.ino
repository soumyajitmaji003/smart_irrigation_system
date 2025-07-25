#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C dis(0x27, 16, 2); // LCD I2C address 0x27 with 16x2 characters

void setup() {
  Serial.begin(9600);
  dis.begin(16, 2);     // Initialize LCD with correct dimensions
  dis.backlight();      // Turn on the backlight
  dis.clear();

  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH); // Motor OFF initially

  // Welcome Message
  dis.setCursor(0, 0);
  dis.print("IRRIGATION");
  dis.setCursor(0, 1);
  dis.print("SYSTEM IS ON");
  delay(1500);

  for (int a = 12; a <= 15; a++) {
    dis.setCursor(a, 1);
    dis.print(".");
    delay(500);  // Shorter delay for animation
  }
  dis.clear();
}

void loop() {
  int value = analogRead(A0);
  Serial.println(value);

  // Clear previous content
  dis.setCursor(0, 0);
  dis.print("                "); // Clear full line
  dis.setCursor(0, 1);
  dis.print("                "); // Clear full line

  // Control Motor
  if (value > 950) {
    digitalWrite(2, LOW); // Motor ON
    dis.setCursor(0, 0);
    dis.print("MOTOR IS ON ");
  } else {
    digitalWrite(2, HIGH); // Motor OFF
    dis.setCursor(0, 0);
    dis.print("MOTOR IS OFF");
  }

  // Moisture Status
  dis.setCursor(0, 1);
  if (value < 300) {
    dis.print("MOISTURE: HIGH");
  } else if (value <= 950) {
    dis.print("MOISTURE: MID ");
  } else {
    dis.print("MOISTURE: LOW ");
  }

  delay(1000); // Wait before next reading
}
