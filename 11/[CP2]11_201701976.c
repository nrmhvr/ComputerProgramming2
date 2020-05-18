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
	//�ǽ�1
	char temp[32]; // �ӽ� temp �迭 ����
	char *ps, *pt; // �Ҵ��� ���� ������ ������ ������ ps
	// ���� ���� ũ�� ������ ���� ������ pt
	int len = 1; //�޸� ���� ����
	ps = (char *)calloc(1, 1); // ���� ���� �Ҵ�
	while (1){ // break �� ������ �ݺ�
	printf("�޸��Է� : ");
	fgets(temp, sizeof(temp), stdin); // �޸� �Է�
	temp[strlen(temp) - 1] = '\0'; // temp �� �Էµ� �޸��� ���� �ε����� \0 ����
	if (strcmp(temp, "end") == 0) break; // �Է��� �޸� end �̸� break
	len += strlen(temp) + 1; // �޸� ���� ����
	pt = (char *)realloc(ps, len); // pt �� ���� ���� ũ�� ����
	if (pt == NULL){ // ���� ������ null �̸� break
	printf("�޸� ����....\n");
	break;
	}
	ps = pt; // ps �� pt ����
	strcat_s(ps, len, temp); // ps �� temp �� �̾����
	strcat_s(ps, len , " "); // temp �ڿ� ��ĭ �̾����
	}
	printf("%s\n\n", ps); // break �ؼ� while���� ���´ٸ� �Է��� ������ ���
	free(ps); //���� �Ҵ� ���� ���� �ݳ�



	//�ǽ�2
	struct cracker basasak; // cracker ����ü�� ����ϴ� basask ����
	printf("�ٻ���� ���ݰ� ������ �Է��ϼ��� : ");
	scanf_s("%d %d", &basasak.price, &basasak.calories);
	// basasak �� ���ݰ� ������ ����
	printf("�ٻ���� ���� : %d��\n", basasak.price); // ���� ���
	printf("�ٻ���� ���� : %dkacl\n\n", basasak.calories); // ���� ���
	*/



	//����1
	char temp[100]; // �ܾ �ӽ� ������ temp ����
	char prev[100]; // �� �ܾ ������ prev ����
	char *sp[100]; // ��ü ���ڿ��� ������ sp ����
	int i = 0, len = 1; //�ݺ� Ƚ�� ���� i, ���� ���� len ����

	while (i < 100){ // �ܾ��Է� �ݺ� ����(�ִ� 100��) 
		printf("�ܾ� �Է� : ");
		fgets(temp, sizeof(temp), stdin); //�ܾ� �Է�
		temp[strlen(temp) - 1] = '\0'; // temp�� �ܾ� �� �ε����� \0 ����
		if (strcmp(temp, "end") == 0) break; // end �� �Է��ϸ� break
		if (i == 0){ // ù ��° �Է��϶�
			len = strlen(temp) + 1; // temp ���� ����
			sp[i] = (char *)malloc(len); // sp[i] �� ���� �Ҵ�
			strcpy(prev, temp); // prev �� temp ����
			strcpy(sp[i], temp);// sp[i] �� temp ����
			i++; //�ݺ�Ƚ�� ����
		}
		else{ // ù ��° �Է��� �ƴ� ��
			if (prev[strlen(prev) - 1] != temp[0]){ //���� �ܾ��� ���� �Է��� �ܾ��� ó���� �ٸ���
				printf("> �ܾ� �ձⰡ �Ұ����մϴ�!\n"); // �ܾ� �ձ� �Ұ���
			}
			else{ //�ܾ� �ձⰡ ������ ��
				if (dup_check(sp, temp, i) > 0){ // �ߺ��� �ƴϸ�
					len = strlen(temp) + 1; //temp ���� ����
					sp[i] = (char *)malloc(len); // sp[i] �� ���� �Ҵ�
					strcpy(prev, temp); // prev �� temp ����
					strcpy(sp[i], temp); // sp[i] �� temp ����
					i++; //�ݺ�Ƚ�� ����
				}
				else{ //�ߺ��̸�
					printf("> �̹� �����ϴ� �ܾ��Դϴ�!\n"); //�޼��� ���, sp �� �������
				}
			}
		}
	}
	int j;
	for (j = 0; j < i; j++){
		printf("%s ", sp[j]); // sp �� ����� �ܾ� ���
	}
	for (j = 0; j < i; j++){
		free(sp[j]); //���� ���� �ݳ�
	}
	printf("\n");
	

	
	//����2
	Student student[100]; //Student ����ü�� ����ϴ�
						//student[100] (�ִ� �л� �� 100) �迭 ����
	int cnt; // �л����� �����ϱ� ���� cnt ����

	printf("> �л��� �Է� : ");
	scanf_s("%d", &cnt); // �л� �� �Է�
	input_data(student, cnt); // �л� �� ��ŭ �л��� ���� �Է�
	calc_data(student, cnt); // �Է��� �л����� ���� ���
	printf("���� �� ������...\n"); 
	print_data(student, cnt); //���� �� ������ ���
	printf("���� �� ������...\n");
	sort_data(student, cnt); // ���� ������ ������ ����
	print_data(student, cnt); //���� �� ������ ���
	
	return 0;
}

//����1 �Լ�
int dup_check(char **sp, char *temp, int cnt){ // �̹� �ִ� �ܾ����� �˻��ϴ� �Լ�
	int i;
	for (i = 0; i < cnt - 1; i++){
		if(strcmp(sp[i], temp) == 0){ //sp[i] �� temp �� ������ �ߺ�
			return 0;// �ߺ��ܾ�
		}
	}
	return 1; // �ߺ��� �ƴ�
}



//����2 �Լ�
void input_data(Student *pary, int inputSize){ //���� �Է� �Լ�
	int i = 0;
	while (i < inputSize){ // inputSize ��ŭ �Է��� �ݺ�
		printf("> �й� : ");
		scanf("%d", &pary[i].student_num); // �л� [i] �� �й� �Է�, ����
		
		printf("> �̸� : ");
		scanf("%s", &pary[i].name); // �л� [i] �� �̸� �Է�, ����

		printf("> ����, ����, ���� ���� : ");
		scanf("%d %d %d", &pary[i].kor_score, &pary[i].eng_score, &pary[i].math_score);
		i++;
		// �л� [i] �� ���� �� ���� �Է�, ����
	}
}
void calc_data(Student *pary, int inputSize){ // ����, ���, ���� ��� �Լ�
	int i = 0;
	while (i < inputSize){ // inputSize ��ŭ ��� �ݺ�
		pary[i].sum_score = (pary[i].kor_score + pary[i].eng_score + pary[i].math_score); // �л� [i] �� ���� ���
		pary[i].average = (double) pary[i].sum_score / 3; // �л� [i] �� ��� ���
		if (pary[i].average >= 90){ // �л� [i] �� ��� ������ ���� ���� ���, ����� 90 �̻��� �� ���� A
			pary[i].grade = 'A';
		}
		else if (pary[i].average >= 80){ // ����� 80�̻��� �� ���� B
			pary[i].grade = 'B';
		}
		else if (pary[i].average >= 70){ // 70 �̻��� �� C
			pary[i].grade = 'C';
		}
		else{ // ������(70 �̸�) F
			pary[i].grade = 'F';
		}
		i++;
	}
}
void sort_data(Student *pary, int inputSize){ //�����͸� ���������� �����ϴ� �Լ�
	int i = 0, j;
	while (i < inputSize){ // inputSize ��ŭ �ݺ�
		for (j = 0; j < inputSize; j++){ 
			if (pary[i].average > pary[j].average) { // ����� ���Ͽ� [i] > [j] ���
				swap(&pary[i], &pary[j]); // �� �������� ��ġ�� ����
			}
		}
		i++;
	}
}
void swap(Student *x, Student *y){ //�Է��� x, y �� �����͸� �ٲ��ִ� �Լ�
	Student a = *x;
	*x = *y;
	*y = a;
}
void print_data(Student *pary, int inputSize){ // �л� ������ ��� �Լ�
	int i = 0;
	while (i < inputSize){ // inputSize ��ŭ �ݺ�
		printf("%d %s %d %d %d %d %.1lf %c", pary[i].student_num, pary[i].name, pary[i].kor_score,
			pary[i].eng_score, pary[i].math_score, pary[i].sum_score, pary[i].average, pary[i].grade);
		printf("\n");
		i++;
		// �л� [i] �� �й�, �̸�, ���� �� ����, ����, ���, ������ ���
	}
	printf("\n");
}