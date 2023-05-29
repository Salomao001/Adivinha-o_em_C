#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NEGATIVO chute < 0

int main()
{
	printf(
	"		                 							            					\n"
    "	     -|                  [-_-_-_-_-_-_-_-]                  |-					\n"
    "	     [-_-_-_-_-]          |             |          [-_-_-_-_-]	Bem vindo		\n"
    "	      | o   o |           [  0   0   0  ]           | o   o |	ao Jogo			\n"
    "	       |     |    -|       |           |       |-    |     |	de Adivinhacao!	\n"
    "	       |     |_-___-___-___-|         |-___-___-___-_|     |					\n"
    "	       |  o  ]              [    0    ]              [  o  |					\n"
    "	       |     ]   o   o   o  [ _______ ]  o   o   o   [     | ----__________		\n"
	"    _____----- |     ]              [ ||||||| ]              [     |				\n"
    "	       |     ]              [ ||||||| ]              [     |					\n"
    "	   _-_-|_____]--------------[_|||||||_]--------------[_____|-_-_				\n"
    "	  ( (__________------------_____________-------------_________) )			\n\n\n");

    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nivel de dificuldade?\n");
    printf("(1)Facil (2)Medio (3)Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch(nivel) {
    	case 1:
    		numerodetentativas = 20;
    		break;

    	case 2:
    		numerodetentativas = 15;
    		break;

    	default:
    		numerodetentativas = 6;
    		break;
    }

    for(int i = 1; i <= numerodetentativas; i++) {

    	printf("Tentativa %d\n", tentativas);
    	printf("Qual e o seu chute? ");
    	scanf("%d", &chute);
    	printf("Seu chute foi %d\n", chute);

    	if(NEGATIVO) {
    		printf("Voce nao pode chutar numeros negativos!\n");
    		continue;
    	}

    	acertou = (chute == numerosecreto);
    	int maior = (chute > numerosecreto);

    	if(acertou) {
        	break;
        }
        else if(maior) {
            printf("Seu chute foi maior que o numero secreto\n");
        }
        else {
            printf("Seu chute foi menor que o numero secreto\n");
       	}
    	tentativas++;
    	double pontosperdidos = abs(chute - numerosecreto) / (double) 2;
    	pontos = pontos - pontosperdidos;
	}

	printf("Fim de jogo\n");

	if(acertou) {

	printf(
	"		      _.-'''''-._		 \n"
	"		    .'  _     _  '.      \n"
	"		   /   (o)   (o)   \\    \n"
	"		  |                 |    \n"
	"		  |  \\           /  |   \n"
	"		   \\  '.       .'  /    \n"
	"		    '.  `'---'`  .'      \n"
	"		      '-._____.-'      \n\n");

		printf("Voce ganhou!\n");
		printf("Voce acertou em %d tentativas!\n", tentativas);
		printf("Total de pontos: %.2f", pontos);
	} else {

	printf(
	"			  , ; ,   .-'---'-.   , ; ,		     \n"
	"			  \\\\|/  .'         '.  \\|//       \n"
	"			   \\-;-/   ()   ()   \\-;-/         \n"
	"			   // ;               ; \\\\         \n"
	"			  //__; :.         .; ;__\\\\        \n"
	"			 `-----\\'.'-.....-'.'/-----'        \n"
	"			        '.'.-.-,_.'.'     	         \n"
	"			          '(  (..-'				     \n"
	"			            '-'					   \n\n");

		printf("Voce perdeu. Tente de novo!\n");
	}
}