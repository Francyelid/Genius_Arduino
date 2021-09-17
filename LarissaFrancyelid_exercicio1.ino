/*pinos de led*/
int led_red = 13;
int led_yellow = 12;
int led_green = 11;

/*números fixos do tempo de cada luz*/
int time_red = 5000;
int time_yellow = 2000;
int time_green = 10000;

void setup()
{
  // outputs:
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);
}

void loop()
{
  /*começando da luz vermelha*/
  //luz vermelha acende
  digitalWrite(led_red, HIGH);
  delay(time_red);
  //luz vermelha apaga
  digitalWrite(led_red, LOW);

  /*seguido da luz verde*/
  //luz verde acende
  digitalWrite(led_green, HIGH);
  delay(time_green);
  //luz verde apaga
  digitalWrite(led_green, LOW);

  /*finalizando com a luz amarela*/
  //luz amarela acende
  digitalWrite(led_yellow, HIGH);
  delay(time_yellow);
  //luz amarela apaga
  digitalWrite(led_yellow, LOW);
}
