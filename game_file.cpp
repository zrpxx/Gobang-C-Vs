#include "global.h"
#include "game_service.h"

int stone[SIZE][SIZE] = {};

void Chessboard()
{
	int i, j;
	printf("\n      A B C D E F G H I J K L M N O\n");
	printf("   ©³ ©× ©× ©× ©× ©× ©× ©× ©× ©× ©× ©× ©× ©× ©× ©× ©·");
	for (i = 0; i < 15; i++)
	{
		printf("\n%2d ©Ç ", i + 1);
		for (j = 0; j < 15; j++)
		{
			if (stone[i][j] == -1)
			{
				printf(CHESS_BLANK);
			}
			else if (stone[i][j] == 0)
			{
				printf(CHESS_BLACK);
			}
			else if (stone[i][j] == 1)
			{
				printf(CHESS_WHITE);
			}
		}
		printf("©Ï");
	}
	printf("\n   ©» ©ß ©ß ©ß ©ß ©ß ©ß ©ß ©ß ©ß ©ß ©ß ©ß ©ß ©ß ©ß ©¿");
}

int PutBlackStone()
{
	char a[5],b[5];
	int m, n;
	printf("\nBlack side,please   ");
	scanf("%s", a);
	while (a[0] > 'O' || a[0] < 'A') {
		printf("\nThe location is not exist,please try again   ");
		scanf("%s", a);
	}
	while (a[1] > '9' || a[1] < '1') {
		printf("\nThe location is not exist,please try again   ");
		scanf("%s", a);
	}
	while (a[2] != '\0') {
		if (a[2] > '9' || a[2] < '0') {
			printf("\nThe location is not exist,please try again   ");
			scanf("%s", a);
		}
		else {
			break;
		}
	}
	b[0] = a[1];
	b[1] = a[2];
	while (atoi(b) > 15 || atoi(b) < 1) {
		printf("\nThe location is not exist,please try again   ");
		scanf("%s", a);
		b[0] = a[1];
		b[1] = a[2];
	}

	m = atoi(b) - 1;
	n = a[0] - 'A';
	for (;;)
	{
		if (stone[m][n] == -1)
		{
			stone[m][n] = STATUS_BLACK;
			break;
		}
		else
		{
			printf("the location has been placed,please try again   ");
			scanf("%s", a);
			m = a[1] - '1';
			n = a[0] - 'A';
		}
	}
	return m * 15 + n;
}

int PutWhiteStone()
{
	char a[5],b[5];
	int m, n;
	printf("\nWhite side,please   ");
	scanf("%s", a);
	while (a[0] > 'O' || a[0] < 'A') {
		printf("\nThe location is not exist,please try again   ");
		scanf("%s", a);
	}
	while (a[1] > '9' || a[1] < '1') {
		printf("\nThe location is not exist,please try again   ");
		scanf("%s", a);
	}
	while (a[2] != '\0') {
		if (a[2] > '9' || a[2] < '0') {
			printf("\nThe location is not exist,please try again   ");
			scanf("%s", a);
		}
		else {
			break;
		}
	}
	b[0] = a[1];
	b[1] = a[2];
	while (atoi(b) > 15 || atoi(b) < 1) {
		printf("\nThe location is not exist,please try again   ");
		scanf("%s", a);
		b[0] = a[1];
		b[1] = a[2];
	}

	m = atoi(b)-1;
	n = a[0] - 'A';
	for (;;)
	{
		if (stone[m][n] == -1)
		{
			stone[m][n] = STATUS_WHITE;
			break;
		}
		else
		{
			printf("the location has been placed,please try again   ");
			scanf("%s", a);
			m = a[1] - '1';
			n = a[0] - 'A';
		}
	}
	return m * 15 + n;
}

int CheckLine(int colour)
{
	int i, j;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (colour == stone[i][j])
			{
				if (j + 4 <= 14)
				{
					if (colour == stone[i][j + 1] && colour == stone[i][j + 2] && colour == stone[i][j + 3] && colour == stone[i][j + 4])
					{
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int CheckRow(int colour)
{
	int i, j;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (colour == stone[i][j])
			{
				if (i + 4 <= 14)
				{
					if (colour == stone[i + 1][j] && colour == stone[i + 2][j] && colour == stone[i + 3][j] && colour == stone[i + 4][j])
					{
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int CheckDiagonal(int colour)
{
	int i, j;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (colour == stone[i][j])
			{
				if (i + 4 <= 14 && j + 4 <= 14)
				{
					if (colour == stone[i + 1][j + 1] && colour == stone[i + 2][j + 2] && colour == stone[i + 3][j + 3] && colour == stone[i + 4][j + 4])
					{
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int CheckBackDiagonal(int colour)
{
	int i, j;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (colour == stone[i][j])
			{
				if (i + 4 <= 14 && j - 4 >= 0)
				{
					if (colour == stone[i + 1][j - 1] && colour == stone[i + 2][j - 2] && colour == stone[i + 3][j - 3] && colour == stone[i + 4][j - 4])
						return 1;
				}
			}
		}
	}
	return 0;
}

int Max(int a, int b, int c, int d)
{
	int max;
	max = a;
	if (b >= max)
		max = b;
	if (c >= max)
		max = c;
	if (d >= max)
		max = d;
	return max;
}

void ClearBoard()
{
	int i, j;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++) 
		{
			stone[i][j] = STATUS_BLANK; 
		}
	}
}

void AddRank(char name[20], int steps) {
	FILE* fp;
	fp = fopen("Rank.txt", "a");
	fprintf(fp, "\n%s %d", name, steps);
	fclose(fp);
}

void LoadBoard() {
	int a[300];
	int k = 0;
	int i, j;
	FILE* fp;
	fp = fopen("Board.txt", "r");
	while (fscanf(fp, "%d", &a[k]) != EOF) {
		k++;
	}
	k = 0;
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			stone[i][j] = a[k];
			k++;
		}
	}
	fclose(fp);
	system("cls");
	printf("\nLoad successfully\n");
	system("pause");
	system("cls");
}

void SaveBoard(int steps) {
	int a[300];
	int i, j, k;
	FILE* fp;
	fp = fopen("Board.txt", "w");
	k = 0;
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			a[k] = stone[i][j];
			k++;
		}
	}
	for (k = 0; k < 225; k++) {
		fprintf(fp, "%d\n", a[k]);
	}

	fclose(fp);
}

int CountSteps() {
	int steps, i, j;
	steps = 0;
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			if (stone[i][j] != -1) {
				steps++;
			}
		}
	}

	return steps;
}