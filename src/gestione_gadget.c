/*
 * gestione_gadget.c
 *
 *  Created on: 22 giu 2022
 *      Author: ranie
 */

#include "gestione_gadget.h"

int registrazione_gadget()
{
	setbuf(stdout, NULL);
	srand(time(NULL));
	char codice[6],tipo[CARATTERI];
	int esito=0;
	gadget_t xgad;

	printf("\n|Inserire nome gadget: ");
	scanf("%s",xgad.nome_gadget);
	printf("\n|Inserire colore gadget: ");
	scanf("%s",xgad.colore);
	printf("\n|Inserire descrizione: ");
	scanf("%s",xgad.desc);
	printf("\n|Inserire prezzo cad.: ");
	scanf("%f",&xgad.prezzo);
	printf("\n|Inserire quantita' disponibile: ");
	scanf("%d",&xgad.quantita);
	xgad.venduti=0;
	itoa(rand(),codice,10);
	strcpy(xgad.cod_gadget,codice);


	if(inserisci_gadget(xgad)==1)
	{
		printf("|Gadget Inserito Correttamente|"); //////////////////
		esito=1;
		sleep(1);
	}

	return esito;

}











void modifica_gadget(char gadget[CARATTERI],char mod[CARATTERI],int scelta)
{
	gadget_t xgadget;
	int esito=0;
	int esito2=0;
	switch(scelta){
	case 1:
			esito=ricerca_gadget(gadget, &xgadget,0);
			strcpy(xgadget.nome_gadget,mod);
			esito2=cancella_gadget(gadget);
			esito2=inserisci_gadget(xgadget);
			if(esito2==1)
			{
				printf("\n|gadget Modificato!|");
				visualizza_gadget(xgadget);
				sleep(1);
			}
			else
			{
				printf("\n|Impossibile Trovare Gadget!|");
				sleep(1);
			}
			break;

	}
}

/*void modifica_prezzo(char gadget[CARATTERI],char mod[CARATTERI],int scelta)
{
	cliente_t xcliente;
	int esito=0;
	int esito2=0;
	switch(scelta){

	case 1:
			esito=restituisci_cliente(username_corrente, &xcliente);
			strcpy(xcliente.piva,mod);
			esito2=cancella_cliente(username_corrente);
			esito2=inserisci_cliente(xcliente);
			if(esito2==1)
			{
				printf("\n|Utente Modificato!|");
				visualizza_cliente(xcliente);
				sleep(1);
			}
			else
			{
				printf("\n|Impossibile Trovare Username!|");
				sleep(1);
			}
			break;

	}
}
*/

