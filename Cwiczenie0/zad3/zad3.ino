bool toggle = false;

void setup() {
	pinMode(A15, OUTPUT);
 	pinMode(A11, OUTPUT);
 	pinMode(A8, OUTPUT);
	pinMode(21, OUTPUT);
	//tutaj zmienilam pin 20 na 18 ze wzgledu na konflikt z obsluga przerwan
 	pinMode(18, OUTPUT);
 	pinMode(19, OUTPUT);

 	pinMode(22, INPUT);
 	pinMode(A2, INPUT);
	pinMode(A14, INPUT);
	
	//zad3 ostatnia cyfra indeksu to 3, więc int3
	pinMode(LED_BUILTIN,OUTPUT);
	digitalWrite(20, 255);
	attachInterrupt(3, funkcjaPrzerwania, LOW);
}

void loop() {
	digitalWrite(2, 255);
	digitalWrite(A2, 255);
	digitalWrite(1, 255);
	digitalWrite(A14, 255);
	digitalWrite(22, 255);
	digitalWrite(A3, 255);

	if (digitalRead(22) == LOW || digitalRead(A2) == LOW || digitalRead(A14) == LOW ) {

		digitalWrite(21, 255);
	 	digitalWrite(18,255);
	 	digitalWrite(19,255);

	 	digitalWrite(A15, 0);
	 	digitalWrite(A11, 0);
	 	digitalWrite(A8, 0);
	 } else {

	 	digitalWrite(21, 0);
	 	digitalWrite(18,0);
	 	digitalWrite(19,0);

	 	digitalWrite(A15, 255);
	 	digitalWrite(A11, 255);
	 	digitalWrite(A8, 255);
	 }
}


void funkcjaPrzerwania() {
	toggle = !toggle;
	digitalWrite(LED_BUILTIN, toggle);
}
