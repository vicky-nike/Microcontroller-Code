const int xpin = A3;                  
const int ypin = A2;                  
const int zpin = A1;  
int x, y;


void setup() 
{ Serial.begin(9600);

}

void loop() 
{ x=analogRead(xpin);
  y=analogRead(ypin);
  Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  // print a tab between values:
  Serial.print("\t");
  Serial.println();
  // delay before next reading:
  delay(100);

}
