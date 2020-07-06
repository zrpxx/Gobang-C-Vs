#include "global.h"

struct Rank* createList() {
	struct Rank* headNode = (struct Rank*)malloc(sizeof(struct Rank));
	strcpy(headNode->name, "\0");
	headNode->steps = 0;
	headNode->next = NULL;
	return headNode;
}

struct Rank* createNode() {
	struct Rank* newNode = (struct Rank*)malloc(sizeof(struct Rank));
	strcpy(newNode->name, "\0");
	newNode->steps = 0;
	newNode->next = NULL;
	return newNode;
}

struct Rank* sortRank(struct Rank* headNode) {
	int temp1;
	char temp2[20];
	struct Rank* move;
	struct Rank* movenext;
	
	for (move = headNode->next; move != NULL; move = move->next) {
		for (movenext = move->next; movenext != NULL; movenext = movenext->next) {
			if (movenext->steps < move->steps) {
				temp1 = movenext->steps;
				movenext->steps = move->steps;
				move->steps = temp1;
				strcpy(temp2 , movenext->name);
				strcpy(movenext->name , move->name);
				strcpy(move->name , temp2);
			}
		}
	}

	return headNode;
}

void insertRank(struct Rank* headNode, int b) {
	struct Rank* newNode = createNode();
	char a[20];

	printf("\nYour name is:\n");
	getchar();
	scanf("%s", a);
	strcpy(newNode->name, a);
	newNode->steps = b;
	newNode->next = headNode->next;
	headNode->next = newNode;
}
