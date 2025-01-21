#ifndef CONFIG_H
#define CONFIG_H

#include <AccelStepper.h>
#include <vector>
#include <string>

// Pin definitions
const int dirPin = 2;
const int stepPin1 = 16;
const int stepPin2 = 17;
const int stepPin3 = 18;
const int stepPin4 = 19;
const int stepPin5 = 21;
const int stepPin6 = 22;
const int stepPin7 = 23;
const int stepPin8 = 25;
const int stepPin9 = 26;
const int stepPin10 = 27;
const int ledPin = 4;

// Define motor interface type
extern const int motorInterfaceType;

// Character set and steps per character
extern const std::vector<char> characterSet;
const int stepsPerChar = 91;

// Function declarations
int calculateStepsForTransition(char current, char target);
void moveToWord(const std::string& word);
void returnToBlank();

#endif //config
