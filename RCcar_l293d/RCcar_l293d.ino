#define MLF1 A0
#define MLF2 A1
#define MRF1 A2
#define MRF2 A3
#define MLB1 A4
#define MLB2 A5
#define MRB1 A6
#define MRB2 A7
#define EN11 3
#define EN12 4
#define EN21 5
#define EN22 6

#define ch1 A9
#define ch2 A8
#define ch5 A10

void setup() {
  // put your setup code here, to run once:
 pinMode(MLF1, OUTPUT);
 pinMode(MLF2, OUTPUT);
 pinMode(MRF1, OUTPUT);
 pinMode(MRF2, OUTPUT);
 pinMode(MLB1, OUTPUT);
 pinMode(MLB2, OUTPUT);
 pinMode(MRB1, OUTPUT);
 pinMode(MRB2, OUTPUT);
 pinMode(EN11, OUTPUT);
 pinMode(EN12, OUTPUT);
 pinMode(EN21, OUTPUT);
 pinMode(EN22, OUTPUT);
 Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
 char a;
 int s;
 int Channel1 = (pulseIn (ch1, HIGH));  // Checks the value of channel1
 int Channel2 = (pulseIn (ch2, HIGH));
 int Channel5 = (pulseIn (ch5, HIGH));
 s = Channel5;
 stopup();
 
 if (Channel1 > 1500)
 {
  Serial.println(s);
  forward(s);
  Serial.println("forward");
 }
 if (Channel1 < 1300) 
 {
  backward(s);
  Serial.println(s);
  Serial.println("backward");
 }
 if (Channel2 > 1500)
 {
  left(s);
  Serial.println(s);
  Serial.println("left");
 }
 if(Channel2 < 1300)
 {
  right(s);
  Serial.println(s);
  Serial.println("right");
 }
 
}

void backward(int a)
{digitalWrite(EN11, 1);
 digitalWrite(EN12, 1);
 digitalWrite(EN21, 1);
 digitalWrite(EN22, 1);
 digitalWrite(MLF1, 0);
 digitalWrite(MLF2, a);
 digitalWrite(MRF1, 0);
 digitalWrite(MRF2, a);
 digitalWrite(MLB1, 0);
 digitalWrite(MLB2, a);
 digitalWrite(MRB1, 0);
 digitalWrite(MRB2, a);
}

void forward(int a)
{digitalWrite(EN11, 1);
 digitalWrite(EN12, 1);
 digitalWrite(EN21, 1);
 digitalWrite(EN22, 1);
 digitalWrite(MLF1, a);
 digitalWrite(MLF2, 0);
 digitalWrite(MRF1, a);
 digitalWrite(MRF2, 0);
 digitalWrite(MLB1, a);
 digitalWrite(MLB2, 0);
 digitalWrite(MRB1, a);
 digitalWrite(MRB2, 0);
}

void left(int a)
{digitalWrite(EN11, 1);
 digitalWrite(EN12, 1);
 digitalWrite(EN21, 1);
 digitalWrite(EN22, 1);
 digitalWrite(MLF1, a);
 digitalWrite(MLF2, 0);
 digitalWrite(MRF1, 0);
 digitalWrite(MRF2, a);
 digitalWrite(MLB1, a);
 digitalWrite(MLB2, 0);
 digitalWrite(MRB1, 0);
 digitalWrite(MRB2, a);
}

void right(int a)
{digitalWrite(EN11, 1);
 digitalWrite(EN12, 1);
 digitalWrite(EN21, 1);
 digitalWrite(EN22, 1);
 digitalWrite(MLF1, 0);
 digitalWrite(MLF2, a);
 digitalWrite(MRF1, a);
 digitalWrite(MRF2, 0);
 digitalWrite(MLB1, 0);
 digitalWrite(MLB2, a);
 digitalWrite(MRB1, a);
 digitalWrite(MRB2, 0);
}

void frontBrake(int a)
{digitalWrite(EN11, 0);
 digitalWrite(EN12, 0);
 digitalWrite(EN21, 1);
 digitalWrite(EN22, 1);
 digitalWrite(MLF1, 1);
 digitalWrite(MLF2, 0);
 digitalWrite(MRF1, 1);
 digitalWrite(MRF2, 0);
 digitalWrite(MLB1, 1);
 digitalWrite(MLB2, 0);
 digitalWrite(MRB1, 1);
 digitalWrite(MRB2, 0);
}

void backBrake(int a)
{digitalWrite(EN11, 1);
 digitalWrite(EN12, 1);
 digitalWrite(EN21, 0);
 digitalWrite(EN22, 0);
 digitalWrite(MLF1, 1);
 digitalWrite(MLF2, 0);
 digitalWrite(MRF1, 1);
 digitalWrite(MRF2, 0);
 digitalWrite(MLB1, 0);
 digitalWrite(MLB2, 0);
 digitalWrite(MRB1, 0);
 digitalWrite(MRB2, 0);
}

void stopup()
{digitalWrite(EN11, 0);
 digitalWrite(EN12, 0);
 digitalWrite(EN21, 0);
 digitalWrite(EN22, 0);
}
