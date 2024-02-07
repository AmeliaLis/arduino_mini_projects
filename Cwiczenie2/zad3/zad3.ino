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
	pinMode(31, INPUT);
	pinMode(33, INPUT);
	pinMode(35, INPUT);
	digitalWrite(31, HIGH);
	digitalWrite(33, HIGH);
	digitalWrite(35, HIGH);

}

void loop() {
	
	for (int i=0; i<8; i++) {
		if (digitalRead(i) == LOW) {
			pressedBits[i] = 1;
		} else {
			pressedBits[i] = 0;
		}
	}
	checkAlgorithm();
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
	
	clearDisplay();
}

void displayNumberOnes(int number) {
    // Implementacja za pomocą tablicy dwuwymiarowej
    const int displayPatterns[][15] = {
        {A7, A6, A5, A4, A3, A2},
        {A5, A6},
        {A7, A6, A1, A3, A4},
        {A7, A6, A5, A4, A1},
        {A6, A5, A1, A2},
        {A7, A5, A4, A1, A2},
        {A7, A5, A4, A3, A2, A1},
        {A7, A6, A5},
        {A7, A6, A5, A4, A3, A2, A1},
        {A7, A6, A5, A4, A2, A1},
	   {A7, A6, A5, A3, A2, A1}, //A
	   {A5, A4, A3, A2, A1}, //b
	   {A7, A4, A3, A2}, //C
	   {A6, A5, A4, A3, A1}, //d
	   {A7, A4, A3, A2, A1}, //E
	   {A7, A3, A2, A1} //F
};

    for (int i = 0; i < 15; i++) {
        digitalWrite(displayPatterns[number][i], HIGH);
    }
}

void displayNumberTens(int number) {
    // Implementacja za pomocą tablicy dwuwymiarowej
    const int displayPatterns[][15] = {
        {A15, A14, A12, A13, A11, A10},
        {A14, A13},
        {A15, A14, A9, A11, A12},
        {A15, A14, A13, A12, A9},
        {A10, A9, A14, A13},
        {A15, A10, A9, A13, A12},
	   {A15, A10, A11, A12, A13, A9},
        {A15, A14, A13},
        {A15, A14, A13, A12, A11, A10, A9},
        {A15, A14, A13, A12, A10, A9},
	   {A15, A14, A13, A11, A10, A9}, //A
	   {A13, A12, A11, A10, A9}, //b
	   {A15, A12, A11, A10}, //C
	   {A14, A13, A12, A11, A9}, //d
	   {A15, A12, A11, A10, A9}, //E
	   {A15, A11, A10, A9} //F

};

    for (int i = 0; i < 15; i++) {
        digitalWrite(displayPatterns[number][i], HIGH);
    }
}

void clearDisplay() {
    delay(500);

    for (int i = 0; i <= 7; i++) {
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

void changeAikenToDec() {
	int aiken[] = {2,4,2,1};
	
	int firstAiken = 0;
	for (int i = 0; i <=3; i++){
		if (pressedBits[i] == 1){
			firstAiken += aiken[i];
		}
	}
	int secondAiken = 0;
	for (int i = 0; i <=3; i++){
		if (pressedBits[i + 4] == 1){
			secondAiken += aiken[i];
		}
	}
	
	displayNumberTens(firstAiken);
	displayNumberOnes(secondAiken);
	
	clearDisplay();	
}

void changeBinaryToHex() {
	int firstByte = 0;
	int secondByte = 0;
	
	for (int i=0; i<=3; i++) {
		if (binaryArray[i] == 1) {
			firstByte += (1 << (3-i));
		}
	}
	
	for (int i=0; i<=3; i++) {
		if (binaryArray[4+i] == 1) {
			secondByte += (1 << (3-i));
		}
	}
	displayNumberTens(firstByte);
	displayNumberOnes(secondByte);
	
	clearDisplay();
}


void checkAlgorithm() {
	int algorithmNumber = 0;
	
	if (digitalRead(31)==LOW) {
		algorithmNumber += 4;
	}
	if (digitalRead(33)==LOW) {
		algorithmNumber += 2;
	}
	if (digitalRead(35)==LOW) {
		algorithmNumber += 1;
	}
	//BIN TO DEC
	if (algorithmNumber == 0) {
		memcpy(binaryArray, pressedBits, sizeof(binaryArray));
		changeBinaryToDecimal();
	}
	//GRAY TO DEC
	if (algorithmNumber == 1) {
		changeGreyToBinary();
		changeBinaryToDecimal();
	}
	//BIN TO HEX
	if (algorithmNumber == 2) {
		memcpy(binaryArray, pressedBits, sizeof(binaryArray));
		changeBinaryToHex();
	}
	//GRAY TO HEX
	if (algorithmNumber == 3) {
		changeGreyToBinary();
		changeBinaryToHex();
	}
	//AIKEN TO DEC
	if (algorithmNumber==4) {
		changeAikenToDec();
	}
	//AIKEN TO HEX
	if (algorithmNumber==5) {
		changeAikenToDec();
	}
	if (algorithmNumber==6) {
		changeJohnsonToDecimal();
	}
	if (algorithmNumber==7) {
		changeJohnsonToHex();
	}	
}


void changeJohnsonToDecimal() {
	int numberToAdd = 0;
	int baseNumber = 0;
	if (pressedBits[3] == 0) {
		for (int i = 4; i>=0; i--){
			if (pressedBits[i] == 1) {
				numberToAdd += 1;
			} else {
				;
			}
		}
	} else {
		baseNumber = 3;
		for (int i = 4; i>=0; i--){
			if (pressedBits[i] == 0) {
				numberToAdd += 1;
			}
		}
	}
	
	baseNumber += numberToAdd;
	int countOfTens = baseNumber % 100;
    	int numberOfOnes = countOfTens % 10;
    	int numberOfTens = (countOfTens - numberOfOnes) / 10;

	displayNumberOnes(numberOfOnes);
    	displayNumberTens(numberOfTens);
	
	clearDisplay();
	
}
void changeJohnsonToHex() {
	int numberToAdd = 0;
	int baseNumber = 0;
	if (pressedBits[3] == 0) {
		for (int i = 4; i>=0; i--){
			if (pressedBits[i] == 1) {
				numberToAdd += 1;
			} else {
				break;
			}
		}
	} else {
		baseNumber = 3;
		for (int i = 4; i>=0; i--){
			if (pressedBits[i] == 0) {
				numberToAdd += 1;
			}
		}
	}
	
	baseNumber += numberToAdd;

	displayNumberOnes(baseNumber);
	
	clearDisplay();	
}
