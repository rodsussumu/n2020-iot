#define pir 10

String leStringSerial() {
  String conteudo = "";
  char caractere;
 
  while (Serial.available() > 0) {
    caractere = Serial.read();
    if (caractere != '\n') {
      conteudo.concat(caractere);
    }
    delay(10);
  }
 
  Serial.print("Recebi: ");
  Serial.println(conteudo);
 
  return conteudo;
}

int botao = 2;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(pir, INPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  if (Serial.available() > 0) {
    if (leStringSerial()== "new") {
      for(int i = 0; i <= 999; i++){
        tone(7, 220, 100);
        delay(200);
       	digitalWrite(13, HIGH);
        delay(500);
        digitalWrite(13, LOW);
        delay(500);
        if(digitalRead(botao) == 1){
         i = 999;
        }
        if(digitalRead(pir) == HIGH){
         i = 999;
        }
        Serial.print(i);
      }
    } else {
      digitalWrite(13, LOW);
    }
  }
  
}