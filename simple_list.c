#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int numero;
	struct nodo *next;
};

struct nodo * inserisci(int);
void stampa(struct nodo*);

int main(void)
{
	int dim;
	struct nodo *p=NULL;

	printf("Quanti numeri vuoi inserire nella lista: ");
	scanf("%d", &dim);

	p=inserisci(dim);
	stampa(p);
	fflush(stdin);
	getchar();
	return 0;
}

struct nodo *inserisci(int i)
{

	struct nodo *aus, *last, *p;
	int counter=0;

	//Inserimento elementi nella lista fino alla fine
	while(counter < i)
	{
		printf("Inserisci elemento: ");
		aus = (struct nodo *) malloc (sizeof(struct nodo));
		scanf("%d", &aus->numero);
		aus->next=NULL;
		counter++;
		
		if(p==NULL)
		{
			p=aus;
			last = aus;
		}
		else
		{
			last->next = aus;
			last = aus;
		}
	}
	return p;
}

void stampa(struct nodo *p)
{
	if(p==NULL)
		printf("Lista vuota!!!\n");
	else
	{
		printf("LISTA\n");
		while(p!=NULL)
		{
			printf("%d", p->numero);
			printf("-->");
			p=p->next;
		}
		printf("NULL\n");
	}
	return;
}
