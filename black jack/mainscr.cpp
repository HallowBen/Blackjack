#define _CRT_SECURE_NO_WARNINGS
#include "blackjack.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctime>

using namespace std;
void log_out(int x);
void help();

void mainscr(int first) {
	if (first == 0) { clear(); }
	if (user.debt != 0 && user.coin > user.debt) {
		printf("Welcome in the world of blackjack!\n\nUser: %s", user.username);
		if (999 < user.coin && user.coin < 100000) { printf("\nMoney: %.2fK\nDebt: %i\n\n\n\t1. Start\n\t2. Help\n\t3. Records\n\t4. Debt pay back\n\t5. Log out", (float)user.coin / (float)1000, user.debt); }
		else if (999999 < user.coin && user.coin < 100000000) { printf("\nMoney: %.2fM\nDebt: %i\n\n\n\t1. Start\n\t2. Help\n\t3. Records\n\t4. Debt pay back\n\t5. Log out", (float)user.coin / (float)1000000, user.debt); }
		else if (999999999 < user.coin && user.coin < 100000000000) { printf("\nMoney: %.2fB\nDebt: %i\n\n\n\t1. Start\n\t2. Help\n\t3. Records\n\t4. Debt pay back\n\t5. Log out", (float)user.coin / (float)1000000000, user.debt); }
		else { printf("\nMoney: %i\nDebt: %i\n\n\n\t1. Start\n\t2. Help\n\t3. Records\n\t4. Debt pay back\n\t5. Log out", user.coin, user.debt); }

		while (1) {
			char men = _getch();
			if (men == '1') { if (user.coin != 0) { gamestart(); } else { Bank(); } }
			if (men == '2') { help(); }
			if (men == '3') { recordscr(); }
			if (men == '4') { debtpayback(); }
			if (men == '5') { log_out(0); startingscreen(); }
		}
	}
	else {
		printf("Welcome in the world of blackjack!\n\nUser: %s", user.username);
		if (999 < user.coin && user.coin < 100000) { printf("\nMoney: %.2fK\nDebt: %i\n\n\n\t1. Start\n\t2. Help\n\t3. Records\n\t4. Log out", (float)user.coin / (float)1000, user.debt); }
		else if (999999 < user.coin && user.coin < 100000000) { printf("\nMoney: %.2fM\nDebt: %i\n\n\n\t1. Start\n\t2. Help\n\t3. Records\n\t4. Log out", (float)user.coin / (float)1000000, user.debt); }
		else if (999999999 < user.coin && user.coin < 100000000000) { printf("\nMoney: %.2fB\nDebt: %i\n\n\n\t1. Start\n\t2. Help\n\t3. Records\n\t4. Log out", (float)user.coin / (float)1000000000, user.debt); }
		else { printf("\nMoney: %i\nDebt: %i\n\n\n\t1. Start\n\t2. Help\n\t3. Records\n\t4. Log out", user.coin, user.debt); }
		while (1) {
			char men = _getch();
			if (men == '1') { if (user.coin != 0) { gamestart(); } else { Bank(); } }
			if (men == '2') { help(); }
			if (men == '3') { recordscr(); }
			if (men == '4') { log_out(0); startingscreen(); }
		}
	}
}

void log_out(int x=0) {
	if (x==0){ save(); }
	userid usercleaner;
	usercleaner.coin = 0;
	usercleaner.line = 0;
	usercleaner.debt = 0;
	user.debt = usercleaner.debt;
	user.coin = usercleaner.coin;
	user.line = usercleaner.line;
	strcpy(user.password, usercleaner.password);
	strcpy(user.username, usercleaner.username);
}

void help() {
	system("cls");
	printf("\t\tThe Blackjack!\n\nThe Main gole:\n\tThe player's cards' value must be as close to 21 as possible without goes over.\n\nCard values:\n\tAce: +1 or +11\n\tTwo: +2\n\tThree: +3\n\tFour: +4\n\tFive: +5\n\tSix: +6\n\tSeven: +7\n\tEight: +8\n\tNine: +9\n\tTen: +10\n\tJack: +10\n\tKing: +10\n\tQueen: +10\n\nHow the pay out:\n\tIf you have 21 it doubles the bet, else it just give you the bet or if you loose it takes away the bet.\n\nPlayer's Choises:\n\tHit: Give you a new card\n\tStand: The House turn or your second hand\n\tDouble: Doubles once in a round your bet\n\tSurrender: automatic house win\n\tSplit: You can split your deck to two hand, if you have the same card\n\nBank:\n\tYou can get money from the bank, if you are totaly broken.\n\tYour debt will grow with 5%% after each round, until you can pay it back!\n\tYou can't borrow money if you allready have debt!");
	printf("\n\n\t\t1. Back");
	while (true) {
		char menu = _getch();
		if (menu == '1') { system("cls"); mainscr(1); }
	}
}


void Bank() {
	system("cls"); 
	printf("Sorry you don't have enough money!\n\n But you can always borrow from the bank, but remember you have to pay it back.\n And your pay back is growing with 5%% after each round!\n\n\t\t1. Borrow\n\t\t2. Exit\n\t\t3. Delete account");
	while (1) {
		char men = _getch();
		if (men == '1') { if (user.debt == 0) { break; } else { printf("\n\tYou cannot choose this option because you already has debt!"); Sleep(2000); system("cls"); Bank(); } }
		if (men == '2') { log_out(); startingscreen(); }
		if (men == '3') { deleteuser(); log_out(1); startingscreen(); }
	}

	system("cls");
	printf("Your options:\n\t1. 10000 coin\n\t2. 5000 coin\n\t3. 2000 coin");

	while (1) {
		char men = _getch();
		if (men == '1') { user.debt = 10000; user.coin = 10000; save(); break; }
		if (men == '2') { user.debt = 5000; user.coin = 5000; save(); break; }
		if (men == '3') { user.debt = 2000; user.coin = 2000; save(); break; }
	}
	
	mainscr(1);
}

void debtpayback() {
	user.coin -= user.debt;
	user.debt = 0;
	system("cls");
	mainscr(1);
}