  int vSpeed = 150;        // MAX 255
  int turn_speed = 90;    // MAX 255 


  //L293 Connection   
  const int motorA1      = 12;  // leftback
  const int motorA2      = 11; // leftforw
  const int motorAspeed  = 13;  // left speed
  const int motorB1      = 10; // rightback
  const int motorB2      = 9; // rightforw
  const int motorBspeed  = 8; // rightspeed


  //Sensor Connection
  const int left_sensor_pin =A0;
  const int right_sensor_pin =A1;

  const int turn_left_pin =A2;
  const int turn_right_pin =A3;
  
  int left_sensor_state;
  int right_sensor_state;

  int turn_left;
  int turn_right;

  int mov;


  
void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(left_sensor_pin, INPUT);
  pinMode(right_sensor_pin, INPUT);
  pinMode(turn_right_pin, INPUT);
  pinMode(turn_left_pin, INPUT);

  Serial.begin(9600);

  delay(3000);
  
}

void loop() 
{
  left_sensor_state=analogRead(left_sensor_pin);
  right_sensor_state=analogRead(right_sensor_pin);
  turn_left=analogRead(turn_left_pin);
  turn_right=analogRead(turn_right_pin);
  
  start_to_stop();
    
}

//forward function


void forward ()
{
  

  if(right_sensor_state > 500 && left_sensor_state < 500)
  {
    Serial.println("turning LEFT");
    Serial.println(right_sensor_state);
  
  
    analogWrite (motorAspeed, vSpeed);
    analogWrite (motorBspeed, turn_speed);
    
    }
  if(right_sensor_state < 500 && left_sensor_state > 500)
  {
    Serial.println("turning RIGHT");
    Serial.println(right_sensor_state);
    
  
    analogWrite (motorBspeed, vSpeed);
    analogWrite (motorAspeed, turn_speed);
  
   
    }
  
  if(right_sensor_state > 500 && left_sensor_state > 500)
  {
    Serial.println("going forward");
  
    digitalWrite (motorA1,LOW);
    digitalWrite (motorA2,HIGH);                       
    digitalWrite (motorB2,HIGH);
    digitalWrite (motorB1,LOW);
  
    analogWrite (motorAspeed, vSpeed);
    analogWrite (motorBspeed, vSpeed);
  
  
    
    }
    if(right_sensor_state < 500 && left_sensor_state < 500)
    {
    Serial.println("stopppppppppppppp");
    
    analogWrite (motorAspeed, 0);
    analogWrite (motorBspeed, 0);
    
    }  
}


//left function
void botleft()    // turning left 90 degree
{

  Serial.println(turn_left);
  turn_left = analogRead(turn_left_pin);
  
  

  Serial.println("turning left 90 degree");
  Serial.println(turn_left);

    while(mov!=100){
    forward();
    mov=mov+1;
  }
  mov=0;
  
  
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);

  delay(1200);

  Serial.println("stop");
  
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);

  delay(1000);


}
//right function

void botright()    // turning left 90 degree
{

  Serial.println(turn_right);
  turn_right = analogRead(turn_right_pin);
  

  Serial.println("turning right 90 degree");
  Serial.println(turn_right);

    while(mov!=100){
    forward();
    mov=mov+1;
  }
  mov=0;
  
  
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);

  delay(1300);

  Serial.println("stop");
  
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);

  delay(1000);


}

//stop function

void botstop()
{

  Serial.println("stop");
  
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);

  digitalWrite (motorA1,LOW);
  digitalWrite (motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite (motorB2,LOW);
   
} 


// start to stop function

void start_to_stop()
{
Serial.println(" bot started to move");
forward();
  
if(turn_left < 500)
{
    botleft();
}

if(turn_right < 500)
{
   botright();
 }

if(right_sensor_state < 500 && left_sensor_state < 500)
{ 
 botstop();
    
}
}
