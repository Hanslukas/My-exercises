#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int numero;
	struct nodo *next;
};

struct nodo * inserisci_in_testa(struct nodo *, int);
void stampa(struct nodo*);

int main(void)
{
	int num;
	struct nodo *p=NULL;

	printf("Inserisci numero (0 per terminare): ");
	scanf("%d", &num);
	

	while(num!=0)
	{	
		p=inserisci_in_testa(p,num);
		printf("Inserisci numero: ");
		scanf("%d", &num);
	}

	stampa(p);
	fflush(stdin);
	getchar();
	return 0;
}

struct nodo *inserisci_in_testa(struct nodo *p, int val)
{
	struct nodo *aus=NULL
	aus = (struct nodo*) malloc (sizeof(struct nodo));
	aus->numero = val;
	aus->next = p;
	p = aus;

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
