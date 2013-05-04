#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int numero;
	struct nodo *next;
};

struct nodo * inserisci_in_testa_ricorsivo(struct nodo *, int);
struct nodo * inserisci_in_coda_ricorsivo(int, int);
void stampa_ricorsivo(struct nodo*);

int main(void)
{
  int num;
	struct nodo *p=NULL, *copia=NULL;

	printf("Inserisci numero (0 per terminare): ");
	scanf("%d", &num);
	

	while(num!=0)
	{	
		p=inserisci_in_testa_ricorsivo(p,num);
		printf("Inserisci numero: ");
		scanf("%d", &num);
	}

	//copia = copia_L_pari(p);

	stampa_ricorsivo(p);
	printf("\n");

fflush(stdin);
  getchar();
	return 0;
}



void stampa_ricorsivo(struct nodo *p)
{
  if(p==NULL)
	{
		printf("NULL\n");
		return;
	}
	printf("%d->", p->numero);
	stampa_ricorsivo(p->next);
}
