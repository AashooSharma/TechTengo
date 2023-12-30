int sensor_pin = 9;
int led= 13;
int val = 0; // Initialize val to a default value (not detecting sound)
int new_val = 0;
void setup() {
  pinMode(sensor_pin, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  // int new_val = analogRead(sensor_pin);
  int new_val = digitalRead(sensor_pin);
  Serial.println(new_val);
  if (new_val == 1){
    if (val==0){
      val=1;
      digitalWrite(led, 1);
      delay(2000);

    } else {
      val=0;
      digitalWrite(led, 0);
      delay(2000);
    }

  }


}
