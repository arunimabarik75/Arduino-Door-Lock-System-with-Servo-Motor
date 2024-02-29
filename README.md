# Arduino Door Lock System with Servo Motor

This project is an Arduino-based door lock system that uses a servo motor and a keypad for entering a password. The system also includes an LCD display for user interaction.

## Overview

The door lock system is controlled by an Arduino Uno. A servo motor is used to lock and unlock the door. The password for the door lock is entered via a keypad. The system provides feedback and instructions to the user through an LCD display.

## Hardware Requirements

- Arduino Uno
- Servo Motor
- Keypad
- LCD Display (I2C)
- Jumper Wires
- Breadboard

## Software Requirements

- Arduino IDE
- Servo Library
- Keypad Library
- Wire Library (for I2C communication)
- LiquidCrystal_I2C Library

## Setup

1. Connect the servo motor to the Arduino Uno (pin 9).
2. Connect the keypad to the Arduino Uno (pins 2, 3, 4 for columns and pins 5, 6, 7, 8 for rows).
3. Connect the LCD display to the Arduino Uno via I2C.

## Code

The Arduino sketch (`Door_Lock_System.ino` file) includes the following functionalities:

- Initialization of the servo motor, keypad, and LCD display.
- A loop that continuously checks for key presses on the keypad.
- When a key is pressed, it is added to the entered password.
- If the '#' key is pressed, the entered password is compared with the stored password.
- If the passwords match, the door is unlocked. The LCD displays "Unlock" and waits for the '*' key to be pressed before locking the door again.
- If the passwords do not match, the LCD displays "Wrong Password" for 2 seconds before prompting for the password again.

## Usage

1. Upload the Arduino sketch to the Arduino Uno.
2. Enter the password using the keypad.
3. Press '#' to submit the password.
4. If the password is correct, the door will unlock. Press '*' to lock the door again.

## Customization

You can customize the password by changing the `password` variable in the Arduino sketch. The unlock and lock angles of the servo motor can also be adjusted by changing the `unlockAngle` and `lockedAngle` variables, respectively.
