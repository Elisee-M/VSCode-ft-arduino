// LED Blink Program
// This program blinks an LED connected to pin 13

const int LED_PIN = 13;  // LED connected to digital pin 13
const int BLINK_DELAY = 1000;  // Delay in milliseconds (1 second)

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Turn LED on
  digitalWrite(LED_PIN, HIGH);
  delay(BLINK_DELAY);
  
  // Turn LED off
  digitalWrite(LED_PIN, LOW);
  delay(BLINK_DELAY);
}
