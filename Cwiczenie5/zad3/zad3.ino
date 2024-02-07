// Zdefiniowanie pinów dla serwomechanizmów
const int pinSekundy = 5;
const int pinMinuty = 6;
const int pinGodziny = 7;

const int pinDS=A0;
const int pinSTC=A1;
const int pinSHC=A2;
//
const int dec_digits  [10] {1,79,18,6,76,36,32,15,0,4};

const int secondsMotor[4] {19,18,17,16};
const int minutesMotor[4] {15,14,8,9};
const int hoursMotor[4] {10,11,12,13};
//poszczególne kroki
int stepArray[4][4] =
	{
		{1,1,0,0},
		{0,1,1,0},
		{0,0,1,1},
		{1,0,0,1}
	};

// Zdefiniowanie pinu dla sygnału dźwiękowego
const int pinDzwiek = 39;

// Inicjalizacja zegara
int sekundy = 0;
int minuty = 0;
int godziny = 0;

// Funkcja ustawiająca pozycję wskazówki serwomechanizmu
void ustawPozycjeSerwomechanizmu(int pin, int kat) {
  int szerokoscPulsu = map(kat, 0, 180, 900, 1900);
  digitalWrite(pin, HIGH);
  delayMicroseconds(szerokoscPulsu);
  digitalWrite(pin, LOW);
}

// Funkcja generująca sygnał dźwiękowy
void generujDzwiek() {
  tone(pinDzwiek, 1000, 100);  // Generowanie dźwięku o częstotliwości 1000 Hz przez 100 ms
}

void calculateTime() {
  // Inkrementacja sekund
  sekundy++;


  // Aktualizacja serwomechanizmu sekundowego
  int katSekundy = map(sekundy, 0, 59, 0, 180);
  ustawPozycjeSerwomechanizmu(pinSekundy, katSekundy);

  // Generowanie sygnału dźwiękowego co minutę
  if (sekundy == 60) {
    generujDzwiek();
    sekundy = 0;

    // Inkrementacja minut
    minuty++;

    // Aktualizacja serwomechanizmu minutowego
    int katMinuty = map(minuty, 0, 59, 0, 180);
    ustawPozycjeSerwomechanizmu(pinMinuty, katMinuty);

    // Resetowanie minut po 60 minutach (jednej godzinie)
    if (minuty == 60) {
      minuty = 0;

      // Inkrementacja godzin
      godziny++;

      // Aktualizacja serwomechanizmu godzinowego
      int katGodziny = map(godziny, 0, 11, 0, 180);
      ustawPozycjeSerwomechanizmu(pinGodziny, katGodziny);

      // Resetowanie godzin po 12 godzinach (jednej doby)
      if (godziny == 12) {
        godziny = 0;
      }
    }
  }

	
	displayTime(godziny/10, godziny%10, minuty/10, minuty%10, sekundy/10, sekundy%10);
	moveStepMotor(secondsMotor, sekundy%4);
	moveStepMotor(minutesMotor, minuty%4);
	moveStepMotor(hoursMotor, godziny%4);
	  
// Opóźnienie dla przyspieszenia działania zegara dziesięciokrotnie
  delay(1);
}

void setup() {
  // Ustawienie pinów jako wyjścia
  pinMode(pinSekundy, OUTPUT);
  pinMode(pinMinuty, OUTPUT);
  pinMode(pinGodziny, OUTPUT);
  pinMode(pinDzwiek, OUTPUT);

  pinMode(pinDS, OUTPUT);
  pinMode(pinSTC, OUTPUT);
  pinMode(pinSHC, OUTPUT);

  // Ustawienie zerowej pozycji wskazówek
  ustawPozycjeSerwomechanizmu(pinSekundy, 0);
  ustawPozycjeSerwomechanizmu(pinMinuty, 0);
  ustawPozycjeSerwomechanizmu(pinGodziny, 0);
}

void loop() {
	calculateTime();

}

void displayTime(int digit1, int digit2, int digit3, int digit4, int digit5, int digit6) {
  
	digitalWrite(pinSTC,LOW);

  shiftOut(pinDS,pinSHC, LSBFIRST,dec_digits[digit6]);
  shiftOut(pinDS,pinSHC, LSBFIRST,dec_digits[digit5]);
  shiftOut(pinDS,pinSHC, LSBFIRST,dec_digits[digit4]);
  shiftOut(pinDS,pinSHC, LSBFIRST,dec_digits[digit3]);
  shiftOut(pinDS,pinSHC, LSBFIRST,dec_digits[digit2]);
  shiftOut(pinDS,pinSHC, LSBFIRST,dec_digits[digit1]);

  digitalWrite(pinSTC,HIGH);
}

void moveStepMotor(int arrayType[], int step){
	for (int i=0;i<=3;i++) {
		digitalWrite(arrayType[i], stepArray[step][i]);
	}
}