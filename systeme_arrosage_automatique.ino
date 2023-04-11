const int moistureSensor = A0;
const int transistorGate = 13;

const int moistureThreshold = 600;
const int wateringTime = 1000;
unsigned long previousMillis = 0UL;
unsigned long waitingTime = 1UL * 60UL * 60UL * 1000UL; //1H
int moistureValue;

void setup() {
  pinMode(transistorGate, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  if (millis() - previousMillis >= waitingTime) {

    previousMillis = millis();
    moistureValue = analogRead(moistureSensor);
    //Serial.println(moistureValue);

    if (moistureValue > moistureThreshold) {
      //Serial.println("Terre trop sèche: il faut arroser");
      digitalWrite(transistorGate, HIGH);
      delay(wateringTime);
      digitalWrite(transistorGate, LOW);
    }

    else {
      //Serial.println("Terre suffisament humide");
    }
  }
}
