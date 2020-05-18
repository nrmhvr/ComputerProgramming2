#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cracker{
	int price;
	int calories;
};
typedef struct{
	int student_num;
	char name[20];
	int eng_score;
	int kor_score;
	int math_score;
	int sum_score;
	double average;
	char grade;
} Student;

int dup_check(char **sp, char *temp, int cnt);

void input_data(Student *pary, int inputSize);
void calc_data(Student *pary, int inputSize);
void sort_data(Student *pary, int inputSize);
void swap(Student *x, Student *y);
void print_data(Student *pary, int inputSize);

int main(void){
	/*
	//실습1
	char temp[32]; // 임시 temp 배열 선언
	char *ps, *pt; // 할당한 저장 공간을 연결할 포인터 ps
	// 저장 공간 크기 조절을 위한 포인터 pt
	int len = 1; //메모 길이 변수
	ps = (char *)calloc(1, 1); // 저장 공간 할당
	while (1){ // break 될 때까지 반복
	printf("메모입력 : ");
	fgets(temp, sizeof(temp), stdin); // 메모 입력
	temp[strlen(temp) - 1] = '\0'; // temp 에 입력된 메모의 다음 인덱스에 \0 저장
	if (strcmp(temp, "end") == 0) break; // 입력한 메모가 end 이면 break
	len += strlen(temp) + 1; // 메모 길이 갱신
	pt = (char *)realloc(ps, len); // pt 의 저장 공간 크기 조절
	if (pt == NULL){ // 저장 공간이 null 이면 break
	printf("메모리 부족....\n");
	break;
	}
	ps = pt; // ps 에 pt 저장
	strcat_s(ps, len, temp); // ps 에 temp 를 이어붙임
	strcat_s(ps, len , " "); // temp 뒤에 빈칸 이어붙임
	}
	printf("%s\n\n", ps); // break 해서 while문을 나온다면 입력한 데이터 출력
	free(ps); //동적 할당 저장 공간 반납



	//실습2
	struct cracker basasak; // cracker 구조체를 사용하는 basask 선언
	printf("바사삭의 가격과 열량을 입력하세요 : ");
	scanf_s("%d %d", &basasak.price, &basasak.calories);
	// basasak 의 가격과 열량을 저장
	printf("바사삭의 가격 : %d원\n", basasak.price); // 가격 출력
	printf("바사삭의 열량 : %dkacl\n\n", basasak.calories); // 열량 출력
	*/



	//과제1
	char temp[100]; // 단어를 임시 저장할 temp 선언
	char prev[100]; // 전 단어를 저장할 prev 선언
	char *sp[100]; // 전체 문자열을 저장할 sp 선언
	int i = 0, len = 1; //반복 횟수 변수 i, 길이 변수 len 선언

	while (i < 100){ // 단어입력 반복 제한(최대 100번) 
		printf("단어 입력 : ");
		fgets(temp, sizeof(temp), stdin); //단어 입력
		temp[strlen(temp) - 1] = '\0'; // temp의 단어 뒤 인덱스에 \0 저장
		if (strcmp(temp, "end") == 0) break; // end 를 입력하면 break
		if (i == 0){ // 첫 번째 입력일때
			len = strlen(temp) + 1; // temp 길이 저장
			sp[i] = (char *)malloc(len); // sp[i] 에 공간 할당
			strcpy(prev, temp); // prev 에 temp 복사
			strcpy(sp[i], temp);// sp[i] 에 temp 복사
			i++; //반복횟수 증가
		}
		else{ // 첫 번째 입력이 아닐 때
			if (prev[strlen(prev) - 1] != temp[0]){ //이전 단어의 끝과 입력한 단어의 처음이 다르면
				printf("> 단어 잇기가 불가능합니다!\n"); // 단어 잇기 불가능
			}
			else{ //단어 잇기가 가능할 때
				if (dup_check(sp, temp, i) > 0){ // 중복이 아니면
					len = strlen(temp) + 1; //temp 길이 저장
					sp[i] = (char *)malloc(len); // sp[i] 에 공간 할당
					strcpy(prev, temp); // prev 에 temp 복사
					strcpy(sp[i], temp); // sp[i] 에 temp 복사
					i++; //반복횟수 증가
				}
				else{ //중복이면
					printf("> 이미 존재하는 단어입니다!\n"); //메세지 출력, sp 에 저장안함
				}
			}
		}
	}
	int j;
	for (j = 0; j < i; j++){
		printf("%s ", sp[j]); // sp 에 저장된 단어 출력
	}
	for (j = 0; j < i; j++){
		free(sp[j]); //저장 공간 반납
	}
	printf("\n");
	

	
	//과제2
	Student student[100]; //Student 구조체를 사용하는
						//student[100] (최대 학생 수 100) 배열 선언
	int cnt; // 학생수를 저장하기 위한 cnt 선언

	printf("> 학생수 입력 : ");
	scanf_s("%d", &cnt); // 학생 수 입력
	input_data(student, cnt); // 학생 수 만큼 학생의 정보 입력
	calc_data(student, cnt); // 입력한 학생들의 성적 계산
	printf("정렬 전 데이터...\n"); 
	print_data(student, cnt); //정렬 전 데이터 출력
	printf("정렬 후 데이터...\n");
	sort_data(student, cnt); // 성적 순으로 데이터 정렬
	print_data(student, cnt); //정렬 후 데이터 출력
	
	return 0;
}

//과제1 함수
int dup_check(char **sp, char *temp, int cnt){ // 이미 있는 단어인지 검사하는 함수
	int i;
	for (i = 0; i < cnt - 1; i++){
		if(strcmp(sp[i], temp) == 0){ //sp[i] 와 temp 가 같으면 중복
			return 0;// 중복단어
		}
	}
	return 1; // 중복이 아님
}



//과제2 함수
void input_data(Student *pary, int inputSize){ //정보 입력 함수
	int i = 0;
	while (i < inputSize){ // inputSize 만큼 입력을 반복
		printf("> 학번 : ");
		scanf("%d", &pary[i].student_num); // 학생 [i] 의 학번 입력, 저장
		
		printf("> 이름 : ");
		scanf("%s", &pary[i].name); // 학생 [i] 의 이름 입력, 저장

		printf("> 국어, 영어, 수학 점수 : ");
		scanf("%d %d %d", &pary[i].kor_score, &pary[i].eng_score, &pary[i].math_score);
		i++;
		// 학생 [i] 의 과목 당 점수 입력, 저장
	}
}
void calc_data(Student *pary, int inputSize){ // 총점, 평균, 학점 계산 함수
	int i = 0;
	while (i < inputSize){ // inputSize 만큼 계산 반복
		pary[i].sum_score = (pary[i].kor_score + pary[i].eng_score + pary[i].math_score); // 학생 [i] 의 총점 계산
		pary[i].average = (double) pary[i].sum_score / 3; // 학생 [i] 의 평균 계산
		if (pary[i].average >= 90){ // 학생 [i] 의 평균 점수에 따른 학점 계산, 평균이 90 이상일 때 학점 A
			pary[i].grade = 'A';
		}
		else if (pary[i].average >= 80){ // 평균이 80이상일 때 학점 B
			pary[i].grade = 'B';
		}
		else if (pary[i].average >= 70){ // 70 이상일 때 C
			pary[i].grade = 'C';
		}
		else{ // 나머지(70 미만) F
			pary[i].grade = 'F';
		}
		i++;
	}
}
void sort_data(Student *pary, int inputSize){ //데이터를 성적순으로 정렬하는 함수
	int i = 0, j;
	while (i < inputSize){ // inputSize 만큼 반복
		for (j = 0; j < inputSize; j++){ 
			if (pary[i].average > pary[j].average) { // 평균을 비교하여 [i] > [j] 라면
				swap(&pary[i], &pary[j]); // 두 데이터의 위치를 스왑
			}
		}
		i++;
	}
}
void swap(Student *x, Student *y){ //입력한 x, y 의 데이터를 바꿔주는 함수
	Student a = *x;
	*x = *y;
	*y = a;
}
void print_data(Student *pary, int inputSize){ // 학생 데이터 출력 함수
	int i = 0;
	while (i < inputSize){ // inputSize 만큼 반복
		printf("%d %s %d %d %d %d %.1lf %c", pary[i].student_num, pary[i].name, pary[i].kor_score,
			pary[i].eng_score, pary[i].math_score, pary[i].sum_score, pary[i].average, pary[i].grade);
		printf("\n");
		i++;
		// 학생 [i] 의 학번, 이름, 과목 당 점수, 총점, 평균, 학점을 출력
	}
	printf("\n");
}