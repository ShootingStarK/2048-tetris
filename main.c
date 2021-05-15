#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

#define ESC 27

#define MAP_BASE_X 10
#define MAP_BASE_Y 5

#define X 7
#define Y 4

void removeCursorFromCMD();
void setCoordinate(int, int);
void drawMainScreen();
void drawGameScreen();

int gameScreen[X][Y] = { 0 };

int main()
{
	removeCursorFromCMD();
	drawMainScreen();
}

void removeCursorFromCMD() // cmd���� �����̴� Ŀ���� ����
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void setCoordinate(int x, int y) // Ŀ�� ��ġ�� x,y ��ǥ�� ����
{
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawMainScreen()
{
	int x = 19;
	int y = 9;
	setCoordinate(x, y); printf("��������������������������������������������������������������������");
	Sleep(30);
	setCoordinate(x, y); printf("IS ��������������������������������������������������������");
	Sleep(30);
	setCoordinate(x, y); printf("TRIS ��������������������������������������������������");
	Sleep(30);
	setCoordinate(x, y); printf("TETRIS ������������������������������������������������");
	Sleep(30);
	setCoordinate(x, y); printf("�� TETRIS ������������������������������������������");
	Sleep(30);
	setCoordinate(x, y); printf("��48 �� TETRIS ����������������������������������������");
	Sleep(30);
	setCoordinate(x, y); printf("���� 2048 �� TETRIS ����������������������������������");
	Sleep(30);
	setCoordinate(x, y); printf("������ 2048 �� TETRIS ������������������������������");
	Sleep(30);
	setCoordinate(x, y); printf("�������� 2048 �� TETRIS ����������������������������");
	Sleep(30);
	setCoordinate(x, y); printf("����������  2048 �� TETRIS ������������������������");
	Sleep(30);
	setCoordinate(x, y); printf("��������������  2048 �� TETRIS ��������������������");
	Sleep(30);
	setCoordinate(x, y); printf("����������������  2048 �� TETRIS ������������������");
	Sleep(30);
	setCoordinate(x, y); printf("������������������  2048 �� TETRIS ����������������");
	Sleep(30);
	setCoordinate(x, y); printf("��������������������  2048 �� TETRIS ��������������");
	Sleep(30);
	setCoordinate(x, y); printf("����������������������  2048 �� TETRIS ������������");
	Sleep(30);
	setCoordinate(x, y); printf("������������������������  2048 �� TETRIS ����������");
	Sleep(30);
	setCoordinate(x, y); printf("��������������������������  2048 �� TETRIS ��������");
	Sleep(30);
	setCoordinate(x, y); printf("����������������������������  2048 �� TETRIS ������");
	Sleep(30);
	setCoordinate(x, y); printf("������������������������������  2048 �� TETRIS ����");
	Sleep(30);
	setCoordinate(x, y); printf("��������������������������������  2048 �� TETRIS ��");
	Sleep(30);

	setCoordinate(x + 6, y + 2); printf("Press any key to start");

	setCoordinate(x, y + 4);  printf(" �ǢǢǢ� HOW TO CONTROL �ǢǢǢ�");
	setCoordinate(x, y + 5);  printf(" ��                            ��");
	setCoordinate(x, y + 6); printf(" ��    ��  �� : Left / Right   ��");
	setCoordinate(x, y + 7); printf(" ��      ��   : Soft Drop      ��");
	setCoordinate(x, y + 8); printf(" ��    SPACE  : Hard Drop      ��");
	setCoordinate(x, y + 9); printf(" ��      P    : Pause          ��");
	setCoordinate(x, y + 10); printf(" ��     ESC   : Quit           ��");
	setCoordinate(x, y + 11); printf(" ��                            ��");
	setCoordinate(x, y + 12); printf(" �ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");

	setCoordinate(x, y + 15); printf("          ESC: Exit game.     ");

	int input_command = _getch();

	if (input_command == ESC) {
		system("cls");
		exit(0);
	}
	else
		system("cls");
		drawGameScreen();
}

void drawGameScreen() {
	int i, j, k;

	for (i = 0; i < 7;i++) {
		for (j = 0; j < 4; j++) {
			setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3));
			if (gameScreen[i][j] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				if (i == 0) {
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3));
					printf("     ��      ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 1);
					printf("             ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 2);
					printf("-------------");
				}
				else {
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3));
					printf("             ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 1);
					printf("     ��      ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 2);
					printf("             ");
				}
			}
			else {
				for (k = 0; k < 12;)
					if (1 << (++k) == gameScreen[i][j]) break; // 2048 �� 2�� 11�±��� 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k + 1); // ��� ������ ����
				if (i == 0) {
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) - 1);
					printf("���������������������� ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3));
					printf("   %4d", gameScreen[i][j]);
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 1);
					printf("���������������������� ");
				}
				else {
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3));
					printf("���������������������� ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 1);
					printf("   %4d", gameScreen[i][j]);
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 2);
					printf("���������������������� ");
				}
			}
		}
	}
}