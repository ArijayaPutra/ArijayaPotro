#define rcPin1 10   // Pin 8 Connected to CH1 of Transmitter;
#define rcPin2 9   // Pin 9 Connected to CH2

#define RPWM_1 5
#define LPWM_1 3
#define R_EN_1 4
#define L_EN_1 2
#define RPWM_2 9
#define LPWM_2 6
#define R_EN_2 8
#define L_EN_2 7

int ch1 = 0;  // Receiver Channel 1 PPM value
int ch2 = 0;  // Receiver Channel 2 PPM value

void setup() {
  pinMode(rcPin1, INPUT);
  pinMode(rcPin2, INPUT);
  pinMode(3,OUTPUT);
  pinMode(RPWM_1,OUTPUT);
  pinMode(RPWM_2,OUTPUT);
  pinMode(LPWM_1,OUTPUT);
  pinMode(LPWM_2,OUTPUT);
  pinMode(R_EN_1,OUTPUT);
  pinMode(R_EN_2,OUTPUT);
  pinMode(L_EN_1,OUTPUT);
  pinMode(L_EN_2,OUTPUT);
  Serial.begin(9600);
}

void loop() {

// Read in the length of the signal in microseconds
  ch1 = pulseIn(rcPin1, HIGH, 25000);  // (Pin, State, Timeout)
  ch2 = pulseIn(rcPin2, HIGH, 25000);

  Serial.print("Channel #1: ");
  Serial.println(ch1);

  
  if(ch1>1800){    
    digitalWrite(R_EN_1,HIGH);
  digitalWrite(L_EN_1,HIGH);
  digitalWrite(L_EN_2,HIGH);
  digitalWrite(R_EN_2,HIGH);
  digitalWrite(RPWM_1,HIGH);
  digitalWrite(RPWM_2,HIGH); 
  }
  else{
     digitalWrite(RPWM_1,LOW);
  digitalWrite(RPWM_2,LOW); 
  }
  
  Serial.print("Channel #2: ");
  Serial.println(ch2); 
  Serial.println("------------");
  delay(500);
  
// Clear screen and move cursor Home, only works in PUTTY
  Serial.write(27);       // ESC command
  Serial.print("[2J");    // clear screen command
  Serial.write(27);
  Serial.print("[H");     // cursor to home command
}
