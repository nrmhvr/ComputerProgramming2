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
	//실습1
	int arr[4];

	printf("수학 점수를 입력하세요 : ");
	scanf_s("%d", &arr[0]);
	printf("영어 점수를 입력하세요 : ");
	scanf_s("%d", &arr[1]);
	printf("국어 점수를 입력하세요 : ");
	scanf_s("%d", &arr[2]);

	arr[3] = arr[0] + arr[1] + arr[2];
	printf("\n");
	printf("수학 : %d\n", arr[0]);
	printf("영어 : %d\n", arr[1]);
	printf("국어 : %d\n", arr[2]);
	printf("합계 : %d\n", arr[3]);
	printf("평균 : %.2f\n\n", arr[3]/3.0);





	//실습2
	int arr2[5];
	int i, sum = 0;

	for (i = 1; i <= 5; i++){
		printf("%d 번째 학생의 성적 : ", i);
		scanf_s("%d", &arr2[i - 1]);
	}
	
	printf("<< 입력한 학생들의 성적 >>\n");
	for (i = 0; i < 5; i++){
		printf("%d ", arr2[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++){
		sum += arr2[i];
	}
	printf("학생들의 총 합계 : %d\n", sum);
	printf("학생들의 평균 점수 : %2.f\n", sum / 5.0);
	*/

	

	

	//과제1

	srand((unsigned int)time((time_t*)NULL));
	//srand : 랜덤함수
	//(unsigned int) : time을 형변환
	//time_t*로 하여 시간마다 값이 랜덤하게 바뀜

	int array[MAX]; //크기 20인 배열을 생성
	int size, min, max;

	printf("저장할 size를 입력하세요(최대 20) : ");
	scanf_s("%d", &size); //20칸 중 값을 저장할 배열의 수 입력

	if (size == 0) printf("배열 안에 원소가 없습니다.\n"); //배열 안에 값을 저장하지 않음
	else{
		printf("배열의 원소 [ ");
		makeArray(array, size);
		for (int i = 0; i < size; i++){
			printf("%d ", array[i]);
		}
		printf("] \n"); //배열의 원소를 차례로 출력

		printf("배열의 원소의 합 : ");
		printf("%d\n", calSum(array, size)); //원소들의 합 출력
		printf("배열의 원소의 평균 : ");
		printf("%d\n", calAvg(array, size)); //원소들의 평균 출력
		printf("배열의 원소의 최소값 : ");
		printf("%d\n", findMin(array, size)); //원소 중 최소값 출력
		printf("배열의 원소의 최대값 : ");
		printf("%d\n", findMax(array, size)); //원소 중 최대값 출력

		printf("\n재귀함수를 사용하여 최소값, 최대값 찾기\n");
		printf("배열의 원소의 최소값 : ");
		printf("%d\n", findMin2(array, size)); //원소 중 최소값 출력
		printf("배열의 원소의 최대값 : ");
		printf("%d\n", findMax2(array, size)); //원소 중 최대값 출력
	}

	return 0;
}
int makeArray(int* intArray, int inputSize){ //배열 intArray 에 inputSize 만큼의 값을 저장
	for (int i = 0; i < inputSize; i++){
		intArray[i] = rand()%1000; //저장할 때 원소는 0~999 중 랜덤한 값
	}
}
int calSum(int* intArray, int arraySize){ //배열 intArray 의 [0] ~ [arraySize-1] 까지의 원소들의 합을 return
	int sum = 0;
	for (int i = 0; i < arraySize; i++){ //반복을 통해 원소를 합한다
		sum += intArray[i];
	}
	return sum;
}
int calAvg(int* intArray, int arraySize){ //배열 intArray 의 [0] ~ [arraySize-1] 까지의 원소들의 평균을 return
	int Avg = calSum(intArray, arraySize) / arraySize;
	return Avg;
}
int findMin(int* intArray, int arraySize){ //배열 intArray 의 [0] ~ [arraySize-1] 까지의 원소들 중 최소값을 return
	int Min = intArray[0];
	for (int i = 1; i < arraySize; i++){ //반복을 통해 원소의 값을 비교
		if (Min > intArray[i]) Min = intArray[i];
	}
	return Min;
}
int findMax(int* intArray, int arraySize){  //배열 intArray 의 [0] ~ [arraySize-1] 까지의 원소들 중 최대값을 return
	int Max = intArray[0];
	for (int i = 1; i < arraySize; i++){ //반복을 통해 원소의 값을 비교
		if (Max < intArray[i]) Max = intArray[i];
	}
	return Max;
}

//과제2
int findMin2(int* intArray, int arraySize){
	if (arraySize == 1) return intArray[0];//배열에 원소가 하나밖에 없을 때 그 원소를 return

	int min = findMin2(intArray+1, arraySize-1); /*min 은 size가 1인 intArray의 배열
												 -> 재귀함수 사용으로 배열을 따라 순차적으로 min 이 바뀜 */
												
	if (intArray[0] > min) return min; //intArray[0]과 min을 비교하여 더 작은 값을 return 
	else return intArray[0];
}
int findMax2(int* intArray, int arraySize){
	int middle = arraySize / 2; //arraySize 를 반으로 나눔
	if (arraySize == 1) return intArray[0]; //배열에 원소가 하나밖에 없을 때 그 원소를 return

	int max1 = findMax2(intArray, middle); /* 배열의 처음 ~ 중간 까지에서 findMax2를 재귀
											 -> max1 안에서 또  max1, max2 로 나뉜 후 findMax2를 재귀 -> 반복
											-> size가 1 이고 intArray의 배열인 max1, max2가 존재 */

	int max2 = findMax2(intArray + middle, arraySize - middle); /*배열의 중간 ~ 끝 까지에서 findMax2를 재귀
														     -> max2 안에서 또  max1, max2 로 나뉜 후 findMax2를 재귀 -> 반복
														     -> size가 1 이고 intArray의 배열인 max1, max2가 존재 */

	if (max1 > max2) return max1; //max1 과 max2 를 비교하여 더 큰 값을 return
	else return max2;
}









