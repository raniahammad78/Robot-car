/*  Joystick Kontrollü Arduino Robot Araba
*/

#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7

int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  int xAxis = analogRead(A0); // Joystick X-ekseni oku
  int yAxis = analogRead(A1); // Joystick Y-ekseni oku

  // Y-ekseni ileri ve geri kontrol için kullanılmaktadır
    if (yAxis < 470) {
    // Motor A geri
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Motor B geri
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
    motorSpeedA = map(yAxis, 470, 0, 0, 255);
    motorSpeedB = map(yAxis, 470, 0, 0, 255);
  }
  else if (yAxis > 550) {
    // Motor A ileri
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Motor B ileri
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // motor hız kontrolü
    motorSpeedA = map(yAxis, 550, 1023, 0, 255);
    motorSpeedB = map(yAxis, 550, 1023, 0, 255);
  }
  // joystick ortada ise hareket etme
  else {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }

  // X-ekseni sağ ve sol kontrol için
  if (xAxis < 470) {
    int xMapped = map(xAxis, 470, 0, 0, 255);
    // Sola dönüşte sol motorun hızını azalt ve sağ motora güç ver
    motorSpeedA = motorSpeedA - xMapped;
    motorSpeedB = motorSpeedB + xMapped;
    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }
  if (xAxis > 550) {
    int xMapped = map(xAxis, 550, 1023, 0, 255);
    // sağa dönüşte sağ motorun hızını azalt ve sol motora güç ver
    motorSpeedA = motorSpeedA + xMapped;
    motorSpeedB = motorSpeedB - xMapped;
    if (motorSpeedA > 255) {
      motorSpeedA = 255;
    }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
    }
  }
  // düşük hızda motordan gelen sesi kapatmak için motoru durdur
  if (motorSpeedA < 70) {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70) {
    motorSpeedB = 0;
  }
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}
