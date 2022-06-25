/*
 * gestione_gadget.c
 *
 *  Created on: 22 giu 2022
 *      Author: ranie
 */

#include "gestione_gadget.h"

int registrazione_gadget()
{
	srand(time(NULL));
	char codice[LUNG_CODICE],tipo[CARATTERI];
	int esito=0;
	gadget_t xgad;
    fflush(stdin);
	printf("\n|Inserire nome gadget: ");
	fgets(xgad.nome_gadget, CARATTERI, stdin);
	printf("\n|Inserire colore gadget: ");
	scanf("%s",xgad.colore);
	fflush(stdin);
	printf("\n|Inserire descrizione: ");
	fgets(xgad.desc, CARATTERI, stdin);
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


void effettua_ricerca()
{
	setbuf(stdout, NULL);
	int scelta;
	char ricerca[CARATTERI];
	visualizza_menu_ricerca();
	printf("Inserire scelta: ");
	scanf("%d",&scelta);
	switch(scelta)
	{
	case 1:
		printf("Inserire nome gadget: ");
		scanf("%s",ricerca);
		ricerca_gadget(ricerca,0);
		break;

	case 2:
		printf("Inserire codice gadget: ");
		scanf("%s",ricerca);
		ricerca_gadget(ricerca,1);
		break;

	case 3:
		printf("Inserire colore gadget: ");
		scanf("%s",ricerca);
		ricerca_gadget(ricerca,2);
		break;

	default:
		break;
	}
}








void modifica_gadget_utente(int scelta)
{
	char gadget[CARATTERI];
	char mod[CARATTERI];
	gadget_t xgadget;
	int esito=0;
	int esito2=0;
	printf("\n|Inserire Nome Gadget: ");
	scanf("%s",gadget);
	switch(scelta){
	case 1:
		printf("\n|Inserire Nome Gadget: ");
		scanf("%s",mod);
		esito=restituisci_gadget(gadget, &xgadget,0);
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

	case 2:
		printf("\n|Inserire Descrizione Gadget: ");
		scanf("%s",mod);
		esito=restituisci_gadget(gadget, &xgadget,0);
		strcpy(xgadget.desc,mod);
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
	case 3:
		printf("\n|Inserire Colore Gadget: ");
		scanf("%s",mod);
		esito=restituisci_gadget(gadget, &xgadget,0);
		strcpy(xgadget.colore,mod);
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

void modifica_prezzo_gadget()
{
	char gadget[CARATTERI];
	float prezzo;
	gadget_t xgadget;
	int esito=0;
	int esito2=0;
	printf("\n|Inserire Nome Gadget: ");
	scanf("%s",gadget);
	printf("\n|Inserire Prezzo Gadget: ");
	scanf("%f",&prezzo);
	esito=restituisci_gadget(gadget, &xgadget,0);
	xgadget.prezzo=prezzo;
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

}

//0 quantità, 1 prezzo, 2 venduti
int modifica_gadget(gadget_t xgadget,int valore, int scelta)
{
	gadget_t gadget;
	int esito=1;
	int esito2=0;

	gadget=xgadget;
	//esito=restituisci_gadget(gadget, &xgadget,0);
	printf("prova gadget: %s",gadget.cod_gadget);
	if(esito==1){
		switch(scelta){

		case 0:
			gadget.quantita=valore;
			printf("Nuova quant: %d",gadget.quantita);
			break;
		case 1:
			gadget.prezzo=valore;
			break;
		case 2:
			gadget.venduti=valore;
			break;

		}
		esito2=cancella_gadget(xgadget.cod_gadget);
		esito2=inserisci_gadget(gadget);

		if(esito2==0)
		{
			esito=0;
		}
	}
	return esito;


}


