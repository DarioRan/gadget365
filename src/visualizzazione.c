/*
 * visualizzazione.c
 *
 *  Created on: 10 giu 2022
 *      Author: ranie
 */

#include "visualizzazione.h"

void inizializza_menu()
{
	printf("\n*---------------------------------------*\n");
	printf("|                gadget365	        |\n");
	printf("*---------------------------------------*\n");
	printf("|  1 - Log-In Utente                    |\n");
	printf("|  2 - Registrazione Utente             |\n");
	printf("|  3 - Esci                             |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_menu()
{
	printf("\n*---------------------------------------*\n");
	printf("|             Menu Cliente              |\n");
	printf("*---------------------------------------*\n");
	printf("|  1 - Visualizza gadget                |\n");
	printf("|  2 - Ricerca gadget                   |\n");
	printf("|  3 - Effettua Ordine                  |\n");
	printf("|  4 - Visualizza Oridni                |\n");
	printf("|  5 - Modifica Dati Personali          |\n");
	printf("|  6 - Cancella Account                 |\n");
	printf("|  7 - Log Out                          |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_menu_modifica()
{
	printf("\n*---------------------------------------*\n");
	printf("|             Menu Modifica             |\n");
	printf("*---------------------------------------*\n");
	printf("|  1 - Modifica P.Iva                   |\n");
	printf("|  2 - Modifica Rag. Sociale            |\n");
	printf("|  3 - Modifica Citta'                  |\n");
	printf("|  4 - Indietro                         |\n");
	printf("*---------------------------------------*\n");

}


void visualizza_menu_ricerca()
{
	printf("\n*--------------------------------------*\n");
	printf("|             Menu Ricerca              |\n");
	printf("*---------------------------------------*\n");
	printf("|  1 - Per Nome                         |\n");
	printf("|  2 - Per Codice                       |\n");
	printf("|  3 - Per Colore                       |\n");
	printf("|  4 - Visualizza piu' venduto          |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_menu_modifica_gadget()
{
	printf("\n*---------------------------------------*\n");
	printf("|             Menu Modifica             |\n");
	printf("*---------------------------------------*\n");
	printf("|  1 - Modifica Nome                    |\n");
	printf("|  2 - Modifica Descrizione             |\n");
	printf("|  3 - Modifica Colore                  |\n");
	printf("|  4 - Modifica Prezzo                  |\n");
	printf("|  5 - Modifica Giacenza                |\n");
	printf("|  6 - Indietro                         |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_menu_gestore()
{
	printf("\n*---------------------------------------*\n");
	printf("|          Menu gestore                 |\n");
	printf("*---------------------------------------*\n");
	printf("|  1 - Aggiungi Gadget                  |\n");
	printf("|  2 - Modifica Gadget                  |\n");
	printf("|  3 - Cancella Gadget                  |\n");
	printf("|  4 - Visualizza Ordini                |\n");
	printf("|  5 - Accetta Ordini	                |\n");
	printf("|  6 - Visualizza gadget                |\n");
	printf("|  7 - Ricerca gadget                   |\n");
	printf("|  8 - Log Out                          |\n");
	printf("*---------------------------------------*\n");

}


void visualizza_cliente(cliente_t xcliente)
{

	printf("\n*---------------------------------------*\n");
	printf("|        Informazioni Utente            |\n");
	printf("*---------------------------------------*\n");
	printf("|  - P.Iva: %s                          \n",xcliente.piva);
	printf("|  - Ragione Sociale: %s                \n",xcliente.ragione_sociale);
	printf("|  - Citta': %s                         \n",xcliente.citta);
	printf("*---------------------------------------*\n");

}


void visualizza_gadget(gadget_t xgadget)
{
	if(xgadget.quantita>=0 && xgadget.prezzo>0)
	{
	printf("*---------------------------------------*\n");
	printf("|          Codice Gadget: %s          |\n",xgadget.cod_gadget);
	printf("*---------------------------------------*\n");
	printf("\t  - Nome: %s\t\n",xgadget.nome_gadget);
	printf("\t  - Descrizione: %s\t\n",xgadget.desc);
	printf("\t  - Colore: %s\t\n",xgadget.colore);
	printf("\t  - Prezzo: %.2f\t\n",xgadget.prezzo);
	printf("\t  - Quantita: %d\t\n",xgadget.quantita);
	printf("\t  - Venduti: %d\t\n",xgadget.venduti);
	printf("*---------------------------------------*\n");
	}
}


void visualizza_gadget_recap(gadget_t xgadget)
{
	printf("*---------------------------------------*\n");
	printf("|          Codice Gadget: %s          |\n",xgadget.cod_gadget);
	printf("*---------------------------------------*\n");
	printf("|\t  - Nome: %s\t\n",xgadget.nome_gadget);
	printf("|\t  - Colore: %s\t\n",xgadget.colore);
	printf("*---------------------------------------*\n");
}


void visualizza_ordine_recap(ordine_t xordine)
{

	cliente_t xcliente;
	gadget_t xgad;
	int esito=0;
	restituisci_cliente(xordine.username_cliente,&xcliente);

	printf("*=======================================*\n");
	printf("|        Codice Ordine: %s	        | \n",xordine.cod_ordine);
	printf("\t Cliente: %s\t\t\n",xcliente.ragione_sociale);

	for(int i=0; i<xordine.n_gadget;i++)
	{
		esito=restituisci_gadget(xordine.articoli_ordine[i].cod_gadget,&xgad,1);
		if(esito==1){
			visualizza_gadget_recap(xgad);
		}
		else{
			printf("Prodotto non disponibile\n");
		}

		printf("\t - Quantita' ordinata: %d\t\n",xordine.articoli_ordine[i].quantita);
		printf("\t - Prezzo CAD: %.2f\t\n", xordine.articoli_ordine[i].prezzo_CAD);
		printf("\t======================\n");

	}


	printf("- Totale: %.2f\t\n", xordine.totale);
	printf("- Commento: %s\t\n", xordine.commento);
	if(xordine.stato==STATO_APPROVATO)
	{
		printf("               |APPROVATO|\n");
	}
	else
	{
		if(xordine.stato==STATO_ATTESA){
			printf("               |IN ATTESA|\n");
		}
		else{
			printf("               |NON APPROVATO|\n");
		}
	}




	printf("*=======================================*\n\n");
}


