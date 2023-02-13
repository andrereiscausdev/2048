#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>


//STRUCT
typedef struct{
	char nome[10];
	char senha[15];
}cadastro;

typedef struct{
    char nome[25];
    char senha[25];
    int score;
}ranking;

ranking rank; // TIPO RANK, PUXAR OS DADOS 

FILE *arqrank; // CRIANDO ARQUIVO TXT

//PROCEDIMENTOS:
void TelaMenu();
void TelaCadastro();
void TelaEntrar();
void TelaOpcaoInvalida();
void TelaJogo();
void TelaRkg();
void limpaCasas();
void jogada();
void preencheCampoComDois();
void gotoxy();
void posicionando();
void inicializar();

// FUNCOES
int desceNumeros();
int sobeNumeros();
int esquerdaNumeros();
int direitaNumeros();
int verificarJogadas();
void abre_arquivo(void);
int dados(int i); //ARMAZENANDO DADOS EM UM LOOP 

// VAR GLOBAIS
int matriz[4][4];
int tecla = 0;
int score = 0;
int opcao = 0;

int main(){
	system("color 06"); // COLOCAR COR NO JOGO INTEIRO
    abre_arquivo(); // CRIANDO TXT
    char nomerk;
	TelaMenu();
	
}

void abre_arquivo(void){//CRIA O ARQUIVO TXT

	arqrank=fopen("arquranking.txt","a+b"); // ARQ COMO PONTEIRO DO ARQUIVO TXT E DANDO NOME E ABRINDO ARQ  A = ALTERAR B = PARA NÃO FICAR CRIANDO INFINITO 

}



TelaMenu(){  // VOID DA TELA DO MENU
	system("cls");
	printf("\n\n");
	printf("                                         ____________________________________________________________________________________ \n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                       MENU                                       ||\n");
	printf("                                        ||__________________________________________________________________________________||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                 $$$$$$$$        $$$$$             $$$$      $$$$$$$$             ||\n");
	printf("                                        ||                $$$$  $$$$$   $$$$   $$$$        $$$$$$    $$$$   $$$$            ||\n");
	printf("                                        ||                       $$$$  $$$$$    $$$$      $$$$$$$    $$$$   $$$$            ||\n");
	printf("                                        ||                      $$$$   $$$$     $$$$    $$$$  $$$      $$$-$$$              ||\n");
	printf("                                        ||                    $$$$$    $$$$     $$$$   $$$$   $$$      $$$-$$$              ||\n");
	printf("                                        ||                  $$$$$      $$$$     $$$$  $$$$$$$$$$$$$  $$$$    $$$$           ||\n");
	printf("                                        ||                $$$$$         $$$$   $$$$$ $$$$$$$$$$$$$$ $$$$      $$$$          ||\n");
	printf("                                        ||               $$$$$$$$$$$$    $$$$$$$$$$           $$$    $$$$$$$$$$$            ||\n");
	printf("                                        ||               $$$$$$$$$$$$       $$$$              $$$        $$$$               ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                              1 - NOVO JOGADOR                                    ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                              2 - INICIAR SESSAO                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                              3 - INICIAR JOGO                                    ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                              4 - RANKING                                         ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||__________________________________________________________________________________||\n");
	printf("                                        ||__________________________________________________________________________________||\n"); 
	printf(" Escolha uma opcao: ");

	int opcao = 0;
	do{ // LOOP DO WHILE ENQUANTO FOR DIFERENTE DE 0, ESOLHER AS TELAS
		opcao = getch(); // CAPTURAR AS TECLAS
		switch(opcao){
			case 49: // ASCII DA TECLA 1
				system("cls");
				TelaCadastro();
				opcao = 0;
				break;
			case 50: // ASCII DA TECLA 2
				system("cls");
				TelaEntrar();
				opcao = 0;
				break;
			case 51: // ASCII DA TECLA 3
				system("cls");
				TelaJogo();
				opcao = 0;
				break;
			case 52: // ASCII DA TECLA 4
				system("cls");
				TelaRkg();
				opcao = 0;
				break;
			default:
				printf("\nERRO!"); // SE DIGITAR QUALQUER NUMERO DIFERENTE DE 0 E ATÉ O 4
				break;
		}
	} while (opcao != 0);
}


TelaCadastro(){
	char c, nome[17], senha[11]; // DEFININDO TAMANHO DA SENHA E NOME
	int cont = 0;
	int opcao = 0;
	 
	system("cls");
	printf("\n\n");
	printf("                                         ____________________________________________________________________________________ \n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                     CADASTRO                                     ||\n");
	printf("                                        ||__________________________________________________________________________________||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                 $$$$$$$$        $$$$$             $$$$      $$$$$$$$             ||\n");
	printf("                                        ||                $$$$  $$$$$   $$$$   $$$$        $$$$$$    $$$$   $$$$            ||\n");
	printf("                                        ||                       $$$$  $$$$$    $$$$      $$$$$$$    $$$$   $$$$            ||\n");
	printf("                                        ||                      $$$$   $$$$     $$$$    $$$$  $$$      $$$-$$$              ||\n");
	printf("                                        ||                    $$$$$    $$$$     $$$$   $$$$   $$$      $$$-$$$              ||\n");
	printf("                                        ||                  $$$$$      $$$$     $$$$  $$$$$$$$$$$$$  $$$$    $$$$           ||\n");
	printf("                                        ||                $$$$$         $$$$   $$$$$ $$$$$$$$$$$$$$ $$$$      $$$$          ||\n");
	printf("                                        ||               $$$$$$$$$$$$    $$$$$$$$$$           $$$    $$$$$$$$$$$            ||\n");
	printf("                                        ||               $$$$$$$$$$$$       $$$$              $$$        $$$$               ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                               NOME:                                              ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                               SENHA:                                             ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                             DEPOIS DE COMPLETAR                                  ||\n");
	printf("                                        ||                         [ESC] PARA VOLTAR AO INICIO                              ||\n");
	printf("                                        ||__________________________________________________________________________________||\n");
	printf("                                        ||__________________________________________________________________________________||\n");
	
	
	gotoxy (78,22); // POSOCIONANDO NA TELA NOME E SENHA
	fflush(stdin);
    gets(rank.nome); // ARMAZENANDO NO TXT
				
	gotoxy (79,24);
	fflush(stdin);
	gets(rank.senha); // ARMAZENANDO NO TXT
	
	fwrite(&rank, sizeof(ranking), 1, arqrank); //GUARDAR OS DADOS NO ARQUIVO
    		
    	

	do{ // LOOP DO WHILE ENQUANTO FOR DIFERENTE DE 0, ESOLHER AS TELAS
		opcao = getch(); // CAPTURAR AS TECLAS
		switch(opcao){
			case 27: // ASCII DA TECLA ESC
				system("cls");
				TelaMenu();
				opcao = 0;
				break;
			default:
				printf("\nERRO! [ ESC ] PARA VOLTAR MENU");
				break;
		}
	} while (opcao != 0);
}


TelaEntrar(){ // TELA ENTRAR PARA INICIAR SESSAO
	char c, nome[11], senha[11]; // DEFININDO TAMANHO DA SENHA E NOME
	int cont = 0;
	
	system("cls");
	printf("\n\n");
	printf("                                         ____________________________________________________________________________________ \n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                  INICIANDO SESSAO                                ||\n");
	printf("                                        ||__________________________________________________________________________________||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                 $$$$$$$$        $$$$$             $$$$      $$$$$$$$             ||\n");
	printf("                                        ||                $$$$  $$$$$   $$$$   $$$$        $$$$$$    $$$$   $$$$            ||\n");
	printf("                                        ||                       $$$$  $$$$$    $$$$      $$$$$$$    $$$$   $$$$            ||\n");
	printf("                                        ||                      $$$$   $$$$     $$$$    $$$$  $$$      $$$-$$$              ||\n");
	printf("                                        ||                    $$$$$    $$$$     $$$$   $$$$   $$$      $$$-$$$              ||\n");
	printf("                                        ||                  $$$$$      $$$$     $$$$  $$$$$$$$$$$$$  $$$$    $$$$           ||\n");
	printf("                                        ||                $$$$$         $$$$   $$$$$ $$$$$$$$$$$$$$ $$$$      $$$$          ||\n");
	printf("                                        ||               $$$$$$$$$$$$    $$$$$$$$$$           $$$    $$$$$$$$$$$            ||\n");
	printf("                                        ||               $$$$$$$$$$$$       $$$$              $$$        $$$$               ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                               NOME:                                              ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                               SENHA:                                             ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                            [ENTER] PARA IR AO JOGO                               ||\n");
	printf("                                        ||                             [ESC] PARA IR AO MENU                                ||\n");
	printf("                                        ||__________________________________________________________________________________||\n");
	printf("                                        ||__________________________________________________________________________________||\n");
	
	 
	
	gotoxy (78,22); // POSOCIONANDO NA TELA NOME, EMAIL E SENHA
	fflush(stdin);
     gets(rank.nome); // ARMAZENANDO NO TXT
				
	gotoxy (79,24);
	fflush(stdin);
	gets(rank.senha); // ARMAZENANDO NO TXT
	

	int opcao = 0;

	do{ // LOOP DO WHILE ENQUANTO FOR DIFERENTE DE 0, ESOLHER AS TELAS
		opcao = getch();
		switch(opcao){
			case 27: // ASCII DA TECLA ESC
			    system("cls");
				TelaMenu();
				opcao = 0;
				break; 
			case 13: // ASCII DA TECLA ENTER
				system("cls");
				TelaJogo();
				opcao = 0;
				break; // PARAR O COMANDO
			default: // CLICAR QUALQUER TECLA DIFERENTE DE ENTER E ESC
				printf("\nERRO!");
				break;
		}
	} while (opcao != 0);   
}

void desenha(int status){	// TELA DE DESENHO DO JOGO E INT STATUS PARA VERIFICAR AS JOGADAS
	int i, y, z; // VARIAVEIS CRIADAS PARA CRIAR A TELA

	system("cls");
	printf("\n\n");
	printf("                                         ____________________________________________________________________________________ \n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                              OBJETIVO : ALCANCAR 2048                            ||\n");
	printf("                                        ||__________________________________________________________________________________||\n");
	if(status == 0 && verificarJogadas() == 0){ // VERIFICANDO O GAME OVER
		printf("\tGAME OVER - SCORE: %d\n", score);
		
	} else {
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||_______________                                                    _______________||\n");
	printf("                                                         |                                                  |                  \n");
	printf("                                            BOA SORTE    |                                                  | PONTOS: %d       \n", score);
	printf("                                          _______________|                                                  |_______________   \n");
	printf("                                        ||                                                                                  ||\n");
	}
	for(i = 0; i < 4; i++){ // IMPRIMINDO 4 VEZES EM L 
	  printf("\t                                ||        ===================================================================       || \n");
	  printf("\t                                          ||");
		for(y = 0; y < 4; y++){
			if(matriz[i][y] == 0) 
				printf("\t \t   ||"); // IMPRIMINDO 4 VEZES EM C
			else
				printf("\t   %d\t   ||", matriz[i][y]); // PARA NÃO QUEBRAR O CÓDIDO 
		}
		printf("\n\t                                ||        ===================================================================       || \n");
	}
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||                                                                                  ||\n");
	printf("                                        ||__________________________________________________________________________________||\n");
	printf("                                        ||__________________________________________________________________________________||\n"); 
	printf("\t                                         USE AS SETAS DO TECLADO                       [ESC] PARA SAIR \n");
	
	
	
}

TelaJogo(status){ // JOGADAS E PUXANDO STATUS PARA VERIFICAR AS JOGADAS
	jogada(1);
	do{ // LOOP DO WHILE ENQUANTO FOR DIFERENTE DE 0, ESOLHER A DIREÇÃO DAS JOGADAS
		tecla = getch(); // CAPTURAR AS TECLAS
		
		switch (tecla) {
		case 75: //Seta para esquerda
			jogada(esquerdaNumeros());
			break; 
		case 72: //Seta para cima
			jogada(sobeNumeros());
			break;
		case 77: //Seta para direita
			jogada(direitaNumeros());
			break;
		case 80: //Seta para baixo
			jogada(desceNumeros());
			break; // PARAR O COMANDO
		case 27: // ASCII DA TECLA ESC
			system("cls");
			TelaMenu();
			opcao = 0;
			break; 
		}	
	}while(tecla != 0); 	
	return 0; //system("pause");
	
}

TelaRkg(){ // TELA DE RANKING
	system("cls");
	
	printf("\n\n");
	 
    int j=1;
    printf("                                        ________________________________________________________________________ \n");
	printf("                                       |                                                                        |\n");
	printf("                                       |                                RANKING                                 |\n");
	printf("                                       |________________________________________________________________________|  ");
	printf("\n                                       |                        |                        |                      |");
	printf("\n                                       |       COLOCACAO        |          NOME          |         PONTOS       |");
	printf("\n                                       |________________________|________________________|______________________|");

	rewind(arqrank);//MOVE PARA INICIO DO ARQUIVO

	do
	{

		fread(&rank, sizeof(ranking), 1, arqrank);//LE O ARQUIVO LINHA A LINHA
		dados(j); // LOOP 
		if(feof(arqrank)==0);
        j++; // LOOP +1

	}while(feof(arqrank)==0);

    printf("\n                                       |________________________|________________________|______________________| \n\n\n");
	printf(" [ESC] PARA VOLTAR AO MENU");
    system("pause>null");
	   
	
	do{
		opcao = getch();
		switch(opcao){
			case 27: // ASCII DA TECLA ESC
				system("cls");
				TelaMenu(); // VOLTAR PARA A TELA MENU SE CLICAR ESC
				opcao = 0;
				break;
			default:
				printf("\nERRO!"); // SE DIGITAR QUALQUER NUMERO DIFERENTE DE 0 E ESC
				break;
		}
	} while (opcao != 0); 
}

	int dados(int i){
    	//DADOS DOS JOGADORES LINHA A LINHA
       	// DE ACORDO COM A QUANTIDADE
    	printf("\n                                       |  %d  COLOCADO           |   %-15s      |    %-11d       | \n",i,rank.nome,rank.score); // 15 E 11 PARA TAMANHO PARA DIVIDIR OS TAMANHO DAS COLUNAS E PUXANDO DADOS DO TXT
	}		
			
limpaCasas(){
int i, y, cont = 2; // DEIXANDO TODAS AS CASAS EM BRANCO 
	for (i = 0; i < 4; i++) {
		for (y = 0; y < 4; y++) {
			matriz[i][y] = 0;
		}
	}
}
			
			
desceNumeros(){ 
int c, l, jogada = 0; // Criando variavel c, l e jogada em todos os movimentos
	for(c = 0; c < 4; c++){ // Coluna
		for(l = 3; l >= 1; l--){ // Linha
			if(matriz[l][c] == 0 && matriz[l-1][c] > 0){
				matriz[l][c] = matriz[l-1][c];
				matriz[l-1][c] = 0;
				l = 4;
				jogada = 1;
			}
		}

	for(l = 3; l >= 1; l--){
		if(matriz[l][c] == matriz[l-1][c]){
			matriz[l][c] += matriz[l-1][c];
			matriz[l-1][c] = 0;
			score += matriz[l][c]; // CHECANDO PONTOS
		}
	}

		for(l = 3; l >= 1; l--){
			if(matriz[l][c] == 0 && matriz[l-1][c] > 0){
				matriz[l][c] = matriz[l-1][c];
				matriz[l-1][c] = 0;
				l = 4;
				jogada = 1;
			}
		}
	}
	return jogada; // RETORNA JOGADA
}
			
sobeNumeros(){
int c, l, jogada = 0;
	for(c = 0; c < 4; c++){ // Coluna
		for(l = 0; l < 3; l++){ // Linha
			if(matriz[l][c] == 0 && matriz[l+1][c] > 0){
				matriz[l][c] = matriz[l+1][c];
				matriz[l+1][c] = 0;
				l = -1;
				jogada = 1;
			}
		}

	for(l = 0; l < 3; l++){
		if(matriz[l][c] == matriz[l+1][c]){
		matriz[l][c] += matriz[l+1][c];
		matriz[l+1][c] = 0;
		score += matriz[l][c];
		}
	}

		for(l = 0; l < 3; l++){
			if(matriz[l][c] == 0 && matriz[l+1][c] > 0){
				matriz[l][c] = matriz[l+1][c];
				matriz[l+1][c] = 0;
				l = -1;
				jogada = 1;
			}
		}
	}
		return jogada; // RETORNA JOGADA
}
			
esquerdaNumeros(){
int c, l, jogada = 0;
	for(l = 0; l < 4; l++){ // Coluna
		for(c = 0; c < 3; c++){ // Linha
			if(matriz[l][c] == 0 && matriz[l][c+1] > 0){
				matriz[l][c] = matriz[l][c+1];
				matriz[l][c+1] = 0;
				c = -1;
				jogada = 1;
			}
		}

	for(c = 0; c < 3; c++){
		if(matriz[l][c] == matriz[l][c+1]){
			matriz[l][c] += matriz[l][c+1];
			matriz[l][c+1] = 0;
			score += matriz[l][c];
		}
	}

		for(c = 0; c < 3; c++){
			if(matriz[l][c] == 0 && matriz[l][c+1] > 0){
				matriz[l][c] = matriz[l][c+1];
				matriz[l][c+1] = 0;
				c = -1;
				jogada = 1;
			}
		}
	}
		return jogada; // RETORNA JOGADA
}
			
direitaNumeros(){
int c, l, jogada = 0;
	for(l = 0; l < 4; l++){ // Coluna
		for(c = 3; c >= 1; c--){ // Linha
			if(matriz[l][c] == 0 && matriz[l][c-1] > 0){
				matriz[l][c] = matriz[l][c-1];
				matriz[l][c-1] = 0;
				c = 4;
				jogada = 1;
			}	
		}

	for(c = 3; c >= 1; c--){
		if(matriz[l][c] == matriz[l][c-1]){
			matriz[l][c] += matriz[l][c-1];
			matriz[l][c-1] = 0;
			score += matriz[l][c];
		}
	}

		for(c = 3; c >= 1; c--){
			if(matriz[l][c] == 0 && matriz[l][c-1] > 0){
				matriz[l][c] = matriz[l][c-1];
				matriz[l][c-1] = 0;
				c = 4;
				jogada = 1;
			}
		}
	}
		return jogada; // RETORNA JOGADA
}		
			
verificarJogadas(){ 
	int c, l;

		for(c = 0; c < 4; c++){  // verificando as jogadas
			for(l = 0; l < 4; l++){
				if (matriz[l][c] == 0) {
					return 1;
				}
			}
		for(l = 3; l >= 1; l--){
			if(matriz[l][c] == matriz[l-1][c] || matriz[l][c] == matriz[l][c-1]){
				return 1;
			}
		}
			for(l = 0; l < 3; l++){
				if(matriz[l][c] == matriz[l+1][c] || matriz[l][c] == matriz[l][c+1]){
					return 1;
				}
			}
		}
			return 0;
}
		
		
jogada(int status) { // ENQUANTO NÃO DER O GAME OVER 
	int i = 0, y = 0, cont = 0; //linha e coluna com i e y e contador

	for (i = 0; i < 4; i++) {
		for (y = 0; y < 4; y++) {
			if (matriz[i][y] == 0) {
				cont++;
			}
		}
	}

	if(status != 0){
		preencheCampoComDois(cont); // SORTEANDO 2 ENQUANTO PODER JOGAR 
		desenha(1); // PUXANDO A TELA DESENHA DO JOGO
	} else {
		if(verificarJogadas() == 1){
			desenha(1); 
		} else {
			desenha(0); // SEM JOGADA
		}
	}
}
	
preencheCampoComDois(int cont){ // SORTEADOR
	int i, y, auxCont; // LINHA, COLUNA E AUX P CONTADOR E GUARDAR

		srand(time(NULL)); // TIME IGUAL HORA DO COMPUTADOR
		auxCont = rand() % cont;  // SORTEANDO NUM
		cont = 0;

	for (i = 0; i < 4; i++) {
		for (y = 0; y < 4; y++) {
			if (matriz[i][y] == 0) {
			if (cont == auxCont) {
				matriz[i][y] = 2;
			}
				cont++;
			}
		}
	}
}



gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
