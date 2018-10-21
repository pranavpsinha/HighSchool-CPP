#include<bits/stdc++.h>
using namespace std;

char *getCharacterStreamFromString(string str) {
	char *c;
	for(char ch : str) {
		c += ch;
	}
	return c;
}

void backgroundColor(string colorCode = "") {
	if("" == colorCode) colorCode = "07";
	
	char *colorCommand = getCharacterStreamFromString("color "+colorCode);
	system(colorCommand);
}

void gotoxy(int x, int y) {
	for(int i=0; i<x; i++) cout<<endl;
	for(int i=0; i<y; i++) cout<<" ";
}

void clearScreen() {
	system("clear");
	system("cls");
}
