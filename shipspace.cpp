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

void ocultarCursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;  //mostrara cursor en pantalla

	SetConsoleCursorInfo(hCon,&cci);
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

void NAVE::pintar(){
	gotoxy(x,y); printf(" %c",94);
	gotoxy(x-1,y+1); printf("%c%c%c%c%c",91,00,70,00,93);
	gotoxy(x-3,y+2); printf(" %c%c%c%c%c%c%c",201,00,206,00,206,00,187);
}

int main(){
     ocultarCursor();
	mapa();

     gotoxy(15,10); printf("*");
     int x = 10, y = 10;

     bool game_over = false;
     while(!game_over){
          gotoxy(x,y); printf("*");
          if(kbhit()){
               char tecla = getch();
               if(tecla == 'j') x--;
               if(tecla == 'l') x++;
               if(tecla == 'i') y--;
               if(tecla == 'k') y++;
          }
     }
	return 0;
}
