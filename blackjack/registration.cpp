#define _CRT_SECURE_NO_WARNINGS
#include "blackjack.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctime>

using namespace std;

users user;
users userinf;

void clear() {
	int ch{};
	while (ch = getchar() != '\n' && ch != EOF);
}


void startingscreen();
void newuser();

void Passwordtest() {
	char test;
	char input[256];
	int ch = 0, spc = 0, cpl = 0, num = 0, space = 0;

	printf("Password (min: 8 character, max: 16 charachter, must contain a specialcharacter(.,;?-), must contain number and at least one capital letter):");
	fgets(input, sizeof input, stdin);
	sscanf(input, "%s", &user.password);
	//printf("\n%s", user.password);
	//Sleep(2000);
	test = input[ch];
	ch = 0;
	while (test != '\n' && test != EOF and test != '\0' && ch < 17) {
		ch++;
		if (test == '.' or test == '-' or test == '+' or test == '*' or test == '/' or test == '_' or test == ':' or test == '?' or test == ',' or test == ';' or test == '>' or test == '<' or test == '}' or test == '{' or test == '@' or test == '&' or test == '#' or test == '[' or test == ']')
		{
			spc = 1;
		}
		if (isalnum(test) == 1) { num = 1; }
		if (isupper(test) == 1) { cpl = 1; }
		if (test == ' ') { space = 1; }
		test = input[ch];
	}

	if (spc == 0){
		printf("Your password is incorrect!!");
		Sleep(1000);
		system("cls");
		newuser();
	}
	if (ch < 8 or ch>16)
	{
		printf("Your password is incorrect!!");
		Sleep(1000);
		system("cls");
		newuser();
	}
	if (cpl == 0)
	{
		printf("Your password is incorrect!!");
		Sleep(1000);
		system("cls");
		newuser();
	}
	if (num == 0)
	{
		printf("Your password is incorrect!!");
		Sleep(1000);
		system("cls");
		newuser();
	}
	if (space != 0)
	{
		printf("Your password is incorrect!!");
		Sleep(1000);
		system("cls");
		newuser();
	}
}

void newuser() {
	int lines=0;
	char c{};
	system("cls");
	printf("Username (max: 20 charachter and it cannot contain space):");
	scanf("%s", &user.username);
	clear();
	Passwordtest();

	FILE* file;
	file = NULL;
	file = fopen("USERS.TXT", "r+");
	while (c != EOF) {
		fscanf(file, "%i\t%s\t\t%s\t%i", &user.line, &userinf.username, &userinf.password, &userinf.coin);
		userinf=encryption(userinf);
		if (strcmp(userinf.username, user.username) == 0)
		{
			printf("The username is already taken try another one!");
			Sleep(1000);
			newuser();
		}
		c = getc(file);
		lines++;
	}
	if (c == EOF) {
		user.coin = 10000;
		user=encryption(user);
		user.line = lines;
		fprintf(file, "%i\t%s\t\t%s\t%i\n", user.line, user.username, user.password, user.coin);
	}
	fclose(file);
	startingscreen();
}

void loggin(int start) {

	char userin[256];
	char passwordin[256];
	char c{};
	if (start == 1) {
		printf("Wrong username or Password try again! or Create a new accout (1)");
		if (_getch() == '1') {
			newuser();
		}
		else {
			loggin(0);
			system("cls");
		}
	}



	FILE* file;
	file = NULL;
	file = fopen("USERS.TXT", "r+");
	system("cls");
	printf("\nPlease give your Username:");
	scanf("%s", &userin);
	//if (strcmp(userin, "5") == 0) { printf("Welcome back Master!"); goto game; }
	printf("\nPlease give your Password:");
	scanf("%s", &passwordin);
	system("cls");
	while (c != EOF) {
		fscanf(file, "%i\t%s\t\t%s\t%i", &user.line, &user.username, &user.password, &user.coin);
		user=encryption(user);

		if (strcmp(userin, user.username) == 0 and strcmp(passwordin, user.password) == 0) {
			{printf("Welcome back %s!\nYour current money: %i", user.username, user.coin); }
		game: Sleep(1200);
			fclose(file);
			system("cls");
			mainscr(0);
			break;
		}


		c = getc(file);
	}
	fclose(file);
	clear();
	if (c == EOF) {
		system("cls");
		loggin(1);
	}
}


void startingscreen() {
	system("cls");
	printf("Please loggin or create a new account!\n      1.\t Logging\n      2.\t Register\n      3.\t Exit");
	while (1) {
			char men = _getch();
		if (men == '2')
		{
			newuser();
		}
		if (men == '1')
		{
			loggin(0);
		}
		if (men == '3')
		{
			exit(0);
		}
	}
}

int main(){
startingscreen();
}
