/*defining the device pins*/
const int trigPin = 11;
const int echoPin = 12;

/* defining the led pins*/
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;

long duration;
int distanceInCm, distanceInInch;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(sender, OUTPUT);
  pinMode(reciever, INPUT);
  
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);  
}

void loop() 
{
  digitalWrite(sender, LOW);
  delayMicroseconds(2 );


  digitalWrite(sender, HIGH);
  delayMicroseconds(10);
  digitalWrite(sender, LOW);

  duration = pulseIn(reciever, HIGH);

  distanceInCm = duration*0.034/2;
  distanceInInch = duration*0.0133/2;

  Serial.print("Distance in CM: ");
  Serial.println(distanceInCm);
  Serial.println(" ");
  Serial.print("Distance in INCH: ");
  Serial.println(distanceInInch);
  Serial.println(" ");  

  if(distanceInCm <= 20)
  {  
    digitalWrite(led1, LOW); 
   digitalWrite(led2, LOW);  
    digitalWrite(led3, HIGH); 
  }

  else if(distanceInCm <= 40)
  {
    digitalWrite(led1, LOW);   
    digitalWrite(led2, HIGH);  
    digitalWrite(led3, LOW);   
  }
  else /*if distance in cm is > 40*/
  {
    digitalWrite(led1, HIGH);    
    digitalWrite(led2, LOW);  
    digitalWrite(led3, LOW);   
  }
}
