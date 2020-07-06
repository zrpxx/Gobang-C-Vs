#include "global.h"
#include "game_file.h"
#include "rank_file.h"

void playGame()
{
	int i, j, steps, win;
	char s;
	char player[20];
	win = 0;
	steps = CountSteps();
	Chessboard();
	while (steps < 225 && win == 0)
	{
		if (steps % 2 == 0)
		{
			PutBlackStone();//下黑子 
			system("cls");
			Chessboard();//打印棋盘 
			win = Max(CheckLine(STATUS_BLACK), CheckRow(STATUS_BLACK), CheckDiagonal(STATUS_BLACK), CheckBackDiagonal(STATUS_BLACK));//胜利win输出1 
		}
		else if (steps % 2 == 1)
		{
			PutWhiteStone();//下白子 
			system("cls");
			Chessboard();//打印棋盘 
			win = Max(CheckLine(STATUS_WHITE), CheckRow(STATUS_WHITE), CheckDiagonal(STATUS_WHITE), CheckBackDiagonal(STATUS_WHITE));//胜利win输出1 
		}
		SaveBoard(steps);
		steps = CountSteps();
	}

	if (win == 1 && steps % 2 == 1)
	{
		printf("\n┏  ━  ━  ━  ━  ━  ━  ━  ━  ┓");
		printf("\n┃      ○ Black Win ○     ┃");
		printf("\n┗  ━  ━  ━  ━  ━  ━  ━  ━  ┛\n");
		printf("your name is:\n");
		getchar();
		scanf("%s", player);
		AddRank(player, steps);
		system("pause");
	}
	else if (win == 1 && steps % 2 == 0)
	{
		printf("\n┏  ━  ━  ━  ━  ━  ━  ━  ━  ┓");
		printf("\n┃      ● White Win ●     ┃");
		printf("\n┗  ━  ━  ━  ━  ━  ━  ━  ━  ┛\n");
		printf("your name is:\n");
		getchar();
		scanf("%s", player);
		AddRank(player, steps);
		system("pause");
	}
	else if (win == 0)
	{
		printf("\n┏  ━  ━  ━  ━  ━  ━  ━  ━  ┓");
		printf("\n┃      ● Draw Game ○     ┃");
		printf("\n┗  ━  ━  ━  ━  ━  ━  ━  ━  ┛\n");
		system("pause");
	}
}

void Rule() {
	system("cls");
	printf("\n(1)  Renju is played by two players against each other.");
	printf("\n(2)  Black stone move first, followed by white.");
	printf("\n(3)  Board: 15×15.");
	printf("\n(4)  The Winner is the first player to get an unbroken row of five stones horizontally, vertically or diagonally.");
	printf("\n(5) A draw occurs when both players will not get an unbroken row of five stones.");
	printf("\n(6)  Columm numbers are letters, while row numbers are numeric.");
	printf("\n(7) The player who slecets black color stone moves first.");
	printf("\n(8)  Player can start game if select Start Game.");
	printf("\n(9)  Move stone: player input row & column number of corresponding point, such as:A1.\n");
	system("pause");
	system("cls");
}

