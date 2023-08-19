#include <string.h>
bool isBlinking = false;
String savedName = "";
const int BUTTON_PIN = 3;
int button_counter;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);// initialize button pin as an output.
  Serial.begin(9600);
}
int checkAlphabet(char c) {
  return (c - 'a' );
}

String morseCodeArray[26]{
  ".-",
  "-...",
  "-.-.",
  "-..",
  ".",
  "..-.",
  "--.",
  "....",
  "..",
  ".---",
  "-.-",
  ".-..",
  "--",
  "-.",
  "---",
  ".--.",
  "--.-",
  ".-.",
  "...",
  "-",
  "..-",
  "...-",
  ".--",
  "-..-",
  "-.--",
  "--.."
};
void blinkLED(String morseCode) {
  for (int k = 0; k < morseCode.length(); k++) {
    if (morseCode[k] == '.') {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN,LOW);
      delay(500);
      
    } else if (morseCode[k] == '-') {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(2000);
      digitalWrite(LED_BUILTIN,LOW);
      delay(500);
      
    }

  }
}
// the loop function runs over and over again forever
void loop() {
  if (digitalRead(3) == LOW) {
     
    // Button is pressed
    if (!isBlinking) {
      isBlinking = true;

      if (savedName == "") {
        Serial.println("Enter your name");
         while (!Serial.available()) {
        // Wait until serial data is available
      }
        savedName = Serial.readStringUntil('\n');
        Serial.println(savedName);
      }
      
      for (int i = 0; i < savedName.length(); i++) {
        Serial.println(savedName[i]);
        int j = checkAlphabet(savedName[i]);
        String morseCode = morseCodeArray[j];
        blinkLED(morseCode);
        digitalWrite(LED_BUILTIN, LOW);
        delay(3000); // Adjust the delay time between letters
      }
    }
  } else {
    isBlinking = false;
  }
}

