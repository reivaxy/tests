void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);

}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  delay(100);
}