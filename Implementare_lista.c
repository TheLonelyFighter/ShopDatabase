// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct produs
{
	char cod[17]; 
	int pret;    
	int stoc;
	int vand;
	int vand_pret;
		struct produs *urmator;
}start, sentinel, *nod;  //sentinele vor fi utilizate pt 
                        //adaugarea in ordine crescatoare in functie de codul
                       //produsului


void sterge()
{
	char x[17];
	struct produs *precedent;
	printf("\nIntroduceti codul produsului pe care vreti sa il stergeti: ");
		scanf("%s", x);
		nod = &start;
		precedent = &start;
		while (nod->urmator) //folosesc "nod->urmator" pentru a nu lua
		{                   //in considerare santinela de la sfarsitul listei
			nod = nod->urmator;
			if ((nod!=NULL) && (strcmp(nod->cod,x)==0)) 
			{
				precedent->urmator = nod->urmator;
				free(nod);
				break;    //daca s-a sters nodul dorit, bucla while poate 
			}            // fi terminata
			precedent = precedent->urmator;
		}

}

void afiseaza_stoc()  //afiseaza produsele aflate in stoc si numarul
{                    //de produse disponibile
	nod = &start;
	printf("\nProduse aflate in stoc:\n");
	while (nod)
	{
		if (nod->stoc) printf("\nProdus %s: %d bucati in stoc", nod->cod, nod->stoc);
		nod = nod->urmator;
	}
}

void afiseaza_vandute()  //afiseaza cate produse s-au vandut din fiecare tip
{
	nod = &start;
	printf("\nNumarul produselor vandute:\n");
	while (nod) 
	{
		if (nod->vand) printf("\nProdus %s: %d produse vandute", nod->cod, nod->vand);
		nod = nod->urmator;
	}
}

void adauga_ordonat()
{ 
	struct produs  *x, *y, *z;
	x = &start;
	y = x->urmator;
	
	printf("\nIntroduceti codul produsului: ");
	scanf("%s", sentinel.cod);
	while ((y!=NULL) && (strcmp(y->cod,sentinel.cod)<0))
	{                         //parcurg lista pana cand se respecta relatia
		x = y;               //de ordine x->cod < codul nou < y>cod
		y = x->urmator;
	}
	z = (struct produs*)malloc(sizeof(struct produs));
	strcpy(z->cod, sentinel.cod);
	z->urmator = y;
	x->urmator = z;
	printf("Introduceti pretul produsului: ");
	scanf("%d", &z->pret);

	printf("Introduceti numarul produselor aflate in stoc: ");
	scanf("%d", &z->stoc);
	
	printf("Introduceti numarul produselor vandute: ");
	scanf("%d", &z->vand);

	printf("Introduceti valoarea produselor vandute: ");
	scanf("%d", &z->vand_pret);
}

int main()
{
	char x;
	int i;
	nod = &start;
	start.urmator = &sentinel;
	sentinel.urmator = NULL;
	
    do
	{
		printf("\nApasati cifra instructiunii dorite:"  
			"\n1.Adauga un element in lista"
			"\n2.Sterge un element"
			"\n3.Afiseaza produse aflate in stoc"
			"\n4.Afiseaza produse vandute"
		    "\n5.Terminare program");  //afiseaza meniul
		x = _getch();
		switch (x)
		{
		case '1': system("cls");  //sterge afisarile anterioare
			adauga_ordonat();    //din consola
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

		case '5': system("cls");
			printf("\n\n\nProgram terminat :\)");
			break;

		default: printf("\n\nAti apasat o tasta gresita.\n"); 
		}
	} while (x != '5');
	
	_getch();
    return 0;
}

