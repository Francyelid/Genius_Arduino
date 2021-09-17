/*pinos de LED*/
int led_red = 10;
int led_yellow = 9;
int led_green = 8;

/*pino do botão*/
int button = 11;

/*números fixos do tempo de cada luz*/
int time_red = 5000;
int time_yellow = 2000;
int time_green = 10000;

/*variavel que guarda o estado do botão*/
int buttonState = 0;

void setup() 
{
  // outputs:
  pinMode(led_red,OUTPUT);
  pinMode(led_yellow,OUTPUT);
  pinMode(led_green,OUTPUT);
  
  // input:
  pinMode(button, INPUT);
}

void loop() {
  /*verifica o estado do botão*/
  buttonState = digitalRead(button);

  /*se o botão foi pressionado, a ordem do semáforo é feita*/
  if(buttonState == HIGH){
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, HIGH);
    digitalWrite(led_green, LOW);
    delay(time_yellow); 

    digitalWrite(led_yellow, LOW);
    digitalWrite(led_red, HIGH);
    delay(time_red);

    digitalWrite(led_green, HIGH);
    digitalWrite(led_red, LOW);
    delay(time_green);

    /*no final de tudo, o estado é alterado*/
    buttonState=LOW;
  }
  
  /*caso o contrário, a luz verde irá permanecer acesa*/
  else{
    digitalWrite(led_green, HIGH);
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
  }
}
