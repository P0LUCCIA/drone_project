#include <Servo.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Servo moter0; // 모터 0번
Servo moter1; // 모터 1번
Servo moter2; // 모터 2번
Servo moter3; // 모터 3번
Adafruit_MPU6050 mpu; // MPU 6050

int moter0_speed = 0; // 모터 0번의 속도
int moter1_speed = 0; // 모터 1번의 속도
int moter2_speed = 0; // 모터 2번의 속도
int moter3_speed = 0; // 모터 3번의 속도

int init_moter(){
  moter0.attach(0); // 0 port 연결
  moter0.write(moter0_speed); // 모터 3번 초기 속도 설정

  moter1.attach(1); // 1 port 연결
  moter1.write(moter1_speed); // 모터 3번 초기 속도 설정

  moter2.attach(2); // 2 port 연결
  moter2.write(moter2_speed); // 모터 3번 초기 속도 설정

  moter3.attach(3); // 3 port 연결
  moter3.write(moter3_speed); // 모터 3번 초기 속도 설정
  
}

int init_mpu(){
  
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip"); // MPU 연결이 되지 않았을 경우 log
    while (1) {
      delay(10);
    }
  }
  
  Serial.println("MPU6050 Found!"); // MPU가 연결 되었을 경우 log
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G); // 가속도계 오차범위 ±8G로 설정
  mpu.setGyroRange(MPU6050_RANGE_500_DEG); // 자이로 오차범위를 ±500deg/s로 설정
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ); // 필터 대역폭을 ±21Hz로 설정
  
}

int print_mpu_log(){
  
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  /* Print out the readings */
  Serial.print("가속도 X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");
  Serial.print("회전 X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");
  Serial.print("오차 범위: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");
  Serial.println("");
  
}
void setup() {

  Serial.begin(9600);
  init_moter();
  init_mpu();
  delay(3000);                        

}

void loop() {
  print_mpu_log();
  delay(2000);
}
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial HC06(10,11); // RX, TX

Servo moter1;
Servo moter2;
Servo moter3;
Servo moter4;

int moter1_speed=0;
int moter2_speed=0;
int moter3_speed=0;
int moter4_speed=0;
int input;

void setup() {

  Serial.begin(9600);
  HC06.begin(9600);
  moter1.attach(6, 1000, 2000);//(escPin, minPulseRate, maxPulseRate)
  moter1.write(moter1_speed); // moter1 초기 속도 설정
 
  moter2.attach(7, 1000, 2000);//(escPin, minPulseRate, maxPulseRate)
  moter2.write(moter2_speed); // moter2 초기 속도 설정
 
  moter3.attach(8, 1000, 2000);//(escPin, minPulseRate, maxPulseRate)
  moter3.write(moter3_speed); // moter3 초기 속도 설정  
 
  moter4.attach(9, 1000, 2000);//(escPin, minPulseRate, maxPulseRate)
  moter4.write(moter4_speed); // moter4 초기 속도 설정
}

void loop() { // run over and over  
    if (HC06.available()) {
      input = HC06.read();    
      if(input=='u'){ // 'u'
        Serial.println('u');
        moter4_speed+=20;
      }else if(input=='d'){ // 'd'
        Serial.println('d');
        moter4_speed-=20;
      }
      Serial.write("\n[moter speed] : ");
      Serial.println(moter4_speed);
      moter4.write(moter4_speed);
  }
  if (Serial.available()) {
    HC06.write(Serial.read());
  }
}  
