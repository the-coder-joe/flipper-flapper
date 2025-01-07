//// Include the AccelStepper Library
//#include <AccelStepper.h>
//
//// Define pin connections
//const int dirPin = 2;
//const int stepPin = 16;
//const int ledPin = 4; // Define pin D4 for the LED or any device you want to control
//
//// Define motor interface type
//#define motorInterfaceType 1
//
//// Creates an instance
//AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);
//
//void setup() {
//  // Set up pin D4 as output and turn it on
//  pinMode(ledPin, OUTPUT);
//  digitalWrite(ledPin, HIGH);
//
//Serial.begin(115200);
//  // Set the maximum speed and acceleration    
//  myStepper.setMaxSpeed(3000); // Set maximum speed
//  myStepper.setAcceleration(1500); // Set acceleration
//
//  Serial.println("Tiem to spinnnn");
//}
//
//void loop() {
//  // Rotate the motor 91 half steps
//  myStepper.moveTo(myStepper.currentPosition() + 4096); // Move 91 half steps
//  while (myStepper.distanceToGo() != 0) {
//    myStepper.run(); // Run until the target position is reached
//  }
//  
//  delay(2000); // Wait for 2 seconds
//}

//===============================================================================3 motor conteol ========================================================================================================

//#include <AccelStepper.h>
//
//// Define pin connections
//const int dirPin = 2;        // Shared direction pin
//const int stepPin1 = 16;     // Step pin for Motor 1
//const int stepPin2 = 17;     // Step pin for Motor 2
//const int stepPin3 = 18;     // Step pin for Motor 3
//const int ledPin = 4;        // Define pin D4 for the LED or any device you want to control
//
//// Define motor interface type
//#define motorInterfaceType 1
//
//// Create instances for all three stepper motors
//AccelStepper stepper1(motorInterfaceType, stepPin1, dirPin);
//AccelStepper stepper2(motorInterfaceType, stepPin2, dirPin);
//AccelStepper stepper3(motorInterfaceType, stepPin3, dirPin);
//
//void setup() {
//  // Set up pin D4 as output and turn it on
//  pinMode(ledPin, OUTPUT);
//  digitalWrite(ledPin, HIGH);
//
//  // Set the maximum speed and acceleration for all motors
//  stepper1.setMaxSpeed(3000); // Set maximum speed
//  stepper1.setAcceleration(1500); // Set acceleration
//
//  stepper2.setMaxSpeed(3000); // Set maximum speed
//  stepper2.setAcceleration(1500); // Set acceleration
//
//  stepper3.setMaxSpeed(3000); // Set maximum speed
//  stepper3.setAcceleration(1500); // Set acceleration
//}
//
//void loop() {
//  // Rotate all motors 4096 steps (equivalent to one full rotation for 1.8° step angle in 1/8 microstepping)
//  stepper1.moveTo(stepper1.currentPosition() + 4096);
//  stepper2.moveTo(stepper2.currentPosition() + 4096);
//  stepper3.moveTo(stepper3.currentPosition() + 4096);
//
//  // Run all motors until they reach their target positions
//  while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0 || stepper3.distanceToGo() != 0) {
//    stepper1.run();
//    stepper2.run();
//    stepper3.run();
//  }
//
//  delay(2000); // Wait for 2 seconds before the next movement
//}

//====================================================================5 motor control letters===============================================================================
//// Include the AccelStepper Library
//#include <AccelStepper.h>
//#include <vector>
//#include <string>
//
//// Define pin connections
//const int dirPin = 2;        // Shared direction pin
//const int stepPin1 = 16;     // Step pin for Motor 1
//const int stepPin2 = 17;     // Step pin for Motor 2
//const int stepPin3 = 18;     // Step pin for Motor 3
//const int stepPin4 = 19;     // Step pin for Motor 4
//const int stepPin5 = 21;     // Step pin for Motor 5 (new motor added)
//const int ledPin = 4;        // Define pin D4 for the LED or any device you want to control
//
//// Define motor interface type
//#define motorInterfaceType 1
//
//// Create instances for all five stepper motors
//AccelStepper stepper1(motorInterfaceType, stepPin1, dirPin);
//AccelStepper stepper2(motorInterfaceType, stepPin2, dirPin);
//AccelStepper stepper3(motorInterfaceType, stepPin3, dirPin);
//AccelStepper stepper4(motorInterfaceType, stepPin4, dirPin);
//AccelStepper stepper5(motorInterfaceType, stepPin5, dirPin);
//
//// Character set and steps per character
//const std::vector<char> characterSet = {
//    ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
//    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
//    'U', 'V', 'W', 'X', 'Y', 'Z', '$', '&', '#', '0', '1',
//    '2', '3', '4', '5', '6', '7', '8', '9', ':', '.', '-', '?', '!'
//};
//const int stepsPerChar = 91; // 91 steps per character
//
//// Track the current letters for each flap (for 5 motors)
//char currentLetter1 = ' ';
//char currentLetter2 = ' ';
//char currentLetter3 = ' ';
//char currentLetter4 = ' ';
//char currentLetter5 = ' ';
//
//// Function to calculate steps for a one-direction transition
//int calculateStepsForTransition(char current, char target) {
//    int currentIndex = std::distance(characterSet.begin(),
//                                     std::find(characterSet.begin(), characterSet.end(), current));
//    int targetIndex = std::distance(characterSet.begin(),
//                                    std::find(characterSet.begin(), characterSet.end(), target));
//
//    // Calculate forward steps accounting for wraparound
//    if (targetIndex < currentIndex) {
//        targetIndex += characterSet.size(); // Wrap around to the end
//    }
//
//    return (targetIndex - currentIndex) * stepsPerChar;
//}
//
//// Function to move all motors to a target word
//void moveToWord(const std::string& word) {
//    // Calculate steps for each motor based on current position
//    int steps1 = calculateStepsForTransition(currentLetter1, word[0]);
//    int steps2 = calculateStepsForTransition(currentLetter2, word[1]);
//    int steps3 = calculateStepsForTransition(currentLetter3, word[2]);
//    int steps4 = calculateStepsForTransition(currentLetter4, word[3]);
//    int steps5 = calculateStepsForTransition(currentLetter5, word[4]);  // Handle 5th motor
//
//    // Update target positions
//    stepper1.moveTo(stepper1.currentPosition() + steps1);
//    stepper2.moveTo(stepper2.currentPosition() + steps2);
//    stepper3.moveTo(stepper3.currentPosition() + steps3);
//    stepper4.moveTo(stepper4.currentPosition() + steps4);
//    stepper5.moveTo(stepper5.currentPosition() + steps5);
//
//    // Run all motors until they reach their target positions
//    while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0 ||
//           stepper3.distanceToGo() != 0 || stepper4.distanceToGo() != 0 ||
//           stepper5.distanceToGo() != 0) {
//        stepper1.run();
//        stepper2.run();
//        stepper3.run();
//        stepper4.run();
//        stepper5.run();
//    }
//
//    // Update the current letters
//    currentLetter1 = word[0];
//    currentLetter2 = word[1];
//    currentLetter3 = word[2];
//    currentLetter4 = word[3];
//    currentLetter5 = word[4];
//}
//
//// Function to return all motors to the blank position (' ')
//void returnToBlank() {
//    moveToWord("     "); // Move all motors to display blank (' ')
//}
//
//void setup() {
//    // Set up pin D4 as output and turn it on
//    pinMode(ledPin, OUTPUT);
//    digitalWrite(ledPin, HIGH);
//
//    // Set the maximum speed and acceleration for all motors
//    stepper1.setMaxSpeed(3000);
//    stepper1.setAcceleration(1500);
//
//    stepper2.setMaxSpeed(3000);
//    stepper2.setAcceleration(1500);
//
//    stepper3.setMaxSpeed(3000);
//    stepper3.setAcceleration(1500);
//
//    stepper4.setMaxSpeed(3000);
//    stepper4.setAcceleration(1500);
//
//    stepper5.setMaxSpeed(3000);
//    stepper5.setAcceleration(1500);
//}
//
//void loop() {
//    // Hardcoded 5-letter words   
//    std::string hardcodedWord = "CALEB";  // Blank space
//    std::string hardcodedWord2 = "HATES"; // 5-letter word (with space at the end)
//    std::string hardcodedWord3 = "BIDEN"; // 5-letter word (with space at the end)
//
//    digitalWrite(ledPin, HIGH);
//
//    // Move to the hardcoded word
//    moveToWord(hardcodedWord);
//    // Wait for 1 second before transitioning to next word
//    delay(1000);
//    
//    // Move to the hardcoded word2
//    moveToWord(hardcodedWord2);
//    delay(1000);
//
//    // Move to the hardcoded word3
//    moveToWord(hardcodedWord3);
//    delay(1000);
//     
//    // Return all flaps to the blank position
//    returnToBlank();
//
//    // Wait for 7 seconds before repeating the loop
//    digitalWrite(ledPin, LOW);
//    delay(7000);
//}
//
//

//===============================================================================================3 motor display word (doesnt works)==========================================================================================================================================
//#include <AccelStepper.h>
//
//// Pin Definitions
//const int dirPin = 2;
//const int stepPin1 = 16;
//const int stepPin2 = 17;
//const int stepPin3 = 18;
//const int ledPin = 4;
//
//// Motor Setup
//#define motorInterfaceType 1
//AccelStepper stepper1(motorInterfaceType, stepPin1, dirPin);
//AccelStepper stepper2(motorInterfaceType, stepPin2, dirPin);
//AccelStepper stepper3(motorInterfaceType, stepPin3, dirPin);
//
//const int stepsPerChar = 91; // Steps per character
//
//// Function to calculate target positions based on a word
//void displayWord(const char word[]) {
//    // Calculate target positions with blank (' ') as the base character
//    int target1 = (word[0] - ' ') * stepsPerChar;
//    int target2 = (word[1] - ' ') * stepsPerChar;
//    int target3 = (word[2] - ' ') * stepsPerChar;
//
//    // Move motors to target positions
//    stepper1.moveTo(target1);
//    stepper2.moveTo(target2);
//    stepper3.moveTo(target3);
//
//    // Run motors until all have reached their targets
//    while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0 || stepper3.distanceToGo() != 0) {
//        stepper1.run();
//        stepper2.run();
//        stepper3.run();
//    }
//}
//
//// Function to return all flaps to the blank position (' ')
//void returnBlank() {
//    // Blank corresponds to position 0
//    int blankPosition = 0;
//
//    // Move each motor to the blank position
//    stepper1.moveTo(blankPosition);
//    stepper2.moveTo(blankPosition);
//    stepper3.moveTo(blankPosition);
//
//    // Run motors until they reach the blank position
//    while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0 || stepper3.distanceToGo() != 0) {
//        stepper1.run();
//        stepper2.run();
//        stepper3.run();
//    }
//}
//
//void setup() {
//    // LED setup
//    pinMode(ledPin, OUTPUT);
//    digitalWrite(ledPin, HIGH);
//
//    // Configure stepper motors
//    stepper1.setMaxSpeed(3000);
//    stepper1.setAcceleration(1500);
//    stepper2.setMaxSpeed(3000);
//    stepper2.setAcceleration(1500);
//    stepper3.setMaxSpeed(3000);
//    stepper3.setAcceleration(1500);
//}
//
//void loop() {
//    // Hardcoded word to display
//    const char word[] = "GAY";
//
//    // Display the word by moving flaps to the correct positions
//    displayWord(word);
//
//    // Wait for 2 seconds before returning to blank
//    delay(2000);
//
//    // Return all flaps to blank position
//    returnBlank();
//
//    // Wait for 2 seconds before restarting the loop
//    delay(2000);
//}

//==============================================================================================Time on 5 seg======================================================================================
//#include <WiFi.h>
//#include "time.h"
//#include <AccelStepper.h>
//#include <vector>
//#include <string>
//
//#include <WiFi.h>
//#include <AccelStepper.h>
//
//// WiFi Credentials
//const char* ssid = "SpectrumSetup-C9";
//const char* password = "awayfish026";
//
//// Time Server
//const char* ntpServer = "pool.ntp.org";
//const long gmtOffset_sec = -6 * 3600; // Adjust to your timezone
//const int daylightOffset_sec = 3600; // 1 hour for daylight savings time
//
//// Motor and Pin Definitions
//const int dirPin = 2;      // Shared direction pin
//const int stepPin1 = 16;   // Step pin for Motor 1
//const int stepPin2 = 17;   // Step pin for Motor 2
//const int stepPin3 = 18;   // Step pin for Motor 3
//const int stepPin4 = 19;   // Step pin for Motor 4
//const int stepPin5 = 21;   // Step pin for Motor 5
//const int ledPin = 4;      // LED pin
//
//#define motorInterfaceType 1
//
//AccelStepper stepper1(motorInterfaceType, stepPin1, dirPin);
//AccelStepper stepper2(motorInterfaceType, stepPin2, dirPin);
//AccelStepper stepper3(motorInterfaceType, stepPin3, dirPin);
//AccelStepper stepper4(motorInterfaceType, stepPin4, dirPin);
//AccelStepper stepper5(motorInterfaceType, stepPin5, dirPin);
//
//// Character Set
//const String characterSet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ$&#0123456789:.-?!";
//const int stepsPerChar = 91; // 91 steps per character
//
//// Current Letters on the Display
//char currentLetter1 = ' ';
//char currentLetter2 = ' ';
//char currentLetter3 = ' ';
//char currentLetter4 = ' ';
//char currentLetter5 = ' ';
//
//// Function to calculate steps for one-direction movement
//int calculateStepsForTransition(char current, char target) {
//    int currentIndex = characterSet.indexOf(current);
//    int targetIndex = characterSet.indexOf(target);
//
//    if (targetIndex < currentIndex) {
//        targetIndex += characterSet.length(); // Wrap around
//    }
//
//    return (targetIndex - currentIndex) * stepsPerChar;
//}
//
//// Function to move all motors to display a word
//void moveToWord(const String& word) {
//    // Turn off the LED while flipping
//    digitalWrite(ledPin, HIGH);
//
//    // Calculate steps for each motor
//    int steps1 = calculateStepsForTransition(currentLetter1, word.charAt(0));
//    int steps2 = calculateStepsForTransition(currentLetter2, word.charAt(1));
//    int steps3 = calculateStepsForTransition(currentLetter3, word.charAt(2));
//    int steps4 = calculateStepsForTransition(currentLetter4, word.charAt(3));
//    int steps5 = calculateStepsForTransition(currentLetter5, word.charAt(4));
//
//    // Update motor positions
//    stepper1.moveTo(stepper1.currentPosition() + steps1);
//    stepper2.moveTo(stepper2.currentPosition() + steps2);
//    stepper3.moveTo(stepper3.currentPosition() + steps3);
//    stepper4.moveTo(stepper4.currentPosition() + steps4);
//    stepper5.moveTo(stepper5.currentPosition() + steps5);
//
//    // Run motors until they reach their positions
//    while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0 ||
//           stepper3.distanceToGo() != 0 || stepper4.distanceToGo() != 0 || 
//           stepper5.distanceToGo() != 0) {
//        stepper1.run();
//        stepper2.run();
//        stepper3.run();
//        stepper4.run();
//        stepper5.run();
//    }
//
//    // Update the current letters
//    currentLetter1 = word.charAt(0);
//    currentLetter2 = word.charAt(1);
//    currentLetter3 = word.charAt(2);
//    currentLetter4 = word.charAt(3);
//    currentLetter5 = word.charAt(4);
//
//    // Turn the LED back on
//    digitalWrite(ledPin, LOW);
//}
//
//// Function to get the current time and display it
//void displayCurrentTime() {
//    struct tm timeinfo;
//
//    // Get time from the NTP server
//    if (!getLocalTime(&timeinfo)) {
//        Serial.println("Failed to obtain time");
//        return;
//    }
//
//    // Format the time (e.g., 13:45 -> "13:45 ")
//    String hour = String(timeinfo.tm_hour);
//    String minute = String(timeinfo.tm_min);
//    if (hour.length() < 2) hour = "0" + hour;
//    if (minute.length() < 2) minute = "0" + minute;
//
//    String displayTime = hour + ":" + minute + " ";
//
//    // Display the time on the flaps
//    moveToWord(displayTime);
//}
//
//void setup() {
//    Serial.begin(115200);
//
//    // Connect to Wi-Fi
//    Serial.print("Connecting to WiFi...");
//    WiFi.begin(ssid, password);
//    while (WiFi.status() != WL_CONNECTED) {
//        delay(500);
//        Serial.print(".");
//    }
//    Serial.println("\nWiFi connected");
//
//    // Initialize time
//    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
//
//    // Initialize motors
//    stepper1.setMaxSpeed(3000);
//    stepper1.setAcceleration(1500);
//
//    stepper2.setMaxSpeed(3000);
//    stepper2.setAcceleration(1500);
//
//    stepper3.setMaxSpeed(3000);
//    stepper3.setAcceleration(1500);
//
//    stepper4.setMaxSpeed(3000);
//    stepper4.setAcceleration(1500);
//
//    stepper5.setMaxSpeed(3000);
//    stepper5.setAcceleration(1500);
//
//    // Set up the LED pin
//    pinMode(ledPin, OUTPUT);
//    digitalWrite(ledPin, HIGH);
//}
//
//void loop() {
//    displayCurrentTime();
//    delay(10000); // Update every 10 seconds
//}

//======================================================================================homing 1 motor=========================================================================================
//// Include the AccelStepper Library
//#include <AccelStepper.h>
//
//// Define pin connections
//const int dirPin = 2;
//const int stepPin = 16;
//const int mEn = 4; // motor enable
//// MUX control pins
//const int S0 = 12;  // Define pin for S0
//const int S1 = 13;  // Define pin for S1
//const int S2 = 14;  // Define pin for S2
//const int S3 = 5;  // Define pin for S3
//const int MUX_OUT = 34; // Define pin to read the MUX output (E)
//
//// Define motor interface type
//#define motorInterfaceType 1
//
//// Creates an instance
//AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);
//
//void setup() {
//  // Initialize Serial communication for debugging
//  Serial.begin(115200);
//  
//  // Set up motor enable pin
//  pinMode(mEn, OUTPUT);
//  digitalWrite(mEn, HIGH);
//
//  // Set up MUX control pins
//  pinMode(S0, OUTPUT);
//  pinMode(S1, OUTPUT);
//  pinMode(S2, OUTPUT);
//  pinMode(S3, OUTPUT);
//
//  // Set up MUX output pin
//  pinMode(MUX_OUT, INPUT);
//
//  // Set the MUX to channel 0
//  digitalWrite(S0, LOW);
//  digitalWrite(S1, LOW);
//  digitalWrite(S2, LOW);
//  digitalWrite(S3, LOW);
//
//  // Set the maximum speed and acceleration
//  myStepper.setMaxSpeed(3000); // Slow rotation speed
//  myStepper.setAcceleration(1500); // Slower acceleration for control
//
// Serial.println("Setup complete. Starting loop...");
//}
//
//void loop() {
//  // Read the MUX output
//  int muxSignal = digitalRead(MUX_OUT);
//
//  // Print the MUX signal state to the Serial Monitor
//  Serial.print("MUX Channel 0 Signal: ");
//  Serial.println(muxSignal == HIGH ? "HIGH" : "LOW");
//
//  // If the signal on channel 0 is HIGH, run the motor
//  if (muxSignal == HIGH) {
//    myStepper.moveTo(myStepper.currentPosition() + 91); // Move 91 half steps
//    while (myStepper.distanceToGo() != 0) {
//      myStepper.run(); // Run until the target position is reached
//    }
//   // delay(25);
//    
//  } else {
//    // If the signal is LOW, stop the motor
//    myStepper.moveTo(myStepper.currentPosition() + 91); // Move 91 half steps
//    while (myStepper.distanceToGo() != 0) {
//      myStepper.run(); // Run until the target position is reached
//    }
//    myStepper.stop();
//    // Optionally disable motor driver to save power:
//     digitalWrite(mEn, LOW);
//  }
//
//  // Add a short delay to avoid flooding the Serial Monitor
// // delay(100);
//}
//=====================================================================================================   2 motor home ===================================================================
//#include <AccelStepper.h>
//
//// Define pin connections
//const int dirPin = 2;        // Shared direction pin for both motors
//const int stepPin1 = 16;     // Step pin for Motor 1
//const int stepPin2 = 17;     // Step pin for Motor 2
//const int mEn = 4;           // Motor enable pin
//
//// MUX control pins
//const int S0 = 12;           // Define pin for S0
//const int S1 = 13;           // Define pin for S1
//const int S2 = 14;           // Define pin for S2
//const int S3 = 5;
//const int MUX_OUT = 34;      // Define pin to read the MUX output (E)
//
//// Define motor interface type
//#define motorInterfaceType 1
//
//// Create instances for both motors
//AccelStepper motor1(motorInterfaceType, stepPin1, dirPin);
//AccelStepper motor2(motorInterfaceType, stepPin2, dirPin);
//
//// Function prototypes
//void setupMUXChannel0();
//void setupMUXChannel1();
//
//void setup() {
//  // Set up motor enable pin
//  pinMode(mEn, OUTPUT);
//  digitalWrite(mEn, HIGH); // Enable motor driver
//
//  // Set up MUX control pins
//  pinMode(S0, OUTPUT);
//  pinMode(S1, OUTPUT);
//  pinMode(S2, OUTPUT);
//   pinMode(S3, OUTPUT);
//
//  // Set up MUX output pin
//  pinMode(MUX_OUT, INPUT);
//
//  // Set maximum speed and acceleration for both motors
//  motor1.setMaxSpeed(3000); // Maximum speed
//  motor1.setAcceleration(1500); // Acceleration
//
//  motor2.setMaxSpeed(3000); // Maximum speed
//  motor2.setAcceleration(1500); // Acceleration
//
//  // Set up the MUX for both channels
//  setupMUXChannel0();
//  setupMUXChannel1();
//  digitalWrite(mEn, LOW);
//}
//
//void loop() {
//  delay(500);
//}
//
//// Function to set up MUX Channel 0
//void setupMUXChannel0() {
//  // Set MUX control pins for channel 0
//  digitalWrite(S0, LOW);  // Channel 0: S0 = LOW
//  digitalWrite(S1, LOW);  // Channel 0: S1 = LOW
//  digitalWrite(S2, LOW);  // Channel 0: S2 = LOW
//   digitalWrite(S3, LOW);  // Channel 0: S2 = LOW
//
//  // Continuously check the MUX signal
//  while (digitalRead(MUX_OUT) == HIGH) {
//    motor1.moveTo(motor1.currentPosition() + 91); // Rotate 91 steps
//    while (motor1.distanceToGo() != 0) {
//      motor1.run();
//    }
//  } 
//  
//  // Disable motor when signal is LOW
//  motor1.stop();
//  
//}
//
//// Function to set up MUX Channel 1
//void setupMUXChannel1() {
//  // Set MUX control pins for channel 1
//  digitalWrite(S0, HIGH); // Channel 1: S0 = HIGH
//  digitalWrite(S1, LOW);  // Channel 1: S1 = LOW
//  digitalWrite(S2, LOW);  // Channel 1: S2 = LOW
//   digitalWrite(S3, LOW);  // Channel 0: S2 = LOW
//
//  // Continuously check the MUX signal
//  while (digitalRead(MUX_OUT) == HIGH) {
//    motor2.moveTo(motor2.currentPosition() + 91); // Rotate 91 steps
//    while (motor2.distanceToGo() != 0) {
//      motor2.run();
//    }
//  } 
//  
//  // Disable motor when signal is LOW
//  motor2.stop();
//  
//}


//========================================================================= 7 seg attempt ====================================================================================
//// Include the AccelStepper Library
//#include <AccelStepper.h>
//#include <vector>
//#include <string>
//
//// Define pin connections
//const int dirPin = 2;         // Shared direction pin
//const int stepPin1 = 16;      // Step pin for Motor 1
//const int stepPin2 = 17;      // Step pin for Motor 2
//const int stepPin3 = 18;      // Step pin for Motor 3
//const int stepPin4 = 19;      // Step pin for Motor 4
//const int stepPin5 = 21;      // Step pin for Motor 5
//const int stepPin6 = 22;      // Step pin for Motor 6 (new motor added)
//const int stepPin7 = 23;      // Step pin for Motor 7 (new motor added)
//const int ledPin = 4;         // Define pin D4 for the LED or any device you want to control
//
//// Define motor interface type
//#define motorInterfaceType 1
//
//// Create instances for all seven stepper motors
//AccelStepper stepper1(motorInterfaceType, stepPin1, dirPin);
//AccelStepper stepper2(motorInterfaceType, stepPin2, dirPin);
//AccelStepper stepper3(motorInterfaceType, stepPin3, dirPin);
//AccelStepper stepper4(motorInterfaceType, stepPin4, dirPin);
//AccelStepper stepper5(motorInterfaceType, stepPin5, dirPin);
//AccelStepper stepper6(motorInterfaceType, stepPin6, dirPin);
//AccelStepper stepper7(motorInterfaceType, stepPin7, dirPin);
//
//// Character set and steps per character
//const std::vector<char> characterSet = {
//    ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
//    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
//    'U', 'V', 'W', 'X', 'Y', 'Z', '$', '&', '#', '0', '1',
//    '2', '3', '4', '5', '6', '7', '8', '9', ':', '.', '-', '?', '!'
//};
//const int stepsPerChar = 91; // 91 steps per character
//
//// Track the current letters for each flap (for 7 motors)
//char currentLetter1 = ' ';
//char currentLetter2 = ' ';
//char currentLetter3 = ' ';
//char currentLetter4 = ' ';
//char currentLetter5 = ' ';
//char currentLetter6 = ' ';
//char currentLetter7 = ' ';
//
//// Function to calculate steps for a one-direction transition
//int calculateStepsForTransition(char current, char target) {
//    int currentIndex = std::distance(characterSet.begin(),
//                                     std::find(characterSet.begin(), characterSet.end(), current));
//    int targetIndex = std::distance(characterSet.begin(),
//                                    std::find(characterSet.begin(), characterSet.end(), target));
//
//    // Calculate forward steps accounting for wraparound
//    if (targetIndex < currentIndex) {
//        targetIndex += characterSet.size(); // Wrap around to the end
//    }
//
//    return (targetIndex - currentIndex) * stepsPerChar;
//}
//
//// Function to move all motors to a target word
//void moveToWord(const std::string& word) {
//    // Calculate steps for each motor based on current position
//    int steps1 = calculateStepsForTransition(currentLetter1, word[0]);
//    int steps2 = calculateStepsForTransition(currentLetter2, word[1]);
//    int steps3 = calculateStepsForTransition(currentLetter3, word[2]);
//    int steps4 = calculateStepsForTransition(currentLetter4, word[3]);
//    int steps5 = calculateStepsForTransition(currentLetter5, word[4]);
//    int steps6 = calculateStepsForTransition(currentLetter6, word[5]);
//    int steps7 = calculateStepsForTransition(currentLetter7, word[6]);
//
//    // Update target positions
//    stepper1.moveTo(stepper1.currentPosition() + steps1);
//    stepper2.moveTo(stepper2.currentPosition() + steps2);
//    stepper3.moveTo(stepper3.currentPosition() + steps3);
//    stepper4.moveTo(stepper4.currentPosition() + steps4);
//    stepper5.moveTo(stepper5.currentPosition() + steps5);
//    stepper6.moveTo(stepper6.currentPosition() + steps6);
//    stepper7.moveTo(stepper7.currentPosition() + steps7);
//
//    // Run all motors until they reach their target positions
//    while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0 ||
//           stepper3.distanceToGo() != 0 || stepper4.distanceToGo() != 0 ||
//           stepper5.distanceToGo() != 0 || stepper6.distanceToGo() != 0 ||
//           stepper7.distanceToGo() != 0) {
//        stepper1.run();
//        stepper2.run();
//        stepper3.run();
//        stepper4.run();
//        stepper5.run();
//        stepper6.run();
//        stepper7.run();
//    }
//
//    // Update the current letters
//    currentLetter1 = word[0];
//    currentLetter2 = word[1];
//    currentLetter3 = word[2];
//    currentLetter4 = word[3];
//    currentLetter5 = word[4];
//    currentLetter6 = word[5];
//    currentLetter7 = word[6];
//}
//
//// Function to return all motors to the blank position (' ')
//void returnToBlank() {
//    moveToWord("       "); // Move all motors to display blank (' ')
//}
//
//void setup() {
//    // Set up pin D4 as output and turn it on
//    pinMode(ledPin, OUTPUT);
//    digitalWrite(ledPin, HIGH);
//
//    // Set the maximum speed and acceleration for all motors
//    stepper1.setMaxSpeed(3000);
//    stepper1.setAcceleration(1500);
//
//    stepper2.setMaxSpeed(3000);
//    stepper2.setAcceleration(1500);
//
//    stepper3.setMaxSpeed(3000);
//    stepper3.setAcceleration(1500);
//
//    stepper4.setMaxSpeed(3000);
//    stepper4.setAcceleration(1500);
//
//    stepper5.setMaxSpeed(3000);
//    stepper5.setAcceleration(1500);
//
//    stepper6.setMaxSpeed(3000);
//    stepper6.setAcceleration(1500);
//
//    stepper7.setMaxSpeed(3000);
//    stepper7.setAcceleration(1500);
//}
//
//void loop() {
//    // Hardcoded 7-letter words   
//    std::string hardcodedWord = "JULIANA"; // Example with spaces
//    std::string hardcodedWord2 = " HATES "; // 7-letter word
//    std::string hardcodedWord3 = "kids"; // 7-letter word
//
//    digitalWrite(ledPin, HIGH);
//
//    // Move to the hardcoded word
//    moveToWord(hardcodedWord);
//    delay(1000);
//
//    // Move to the hardcoded word2
//    moveToWord(hardcodedWord2);
//    delay(1000);
//
//    // Move to the hardcoded word3
//    moveToWord(hardcodedWord3);
//    delay(1000);
//
//    // Return all flaps to the blank position
//    returnToBlank();
//
//    // Wait for 7 seconds before repeating the loop
//    digitalWrite(ledPin, LOW);
//    delay(7000);
//}
//

//==================================================================== 10 seg display =============================

// Include the AccelStepper Library
#include <AccelStepper.h>
#include <vector>
#include <string>

// Define pin connections
const int dirPin = 2;         // Shared direction pin
const int stepPin1 = 16;      // Step pin for Motor 1
const int stepPin2 = 17;      // Step pin for Motor 2
const int stepPin3 = 18;      // Step pin for Motor 3
const int stepPin4 = 19;      // Step pin for Motor 4
const int stepPin5 = 21;      // Step pin for Motor 5
const int stepPin6 = 22;      // Step pin for Motor 6
const int stepPin7 = 23;      // Step pin for Motor 7
const int stepPin8 = 25;      // Step pin for Motor 8
const int stepPin9 = 26;      // Step pin for Motor 9
const int stepPin10 = 27;     // Step pin for Motor 10
const int ledPin = 4;         // Define pin D4 for the LED or any device you want to control

// Define motor interface type
#define motorInterfaceType 1

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
const int stepsPerChar = 91; // 91 steps per character

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
    std::string hardcodedWord = "WYATT YOU "; // Example with spaces
    std::string hardcodedWord2 = "SUCK BIG.."; // 10-letter word
    std::string hardcodedWord3 = "COCKNBALLS"; // 10-letter word
    std::string hardcodedWord4 = "LOSERRR!!!"; // 10-letter word

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
