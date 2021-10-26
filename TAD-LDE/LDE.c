
#include "LDE.h" 
#include <stdio.h>
#include <stdlib.h> 


struct Lista
{
	no* primeiro;
	no* ultimo;
	int clas;
	int rep;
};


struct Noli
{
	int v;
	no* anterior;
	no* sucessor;
};

list* cria_lista(void)
{

	list* l;
	l = (list*)malloc(sizeof(list));
	return l;
}

void cria_lista_vazia(list* l, int c, int r)
{
	l->primeiro = NULL;
	l->ultimo = NULL;
	l->clas = c;
	l->rep = r;
}

no* cria_no_lista(int val)
{

	no* novo;
	novo = (no*)malloc(sizeof(no));
	novo->v = val;
	novo->anterior = NULL;
	novo->sucessor = NULL;

	return;
}


int vazia_lista(list* l)
{
	return (l->primeiro == NULL);
}

int busca_lista(list* l, int val, no** pos)
{

	no* aux;
	int cond = 2;
	for (aux = l->primeiro; aux != NULL; aux = aux->sucessor)
	{
		if (aux->v == val)
		{
			*pos = aux;
			return 1;
		}
	}

	for (aux = l->primeiro; aux != NULL; aux = aux->sucessor)
	{

		if (aux->v > val)
		{
			*pos = aux;
			return 0;
		}
	}

	*pos = NULL;
	return 0;
}


int clas_lista(const list* l)
{
	return(l->clas == 1);
}

int rep_lista(const list* l)
{

	return(l->rep == 1);
}

void exibir_lista(list* l)
{

	no* p;
	if (vazia_lista(l))
	{
		printf("\n-------------Lista esta vazia-------------\n\n");
	}
	else
	{
		printf("\n\n|-------|\n");
		printf("| Lista |\n");
		printf("|-------|\n");
		for (p = l->primeiro; p != NULL; p = p->sucessor)
		{

			printf("| %3d	|\n", p->v);
		}
		printf("|-------|\n");

		return;
	}

}

int insere_lista(list* l, int valor)
{

	no* novo;
	no* pos;
	novo = cria_no_lista(valor);

	if (vazia_lista(l))
	{
		l->primeiro = l->ultimo = novo;
		return 1;
	}

	else
	{

		if (rep_lista(l))
		{

			if (clas_lista(l))
			{

				if (busca_lista(l, valor, &pos))
				{

					if (pos == l->primeiro)
					{

						l->primeiro->anterior = novo;
						novo->sucessor = l->primeiro;
						l->primeiro = novo;

						return 1;
					}

					else
					{

						pos->anterior->sucessor = novo;
						novo->anterior = pos->anterior;
						pos->anterior = novo;
						novo->sucessor = pos;
						return 1;
					}
				}
				else
				{

					if (pos == NULL)
					{

						l->ultimo->sucessor = novo;
						novo->anterior = l->ultimo;
						l->ultimo = novo;

						return 1;
					}

					else
					{

						if (pos == l->primeiro)
						{

							l->primeiro->anterior = novo;
							novo->sucessor = l->primeiro;
							l->primeiro = novo;

							return 1;
						}
						else
						{

							pos->anterior->sucessor = novo;
							novo->anterior = pos->anterior;
							pos->anterior = novo;
							novo->sucessor = pos;

							return 1;
						}
					}
				}
			}

			else
			{

				l->primeiro->anterior = novo;
				novo->sucessor = l->primeiro;
				l->primeiro = novo;
				return 1;
			}
		}
		else
		{

			if (busca_lista(l, valor, &pos)) {

				return 0;
			}
			else
			{
				if (clas_lista(l))
				{

					if (pos == NULL)
					{

						l->ultimo->sucessor = novo;
						novo->anterior = l->ultimo;
						l->ultimo = novo;
						return 1;
					}
					else
					{

						if (pos == l->primeiro)
						{

							l->primeiro->anterior = novo;
							novo->sucessor = l->primeiro;
							l->primeiro = novo;
							return 1;
						}
						else
						{

							pos->anterior->sucessor = novo;
							novo->anterior = pos->anterior;
							pos->anterior = novo;
							novo->sucessor = pos;

							return 1;
						}
					}
				}

				else
				{

					l->primeiro->anterior = novo;
					novo->sucessor = l->primeiro;
					l->primeiro = novo;
					return 1;
				}
			}
		}
	}
}


int exclui_um(list* l, int valor)
{
	no* pos;

	busca_lista(l, valor, &pos);

	if (pos == l->primeiro)
	{

		if (pos == l->ultimo)
		{

			l->ultimo = NULL;
		}
		else
		{
			pos->sucessor->anterior = NULL;
		}

		l->primeiro = pos->sucessor;
	}

	else
	{

		if (pos == l->ultimo)
		{
			pos->anterior->sucessor = NULL;
			l->ultimo = pos->anterior;
		}
		else
		{

			pos->anterior->sucessor = pos->sucessor;
			pos->sucessor->anterior = pos->anterior;
		}

	}
	free(pos);
}

void exclui(list* l, int valor)
{
	no* pos;
	if (vazia_lista(l))
	{
		printf("\n-------------Lista esta vazia-------------\n\n");
	}

	else
	{

		if (!busca_lista(l, valor, &pos))
		{

			printf("\n--Nenhum valor correspondente encontrado--\n\n");
		}

		else
		{
			if (l->rep == 0)
			{
				exclui_um(l, valor);
			}
			else
			{
				while (busca_lista(l, valor, &pos))
				{
					exclui_um(l, valor);
				}
			}
		}
	}
}