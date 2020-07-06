#include "menu.h"
#include "global.h"
#include "game_service.h"
#include "rank_service.h"
#include "game_file.h"
#include "rank_file.h"

int main()
{
	int stone[SIZE][SIZE] = {};
	ClearBoard();
	struct Rank* headNode = createList();
	initApplication();
	int nSelect;
	int printMainMenu();
	nSelect = printMainMenu();
	for (;;)
	{
		switch (nSelect)
		{
		case 0:
			printf("\nThank you for using\n");
			system("pause");
			exit(0);
			break;
		case 1:
			printf("start game");
			playGame();
			break;
		case 2:
			printf("start game");
			playGameAI();
			break;
		case 3:
			LoadBoard();
			break;
		case 4:
			LoadRank(headNode);
			ShowRank(headNode);
			break;
		case 5:
			printf("view rules");
			Rule();
			break;
		case 6:
			printf("about us");
			break;
		default:
			break;
		}
		if (nSelect != 0)
		{
			nSelect = printMainMenu();
		}
	}
	return 0;
}
