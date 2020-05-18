#include <stdio.h>
#define MAX 5
#define MAXSTAR 10


int main(void){
	/*
	//실습1
	int a = 10, b = 20, c = 30;

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta + b++ 의 결과 = %5d\n\n", a + b++);

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta + ++b %% 3 의 결과 = %5d\n\n", a + ++b % 3);	

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\t++a / 2 + c++ 의 결과 = %5d\n\n", ++a / 2 + c++);
	
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta++ + ++b + ++c 의 결과 = %5d\n\n", a++ + ++b + ++c);
	printf("a = %d, b = %d, c = %d\n\n", a, b, c);


	//실습2
	int number = 0;

	printf("양의 정수 하나를 입력하세요. ");
	scanf_s("%d", &number);
	printf("---> 입력한 수 %d 는(은) ", number);

	if (number % 2 == 0){
		printf("짝수 입니다.\n\n");
	}
	else{
		printf("홀수 입니다.\n\n");
	}



	//실습3
	int point = 0;

	printf("프로그래밍 언어 점수를 입력하세요. --> ");
	scanf_s("%d", &point);

	if (point >= 90){ //point >= 80 && point < 90
		printf("프로그래밍 언어 학점이 A입니다.\n\n");
	}
	else if (point >= 80){ // point >= 70 && point < 80
		printf("프로그래밍 언어 학점이 B입니다.\n\n");
	}
	else if (point >= 70){ // point >= 60 && point <70
		printf("프로그래밍 언어 학점이 C입니다.\n\n");
	}
	else if (point >= 60){ // point < 60
		printf("프로그래밍 언어 학점이 D입니다.\n\n");
	}
	else{
		printf("프로그래밍 언어 학점이 F입니다.\n\n");
	}



	//실습4
	int year = 0, month = 0, maxDay = 30, vaildinput = 0;
	printf("년과 월을 다음과 같이 입력하면 그 달의 말일을 알려드립니다.\n");
	printf("2003 2 : 입력 > ");
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
		printf("%d년 %d월의 말일은 %d일 입니다.\n\n", year, month, maxDay);
	else
		printf("입력이 잘못되었습니다.\n\n");



	//실습5
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
	



	//과제
	int num = 1;
	int empty, star, i;

	while (num != 0){ 
		printf("개수를 입력해 주세요 : [종료 : 0]\n"); // 0 을 입력하면 종료
		scanf_s("%d", &num);

		if (num > MAXSTAR){
			printf("다시 입력해주세요!\n\n"); // MAXSTAR 보다 num 이 크면 다시 입력
		}
		else{
			for (i = 0; i <= num; i++){ // 행 개수 설정
				for (empty = 1; empty <= num-i; empty++){ // 빈칸 출력
					putchar(' ');
					}
				for (star = 1; star <= i * 2 - 1; star++){ // * 출력
					printf("*");
				}
				printf("\n");
			}
		}
	}
	return 0;
}