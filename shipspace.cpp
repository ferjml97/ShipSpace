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


class NAVE{
	int x, y;
	int corazones;
	int vidas;
public:

};


void NAVE::pintar(){
	gotoxy(x,y); printf(" %c",94);
	gotoxy(x-1,y+1); printf("%c%c%c%c%c",91,00,70,00,93);
	gotoxy(x-3,y+2); printf(" %c%c%c%c%c%c%c",201,00,206,00,206,00,187);
}

void NAVE::borrar(){
	gotoxy(x,y); printf("        ");
	gotoxy(x-1,y+1); printf("         ");
	gotoxy(x-3,y+2); printf("          ");
}

void NAVE::mover(){
	if(kbhit()){
		char tecla = getch();
		borrar();
		gotoxy(x,y);
			printf(" ");
		if(tecla == IZQUIERDA && x>8) x--;
		if(tecla == DERECHA && x+8 < 77) x++;
		if(tecla == ARRIBA && y>4) y--;
		if(tecla == ABAJO && y+5 < 33) y++;
		if(tecla == 'e') corazones--;
		pintar();
		corazao();
	}
}

class ASTEROID{
	int x;
	int y;
public:
	ASTEROID(int _x, int _y):x(_x), y(_y){}
	int X(){ return x; }
	int Y(){ return y; }
	//void pintar();
	//void mover();
	//void colision(class NAVE &N);

	//strct  o class funciona igual
};

void ASTEROID::pintar(){
	gotoxy(x,y); printf("%c",184);
}

void ASTEROID::mover(){
	gotoxy(x,y); printf(" ");
	y++;
	if(y > 32){
		x = rand()%73 + 4;
		y = 4;
	}

	pintar();
}

void ASTEROID::colision(class NAVE &N){
	if(x >= N.X()-3 && x < N.X()+3 && y >= N.Y() && y < N.Y()+3){
		N.vida();
		N.borrar();
		N.pintar();
		N.corazao();
		x = rand()%71 + 4;
		y = 4;
	}
}


class BULLET{
	int x;
	int y;
public:
	BULLET(int _x, int _y): x(_x), y(_y){}
	int X(){ return x; }
	int Y(){ return y; }
	void bmover();
	bool fuera();
};

void BULLET::bmover(){
	gotoxy(x,y);
		printf(" ");
	y--;
	gotoxy(x,y);
		printf("*");
}

class BULLET2{
	int x;
	int y;
public:
	BULLET2(int _x, int _y): x(_x), y(_y){}
	int X(){ return x; }
	int Y(){ return y; }
	void b2mover();
	bool b2fuera();
};

void BULLET2::b2mover(){
	gotoxy(x,y);
		printf(" ");
	y--;
	gotoxy(x,y);
		printf("*");
}

bool BULLET2::b2fuera(){
	if(y == 4) return true;
	return false;
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
