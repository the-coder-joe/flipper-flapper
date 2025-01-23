/*
#include "CONFIG.H"
#include "FLAPROTATION.H"




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

////testtttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
#include <WiFi.h>
#include <WebServer.h>
#include "CONFIG.H"
#include "FLAPROTATION.H"

const char* ssid = "ESP32";  // Enter SSID here
const char* password = "12345678";  // Enter Password here

IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);

// Motor and character set configuration
const int motorInterfaceType = 1;
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

// Add the other motors similarly...

const std::vector<char> characterSet = {
    ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', '$', '&', '#', '0', '1',
    '2', '3', '4', '5', '6', '7', '8', '9', ':', '.', '-', '?', '!'
};

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
// Add currentLetter2 to currentLetter10...

// Function prototypes
int calculateStepsForTransition(char current, char target);
void moveToWord(const std::string& word);
void returnToBlank();
String SendHTML();
void handle_OnConnect();
void handle_SetText();

// Web server handlers
void handle_OnConnect() {
    server.send(200, "text/html", SendHTML());
}

void handle_SetText() {
    if (server.hasArg("word")) {
        String inputWord = server.arg("word");
        if (inputWord.length() == 10) {
            moveToWord(inputWord.c_str());
            server.send(200, "text/html", "<h1>Text updated successfully</h1><a href='/'>Go Back</a>");
        } else {
            server.send(400, "text/html", "<h1>Error: Text must be 10 characters long</h1><a href='/'>Go Back</a>");
        }
    } else {
        server.send(400, "text/html", "<h1>Error: No text received</h1><a href='/'>Go Back</a>");
    }
}

// HTML page generation
String SendHTML() {
    String html = "<!DOCTYPE html><html><head><title>Split-Flap Control</title></head><body>";
    html += "<h1>ESP32 Split-Flap Control</h1>";
    html += "<form action='/settext' method='POST'>";
    html += "Enter 10-character string: <input type='text' name='word' maxlength='10'>";
    html += "<input type='submit' value='Update'>";
    html += "</form>";
    html += "</body></html>";
    return html;
}

// Core functionality
int calculateStepsForTransition(char current, char target) {
    int currentIndex = std::distance(characterSet.begin(),
                                     std::find(characterSet.begin(), characterSet.end(), current));
    int targetIndex = std::distance(characterSet.begin(),
                                    std::find(characterSet.begin(), characterSet.end(), target));

    if (targetIndex < currentIndex) {
        targetIndex += characterSet.size(); // Wrap around to the end
    }

    return (targetIndex - currentIndex) * stepsPerChar;
}

void moveToWord(const std::string& word) {
    // Ensure the word is exactly 10 characters long
    if (word.length() != 10) {
        Serial.println("Error: Word must be exactly 10 characters.");
        return;
    }
     // Enable motors
    digitalWrite(mEn, HIGH);

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

    // Set target positions for all motors
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

    // Update the current letter for each motor
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

      // Disable motors
    digitalWrite(mEn, LOW);

    Serial.println("Word updated successfully.");
}
void handle_SetWord() {
    if (server.hasArg("word")) { // Check if the 'word' parameter is present
        String word = server.arg("word"); // Retrieve the word parameter
        if (word.length() == 10) {
            Serial.print("Received word: ");
            Serial.println(word); // Print the received word

            moveToWord(word.c_str()); // Pass the word to the moveToWord function
            server.send(200, "text/plain", "Word accepted and displayed.");
        } else {
            Serial.println("Error: Word must be exactly 10 characters.");
            server.send(400, "text/plain", "Error: Word must be exactly 10 characters.");
        }
    } else {
        Serial.println("Error: 'word' parameter missing.");
        server.send(400, "text/plain", "Error: 'word' parameter missing.");
    }
}



void returnToBlank() {
    moveToWord("          ");
}

void setup() {
    Serial.begin(115200);
    pinMode(mEn, OUTPUT);

    // Motor setup
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

    // WiFi setup
    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    delay(100);

    server.on("/", handle_OnConnect);
    server.on("/settext", handle_SetText);
    server.on("/setword", handle_SetWord);
    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();
    // Run motor logic here if needed.
}
*/
#include <WiFi.h>
#include "time.h"
#include <AccelStepper.h>
#include <vector>
#include <string>

#include <WiFi.h>
#include <AccelStepper.h>

// WiFi Credentials
const char* ssid = "my24G";
const char* password = "Mypetfish6^";

// Time Server
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -6 * 3600; // Adjust to your timezone
const int daylightOffset_sec = 3600; // 1 hour for daylight savings time

// Motor and Pin Definitions
const int dirPin = 2;      // Shared direction pin
const int stepPin1 = 16;   // Step pin for Motor 1
const int stepPin2 = 17;   // Step pin for Motor 2
const int stepPin3 = 18;   // Step pin for Motor 3
const int stepPin4 = 19;   // Step pin for Motor 4
const int stepPin5 = 21;   // Step pin for Motor 5
const int ledPin = 4;      // LED pin

#define motorInterfaceType 1

AccelStepper stepper1(motorInterfaceType, stepPin1, dirPin);
AccelStepper stepper2(motorInterfaceType, stepPin2, dirPin); 
AccelStepper stepper3(motorInterfaceType, stepPin3, dirPin);
AccelStepper stepper4(motorInterfaceType, stepPin4, dirPin);
AccelStepper stepper5(motorInterfaceType, stepPin5, dirPin);

// Character Set
const String characterSet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ$&#0123456789:.-?!";
const int stepsPerChar = 91; // 91 steps per character

// Current Letters on the Display
char currentLetter1 = ' ';
char currentLetter2 = ' ';
char currentLetter3 = ' ';
char currentLetter4 = ' ';
char currentLetter5 = ' ';

// Function to calculate steps for one-direction movement
int calculateStepsForTransition(char current, char target) {
   int currentIndex = characterSet.indexOf(current);
   int targetIndex = characterSet.indexOf(target);

   if (targetIndex < currentIndex) {
       targetIndex += characterSet.length(); // Wrap around
   }

   return (targetIndex - currentIndex) * stepsPerChar;
}

// Function to move all motors to display a word
void moveToWord(const String& word) {
   // Turn off the LED while flipping
   digitalWrite(ledPin, HIGH);

   // Calculate steps for each motor
   int steps1 = calculateStepsForTransition(currentLetter1, word.charAt(0));
   int steps2 = calculateStepsForTransition(currentLetter2, word.charAt(1));
   int steps3 = calculateStepsForTransition(currentLetter3, word.charAt(2));
   int steps4 = calculateStepsForTransition(currentLetter4, word.charAt(3));
   int steps5 = calculateStepsForTransition(currentLetter5, word.charAt(4));

   // Update motor positions
   stepper1.moveTo(stepper1.currentPosition() + steps1);
   stepper2.moveTo(stepper2.currentPosition() + steps2);
   stepper3.moveTo(stepper3.currentPosition() + steps3);
   stepper4.moveTo(stepper4.currentPosition() + steps4);
   stepper5.moveTo(stepper5.currentPosition() + steps5);

   // Run motors until they reach their positions
   while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0 ||
          stepper3.distanceToGo() != 0 || stepper4.distanceToGo() != 0 || 
          stepper5.distanceToGo() != 0) {
       stepper1.run();
       stepper2.run();
       stepper3.run();
       stepper4.run();
       stepper5.run();
   }

   // Update the current letters
   currentLetter1 = word.charAt(0);
   currentLetter2 = word.charAt(1);
   currentLetter3 = word.charAt(2);
   currentLetter4 = word.charAt(3);
   currentLetter5 = word.charAt(4);

   // Turn the LED back on
   digitalWrite(ledPin, LOW);
}

// Function to get the current time and display it
void displayCurrentTime() {
   struct tm timeinfo;

   // Get time from the NTP server
   if (!getLocalTime(&timeinfo)) {
       Serial.println("Failed to obtain time");
       return;
   }

   // Format the time (e.g., 13:45 -> "13:45 ")
   String hour = String(timeinfo.tm_hour);
   String minute = String(timeinfo.tm_min);
   if (hour.length() < 2) hour = "0" + hour;
   if (minute.length() < 2) minute = "0" + minute;

   String displayTime = hour + ":" + minute + " ";

   // Display the time on the flaps
   moveToWord(displayTime);
}

void setup() {
   Serial.begin(115200);

   // Connect to Wi-Fi
   Serial.print("Connecting to WiFi...");
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
       delay(500);
       Serial.print(".");
   }
   Serial.println("\nWiFi connected");

   // Initialize time
   configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

   // Initialize motors
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

   // Set up the LED pin
   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, HIGH);
}

void loop() {
   displayCurrentTime();
   delay(10000); // Update every 10 seconds
}

