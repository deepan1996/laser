
//#include <Sim800l.h>
#include <Wire.h>
#include <MPU6050.h>



#include <SoftwareSerial.h>
static const uint32_t  GPSBaud = 9600;
SoftwareSerial mySerial(9, 10);
MPU6050 mpu;


unsigned long timer = 0;
float timeStep = 0.01;

// Pitch, Roll and Yaw values
float pitch = 0;
float roll = 0;
float yaw = 0;
float temp =0;

void setup() {
  // put your setup code here, to run once:
mySerial.begin(GPSBaud);
Serial.begin(9600);
pinMode(8,OUTPUT);
pinMode(2, INPUT);
pinMode(3, INPUT);
pinMode(13, OUTPUT);
digitalWrite(13,HIGH);
pinMode(12,OUTPUT);
 while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  
  // Calibrate gyroscope. The calibration must be at rest.
  // If you don't want calibrate, comment this line.
  mpu.calibrateGyro();

  // Set threshold sensivty. Default 3.
  // If you don't want use threshold, comment this line or set 0.
  mpu.setThreshold(3);
}

void loop() {

  int a = digitalRead(2);
  Serial.println(a);
   int b = digitalRead(3);
  Serial.print(b);
   timer = millis();

  // Read normalized values
  Vector norm = mpu.readNormalizeGyro();
  temp = mpu.readTemperature();
  // Calculate Pitch, Roll and Yaw
  pitch = pitch + norm.YAxis * timeStep;
  roll = roll + norm.XAxis * timeStep;
  yaw = yaw + norm.ZAxis * timeStep;

  // Output raw
/*  Serial.print(" Pitch = ");
  Serial.print(pitch);
  Serial.print(" Roll = ");
  Serial.print(roll);  
  Serial.print(" Yaw = ");
  Serial.println(yaw);
  Serial.println(" Temperature = ");
  Serial.print(temp);
  delay(500);*/
  //delay((timeStep*1000) - (millis() - timer));
if(pitch!=0 || roll!=0 || yaw!=0)
{

 spinum();
 //Serial.println("message has sent");
 delay(1000);
  //mpu.calibrateGyro();
  pitch=0;
  roll=0;
  yaw=0;
  
}
  
  
 if(a==1 && b==1){

    //digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(12,HIGH);
  delay(2000);
  digitalWrite(12,LOW);
  num1();
  delay(5000);
   num2();
  delay(5000);
   num3();
  delay(5000);
   num4();
  delay(5000);
  num5();
  delay(5000);
   num6();
  } 
  else
  {
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
  }
}


void num1(){
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919994501591\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Pole interuption between  1 and 2");
  delay(1000);
   mySerial.println((char)26);// ASCII code of CTRL+Z
 // Serial.write(0x1A);
 // Serial.write(0x0D);
//  Serial.write(0x0A);
}

void num2(){
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919952280239\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Pole interruption between 1 and 2");
  delay(1000);
   mySerial.println((char)26);// ASCII code of CTRL+Z
 // Serial.write(0x1A);
 // Serial.write(0x0D);
//  Serial.write(0x0A);
}


void num3(){
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919442776641\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Pole interruption between 1 and 2");
  delay(1000);
   mySerial.println((char)26);// ASCII code of CTRL+Z
 // Serial.write(0x1A);
 // Serial.write(0x0D);
//  Serial.write(0x0A);
}

void num4(){
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918248167164\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Pole interruption between 1 and 2");
  delay(1000);
   mySerial.println((char)26);// ASCII code of CTRL+Z
 // Serial.write(0x1A);
 // Serial.write(0x0D);
//  Serial.write(0x0A);
}

void num5(){
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919943952740\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Pole interruption between 1 and 2");
  delay(1000);
   mySerial.println((char)26);// ASCII code of CTRL+Z
 // Serial.write(0x1A);
 // Serial.write(0x0D);
//  Serial.write(0x0A);
}

void num6(){
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919597210395\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Pole interruption between 1 and 2");
  delay(1000);
   mySerial.println((char)26);// ASCII code of CTRL+Z
 // Serial.write(0x1A);
 // Serial.write(0x0D);
//  Serial.write(0x0A);
}

void spinum(){

  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919994501591\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("pole falls due to some external factors. It may be an Elephant too");
  delay(1000);
   mySerial.println((char)26);// ASCII code of CTRL+Z
}

