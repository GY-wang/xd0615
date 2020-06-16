int x=0;
void setup()
{
  for(x=0;x<=14;x++)
  pinMode(x, OUTPUT);
}

void loop()
{
  for(x=0;x<=14;x++)
  {
  digitalWrite(x, HIGH);
  delay(120); // Wait for 1000 millisecond(s)
  digitalWrite(x, LOW);
  delay(120); // Wait for 1000 millisecond(s)
  }
}