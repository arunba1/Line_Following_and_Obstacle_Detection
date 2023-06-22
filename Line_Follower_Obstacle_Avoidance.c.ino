#define LS 11      // left sensor
#define RS 12     // right sensor
#define LM1 4       // left motor
#define LM2 5       // left motor
#define RM1 7       // right motor
#define RM2 8       // right motor
#define EN1 3
#define EN2 9
int buzz =13;

int trig = 6;
int echo = 2;
long dur;
float dist=0;

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, HIGH);
  Serial.begin(9600);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

void loop()
{
  //setting trigpin
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  //distance
  dur=pulseIn(echo,HIGH);
  dist=dur*0.0117;
  Serial.println(dist);
  
  if(dist <5.0)
  {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, LOW);
      delay(1000);
      digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  //distance
  dur=pulseIn(echo,HIGH);
  dist=dur*0.0117;
  Serial.println(dist);
  if (dist <5){
    digitalWrite(buzz,HIGH);
  }
      
  }
  else
  {
    if(!(digitalRead(LS)) && (!(digitalRead(RS))))     // Move Forward
    {
          digitalWrite(buzz,LOW);

      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
      Serial.println(digitalRead(LS));
            Serial.println(digitalRead(RS));


    }
    else if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
    {
                digitalWrite(buzz,LOW);

      digitalWrite(LM1, LOW);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
        Serial.println(digitalRead(LS));
            Serial.println(digitalRead(RS));
    }
    else if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
    {
                digitalWrite(buzz,LOW);

      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, LOW);
       Serial.println(digitalRead(LS));
            Serial.println(digitalRead(RS));
    }
  }
}
