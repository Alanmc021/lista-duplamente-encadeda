// ############################ //
// ALUNO: ALAN MARTINS DA CRUZ //
// ############################ //
#include "LDE.h"
#include <stdio.h>

int main()
{

	list* lista;
	lista = cria_lista();
	int val;
	int classifica;
	int repet;
	int opC;
	int opR;
	int opS;
	int op;


	printf("Tipo de lista: \n");
	printf("Digite [1] para lista classificada\n\n");
	printf("Digite [0] para lista nao classificada\n\n ");
	scanf("%d", &classifica);
	printf("Digite [1] para lista com repeticaoa\n\n");
	printf("Digite [0] para lista sem repeticaoa\n\n");
	scanf("%d", &repet);

	do
	{
		if (classifica == 1 || classifica == 0)
		{
			opC = 1;
			if (repet == 1 || repet == 0)
			{
				opR = 1;
			}
			else
			{
				opR = 0;
				printf("\n\n-----ERRO-----\n");
				printf("Valor incorreto\n\n");
				printf("Digite [1] para lista com repeticao\n\n");
				printf("Digite [0] para lista sem repeticao\n\n");
				scanf("%d", &repet);
			}
		}
		else
		{
			opC = 0;
			printf("\n\n-----ERRO-----\n");
			printf("Valor incorreto\n\n");
			printf("Digite [1] para lista classificada\n\n");
			printf("Digite [0] para lista nao classificada\n\n");
			scanf("%d", &classifica);
		}

		if (opC == 1 && opR == 1)
		{
			opS = 1;
		}
		else
		{
			opS = 0;
		}

	} while (opS != 1);


	cria_lista_vazia(lista, classifica, repet);
	printf("\n\n-----------SUA LISTA FOI CRIADA-----------\n\n");
	printf("TIPO: ");
	if (classifica == 1)
	{
		printf("CLASSIFICADA ");
	}
	else
	{
		printf("NAO CLASSIFICADA ");
	}
	if (repet == 1)
	{
		printf("COM REPETICAO");
	}
	else
	{
		printf("SEM REPETICAO");
	}
	printf("\n\n");

	do
	{
		printf("\n|------------------MENU------------------|\n");
		printf("| [1]Insercao de um novo numero		 |\n| [2]Remocao de determinado valor	 |\n| [3]Exibir todos os elementos da lista	 |\n| [4]Sair do sistema			 |");
		printf("\n|----------------------------------------|");
		printf("\n#Opcao: ");
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			printf("\nDigite o valor: ");
			scanf("%d", &val);
			if (insere_lista(lista, val))
			{
				printf("\n------------Valor foi inserido------------\n\n");
			}
			else
			{
				printf("\n------------Valor nao inserido------------\n\n");
			}
			break;
		case 2:
			printf("\nRemover numero: ");
			scanf("%d", &val);
			exclui(lista, val);
			break;
		case 3:
			exibir_lista(lista);
			break;
		case 4:
			break;
		default:
			printf("\n	!!!! Comando invalido !!!!\n");
		}
	} while (op != 4);
}