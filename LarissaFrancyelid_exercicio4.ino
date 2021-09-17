/*contabilizador de tempo*/
unsigned long time; 
unsigned long time2;

/*pino do botão*/
int button = 9;

/*pinos de led*/
int led_red = 10;
int led_green = 11;

/*verifica o estado de frequencia atual e o próximo*/
int state, state2;

/*variavel auxiliar do botão*/
int but;

/*variavel que determina a frequencia atual*/
int f;

/*intervalo entre uma frequancia e outra*/
int freq = 1000;

void setup()
{
  // outputs:
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);

  // inputs:
  pinMode(button, INPUT);

  /*inicialização da serialização*/
  Serial.begin(9600);

  /*inicialização de variáveis*/
  time = millis();
  time2 = millis();
  f = 1;

  state = 1;
  state2 = 1;
}

void loop()
{
  if (but != digitalRead(button))
  {
    but = digitalRead(button);
    if (f < 5)
    {
      f = f + 1;
    }
    else
    {
      f = 1;
    }

    time = millis();
    time2 = millis();

    state = 0;
    digitalWrite(led_green, LOW);

    state2 = 0;
    digitalWrite(led_red, LOW);

    Serial.println(f);
  }

  if ((time + ((1 / f) *freq)) <= millis())
  {
    time = millis();

    if (state == 1)
    {
      state = 0;
      digitalWrite(led_green, LOW);
    }
    else
    {
      state = 1;
      digitalWrite(led_green, HIGH);
    }
  }

  if ((time2 + ((3 / f) * freq)) <= millis())
  {
    time2 = millis();

    if (state == 1)
    {
      state2 = 0;
      digitalWrite(led_red, LOW);
    }
    else
    {
      state2 = 1;
      digitalWrite(led_red, HIGH);
    }
  }
}
