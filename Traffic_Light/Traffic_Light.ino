int redPin = 13;
int yellowPin = 12;
int greenPin = 11;
int buttonPin = 2; // Pin 2 supports external interrupts on the Uno

volatile bool button = false;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  // Use internal pull-up resistor (button reads HIGH when unpressed, LOW when pressed)
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Attach the interrupt to Pin 2. Triggers when voltage FALLS (button is pressed)
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, FALLING);
}

void loop() {
  if (button) {
    if (digitalRead(redPin) == LOW && digitalRead(yellowPin) == LOW && digitalRead(greenPin) == LOW) {
      delay(1000);
      digitalWrite(greenPin, HIGH);
    } else if (digitalRead(redPin) == LOW && digitalRead(yellowPin) == LOW && digitalRead(greenPin) == HIGH) {
      delay(1000);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
    } else if (digitalRead(redPin) == LOW && digitalRead(yellowPin) == HIGH && digitalRead(greenPin) == LOW) {
      delay(1000);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, HIGH);
    } else if (digitalRead(redPin) == HIGH && digitalRead(yellowPin) == LOW && digitalRead(greenPin) == LOW) {
      delay(1000);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
    }
    button = false;
  } 
}

// The Interrupt Service Routine (ISR)
void buttonPressed() {
  button = true;
}

