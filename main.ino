#include <Servo.h>
#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial HC06(10, 11);

#define DEBUG_LOG(data) Serial.println(data)
#define moter1 top_left_moter // 왼쪽 위 모터
#define moter2 below_left_moter // 왼쪽 아래 모터
#define moter3 top_right_moter // 오른쪽 위 모터 
#define moter4 below_right_moter // 오른쪽 아래 모터
#define moter1_speed top_left_speed // 왼쪽 위 모터 속도
#define moter2_speed below_left_speed // 왼쪽 아래 모터 속도
#define moter3_speed top_right_speed // 오른쪽 위 모터 속도
#define moter4_speed below_right_speed // 오른쪽 아래 모터 속도
/*
* 블루투스에 읽을 수 있는 데이터가 있는지 확인
* returns 데이터가 있을 경우 1, 없을 경우 0을 반환
*/
#define Bluetooth_data_check HC06.available() 
/*
* 블루투스에서 데이터를 읽어옴
* returns 블루투스에서 읽은 데이터를 반환
*/
#define Bluetooth_read HC06.read() 

Servo top_left_moter;
Servo below_left_moter;
Servo top_right_moter;
Servo below_right_moter;
int top_left_speed = 0, below_left_speed = 0, top_right_speed = 0, below_right_speed = 0,input;

/**
 * 드론의 모터 초기 설정
*/
void init_moter() {
	moter1.attach(6, 1000, 2000); //  6번핀의 펄스 폭을 0.001ms ~ 0.002ms으로 제한
	moter1.write(moter1_speed); // 0으로 moter1의 속도 설정
	delay(3000); // 3초 지연

	moter2.attach(7, 1000, 2000); // 7번핀의 펄스 폭을 0.001ms ~ 0.002ms으로 제한
	moter2.write(moter2_speed); // 0으로 moter2의 속도 설정
	delay(3000); // 3초 지연

	moter3.attach(8, 1000, 2000); // 8번핀의 펄스 폭을 0.001ms ~ 0.002ms으로 제한
	moter3.write(moter3_speed); // 0으로 moter3의 속도 설정
	delay(3000); // 3초 지연

	moter4.attach(9, 1000, 2000); // 9번핀의 펄스 폭을 0.001ms ~ 0.002ms으로 제한
	moter4.write(moter4_speed); // 0으로 moter4의 속도 설정
	delay(3000); // 3초 지연
}
/*
 * z좌표의 위치를 증가시킴
*/
void z_up() {
	moter1_speed += 20;
	moter2_speed += 20;
	moter3_speed += 20;
	moter4_speed += 20;
	moter1.write(moter1_speed);
	moter2.write(moter2_speed);
	moter3.write(moter3_speed);
	moter4.write(moter4_speed);
}
/*
 * z좌표의 위치를 감소시킴
*/
void z_down() {
	moter1_speed -= 20;
	moter2_speed -= 20;
	moter3_speed -= 20;
	moter4_speed -= 20;
	moter1.write(moter1_speed);
	moter2.write(moter2_speed);
	moter3.write(moter3_speed);
	moter4.write(moter4_speed);
}
void setup() {
	Serial.begin(9600); // 디버깅을 하기위해 데이터 전송 속도를 9600으로 설정함
	HC06.begin(9600); // 블루투스 데이터 전송 속도를 9600으로 설정함
	init_moter(); // 드론 모터 초기 설정
}
void loop() {
	if (Bluetooth_data_check) {
		input = Bluetooth_read;
		if (input == 'u') {
			DEBUG_LOG('u');
			z_up();
		}
		else if (input == 'd') {
			DEBUG_LOG('d');
			z_down();
		}
	}
}
