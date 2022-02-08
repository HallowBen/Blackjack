#define _CRT_SECURE_NO_WARNINGS
#include "blackjack.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctime>

const long Key= 207512;
userid encryption(userid users) {
	for (int j = 0; j < 25; j++)
	{
		if (users.username[j] == '\0' or users.username[j] == EOF ) { users.username[j] == '\0'; break; }
		else { users.username[j] = users.username[j] ^ Key; }
	}
	int passlength = strlen(users.password);
	for (int h = 0; h < passlength; h++)
	{
		if (users.password[h] == '\0') { break; }
		//std::cout << "\n" << users.password[h] ;
		users.password[h] = users.password[h] ^ Key;
		//std::cout <<" " << users.password[h];
		//Sleep(1000);
	}
	users.coin = users.coin ^ Key;
	return users;
}




void save() {
	system("cls");
	FILE* file, *temp;
	file = fopen("USERS.txt", "r");
	temp = fopen("temp____USERS.temp", "w");
	if (file == NULL || temp == NULL) { printf("Opening Error!"); }

	bool keep_reading = true;
	int current_line = 1;
	char buffer[2048];
	
	do {
		fgets(buffer, sizeof buffer, file);
		if (feof(file)) { keep_reading = false; }
		else if (current_line != user.line) { fputs(buffer, temp); }
		else{ user = encryption(user); fprintf(temp, "%i\t%s\t\t%s\t%i\n", user.line, user.username, user.password, user.coin); user = encryption(user);}

		current_line++;
	} while (keep_reading);

	fclose(file);
	fclose(temp);

	remove("USERS.txt");
	rename("temp____USERS.temp", "USERS.txt");
}