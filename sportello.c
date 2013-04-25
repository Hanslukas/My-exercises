/*Scrivere un programma che permetta di gestire le informazioni ad uno sportello didattico di informatica.

Deve essere prevista, per ciascuno studente, la possibilità di effettuare una prenotazione al suddetto

sportello.

Ciascuna prenotazione sarà costituita dalle informazioni relative al Nome,Cognome e Classe di

appartenenza dello studente e dalla data di prenotazione.

Dovrà essere possibile, a scelta dell'utente, di:

- Effettuare una prenotazione allo sportello didattico;

- Eliminare una certa prenotazione individuata da nominativo, classe, data;

- Visualizzare tutte le prenotazioni allo sportello didattico;

- Calcolare il numero di prenotazioni di una data precisata in input;
*/

// La Manna Gianluca IV B
// Data Ultima modifica: 16 gen 18.34


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Strutture dati
//***********************************************
struct _data{
  int giorno;
	int mese;
	int anno;
};

typedef struct _data dat;

struct alunno {
	char nome[25];
	char cognome[25];
	char classe[7];
	dat data_pren;
};

typedef struct alunno alu;


//***************************************************

//Prototipi funzioni
//***************************************************
int menu();
alu prenotazione();
alu * elimina_prenotazione(alu *,int *);
void visualizza_prenotazioni(alu *, int );
void visualizza_numero_prenotazioni(alu *, int );
void pulisci();
//****************************************************

//Main
//****************************************************
int main()
{
	int m;
	int counter=0;
	alu *p=NULL, *tmp=NULL;
	
	do
	{
		
		switch(m=menu())
		{
			case 1:
				if(counter==0)//controlla se il contatore è uguale a 0
				{
					p=(alu *)malloc(sizeof(alu));// esegue l'allocazione dinamica
					if(p==NULL)//controlla se p è uguale a NULL
						printf("Memoria insufficiente1\n");
					else
					{
						*p=prenotazione();//assegna al contenuto di p la funzione prenotazione
						counter++;
					}
				}
				
				else
				{
					tmp=(alu *)realloc(p, (counter+1)*sizeof(alu));// esegue la rilocazione dinamica
					if(tmp==NULL)
						printf("Memoria insufficiente2\n");
					else
					{
						p=tmp;
						*(p+counter)=prenotazione();//assegna al contenuto di tmp la funzione prenotazione
						counter++;//incrementa la posizione di 1
					}
				}
				break;
			
			case 2:p=elimina_prenotazione(p, &counter);//elimina una prenotazione ricoprendo la cella eliminata con quella successiva
			       break;
			
			case 3:visualizza_prenotazioni(p, counter);//visualizza tutte le prenotazioni presenti nello sportello didattico
			       break;
			
			case 4:visualizza_numero_prenotazioni(p, counter);//visualizza il numero delle prenotazioni che hanno una determinata data
			       break;
			
			case 5: break;
			default: printf("Nessuna voce appartenente al menu\n");// Messaggio in caso di errore battitura
				 break;
		}
	}while(m!=5);// Esce dal ciclo
	
	fflush(stdin);
	getchar();
	return 0;
}
//*******************************************************************************


//Funzioni
//*******************************************************************************
int menu(){
	
	int x;
	printf("\n*****MENU*********\n");
	printf("[1] - Prenota\n");
	printf("[2] - Elimina prenotazione\n");
	printf("[3] - Visualizza tutte le prenotazioni\n");
	printf("[4] - Visualizza il numero di prenotazioni\n");
	printf("[5] - Esci\n");
	printf("===> ");
	scanf("%d", &x);
	return x;
}

alu prenotazione(){
	
	//caricamento dati
	alu x;
	printf("\nInserisci nome: ");
	scanf("%s", x.nome);
	printf("Inserisci cognome: ");
	scanf("%s", x.cognome);
	printf("Inserisci classe: ");
	scanf("%s", x.classe);
    
	do
	{ //Controlli inserimento data
		printf("Inserisci data (gg/mm/aaaa): ");
		scanf("%d/%d/%d", &x.data_pren.giorno, &x.data_pren.mese, &x.data_pren.anno);
	}while((x.data_pren.giorno>31) || (x.data_pren.giorno<=0) || (x.data_pren.mese>12) || (x.data_pren.mese<=0) || (x.data_pren.anno>2100) || (x.data_pren.anno<1900));
	return x;
}

alu * elimina_prenotazione(alu *p,int *dim){
	
	if(*dim==0)
		printf("\nImpossibile cancellare!\n");
	else // se sono presenti ordini ossia *dim!=0
	{
		alu *app;
		int i=0,j;
		int giorno, mese, anno;
		char nome[25], cognome[25], classe[7];
		printf("Inserisci nome: ");
		scanf("%s", nome);
		printf("Inserisci cognome: ");
		scanf("%s", cognome);
		printf("Inserisci classe: ");
		scanf("%s", classe);
		
		do
		{
			printf("Inserisci data (gg/mm/aaaa): ");
			scanf("%d/%d/%d", &giorno,&mese, &anno);
		}while((giorno>31) || (giorno<=0) || (mese>12) || (mese<=0) || (anno>2100) || (anno<1900));
		
		
		while(strcmp(nome, p->nome)==1 && strcmp(cognome, p->cognome)==1 && strcmp(classe, p->classe)==1 && giorno!=p->data_pren.giorno && mese!=p->data_pren.mese && anno!=p->data_pren.anno && i<*dim) // ricerca codice ordine
			i++;

		if(i==*dim) // se si e' raggiunta la fine dei dati allocati
		{
			printf("\nPrenotazione non trovata!\n");
			return p;
		}
		else  // in questo caso i < *dim quindi i e' l'indice dell'ordine che e' stato trovato
		{
			for(j=i;j<*dim-1;j++) //cancellazione per shift left
				*(p+j)=*(p+j+1);
			
			*dim=*dim-1;
			
			app=(alu *)realloc(p,*dim * sizeof(alu));
			if(app==NULL)
			{
				printf("Memoria insufficiente\n");
				return(p);
			}
			else
				return(app);
		}
	}
}

void visualizza_prenotazioni(alu *p, int cont){
	
	int i;
	for(i=0; i<cont; i++)
	{
		printf("\nPrenotazione %d\n", i);
		printf("Nome: %s\n", (p+i)->nome);
		printf("Cognome: %s\n", (p+i)->cognome);
		printf("Classe: %s\n", (p+i)->classe);
		printf("Data: %d/%d/%d\n", (p+i)->data_pren.giorno, (p+i)->data_pren.mese, (p+i)->data_pren.anno);
	}
	return;
}

void visualizza_numero_prenotazioni(alu *p, int cont){
	
	int giorno, mese, anno, i, j=0;
	
	do
	{
		printf("Inserisci data (gg/mm/aaaa): ");
		scanf("%d/%d/%d", &giorno, &mese, &anno);
	}while((giorno>31) || (giorno<=0) || (mese>12) || (mese<=0) || (anno>2100) || (anno<1900));
    
	for(i=0; i<cont; i++)
	{
		if(giorno==(p+i)->data_pren.giorno && mese==(p+i)->data_pren.mese && anno==(p+i)->data_pren.anno)
			j++;
	}
	printf("Numero prenotazioni in data %d/%d/%d = %d", giorno, mese, anno, j);
	return;
}
