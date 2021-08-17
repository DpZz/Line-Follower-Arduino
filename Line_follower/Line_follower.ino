int TRESH=80;
void setspeed(int Speed)
{
  analogWrite(9, Speed);
  analogWrite(10, Speed);
}

void moveforward()
{
 setspeed(45);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  
  }
void arcright()
{
  
  setspeed(40);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  }
  void arcleft()
{
  
  setspeed(40);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

  }

void spotright()
{
  
  setspeed(55);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);

  }
void spotleft()
{
  
  setspeed(55);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

  }


void Stop()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  }
   
void setup()
{
  
   pinMode(2,OUTPUT);
   pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
   pinMode(5,OUTPUT);
  Serial.begin(9600);
  }

void loop() {
  int L2=analogRead(A0);
  int L1=analogRead(A1);
  int C=analogRead(A2);
  int R1=analogRead(A3);
  int R2=analogRead(A4);

Serial.print("\n");  
Serial.print(L2);
Serial.print("\t");  
Serial.print(L1); 
Serial.print("\t");  
Serial.print(C); 
Serial.print("\t");
Serial.print(R1); 
Serial.print("\t");  
Serial.print(R2); 
Serial.print("\t");  

if(L2>TRESH && L1>TRESH && C>TRESH && R1>TRESH && R2>TRESH)//all 
{
 delay(200);
 Stop();
 Serial.print("stop"); 
  }
//  else if (L2<TRESH&&L1<TRESH&&C<TRESH&&R1<TRESH&&R2<TRESH)
//{
// arcleft();
// Serial.print("spotLEFT");
// delay(20); 
// }
else if (L2>TRESH&&L1>TRESH&&C>TRESH&&R1<TRESH&&R2<TRESH)//L1,L2,C
{
 spotleft();
 Serial.print("moveLEFT");
 delay(20); 
 }
else if (L2<TRESH&&L1<TRESH&&C>TRESH&&R1>TRESH&&R2>TRESH)//C,R1,R2
{
 spotright();
 Serial.print("moveRIGHT");
 delay(20); 
 }
else if (L2<TRESH&&L1>TRESH&&C>TRESH&&R1<TRESH&&R2<TRESH)//L1,C
{
 arcleft();
 Serial.print("moveLEFT");
 delay(20); 
 }
else if (L2<TRESH&&L1<TRESH&&C>TRESH&&R1>TRESH&&R2<TRESH)//C,R1
{
 arcright();
 Serial.print("moveRIGHT");
 delay(20); 
 }
 else if (L2>TRESH&&L1<TRESH&&C<TRESH&&R1<TRESH&&R2<TRESH)//L2
{
 spotleft();
 Serial.print("moveLEFT");
 delay(20); 
 }
else if (L2<TRESH&&L1<TRESH&&C<TRESH&&R1<TRESH&&R2>TRESH)//R2
{
 spotright();
 Serial.print("moveRIGHT");
 delay(20); 
 }
else if (L2<TRESH&&L1>TRESH&&C>TRESH&&R1>TRESH&&R2<TRESH)//L1,C,R1
{
 moveforward();
 Serial.print("moveRIGHT");
 delay(20); 
 }
else if (L2<TRESH&&L1<TRESH&&C>TRESH&&R1<TRESH&&R2<TRESH)//C
{
 moveforward();
 Serial.print("moveforwd");
 delay(20); 
 }
 else if (L2>TRESH&&L1>TRESH&&C<TRESH&&R1<TRESH&&R2<TRESH)//L2,L1
{
 spotleft();
 Serial.print("moveRIGHT");
 delay(20); 
 }
 else if (L2<TRESH&&L1<TRESH&&C<TRESH&&R1>TRESH&&R2>TRESH)//R1,R2
{
 spotright();
 Serial.print("moveRIGHT");
 delay(20); 
 }
 else if (L2<TRESH&&L1>TRESH&&C<TRESH&&R1<TRESH&&R2<TRESH)//L1
{
 arcleft();
 Serial.print("moveRIGHT");
 delay(20); 
 }
 else if (L2<TRESH&&L1<TRESH&&C<TRESH&&R1>TRESH&&R2<TRESH)//R1
{
 arcright();
 Serial.print("moveRIGHT");
 delay(20); 
 }
 

 }
