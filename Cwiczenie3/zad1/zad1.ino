//221423
// 1 4 2 3 -> D7-> 1 D6-> 2 D5-> 3 D4-> 4
//22 -> RS
//12 -> En
#include <LiquidCrystal.h>
const int rs = 22, en = 12, d4 = 4, d5 = 3, d6 = 2, d7 = 1;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
}

void loop() {
  int potPin = A0;
  int potValue = analogRead(potPin);

  // Map the analog reading to voltage (0-1023 to 0-5V)
  //map is used to map a range of values to another range
  float voltage = map(potValue, 0, 1023, 0, 5000) / 1000.0;

  // Clear the LCD
  lcd.clear();

  // Print the voltage on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
  lcd.print(voltage);
  lcd.print("V");

  delay(500);
}
