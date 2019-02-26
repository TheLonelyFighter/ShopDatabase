// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct produs
{
	char cod[17];
	int pret;
	int stoc;
	int vand;
	int vand_pret;
	struct produs *left, *right;

}PRODUS;
PRODUS start, sentinel, *nod ; //start si sentinel sunt
                              //folosite pt. inserarea in ordine
                             //crescatoare a produselor
void sterge()
{
	char x[17];
	printf("\nIntroduceti codul produsului pe care doriti sa il stergeti: ");
	scanf("%s", x);
	nod = &start;
	while (nod->right)
	{
		nod = nod->right;
		if( strcmp(nod->cod,x) == 0 )
		{nod->left->right = nod->right;
		nod->right->left = nod->left;
		free(nod);
		break;   //dupa ce nodul a fost sters, bucla
		}       //while poate fi terminata
	} 
}

void adauga_ordonat()
{ 
	PRODUS *x, *y, *z;
	x = &start;
	y = x->right;
	printf("\nIntroduceti codul noului produs: ");
	scanf("%s", sentinel.cod);
	while (y!=NULL && strcmp(y->cod,sentinel.cod)<0)
	{
		x = y;
		y = x->right;
	}
	z = (PRODUS*)malloc(sizeof(PRODUS));
	strcpy(z->cod, sentinel.cod);
	x->right = z;
	z->left = x;
	z->right = y;
	y->left =z;
	printf("Introduceti pretul produsului: ");
	scanf("%d", &z->pret);
	
	printf("Introduceti numarul produselor aflate in stoc: ");
	scanf("%d", &z->stoc);
	
	printf("Introduceti numarul produselor vandute: ");
	scanf("%d", &z->vand);
	
	printf("Introduceti valoarea produselor vandute: ");
	scanf("%d", &z->vand_pret);
	
}

void afiseaza_stoc()
{
	printf("\nProduse in stoc:\n");
	nod = &start;
	while (nod)
	{
		if (nod->stoc) printf("\nProdus %s: %d bucati",nod->cod,nod->stoc);
			nod = nod->right;
	}
}

void afiseaza_vandute()
{
	printf("\nProduse vandute:\n");
	nod = &start;
	while(nod)
	{
		if (nod->vand) printf("\nProdus %s: %d bucati", nod->cod, nod->vand);
		nod = nod->right;
	}
}

int main()
{
	char x;
	int i;
	nod = &start;
	start.left = NULL;
	start.right = &sentinel;
	sentinel.right = NULL;
	
	do
	{
			printf("\nApasati cifra instructiunii dorite:"
			"\n1.Adauga un element in lista"
			"\n2.Sterge un element"
			"\n3.Afiseaza produse aflate in stoc"
			"\n4.Afiseaza produse vandute"
			"\n5.Terminare program");
		x = _getch();
		switch (x)
		{
		case '1': system("cls");
			adauga_ordonat();
			break;

		case '2': system("cls");
			sterge();
			break;

		case '3': system("cls");
			afiseaza_stoc();
			printf("\n");
			break;

		case '4': system("cls");
			afiseaza_vandute();
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

