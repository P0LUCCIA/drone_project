#include <Servo.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Servo moter0;
Servo moter1;
Servo moter2;
Servo moter3;
Adafruit_MPU6050 mpu;

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

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!"); // MPU가 있을 경우 연결 확인 print가 뜸
  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  delay(3000);                        

}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  /* Print out the readings */
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");
  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");
  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");
  Serial.println("");
  delay(500);
}
