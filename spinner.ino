
#define ENABLE 5
#define DIRA 3
#define DIRB 4
#define BUTTON 7

int motor_speed = 150;
int button_state = 0;
int random_time;
int time_multiplier = 150;

 
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode (BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop () {
  //spin on button press
 
button_state = digitalRead(BUTTON);  //check state of button

if (button_state == LOW) {           //inverted due to input pullup, when button is pressed begin action
  digitalWrite(ENABLE,HIGH); //turns motor on
  analogWrite(ENABLE,motor_speed);  //set motor speed
  random_time = random(5,20) * time_multiplier ;   //generates random number between 5-20 and multiplies it by time multiplier to be used for the delay time
    digitalWrite(DIRA,HIGH); // starts motor spinning
    digitalWrite(DIRB,LOW);  //starts motor spinning
    delay(random_time);             //uses random number generated to dictate spin time
    digitalWrite(ENABLE,LOW);  // turns motor off
   
  }
 
}
 
    
