#define _CRT_SECURE_NO_WARNINGS
#include "blackjack.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctime>

struct recordid {
	int line = 0;
	char name[21] = "unknown";
	int coin = 0;
};

userid encryption(userid users) {
	const long Key = 207512;
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
	users.debt = users.debt ^ Key;
	return users;
}

recordid encryptionrecord(recordid users) {
	const long Key = 512209;
	for (int j = 0; j < 25; j++)
	{
		if (users.name[j] == '\0' or users.name[j] == EOF) { users.name[j] == '\0'; break; }
		else { users.name[j] = users.name[j] ^ Key; }
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
		else{ user = encryption(user); fprintf(temp, "%i\t%s\t\t%s\t%i\t%i\n", user.line, user.username, user.password, user.coin, user.debt); user = encryption(user);}

		current_line++;
	} while (keep_reading);

	fclose(file);
	fclose(temp);
	remove("USERS.txt");
	rename("temp____USERS.temp", "USERS.txt");
	record();
}







void record() {
	recordid records[11], rechelp;
	char buffer[1024];

	records[10].coin = user.coin;
	strcpy(records[10].name,user.username);

	FILE* file, * temp;
	file = temp = NULL;
	
	file = fopen("record.txt", "r");
	if (file == NULL) { printf("File Opening ERROR!"); }

	for (int i = 0; i < 10; i++) {
		fgets(buffer, sizeof buffer, file);
		sscanf(buffer, "%i\t%s\t\t%i", &records[i].line, &records[i].name, &records[i].coin);
		if (feof(file)) { break; }
	}
	fclose(file);

	for (int i = 0; i < 10; i++) {
		if (records[i].line != 0) {
			records[i] = encryptionrecord(records[i]);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (strcmp(records[i].name, records[10].name) == 0)
		{
			if (records[i].coin < records[10].coin) {
				records[i].coin = records[10].coin;
			}
			records[10].coin = 0; records[10].line = 0; strcpy(records[10].name, "unknown");
		}
	}

	for (int i=0; i < 10; i++) {
		rechelp = records[i];
		if (records[i].coin < records[10].coin) {
			records[10].line = i+1;
			records[i] = records[10];
			records[10] = rechelp;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (records[i].line != 0) {
			records[i] = encryptionrecord(records[i]);
		}
	}
	
	temp = fopen("temp____record.temp", "w");
	if(temp==NULL) { printf("File Opening ERROR!"); }

	for (int i = 0; i < 10; i++)
	{
		fprintf(temp, "%i\t%s\t\t%i\n", records[i].line, records[i].name, records[i].coin);
	}
	fclose(temp);
	remove("record.txt");
	rename("temp____record.temp", "record.txt");
}







void recordscr() {
	system("cls");
	printf("\n%-40s%-40s%-40s\n", "Placement", "User", "Money");
	for (int h = 0; h < 60; h++) { printf("%-2s", "_"); }
	printf("\n");
	
	char buffer[1024];
	recordid records[10];
	FILE* file;
	
	file = NULL;
	file = fopen("record.txt", "r");
	if (file == NULL) { printf("File opening error!"); exit(1); }
	
	for (int i = 0; i < 10; i++) {
		fgets(buffer, sizeof buffer, file);
		sscanf(buffer, "%i\t%s\t\t%i", &records[i].line, &records[i].name, &records[i].coin);
		if (feof(file)) { break; }
	}
	fclose(file);
	
	for (int i = 0; i < 10; i++) {
		if (records[i].line != 0) {
			records[i] = encryptionrecord(records[i]);
		}
	}

	for (int i = 0; i < 10; i++) {

		printf("\n  %-40i%-40s%i\n", records[i].line, records[i].name, records[i].coin);
		for (int h = 0; h < 60; h++) { printf("%-2s", "_"); }
		printf("\n");
	}

	printf("\n\n%50s", "1. Back");
	while (true) {
		char menu = _getch();
		if (menu == '1') { system("cls"); mainscr(1); }
	}
}




void deleteuser() {
	system("cls");
	userid tempuser;
	int deleter=0;
	FILE* file, * temp;
	file = fopen("USERS.txt", "r");
	temp = fopen("temp____USERS.temp", "w");
	if (file == NULL || temp == NULL) { printf("Opening Error!"); }

	bool keep_reading = true;
	int current_line = 1;
	char buffer[2048];

	do {
		fgets(buffer, sizeof buffer, file);
		sscanf(buffer, "%i\t%s\t\t%s\t%i\t%i\n", &tempuser.line, &tempuser.username, &tempuser.password, &tempuser.coin, &tempuser.debt);
		if (feof(file)) { keep_reading = false; }
		else if (current_line != user.line) {
			if (deleter != 0) { fprintf(temp, "%i\t%s\t\t%s\t%i\t%i\n", tempuser.line - 1, tempuser.username, tempuser.password, tempuser.coin, tempuser.debt); }
			else fputs(buffer, temp);
		}
		else { deleter = 1; }
		current_line++;
	} while (keep_reading);

	fclose(file);
	fclose(temp);
	remove("USERS.txt");
	rename("temp____USERS.temp", "USERS.txt");
}