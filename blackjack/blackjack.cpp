#define _CRT_SECURE_NO_WARNINGS
#include "blackjack.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctime>

carddeck pcsdeck[26];
carddeck playersdeck2[26];
carddeck playersdeck[26];
carddeck nuller;
int pcy = 0, ply = 0, nc = 0;

void gamestart() {
	for(int i =0; i<26; i++)
	{
		pcsdeck[i]=nuller;
		playersdeck2[i]=nuller;
		playersdeck[i]=nuller;
	}
	pcy = 0, ply = 0, nc = 0;
	system("cls");
	deckinput();
	pcsdeck[pcy] = deck[nc];
	pcy++;
	nc++;
	playersdeck[ply] = deck[nc];
	ply++;
	nc++;
	pcsdeck[pcy] = deck[nc];
	nc++;	
	playersdeck[ply] = deck[nc];
	bet();
	showcard(1);
}

void showcard(int  pcorpl) {
	int pc = 0, pl = 0, plvalue = 0, pcvalue = 0, pcmc=0;
	if (deck[4].split == 0) {
		if (nc == 53) { deckinput(); nc = 0; };
		if (pcorpl == 3 or pcorpl == 2) { pcmc = 1; };
		system("cls");

		printf("\n%-22s%-22s%-22s%-22s", "1. Hit", "2. Stand", "3. Doubling", "4. Surrender");
		if (deck[1].split == '1') { printf("%s", "5. Split"); }

		printf("\n");
		for (int h = 0; h < 60; h++) { printf("%-2s", "_"); }

		printf("\n\n%-100s%s\n", "Pc's cards:", "Player's cards:");

		for (int h = 0; h < 60; h++) { printf("%-2s", "_"); }
		printf("\n\n");


		pc = 0;
		pl = 0;
		while (1) {
			switch (pcmc)
			{
			case 0:
				if (pc < pcy) {
					printf("%-100s", pcsdeck[pc].name);
					pc++;
				}
				else
				{
					printf("%-100s", " ");
				}
				break;
			default:
				if (pc <= pcy) {
					printf("%-100s", pcsdeck[pc].name);
					pc++;
				}
				else
				{
					printf("%-100s", " ");
				}
				break;
			}


			if (pl <= ply) {
				printf("%s", playersdeck[pl].name);
				pl++;
			}


			printf("\n");


			if (pcmc == 0) {
				if (pc == pcy)
				{
					if (pl > ply) { break; }
				}
			}
			else
			{
				if (pc > pcy)
				{
					if (pl > ply) { break; }
				}
			}
		}
	}
	else{
		int pc = 0, pl = 0, plvalue = 0, pcvalue = 0, pcmc = 0;

		if (nc == 53) { deckinput(); nc = 0; };
		if (pcorpl == 3 or pcorpl == 2) { pcmc = 1; };
		system("cls");

		printf("\n%-22s%-22s%-22s%-22s", "1. Hit", "2. Stand", "3. Doubling", "4. Surrender");
		if (deck[1].split == '1') { printf("%s", "5. Split"); }

		printf("\n");
		for (int h = 0; h < 60; h++) { printf("%-2s", "_"); }

		printf("\n\n%-40s%-40s%s\n", "Pc's cards:", "Player's cards:", "Player's second hand:");

		for (int h = 0; h < 60; h++) { printf("%-2s", "_"); }
		printf("\n\n");


		pc = 0;
		pl = 0;
		int pl2 = 0;
		while (1) {
			switch (pcmc)
			{
			case 0:
				if (pc < pcy) {
					printf("%-40s", pcsdeck[pc].name);
					pc++;
				}
				else
				{
					printf("%-40s", " ");
				}
				break;
			default:
				if (pc <= pcy) {
					printf("%-40s", pcsdeck[pc].name);
					pc++;
				}
				else
				{
					printf("%-40s", " ");
				}
				break;
			}


			if (pl <= ply) {
				printf("%40-s", playersdeck[pl].name);
				pl++;
			}
			else {
				printf("%-40s", " ");
			}

			if (pl <= ply) {
				printf("%s", playersdeck2[pl2].name);
				pl2++;
			}

			printf("\n");


			if (pcmc == 0) {
				if (pc == pcy)
				{
					if (pl > ply) { if (pl2>pl2y) { break; } }
				}
			}
			else
			{
				if (pc > pcy)
				{
					if (pl > ply) { if (pl2 > pl2y) { break; } }
				}
			}
		}
	}
	if (pcorpl == 1) { playersround(0); }
	if (pcorpl == 2) { if (deck[3].split == 1) { playersround(1); } else { whowin(); } }
	if (pcorpl == 3) { if (deck[3].split == 1) { playersround(1); } else { airound(); } }
	if (pcorpl == 4) { airound(); }
}




void playersround(int x) {
	while (1) {
		char menu = _getch();
		if (menu == '1') { if (x == 1) { splitdeck(); } else { Hit(); } }
		if (menu == '2') { Stand(); }
		if (menu == '3') {
			if (deck[5].split == 0) { Doubling(); deck[5].split = 1; }
			else { printf("You can only double once"); }}
		if (menu == '4') { Surrender(); }
		if (deck[1].split == '1') { if (menu == '5') { Split();} }
	}
}
//deck splitting mechanic