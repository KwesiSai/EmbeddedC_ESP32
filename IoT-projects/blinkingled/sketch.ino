
const int ledOne = 16;
const int ledTwo = 8;
const int ledThree = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledOne , OUTPUT);
  pinMode(ledTwo , OUTPUT);
  pinMode(ledThree , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledOne , HIGH);
  delay(1000);
  digitalWrite(ledOne , LOW);
  delay(100);
  digitalWrite(ledTwo , HIGH);
  delay(1000);
  digitalWrite(ledTwo , LOW);
  delay(200);
  digitalWrite(ledThree , HIGH);
  delay(1000);
  digitalWrite(ledThree , LOW);
  delay(200);


}
