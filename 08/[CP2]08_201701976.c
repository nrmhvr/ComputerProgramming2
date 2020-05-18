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
	//�ǽ�1
	char animal[20];
	char why[80];

	printf("�����ϴ� ���� : ");
	scanf_s("%s", animal, 20);
	//	getchar(); ���1
	//	scanf_s("%*C"); ���2
	fgetc(stdin); //���3
	printf("�����ϴ� ���� : ");
	fgets(why, sizeof(why), stdin);
	printf("%s is %s", animal, why);
	printf("\n");
	//������ dog ġ�� ����ġ�� ���۾ȿ� ���Ͱ� ����Ǿ
	//�����ϴ� ������ ĥ�� ���Ͷ����� �Է��� �Ұ���
	//���� ����Ű�� ���ָ� ����



	//�ǽ�2
	char str[16];
	char res_str[16];
	char *star = "**********";
	int len;

	printf("�ܾ� �Է� : ");
	scanf_s("%s", str, 16);
	len = (int)strlen(str);
	if (len <= 5) strcpy_s(res_str, 16, str);
	else{
		strncpy_s(res_str, 16, str, 5);
		res_str[5] = '\0';
		strncat_s(res_str, 16, star, len - 5);
	}
	printf("�Է��� �ܾ� : %s, ������ �ܾ� : %s\n", str, res_str);
	printf("\n");
	*/



	
	//����1 - �ƽ�Ű�ڵ� ���� �̿�
	char str[200][15]; //��ü ���ڿ�
	int len = 0; //��ü ���ڿ��� ����
	int num = 0; //���ڸ� �Է��� Ƚ��
	for (int i = 0; i < 200; i++) { 
		printf("�ܾ� �Է� : ");
		gets_s(str[i], 200);
		len += (int)strlen(str[i]); //��ü ���ڿ��� ���̿� �Է��� ���ڿ��� ���̸� ����
		if (len > 200) { // ��ü ���ڿ� ���̰� 200�� ������ �޽��� ��� �� ����
			printf("���̻� �Է¹��� �� �����ϴ�.\n���α׷��� �����մϴ�.\n\n");
			break;
		}
		if ((int)strlen(str[i]) >= 16) { //�Է¹��� ���ڿ��� ���̰� 15�� ������ �޽��� ���
			printf("���ڿ��� ���̰� ��ϴ�.\n");
			str[i][0] = NULL; //��ü ���ڿ��� �������� ����
		}
		if (!strcmp(str[i], "end")) { // end �� �Է¹����� ���α׷� ����
			printf("���α׷��� �����մϴ�.\n\n");
			break;
		}
		num++; //�Է��� Ƚ�� ī��Ʈ
		qsort(str, num, sizeof(str[0]), compare); //�ƽ�Ű �ڵ� ������ ������ �ٲ��ִ� �Լ�
		printf("������� ���ڿ� :"); // ������� �����(�ƽ�Ű�ڵ� ������ ������) ���ڿ��� ���
		for (int j = 0; j < num; j++) {
			printf("%s ", str[j]);
		}
		printf("\n");
	}
	
	
	
	//����2
	srand((unsigned int)time((time_t*)NULL));
	int lotto[6]; //ũ�� 6�� lotto�迭 ����

	makeLottoNumber(lotto);  // ������ ���� lotto�� ���� �� ������������ ����
	int a = checkLottoNumber(lotto); //���ڸ� �Է¹ް� lotto�� ���� ���� ��ȯ
	printf("�ζ� ��ȣ : ");
	for (int i = 0; i < 6; i++){ //lotto��ȣ ���
		printf("%d ", lotto[i]);
	}
	printf("\n�� %d���� �´� ���ڰ� �ֽ��ϴ�.\n", a); //lotto�� ���� ���� ���


	
	//����3
	int bingo[400] = { 0 }; // 20 * 20 �������� bingo �迭�� ����
	int size = 0;

	printf("������ ����� �Է��ϼ��� : ");
	scanf_s("%d", &size);
	makeBingo(bingo, size); // �Է��� size * size ũ���� �������� ����
	printBingo(bingo, size); //�������� ���
	if (checkBingo(bingo, size) == 0){ //checkBingo �� 0 �̶��(���� �ִٸ�) �޽����� ������ ���
		printf("����!\n");
		printBingo(bingo, size);
	}
}



//����1 �Լ�
int compare(const void * first, const void * second) { //qsort �Լ��� ���� ���� �ʿ��� �Լ�
	return strcmp((char*)first, (char*)second); //�Է��� first, second �� �ƽ�Ű �ڵ带 ������
}



//����2 �Լ�
void makeLottoNumber(int *lottoNums){
	for (int i = 0; i < 6; i++){
		lottoNums[i] = rand() % 45 + 1; // 1~45������ ���� ���� 6���� �迭�� ����
	}
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			if (lottoNums[i] < lottoNums[j]) swap(&lottoNums[i], &lottoNums[j]);
			// ������������ �迭�� swap �Ͽ� ����
		}
	}
}
int checkLottoNumber(int *lottoNums){
	int num[6]; // ����ڰ� �Է��� 6�ڸ� ���ڸ� ������ �迭
	int same_num = 0; // num �߿� lotto�� ���� ����
	int temp = 0;

	printf("��ȣ �Է� : ");
	scanf_s("%d", &num[0]); // num[0]�� �Է¹��� ���ڸ� ����

	for (int i = 1; i < 6; i++){ //num �迭�� �� �������� �ݺ�
		printf("��ȣ �Է� : ");
		scanf_s("%d", &temp); // temp�� �Է��� ���� ����
		for (int j = 0; j < i; j++){ // j < i �� �� for���� �ݺ��Ǹ� ���� for ���� �ݺ�Ƚ���� ++����
			if (temp == num[j]) { // temp �� num �� ���� ���ڰ� ������ �ȳ��޽��� ���
				printf("���� ��ȣ�� �ֽ��ϴ�!\n");
				i--;
			}
			else num[i] = temp; // temp �� num �� �ߺ����� �ʴ´ٸ� num �迭�� ����
		}
	}
	for (int i = 0; i < 6; i++){ // num �� lotto �� ���Ͽ� ���� ������ ���� ��ŭ same_num ����
		for (int j = 0; j < 6; j++){
			if (lottoNums[i] == num[j]) same_num++;
		}
	}
	return same_num; // same_num �� ��ȯ
}
void swap(int *x, int *y){ // x �� y �� �ٲ�
	int a = *x;
	*x = *y;
	*y = a;
}



//����3 �Լ�
void makeBingo(int *bingoArray, int inputSize){ 
	int size = inputSize * inputSize;
	int* temp = (int *)malloc(size * sizeof(int)); //size ũ���� temp ����
	for (int i = 0; i < size; i++){ 
		temp[i] = 0; //��� temp[i] �� 0 ����
	}
	int num;
	printf("������ ����\n");
	for (int i = 0; i < size; i++){
		num = rand() % size; //num �� 0 ~ size-1 ������ ������ ��
		while (temp[num]){ // temp[num] �� 1 �̸�(�ߺ��� �ǹ�) while���� ����(= num�� ������ �� �ٽ� ����)
			num = rand() % size;		// 1�� �ƴϸ�(= 0 �̸�/ �ߺ��� �ƴ϶� �ǹ�) while���� �������� ����
		}
		bingoArray[i] = num + 1; //bingo �迭�� num + 1 �� ����
								// +1 �� �ϴ� ���� : num �� 0 ~ size-1 ������ ������ ���̰�
								// �����ǿ� ����� ���� 1 ~ size �̱� ����
		temp[num] = 1; // �� �� �����ߴٸ� temp[num] �� 1�� ���� (�ߺ��� �ǹ�)
	}
}
void printBingo(int *bingoArray, int inputSize){ //�������� ���
	int i, j = 1;
	for (i = 0; i < inputSize*inputSize; i++, j++){
		if (bingoArray[i] == 0) printf("  * "); // �������� ���ڰ� 0 �̶��(����� �ڸ�) * �� ���
		else printf("%3d ", bingoArray[i]); 
		if (j % inputSize == 0){ //inputSize �� ���� 1�� ����
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
		printf("���� ���� ����� ����[1:����][2:������Է�] : ");
		scanf_s("%d", &choice); //����� ����
		if (choice== 1){ //1�̸� getRandomNumber ���
			a = getRandomNumber(prevNumberList, inputSize);
			printf("���� ���ڸ� ���� : %d\n", a);
			for (i = 0; i<size; i++){ //�����ǿ��� ������ ���ڰ� �ִ� �ڸ��� 0 ���� ����
				if (bingoArray[i] == a)
					bingoArray[i] = 0;
			}
		}
		if (choice == 2){ //2�̸� getUserSelectNumber ���
			b = getUserSelectNumber(prevNumberList);
			if (b == -1)
				printf("�̹� �Էµ� �����Դϴ�.\n");
			for (i = 0; i<size; i++){ //�����ǿ��� ������ ���ڰ� �ִ� �ڸ��� 0 ���� ����
				if (bingoArray[i] == b)
					bingoArray[i] = 0;
			}
		}
		//���� Ȯ�� 4���� : ����, ����, �밢��, ���밢�� �� 1���� 0 �� �� ����
		for (i = 0; i < size; i = i + inputSize) { //������ ���� Ȯ��
			for (j = 0; j < inputSize; j++) {
				count += bingoArray[i + j];
			}
			if (count == 0) {
				return 0;
			}
			count = 0;
		}
		for (j = 0; j < inputSize; j++) {//������ ���� Ȯ��
			for (i = 0; i < size; i = i + inputSize) {
				count += bingoArray[i + j];
			}
			if (count == 0) {
				return 0;
			}
			count = 0;
		}
		for (i = 0, j = 0; i < size; i = i + inputSize, j++) {//�밢�� ���� Ȯ��
			count += bingoArray[i + j];
		}
		if (count == 0) {
			return 0;
		}
		count = 0;

		for (i = 0, j = inputSize - 1; i < size; i = i + inputSize, j--) {//�밢�� ���� Ȯ��
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
		if (prevNumberList[i] == 0) //prevNumberList[i]�� 0 �̸�(�̹� ����� �ڸ�) ����
			break;
	}
	n = prevNumberList[i] = rand() % size + 1; //������ ���� �����Ͽ� �迭�� ����
	for (j = 0; j<i; j++){
		if (prevNumberList[i] == prevNumberList[j]){  //�迭�� �ߺ��Ǵ��� �˻��Ͽ� �ִٸ� �ٽ� ����
			n = prevNumberList[i] = rand() % size + 1;
			j = -1;
		}
	}
	return n;

}
int getUserSelectNumber(int *prevNumberList){
	int i, j;
	for (i = 0; i<400; i++){
		if (prevNumberList[i] == 0) //prevNumberList[i]�� 0 �̸�(�̹� ����� �ڸ�) ����
			break;
	}
	printf("����� ���� ���� �Է� : ");
	scanf_s("%d", &prevNumberList[i]); //�Է��� ���� �迭�� ���� �� ���Ͽ� �ִٸ� -1�� ����
	for (j = 0; j<i; j++){
		if (prevNumberList[i] == prevNumberList[j]){
			prevNumberList[i] = -1;
		}
	}
	return prevNumberList[i];

}
