#include <Servo.h>
#include <Keypad.h>
#include <Wire.h> // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h> // Include the I2C LCD library

Servo doorServo;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address (0x27) to match your LCD's address

const int servoPin = 9;
const int numRows = 4;
const int numCols = 3;

char keypadKeys[numRows][numCols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[numRows] = {8, 7, 6, 5}; //connect to the row pins (R0-R3) of the keypad
byte colPins[numCols] = {4, 3, 2}; //connect to the column pins (C0-C2) of the keypad


char password[] = "1234"; // Change this to your desired password
char enteredPassword[5]; // Store the entered password
int passwordIndex = 0;

const int unlockAngle = 90; // Angle to unlock the door
const int lockedAngle = 0;  // Angle to lock the door

Keypad keypad = Keypad(makeKeymap(keypadKeys),rowPins,colPins,numRows,numCols);

void setup() {
  doorServo.attach(servoPin);
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
  lcd.print(">");
}

void loop() {
  char key = getKey();

  if (key != NO_KEY && key != '#') {
    enteredPassword[passwordIndex++] = key;
    lcd.setCursor(passwordIndex, 1);
    lcd.print('*');
  }

  if (key == '#') {
    enteredPassword[passwordIndex] = '\0'; // Null-terminate the entered password
    if (strcmp(enteredPassword, password) == 0) {
      unlockDoor();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Unlock");
      while(getKey() != '*');
      lcd.print("Locking");
      lockDoor();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Wrong Password");
      delay(2000); // Display "Wrong Password" for 2 seconds
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");
    }
    clearPassword();
  }
}

char getKey() {
  char key = keypad.getKey();
  return key;
}

void unlockDoor() {
  doorServo.write(unlockAngle);
}

void lockDoor() {
  doorServo.write(lockedAngle);
}

void clearPassword() {
  passwordIndex = 0;
  memset(enteredPassword, 0, sizeof(enteredPassword));
  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear the password display
  lcd.setCursor(0, 1);
  lcd.print(">");
}