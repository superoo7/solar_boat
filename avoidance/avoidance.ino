// Ultrasonic
long rightSensor,frontSensor,leftSensor;
// right
#define trigPin1 3
#define echoPin1 2
// left
#define trigPin2 4
#define echoPin2 5
// front
#define trigPin3 46
#define echoPin3 8

// Motor
const int right1 =9 , right2=10, left1=11, left2=12;
int pins[4] = { right1, right2, left1, left2};

// function
// ultrasonic algorithm
long sonarSensorDistance(int trigPin,int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration/2) / 29.1;

  return distance;
}

// Motor direction
void stop(){
  digitalWrite(pins[0], LOW);
  digitalWrite(pins[1], LOW);
  digitalWrite(pins[2], LOW);
  digitalWrite(pins[3], LOW);
}

void forward(){
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[1], LOW);
  digitalWrite(pins[2], LOW);
  digitalWrite(pins[3], HIGH);
}

void reverse(){
  digitalWrite(pins[0], LOW);
  digitalWrite(pins[1], HIGH);
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[3], LOW);
}

void left(){
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[1], LOW);
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[3], LOW);
}

void right(){
  digitalWrite(pins[0], LOW);
  digitalWrite(pins[1], HIGH);
  digitalWrite(pins[2], LOW);
  digitalWrite(pins[3], HIGH);
}

// avoidance system
void avoidanceSystem(long right, long left, long front){
  long tresholdDistance = 30;  // 30cm threshold

  if (front <= tresholdDistance && right <= tresholdDistance && left <= tresholdDistance) {
    stop();
    Serial.println("MOTOR IS STOPPING!!!");
  } else if (front <= tresholdDistance) {
    reverse();
    Serial.println("MOTOR IS REVERSING");
  } else if (left <= tresholdDistance) {
    right();
    Serial.println("MOTOR IS TURNING LEFT");
  } else if (right <= tresholdDistance) {
    left();
    Serial.println("MOTOR IS TURNING RIGHT");
  } else {
    forward();
    Serial.println("FORWARDING");
  }
}


void setup() {
  Serial.begin(9600);
// Ultrasonic
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 pinMode(trigPin3, OUTPUT);
 pinMode(echoPin3, INPUT);

// Motor
 for (int i=0; i<4; i++) {
   pinMode(pins[i], OUTPUT);
 }
}

void loop() {
  // ultrasonic
  rightSensor = sonarSensorDistance(trigPin1, echoPin1);
  leftSensor = sonarSensorDistance(trigPin2, echoPin2);
  frontSensor = sonarSensorDistance(trigPin3, echoPin3);
  // print ultrasonic result
  Serial.println("Ultrasonic:");
  Serial.print(rightSensor);
  Serial.print(",");
  Serial.print(leftSensor);
  Serial.print(",");
  Serial.println(frontSensor);

  avoidanceSystem(rightSensor, leftSensor, frontSensor);

  delay(250);
}