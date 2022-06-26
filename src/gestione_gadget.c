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
	char codice[LUNG_CODICE];
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
	case 4:
		visualizza_piu_venduti();
		break;
	default:
		break;
	}
}




void modifica_gadget_utente()
{
	int scelta;
	int esito;
	char gadget[CARATTERI];
	char stringa_modifica[CARATTERI];
	int nuova_giacenza;
	float prezzo;


	gadget_t xgad;
	visualizza_menu_modifica_gadget();
	printf("\n Inserire scelta: ");
	scanf("%d",&scelta);
	printf("\n|Inserire Codice Gadget: ");
	scanf("%s",gadget);

	esito=restituisci_gadget(gadget,&xgad,1);

	if(esito==1)
	{
		switch(scelta){
		case 1:
			//NOME
			printf("\n|Inserire Nome Gadget: ");
			fflush(stdin);
			fgets(stringa_modifica, CARATTERI, stdin);
			strcpy(xgad.nome_gadget,stringa_modifica);
			esito=cancella_gadget(xgad.cod_gadget);
			if(esito==1)
			{
				esito=inserisci_gadget(xgad);
			}
			break;
		case 2:
			//DESCRIZIONE
			printf("\n|Inserire Descrizione Gadget: ");
			fflush(stdin);
			fgets(stringa_modifica,CARATTERI,stdin);
			strcpy(xgad.desc,stringa_modifica);
			esito=cancella_gadget(xgad.cod_gadget);
			if(esito==1)
			{
				esito=inserisci_gadget(xgad);
			}

			break;
		case 3:
			//COLORE
			printf("\n|Inserire Descrizione Gadget: ");
			fflush(stdin);
			fgets(stringa_modifica,CARATTERI,stdin);
			strcpy(xgad.colore,stringa_modifica);
			esito=cancella_gadget(xgad.cod_gadget);
			if(esito==1)
			{
				esito=inserisci_gadget(xgad);
			}

			break;
		case 4:
			//PREZZO
			printf("\n|Inserire Prezzo Gadget: ");
			scanf("%f",&prezzo);
			esito=modifica_gadget(xgad,prezzo,1);
			break;

		case 5:
			//GAICENZA
			printf("\n|Inserire Giacenza Gadget: ");
			scanf("%d",&nuova_giacenza);
			esito=modifica_gadget(xgad,nuova_giacenza,0);
			break;
		default:

			break;

		}

		if(esito==1)
		{
			printf("Modifica avvenuta correttamente! \n");
		}


	}
	else
	{
		printf("Gadget non trovato! \n");
	}


}

/*

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

	case 4:
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
*/
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
int modifica_gadget(gadget_t xgadget,float valore, int scelta)
{
	gadget_t gadget;
	int esito=1;
	int esito2=0;


	gadget=xgadget;
	//esito=restituisci_gadget(gadget, &xgadget,0);
	if(esito==1){
		switch(scelta){

		case 0:
			gadget.quantita=valore;
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


