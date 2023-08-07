#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>

void playerMove(int x, char nickname[50]);
void computerMove(int x);
void winner(int p, int c, char nickname[50]);
void secretMove(int p, int c, char nickname[50]);

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	int player, computer;
	char name[50];
	
	printf("\t\tJoKenPô\n\n");
	
	printf("Digite o seu nome (somente o primeiro se for composto): ");
	scanf("%s", &name);
	
	printf("\n1. Pedra\n");
	printf("2. Papel\n");
	printf("3. Tesoura\n");
	printf("Digite a opção desejada: ");
	scanf("%d",&player);
	
	printf("_______________________________\n");
	
	if (player == 4 || player == 5)
	{
		printf("Parabéns!! Você desbloqueou um caminho oculto!!!\n");
		system("pause");
		playerMove(player, name);
		srand(time(NULL));
		computer = ("%d", rand()%5 + 1);
		computerMove(computer);
		secretMove(player, computer, name);
	} else
		{
			playerMove(player, name);
			srand(time(NULL));
			computer = ("%d",rand()%3 + 1);
			computerMove(computer);
			winner(player, computer, name);
		}
	
	system("pause");
	
	return 0;
}

void playerMove(int x, char nickname[50])
{
	switch(x)
	{
		case 1:
			printf("\n%s escolheu Pedra\n", nickname);
		break;
		
		case 2:
			printf("\n%s escolheu Papel\n", nickname);
		break;
		
		case 3:
			printf("\n%s escolheu Tesoura\n", nickname);
		break;
		
		case 4:
			printf("\n%s escolheu Lagarto\n", nickname);
		break;
		
		case 5:
			printf("\n%s escolheu Spock\n", nickname);
		break;
		
		default:
			printf("\nOpção inválida\n");
			exit(1);
	}
}

void computerMove(int x)
{
	switch(x)
	{
		case 1:
			printf("Computador escolheu Pedra\n");
		break;
		
		case 2:
			printf("Computador escolheu Papel\n");
		break;
		
		case 3:
			printf("Computador escolheu Tesoura\n");
		break;
		
		case 4:
			printf("Computador escolheu Lagarto\n");
		break;
		
		case 5:
			printf("Computador escolheu Spock\n");
		break;		
	}
}

void winner(int p, int c, char nickname[50])
{
	if(p == c)
		printf("\nEmpate\n");
	else if((p == 1 && c == 3) || (p == 2 && c == 1) ||(p == 3 && c == 2))
		printf("\n%s Venceu\n", nickname);
	else
		printf("\nComputador Venceu\n");
}

void secretMove(int p, int c, char nickname[50])
{	
	if(p == c)
		printf("\nEmpate\n");
	else if((p == 1 && c == 3) || (p == 2 && c == 1) ||(p == 3 && c == 2) || (p == 4 && c == 2) || (p == 4 && c == 5) || (p == 5 && c == 1) || (p == 5 && c == 3))
		printf("\n%s Venceu\n", nickname);
	else
		printf("\nComputador Venceu\n");
}

// spock > pedra e tesoura
// papel > spock
// lagarto > papel e spock
// tesoura > lagarto
// pedra > lagarto
