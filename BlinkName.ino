
#define DOT_DELAY 500    // Duration of a dot blink (500ms)
#define DASH_DELAY 1000   // Duration of a dash blink (1000ms)
#define LETTER_GAP 500   // Gap between letters (500ms)
#define WORD_GAP 1400    // Gap between repeating the name (1400ms)

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Set built-in LED as an output
}

// Function to blink a dot (short blink)
void blinkDot() {
  digitalWrite(LED_BUILTIN, HIGH);  // Turn LED on
  delay(DOT_DELAY);                 // Wait for dot duration
  digitalWrite(LED_BUILTIN, LOW);   // Turn LED off
  delay(DOT_DELAY);                 // Wait before next signal
}

// Function to blink a dash (long blink)
void blinkDash() {
  digitalWrite(LED_BUILTIN, HIGH);  // Turn LED on
  delay(DASH_DELAY);                // Wait for dash duration
  digitalWrite(LED_BUILTIN, LOW);   // Turn LED off
  delay(DOT_DELAY);                 // Wait before next signal
}

// Function to blink a letter in Morse code
void blinkLetter(char letter) {
  switch (letter) {
    case 'S': 
      blinkDot(); blinkDot(); blinkDot(); // Morse code for 'S' (…)
      break;
    case 'A': 
      blinkDot(); blinkDash(); // Morse code for 'A' (.-)
      break;
    case 'I': 
      blinkDot(); blinkDot(); // Morse code for 'I' (..)
      break;
    case 'M': 
      blinkDash(); blinkDash(); // Morse code for 'M' (--)
      break;
  }
  delay(LETTER_GAP); // Wait before blinking next letter
}

// Function to blink the name "SAIMA" in Morse code
void blinkName() {
  char name[] = "SAIMA"; // Define the name
  for (int i = 0; i < 5; i++) { // Loop through each letter in "SAIMA"
    blinkLetter(name[i]); // Blink the current letter
  }
  delay(WORD_GAP); // Wait before repeating the name
}

void loop() {
  blinkName(); // Continuously blink the name "SAIMA" in Morse code
}

