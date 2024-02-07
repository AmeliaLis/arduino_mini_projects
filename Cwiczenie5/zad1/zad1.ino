// Zdefiniowanie pinów dla serwomechanizmów
const int pinSekundy = 5;
const int pinMinuty = 6;
const int pinGodziny = 7;

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

void setup() {
  // Ustawienie pinów jako wyjścia
  pinMode(pinSekundy, OUTPUT);
  pinMode(pinMinuty, OUTPUT);
  pinMode(pinGodziny, OUTPUT);
  pinMode(pinDzwiek, OUTPUT);
  
  // Ustawienie zerowej pozycji wskazówek
  ustawPozycjeSerwomechanizmu(pinSekundy, 0);
  ustawPozycjeSerwomechanizmu(pinMinuty, 0);
  ustawPozycjeSerwomechanizmu(pinGodziny, 0);
}

void loop() {
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

  // Opóźnienie dla przyspieszenia działania zegara dziesięciokrotnie
  delay(100);
}
