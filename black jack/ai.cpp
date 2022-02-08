#define _CRT_SECURE_NO_WARNINGS
#include "blackjack.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctime>

void airound(){
	int pcvalue = 0, ace=0;
	for (int pc = 0; pc <= pcy; pc++)
	{
		pcvalue = pcvalue + pcsdeck[pc].value;
	}

	for (int pc = 0; pc <= pcy; pc++)
	{
		if (pcsdeck[pc].value == 0) {
			ace++;
		}
	}

	if ((pcvalue <= 17 and ace!=0) or pcvalue <= 16) {
		pcy++;
		nc++;
		pcvalue = 0;
		ace = 0;
		pcsdeck[pcy] = deck[nc];

		for (int pc = 0; pc <= pcy; pc++)
		{
			if (pcsdeck[pc].value != 0) {
				pcvalue = pcvalue + pcsdeck[pc].value;
			}
		}
		for (int pc= 0; pc <= pcy; pc++)
		{
			if (pcsdeck[pc].value == 0) {
				if (pcvalue < 10) { pcvalue += 11; }
				else if (pcvalue == 10 and ace == 1) { pcvalue += 11; }
				else if (pcvalue == 10 and ace == 2) { pcvalue += 1; }
				else { pcvalue += 1; }
			}
		}
		if (pcvalue >= 21) { showcard(2); }
		else showcard(3);
	}
	whowin();
}

void aiwin(int plvalue, int pcvalue) {
	printf("\n\n%s %-80i%s %i\n", "Pc's points:", pcvalue, "Player's point:", plvalue);
	Sleep(2000);
	system("cls");
	printf("\n\n\t\tWinner\n\t\tThe House"); Sleep(2000);
	user.coin -= plbet;
	save();
	system("cls");
	mainscr(1);
}