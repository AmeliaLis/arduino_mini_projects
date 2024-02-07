//221423
// A2 (yellow cars) 
// A12 (red pedastrian) 
// A1 (green cars)
// A4 (red cars) 
// 2   (przycisk)
// A3 (green pedastrian)]

#define RED_PEDASTRIAN A12
#define GREEN_PEDASTRIAN A3
#define RED_CARS A4
#define YELLOW_CARS A2
#define GREEN_CARS A1
#define BUTTON_NIGHT 2

#define PEDESTRIAN_BUTTON 20
#define PEDESTRIAN_BUTTON_LIGHT A0

bool nightMode = false;
bool buttonPressed = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 100;
bool additionalTime = false;


void setup() {
pinMode(RED_PEDASTRIAN, OUTPUT);
pinMode(GREEN_PEDASTRIAN, OUTPUT);
pinMode(RED_CARS, OUTPUT);
pinMode(YELLOW_CARS, OUTPUT);
pinMode(GREEN_CARS, OUTPUT);

pinMode(PEDESTRIAN_BUTTON_LIGHT, OUTPUT);

//przycisk nocny
pinMode(BUTTON_NIGHT, INPUT);
digitalWrite(BUTTON_NIGHT, HIGH);

//przycisk pieszych
pinMode(PEDESTRIAN_BUTTON, INPUT);
digitalWrite(PEDESTRIAN_BUTTON, HIGH);
attachInterrupt(3, pedestrianGreenButton, LOW);

testingProcedure();

}

void loop() {
	if (digitalRead(BUTTON_NIGHT) == HIGH) {
		greenCars();
		redPedastrian();
		if (digitalRead(PEDESTRIAN_BUTTON) == LOW) {
			dailyProcedure();
		}
	} else {
		turnOffLights();
		yellowNightCars();
	}
}

//procedury
void testProcedure() {
	digitalWrite(RED_PEDASTRIAN, HIGH);
	digitalWrite(GREEN_PEDASTRIAN, HIGH);
	digitalWrite(RED_CARS, HIGH);
	digitalWrite(YELLOW_CARS, HIGH);
	digitalWrite(GREEN_CARS, HIGH);
}

void stopTestProcedure() {
	digitalWrite(RED_PEDASTRIAN, LOW);
	digitalWrite(GREEN_PEDASTRIAN, LOW);
	digitalWrite(RED_CARS, LOW);
	digitalWrite(YELLOW_CARS, LOW);
	digitalWrite(GREEN_CARS, LOW);
}

void testingProcedure() {
	testProcedure();
	delay(1000);
	stopTestProcedure();
}

void redPedastrian() {digitalWrite(RED_PEDASTRIAN, HIGH);}

void turnOffRedPedastrian() {digitalWrite(RED_PEDASTRIAN, LOW);}

void greenCars() {digitalWrite(GREEN_CARS, HIGH);}

void turnOffGreenCars() {digitalWrite(GREEN_CARS, LOW);}

void yellowCars() {digitalWrite(YELLOW_CARS, HIGH);}

void turnOffYellowCars() {digitalWrite(YELLOW_CARS, LOW);}

void greenPedastrian(){digitalWrite(GREEN_PEDASTRIAN, HIGH);}

void turnOffGreenPedastrian(){digitalWrite(GREEN_PEDASTRIAN, LOW);}

void redCars() {digitalWrite(RED_CARS, HIGH);}

void turnOffRedCars() {digitalWrite(RED_CARS, LOW);}

void dailyProcedure() {
	redPedastrian();
	greenCars();
	delay(4000);
	turnOffGreenCars();
	yellowCars();
	delay(2000);
	turnOffYellowCars();
	redCars();
	delay(2000);
	turnOffRedPedastrian();
	greenPedastrian();
	delay(10000);
	if (additionalTime) {
		delay(5000);
	}
	greenPedastrianChange();
	redPedastrian();
	delay(2000);
	yellowCars();
	delay(1000);
	turnOffRedCars();
	turnOffYellowCars();
	greenCars();
	delay(2000);
	additionalTime = false;
	buttonPressed = false;
	digitalWrite(PEDESTRIAN_BUTTON_LIGHT, LOW);	
}

void greenPedastrianChange() {
	for (int i = 0; i < 5; i++) {
		delay(500);
		greenPedastrian();
		delay(500);
		turnOffGreenPedastrian();
	}
}

void turnOffLights() {
	turnOffRedPedastrian();
	turnOffGreenPedastrian();
	turnOffRedCars();
	turnOffYellowCars();
	turnOffGreenCars();
}


void yellowNightCars() {
	delay(500);
	yellowCars();
	delay(500);
	turnOffYellowCars();
}

void pedestrianGreenButton(){
	unsigned long currentMillis = millis();
	if (currentMillis - lastDebounceTime >= debounceDelay) {
		if (buttonPressed) {
			 additionalTime = true;
		}
		buttonPressed = true;
		digitalWrite(PEDESTRIAN_BUTTON_LIGHT, HIGH);
	}


}