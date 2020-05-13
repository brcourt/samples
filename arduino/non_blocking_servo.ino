#include <Servo.h>

class MyServo {
  int buttonPin;
  int servoPin;
  int buttonState = 0;
  int isSpinning = 0;
  long previousMillis = 0;
  long interval = 1000; 
  Servo myservo;

  public:
    MyServo(int button, int servo) :
      buttonPin(button),
      servoPin(servo)
  {}

  void setup() {
    myservo.attach(servoPin);
    pinMode(buttonPin, INPUT);
  }

  void loop() {
    unsigned long currentMillis = millis();
    buttonState = digitalRead(buttonPin);

    if(currentMillis - previousMillis > interval) {
      previousMillis = currentMillis;
      Serial.println(previousMillis);
      isSpinning = LOW;
    } else {
      if (digitalRead(buttonPin) == HIGH) {
        if (isSpinning == LOW){
          previousMillis = currentMillis;
        }
        Serial.println("BUTTON PRESSED");
        isSpinning = HIGH;
      }
    }


    if (isSpinning == HIGH) {
      Serial.println("start");
      myservo.write(0);
    }
    if (isSpinning == LOW) {
      Serial.println("stop");
      myservo.write(90);
    }
  }
};


MyServo servo1(50, 30);
MyServo servo2(52, 32);

void setup() {
  Serial.begin(9600);
  servo1.setup();
  servo2.setup();

}

void loop() {
  servo1.loop();
  servo2.loop();
}
