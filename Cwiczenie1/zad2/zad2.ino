//221423
// A2 (yellow cars) 
// A12 (red PEDESTRIAN) 
// A1 (green cars)
// A4 (red cars) 
// 2   (przycisk)
// A3 (green PEDESTRIAN)]

#define RED_PEDESTRIAN A12
#define GREEN_PEDESTRIAN A3
#define RED_CARS A4
#define YELLOW_CARS A2
#define GREEN_CARS A1
#define BUTTON 2

void setup() {
pinMode(RED_PEDESTRIAN, OUTPUT);
pinMode(GREEN_PEDESTRIAN, OUTPUT);
pinMode(RED_CARS, OUTPUT);
pinMode(YELLOW_CARS, OUTPUT);
pinMode(GREEN_CARS, OUTPUT);
//przycisk nocny
pinMode(BUTTON, INPUT);
digitalWrite(BUTTON, HIGH);
}

void loop() {
	if (digitalRead(BUTTON) == HIGH) {
		dailyProcedure();
	} else {
		turnOffLights();
		yellowNightCars();
	}
}

//procedury
void testProcedure() {
	digitalWrite(RED_PEDESTRIAN, HIGH);
	digitalWrite(GREEN_PEDESTRIAN, HIGH);
	digitalWrite(RED_CARS, HIGH);
	digitalWrite(YELLOW_CARS, HIGH);
	digitalWrite(GREEN_CARS, HIGH);
}

void stopTestProcedure() {
	digitalWrite(RED_PEDESTRIAN, LOW);
	digitalWrite(GREEN_PEDESTRIAN, LOW);
	digitalWrite(RED_CARS, LOW);
	digitalWrite(YELLOW_CARS, LOW);
	digitalWrite(GREEN_CARS, LOW);
}

void testingProcedure() {
	testProcedure();
	delay(2000);
	stopTestProcedure();
}

void redPEDESTRIAN() {digitalWrite(RED_PEDESTRIAN, HIGH);}

void turnOffRedPEDESTRIAN() {digitalWrite(RED_PEDESTRIAN, LOW);}

void greenCars() {digitalWrite(GREEN_CARS, HIGH);}

void turnOffGreenCars() {digitalWrite(GREEN_CARS, LOW);}

void yellowCars() {digitalWrite(YELLOW_CARS, HIGH);}

void turnOffYellowCars() {digitalWrite(YELLOW_CARS, LOW);}

void greenPEDESTRIAN(){digitalWrite(GREEN_PEDESTRIAN, HIGH);}

void turnOffGreenPEDESTRIAN(){digitalWrite(GREEN_PEDESTRIAN, LOW);}

void redCars() {digitalWrite(RED_CARS, HIGH);}

void turnOffRedCars() {digitalWrite(RED_CARS, LOW);}

void dailyProcedure() {
	redPEDESTRIAN();
	greenCars();
	delay(4000);
	turnOffGreenCars();
	yellowCars();
	delay(2000);
	turnOffYellowCars();
	redCars();
	delay(2000);
	turnOffRedPEDESTRIAN();
	greenPEDESTRIAN();
	delay(4000);
	greenPEDESTRIANChange();
	redPEDESTRIAN();
	delay(2000);
	yellowCars();
	delay(1000);
	turnOffRedCars();
	turnOffYellowCars();
	greenCars();
	delay(2000);
}

void greenPEDESTRIANChange() {
	for (int i = 0; i < 5; i++) {
		delay(500);
		greenPEDESTRIAN();
		delay(500);
		turnOffGreenPEDESTRIAN();
	}
}

void turnOffLights() {
	turnOffRedPEDESTRIAN();
	turnOffGreenPEDESTRIAN();
	turnOffRedCars();
	turnOffYellowCars();
	turnOffGreenCars();
}

void nightProcedure() {
	for (int i = 0; i < 5; i++) {
		yellowNightCars();
	}	
}

void yellowNightCars() {
	delay(500);
	yellowCars();
	delay(500);
	turnOffYellowCars();
}
