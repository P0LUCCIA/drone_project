#include <Servo.h>
#include <MPU6050.h>
#include <Wire.h>

Servo moter0;
Servo moter1;
Servo moter2;
Servo moter3;
MPU6050 gyro;

int moter0_speed = 0;
int moter1_speed = 0;
int moter2_speed = 0;
int moter3_speed = 0;

void setup() {

  Serial.begin(9600);

  // moter0 BEGIN INIT
  moter0.attach(0);
  moter0.write(moter0_speed);
  // moter0 END INIT

  // moter1 BEGIN INIT
  moter1.attach(1);
  moter1.write(moter1_speed);
  // moter1 END INIT

  // moter2 BEGIN INIT
  moter2.attach(2);
  moter2.write(moter2_speed);
  // moter2 END INIT

  // moter3 BEGIN INIT
  moter3.attach(3);
  moter3.write(moter3_speed);
  // moter3 END INIT

  delay(3000);                        

}

void loop() {
  
}

// https://m.blog.naver.com/scw0531/221276680031 Gryo
