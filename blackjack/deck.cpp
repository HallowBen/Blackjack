#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string.h>
#include <ctime>
#include "blackjack.h"

using namespace std;

card deck[52];

void deckinput() {
	srand(time(0));
	char input[1024];

	FILE* crd;
	int h, j, g;
	for (int i = 0; i < 52; i++)
	{
		crd = NULL;
		crd = fopen("carddeck.txt", "r");
		h = rand() % 52;
		//printf("%i\n", h);
		deck[i].num = h;
		h++;

		j = 0;
		while (j < h)
		{
			fgets(input, sizeof(input), crd);
			j++;
		}
		sscanf(input, "%[^\n]s", deck[i].name);

		fclose(crd);
		g = i - 1;
		while (g >= 0)
		{
			if (deck[i].num == deck[g].num) { i--; break; }
			g--;
		}

	}

	for (int i = 0; i <= 52; i++)
	{
		if ( deck[i].num > 47) { deck[i].value = 10; }
		else if ( deck[i].num > 43) { deck[i].value = 10; }
		else if (deck[i].num > 39) { deck[i].value = 10; }
		else if (deck[i].num > 35) { deck[i].value = 10; }
		else if (deck[i].num > 31) { deck[i].value = 9; }
		else if (deck[i].num > 27) { deck[i].value = 8; }
		else if ( deck[i].num > 23) { deck[i].value = 7; }
		else if (deck[i].num > 19) { deck[i].value = 6; }
		else if (deck[i].num > 15) { deck[i].value = 5; }
		else if (deck[i].num > 11) { deck[i].value = 4; }
		else if (deck[i].num > 7) { deck[i].value = 3; }
		else if ( deck[i].num > 3) { deck[i].value = 2; }
		else { deck[i].value = 0; }
	}

	/*for (int i = 0; i < 52; i++)
	{
		printf("%i %s %i\n", i, deck[i].name, deck[i].value);
		Sleep(2000);
	}*/


	for (int i = 0; i < 48; i+=4)
	{
		if (deck[1].num > i and deck[1].num <= i + 4) {
			if (deck[3].num > i and deck[3].num <= i + 4) {
				deck[1].split = 1;
			}
		}
	}
}