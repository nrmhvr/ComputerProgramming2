#include <stdio.h>

int main() {
//	printf("**********\n");
//	printf("*        *\n");
//	printf("**********\n");
//	printf("*  ****  *\n");
//	printf("**********\n");
//	printf("****  ****\n");
//	printf("**********\n\n");
//	1주차 연습

	printf("나는 컴퓨터공학과 2학년이고\n");
	printf("학번은 201701976이다.\n\n");

	int grade = 2, student_number = 201701976;
	printf("나는 컴퓨터공학과 %d학년이고\n", grade);
	printf("학번은 %d이다.\n\n", student_number);

	int front = 10, rear = 5;
	printf("a + b = %d\n", front + rear);
	printf("a - b = %d\n", front - rear);
	printf("a * b = %d\n", front * rear);
	printf("a / b = %d\n\n", front / rear);

	int frontInt = 10, rearInt = 15;
	float frontFloat = 10, rearFloat = 15;
	printf("a + b = %d\n", frontInt + rearInt);
	printf("a - b = %d\n", frontInt - rearInt);
	printf("a * b = %d\n", frontInt * rearInt);
	printf("a / b = %d\n\n", frontInt / rearInt);

	printf("c + d = %f\n", frontFloat + rearFloat);
	printf("c - d = %f\n", frontFloat - rearFloat);
	printf("c * d = %f\n", frontFloat * rearFloat);
	printf("c / d = %f\n\n", frontFloat / rearFloat);

//	a / b 와 c / d 는 같은 값을 계산하지만 a / b 는 %d 를 쓰는 정수를 계산하므로 소수점 자리의 값이 생략되고
//	c / d 는 %f 를 쓰는 실수를 계산하므로 소수점 자리까지 전부 출력된다.

	int a = 20, b = 30;
	float p = 3.14F, q = 4.2F;
	double m = 7.23, n = 1.2;

	int x = 0;
	x = x + 10;
	printf(" x = %d ", x);

	printf(" a = %d 이고 b = %d : \n", a, b);
	printf(" p = %f 이고 q = %f : \n", p, q);
	printf(" m = %lf 이고 n = %lf : \n\n", m, n);
	printf("\tb / a -> %d\n", b / a);
	printf("\tb / a -> %f\n", b / a);
	printf("\tp - q -> %f\n", p - q);
	printf("\tm * n -> %lf\n\n", m * n);
	return 0;
}
//	b / a 에서 %d(정수 출력) 를 쓴 경우, b 와 a 가 정수라서 계산이 되고 소수점 자리의 값은 생략된다.
//	b / a 에서 %f(실수 출력) 를 쓴 경우, b 와 a 가 정수라서 계산이 되지 않고 소수점 자리까지 모두 0 으로 출력된다.

//	f = float 를 뜻한다.
//	lf = double 을 뜻한다.
//	%d 는 "", 뒤에 오는 int 의 값을 출력한다.
//	%f 는 "", 뒤에 오는 float 의 값을 출력한다.
//	%lf 는 "", 뒤에 오는 double 의 값을 출력한다.
//	%t 는 tap 만큼 뛰어져서 출력된다.
//	소수점은 기본 6자리까지 출력된다.