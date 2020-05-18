#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define MAX 20

int makeArray(int intArray, int inputSize);
int calSum(int intArray, int arraySize);
int calAvg(int intArray, int arraySize);
int findMin(int intArray, int arraySize);
int findMax(int intArray, int arraySize);
int findMin2(int intArray, int arraySize);
int findMax2(int intArray, int arraySize);

int main(){
	/*
	//�ǽ�1
	int arr[4];

	printf("���� ������ �Է��ϼ��� : ");
	scanf_s("%d", &arr[0]);
	printf("���� ������ �Է��ϼ��� : ");
	scanf_s("%d", &arr[1]);
	printf("���� ������ �Է��ϼ��� : ");
	scanf_s("%d", &arr[2]);

	arr[3] = arr[0] + arr[1] + arr[2];
	printf("\n");
	printf("���� : %d\n", arr[0]);
	printf("���� : %d\n", arr[1]);
	printf("���� : %d\n", arr[2]);
	printf("�հ� : %d\n", arr[3]);
	printf("��� : %.2f\n\n", arr[3]/3.0);





	//�ǽ�2
	int arr2[5];
	int i, sum = 0;

	for (i = 1; i <= 5; i++){
		printf("%d ��° �л��� ���� : ", i);
		scanf_s("%d", &arr2[i - 1]);
	}
	
	printf("<< �Է��� �л����� ���� >>\n");
	for (i = 0; i < 5; i++){
		printf("%d ", arr2[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++){
		sum += arr2[i];
	}
	printf("�л����� �� �հ� : %d\n", sum);
	printf("�л����� ��� ���� : %2.f\n", sum / 5.0);
	*/

	

	

	//����1

	srand((unsigned int)time((time_t*)NULL));
	//srand : �����Լ�
	//(unsigned int) : time�� ����ȯ
	//time_t*�� �Ͽ� �ð����� ���� �����ϰ� �ٲ�

	int array[MAX]; //ũ�� 20�� �迭�� ����
	int size, min, max;

	printf("������ size�� �Է��ϼ���(�ִ� 20) : ");
	scanf_s("%d", &size); //20ĭ �� ���� ������ �迭�� �� �Է�

	if (size == 0) printf("�迭 �ȿ� ���Ұ� �����ϴ�.\n"); //�迭 �ȿ� ���� �������� ����
	else{
		printf("�迭�� ���� [ ");
		makeArray(array, size);
		for (int i = 0; i < size; i++){
			printf("%d ", array[i]);
		}
		printf("] \n"); //�迭�� ���Ҹ� ���ʷ� ���

		printf("�迭�� ������ �� : ");
		printf("%d\n", calSum(array, size)); //���ҵ��� �� ���
		printf("�迭�� ������ ��� : ");
		printf("%d\n", calAvg(array, size)); //���ҵ��� ��� ���
		printf("�迭�� ������ �ּҰ� : ");
		printf("%d\n", findMin(array, size)); //���� �� �ּҰ� ���
		printf("�迭�� ������ �ִ밪 : ");
		printf("%d\n", findMax(array, size)); //���� �� �ִ밪 ���

		printf("\n����Լ��� ����Ͽ� �ּҰ�, �ִ밪 ã��\n");
		printf("�迭�� ������ �ּҰ� : ");
		printf("%d\n", findMin2(array, size)); //���� �� �ּҰ� ���
		printf("�迭�� ������ �ִ밪 : ");
		printf("%d\n", findMax2(array, size)); //���� �� �ִ밪 ���
	}

	return 0;
}
int makeArray(int* intArray, int inputSize){ //�迭 intArray �� inputSize ��ŭ�� ���� ����
	for (int i = 0; i < inputSize; i++){
		intArray[i] = rand()%1000; //������ �� ���Ҵ� 0~999 �� ������ ��
	}
}
int calSum(int* intArray, int arraySize){ //�迭 intArray �� [0] ~ [arraySize-1] ������ ���ҵ��� ���� return
	int sum = 0;
	for (int i = 0; i < arraySize; i++){ //�ݺ��� ���� ���Ҹ� ���Ѵ�
		sum += intArray[i];
	}
	return sum;
}
int calAvg(int* intArray, int arraySize){ //�迭 intArray �� [0] ~ [arraySize-1] ������ ���ҵ��� ����� return
	int Avg = calSum(intArray, arraySize) / arraySize;
	return Avg;
}
int findMin(int* intArray, int arraySize){ //�迭 intArray �� [0] ~ [arraySize-1] ������ ���ҵ� �� �ּҰ��� return
	int Min = intArray[0];
	for (int i = 1; i < arraySize; i++){ //�ݺ��� ���� ������ ���� ��
		if (Min > intArray[i]) Min = intArray[i];
	}
	return Min;
}
int findMax(int* intArray, int arraySize){  //�迭 intArray �� [0] ~ [arraySize-1] ������ ���ҵ� �� �ִ밪�� return
	int Max = intArray[0];
	for (int i = 1; i < arraySize; i++){ //�ݺ��� ���� ������ ���� ��
		if (Max < intArray[i]) Max = intArray[i];
	}
	return Max;
}

//����2
int findMin2(int* intArray, int arraySize){
	if (arraySize == 1) return intArray[0];//�迭�� ���Ұ� �ϳ��ۿ� ���� �� �� ���Ҹ� return

	int min = findMin2(intArray+1, arraySize-1); /*min �� size�� 1�� intArray�� �迭
												 -> ����Լ� ������� �迭�� ���� ���������� min �� �ٲ� */
												
	if (intArray[0] > min) return min; //intArray[0]�� min�� ���Ͽ� �� ���� ���� return 
	else return intArray[0];
}
int findMax2(int* intArray, int arraySize){
	int middle = arraySize / 2; //arraySize �� ������ ����
	if (arraySize == 1) return intArray[0]; //�迭�� ���Ұ� �ϳ��ۿ� ���� �� �� ���Ҹ� return

	int max1 = findMax2(intArray, middle); /* �迭�� ó�� ~ �߰� �������� findMax2�� ���
											 -> max1 �ȿ��� ��  max1, max2 �� ���� �� findMax2�� ��� -> �ݺ�
											-> size�� 1 �̰� intArray�� �迭�� max1, max2�� ���� */

	int max2 = findMax2(intArray + middle, arraySize - middle); /*�迭�� �߰� ~ �� �������� findMax2�� ���
														     -> max2 �ȿ��� ��  max1, max2 �� ���� �� findMax2�� ��� -> �ݺ�
														     -> size�� 1 �̰� intArray�� �迭�� max1, max2�� ���� */

	if (max1 > max2) return max1; //max1 �� max2 �� ���Ͽ� �� ū ���� return
	else return max2;
}









