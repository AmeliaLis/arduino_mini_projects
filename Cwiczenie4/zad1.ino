#include <LiquidCrystal.h>

const int rs = 14, en = 15, d4 = 18, d5 = 19, d6 = 20, d7 = 21;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int result = 0;
String currExpr = "";
const int ROW_NUM = 4; // four rows
const int COLUMN_NUM = 4; // four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'/','*','-','+'},
  {'9','6','3','='},
  {'8','5','2','0'},
  {'7','4','1','R'}
};

byte pin_rows[ROW_NUM] = {7,6,5,4}; // connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {3,2,1,0}; // connect to the column pinouts of the keypad

void setup() {
	lcd.begin(16, 2);
}

void loop() {
	char key = getKey();
	if (key != '\0') {
		lcd.clear();
		lcd.setCursor(0, 0);
    
    		if (key == 'R') {
			// reset result
			result = 0;
			currExpr="";
			lcd.print("Result reset");
			
		} else if (key == '=') {
			// display result
			lcd.print("Result: ");
			lcd.print(result);
			
		} else if (isdigit(key)) {
	      	// add a number to result
	      	result = result * 10 + (key - '0');
		 	currExpr = result;
	      	lcd.print(result);
	
		} else if (key == '+') {
	      	operate('+');
	
		} else if (key == '-') {
			operate('-');
			
		} else if (key == '*') {
			operate('*');
			
		} else if (key == '/') {
			operate('/');
			
		}
	}
}

void operate(char operation) {
	int operand = 0;
	lcd.print(currExpr);
	lcd.print(operation);
  	while (true) {
    		char numKey = getKey();
    		if (isdigit(numKey)) {
      		lcd.print(numKey);
      		operand = operand * 10 + (numKey - '0');
    		} else if (numKey == '=') {
      		lcd.setCursor(0, 1);
      		lcd.print("Result: ");
      		switch (operation) {
				case '+':
			          result = result + operand;
			          break;
			     case '-':
			          result = result - operand;
			          break;
			     case '*':
			          result = result * operand;
			          break;
			     case '/':
			          if (operand != 0) {
						result = result / operand;
			          } else {
						lcd.print("Error");
						result=0;
					 	currExpr="";
						break;
			          	}
			          break;
			      }
      	lcd.print(result);
		currExpr = result;
     		break;
    		}
  	}
}

char getKey() {
	char key = '\0';
	for (int i = 0; i < ROW_NUM; i++) {
		pinMode(pin_rows[i], OUTPUT);
		digitalWrite(pin_rows[i], LOW);
		
		for (int j = 0; j < COLUMN_NUM; j++) {
			pinMode(pin_column[j], INPUT_PULLUP);
			if (digitalRead(pin_column[j]) == LOW) {
				delay(50); // debounce delay
				while (digitalRead(pin_column[j]) == LOW);
					key = keys[i][j];
	      		}
	      	pinMode(pin_column[j], INPUT);
	    	}
		pinMode(pin_rows[i], INPUT);
	}
	return key;
}