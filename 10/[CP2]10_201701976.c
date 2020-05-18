#include <stdio.h>


int count_num(int (*a)[4], int (*b)[4], int (*c)[2]);
void exchange(double *a, double *b);
void func(void(*fp)(double *a, double *b), double c, double d);
int assign02(void);
int input_intro(char(*intro)[80]);
void init_intro(char(*intro)[80], char **intp);
void sort_intro(char **intp, int cnt);
void print_intro(int mode, void *vp, int cnt);
int assign03(void);

/*
int main(void){
	
	//실습1
	int a = 10, b = 20;
	int *pa = &a, *pb = &b; // *pa 가 a 의 주소 참조, *pb 가 b 의 주소 참
	int **ppa = &pa, **ppb = &pb; // *ppa 가 pa의 주소 참조, **ppa 가 a 의 주소 참조
	//  *ppb 가 pb 의 주소 참조, **ppb 가 b 의 주소 참조
	int *pt;

	pt = *ppa; // pt 는 &pa 의 값 => pt = &pa == &a == 10
	*ppa = *ppb; // &pa 는 &pb 의 값 => &pa = &pb == &b == 20;
	*ppb = pt; // &pb 는 pt의 값 = 10 => &pb = pt == 10

	// 따라서 pa 의 주소가 pb 의 주소이고 pb 의 주소는 pt 이므로
	// *pa 를 출력하면 pb 안에 있는 b 의 주소 = 20 이 출력된다.
	// *pb 를 출력하면 pt = 10 이 출력된다.

	printf("a:%d, b:%d\n", a, b); //a 와 b 에 저장된 값을 출력
	printf("*pd:%d, *pb:%d\n\n", *pa, *pb);

	
}
*/



int main(int argc, const char * argv[]){

	//과제1
	int ary1[3][4] = {
		{ 15, 3, 9, 11 },
		{ 23, 7, 10, 12 },
		{ 0, 17, 55, 24 }
	};
	int ary2[3][4] = {
		{ 13, 8, 9, 15 },
		{ 23, 0, 10, 11 },
		{ 29, 17, 43, 3 }
	};
	int same_num[12][2]; // 12행 2열 인 배열 생성
	int i, cnt;
	cnt = count_num(ary1, ary2, same_num); //두 배열의 원소가 일치하는 개수 = cnt
	printf("일치하는 번호의 수 : %d\n", cnt);
	printf("배열에서의 위치(행, 열)...\n");

	for (i = 0; i < cnt; i++){
		printf("(%d, %d)\n", same_num[i][0], same_num[i][1]);
		//same_num 의 원소(일치하는 원소의 위치) 출력
	}
	printf("\n");
	


	//과제2
	assign02();
	printf("\n");



	//과제3
	assign03();
}




//과제1 함수
int count_num(int (*a)[4], int (*b)[4], int (*c)[2]){
	int count = 0, n = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){ //두 배열 a, b 의 모든 원소를 비교하여
			if (a[i][j] == b[i][j]){ // 원소가 같다면
				count++; // 두 배열의 원소가 일치하는 개수 증가
				c[n][0] = i; // 배열 c 의 1열 인 행에 i 저장
				c[n][1] = j; // 배열 c 의 2열 인 행에 j 저장 
							//  -> ex) c 의 행 : (i, j)
				n++; // 저장 후 다음 행에 저장하기 위해 n 증가
			}
		}
	}
	return count; //두 배열의 원소가 일치하는 개수 반환
}



//과제2 함수
void exchange(double *a, double *b){ //a 와 b 가 가리키는 값의 주소를 교환
	double temp; //임시 temp
	temp = *a; // temp 에 임시로 a 의 주소 저장
	*a = *b; // a 의 주소는 b 의 주소
	*b = temp; // b 의 주소는 temp(a 의 주소)
}
void func(void(*fp)(double *a, double *b), double a, double b){//함수를 쓰기 전, 후를 출력
	printf("a : %.1lf, b = %.1lf\n", a, b); //함수를 쓰기 전 a, b 의 값 출력
	fp(&a, &b); // 함수 fp (= exchange) 사용 -> a, b 의 주소가 교환됨 
	printf("a : %.1lf, b = %.1lf\n", a, b); //함수 사용 후 주소가 교환된 a, b 의 값 출력
}
int assign02(void){
	double a = 10, b = 20;
	func(exchange, a, b); // void 포인터를 사용하여 exchange 함수의 주소를 func 함수의 인자로 사용
	return 0;
}



//과제3 함수
int input_intro(char(*intro)[80]){ //intro 는 10행 80열
	int cnt = 0;
	for(int i = 0; i < 10 ;i++){ // 10행이므로 입력은 최대 10번 가능
 		printf("> 문장 입력 : ");
		gets_s(intro[i], 80); //intro 에 입력된 문자를 저장
		if (!strcmp(intro[i], "end")){ // 'end' 를 입력할 시 입력종료
			break; 
		}
		cnt++; //문자를 몇 번 입력했는지 계산
	}
	return cnt; // 문자를 입력한 횟수 반환
}
void init_intro(char(*intro)[80], char **intp){ //intro 를 intp 에 복사
	for (int i = 0; i < 10; i++) { //입력은 최대 10번 하므로 10번 동안 반복
			intp[i] = &intro[i]; // intp[i] 에 intrp[i] 의 주소를 저장
								// -> ex) *intp[0]  =  &intro[0](= intro[0][] = 한 행)
	}
}
void sort_intro(char **intp, int cnt){ //사전 순으로 정렬
	char *temp; //임시 temp
	for (int i = 0; i < cnt - 1; i++){ // 입력을 10번 했을 때(cnt == 10) 사전 순으로의 정렬을 위한
										// 반복은 (두 값을 비교하므로) 9번 하면 된다.
										// -> cnt - 1 만큼 반복
		for (int j = 0; j < cnt - i - 1; j++){ // cnt, i 에 따라 비교횟수가 달라지는데
												// cnt - i - 1 만큼 반복한다.
												//  -> ex) cnt = 7 이면 i = 0 일때 6번, i = 1 일때 5번...
			if (strcmp(intp[j], intp[j + 1])>0){// 문자열을 비교하여 intp[j] 가 intp[j + 1]보다 
												// 크다면 = j 인 경우의 순서가 더 빠르다면
				temp = intp[j];
				intp[j] = intp[j + 1];
				intp[j + 1] = temp;
				// temp 를 사용하여 둘의 원소를 변경
			}
		}
	}
}
void print_intro(int mode, void *vp, int cnt){ //문자열 출력
	if (mode == 1){ // mode 가 1 이면 사전순으로 출력
		printf("\n사전순으로 출력...\n");
		for (int i = 0; i < cnt; i++){ // cnt 만큼
			printf("%s \n", *((char **)vp + i)); // *intp[i] 를 차례로 (*intp[0], *intp[1], ...) 출력
		}
	}
	if (mode == 0){ // mode 가 0 이면 입력순으로 출력
		printf("\n입력순으로 출력...\n");
		for (int j = 0; j < cnt; j++){ // cnt 만큼
			printf("%s \n", ((char *)vp) + 80 * j); // intro 의 행을 차례로 (intro[0][], intro[1][], ...) 출력
		}
	}
}
int assign03(void){
	char intro[10][80];
	char *intp[10];
	int cnt;

	init_intro(intro, intp); // intp 는 intro 의 복사
	cnt = input_intro(intro); //함수를 통해 문자를 입력받고 총 입력한 횟수를 cnt 에 저장
	sort_intro(intp, cnt); // intp 를 사전순으로 정렬
	print_intro(1, intp, cnt); //사전 순인 intp 출력
	print_intro(0, intro, cnt); //입력 순인 intro 출력
	return 0;
}