#include <LiquidCrystal.h>
#include <string.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pos = 0;
int posLenth;
String msg;
char message[300];

void setup() {
  lcd.begin(16, 2);
}

void printLine() {
  posLenth = strlen(message);
  posLenth = posLenth - 16;
  for (int i = 0; i <= posLenth; i++) {

    lcd.setCursor(0, 0);
    lcd.print("Time = ");
    lcd.print(millis() / 1000);
    
    lcd.setCursor(0, 1);
    char lcdTop[16];
    int copySize = 16;
    if (strlen(message) < 16) {
      copySize = strlen(message);
    }

    int tempPos = pos;
    if (tempPos < 0)  {
      tempPos = -(tempPos);
    }

    memcpy(&lcdTop[0], &message[tempPos], copySize);
    lcd.print(lcdTop);

    pos += 1;
    if (pos + 15 >= strlen(message)) {
      i = posLenth;
    }
    delay(300);
  }

  pos = 0;  // reset position
}

void loop() {
  msg = "F1 A=" + String(analogRead(A0)) + "A B=" + String(analogRead(A1)) + "A C=" + String(analogRead(A2)) + " F2 A=" + String(analogRead(A3)) + "A B=" + String(analogRead(A4)) + "A C=" + String(analogRead(A5));
  msg.toCharArray(message, 300);
  printLine();
}
