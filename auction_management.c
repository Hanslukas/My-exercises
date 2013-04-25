
/************************************************************************************************************************************************
*  																	*
* Visualizzare il numero di oggetti dell'asta													*
* Inserire un nuovo prodotto nel db con numero di serie (10 caratteri), breve descrizione di 15 caratteri e il valore in euro per la base 	*
* d'asta.																	*
*																		*
* Ricercare un prodotto per numero di serie con visualizzazione delle restanti informazioni se l'oggetto è presente nel db			*
* o altrimenti un msg di errore.														*
************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char num_serie[11]; //Numero di serie del prodotto
	char desc[16];	   //Descrizione del prodotto
	float base_asta;  //Base asta del prodotto
}asta;  //Tipo di dato asta

/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// PROTOTIPI
asta carica_ordine();
asta * inserisci(asta *, int *);
void ricerca (asta *, int );
void visualizza_tabella(asta *, int );
int menu();
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// MAIN
int main()
{
	char serie[11];
	int  scelta; //Serve per il menu
	int i=0; //dimensione array di strutture
	asta *db=NULL; //array di strutture di tipo asta inizializzato a NULL
	
	do
	{
		scelta=menu();
		
		switch(scelta)
		{
			case 1: db=inserisci(db, &i);
				break;
			case 2: visualizza_tabella(db, i);
                                break;
                        case 3: ricerca(db, i); 
                                break;
                        case 4: printf ("FINE");
			        break;
		}
	
	}while (scelta!=4);
	
	putchar('\n');
	
	fflush(stdin); //Svuota il buffer
	getchar();
	
	return 0; //Ritorna 0 al SO
}


/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//MENU
int menu(void)
{
    int opz;

    printf("\n\n\n**************** MENU ****************\n");
    printf("\n1. Aggiungere nuovo prodotto\n");
    printf("2. Visualizza numero prodotti\n");
    printf("3. Ricerca prodotto\n");
    printf("4. Per uscire\n");
    
    do
    {
	    printf("\nInserisci la scelta: ");
	    scanf("%d", &opz);
    
    }while ((opz<1)||(opz>4));
    
    return(opz);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// CARICA_PRODOTTO
asta carica_prodotto()
{
	asta prod;

	printf("\nInserisci  numero serie: ");
	scanf("%s", prod.num_serie);
	printf("\nInserisci descrizione: ");
	scanf("%s", prod.desc);
	printf("\nInserisci base asta: ");
	scanf("%f", &prod.base_asta);

	return prod;
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//INSERISCI
asta * inserisci(asta *p,int *dim)
{
	if(*dim==0)
	{
		p=(asta*)malloc(sizeof(asta)); //Allocazione dinamica della prima cella dell'array tramite malloc
		if(p==NULL) //Controllo se p punta a NULL
			printf("Impossibile inserire il prodotto (Errore di allocazione)");
		else
		{
			*p=carica_prodotto(); //Chiamo la funzione carica_prodotto su p
			*dim = *dim + 1; //incremento la dimensione di 1
		}
	}
	else //Se dim è diverso da 0 eseguo questo blocco di codice
	{
		asta *temp;
		temp=(asta *)realloc(p,(*dim+1)*sizeof(asta)); //Allocazione dinamica delle celle successive tramite realloc. Parto da p
		if(temp==NULL)//Controllo se temp punta a NULL
			printf("Impossibile aggiungere prodotti (Errore di allocazione)");
		else
		{
			*(temp + *dim)=carica_prodotto();//Chiamo la funzione carica_prodotto sul contenuto di temp più la dimensione
			p=temp;
			*dim = *dim + 1; //Incremento la dimensione
		}
	}
	
	return p;
}
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
//RICERCA
void ricerca(asta *p,int dim)
 {
	 if(dim==0)
		 printf("\nNon sono presenti prodotti.");
	 else
	 {
		 char codice[11];
		 int i, flag=1; 
		 
		 printf("\nInserisci il numero di serie: ");
		 scanf("%s",codice);
		 
		 for(i=0;i<dim;i++)
		 {
			 if(strcmp(codice,(p+i)->num_serie)==0)//Confronto la stringa acquisita con quella  della struttura, nel campo num_serie
			 {
				 flag=0; //flag a 0. Se il flag rimane 1 ciò significa che nessun prodotto è stato trovato.
				 printf("\nNumero serie: %s\n", (p+i)->num_serie);
				 printf("Descrizione: %s\n", (p+i)->desc);
				 printf("Base asta: %.2f ", (p+i)->base_asta);
			 }
		 }
		 
		 if(flag==1)//Se il flag è 1, nessun prodotto è stato trovato
			 printf("Nessun prodotto trovato\n");
		 
	 }

	 return;
}

/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// VISUALIZZA_TABELLA

void visualizza_tabella(asta *p, int dim)
{
	if(dim==0) //Se la dimensione dell'array è 0 non sono presenti prodotti nella struttura
		printf("\nNon sono presenti prodotti.");
	else
	{
		int j;
		
		printf("\n**********************************************");
		printf("\n* Numero serie *   Descrizione   * Base asta *");
		
		for(j=0; j<dim; j++) //Scorro l'array di strutture stampando campo per campo tutta la struttura
			printf("\n* %12s * %15s * %.3f *",(p+j)->num_serie,(p+j)->desc, (p+j)->base_asta);
		
		printf("\n**********************************************");
	}
	
	return;
}
//FINE
