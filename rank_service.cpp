#include "global.h"
#include "rank_file.h"

void LoadRank(struct Rank* headNode) {
	FILE* fp;
	struct Rank* Node = createNode();
	headNode->next = Node;
	int i = 1;

	fp = fopen("Rank.txt", "r");

	while (fscanf(fp, "%s %d", Node->name, &Node->steps) != EOF) {
		struct Rank* pNode = createNode();
		Node->next = pNode;
		Node = pNode;
	}
	headNode = sortRank(headNode);
	
	fclose(fp);
}

void ShowRank(struct Rank* headNode) {
	struct Rank* Node = createNode();
	Node = headNode->next;
	Node = Node->next;
	int i = 1;
	system("cls");
	printf("Rank\n\n");
	do {
		printf("No.%d  %s  %d\n", i, Node->name, Node->steps);
		Node = Node->next;
		i++;
	} while (Node != NULL);
	system("pause");
}



