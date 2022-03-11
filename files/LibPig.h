#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colors.h"
#include <windows.h>
//Estruturas

	enum nivel {
			basico, dificil
		};

//Tela login
struct login {
	char user[20];
	char password[20];
};
typedef struct login tLogin;

//dados do jogador
struct jogador {
	char nickname[20];
	int score;
	int score2;
	int dificuldade;
};
typedef struct jogador tJogador;

//opcoes do menu
struct opcoes {
	int newGame;
	int viewRank;
	int exit;
	int select;
};
typedef struct opcoes tOpcao;

//Apenas as assinaturas das funções

void nivelBasico();
void nivelDificil();
void telaGame();
void telaMenu();
void telaLogin();

