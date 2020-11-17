#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<list>
using namespace std;

# define ARRIBA 72
# define IZQUIERDA 75
# define DERECHA 77
# define ABAJO 80


// simula funcion de Borl
void gotoxy(int x, int y){

	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon,dwPos);
}

void mapa(){
	for(int i=2; i<78; i++){
		gotoxy(i,3);
			printf("%c",205);
		gotoxy(i,33);
			printf("%c",205);
	}
	for(int i=4; i<33; i++){
		gotoxy(2,i);
			printf("%c",186);
		gotoxy(77,i);
			printf("%c",186);
	}
	gotoxy(2,3); printf("%c",201);
	gotoxy(2,33); printf("%c",200);
	gotoxy(77,3); printf("%c",187);
	gotoxy(77,33); printf("%c",188);
}

int main(){
	mapa();
}
