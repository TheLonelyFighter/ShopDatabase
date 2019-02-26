// Arbore tema.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>	
#include<conio.h>
#include<string.h>

typedef struct arbore
{
	char cod[17];
	int pret;
	int stoc;
	int vand;
	int vand_pret;
	struct arbore *right, *left;
}ELEM,*LINK;

LINK nod_nou(char *a)
{
	LINK p;
	p = (LINK)malloc(sizeof(ELEM));
	if (!p) {
		exit(-1);
		printf("Memorie insuficienta");
	}
	else {
		strcpy(p->cod, a);
		p->right = NULL;
		p->left = NULL;
		return p;
	}
}

LINK adauga_ordonat(LINK t, char *a)
{
	if (t == NULL) return nod_nou(a);
	
	if (strcmp(a, t->cod) < 0) t->left = adauga_ordonat(t->left, a);
	else if (strcmp(a, t->cod) > 0) t->right = adauga_ordonat(t->right, a);
	return t;
}

void inordine_stoc(LINK t)
{if (t) 
   {
	inordine_stoc(t->left);
  if (t->stoc)	printf("\nProdus %s: %d bucati in stoc", t->cod,t->stoc);
	inordine_stoc(t->right);
   }
}
void inordine_vandute(LINK t)
{
	if (t)
	{
		inordine_vandute(t->left);
		if (t->vand) printf("\nProdus %s: %d bucati vandute", t->cod, t->vand);
		inordine_vandute(t->right);
} }

LINK minim(LINK t)
{
	LINK p = t;
	while (p->left != NULL)
		p = p->left;
	return p;
}

LINK sterge(LINK t, char *a)
{
	if (t == NULL) return t;

	if (strcmp(a, t->cod) < 0) t->left = sterge(t->left, a);
	else if (strcmp(a, t->cod) > 0) t->right = sterge(t->right,a);
	else 
	{
		if (t->left == NULL)
		{
			LINK p = t->right;
			free(t);
			return p;
		}
		else if (t->right == NULL)
		{
			LINK p = t->left;
			free(t);
			return p;
		}

    LINK p = minim(t->right);
	strcpy(t->cod, p->cod);
	t->right = sterge(t->right, p->cod);
	}
	return t;
}

int main()
{
	char a[17],x, sir[17] = "2", sir2[17] = "3";
    LINK t=NULL;
   
	do
	{
		printf("\nApasati cifra instructiunii dorite:"
			"\n1.Adauga un element in arbore"
			"\n2.Sterge un element"
			"\n3.Afiseaza produse aflate in stoc"
			"\n4.Afiseaza produse vandute"
			"\n5.Terminare program\n");
		x = _getch();
		switch (x)
		{
		case '1': { system("cls");
			printf("\nIntroduceti codul produsului: ");
			scanf("%s", a);
			t=adauga_ordonat(t, a);
			break;
		         }
				  
		case '2': { system("cls");
			printf("\nIntroduceti codul produsului care va fi sters: ");
			scanf("%s", a);
			t=sterge(t, a);
			break;
		          }   

		case '3': system("cls");
			inordine_stoc(t);
			printf("\n");
			break;

		case '4': system("cls");
			inordine_vandute(t);
			printf("\n");
			break;

		case '5': printf("\n\nProgram terminat :\)");
			break;

		default: printf("\n\nAti apasat o tasta gresita.\n");
		}
	} while (x != '5');

	_getch();
    return 0;
}

