#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int numero;
	struct nodo *next;
};

void inserisci_ricorsivo_ordinato(struct nodo **, int);
void stampa_ricorsivo(struct nodo*);

int main(void)
{
  int num;
	struct nodo *p=NULL, *copia=NULL;

	printf("Inserisci numero (0 per terminare): ");
	scanf("%d", &num);
	

	while(num!=0)
	{	
		inserisci_ricorsivo_ordinato(&p,num);
		printf("Inserisci numero: ");
		scanf("%d", &num);
	}

	stampa_ricorsivo(p);
	printf("\n");

fflush(stdin);
  getchar();
	return 0;
}

void inserisci_ricorsivo_ordinato(struct nodo **p, int val) {
  struct nodo *s=NULL;

			/* caso di lista vuota */
  if(*p==NULL) {
    *p=  malloc(sizeof(struct nodo));
    (*p)->numero = val;
    (*p)->next=NULL;
    return;
  }

			/* l'elemento va messo in prima posizione */
  if(((*p)->numero) > val) {
    s= malloc(sizeof(struct nodo));
    s->numero=val;
    s->next=*p;
    *p=s;
    return;
  }

			/* l'elemento va aggiunto al resto della lista */
  inserisci_ricorsivo_ordinato(&(*p)->next, val);
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
