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
	
	//�ǽ�1
	int result;
	result = aaa(5, 3);

	printf("aaa()�Լ��� ȣ���ϸ鼭 ���ڷ� 5�� 3 �����ؼ� ����� %d�� �˴ϴ�.\n\n", result);



	//�ǽ�2
	int v1, v2, m = 10, n = 20;
	v1 = add(m, n);
	v2 = subtract(15, 3) + 2;

	printf("%d %d %d \n\n", v1, v2, add(2, 6));




	//�ǽ�3
	int a, b, result2;

	printf("�غ� ���� : ");
	scanf_s("%d", &a);
	printf("���� : ");
	scanf_s("%d", &b);

	result2 = getArea(a, b);
	printf("�簢���� ���̴� %d�Դϴ�. \n\n", result2);




	//�ǽ�4
	int c, result3;

	printf("input your number = ");
	scanf_s("%d", &c);
	result3 = sum(c);
	printf("1���� %d������ �� : %d \n\n", c, result3);

	*/

	

	//����1
	int num, j = 0;

	printf("���� �Է� : ");
	scanf_s("%d", &num);
	if (num < 2){
		printf("2���� ���� �� �Դϴ�.\n");
	}else{
		for (int i = 2; i <= num; i++){ //2���� �Է��� �� ���� prime_check
			if (prime_check(i) == 1){ //prime_check(i)�� 1 �̸� i �� �Ҽ�
				printf("%d", i); //�Ҽ��� i �� ���
				putchar(' ');
				j++;

				if (j == 3){ //j�� 3�� �Ǹ�(�Ҽ��� 3�� ��µǸ�) �� �� ����
					printf("\n");
					j = 0; //j �ʱ�ȭ
				}
			}
		}
		printf("\n\n");
	}
	


	//����2
	int r = 0, month = 1;

	printf("�䳢 ��\n");
	for (;month <= 12; r++, month++){ // 12�� ���� �ݺ�
		printf("%d�� = %d\n", month, rabbit(r)); //�Լ��� ����Ͽ� �䳢 �� ���
	}

}



//�ǽ� �Լ�
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



//���� �Լ�
int prime_check(int checkNum){ //�Ҽ��̸� return 1, �Ҽ��� �ƴϸ� return 0
	if (checkNum == 2) return 1; //2�� ¦�� �� ������ �Ҽ�, return 1
	else{
		for (int i = 2; i < checkNum; i++){ 
			if ((checkNum % i == 0)) return 0; //checknum(3 �̻�)�� 2���� checknum-1 ���� ����
		}								//�������� �ѹ��̶� 0 �̸� �Ҽ��� �ƴϴ�, return 0
		return 1; //���� �������� �����ؼ� �Ҽ�, return 1
	}
}

long rabbit(int n){ //�䳢�� ������ �� = �Ǻ���ġ ��
	if (n <= 1) return 1; // n �� 1 ���� �̸� �Ǻ���ġ ���� 1
	else return (rabbit(n-1) + rabbit(n-2)); //n �� 2 �̻��̸� �Ǻ���ġ ���� n-1 + n-2
}