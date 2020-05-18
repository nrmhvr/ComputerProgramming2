#include <stdio.h>
#define MAX 20

void inputScore(int *scoreArray);
void printScore(int *scoreArray, int index);
int printSum(int *scoreArray, int inputIndex);
int printAvg(int *scoreArray);
void invertedOutput(char str[]);
int makeArray(int* intArray, int inputSize);
void swap(int *x, int *y);
void sortArray(int *intArray, int inputSize);
void print(int *arr, int arraySize);

int main(){
	//����2
	char sta[100];//ũ�Ⱑ 100�� �迭 ����

	printf("<< �� ���� �Է��ϼ���. >>\n");
	gets_s(sta, sizeof(sta));//���ڿ��� �迭�� ����

	printf("\n������ �Է��� ���ڿ��� �Ųٷ� ����մϴ�.\n");
	invertedOutput(sta); //���ڿ��� �Ųٷ� ���
	printf("\n");


	/*
	//�ǽ�1
	int array[3][3];
	int rowIndex, colIndex;

	printf("������ 9�� �Է��ϼ���\n");
	for (rowIndex = 0; rowIndex < 3; rowIndex++){
		for (colIndex = 0; colIndex < 3; colIndex++)
			scanf_s("%d", &array[rowIndex][colIndex]);
	}
	for (rowIndex = 0; rowIndex < 3; rowIndex++){
		for (colIndex = 0; colIndex < 3; colIndex++)
			printf("%d ", array[rowIndex][colIndex]);
		printf("\n");
	}
	printf("\n");
	*/
	

	
	//�ǽ�2
	int scoreArray[20][3]; //�л� ��(�ִ� 20), 3������ ������ �迭 ���� 
	int inputStudentSize;
	int studentIndex;

	printf("�Է� ���� �л����� �Է��ϼ��� : ");
	scanf_s("%d", &inputStudentSize); // �л� �� �Է�

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		inputScore(&(scoreArray[studentIndex])); //�л��� ������ �Է�
	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		printScore(&(scoreArray[studentIndex]), studentIndex);//�л��� ������ ���
	printf("\n");

	//����1
	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++){
		printSum(&(scoreArray[studentIndex]), studentIndex);//�л��� ������ ������ ����Ͽ� ���
		printAvg(&(scoreArray[studentIndex]));//�л��� ������ ����� ����Ͽ� ���
	}
	printf("\n");

	

	//����3
	srand((unsigned int)time((time_t*)NULL));
	//srand : �����Լ�
	//(unsigned int) : time�� ����ȯ
	//time_t*�� �Ͽ� �ð����� ���� �����ϰ� �ٲ�

	int arr[MAX];//ũ�Ⱑ 20�� �迭 ����
	int arraySize;
	printf("�迭�� size�� �Է��ϼ���(�ִ� 20) : ");
	scanf_s("%d", &arraySize); //20ĭ �� ���� ������ �迭�� �� �Է�

	if (arraySize <= 0) printf("�迭 �ȿ� ���Ұ� �����ϴ�.\n"); //�迭 �ȿ� ���� �������� ����
	else{
		makeArray(arr, arraySize); //�迭 �ȿ� ������ ���� ����
		print(arr, arraySize); //�迭 ���
		printf("�������� ����\n");
		printf("->");
		sortArray(arr, arraySize); //�迭�� ������������ ����
		print(arr, arraySize);//�迭 ���
	}
}



//�ǽ� �Լ�
void inputScore(int *scoreArray){
	printf("���� ���� �Է� : ");
	scanf_s("%d", &scoreArray[0]);
	printf("���� ���� �Է� : ");
	scanf_s("%d", &scoreArray[1]);
	printf("���� ���� �Է� : ");
	scanf_s("%d", &scoreArray[2]);
}
void printScore(int *scoreArray, int index){
	printf("[%d] %d, %d, %d\n", index, scoreArray[0], scoreArray[1], scoreArray[2]);
}



//����1 �Լ�
int printSum(int *scoreArray, int inputIndex){
	int sum = scoreArray[0] + scoreArray[1] + scoreArray[2];//�л��� ����, ����, ���� ������ �� ���
	printf("[%d] �л��� ���� : %d \n",inputIndex, sum); //����� ������ ���
	return sum;
}
int printAvg(int *scoreArray){
	int avg = (scoreArray[0] + scoreArray[1] + scoreArray[2]) / 3;//�л��� ������ ����� ���
	printf("\t- ��� : %d \n", avg);//����� ����� ���
	return avg;
}



//����2 �Լ�
void invertedOutput(char str[]){ 
	int length = strlen(str); //length �� str �� ����
	for (int i = length - 1; i >= 0; i--){
		printf("%c", str[i]); //�迭�� ������ ���� �Ųٷ� ���
	}
	printf("\n");
}



//����3 �Լ�
int makeArray(int* intArray, int inputSize){ //�迭 intArray �� inputSize ��ŭ�� ���� ����
	for (int i = 0; i < inputSize; i++){
		intArray[i] = rand() % 1000; //������ �� ���Ҵ� 0~999 �� ������ ��
	}
}
void swap(int *x, int *y){ //x, y�� ������ ��ġ�� ����
	int a = *x;
	*x = *y;
	*y = a;
}
void sortArray(int *intArray, int inputSize){ //�迭�� ������������ ����
	int i = 0;
	while (i < inputSize){ //�迭�� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < inputSize; j++){
			if (intArray[i] < intArray[j]) swap(&intArray[i], &intArray[j]);
											// i �� �����Ǿ j ���� Ŀ���� 
											// if�� ���� �����Ͽ� ������������ �迭�� ����
		}
		i++;
	}
}
void print(int *arr, int arraySize){ //�迭�� ���ʷ� ���
	printf("�迭�� ���� [ ");
	for (int i = 0; i < arraySize; i++){
		printf("%d ", arr[i]);
	}
	printf("] \n\n");
}