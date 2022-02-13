#pragma once
#ifndef _BLACKJACK_H
#define _BLACKJACK_H

typedef struct userid {
	int line;
	char username[21];
	char password[17];
	int coin;
	int debt;
}users;

typedef struct carddeck {
	int num;
	char name[17];
	int value;
	int split;
}card;

extern carddeck deck[52];
extern userid user, userinf;
extern carddeck pcsdeck[26];
extern carddeck playersdeck[26];
extern carddeck playersdeck2[26];
extern int pcy, ply, pl2y, nc, plbet;


//it's generating the deck
extern void deckinput();
//the loggin screen
extern void startingscreen();
//after loggin screen
extern void mainscr(int first);
//buffer clearer
extern void clear();
//game starter
extern void gamestart();
//start players round
extern void playersround(int x);
//card output
extern void showcard(int pcorpl);
//card drawing
extern void Hit();
//pc's round
extern void Stand();
//doubling the bet
extern void Doubling();
//pc auto win
extern void Surrender();
//play with two deck
extern void Split();
//ai round
extern void airound();
//instant aiwin
extern void aiwin(int plvalue, int pcvalue);
//instant playerwin
extern void plwin(int plvalue, int pcvalue);
//it desides who is the winner
extern void whowin();
//players bet
extern void bet();
//encyription
extern userid encryption(userid users);
//save the user data after a round
extern void save();
//split deck hit
extern void splitdeck();
//it defines who is the winner if the deck is splitted
extern void splitwin(int pl, int pl2, int pc);
//record into a file
extern void record();
//record to the screen
extern void recordscr();
//user delete
extern void deleteuser();
//bank
extern void Bank();
//it increase the debt
extern int debtincreaser(float debt);
//debt pay back
extern void debtpayback();

#endif _BLACKJACK_H
