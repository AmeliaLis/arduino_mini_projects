void setup() {
	pinMode(A15, OUTPUT);
 	pinMode(A11, OUTPUT);
 	pinMode(A8, OUTPUT);
	pinMode(21, OUTPUT);
 	pinMode(20, OUTPUT);
 	pinMode(19, OUTPUT);

	pinMode(A2, INPUT);
	pinMode(A13, INPUT);
	pinMode(22, INPUT);
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
	 	digitalWrite(20,255);
	 	digitalWrite(19,255);
	
	 	digitalWrite(A15, 0);
	 	digitalWrite(A11, 0);
	 	digitalWrite(A8, 0);
	 } else {

	 	digitalWrite(21, 0);
	 	digitalWrite(20,0);
	 	digitalWrite(19,0);

	 	digitalWrite(A15, 255);
	 	digitalWrite(A11, 255);
	 	digitalWrite(A8, 255);
	 }
}