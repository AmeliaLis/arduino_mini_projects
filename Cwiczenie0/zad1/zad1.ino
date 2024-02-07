//221423
//wybrane porty
//2   A2   1    A14    22    A3
//analogowe to te z A
//cyfrowe to reszta

void setup() {
//PINY OUTPUTOWE - używane do generowania sygnału
//PINY INPUTOWE - do odczytywania informacji
	pinMode(A15, OUTPUT); //przyjmuje sygnały wejściowe
 	pinMode(A11, OUTPUT);
 	pinMode(A8, OUTPUT);
	pinMode(21, OUTPUT);
 	pinMode(20, OUTPUT);
 	pinMode(19, OUTPUT);

	pinMode(A2, INPUT_PULLUP);
	pinMode(A13, INPUT_PULLUP);
	pinMode(22, INPUT_PULLUP);
}

void loop() {
//ustalam stan HIGH na moje wybrane porty związane z indeksem, bo chcę, żeby probes się cały czas świeciły
	digitalWrite(2, 255);
	digitalWrite(A2, 255);
	digitalWrite(1, 255);
	digitalWrite(A14, 255);
	digitalWrite(22, 255);
	digitalWrite(A3, 255);
// sprawdzam jeżeli odczytany stan moich portów jest LOW
// stan tych portów jest zmieniany podczas nacisku przycisku switch push (płynie/nie płynie)
// czyli stan zwarty i rozwarty, jak jest zwarty to płynie prąd 
// digitalRead() zwraca 1 (HIGH) lub 0 (LOW), odczytuje stan cyfrowy
	if (digitalRead(22) == LOW || digitalRead(A2) == LOW || digitalRead(A14) == LOW ) {
	// teraz ustawiam informację, żeby świeciły się diody
	// czyli przekazuję do anody high
		digitalWrite(21, 255);
	 	digitalWrite(20,255);
	 	digitalWrite(19,255);
	// a tu do katody mam ustawić na 0, żeby prąd ustał - rozumiem to jako uziemienie
	 	digitalWrite(A15, 0);
	 	digitalWrite(A11, 0);
	 	digitalWrite(A8, 0);
	 } else {
	// cały czas jest ustawione na 0, żeby się nie świeciło
	 	digitalWrite(21, 0);
	 	digitalWrite(20,0);
	 	digitalWrite(19,0);
	//a resztę zostawiam jako HIGH
	 	digitalWrite(A15, 255);
	 	digitalWrite(A11, 255);
	 	digitalWrite(A8, 255);
	 }
}