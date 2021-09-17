/*pinos dos botões*/
int blue_btn = 2;
int green_btn = 3;
int yellow_btn = 4;
int red_btn = 5;

/*pinos de LED*/
int blue_led = 7;
int green_led = 8;
int yellow_led = 9;
int red_led = 10;

/*histórico das luzes que já piscaram*/
int order_history[100];

/*nível do usuário*/
int level = 1;

/*quantos botões ele já apertou no turno do usuário*/
int index_buttons = 0;

/*turno do usuário*/
bool turn_user = false;

void setup()
{
  // inputs :
  randomSeed(analogRead(0));
  pinMode(blue_btn, INPUT);
  pinMode(green_btn, INPUT);
  pinMode(yellow_btn, INPUT);
  pinMode(red_btn, INPUT);

  // outputs:
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);

}

/*função que roda quando o usuário ganha*/
void win()
{
    /*sobe de nível*/
  level++;
  
  /*termina a vez do usuário*/
  turn_user = false;

/*pisca uma vez pra mostrar que ganhou*/
  delay(1000);

  digitalWrite(blue_led, HIGH);
  digitalWrite(green_led, HIGH);
  digitalWrite(yellow_led, HIGH);
  digitalWrite(red_led, HIGH);

  delay(500);

  digitalWrite(blue_led, LOW);
  digitalWrite(green_led, LOW);
  digitalWrite(yellow_led, LOW);
  digitalWrite(red_led, LOW);

  delay(1000);
}

/*função que roda quando o usuário perde*/
void lose()
{
    /*zera o histórico das luzes que piscaram até o determinado nível*/
  memset(order_history, 0, level + 1);
  
  /*retorna ao nível 1*/
  level = 1;
  
    /*termina a vez do usuário*/
  turn_user = false;

/*pisca duas vezes pra mostrar que perdeu*/

  delay(1000);

  digitalWrite(blue_led, HIGH);
  digitalWrite(green_led, HIGH);
  digitalWrite(yellow_led, HIGH);
  digitalWrite(red_led, HIGH);

  delay(250);

  digitalWrite(blue_led, LOW);
  digitalWrite(green_led, LOW);
  digitalWrite(yellow_led, LOW);
  digitalWrite(red_led, LOW);

  delay(250);

  digitalWrite(blue_led, HIGH);
  digitalWrite(green_led, HIGH);
  digitalWrite(yellow_led, HIGH);
  digitalWrite(red_led, HIGH);

  delay(250);

  digitalWrite(blue_led, LOW);
  digitalWrite(green_led, LOW);
  digitalWrite(yellow_led, LOW);
  digitalWrite(red_led, LOW);

  delay(1000);

}

/*função que roda para gerar a ordem das luzes que vão piscar*/
void order_game()
{
  int i, order;

/*escolhe um número aleatório e salva no histórico*/
  order = random(1, 5);

  order_history[level] = order;

/*exibe o histórico. 
conforme o nível aumenta, mais rápido as luzes piscam*/
  for (i = 0; i < level; i++)
  {
    switch (order_history[i + 1])
    {
      case 1:
        digitalWrite(blue_led, HIGH);
        delay(2000 / level);
        digitalWrite(blue_led, LOW);
        delay(2000 / level);
        break;

      case 2:
        digitalWrite(green_led, HIGH);
        delay(2000 / level);
        digitalWrite(green_led, LOW);
        delay(2000 / level);
        break;

      case 3:
        digitalWrite(yellow_led, HIGH);
        delay(2000 / level);
        digitalWrite(yellow_led, LOW);
        delay(2000 / level);
        break;

      case 4:
        digitalWrite(red_led, HIGH);
        delay(2000 / level);
        digitalWrite(red_led, LOW);
        delay(2000 / level);
        break;
    }
  }

/*passa a vez para o usuário*/
  turn_user = true;
}

void loop()
{
    /*se não é a vez do usuário, o histórico de luzes é feito*/
  if (turn_user == false)
  {
    order_game();
    index_buttons = 0;
  }
  else
  {
      /*se a quantidade de botões apertados for igual ao número de nível, significa que o usuário ganhou a rodada*/
    if (index_buttons == level)
    {
      win();
    }
    else
    {
        /*verifica qual botão o usuário aperta e verifica se ele está de acordo com a ordem do histórico*/
      if (digitalRead(blue_btn) == HIGH)
      {
        digitalWrite(blue_led, HIGH);
        delay(1000);
        digitalWrite(blue_led, LOW);
        delay(1000);

        if (order_history[index_buttons + 1] != 1)
        {
          lose();
        }
        else
        {
          index_buttons++;
        }
      }
      else if (digitalRead(green_btn) == HIGH)
      {
        digitalWrite(green_led, HIGH);
        delay(1000);
        digitalWrite(green_led, LOW);
        delay(1000);

        if (order_history[index_buttons + 1] != 2)
        {
          lose();
        }
        else
        {
          index_buttons++;
        }
      }
      else if (digitalRead(yellow_btn) == HIGH)
      {
        digitalWrite(yellow_led, HIGH);
        delay(1000);
        digitalWrite(yellow_led, LOW);
        delay(1000);

        if (order_history[index_buttons + 1] != 3)
        {
          lose();
        }
        else
        {
          index_buttons++;
        }
      }
      else if (digitalRead(red_btn) == HIGH)
      {
        digitalWrite(red_led, HIGH);
        delay(1000);
        digitalWrite(red_led, LOW);
        delay(1000);

        if (order_history[index_buttons + 1] != 4)
        {
          lose();
        }
        else
        {
          index_buttons++;
        }
      }
    }
  }
}
