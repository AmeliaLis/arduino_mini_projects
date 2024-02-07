const int tensPins[] = {A15, A14, A13, A12, A11, A10, A9, A8};
const int onesPins[] = {A7, A6, A5, A4, A3, A2, A1, A0};


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
    checkNumber();
}

void checkNumber() {
    int numberDec = 0;

    for (int i = 0; i < 8; i++) {
        if (digitalRead(i) == LOW) {
            numberDec += (1 << (7 - i));
        }
    }

    int countOfTens = numberDec % 100;
    int numberOfOnes = countOfTens % 10;
    int numberOfTens = (countOfTens - numberOfOnes) / 10;

    displayNumberOnes(numberOfOnes);
    displayNumberTens(numberOfTens);
	
	if (numberOfTens > 0) {
    	   digitalWrite(A8, HIGH);
    } else {
		digitalWrite(A8, LOW);
	}	
    if (numberDec % 2 == 1) {
	   digitalWrite(A0, HIGH);
	} else {
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