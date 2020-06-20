#define dirA 3
#define brkA 4
#define pwA 10
#define dirB 8
#define brkB 9
#define pwB 11


void setup() {
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  
  //digitalWrite(dirA, LOW);
  //analogWrite(pwA, 50);
  //digitalWrite(dirB, HIGH);
  //analogWrite(pwB, 50);
  //digitalWrite(brkA, LOW);
  //digitalWrite(brkB, LOW);
  Serial.begin(38400);
}

void forward()
{ digitalWrite(dirA, LOW);
  analogWrite(pwA, 50);
  digitalWrite(dirB, LOW);
  analogWrite(pwB, 50);
  digitalWrite(brkA, LOW);
  digitalWrite(brkB, LOW);
}

void backward()
{ digitalWrite(dirA, HIGH);
  analogWrite(pwA, 50);
  digitalWrite(dirB, HIGH);
  analogWrite(pwB, 50);
  digitalWrite(brkA, LOW);
  digitalWrite(brkB, LOW);
}

void left()
{ digitalWrite(dirA, HIGH);
  analogWrite(pwA, 50);
  digitalWrite(dirB, LOW);
  analogWrite(pwB, 50);
  digitalWrite(brkA, LOW);
  digitalWrite(brkB, LOW);
}

void right()
{ digitalWrite(dirA, LOW);
  analogWrite(pwA, 50);
  digitalWrite(dirB, HIGH);
  analogWrite(pwB, 50);
  digitalWrite(brkA, LOW);
  digitalWrite(brkB, LOW);
}

void brake()
{digitalWrite(dirA, LOW);
 analogWrite(pwA, 0);
 digitalWrite(dirB, LOW);
 analogWrite(pwB, 0);
 digitalWrite(brkA, HIGH);
 digitalWrite(brkB, HIGH);
}

void loop() {
  
if(Serial.available())
 {
  char m = Serial.read();
  //Serial.println(m);
  switch(m)
  {
   case 'F': forward();
             Serial.println("F");
             break;
   case 'B': backward();
             Serial.println("B");
             break;
   case 'L': left();
             Serial.println("L");
             break;
   case 'R': right();
             Serial.println("R");
             break;
   default: brake();
            Serial.println("S");                                                
            break;
  }
 }
}
