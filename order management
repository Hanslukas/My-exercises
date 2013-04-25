#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 35
struct ordine{
               int cod_ord;
               char cod_prod[N];
               int num_prod;
               char nome[N];
               char cognome[N];
               char telefono[N];
               char residenza[N];
               };
/////////////////////////////////////////////////////
// PROTOTIPI
struct ordine carica_ordine(int);
struct ordine * inserisci(struct ordine *, int *, int *);
struct ordine * elimina(struct ordine *, int *);
int ricerca_codice_num (struct ordine *, int );
void visualizza (struct ordine *, int );
struct ordine modifica(struct ordine*, int);
void visualizza_tabella(struct ordine *, int);
int menu();
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// MAIN
main()
{
// scelta serve per il menu
// numero_ordini indica il numero di ordini presenti (decresce se si elimina un ordine)
// progressivo_ordini indica un numero progressivo da assegnare agli ordini
int  scelta, numero_ordini=0, progressivo_ordini=0;

struct ordine *p_ord=NULL;

do{
      scelta=menu();

      switch(scelta){
                   case 1: p_ord=inserisci(p_ord, &numero_ordini, &progressivo_ordini);
                           break;
                   case 2: p_ord=elimina(p_ord,&numero_ordini);
                           break;
                   case 3: modifica(p_ord,numero_ordini );
                           break;
                   case 4: visualizza(p_ord,numero_ordini );
                           break;
                   case 5: visualizza_tabella(p_ord,numero_ordini );
                           break;
                   case 6: printf ("FINE");
                           break;
                   }
}while (scelta!=6);


printf("\n");
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//MENU
int menu(void)
{
    int opz;
    printf("\n\n\n**************** MENU ****************\n");
    printf("\n1. Aggiungere un ordine\n");
    printf("2. Eliminare un ordine\n");
    printf("3. Modificare la quantita' di un ordine\n");
    printf("4. Visualizzare la quantita' totale di pezzi ordinati di un prodotto\n");
    printf("5. Visualizzare una tabella riassuntiva\n");
    printf("6. Per uscire\n");
    do {
       printf("\nInserisci la scelta: ");
       scanf("%d", &opz);
    }while ((opz<1)||(opz>6));
    return(opz);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// CARICA_ORDINE
struct ordine carica_ordine(int progr_ordini)
{
  struct ordine ord;

  printf("\nNome: ");
  scanf("%s",ord.nome);
  printf("\nCognome: ");
  scanf("%s",ord.cognome);
  printf("\nTelefono: ");
  scanf("%s",ord.telefono);
  printf("\nResidenza: ");
  scanf("%s",ord.residenza);
  printf("\nCodice prodotto: ");
  scanf("%s",ord.cod_prod);
  printf("\nQuantita': ");
  scanf("%d",& ord.num_prod);

  ord.cod_ord = progr_ordini + 1;
  printf("\n===>Il codice dell'ordine e': %d\n",ord.cod_ord);

  return(ord);
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//INSERISCI
struct ordine * inserisci(struct ordine *p,int *dim, int *progr_ordini)
{
    if(*dim==0)
    {
       p=(struct ordine*)malloc(sizeof(struct ordine));
       if(p==NULL)
          printf("Impossibile inserire l'ordine (Errore di allocazione)");
          else
          {
             *p=carica_ordine(*progr_ordini);
             *dim = *dim + 1;
             *progr_ordini = *progr_ordini + 1;
          }
     }
     else
     {
           struct ordine *temp;
           temp=(struct ordine *)realloc(p,(*dim+1)*sizeof(struct ordine));
           if(temp==NULL)
              printf("Impossibile aggiungere ordini (Errore di allocazione)");
           else
           {
               *(temp+ *dim)=carica_ordine(*progr_ordini);
               p=temp;
               *dim = *dim + 1;
               *progr_ordini = *progr_ordini + 1;
           }
     }
     return p;
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// ELIMINA
struct ordine * elimina(struct ordine *p,int *dim)
 {
   if(*dim==0)
      printf("\nImpossibile cancellare. Non sono presenti ordini.");
   else // se sono presenti ordini ossia *dim!=0
      {
         struct ordine *app;
         int codice,i=0,j;

         printf("\nInserisci il codice dell'ordine da eliminare: ");
         scanf("%d",&codice);

         while(codice!=(p+i)->cod_ord && i<*dim) // ricerca codice ordine
            i++;

         if(i==*dim) // se si e' raggiunta la fine dei dati allocati
           {
              printf("\nCodice non trovato");
              return p;
           }
         else  // in questo caso i < *dim quindi i e' l'indice dell'ordine che e' stato trovato
         {
               for(j=i;j<*dim-1;j++) //cancellazione per shift left
                  *(p+j)=*(p+j+1);

               *dim=*dim-1;

               app=(struct ordine *)realloc(p,*dim * sizeof(struct ordine));
               if(app==NULL)
               {
                  printf("non è possibile allocare");
                  return(p);
               }
               else
                  return(app);
         }
      }
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// ORDINE_MODIFICA
struct ordine modifica(struct ordine*p,int dim)
{
   if(dim==0)
     printf("Non sono presenti ordini.");
   else
     {
        struct ordine *app;
        int codice,i=0,j;

        printf("insrisci il codice ordine per modificare la quantita'");
        scanf("%d",&codice);

        while(codice!=(p+i)->cod_ord && i<dim)
             i++;

        if(i==dim)
           printf("codice non trovato");
        else
          {
               int q;

               printf("\nInserisci la nuova quantita': ");
               scanf("%d",&q);
               (p+i)->num_prod=q;
          }
     }
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//VISUALIZZA
void visualizza(struct ordine*p,int dim)
{

   if(dim==0)
     printf("\nNon sono presenti ordini.");
   else
     {
       char codice[N];
       int i,q_tot=0;

       printf("\nInserisci il codice prodotto da visualizzare: ");
       scanf("%s",codice);

       for(i=0;i<dim;i++)
         {
           if(strcmp(codice,(p+i)->cod_prod)==0)
           q_tot = q_tot+ ((p+i)->num_prod);
         }

       printf("\nLa quantita' totale di prodotto %s e': %d\n",codice ,q_tot);
     }
}
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// VISUALIZZA_TABELLA
void visualizza_tabella(struct ordine *p,int dim)
{
   if(dim==0)
     printf("\nNon sono presenti ordini.");
   else
     {

        struct prod
        {
          char cod_prod[N];
          int quant;
        } *p_prod=NULL ;

         int contaprod=0,i,j;

        if(dim!=0)
        {
          p_prod=(struct prod *)malloc(sizeof(struct prod));
          strcpy(p_prod->cod_prod,p->cod_prod);
          p_prod->quant=p->num_prod;
          contaprod++;
        }

        for(i=1;i<dim;i++)
          {
             j=0;
             while(j<contaprod && strcmp ((p+i)->cod_prod,(p_prod+j)->cod_prod)!=0)
               j++;

             if(j==contaprod)
             {
                 struct prod *temp;

                 temp=(struct prod*)realloc(p_prod,(contaprod+1)*sizeof(struct prod));
                 if(temp==NULL)
                    printf("non è possibile allocare");
                 else
                 {
                    p_prod=temp;
                    strcpy((p_prod+contaprod)->cod_prod,(p+i)->cod_prod);
                    (p_prod+contaprod)->quant=(p+i)->num_prod;
                    contaprod++;
                 }
             }
             else
                (p_prod+j)->quant+=(p+i)->num_prod;

           }

           printf("\n**************************************");
           printf("\n* codice prodotto * quantita' totale *");

           for(j=0;j<contaprod;j++)
             printf("\n* %15s * %16d *",(p_prod+j)->cod_prod,(p_prod+j)->quant);

           printf("\n**************************************");
     }
}
/////////////////////////////////////////////////////
