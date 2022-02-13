#define _CRT_SECURE_NO_WARNINGS
#include "blackjack.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctime>

int pl2y = 0;
int plbet = 0;

void bet() {
	char input[1024];
	system("cls");
	printf("Your curent money: %i\n How much money do you want to spend:", user.coin);
	fgets(input, sizeof input, stdin);
	sscanf(input, "%i", &plbet);
	if (plbet > user.coin) { printf("You don't have that much money!"); Sleep(1000); bet(); }
	else if (plbet <= 0) { printf("You have to make debt!"); Sleep(1000); bet(); }
}

void Hit() {
	ply++;
	nc++;
	int plvalue = 0, ace = 0;
	playersdeck[ply] = deck[nc];
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
	if (plvalue >= 21) { showcard(2); }
	showcard(1);
}
void Stand() { if (deck[2].split == 1) { showcard(3); } else { deck[3].split = 0; showcard(3); } }
void Doubling() { if (2 * plbet <= user.coin) { plbet = plbet * 2; }
else { printf("You don't have that much money!"); Sleep(2000); }}
void Surrender() { showcard(2); }

void Split() {
	if (deck[1].split == 1) {
		deck[1].split = 0;
	}
	nc++;
	playersdeck2[pl2y] = playersdeck[1];
	playersdeck[1] = deck[nc];
	deck[3].split = 1;
	deck[2].split = 1;
	deck[4].split = 1;
	showcard(1);
}



void plwin(int plvalue, int pcvalue){ 
	printf("\n\n%s %-80i%s %i\n", "Pc's points:", pcvalue , "Player's point:", plvalue);
	Sleep(2000);
	system("cls");
	printf("\n\n\t\tWinner\n\t\tThe Player"); Sleep(2000);
if (plvalue == 21) { user.coin += 2 * plbet; }
else { user.coin += plbet; }
save();
system("cls");
mainscr(1);}



void splitdeck() {
	pl2y++;
	nc++;
	deck[2].split = 0;
	int plvalue = 0, ace = 0;
	playersdeck2[ply] = deck[nc];
	for (int pl = 0; pl <= ply; pl++)
	{
		if (playersdeck2[pl].value != 0) {
			plvalue = plvalue + playersdeck2[pl].value;
		}
		else { ace++; }
	}
	for (int pl = 0; pl <= ply; pl++)
	{
		if (playersdeck2[pl].value == 0) {
			if (plvalue < 10) { plvalue += 11; }
			else if (plvalue == 10 and ace == 1) { plvalue += 11; }
			else if (plvalue == 10 and ace == 2) { plvalue += 1; }
			else { plvalue += 1; }
		}
	}
	if (plvalue >= 21) { deck[3].split = 0; showcard(3); }
	showcard(3);
}