#include <LiquidCrystal.h>

const int rs = 22, en = 12, d4 = 4, d5 = 3, d6 = 2, d7 = 1;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



void setup() {
  lcd.begin(16, 2);  // Inicjalizacja LCD z 16 kolumnami i 2 wierszami
	pinMode(A1, INPUT);
	pinMode(A3, INPUT);
	pinMode(A5, INPUT);
	pinMode(A7, INPUT);
	pinMode(A9, INPUT);
	pinMode(A11, INPUT);
	pinMode(A2, OUTPUT);
	pinMode(A4, OUTPUT);
	pinMode(A6, OUTPUT);
	pinMode(A8, OUTPUT);
	pinMode(A10, OUTPUT);
}

void loop() {
// zakres 0-423V
	delay(100);
	int voltReader = analogRead(A1);
	float voltage = (voltReader / 1023.0) * 423;
	// zakres 0-350, czyli co 70V
	if (voltage < 350.0){
		digitalWrite(A2, HIGH);
		voltReader = analogRead(A3);
		voltage = (voltReader / 1023.0) * 350;
	} else {
		digitalWrite(A2, LOW);
	}
	// zakres 0-280V
	if (voltage < 280.0) {
		digitalWrite(A4, HIGH);
		voltReader = analogRead(A5);
		voltage = (voltReader / 1023.0) * 280;
	} else {
		digitalWrite(A4, LOW);
	}
	// zakres 0-210V
	if (voltage < 210.0) {
		digitalWrite(A6, HIGH);
		voltReader = analogRead(A7);
		voltage = (voltReader / 1023.0) * 210;
	} else {
		digitalWrite(A6, LOW);
	}
	// zakres 0-140V
	if (voltage < 140.0) {
		digitalWrite(A8, HIGH);
		voltReader = analogRead(A9);
		voltage = (voltReader / 1023.0) * 140;
	} else {
		digitalWrite(A8, LOW);
	}
	//zakres 0-70V
	if (voltage < 70.0) {
		digitalWrite(A10, HIGH);
		voltReader = analogRead(A11);
		voltage = (voltReader / 1023.0) * 70;
	} else {
		digitalWrite(A10, LOW);
	}

	
	displayVoltage(voltage);
}

void displayVoltage(float voltage) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
  lcd.print(voltage);
  lcd.print("V");
}
