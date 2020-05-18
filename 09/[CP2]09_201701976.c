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
	//�ǽ�1
	int hour, min, sec;
	double getTime, calTime;

	printf("�ð� �Է� : ");
	scanf_s("%lf", &calTime);
	getTime = calTime;

	hour = (int)calTime;
	calTime -= hour;
	calTime *= 60.0;
	min = (int)calTime;
	calTime -= min;
	calTime *= 60.0;
	sec = (int)calTime;
	printf("%.2lf�ð��� %d�ð� %d�� %d���Դϴ�.\n\n", getTime, hour, min, sec);
	*/


	
	//����1
	int distance, speed, hou, mi; //�Ÿ�, �ӷ�, �ð�, �� �� ������ int ����
	double se, temp; //��, ����� �ð��� ������ double ����

	printf("�Ÿ��� �ӷ� �Է� : ");
	scanf_s("%d %d", &distance, &speed);
	temp = (double)distance / speed; // ����� �ð� = �Ÿ� / �ӷ�

	hou = (int)temp; // ��ü �ð� temp(�Ҽ������� ����)���� �����κи� = hour
	temp -= hou;    //temp = ��ü�ð� - hour => �Ҽ��κи� �����(��, �� ����� ����)
	temp *= 60.0; // �� ����� ���� temp * 60
	mi = (int)temp; //�ð��� ����ϰ� ���� temp���� �����κи� = min
	temp -= mi; //  temp = temp - min => �Ҽ��κи� �����(�� ����� ����)
	temp *= 60.0; //�� ����� ���� temp * 60
	se = temp; //�ð�, �� �� �� ������ = ��
	printf("�ҿ�ð��� %d�ð� %d�� %.3lf���Դϴ�.\n\n",hou, mi, se); 
					//�ҿ�ð� ���, ��(double)�� �Ҽ��� 3�ڸ� ���� = %.3lf
	
	
	
	//����2
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
	
	
		// 3�� 10���� �����ϱ� ���� reserved[3][10] ���� ����
		//  -> �Լ��� ���ڵ鵵 (*reserved)[10]���� �����߽��ϴ�.

		// park_space �迭�� �Լ��� ���ڷ� ����� �� ���ڰ� (*park_space)[5] �� ���� �� ����
		// (*park_space)[2][5] �� �� ���� �� ���Ƽ� �����߽��ϴ�.

		// �������� ��� : reserved �迭�� ������ �ڸ��� �� ��ȣ�� �����ϰ�
		// park_space �迭�� �Ȱ��� ��ġ���� 0 �� ���� ( ����� �� resv ��� ����ϱ� ����)
		// -> ���� ����� ���� : reserved �� �ִ� �� ��ȣ�� �Է��Ѵٸ�
		// �� ��ȣ�� ����� ��ġ�� reserved �� ���� �ִ� �ڸ� ��ȣ��, 
		// park_space �迭�� ���� ��ġ���� ������ �� ��ȣ�� ����



	int a = disp_menu();
	while (a != 0){ //�޴��� ����(= 0)�� �ƴѵ��� �޴������� �ݺ�
		if (a == 1) enter_park(park_space, reserved); // 1 �̸� ������� ����
		else if (a == 2) exit_park(park_space); // 2 �̸� ������� ����
		else if (a == 3) reserve_park(park_space, reserved); // 3 �̸� �������� ��� ��� ����
		else if (a == 4) print_park(park_space); // 4 �̸� ���� ��Ȳ ��� ����
		else printf("�ٽ� �Է��� �ּ���");
		a = disp_menu();
	}
	printf("\n���α׷� ����\n");
	
}

int disp_menu(void){ //�޴��� ����ϰ� ���õ� �޴��� ��ȯ
	int choice;
	printf("\n1. ����\n2. ����\n3. �������� ���\n4. ������Ȳ ���\n0. ����\n> ��ȣ ���� : ");
	scanf_s("%d", &choice); //�޴� ����
	printf("\n");
	return choice; //������ �޴� ��ȯ
}
void enter_park(int(*park_space)[2][5], int(*reserved)[10]){ // ���� ��� ����
	int car_num, m, a = 0, b = 0, temp = 0, choice = 0, k = 0;
	printf("> ���� �Է�(���� 4�ڸ�) : "); // ���� �Է�
	scanf_s("%d", &car_num);
	for (int i = 0; i < 3; i++){ 
		for (int j = 0; j < 10; j++){
			if (reserved[i][j] == car_num){
				temp = reserved[i][j]; //�Է��� ������ reserved �迭�� ���������� �����϶� �ӽ� temp ����
				reserved[i][j] = j + 1; // reserved �迭�� �� ��ġ�� ���� �ڸ� ��ȣ�� ����
				a = i; // reverse �迭�� ��ġ(��) ����
				b = j; // reverse �迭�� ��ġ(��) ����
			}
		}
	}
	if (temp == car_num){// �Է��� ������ temp(reserved �迭�� ���������� ����) �϶�
		if (a < 5) park_space[a][0][b] = car_num; // park_space �� ������ �ڸ��� ����� ���� ����
		else park_space[a][1][b - 5] = car_num;
		check_reserved_num(reserved, car_num, a, b);
		printf("@ �������� : %d�� %d�� �����߽��ϴ�.\n", a + 1, b + 1); // ����� ���� �� �� �� ���� �����ߴ� �� ���
	}
	else{
		printf("@ ���� ���� ���� : 1��[%d��] 2��[%d��] 3��[%d��]\n\n",
			find_space(park_space, 1), find_space(park_space, 2), find_space(park_space, 3));
		// �� ������ �������� �ʾҰų� ������� ����, �� ������ ������ ������ ���� ���
		for (int n = 1; n < 4; n++){
			if (choice == 0){
				print_basement(park_space, n, reserved);
				printf("> ���� ��ȣ �Է�(�ٸ� �� 0, ��� -1) : ");
				scanf_s("%d", &choice);
				m = n;
				//0 �� �Է��ϸ� 1, 2, 3 �� ������ �̵��ϰ� -1�� �Է��ϸ� ������� ������ ���
			}
		}
		if (choice != 0 && choice != -1){ //������ �ڸ� ��ȣ�� �Է��ϸ�
			for (int i = 0; i < 2; i++){
				for (int j = 0; j < 5; j++){
					if (park_space[m - 1][i][j] == choice){ 
						park_space[m - 1][i][j] = car_num; //�� �ڸ��� ���� �������� ����
						printf("\n@ �����Ǿ����ϴ�!\n");
					}
				}
			}
		}
		if (choice == -1) printf("> ��ҵǾ����ϴ�.\n\n");
	}
}
void exit_park(int(*park_space)[2][5]){ //���� ��� ����
	int car_num, result = 0;
	printf("> ���� �Է�(���� 4�ڸ�) : ");
	scanf_s("%d", &car_num); // ������ ���� �Է�
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 5; k++){
				if (park_space[i][j][k] == car_num && park_space[i][j][k] > 10){
					// park_space �迭���� �̹� ������ �ڸ��̸鼭 �Է��� ������ ����� �ڸ��� �ִٸ�
					if (j == 0) park_space[i][j][k] = k + 1;
					else park_space[i][j][k] = k + 6;
					// park_space �迭�� �� ��ġ�� ���� �ڸ� ��ȣ�� ����
					printf("@ �����Ǿ����ϴ�.\n");
					result = 1; //���� �Ϸ�
				}
			}
		}
	}
	if (result != 1) printf("@ �ش� ������ �����ϴ�.\n");
	//�������� �ʾҴٸ� �ش� ������ ���ٴ� �޽��� ���
}
void reserve_park(int (*park_space)[2][5], int(*reserved)[10]){ //�������� ����ϴ� �Լ�
	int floor, num, car_num;
	printf("> ���� ��ȣ �Է�(���� 0) : ");
	scanf_s("%d %d", &floor, &num); // �����忡�� ������ ��ġ�� �Է�
	printf("\n> ������� ��ȣ �Է� : ");
	scanf_s("%d", &car_num); // �� ��ġ�� ����� �� ��ȣ�� �Է�
	if (check_reservation(reserved, floor, num) == 0){ //�� ��ġ�� ������ ������ ���ٸ�
		reserved[floor - 1][num - 1] = car_num; // reserved �迭�� �� ��ġ�� �� ��ȣ�� ����
		if (num < 6) park_space[floor - 1][0][num - 1] = 0; // park_space �迭�� �� ��ġ�� 0 �� ����
		else park_space[floor - 1][1][num - 6] = 0;
		printf("@ ��ϵǾ����ϴ�.\n"); //��� �Ϸ� �޽��� ���
	}
	else { //�� ��ġ�� ������ ������ �ִٸ�
		printf("@ �̹� ��ϵ� ������ �ֽ��ϴ�.\n"); //��� ���� �޽��� ���
	}
}
void print_park(int(*park_space)[2][5]){ // ��ü ���� ��Ȳ ���
	for (int i = 0; i < 3; i++){
			print_basement(park_space, i+1); // 1~3������ ��� ���� ��Ȳ�� ���
	}
}
void print_basement(int(*park_space)[2][5], int floor){ //���� ���� ���� ��Ȳ ���
	if (floor == 1){ // 1���϶�
		printf("\n[ 1��]===========================================\n");
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 5; j++){
				if (park_space[0][i][j] == 0) printf("[resv]"); //�迭�� 0 �� ����� ������(����� �ڸ�) resv ���
				else printf("[%3d]", park_space[0][i][j]); // 1���� ���� ��Ȳ ���
			}
			printf("\n");
		}
	}
	else if (floor == 2){ // 2���϶�
		printf("\n[ 2��]===========================================\n");
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 5; j++){
				if (park_space[1][i][j] == 0) printf("[resv]"); //�迭�� 0 �� ����� ������(����� �ڸ�) resv ���
				else printf("[%3d]", park_space[1][i][j]); // 2���� ���� ��Ȳ ���
			}
			printf("\n");
		}
	}
	else if (floor == 3){ // 3���϶�
		printf("\n[ 3��]===========================================\n");
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 5; j++){
				if (park_space[2][i][j] == 0) printf("[resv]"); //�迭�� 0 �� ����� ������(����� �ڸ�) resv ���
				else printf("[%3d]", park_space[2][i][j]); // 3���� ���� ��Ȳ ���
			}
			printf("\n");
		}
	}
}
int check_reservation(int(*reserved)[10], int basement, int num){ //���������� �ִ� ��� 1, �ƴ� ��� 0 ��ȯ
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 10; j++){
			if (i == basement - 1 && j == num - 1){
				if (reserved[i][j] < 11) return 0;
				// reserved[basement][num] �� �ڸ��� ����� ���� 11���� �۴ٸ�(���������� ���ٸ�) 0 ��ȯ
			}
		}
	}
	return 1; //�ƴ϶��(�� �ڸ��� ���������� �ִٸ�) 1 ��ȯ
}
int check_reserved_num(int(*reserved)[10], int car_num, int *floor, int *resv_num){
	//������ ������������ Ȯ�� �� ���������� ��� 1 ��ȯ
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 10; j++){
			if (reserved[i][j] == car_num){ // reserved[i][j] �� �Է��� �����̸�(= ���������̸�)
				floor = i;  //���������� ��ġ(��)�� ����
				resv_num = j; //���������� ��ġ(��)�� ����
				return 1; //���������̹Ƿ� 1 ��ȯ
			}
		}
	}
	return 0;
}
int find_space(int(*park_space)[2][5], int floor){ // ���� ���� �� ���������� ���� ��ȯ���ִ� �Լ�
	int num = 0, n = 0;
	for (int i = 0; i < 3; i++){
		if (floor == i + 1) n = i; // �Է��� ���� n ���� ���� (ex, 1�� = (n = 0) )
	}
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 5; j++){
			if (park_space[n][i][j] < 11 && park_space[n][i][j] != 0) num++;
			// �Է��� ������ �迭�� ����� ���� 11���� �۰ų�(11���� ũ�� �̹� ������ �ڸ�)
			// 0 �� �ƴϸ�(0�̸� ����� �ڸ�) num(���� ������ ������ ��)�� ����
		}
	}
	return num; //���������� ������ �� ��ȯ
}
