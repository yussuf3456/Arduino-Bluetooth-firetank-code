int motor_A_Dir = 12; //Direction pin for left motor HIGH is clockwise LOW is counter clockwise
int motor_A_speed = 3; //Speed PWM pin for left motor
int motor_A_brake = 9;  //Brake pin for left motor, HIGH is brake activated LOW is brake deactivated

int motor_B_Dir = 13; //Direction pin for right motor HIGH is clockwise LOW is counter clockwise
int motor_B_speed = 11; //Speed PWM pin for right motor
int motor_B_brake = 8; //Brake pin for right motor, HIGH is brake activated LOW is brake deactivated

int shootPin = 6; //Pump pin

char bt='S'; //Bluetooth character reciving pin

void setup(){  
  Serial.begin(9600); 

  pinMode(motor_A_Dir, OUTPUT);
  pinMode(motor_A_brake, OUTPUT);
  pinMode(motor_A_speed, OUTPUT);

  pinMode(motor_B_Dir, OUTPUT);
  pinMode(motor_B_speed, OUTPUT);
  pinMode(motor_B_brake, OUTPUT);

  pinMode(shootPin, OUTPUT);

  digitalWrite(shootPin, LOW);
}

void Forward(){
  Serial.print("fwd");
  digitalWrite(motor_A_Dir, HIGH);
  digitalWrite(motor_A_brake, LOW);
  analogWrite(motor_A_speed, 230);

  digitalWrite(motor_B_Dir, LOW);
  digitalWrite(motor_B_brake, LOW);
  analogWrite(motor_B_speed, 230);
}

void Backward(){
  Serial.print("back");
  digitalWrite(motor_A_Dir, LOW);
  digitalWrite(motor_A_brake, LOW);
  analogWrite(motor_A_speed, 230);

  digitalWrite(motor_B_Dir, HIGH);
  digitalWrite(motor_B_brake, LOW);
  analogWrite(motor_B_speed, 230);
}

void Left(){
  Serial.print("left");
  digitalWrite(motor_A_Dir, HIGH);
  digitalWrite(motor_A_brake, LOW);
  analogWrite(motor_A_speed, 230);

  digitalWrite(motor_B_Dir, HIGH);
  digitalWrite(motor_B_brake, LOW);
  analogWrite(motor_B_speed, 230);
}

void Right(){
  Serial.print("right");
  digitalWrite(motor_A_Dir, LOW);
  digitalWrite(motor_A_brake, LOW);
  analogWrite(motor_A_speed, 230);

  digitalWrite(motor_B_Dir, LOW);
  digitalWrite(motor_B_brake, LOW);
  analogWrite(motor_B_speed, 230);
}

void Stop(){
  digitalWrite(motor_A_Dir, HIGH);
  digitalWrite(motor_A_brake, HIGH);
  analogWrite(motor_A_speed, 0);

  digitalWrite(motor_B_Dir, LOW);
  digitalWrite(motor_B_brake, HIGH);
  analogWrite(motor_B_speed, 0);
}

void Shoot(){
  digitalWrite(shootPin, HIGH);
}

void StopShoot(){
  digitalWrite(shootPin, LOW);
}



void loop() {
  if(Serial.available() > 0)  {
    bt=Serial.read(); // reads serial input from BT

    Serial.print(bt);        // for debugging uncommment this line
    Serial.print("\n"); 

    if(bt=='f'|| bt=='F'){ //F is sent when up is pressed on the app
      Forward(); 
    }
    if(bt=='b'|| bt=='B'){ //B is sent when down is pressed on the app
      Backward(); 
    }
    if(bt=='L'|| bt=='l'){ //L is sent when left is pressed on the app
      Left(); 
    }
    if(bt=='R'|| bt=='r'){ //R is sent when up is right on the app
      Right(); 
    }
    if(bt=='S'){ //S is sent when no button is pressed on the app
      Stop(); 
    }
    if(bt=='j'||bt=='J'){ //J is sent when more then 2 buttons are pressed at once
      Stop(); 
    }
    if(bt == 'W'){ //W is sent when the pump button is pressed on the app
      Shoot();
    }
    if(bt == 'w'){ //W is sent when the pump button is deactivated on the app
      StopShoot();
    }
  }
}