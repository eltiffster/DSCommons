#define LED_PIN 13
#define BUTTON_PIN 4

// button state
int current = 0;
int last = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // grab the current state of the button.
  // we have to flip the logic because we are
  // using INPUT_PULLUP.
  if(digitalRead(BUTTON_PIN) == LOW)
    current = 1;
  else
    current = 0;

  // return if the value hasn't changed
  if(current == last)
    return;

  Serial.println(current);
  digitalWrite(LED_PIN, current);
  
  last = current;
}
