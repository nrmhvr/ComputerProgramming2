#include <stdio.h>
#define MAXSTAR 20

int main(){
	//실습1
	int i = 0;
	int j = 0;
	int sum = 0;

	printf("등차수열의 n번째 항의 값 구하기, n의 값 입력하기 : ");
	scanf_s("%d", &i); // n 입력

	for (j = 0; j < i; j++){
		sum = 2 + 5 * j; //등차수열의 n번째 항의 값 계산
	}
	printf("sum = %d\n\n", sum);

	

	//실습 1 - 수정
	printf("등차수열의 n번째 항까지의 합의 값 구하기, n의 값 입력하기 : ");
	scanf_s("%d", &i); // n 입력
	int first = 2;
	sum = 0;
	if (i > 1){
		for (j = 2; j <= i; j++){
			sum = sum + 2 * j; //등차수열의 n번째 항의 값 계산 : 2 + (n-1)*2 = 2n
		}
	}
	printf("sum = %d\n\n", first + sum);




	//실습2
	int answer;
	printf("1+5의 값은 얼마입니까?\n");
	printf("<1> 4	<2> 5	<3> 6\n");
	scanf_s("%d", &answer);

	switch (answer){
	case 3: printf("맞았습니다.\n\n"); //6을 입력해서 정답일 경우
		break;

	default :
		printf("틀렸습니다.\n\n"); // 6이 아닌 수를 입력해서 틀릴 경우
		break;
	}
	


	//실습3
	int a, b, c;

	printf("단을 입력하고 엔터를 치시오 ==> ");
	scanf_s("%d", &c); // 단 입력
	for (a = 1; a < 10; a++){ // 각 단을 1에서 9까지 반복
		printf("%d * %d = %d\n", c, a, a*c); //c는 단을 출력, a는 1에서 9 까지
	}
	printf("\n");
	


	//실습4

	int k = 0, n = 0, sum2 = 0;

	while (1){ //무한반복 하기 위해 1
		printf("더할 수 입력 : ");
		scanf_s("%d", &n);
		if (n == 0)break; // 입력한 수가 0 이면 반복문을 빠져나와서 종료
		else{
			sum2 += n; // 입력받은 수를 sum에 누적해서 더함
			printf("지금까지 입력한 수의 합은 %d입니다. \n", sum2); //합 출력
		}
	}
	printf("프로그램 종료.\n\n");

	return 0;
}