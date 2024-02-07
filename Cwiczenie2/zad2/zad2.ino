const int tensPins[] = {A15, A14, A13, A12, A11, A10, A9, A8};
const int onesPins[] = {A7, A6, A5, A4, A3, A2, A1, A0};
int pressedBits[] = {0,0,0,0,0,0,0,0,0};
int binaryArray[] = {0,0,0,0,0,0,0,0,0};

void setup() {
    for (int i = 0; i < 8; i++) {
        pinMode(tensPins[i], OUTPUT);
        pinMode(onesPins[i], OUTPUT);
    }

    for (int i = 0; i < 8; i++) {
        digitalWrite(i, HIGH);
    }
}

void loop() {
	
	for (int i=0; i<8; i++) {
		if (digitalRead(i) == LOW) {
			pressedBits[i] = 1;
		} else {
			pressedBits[i] = 0;
		}
	}
	
	changeGreyToBinary(); //najpierw zamieniam na binarny, 
    	changeBinaryToDecimal(); //by potem zamienić na decimal
}

void changeBinaryToDecimal() {
    int numberDec = 0;

    for (int i = 0; i < 8; i++) {
        if (binaryArray[i] == 1) {
            numberDec += (1 << (7 - i));
        }
    }

    int countOfTens = numberDec % 100;
    int numberOfOnes = countOfTens % 10;
    int numberOfTens = (countOfTens - numberOfOnes) / 10;

    displayNumberOnes(numberOfOnes);
    displayNumberTens(numberOfTens);
	
    if (numberOfOnes % 2 == 1) {
	   digitalWrite(A0, HIGH);
	digitalWrite(A8, LOW);
	} else {
		digitalWrite(A8, HIGH);
		digitalWrite(A0, LOW);
	}
	clearDisplay();
}

void displayNumberOnes(int number) {
    // Implementacja za pomocą tablicy dwuwymiarowej
    const int displayPatterns[][7] = {
        {A7, A6, A5, A4, A3, A2},
        {A5, A6},
        {A7, A6, A1, A3, A4},
        {A7, A6, A5, A4, A1},
        {A6, A5, A1, A2},
        {A7, A5, A4, A1, A2},
        {A7, A5, A4, A3, A2, A1},
        {A7, A6, A5},
        {A7, A6, A5, A4, A3, A2, A1},
        {A7, A6, A5, A4, A2, A1}};

    for (int i = 0; i < 7; i++) {
        digitalWrite(displayPatterns[number][i], HIGH);
    }
}

void displayNumberTens(int number) {
    // Implementacja za pomocą tablicy dwuwymiarowej
    const int displayPatterns[][7] = {
        {A15, A14, A12, A13, A11, A10},
        {A14, A13},
        {A15, A14, A9, A11, A12},
        {A15, A14, A13, A12, A9},
        {A10, A9, A14, A13},
        {A15, A10, A9, A13, A12},
	   {A15, A10, A11, A12, A13, A9},
        {A15, A14, A13},
        {A15, A14, A13, A12, A11, A10, A9},
        {A15, A14, A13, A12, A10, A9}};

    for (int i = 0; i < 7; i++) {
        digitalWrite(displayPatterns[number][i], HIGH);
    }
}

void clearDisplay() {
    delay(500);

    for (int i = 0; i < 7; i++) {
        digitalWrite(tensPins[i], LOW);
        digitalWrite(onesPins[i], LOW);
    }
}


void changeGreyToBinary() {
	int numberDec = 0;
	binaryArray[0] = pressedBits[0];
	for (int i=1; i<8; i++) {
		if (pressedBits[i] == binaryArray[i-1]) {
			binaryArray[i] = 0;
		} else {
			binaryArray[i] = 1;
		}
	}
	
	
}