#include <stdio.h>
#define MAX 5
#define MAXSTAR 10


int main(void){
	/*
	//�ǽ�1
	int a = 10, b = 20, c = 30;

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta + b++ �� ��� = %5d\n\n", a + b++);

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta + ++b %% 3 �� ��� = %5d\n\n", a + ++b % 3);	

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\t++a / 2 + c++ �� ��� = %5d\n\n", ++a / 2 + c++);
	
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta++ + ++b + ++c �� ��� = %5d\n\n", a++ + ++b + ++c);
	printf("a = %d, b = %d, c = %d\n\n", a, b, c);


	//�ǽ�2
	int number = 0;

	printf("���� ���� �ϳ��� �Է��ϼ���. ");
	scanf_s("%d", &number);
	printf("---> �Է��� �� %d ��(��) ", number);

	if (number % 2 == 0){
		printf("¦�� �Դϴ�.\n\n");
	}
	else{
		printf("Ȧ�� �Դϴ�.\n\n");
	}



	//�ǽ�3
	int point = 0;

	printf("���α׷��� ��� ������ �Է��ϼ���. --> ");
	scanf_s("%d", &point);

	if (point >= 90){ //point >= 80 && point < 90
		printf("���α׷��� ��� ������ A�Դϴ�.\n\n");
	}
	else if (point >= 80){ // point >= 70 && point < 80
		printf("���α׷��� ��� ������ B�Դϴ�.\n\n");
	}
	else if (point >= 70){ // point >= 60 && point <70
		printf("���α׷��� ��� ������ C�Դϴ�.\n\n");
	}
	else if (point >= 60){ // point < 60
		printf("���α׷��� ��� ������ D�Դϴ�.\n\n");
	}
	else{
		printf("���α׷��� ��� ������ F�Դϴ�.\n\n");
	}



	//�ǽ�4
	int year = 0, month = 0, maxDay = 30, vaildinput = 0;
	printf("��� ���� ������ ���� �Է��ϸ� �� ���� ������ �˷��帳�ϴ�.\n");
	printf("2003 2 : �Է� > ");
	scanf_s("%d %d", &year, &month);

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		maxDay = 31;
		vaildinput = 1;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		maxDay = 30;
		vaildinput = 1;
		break;

	case 2:
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
			maxDay = 29;
		else
			maxDay = 28;
		vaildinput = 1;
		break;

	default:
		vaildinput = 0;
	}
	if (vaildinput)
		printf("%d�� %d���� ������ %d�� �Դϴ�.\n\n", year, month, maxDay);
	else
		printf("�Է��� �߸��Ǿ����ϴ�.\n\n");



	//�ǽ�5
	int i, j;

	for (i = 0; i <= MAX; i++)
	{
		for (j = MAX; j >= 0; j--)
		{
			if (j > i) putchar(' ');
			else printf("%d", j);
		}
		putchar('\n\n');
	}
	*/
	



	//����
	int num = 1;
	int empty, star, i;

	while (num != 0){ 
		printf("������ �Է��� �ּ��� : [���� : 0]\n"); // 0 �� �Է��ϸ� ����
		scanf_s("%d", &num);

		if (num > MAXSTAR){
			printf("�ٽ� �Է����ּ���!\n\n"); // MAXSTAR ���� num �� ũ�� �ٽ� �Է�
		}
		else{
			for (i = 0; i <= num; i++){ // �� ���� ����
				for (empty = 1; empty <= num-i; empty++){ // ��ĭ ���
					putchar(' ');
					}
				for (star = 1; star <= i * 2 - 1; star++){ // * ���
					printf("*");
				}
				printf("\n");
			}
		}
	}
	return 0;
}