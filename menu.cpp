#include "global.h"
#include "game_service.h"
#include "rank_service.h"
#include "game_file.h"
#include "rank_file.h"

void initApplication()
{
	printf("©· ©· ©· ©· ©· ©· ©· ©· ©· ©· ©· ©· ©· ©· ©· ©· ©· ©· ©·\n");
	printf("¡ð¡ñ¡ð¡ñWelcome to Renju Game¡ð¡ñ¡ð¡ñ\n");
	printf("©» ©» ©» ©» ©» ©» ©» ©» ©» ©» ©» ©» ©» ©» ©» ©» ©» ©» ©»\n");
}

void exitApplication()
{
	printf("\n");
	printf("©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤\n");
	printf("G A M E    O V E R !\n");
	printf("©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨\n");
}

int printMainMenu()
{
	system("cls");
	int nSelect = -1;
	printf("\n");
	printf("©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤\n");
	printf("1.start game\t2.start game vs AI\t3.load board\n");
	printf("4.rank list\t5.view rules\t6.about us\n");
	printf("0.exit\n");
	printf("©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨\n");
	printf("Please select menu item number:");
	
	while (scanf("%d", &nSelect)) {
		if (0 <= nSelect && nSelect <= 6)
			break;
		printf("Wrong Input!\n Retry:");
	}
	fflush(stdin);
	return nSelect;
}