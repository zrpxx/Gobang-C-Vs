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
	int nSelect = -1;
	printf("\n");
	printf("©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤ ©¤\n");
	printf("1.start game\t2.load board\t3.rank list\n");
	printf("4.view rules\t5.about us\t0.exit\n");
	printf("©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨ ©¨\n");
	printf("Please select menu item number:");

	scanf("%d", &nSelect);
	fflush(stdin);

	return nSelect;
}