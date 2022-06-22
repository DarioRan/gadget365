/*
 * gestione_gadget.c
 *
 *  Created on: 22 giu 2022
 *      Author: ranie
 */

#include <stdlib.h>
#include <stdio.h>
#include "strutture.h"

int registrazione_gadget()
{
	srand(time(NULL));
	char codice[6],tipo[CARATTERI];
	int esito=0;
	gadget_t xgad;

	printf("\n|Inserire nome gadget: ");
	scanf("%s",xgad.nome_gadget);
	printf("\n|Inserire colore gadget: ");
	scanf("%s",xgad.colore);
	printf("\n|Inserire descrizione: ");
	scanf("%s",&xgad.desc);
	printf("\n|Inserire prezzo cad.: ");
	scanf("%f",&xgad.prezzo);
	printf("\n|Inserire quantita' disponibile: ");
	scanf("%f",&xgad.quantita);
	xgad.venduti=0;
	itoa(rand(),codice,10);
	strcpy(xgad.cod_gadget,codice);


	if(inserisci_gadget(xgad)==1)
	{
		printf("|gadget Inserito Correttamente|"); //////////////////
		esito=1;
		sleep(1);
	}

	return esito;

}
