#include <stdio.h>
#define MAXSTAR 20

int main(){
	//�ǽ�1
	int i = 0;
	int j = 0;
	int sum = 0;

	printf("���������� n��° ���� �� ���ϱ�, n�� �� �Է��ϱ� : ");
	scanf_s("%d", &i); // n �Է�

	for (j = 0; j < i; j++){
		sum = 2 + 5 * j; //���������� n��° ���� �� ���
	}
	printf("sum = %d\n\n", sum);

	

	//�ǽ� 1 - ����
	printf("���������� n��° �ױ����� ���� �� ���ϱ�, n�� �� �Է��ϱ� : ");
	scanf_s("%d", &i); // n �Է�
	int first = 2;
	sum = 0;
	if (i > 1){
		for (j = 2; j <= i; j++){
			sum = sum + 2 * j; //���������� n��° ���� �� ��� : 2 + (n-1)*2 = 2n
		}
	}
	printf("sum = %d\n\n", first + sum);




	//�ǽ�2
	int answer;
	printf("1+5�� ���� ���Դϱ�?\n");
	printf("<1> 4	<2> 5	<3> 6\n");
	scanf_s("%d", &answer);

	switch (answer){
	case 3: printf("�¾ҽ��ϴ�.\n\n"); //6�� �Է��ؼ� ������ ���
		break;

	default :
		printf("Ʋ�Ƚ��ϴ�.\n\n"); // 6�� �ƴ� ���� �Է��ؼ� Ʋ�� ���
		break;
	}
	


	//�ǽ�3
	int a, b, c;

	printf("���� �Է��ϰ� ���͸� ġ�ÿ� ==> ");
	scanf_s("%d", &c); // �� �Է�
	for (a = 1; a < 10; a++){ // �� ���� 1���� 9���� �ݺ�
		printf("%d * %d = %d\n", c, a, a*c); //c�� ���� ���, a�� 1���� 9 ����
	}
	printf("\n");
	


	//�ǽ�4

	int k = 0, n = 0, sum2 = 0;

	while (1){ //���ѹݺ� �ϱ� ���� 1
		printf("���� �� �Է� : ");
		scanf_s("%d", &n);
		if (n == 0)break; // �Է��� ���� 0 �̸� �ݺ����� �������ͼ� ����
		else{
			sum2 += n; // �Է¹��� ���� sum�� �����ؼ� ����
			printf("���ݱ��� �Է��� ���� ���� %d�Դϴ�. \n", sum2); //�� ���
		}
	}
	printf("���α׷� ����.\n\n");

	return 0;
}