#include <stdio.h>

int main() {
//	printf("**********\n");
//	printf("*        *\n");
//	printf("**********\n");
//	printf("*  ****  *\n");
//	printf("**********\n");
//	printf("****  ****\n");
//	printf("**********\n\n");
//	1���� ����

	printf("���� ��ǻ�Ͱ��а� 2�г��̰�\n");
	printf("�й��� 201701976�̴�.\n\n");

	int grade = 2, student_number = 201701976;
	printf("���� ��ǻ�Ͱ��а� %d�г��̰�\n", grade);
	printf("�й��� %d�̴�.\n\n", student_number);

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

//	a / b �� c / d �� ���� ���� ��������� a / b �� %d �� ���� ������ ����ϹǷ� �Ҽ��� �ڸ��� ���� �����ǰ�
//	c / d �� %f �� ���� �Ǽ��� ����ϹǷ� �Ҽ��� �ڸ����� ���� ��µȴ�.

	int a = 20, b = 30;
	float p = 3.14F, q = 4.2F;
	double m = 7.23, n = 1.2;

	int x = 0;
	x = x + 10;
	printf(" x = %d ", x);

	printf(" a = %d �̰� b = %d : \n", a, b);
	printf(" p = %f �̰� q = %f : \n", p, q);
	printf(" m = %lf �̰� n = %lf : \n\n", m, n);
	printf("\tb / a -> %d\n", b / a);
	printf("\tb / a -> %f\n", b / a);
	printf("\tp - q -> %f\n", p - q);
	printf("\tm * n -> %lf\n\n", m * n);
	return 0;
}
//	b / a ���� %d(���� ���) �� �� ���, b �� a �� ������ ����� �ǰ� �Ҽ��� �ڸ��� ���� �����ȴ�.
//	b / a ���� %f(�Ǽ� ���) �� �� ���, b �� a �� ������ ����� ���� �ʰ� �Ҽ��� �ڸ����� ��� 0 ���� ��µȴ�.

//	f = float �� ���Ѵ�.
//	lf = double �� ���Ѵ�.
//	%d �� "", �ڿ� ���� int �� ���� ����Ѵ�.
//	%f �� "", �ڿ� ���� float �� ���� ����Ѵ�.
//	%lf �� "", �ڿ� ���� double �� ���� ����Ѵ�.
//	%t �� tap ��ŭ �پ����� ��µȴ�.
//	�Ҽ����� �⺻ 6�ڸ����� ��µȴ�.