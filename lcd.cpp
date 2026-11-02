
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

byte character1[8] = {
  B00100,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B10001
};

byte character2[8] = {
  B00100,
  B01110,
  B00100,
  B11111,
  B00100,
  B01010,
  B01010,
  B01010
};

String napis = "BIEGAMY PANOWIE     ";
int pozycja = 0;
int postac = 0;
unsigned long poprzedniCzas = 0;

void setup()
{
  lcd_1.begin(16, 2);
  lcd_1.createChar(0, character1);
  lcd_1.createChar(1, character2);
  lcd_1.setBacklight(1);
  lcd_1.clear();
}

void loop()
{
  if (millis() - poprzedniCzas >= 200)
  {
    poprzedniCzas = millis();

    // Animacja postaci
    lcd_1.setCursor(0, 0);
    lcd_1.print("                ");

    lcd_1.setCursor(postac, 0);
    lcd_1.write(byte(postac % 2));

    postac++;
    if (postac >= 16) postac = 0;

    // Przewijany napis
    lcd_1.setCursor(0, 1);

    for (int i = 0; i < 16; i++)
    {
      int indeks = (pozycja + i) % napis.length();
      lcd_1.print(napis[indeks]);
    }

    pozycja++;
    if (pozycja >= napis.length()) pozycja = 0;
  }
}
