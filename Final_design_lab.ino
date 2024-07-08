// Define the pins for solenoid valves
const int solenoid1Pin = 2;
const int solenoid2Pin = 3;
const int solenoid3Pin = 4;

// Define the pin for the relay module controlling the compressor
const int compressorRelayPin = 5;

void setup() {
  // Initialize the solenoid valve pins as outputs
  pinMode(solenoid1Pin, OUTPUT);
  pinMode(solenoid2Pin, OUTPUT);
  pinMode(solenoid3Pin, OUTPUT);

  // Initialize the relay pin for the compressor as output
  pinMode(compressorRelayPin, OUTPUT);

  // Turn off all solenoid valves and the compressor at the beginning
  closeAllSolenoids();
  turnOffCompressor();
}

void loop() {
  // Example: move forward
  openSolenoid(solenoid1Pin);
  turnOnCompressor();
  delay(1000); // Adjust the delay as needed
  closeSolenoid(solenoid1Pin);
  turnOffCompressor();
  delay(1000); // Adjust the delay as needed
}

void openSolenoid(int pin) {
  digitalWrite(pin, HIGH);
}

void closeSolenoid(int pin) {
  digitalWrite(pin, LOW);
}

void closeAllSolenoids() {
  digitalWrite(solenoid1Pin, LOW);
  digitalWrite(solenoid2Pin, LOW);
  digitalWrite(solenoid3Pin, LOW);
}

void turnOnCompressor() {
  digitalWrite(compressorRelayPin, HIGH);
}

void turnOffCompressor() {
  digitalWrite(compressorRelayPin, LOW);
}
