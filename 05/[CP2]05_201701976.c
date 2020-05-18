#include <stdio.h>

int aaa(int su1, int su2){
		int hap;
		hap = su1 + su2;
		return hap;
}
int subtract(int a, int b);
int add(int a, int b);
int getArea(int x, int y);
int sum(int x);
int prime_check(int checkNum);
long rabbit(int n);

	
int main(void){
	/*
	
	//실습1
	int result;
	result = aaa(5, 3);

	printf("aaa()함수를 호출하면서 인자로 5와 3 전달해서 결과는 %d이 됩니다.\n\n", result);



	//실습2
	int v1, v2, m = 10, n = 20;
	v1 = add(m, n);
	v2 = subtract(15, 3) + 2;

	printf("%d %d %d \n\n", v1, v2, add(2, 6));




	//실습3
	int a, b, result2;

	printf("밑변 길이 : ");
	scanf_s("%d", &a);
	printf("높이 : ");
	scanf_s("%d", &b);

	result2 = getArea(a, b);
	printf("사각형의 넓이는 %d입니다. \n\n", result2);




	//실습4
	int c, result3;

	printf("input your number = ");
	scanf_s("%d", &c);
	result3 = sum(c);
	printf("1부터 %d까지의 합 : %d \n\n", c, result3);

	*/

	

	//과제1
	int num, j = 0;

	printf("숫자 입력 : ");
	scanf_s("%d", &num);
	if (num < 2){
		printf("2보다 작은 수 입니다.\n");
	}else{
		for (int i = 2; i <= num; i++){ //2부터 입력한 수 까지 prime_check
			if (prime_check(i) == 1){ //prime_check(i)가 1 이면 i 는 소수
				printf("%d", i); //소수인 i 를 출력
				putchar(' ');
				j++;

				if (j == 3){ //j가 3이 되면(소수가 3번 출력되면) 한 줄 띄우기
					printf("\n");
					j = 0; //j 초기화
				}
			}
		}
		printf("\n\n");
	}
	


	//과제2
	int r = 0, month = 1;

	printf("토끼 수\n");
	for (;month <= 12; r++, month++){ // 12달 까지 반복
		printf("%d달 = %d\n", month, rabbit(r)); //함수를 사용하여 토끼 수 출력
	}

}



//실습 함수
/*
int add(int a, int b){
	return a + b;
}
int subtract(int a, int b){
	int diff;
	diff = a - b;
	return diff;
}
int getArea(int x, int y){
	return x * y;
}
int sum(int x) {
	if (x <= 1) return 1;
	else return x + sum(x - 1);
}
*/



//과제 함수
int prime_check(int checkNum){ //소수이면 return 1, 소수가 아니면 return 0
	if (checkNum == 2) return 1; //2는 짝수 중 유일한 소수, return 1
	else{
		for (int i = 2; i < checkNum; i++){ 
			if ((checkNum % i == 0)) return 0; //checknum(3 이상)을 2부터 checknum-1 까지 나눈
		}								//나머지가 한번이라도 0 이면 소수가 아니다, return 0
		return 1; //나눈 나머지가 존재해서 소수, return 1
	}
}

long rabbit(int n){ //토끼가 증가한 수 = 피보나치 수
	if (n <= 1) return 1; // n 이 1 이하 이면 피보나치 수는 1
	else return (rabbit(n-1) + rabbit(n-2)); //n 이 2 이상이면 피보나치 수는 n-1 + n-2
}