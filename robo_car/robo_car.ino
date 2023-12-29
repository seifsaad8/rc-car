#include <SoftwareSerial.h>
//the motor control pins
#define motor1a 8
#define motor1b 7 
#define motor2a 9
#define motor2b 10

//the bluetooth pins
char val;
SoftwareSerial bluetoothSerial(6, 5); // RX, TX

void setup() 
{  
  //defining the motor pins
  pinMode(motor1a, OUTPUT);  
  pinMode(motor1b, OUTPUT);  
  pinMode(motor2a, OUTPUT); 
  pinMode(motor2b, OUTPUT); 
  bluetoothSerial.begin(9600);
}

void loop()
{
  while (bluetoothSerial.available() > 0)
  {
    val = bluetoothSerial.read();
  }
   switch (val) 
   {
    // Forward
    case 'F':
          FORWARD();     
          break;

    // Backward     
    case 'B':
          BACKWARD();
          break;

    //left done
    case 'L':
          LEFT();
          break;

    //right done
    case 'R':
        RIGHT();
        break;

    //Stop
    case 'S':
        STOP();
        break;

    //Forward Right 
    case 'I':
        FORWARDRIGHT();
        break;

    //Backward Right 
    case 'J':
        BACKWARDRIGHT();
        break;

    //Forward Left 
    case 'G':
        FORWARDLEFT();
        break;

    //Backward Left 
    case 'H':
        BACKWARDLEFT();
        break;

    }
}
void FORWARD()
  {
     digitalWrite(motor1b, LOW);
     digitalWrite(motor1a, HIGH);
     digitalWrite(motor2b, LOW);
     digitalWrite(motor2a, HIGH); 
  }
void BACKWARD()
  {
      digitalWrite(motor1b, HIGH);
      digitalWrite(motor1a, LOW);
      digitalWrite(motor2b, HIGH);
      digitalWrite(motor2a, LOW); 
  }
  

void LEFT()
{
    digitalWrite(motor1b, LOW);
    digitalWrite(motor1a, HIGH);
    digitalWrite(motor2b, HIGH);    
    digitalWrite(motor2a, LOW);      
}
void RIGHT()
{
    digitalWrite(motor1b, HIGH);
    digitalWrite(motor1a, LOW);
    digitalWrite(motor2b, LOW);
    digitalWrite(motor2a, HIGH);
}

void STOP()
{
    digitalWrite(motor1b, LOW);
    digitalWrite(motor1a, LOW);
    digitalWrite(motor2b, LOW);
    digitalWrite(motor2a, LOW); 
}

void FORWARDLEFT()
{
    analogWrite(motor1b, LOW);
    analogWrite(motor1a, HIGH);
    analogWrite(motor2b, low);
    analogWrite(motor2a, LOW);
 }

void FORWARDRIGHT()
{
    analogWrite(motor1b, LOW);
    analogWrite(motor1a, LOW);
    analogWrite(motor2b, LOW);
    analogWrite(motor2a, HIGH);
}

void BACKWARDRIGHT()
{
    analogWrite(motor1b, LOW);
    analogWrite(motor1a, LOW);
    analogWrite(motor2b, HIGH);
    analogWrite(motor2a, LOW);
}

void BACKWARDLEFT()
{
    analogWrite(motor1b, HIGH);
    analogWrite(motor1a, LOW);
    analogWrite(motor2b, LOW);
    analogWrite(motor2a, LOW);
}

