#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Rand �Լ��� ���� �������
#include <Windows.h> // ȭ�� Clear �� ���� ��� ����
#include <time.h> // Srand�� ����ϱ� ���� �������
#include <conio.h> //getch �� ����ϱ� ���� �������

//�÷� ����ϱ� Define ��
#define colorHandle GetStdHandle(STD_OUTPUT_HANDLE) //�ܼ�â�� �ڵ����� �ޱ�
#define BLACK SetConsoleTextAttribute(colorHandle, 0x0000); //������
#define GRAY SetConsoleTextAttribute(colorHandle, 0x0007); //���� ȸ��
#define RED SetConsoleTextAttribute(colorHandle, 0x000c); //������
#define BLUE SetConsoleTextAttribute(colorHandle, 0x0001 | 0x0008); //�Ķ���
#define WHITE SetConsoleTextAttribute(colorHandle, 0x000f); //�Ͼ��
#define YEL SetConsoleTextAttribute(colorHandle, 0x000e); //�����
#define GREEN SetConsoleTextAttribute(colorHandle, 0x0002); //���
#define VIO SetConsoleTextAttribute(colorHandle, 0x0001 | 0x0008 | 0x000c); //�����

//Ŀ�� ����� ��ũ��
enum { HIDDEN, SHOW };

//�̷��Լ� ����Ű �ƽ�Ű�ڵ尪
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define Enter 13 //���� ��
#define ESC 27

//System �Լ�
void gotoxy(int, int ); // x�� y�� �̵������ִ� �Լ�
void delay(clock_t wait); // ������ �Լ� �ð� ���ʸ� ����Ͽ���
void color(unsigned short color); // ���� �÷��� �ֱ� ���� �Լ�
void viewCursor(char show); //Ŀ���� ����ų� �����ش�

//�̷�Ż����� �Լ�
void miro(); //�̷ΰ��� �����Լ�
int miroGame();

int main(){
	miro();
	return 0;
}

void miro(){
	int n;
	n = miroGame();
}
void gotoxy(int x, int y){ // x�� y�� �̵������ִ� �Լ�
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void color(unsigned short color){// ������ �÷��� ����� ���� �Լ�
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}
void viewCursor(char show){ // Ŀ�� ����� / ���̱�
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void delay(clock_t wait){ 
	// wait ms ��ŭ ��� 1000 = 1��
	clock_t goal;
	goal = wait + clock();
	while (goal > clock());
}
int miroGame(){
	struct MIRO { //�̷� ����ü
		int x, y;
		int PlayN;
	};
	struct MIRO Me, Mon[20], Pre[10];
	static int Stage = 1, PreNum;
	static int i, j, k = 0, T = 0, b, c[20][2] = { 0 }, d[30] = { 0 };
	static int Screen[18][28] = { 0 }; // ȭ��
	int randNum[2] = { 0 };
	char ch;
	int Life = 3, LifeN, GameOver = 0;

	srand(time(NULL));

	system("mode con lines=20 cols=58"); // â ũŰ line = y��, cols = x��, line�� -1 ũ�� ���
	system("cls");
	viewCursor(HIDDEN);
	system("cls");

	while (1){
		randNum[0] = 0;
		randNum[1] = 0;

		gotoxy(22, 9);
		printf("S t a g e  %d", Stage);
		Sleep(3000);
		system("cls");

		b = rand() % 14 + 2;

		for (i = 0; i < Stage * 2; i++){
			c[i][0] = rand() % 14 + 2;
			c[i][1] = rand() % 22 + 3;
		}
		for (i = 0; i < 35; i++){
			d[i] = rand() % 26 + 1;
		}

		Me.x = 7;
		Me.y = 1;
		Me.PlayN = 1;

		for (i = 0; i < Stage * 2; i++){
			Mon[i].x = c[i][0];
			Mon[i].y = c[i][1];
			Mon[i].PlayN = 10;
		}
		for (i = 0; i < Stage; i++){
			Pre[i].x = c[i][0];
			Pre[i].y = c[i][1] + 1;
			Pre[i].PlayN = 7;
		}
		for (i = 0; i < 18; i++){ // �ʱ�ȭ
			for (j = 0; j < 28; j++){
				Screen[i][j] = 0;
			}
		}

		k = 0;
		for (i = 0; i < 18; i++){ //�� ����
			for (j = 0; j < 28; j++){
				if (i == 0 || i == 17) Screen[i][j] = 9;
				else if (j == 0 || j == 27) Screen[i][j] = 9;
			}
		}
		for (i = 1; i < 18; i++){
			for (j = 0; j < 28; j++){
				if (d[k] == j){
					Screen[i][j] = 9;
					k++;
				}
			}
		}
		Screen[b][26] = 0;
		Screen[b][27] = 0;
		Screen[7][1] = 1; // �ʱ�ȭ
		Screen[6][1] = 0;

		for (i = 0; i < Stage * 2; i++){
			Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
		}
		for (i = 0; i < Stage; i++){
			Screen[Pre[i].x][Pre[i].y] = Mon[0].PlayN;
		}
		while (1){
			PreNum = 0;

			for (i = 0; i < Stage * 2; i++){
				randNum[0] = rand() % 15;
				if (randNum[0] == 0){
					randNum[1] = rand() % 4;
					switch (randNum[1]){
					case 0:
						if (Screen[Mon[i].x][Mon[i].y - 1] != 9 && Screen[Mon[i].x][Mon[i].y - 1] != Mon[i].PlayN
							&& Screen[Mon[i].x][Mon[i].y - 1] != Pre[0].PlayN) {
							Screen[Mon[i].x][Mon[i].y] = 0;
							Mon[i].y -= 1;
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) Me.PlayN = 99;
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
						break; // ����
					case 1:
						if (Screen[Mon[i].x][Mon[i].y + 1] != 9 && Screen[Mon[i].x][Mon[i].y + 1] != Mon[i].PlayN
							&& Screen[Mon[i].x][Mon[i].y + 1] != Pre[0].PlayN) {
							Screen[Mon[i].x][Mon[i].y] = 0;
							Mon[i].y += 1;
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) Me.PlayN = 99;
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
						break; // ������
					case 2:
						if (Screen[Mon[i].x - 1][Mon[i].y] != 9 && Screen[Mon[i].x - 1][Mon[i].y] != Mon[i].PlayN
							&& Screen[Mon[i].x - 1][Mon[i].y] != Pre[0].PlayN) {
							Screen[Mon[i].x][Mon[i].y] = 0;
							Mon[i].x -= 1;
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) Me.PlayN = 99;
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
						break; // ����
					case 3:
						if (Screen[Mon[i].x + 1][Mon[i].y] != 9 && Screen[Mon[i].x + 1][Mon[i].y] != Mon[i].PlayN
							&& Screen[Mon[i].x + 1][Mon[i].y] != Pre[0].PlayN) {
							Screen[Mon[i].x][Mon[i].y] = 0;
							Mon[i].x += 1;
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) Me.PlayN = 99;
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
						break; // �Ʒ���
					}
				}
			}
			for (i = 0; i < 18; i++){ // ���� ���
				gotoxy(1, i + 1);
				for (j = 0; j < 28; j++){
					if (Screen[i][j] == 0){
						BLACK;
						printf("��");
					}
					else if (Screen[i][j] == Me.PlayN){
						RED;
						printf("��");
					}
					else if (Screen[i][j] == 9){
						WHITE;
						printf("��");
					}
					else if (Screen[i][j] == Mon[0].PlayN){
						VIO;
						printf("��");
					}
					else if (Screen[i][j] == Pre[0].PlayN){
						YEL;
						printf("��");
					}
				}
				printf("\n");
			}
			if (_kbhit()){ //Ű���� �Է�������
				ch = _getch();
				switch (ch){
				case 75:
					if (Screen[Me.x][Me.y - 1] != 9){
						Screen[Me.x][Me.y] = 0;
						Me.y -= 1;
						if (Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN = 99;
					}
					Screen[Me.x][Me.y] = Me.PlayN;
					break; //����
				case 77:
					if (Screen[Me.x][Me.y + 1] != 9){
						Screen[Me.x][Me.y] = 0;
						Me.y += 1;
						if (Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN = 99;
					}
					Screen[Me.x][Me.y] = Me.PlayN;
					break; // ������
				case 72:
					if (Screen[Me.x - 1][Me.y] != 9){
						Screen[Me.x][Me.y] = 0;
						Me.x -= 1;
						if (Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN = 99;
					}
					Screen[Me.x][Me.y] = Me.PlayN;
					break; // ����
				case 80:
					if (Screen[Me.x + 1][Me.y] != 9){
						Screen[Me.x][Me.y] = 0;
						Me.x += 1;
						if (Screen[Me.x][Me.y] == Mon[0].PlayN) Me.PlayN = 99;
					}
					Screen[Me.x][Me.y] = Me.PlayN;
					break; //�Ʒ���
				case ESC: break;
				}
			}
			if (ch == ESC) break;

			LifeN = Life;
			if (Me.PlayN == 99){
				Life -= 1;
				break;
			}
			for (i = 0; i < 18; i++){
				for (j = 0; j < 28; j++){
					if (Screen[i][j] == Pre[0].PlayN){
						PreNum++;
					}
				}
			}
			if (PreNum == 0){
				if (Me.y == 27) break;
			}
		}
		if (ch == ESC) break;

		if (Life != 0 && Stage != 11){
			if (LifeN == Life){
				Stage += 1;
				system("cls");
				gotoxy(16, 9);
				printf("S t a g e  C l e a r !!");
				Sleep(3000);
				system("cls");
			}
			else{
				gotoxy(19, 10);
				printf("G a m e  o v e R ! !");
				Sleep(3000);
				system("cls");
				gotoxy(22, 9);
				RED;
				printf("��");
				gotoxy(26, 9);
				WHITE;
				printf(" =  %d", Life);
				Sleep(3000);
				system(3000);
				GRAY;
			}
		}
		if (Life == 0){ //���� ��� ���ӿ���
			gotoxy(19, 9);
			printf("G a M e  o V e R ! !");
			Sleep(3000);
			system("cls");
			break;
		}
		else if (Stage == 11){//������ �������� Ŭ�������� ��
			system("cls");
			WHITE;
			gotoxy(14, 9);
			printf(" C o n g r a t u l a t i o n ");
			Sleep(3000);
			system("cls");
			gotoxy(19, 9);
			printf("T h e E n d ! !");
			Sleep(4000);
			GRAY;
			break;
		}
	}
	return 0;
}












