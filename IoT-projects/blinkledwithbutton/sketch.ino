const int redLed = 9;
const int button = 15;
int buttonStatus = 0;

void setup() {
  pinMode(button, INPUT);
  pinMode(redLed, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  buttonStatus = digitalRead(button);
  if(buttonStatus == 0){
    digitalWrite(redLed, HIGH);
  }
  else{
    digitalWrite(redLed, LOW);
  }
 
}

