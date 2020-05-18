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
	
	//�ǽ�1
	int a = 10, b = 20;
	int *pa = &a, *pb = &b; // *pa �� a �� �ּ� ����, *pb �� b �� �ּ� ��
	int **ppa = &pa, **ppb = &pb; // *ppa �� pa�� �ּ� ����, **ppa �� a �� �ּ� ����
	//  *ppb �� pb �� �ּ� ����, **ppb �� b �� �ּ� ����
	int *pt;

	pt = *ppa; // pt �� &pa �� �� => pt = &pa == &a == 10
	*ppa = *ppb; // &pa �� &pb �� �� => &pa = &pb == &b == 20;
	*ppb = pt; // &pb �� pt�� �� = 10 => &pb = pt == 10

	// ���� pa �� �ּҰ� pb �� �ּ��̰� pb �� �ּҴ� pt �̹Ƿ�
	// *pa �� ����ϸ� pb �ȿ� �ִ� b �� �ּ� = 20 �� ��µȴ�.
	// *pb �� ����ϸ� pt = 10 �� ��µȴ�.

	printf("a:%d, b:%d\n", a, b); //a �� b �� ����� ���� ���
	printf("*pd:%d, *pb:%d\n\n", *pa, *pb);

	
}
*/



int main(int argc, const char * argv[]){

	//����1
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
	int same_num[12][2]; // 12�� 2�� �� �迭 ����
	int i, cnt;
	cnt = count_num(ary1, ary2, same_num); //�� �迭�� ���Ұ� ��ġ�ϴ� ���� = cnt
	printf("��ġ�ϴ� ��ȣ�� �� : %d\n", cnt);
	printf("�迭������ ��ġ(��, ��)...\n");

	for (i = 0; i < cnt; i++){
		printf("(%d, %d)\n", same_num[i][0], same_num[i][1]);
		//same_num �� ����(��ġ�ϴ� ������ ��ġ) ���
	}
	printf("\n");
	


	//����2
	assign02();
	printf("\n");



	//����3
	assign03();
}




//����1 �Լ�
int count_num(int (*a)[4], int (*b)[4], int (*c)[2]){
	int count = 0, n = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){ //�� �迭 a, b �� ��� ���Ҹ� ���Ͽ�
			if (a[i][j] == b[i][j]){ // ���Ұ� ���ٸ�
				count++; // �� �迭�� ���Ұ� ��ġ�ϴ� ���� ����
				c[n][0] = i; // �迭 c �� 1�� �� �࿡ i ����
				c[n][1] = j; // �迭 c �� 2�� �� �࿡ j ���� 
							//  -> ex) c �� �� : (i, j)
				n++; // ���� �� ���� �࿡ �����ϱ� ���� n ����
			}
		}
	}
	return count; //�� �迭�� ���Ұ� ��ġ�ϴ� ���� ��ȯ
}



//����2 �Լ�
void exchange(double *a, double *b){ //a �� b �� ����Ű�� ���� �ּҸ� ��ȯ
	double temp; //�ӽ� temp
	temp = *a; // temp �� �ӽ÷� a �� �ּ� ����
	*a = *b; // a �� �ּҴ� b �� �ּ�
	*b = temp; // b �� �ּҴ� temp(a �� �ּ�)
}
void func(void(*fp)(double *a, double *b), double a, double b){//�Լ��� ���� ��, �ĸ� ���
	printf("a : %.1lf, b = %.1lf\n", a, b); //�Լ��� ���� �� a, b �� �� ���
	fp(&a, &b); // �Լ� fp (= exchange) ��� -> a, b �� �ּҰ� ��ȯ�� 
	printf("a : %.1lf, b = %.1lf\n", a, b); //�Լ� ��� �� �ּҰ� ��ȯ�� a, b �� �� ���
}
int assign02(void){
	double a = 10, b = 20;
	func(exchange, a, b); // void �����͸� ����Ͽ� exchange �Լ��� �ּҸ� func �Լ��� ���ڷ� ���
	return 0;
}



//����3 �Լ�
int input_intro(char(*intro)[80]){ //intro �� 10�� 80��
	int cnt = 0;
	for(int i = 0; i < 10 ;i++){ // 10���̹Ƿ� �Է��� �ִ� 10�� ����
 		printf("> ���� �Է� : ");
		gets_s(intro[i], 80); //intro �� �Էµ� ���ڸ� ����
		if (!strcmp(intro[i], "end")){ // 'end' �� �Է��� �� �Է�����
			break; 
		}
		cnt++; //���ڸ� �� �� �Է��ߴ��� ���
	}
	return cnt; // ���ڸ� �Է��� Ƚ�� ��ȯ
}
void init_intro(char(*intro)[80], char **intp){ //intro �� intp �� ����
	for (int i = 0; i < 10; i++) { //�Է��� �ִ� 10�� �ϹǷ� 10�� ���� �ݺ�
			intp[i] = &intro[i]; // intp[i] �� intrp[i] �� �ּҸ� ����
								// -> ex) *intp[0]  =  &intro[0](= intro[0][] = �� ��)
	}
}
void sort_intro(char **intp, int cnt){ //���� ������ ����
	char *temp; //�ӽ� temp
	for (int i = 0; i < cnt - 1; i++){ // �Է��� 10�� ���� ��(cnt == 10) ���� �������� ������ ����
										// �ݺ��� (�� ���� ���ϹǷ�) 9�� �ϸ� �ȴ�.
										// -> cnt - 1 ��ŭ �ݺ�
		for (int j = 0; j < cnt - i - 1; j++){ // cnt, i �� ���� ��Ƚ���� �޶����µ�
												// cnt - i - 1 ��ŭ �ݺ��Ѵ�.
												//  -> ex) cnt = 7 �̸� i = 0 �϶� 6��, i = 1 �϶� 5��...
			if (strcmp(intp[j], intp[j + 1])>0){// ���ڿ��� ���Ͽ� intp[j] �� intp[j + 1]���� 
												// ũ�ٸ� = j �� ����� ������ �� �����ٸ�
				temp = intp[j];
				intp[j] = intp[j + 1];
				intp[j + 1] = temp;
				// temp �� ����Ͽ� ���� ���Ҹ� ����
			}
		}
	}
}
void print_intro(int mode, void *vp, int cnt){ //���ڿ� ���
	if (mode == 1){ // mode �� 1 �̸� ���������� ���
		printf("\n���������� ���...\n");
		for (int i = 0; i < cnt; i++){ // cnt ��ŭ
			printf("%s \n", *((char **)vp + i)); // *intp[i] �� ���ʷ� (*intp[0], *intp[1], ...) ���
		}
	}
	if (mode == 0){ // mode �� 0 �̸� �Է¼����� ���
		printf("\n�Է¼����� ���...\n");
		for (int j = 0; j < cnt; j++){ // cnt ��ŭ
			printf("%s \n", ((char *)vp) + 80 * j); // intro �� ���� ���ʷ� (intro[0][], intro[1][], ...) ���
		}
	}
}
int assign03(void){
	char intro[10][80];
	char *intp[10];
	int cnt;

	init_intro(intro, intp); // intp �� intro �� ����
	cnt = input_intro(intro); //�Լ��� ���� ���ڸ� �Է¹ް� �� �Է��� Ƚ���� cnt �� ����
	sort_intro(intp, cnt); // intp �� ���������� ����
	print_intro(1, intp, cnt); //���� ���� intp ���
	print_intro(0, intro, cnt); //�Է� ���� intro ���
	return 0;
}