#pragma once
#ifndef _GAME_FILE_H_
#define _GAME_FILE_H_

void Chessboard();
int PutBlackStone();
int PutWhiteStone();
int CheckLine(int);
int CheckRow(int);
int CheckDiagonal(int);
int CheckBackDiagonal(int);
int Max(int, int, int, int);
void ClearBoard();
void AddRank(char[20], int);
void LoadBoard();
void SaveBoard(int);
int CountSteps();

#endif
