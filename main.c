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

void removeCursorFromCMD() // cmd縑憮 梭緇檜朝 醴憮蒂 獗梯
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void setCoordinate(int x, int y) // 醴憮 嬪纂蒂 x,y 謝ル煎 撲薑
{
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawMainScreen()
{
	int x = 19;
	int y = 9;
	setCoordinate(x, y); printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("IS 式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("TRIS 式式式式式式式式式式式式式式式式式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("TETRIS 式式式式式式式式式式式式式式式式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("≧ TETRIS 式式式式式式式式式式式式式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式48 ≧ TETRIS 式式式式式式式式式式式式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式 2048 ≧ TETRIS 式式式式式式式式式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式 2048 ≧ TETRIS 式式式式式式式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式 2048 ≧ TETRIS 式式式式式式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式式  2048 ≧ TETRIS 式式式式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式式式式  2048 ≧ TETRIS 式式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式式式式式  2048 ≧ TETRIS 式式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式式式式式式  2048 ≧ TETRIS 式式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式式式式式式式  2048 ≧ TETRIS 式式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式式式式式式式式  2048 ≧ TETRIS 式式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式式式式式式式式式  2048 ≧ TETRIS 式式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式式式式式式式式式式  2048 ≧ TETRIS 式式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式式式式式式式式式式式  2048 ≧ TETRIS 式式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式式式式式式式式式式式式  2048 ≧ TETRIS 式式");
	Sleep(30);
	setCoordinate(x, y); printf("式式式式式式式式式式式式式式式式  2048 ≧ TETRIS 式");
	Sleep(30);

	setCoordinate(x + 6, y + 2); printf("Press any key to start");

	setCoordinate(x, y + 4);  printf(" 〥〥〥〥 HOW TO CONTROL 〥〥〥〥");
	setCoordinate(x, y + 5);  printf(" 〥                            〥");
	setCoordinate(x, y + 6); printf(" 〥    ８  Ⅰ : Left / Right   〥");
	setCoordinate(x, y + 7); printf(" 〥      ∩   : Soft Drop      〥");
	setCoordinate(x, y + 8); printf(" 〥    SPACE  : Hard Drop      〥");
	setCoordinate(x, y + 9); printf(" 〥      P    : Pause          〥");
	setCoordinate(x, y + 10); printf(" 〥     ESC   : Quit           〥");
	setCoordinate(x, y + 11); printf(" 〥                            〥");
	setCoordinate(x, y + 12); printf(" 〥〥〥〥〥〥〥〥〥〥〥〥〥〥〥〥");

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
					printf("     氖      ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 1);
					printf("             ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 2);
					printf("-------------");
				}
				else {
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3));
					printf("             ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 1);
					printf("     氖      ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 2);
					printf("             ");
				}
			}
			else {
				for (k = 0; k < 12;)
					if (1 << (++k) == gameScreen[i][j]) break; // 2048 闊 2曖 11蝓梱雖 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k + 1); // 綰煙 儀梃擊 摹鷗
				if (i == 0) {
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) - 1);
					printf("忙式式式式式式式式式忖 ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3));
					printf("   %4d", gameScreen[i][j]);
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 1);
					printf("戌式式式式式式式式式戎 ");
				}
				else {
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3));
					printf("忙式式式式式式式式式忖 ");
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 1);
					printf("   %4d", gameScreen[i][j]);
					setCoordinate(MAP_BASE_X + (j * 6), MAP_BASE_Y + (i * 3) + 2);
					printf("戌式式式式式式式式式戎 ");
				}
			}
		}
	}
}