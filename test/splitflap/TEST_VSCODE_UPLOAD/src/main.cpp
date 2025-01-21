#include "CONFIG.H"




const int motorInterfaceType = 1;
// Create instances for all ten stepper motors
AccelStepper stepper1(motorInterfaceType, stepPin1, dirPin);
AccelStepper stepper2(motorInterfaceType, stepPin2, dirPin);
AccelStepper stepper3(motorInterfaceType, stepPin3, dirPin);
AccelStepper stepper4(motorInterfaceType, stepPin4, dirPin);
AccelStepper stepper5(motorInterfaceType, stepPin5, dirPin);
AccelStepper stepper6(motorInterfaceType, stepPin6, dirPin);
AccelStepper stepper7(motorInterfaceType, stepPin7, dirPin);
AccelStepper stepper8(motorInterfaceType, stepPin8, dirPin);
AccelStepper stepper9(motorInterfaceType, stepPin9, dirPin);
AccelStepper stepper10(motorInterfaceType, stepPin10, dirPin);

// Character set and steps per character
const std::vector<char> characterSet = {
    ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', '$', '&', '#', '0', '1',
    '2', '3', '4', '5', '6', '7', '8', '9', ':', '.', '-', '?', '!'
};

// Track the current letters for each flap (for 10 motors)
char currentLetter1 = ' ';
char currentLetter2 = ' ';
char currentLetter3 = ' ';
char currentLetter4 = ' ';
char currentLetter5 = ' ';
char currentLetter6 = ' ';
char currentLetter7 = ' ';
char currentLetter8 = ' ';
char currentLetter9 = ' ';
char currentLetter10 = ' ';

// Function to calculate steps for a one-direction transition
int calculateStepsForTransition(char current, char target) {
    int currentIndex = std::distance(characterSet.begin(),
                                     std::find(characterSet.begin(), characterSet.end(), current));
    int targetIndex = std::distance(characterSet.begin(),
                                    std::find(characterSet.begin(), characterSet.end(), target));

    // Calculate forward steps accounting for wraparound
    if (targetIndex < currentIndex) {
        targetIndex += characterSet.size(); // Wrap around to the end
    }

    return (targetIndex - currentIndex) * stepsPerChar;
}

// Function to move all motors to a target word
void moveToWord(const std::string& word) {
    // Calculate steps for each motor based on current position
    int steps1 = calculateStepsForTransition(currentLetter1, word[0]);
    int steps2 = calculateStepsForTransition(currentLetter2, word[1]);
    int steps3 = calculateStepsForTransition(currentLetter3, word[2]);
    int steps4 = calculateStepsForTransition(currentLetter4, word[3]);
    int steps5 = calculateStepsForTransition(currentLetter5, word[4]);
    int steps6 = calculateStepsForTransition(currentLetter6, word[5]);
    int steps7 = calculateStepsForTransition(currentLetter7, word[6]);
    int steps8 = calculateStepsForTransition(currentLetter8, word[7]);
    int steps9 = calculateStepsForTransition(currentLetter9, word[8]);
    int steps10 = calculateStepsForTransition(currentLetter10, word[9]);

    // Update target positions
    stepper1.moveTo(stepper1.currentPosition() + steps1);
    stepper2.moveTo(stepper2.currentPosition() + steps2);
    stepper3.moveTo(stepper3.currentPosition() + steps3);
    stepper4.moveTo(stepper4.currentPosition() + steps4);
    stepper5.moveTo(stepper5.currentPosition() + steps5);
    stepper6.moveTo(stepper6.currentPosition() + steps6);
    stepper7.moveTo(stepper7.currentPosition() + steps7);
    stepper8.moveTo(stepper8.currentPosition() + steps8);
    stepper9.moveTo(stepper9.currentPosition() + steps9);
    stepper10.moveTo(stepper10.currentPosition() + steps10);

    // Run all motors until they reach their target positions
    while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0 ||
           stepper3.distanceToGo() != 0 || stepper4.distanceToGo() != 0 ||
           stepper5.distanceToGo() != 0 || stepper6.distanceToGo() != 0 ||
           stepper7.distanceToGo() != 0 || stepper8.distanceToGo() != 0 ||
           stepper9.distanceToGo() != 0 || stepper10.distanceToGo() != 0) {
        stepper1.run();
        stepper2.run();
        stepper3.run();
        stepper4.run();
        stepper5.run();
        stepper6.run();
        stepper7.run();
        stepper8.run();
        stepper9.run();
        stepper10.run();
    }

    // Update the current letters
    currentLetter1 = word[0];
    currentLetter2 = word[1];
    currentLetter3 = word[2];
    currentLetter4 = word[3];
    currentLetter5 = word[4];
    currentLetter6 = word[5];
    currentLetter7 = word[6];
    currentLetter8 = word[7];
    currentLetter9 = word[8];
    currentLetter10 = word[9];
}

// Function to return all motors to the blank position (' ')
void returnToBlank() {
    moveToWord("          "); // Move all motors to display blank (' ')
}

void setup() {
    // Set up pin D4 as output and turn it on
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);

    // Set the maximum speed and acceleration for all motors
    stepper1.setMaxSpeed(3000);
    stepper1.setAcceleration(1500);

    stepper2.setMaxSpeed(3000);
    stepper2.setAcceleration(1500);

    stepper3.setMaxSpeed(3000);
    stepper3.setAcceleration(1500);

    stepper4.setMaxSpeed(3000);
    stepper4.setAcceleration(1500);

    stepper5.setMaxSpeed(3000);
    stepper5.setAcceleration(1500);

    stepper6.setMaxSpeed(3000);
    stepper6.setAcceleration(1500);

    stepper7.setMaxSpeed(3000);
    stepper7.setAcceleration(1500);

    stepper8.setMaxSpeed(3000);
    stepper8.setAcceleration(1500);

    stepper9.setMaxSpeed(3000);
    stepper9.setAcceleration(1500);

    stepper10.setMaxSpeed(3000);
    stepper10.setAcceleration(1500);
}

void loop() {
    // Hardcoded 10-letter words
    std::string hardcodedWord = "HELLOOOOO!"; // Example with spaces
    std::string hardcodedWord2 = "WELCOME TO"; // 10-letter word
    std::string hardcodedWord3 = "MILWAUKEE!"; // 10-letter word
    std::string hardcodedWord4 = "GOOD LUCK!"; // 10-letter word

    digitalWrite(ledPin, HIGH);

    // Move to the hardcoded word
    moveToWord(hardcodedWord);
    delay(1700);

    // Move to the hardcoded word2
    moveToWord(hardcodedWord2);
    delay(1700);

    // Move to the hardcoded word3
    moveToWord(hardcodedWord3);
    delay(1700);

// Move to the hardcoded word3
    moveToWord(hardcodedWord4);
    delay(1700);
    // Return all flaps to the blank position
    returnToBlank();

    // Wait for 7 seconds before repeating the loop
    digitalWrite(ledPin, LOW);
    delay(7000);
}
////testtttt
