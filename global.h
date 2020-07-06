#pragma once
#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define CHESS_BLANK "©ï "
#define CHESS_BLACK "¡ð"
#define CHESS_WHITE "¡ñ"
#define STATUS_BLANK -1
#define STATUS_BLACK 0
#define STATUS_WHITE 1

#define SIZE 15

extern int stone[SIZE][SIZE];

struct Rank 
{
	int steps;
	char name[20];
	struct Rank* next;
};

#endif
