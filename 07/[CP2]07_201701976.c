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
	//과제2
	char sta[100];//크기가 100인 배열 생성

	printf("<< 한 줄을 입력하세요. >>\n");
	gets_s(sta, sizeof(sta));//문자열을 배열에 저장

	printf("\n위에서 입력한 문자열을 거꾸로 출력합니다.\n");
	invertedOutput(sta); //문자열을 거꾸로 출력
	printf("\n");


	/*
	//실습1
	int array[3][3];
	int rowIndex, colIndex;

	printf("정수를 9번 입력하세요\n");
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
	

	
	//실습2
	int scoreArray[20][3]; //학생 수(최대 20), 3과목의 이차원 배열 생성 
	int inputStudentSize;
	int studentIndex;

	printf("입력 받을 학생수를 입력하세요 : ");
	scanf_s("%d", &inputStudentSize); // 학생 수 입력

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		inputScore(&(scoreArray[studentIndex])); //학생의 성적을 입력
	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		printScore(&(scoreArray[studentIndex]), studentIndex);//학생의 성적을 출력
	printf("\n");

	//과제1
	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++){
		printSum(&(scoreArray[studentIndex]), studentIndex);//학생의 성적의 총합을 계산하여 출력
		printAvg(&(scoreArray[studentIndex]));//학생의 성적의 평균을 계산하여 출력
	}
	printf("\n");

	

	//과제3
	srand((unsigned int)time((time_t*)NULL));
	//srand : 랜덤함수
	//(unsigned int) : time을 형변환
	//time_t*로 하여 시간마다 값이 랜덤하게 바뀜

	int arr[MAX];//크기가 20인 배열 생성
	int arraySize;
	printf("배열의 size를 입력하세요(최대 20) : ");
	scanf_s("%d", &arraySize); //20칸 중 값을 저장할 배열의 수 입력

	if (arraySize <= 0) printf("배열 안에 원소가 없습니다.\n"); //배열 안에 값을 저장하지 않음
	else{
		makeArray(arr, arraySize); //배열 안에 랜덤한 값을 저장
		print(arr, arraySize); //배열 출력
		printf("오름차순 정렬\n");
		printf("->");
		sortArray(arr, arraySize); //배열을 오름차순으로 나열
		print(arr, arraySize);//배열 출력
	}
}



//실습 함수
void inputScore(int *scoreArray){
	printf("국어 성적 입력 : ");
	scanf_s("%d", &scoreArray[0]);
	printf("영어 성적 입력 : ");
	scanf_s("%d", &scoreArray[1]);
	printf("수학 성적 입력 : ");
	scanf_s("%d", &scoreArray[2]);
}
void printScore(int *scoreArray, int index){
	printf("[%d] %d, %d, %d\n", index, scoreArray[0], scoreArray[1], scoreArray[2]);
}



//과제1 함수
int printSum(int *scoreArray, int inputIndex){
	int sum = scoreArray[0] + scoreArray[1] + scoreArray[2];//학생의 국어, 영어, 수학 성적의 합 계산
	printf("[%d] 학생의 총점 : %d \n",inputIndex, sum); //계산한 총합을 출력
	return sum;
}
int printAvg(int *scoreArray){
	int avg = (scoreArray[0] + scoreArray[1] + scoreArray[2]) / 3;//학생의 성적의 평균을 계산
	printf("\t- 평균 : %d \n", avg);//계산한 평균을 출력
	return avg;
}



//과제2 함수
void invertedOutput(char str[]){ 
	int length = strlen(str); //length 는 str 의 길이
	for (int i = length - 1; i >= 0; i--){
		printf("%c", str[i]); //배열의 마지막 부터 거꾸로 출력
	}
	printf("\n");
}



//과제3 함수
int makeArray(int* intArray, int inputSize){ //배열 intArray 에 inputSize 만큼의 값을 저장
	for (int i = 0; i < inputSize; i++){
		intArray[i] = rand() % 1000; //저장할 때 원소는 0~999 중 랜덤한 값
	}
}
void swap(int *x, int *y){ //x, y의 원소의 위치를 변경
	int a = *x;
	*x = *y;
	*y = a;
}
void sortArray(int *intArray, int inputSize){ //배열을 오름차순으로 나열
	int i = 0;
	while (i < inputSize){ //배열의 크기만큼 반복
		for (int j = 0; j < inputSize; j++){
			if (intArray[i] < intArray[j]) swap(&intArray[i], &intArray[j]);
											// i 가 증가되어서 j 보다 커지면 
											// if문 안을 실행하여 오름차순으로 배열을 나열
		}
		i++;
	}
}
void print(int *arr, int arraySize){ //배열을 차례로 출력
	printf("배열의 원소 [ ");
	for (int i = 0; i < arraySize; i++){
		printf("%d ", arr[i]);
	}
	printf("] \n\n");
}