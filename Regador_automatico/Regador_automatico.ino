// C++ code
//
int counter;

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);

  for (counter = 0; counter < 3; ++counter) {
    analogWrite(11, 255);
    analogWrite(10, 0);
    analogWrite(9, 0);
    delay(250); // Wait for 250 millisecond(s)
    analogWrite(11, 0);
    analogWrite(10, 255);
    analogWrite(9, 0);
    delay(250); // Wait for 250 millisecond(s)
    analogWrite(11, 0);
    analogWrite(10, 0);
    analogWrite(9, 255);
    delay(250); // Wait for 250 millisecond(s)
  }
  analogWrite(11, 0);
  analogWrite(10, 0);
  analogWrite(9, 0);
}

void loop()
{
  Serial.println(analogRead(A5));
  if (analogRead(A5) <= 350) {
    digitalWrite(8, HIGH);
    analogWrite(11, 255);
    analogWrite(10, 0);
    analogWrite(9, 0);
  } else {
    if (analogRead(A5) < 750) {
      digitalWrite(8, LOW);
      analogWrite(11, 0);
      analogWrite(10, 255);
      analogWrite(9, 0);
    }
    if (analogRead(A5) >= 750) {
      analogWrite(11, 125);
      analogWrite(10, 0);
      analogWrite(9, 255);
    }
  }
  delay(10); // Delay a little bit to improve simulation performance
}
