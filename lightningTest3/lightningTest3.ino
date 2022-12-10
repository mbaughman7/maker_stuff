
int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 9;

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}


void loop() {
  chain();
  lightning2(random(4, 8));
  delay(random(1000, 4000));
}

void flashon(int duration, int bright)
{
  analogWrite(led1, bright);
  analogWrite(led2, bright);
  analogWrite(led3,  bright);
  analogWrite(led4, bright);
  delay(duration);
}

void flashoff (int offduration)
{

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(offduration);
}

void lightning2(int times)
{
  for ( int i = 0; i <= times; i++)
  {
    flashon(random(5, 200), random(0, 800));
    flashoff(random(5, 200));
  }
}

void chain()
{
  for (int j = 0; j <= (random(5, 20)); j++)
  {
    analogWrite(led1, random(300, 800));

    delay(random(20, 100));
    analogWrite(led2, random(300, 800));
    delay(random(20, 100));
    analogWrite(led3, random(300, 800));
    delay(random(20, 100));
    analogWrite(led4, random(300, 800));
    delay(random(20, 100));
  }
}
