int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 9;
int led5 = 10;
int led6 = 11;
int led;
void setup() 
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void loop()
{ 
  // wrote this when I was new.  Change this to pass randomly chosen led into function as argument. 
  led = random(1,10);
  if (led == 1)
  {
    firefly(led1); 
  }
  if (led == 2)
  {
    firefly(led2);
  }
   if (led == 3)
  {
    firefly(led3); 
  }
   if (led == 4)
  {
    firefly(led4); 
  }
   if (led == 5)
  {
    firefly(led5); 
  }
   if (led == 6)
  {
    firefly(led6); 
  }
  if (led == 7)
  {
    firefly2(led1,led4);
  }
  if (led == 8)
  {
    firefly2(led2,led5);
  }
  if (led == 9)
  {
    firefly2(led3,led6);
  }
  Serial.println(led);
  delay(random(300,2000));
}

void firefly(int light)
{
  for(int brightness = 0; brightness < 255; brightness++)
  {
    
    analogWrite(light, brightness);
    delay(random(2,6));
  }

  for(int brightness = 255; brightness>=0; brightness--)
  {
    analogWrite(light, brightness);
    delay(random(2,6));
  }
}
void firefly2(int light, int light2)
{
  for(int brightness = 0; brightness < 255; brightness++)
  {
    analogWrite(light, brightness);
    analogWrite(light2, brightness);
    delay(random(1,6));
  }

  for(int brightness = 255; brightness>=0; brightness--)
  {
    analogWrite(light, brightness);
    analogWrite(light2, brightness);
    delay(random(1,6));
  }
}
