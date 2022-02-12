#define _CRT_SECURE_NO_WARNINGS
#include "blackjack.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctime>

void whowin() {
	int plvalue = 0;
	int pl2value = 0;
	int pcvalue = 0;
	int plsavevalue = 0;
	int pl2savevalue = 0;
	int pcsavevalue = 0;
	int ace = 0;

	for (int pl = 0; pl <= ply; pl++)
	{
		if (playersdeck[pl].value != 0) {
			plvalue = plvalue + playersdeck[pl].value;
		}
		else { ace++; }
	}
	for (int pl = 0; pl <= ply; pl++)
	{
		if (playersdeck[pl].value == 0) {
			if (plvalue < 10) { plvalue += 11; }
			else if (plvalue == 10 and ace == 1) { plvalue += 11; }
			else if (plvalue == 10 and ace == 2) { plvalue += 1; }
			else { plvalue += 1; }
		}
	}

	ace = 0;
	for (int pc = 0; pc <= pcy; pc++)
	{
		if (pcsdeck[pc].value != 0) {
			pcvalue = pcvalue + pcsdeck[pc].value;
		}
		else { ace++; }
	}
	for (int pc = 0; pc <= pcy; pc++)
	{
		if (pcsdeck[pc].value == 0) {
			if (pcvalue < 10) { pcvalue += 11; }
			else if (pcvalue == 10 and ace == 1) { pcvalue += 11; }
			else if (pcvalue == 10 and ace == 2) { pcvalue += 1; }
			else { pcvalue += 1; }
		}
	}

	for (int pl = 0; pl <= ply; pl++)
	{
		if (playersdeck2[pl].value != 0) {
			pl2value = pl2value + playersdeck2[pl].value;
		}
		else { ace++; }
	}
	for (int pl = 0; pl <= ply; pl++)
	{
		if (playersdeck2[pl].value == 0) {
			if (pl2value < 10) { pl2value += 11; }
			else if (pl2value == 10 and ace == 1) { pl2value += 11; }
			else if (pl2value == 10 and ace == 2) { pl2value += 1; }
			else { pl2value += 1; }
		}
	}


	plsavevalue = plvalue;
	pl2savevalue = pl2value;
	pcsavevalue = pcvalue;

	if (plvalue > 21) { plvalue = 0; }
	if (pl2value > 21) { pl2value = 0; }
	if (pcvalue > 21) { pcvalue = 0; }

	if (deck[4].split == 0) {
		if (plvalue >= pcvalue) { plwin(plsavevalue, pcsavevalue); }
		else { aiwin(plsavevalue, pcsavevalue); }
	}

	else {
		splitwin(plsavevalue,pl2savevalue,pcsavevalue);
	}
}




void splitwin(int pl, int pl2, int pc) {
	printf("\n\n%s %-20i%s %-20i%s %i\n", "Pc's points:", pc, "Player's point:", pl, "Player's second point:", pl2);
	Sleep(2000);
	system("cls");
	if (pl == 21) { user.coin += 2 * plbet; }
	
	else if(pl<pc){
		user.coin -= plbet;
	}
	
	else { user.coin += plbet; }


	if (pl2 == 21) { user.coin += 2 * plbet; }
	
	else if (pl2 < pc) {
		user.coin -= plbet;
	}

	else { user.coin += plbet; }

	save();
	system("cls");
	if (user.debt != 0) {
		if (user.debt < user.coin + 10000) { printf("The bank take back your debt from your money!"); user.coin -= user.debt; user.debt = 0; Sleep(2000); system("cls"); }
		else {user.debt += 0, 05 * user.debt;
	}
	}

	mainscr(1);
}