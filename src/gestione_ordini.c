/*
 * gestione_ordini.c
 *
 *  Created on: 23 giu 2022
 *      Author: ranie
 */

#include "gestione_ordini.h"

void effettua_ordine(char* username){

	srand(time(NULL));
	int scelta;
	int esito;
	int codice[LUNG_CODICE];
	int n_articolo=0;

	gadget_t xgad;
	ordine_t ordine;
	ordine.stato=1;

	printf("\n| CREAZIONE ORDINE |");

	do{
		printf("\n|Inserire codice gadget: ");
		scanf("%s",ordine.articoli_ordine[n_articolo].cod_gadget);
		esito=restituisci_gadget(ordine.articoli_ordine[n_articolo].cod_gadget,&xgad,1);
		if(esito==1)
		{
			visualizza_gadget(xgad);
			printf("\n|Inserire quantita gadget: ");
			scanf("%d",&ordine.articoli_ordine[n_articolo].quantita);
			if(xgad.quantita>=ordine.articoli_ordine[n_articolo].quantita && ordine.stato==1)
			{
				ordine.stato=1;

			}
			else
			{
				ordine.stato=0;
			}
			ordine.articoli_ordine[n_articolo].prezzo_CAD=xgad.prezzo;
			ordine.totale+=ordine.articoli_ordine[n_articolo].prezzo_CAD*ordine.articoli_ordine[n_articolo].quantita;

			n_articolo++;
		}
		else
		{
			printf("\n|Articolo non trovato!");
		}
		printf("\n|Continuare: 1, Chiudere ordine: 2, Annullare:3 ");
		scanf("%d",&scelta);

	}
	while(scelta==1);

	if(scelta==2 && n_articolo>0)
	{
		ordine.n_gadget=n_articolo;
		strcpy(ordine.username_cliente,username);

		itoa(rand(),codice,10);
		strcpy(ordine.cod_ordine,codice);

		esito=inserisci_ordine(ordine);
		if(esito==1)
		{
			printf("\n| Oridne registrato correttamente! |");
			sleep(1);
		}
		else
		{
			printf("\n| Errore nella registrazione dell'ordine |");
			sleep(1);
		}
		if (ordine.stato==1)
		{

		}

	}else
	{
		printf("\n|Ordine Annullato.");
	}

}

void emetti_ordine(ordine_t xordine)
{
	int esito;
	int nuova_giacenza=0;
	gadget_t xgad;

	for(int i=0;i<xordine.n_gadget;i++){
		esito=restituisci_gadget(xordine.articoli_ordine[i].cod_gadget,&xgad,1);
		nuova_giacenza=xgad.quantita-xordine.articoli_ordine[i].quantita;
		if(nuova_giacenza<0){
			nuova_giacenza=0;
		}
		modifica_quant_gadget(xordine.articoli_ordine[i].cod_gadget,nuova_giacenza);
		//MODIFICA VENDUTI
	}

	return esitoFinale;


}





