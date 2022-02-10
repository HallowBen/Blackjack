#define _CRT_SECURE_NO_WARNINGS
#include "blackjack.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctime>

using namespace std;
void log_out();
void help();

void mainscr(int first) {
	if (first == 0) { clear(); }
	printf("Welcome in the world of blackjack!\n\n%s\n%i\n\n\n\t1. Start\n\t2. Help\n\t3. Records\n\t4. Log out", user.username, user.coin);
	while (1) {
		char men = _getch();
		if (men == '1'){ gamestart(); }
		if (men == '2'){ help(); }
		if (men == '3') { recordscr(); }
		if (men == '4') { log_out(); startingscreen(); }
	}
}

void log_out() {
	save();
	userid usercleaner;
	usercleaner.coin = 0;
	usercleaner.line = 0;
	user.coin = usercleaner.coin;
	user.line = usercleaner.line;
	strcpy(user.password, usercleaner.password);
	strcpy(user.username, usercleaner.username);
}

void help() {
	system("cls");
	printf("\t\tThe Blackjack!\n\nThe Main gole:\n\tThe player's cards' value must be as close to 21 as possible without goes over.\n\nCard values:\n\tAce: +1 or +11\n\tTwo: +2\n\tThree: +3\n\tFour: +4\n\tFive: +5\n\tSix: +6\n\tSeven: +7\n\tEight: +8\n\tNine: +9\n\tTen: +10\n\tJack: +10\n\tKing: +10\n\tQueen: +10\n\nHow the pay out:\n\tIf you have 21 it doubles the bet, else it just give you the bet or if you loose it takes away the bet.\n\nPlayer's Choises:\n\tHit: Give you a new card\n\tStand: The House turn or your second hand\n\tDouble: Doubles once in a round your bet\n\tSurrender: automatic house win\n\tSplit: You can split your deck to two hand, if you have the same card");
	printf("\n\n\t\t1. Back");
	while (true) {
		char menu = _getch();
		if (menu == '1') { system("cls"); mainscr(1); }
	}
}