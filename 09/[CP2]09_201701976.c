#include <stdio.h>

int disp_menu(void);
void enter_park(int(*park_space)[2][5], int(*reserved)[10]);
void exit_park(int(*park_space)[2][5]);
void reserve_park(int(*park_space)[2][5], int(*reserved)[10]);
void print_park(int(*park_space)[2][5]);
void print_basement(int(*park_space)[2][5], int floor);
int check_reservation(int(*reserved)[10], int basement, int num);
int check_reserved_num(int(*reserved)[10], int car_num, int *floor, int *resv_num);
int find_space(int(*park_space)[2][5], int floor);

int main(void){
	
	/*
	//실습1
	int hour, min, sec;
	double getTime, calTime;

	printf("시간 입력 : ");
	scanf_s("%lf", &calTime);
	getTime = calTime;

	hour = (int)calTime;
	calTime -= hour;
	calTime *= 60.0;
	min = (int)calTime;
	calTime -= min;
	calTime *= 60.0;
	sec = (int)calTime;
	printf("%.2lf시간은 %d시간 %d분 %d초입니다.\n\n", getTime, hour, min, sec);
	*/


	
	//과제1
	int distance, speed, hou, mi; //거리, 속력, 시간, 분 을 저장할 int 선언
	double se, temp; //초, 계산한 시간을 저장할 double 선언

	printf("거리와 속력 입력 : ");
	scanf_s("%d %d", &distance, &speed);
	temp = (double)distance / speed; // 계산한 시간 = 거리 / 속력

	hou = (int)temp; // 전체 시간 temp(소수점까지 포함)에서 정수부분만 = hour
	temp -= hou;    //temp = 전체시간 - hour => 소수부분만 저장됨(분, 초 계산을 위해)
	temp *= 60.0; // 분 계산을 위해 temp * 60
	mi = (int)temp; //시간을 계산하고 남은 temp에서 정수부분만 = min
	temp -= mi; //  temp = temp - min => 소수부분만 저장됨(초 계산을 위해)
	temp *= 60.0; //초 계산을 위해 temp * 60
	se = temp; //시간, 분 을 뺀 나머지 = 초
	printf("소요시간은 %d시간 %d분 %.3lf초입니다.\n\n",hou, mi, se); 
					//소요시간 출력, 초(double)는 소수점 3자리 까지 = %.3lf
	
	
	
	//과제2
	int park_space[3][2][5] = {
		{
			{ 1, 2, 3, 4, 5 },
			{ 6, 7, 8, 9, 10 }
		},
		{
			{ 1, 2, 3, 4, 5 },
			{ 6, 7, 8, 9, 10 }

		},
		{
			{ 1, 2, 3, 4, 5 },
			{ 6, 7, 8, 9, 10 }
		}
	};
	int reserved[3][10] = {
		  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
		, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
		, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
	}; 
	
	
		// 3행 10열로 생성하기 위해 reserved[3][10] 으로 선언
		//  -> 함수의 인자들도 (*reserved)[10]으로 변경했습니다.

		// park_space 배열을 함수의 인자로 사용할 때 인자가 (*park_space)[5] 로 쓰는 것 보다
		// (*park_space)[2][5] 가 더 편리한 것 같아서 변경했습니다.

		// 지정차량 등록 : reserved 배열의 지정한 자리에 차 번호를 저장하고
		// park_space 배열의 똑같은 위치에는 0 을 저장 ( 출력할 때 resv 라고 출력하기 위해)
		// -> 주차 기능을 수행 : reserved 에 있는 차 번호를 입력한다면
		// 차 번호가 저장된 위치의 reserved 는 원래 있던 자리 번호를, 
		// park_space 배열의 같은 위치에는 지정된 차 번호를 저장



	int a = disp_menu();
	while (a != 0){ //메뉴가 종료(= 0)가 아닌동안 메뉴선택을 반복
		if (a == 1) enter_park(park_space, reserved); // 1 이면 주차기능 수행
		else if (a == 2) exit_park(park_space); // 2 이면 출차기능 수행
		else if (a == 3) reserve_park(park_space, reserved); // 3 이면 지정차량 등록 기능 수행
		else if (a == 4) print_park(park_space); // 4 이면 주차 현황 출력 수행
		else printf("다시 입력해 주세요");
		a = disp_menu();
	}
	printf("\n프로그램 종료\n");
	
}

int disp_menu(void){ //메뉴를 출력하고 선택된 메뉴를 반환
	int choice;
	printf("\n1. 주차\n2. 출차\n3. 지정차량 등록\n4. 주차현황 출력\n0. 종료\n> 번호 선택 : ");
	scanf_s("%d", &choice); //메뉴 선택
	printf("\n");
	return choice; //선택한 메뉴 반환
}
void enter_park(int(*park_space)[2][5], int(*reserved)[10]){ // 주차 기능 수행
	int car_num, m, a = 0, b = 0, temp = 0, choice = 0, k = 0;
	printf("> 차번 입력(숫자 4자리) : "); // 차번 입력
	scanf_s("%d", &car_num);
	for (int i = 0; i < 3; i++){ 
		for (int j = 0; j < 10; j++){
			if (reserved[i][j] == car_num){
				temp = reserved[i][j]; //입력한 차번이 reserved 배열의 지정차량된 차번일때 임시 temp 저장
				reserved[i][j] = j + 1; // reserved 배열의 그 위치는 원래 자리 번호로 저장
				a = i; // reverse 배열의 위치(층) 저장
				b = j; // reverse 배열의 위치(번) 저장
			}
		}
	}
	if (temp == car_num){// 입력한 차번이 temp(reserved 배열의 지정차량된 차번) 일때
		if (a < 5) park_space[a][0][b] = car_num; // park_space 의 지정된 자리에 예약된 차를 주차
		else park_space[a][1][b - 5] = car_num;
		check_reserved_num(reserved, car_num, a, b);
		printf("@ 지정차량 : %d층 %d번 주차했습니다.\n", a + 1, b + 1); // 예약된 차를 몇 층 몇 번에 주차했는 지 출력
	}
	else{
		printf("@ 주차 가능 공간 : 1층[%d대] 2층[%d대] 3층[%d대]\n\n",
			find_space(park_space, 1), find_space(park_space, 2), find_space(park_space, 3));
		// 각 층마다 주차되지 않았거나 예약되지 않은, 즉 주차가 가능한 공간의 수를 출력
		for (int n = 1; n < 4; n++){
			if (choice == 0){
				print_basement(park_space, n, reserved);
				printf("> 주차 번호 입력(다른 층 0, 취소 -1) : ");
				scanf_s("%d", &choice);
				m = n;
				//0 을 입력하면 1, 2, 3 층 순으로 이동하고 -1을 입력하면 주차기능 수행을 취소
			}
		}
		if (choice != 0 && choice != -1){ //주차할 자리 번호를 입력하면
			for (int i = 0; i < 2; i++){
				for (int j = 0; j < 5; j++){
					if (park_space[m - 1][i][j] == choice){ 
						park_space[m - 1][i][j] = car_num; //그 자리의 값을 차번으로 저장
						printf("\n@ 주차되었습니다!\n");
					}
				}
			}
		}
		if (choice == -1) printf("> 취소되었습니다.\n\n");
	}
}
void exit_park(int(*park_space)[2][5]){ //출자 기능 수행
	int car_num, result = 0;
	printf("> 차번 입력(숫자 4자리) : ");
	scanf_s("%d", &car_num); // 출차할 차번 입력
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 5; k++){
				if (park_space[i][j][k] == car_num && park_space[i][j][k] > 10){
					// park_space 배열에서 이미 주차된 자리이면서 입력한 차번이 저장된 자리가 있다면
					if (j == 0) park_space[i][j][k] = k + 1;
					else park_space[i][j][k] = k + 6;
					// park_space 배열의 그 위치를 원래 자리 번호로 설정
					printf("@ 출차되었습니다.\n");
					result = 1; //출차 완료
				}
			}
		}
	}
	if (result != 1) printf("@ 해당 차량이 없습니다.\n");
	//출차되지 않았다면 해당 차량이 없다는 메시지 출력
}
void reserve_park(int (*park_space)[2][5], int(*reserved)[10]){ //지정차량 등록하는 함수
	int floor, num, car_num;
	printf("> 층과 번호 입력(종료 0) : ");
	scanf_s("%d %d", &floor, &num); // 주차장에서 예약할 위치를 입력
	printf("\n> 등록차량 번호 입력 : ");
	scanf_s("%d", &car_num); // 그 위치에 등록할 차 번호를 입력
	if (check_reservation(reserved, floor, num) == 0){ //그 위치에 지정된 차량이 없다면
		reserved[floor - 1][num - 1] = car_num; // reserved 배열의 그 위치에 차 번호를 저장
		if (num < 6) park_space[floor - 1][0][num - 1] = 0; // park_space 배열의 그 위치에 0 을 저장
		else park_space[floor - 1][1][num - 6] = 0;
		printf("@ 등록되었습니다.\n"); //등록 완료 메시지 출력
	}
	else { //그 위치에 지정된 차량이 있다면
		printf("@ 이미 등록된 차량이 있습니다.\n"); //등록 실패 메시지 출력
	}
}
void print_park(int(*park_space)[2][5]){ // 전체 주차 현황 출력
	for (int i = 0; i < 3; i++){
			print_basement(park_space, i+1); // 1~3층까지 모든 주차 현황을 출력
	}
}
void print_basement(int(*park_space)[2][5], int floor){ //층에 따른 주차 현황 출력
	if (floor == 1){ // 1층일때
		printf("\n[ 1층]===========================================\n");
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 5; j++){
				if (park_space[0][i][j] == 0) printf("[resv]"); //배열에 0 이 저장되 있으면(예약된 자리) resv 출력
				else printf("[%3d]", park_space[0][i][j]); // 1층의 주차 현황 출력
			}
			printf("\n");
		}
	}
	else if (floor == 2){ // 2층일때
		printf("\n[ 2층]===========================================\n");
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 5; j++){
				if (park_space[1][i][j] == 0) printf("[resv]"); //배열에 0 이 저장되 있으면(예약된 자리) resv 출력
				else printf("[%3d]", park_space[1][i][j]); // 2층의 주차 현황 출력
			}
			printf("\n");
		}
	}
	else if (floor == 3){ // 3층일때
		printf("\n[ 3층]===========================================\n");
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 5; j++){
				if (park_space[2][i][j] == 0) printf("[resv]"); //배열에 0 이 저장되 있으면(예약된 자리) resv 출력
				else printf("[%3d]", park_space[2][i][j]); // 3층의 주차 현황 출력
			}
			printf("\n");
		}
	}
}
int check_reservation(int(*reserved)[10], int basement, int num){ //지정차량이 있는 경우 1, 아닐 경우 0 반환
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 10; j++){
			if (i == basement - 1 && j == num - 1){
				if (reserved[i][j] < 11) return 0;
				// reserved[basement][num] 의 자리에 저장된 값이 11보다 작다면(지정차량이 없다면) 0 반환
			}
		}
	}
	return 1; //아니라면(그 자리에 지정차량이 있다면) 1 반환
}
int check_reserved_num(int(*reserved)[10], int car_num, int *floor, int *resv_num){
	//차량이 지정차량인지 확인 후 지정차량일 경우 1 반환
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 10; j++){
			if (reserved[i][j] == car_num){ // reserved[i][j] 가 입력한 차번이면(= 지정차량이면)
				floor = i;  //지정차량의 위치(층)를 저장
				resv_num = j; //지정차량의 위치(번)를 저장
				return 1; //지정차량이므로 1 반환
			}
		}
	}
	return 0;
}
int find_space(int(*park_space)[2][5], int floor){ // 층에 따라 빈 주차공간의 수를 반환해주는 함수
	int num = 0, n = 0;
	for (int i = 0; i < 3; i++){
		if (floor == i + 1) n = i; // 입력한 층을 n 으로 설정 (ex, 1층 = (n = 0) )
	}
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 5; j++){
			if (park_space[n][i][j] < 11 && park_space[n][i][j] != 0) num++;
			// 입력한 층에서 배열에 저장된 수가 11보다 작거나(11보다 크면 이미 주차된 자리)
			// 0 이 아니면(0이면 예약된 자리) num(주차 가능한 공간의 수)이 증가
		}
	}
	return num; //주차가능한 공간의 수 반환
}
