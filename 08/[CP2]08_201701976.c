#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int compare(const void * first, const void * second);
void makeLottoNumber(int *lottoNums);
int checkLottoNumber(int *lottoNums);
void swap(int *x, int *y);
void printLottoNumber(int *lottoNums);
void makeBingo(int *bingoArray, int inputSize);
void printBingo(int *bingoArray, int inputSize);
int checkBingo(int *bingoArray, int inputSize);
int getRandomNumber(int *prevNumberList, int inputSize);
int getUserSelectNumber(int *prevNumberList);


int main(void){
	/*
	//실습1
	char animal[20];
	char why[80];

	printf("좋아하는 동물 : ");
	scanf_s("%s", animal, 20);
	//	getchar(); 방법1
	//	scanf_s("%*C"); 방법2
	fgetc(stdin); //방법3
	printf("좋아하는 이유 : ");
	fgets(why, sizeof(why), stdin);
	printf("%s is %s", animal, why);
	printf("\n");
	//원래는 dog 치고 엔터치면 버퍼안에 엔터가 저장되어서
	//좋아하는 이유를 칠때 엔터때문에 입력이 불가능
	//따라서 엔터키를 없애면 가능



	//실습2
	char str[16];
	char res_str[16];
	char *star = "**********";
	int len;

	printf("단어 입력 : ");
	scanf_s("%s", str, 16);
	len = (int)strlen(str);
	if (len <= 5) strcpy_s(res_str, 16, str);
	else{
		strncpy_s(res_str, 16, str, 5);
		res_str[5] = '\0';
		strncat_s(res_str, 16, star, len - 5);
	}
	printf("입력한 단어 : %s, 생략한 단어 : %s\n", str, res_str);
	printf("\n");
	*/



	
	//과제1 - 아스키코드 순서 이용
	char str[200][15]; //전체 문자열
	int len = 0; //전체 문자열의 길이
	int num = 0; //문자를 입력한 횟수
	for (int i = 0; i < 200; i++) { 
		printf("단어 입력 : ");
		gets_s(str[i], 200);
		len += (int)strlen(str[i]); //전체 문자열의 길이에 입력한 문자열의 길이를 더함
		if (len > 200) { // 전체 문자열 길이가 200이 넘으면 메시지 출력 후 종료
			printf("더이상 입력받을 수 없습니다.\n프로그램을 종료합니다.\n\n");
			break;
		}
		if ((int)strlen(str[i]) >= 16) { //입력받은 문자열의 길이가 15를 넘으면 메시지 출력
			printf("문자열의 길이가 깁니다.\n");
			str[i][0] = NULL; //전체 문자열에 저장하지 않음
		}
		if (!strcmp(str[i], "end")) { // end 를 입력받으면 프로그램 종료
			printf("프로그램을 종료합니다.\n\n");
			break;
		}
		num++; //입력한 횟수 카운트
		qsort(str, num, sizeof(str[0]), compare); //아스키 코드 순으로 순서를 바꿔주는 함수
		printf("현재까지 문자열 :"); // 현재까지 저장된(아스키코드 순으로 나열한) 문자열을 출력
		for (int j = 0; j < num; j++) {
			printf("%s ", str[j]);
		}
		printf("\n");
	}
	
	
	
	//과제2
	srand((unsigned int)time((time_t*)NULL));
	int lotto[6]; //크기 6인 lotto배열 생성

	makeLottoNumber(lotto);  // 랜덤한 수를 lotto에 저장 후 오름차순으로 나열
	int a = checkLottoNumber(lotto); //숫자를 입력받고 lotto를 맞춘 개수 반환
	printf("로또 번호 : ");
	for (int i = 0; i < 6; i++){ //lotto번호 출력
		printf("%d ", lotto[i]);
	}
	printf("\n총 %d개의 맞는 숫자가 있습니다.\n", a); //lotto를 맞춘 개수 출력


	
	//과제3
	int bingo[400] = { 0 }; // 20 * 20 사이즈인 bingo 배열을 생성
	int size = 0;

	printf("빙고판 사이즈를 입력하세요 : ");
	scanf_s("%d", &size);
	makeBingo(bingo, size); // 입력한 size * size 크기의 빙고판을 생성
	printBingo(bingo, size); //빙고판을 출력
	if (checkBingo(bingo, size) == 0){ //checkBingo 가 0 이라면(빙고가 있다면) 메시지와 빙고판 출력
		printf("빙고!\n");
		printBingo(bingo, size);
	}
}



//과제1 함수
int compare(const void * first, const void * second) { //qsort 함수를 쓰기 위해 필요한 함수
	return strcmp((char*)first, (char*)second); //입력한 first, second 의 아스키 코드를 비교해줌
}



//과제2 함수
void makeLottoNumber(int *lottoNums){
	for (int i = 0; i < 6; i++){
		lottoNums[i] = rand() % 45 + 1; // 1~45사이의 랜덤 숫자 6개를 배열에 저장
	}
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			if (lottoNums[i] < lottoNums[j]) swap(&lottoNums[i], &lottoNums[j]);
			// 오름차순으로 배열을 swap 하여 나열
		}
	}
}
int checkLottoNumber(int *lottoNums){
	int num[6]; // 사용자가 입력한 6자리 숫자를 저장할 배열
	int same_num = 0; // num 중에 lotto를 맞춘 개수
	int temp = 0;

	printf("번호 입력 : ");
	scanf_s("%d", &num[0]); // num[0]에 입력받은 숫자를 저장

	for (int i = 1; i < 6; i++){ //num 배열이 다 찰때까지 반복
		printf("번호 입력 : ");
		scanf_s("%d", &temp); // temp에 입력한 숫자 저장
		for (int j = 0; j < i; j++){ // j < i 로 밖 for문이 반복되면 안의 for 문의 반복횟수가 ++증가
			if (temp == num[j]) { // temp 와 num 중 같은 숫자가 있으면 안내메시지 출력
				printf("같은 번호가 있습니다!\n");
				i--;
			}
			else num[i] = temp; // temp 가 num 과 중복되지 않는다면 num 배열에 저장
		}
	}
	for (int i = 0; i < 6; i++){ // num 과 lotto 를 비교하여 같은 숫자의 개수 만큼 same_num 증가
		for (int j = 0; j < 6; j++){
			if (lottoNums[i] == num[j]) same_num++;
		}
	}
	return same_num; // same_num 을 반환
}
void swap(int *x, int *y){ // x 와 y 를 바꿈
	int a = *x;
	*x = *y;
	*y = a;
}



//과제3 함수
void makeBingo(int *bingoArray, int inputSize){ 
	int size = inputSize * inputSize;
	int* temp = (int *)malloc(size * sizeof(int)); //size 크기의 temp 생성
	for (int i = 0; i < size; i++){ 
		temp[i] = 0; //모든 temp[i] 에 0 저장
	}
	int num;
	printf("빙고판 생성\n");
	for (int i = 0; i < size; i++){
		num = rand() % size; //num 은 0 ~ size-1 사이의 랜덤한 값
		while (temp[num]){ // temp[num] 이 1 이면(중복의 의미) while문을 실행(= num에 랜덤한 값 다시 저장)
			num = rand() % size;		// 1이 아니면(= 0 이면/ 중복이 아니란 의미) while문을 실행하지 않음
		}
		bingoArray[i] = num + 1; //bingo 배열에 num + 1 을 저장
								// +1 을 하는 이유 : num 은 0 ~ size-1 사이의 랜덤한 값이고
								// 빙고판에 저장될 수는 1 ~ size 이기 때문
		temp[num] = 1; // 한 번 저장했다면 temp[num] 을 1로 저장 (중복의 의미)
	}
}
void printBingo(int *bingoArray, int inputSize){ //빙고판을 출력
	int i, j = 1;
	for (i = 0; i < inputSize*inputSize; i++, j++){
		if (bingoArray[i] == 0) printf("  * "); // 빙고판의 숫자가 0 이라면(추출된 자리) * 로 출력
		else printf("%3d ", bingoArray[i]); 
		if (j % inputSize == 0){ //inputSize 에 따라 1줄 띄우기
			printf("\n");
		}
	}
	printf("\n");
}
int checkBingo(int *bingoArray, int inputSize){
	int i, j, a, b, choice, count = 0;
	int size = inputSize*inputSize;
	int prevNumberList[100] = { 0 };
	while (1){
		printf("숫자 추출 방법을 선택[1:랜덤][2:사용자입력] : ");
		scanf_s("%d", &choice); //방법을 선택
		if (choice== 1){ //1이면 getRandomNumber 사용
			a = getRandomNumber(prevNumberList, inputSize);
			printf("랜덤 숫자를 추출 : %d\n", a);
			for (i = 0; i<size; i++){ //빙고판에서 추출한 숫자가 있던 자리를 0 으로 저장
				if (bingoArray[i] == a)
					bingoArray[i] = 0;
			}
		}
		if (choice == 2){ //2이면 getUserSelectNumber 사용
			b = getUserSelectNumber(prevNumberList);
			if (b == -1)
				printf("이미 입력된 숫자입니다.\n");
			for (i = 0; i<size; i++){ //빙고판에서 추출한 숫자가 있던 자리를 0 으로 저장
				if (bingoArray[i] == b)
					bingoArray[i] = 0;
			}
		}
		//빙고 확인 4가지 : 가로, 세로, 대각선, 역대각선 중 1줄이 0 일 때 빙고
		for (i = 0; i < size; i = i + inputSize) { //가로줄 빙고 확인
			for (j = 0; j < inputSize; j++) {
				count += bingoArray[i + j];
			}
			if (count == 0) {
				return 0;
			}
			count = 0;
		}
		for (j = 0; j < inputSize; j++) {//세로줄 빙고 확인
			for (i = 0; i < size; i = i + inputSize) {
				count += bingoArray[i + j];
			}
			if (count == 0) {
				return 0;
			}
			count = 0;
		}
		for (i = 0, j = 0; i < size; i = i + inputSize, j++) {//대각선 빙고 확인
			count += bingoArray[i + j];
		}
		if (count == 0) {
			return 0;
		}
		count = 0;

		for (i = 0, j = inputSize - 1; i < size; i = i + inputSize, j--) {//대각선 빙고 확인
			count += bingoArray[i + j];      
		}
		if (count == 0) {
			return 0;
		}
		count = 0;
	}
	return 0;
}

int getRandomNumber(int *prevNumberList, int inputSize){
	int i, j, n;
	int size = inputSize*inputSize;
	for (i = 0; i<400; i++){
		if (prevNumberList[i] == 0) //prevNumberList[i]가 0 이면(이미 추출된 자리) 멈춤
			break;
	}
	n = prevNumberList[i] = rand() % size + 1; //랜덤한 값을 추출하여 배열에 저장
	for (j = 0; j<i; j++){
		if (prevNumberList[i] == prevNumberList[j]){  //배열에 중복되는지 검사하여 있다면 다시 추출
			n = prevNumberList[i] = rand() % size + 1;
			j = -1;
		}
	}
	return n;

}
int getUserSelectNumber(int *prevNumberList){
	int i, j;
	for (i = 0; i<400; i++){
		if (prevNumberList[i] == 0) //prevNumberList[i]가 0 이면(이미 추출된 자리) 멈춤
			break;
	}
	printf("사용자 선택 숫자 입력 : ");
	scanf_s("%d", &prevNumberList[i]); //입력한 수를 배열에 저장 후 비교하여 있다면 -1을 저장
	for (j = 0; j<i; j++){
		if (prevNumberList[i] == prevNumberList[j]){
			prevNumberList[i] = -1;
		}
	}
	return prevNumberList[i];

}
