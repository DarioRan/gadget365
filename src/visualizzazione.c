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
	printf("|  a - Log-In Utente                    |\n");
	printf("|  b - Registrazione Utente             |\n");
	printf("|  c - Esci                             |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_menu()
{
	printf("\n*---------------------------------------*\n");
	printf("|             Menu Cliente              |\n");
	printf("*---------------------------------------*\n");
	printf("|  a - Visualizza gadget                |\n");
	printf("|  b - Ricerca gadget                   |\n");
	printf("|  c - Effettua Ordine                  |\n");
	printf("|  d - Visualizza Oridni                |\n");
	printf("|  e - Modifica Dati Personali          |\n");
	printf("|  f - Cancella Account                 |\n");
	printf("|  g - Log Out                          |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_menu_modifica()
{
	printf("\n*---------------------------------------*\n");
	printf("|             Menu Modifica             |\n");
	printf("*---------------------------------------*\n");
	printf("|  a - Modifica P.Iva                   |\n");
	printf("|  b - Modifica Rag. Sociale            |\n");
	printf("|  c - Modifica Citta'                  |\n");
	printf("|  d - Indietro                         |\n");
	printf("*---------------------------------------*\n");

}


void visualizza_menu_ricerca()
{
	printf("\n*--------------------------------------*\n");
	printf("|             Menu Ricerca              |\n");
	printf("*---------------------------------------*\n");
	printf("|  a - Per nome                         |\n");
	printf("|  b - Per codice                       |\n");
	printf("|  c - Per colore                       |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_menu_modifica_gadget()
{
	printf("\n*---------------------------------------*\n");
	printf("|             Menu Modifica             |\n");
	printf("*---------------------------------------*\n");
	printf("|  a - Modifica Nome                    |\n");
	printf("|  b - Modifica Descrizione             |\n");
	printf("|  c - Modifica Colore                  |\n");
	printf("|  d - Modifica Prezzo                  |\n");
	printf("|  e - Indietro                         |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_menu_gestore()
{
	printf("\n*---------------------------------------*\n");
	printf("|          Menu gestore                 |\n");
	printf("*---------------------------------------*\n");
	printf("|  a - Aggiungi Gadget                  |\n");
	printf("|  b - Modifica Gadget                  |\n");
	printf("|  c - Cancella Gadget                  |\n");
	printf("|  d - Visualizza Ordini                |\n");
	printf("|  e - Accetta Ordini	                |\n");
	printf("|  f - Log Out                          |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_ricerca_appartamento()
{

	printf("\n*---------------------------------------*\n");
	printf("|        Ricerca gadget	        |\n");
	printf("*---------------------------------------*\n");
	printf("|  a - Ricerca per Nome                 |\n");
	printf("|  b - Ricerca per Colore               |\n");
	printf("|  c - Ricerca per codice               |\n");
	printf("|  d - Indietro                         |\n");
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
	if(xgadget.quantita>0)
	{
	printf("\n*---------------------------------------*\n");
	printf("|        COD: %s	        \n",xgadget.cod_gadget);
	printf("*---------------------------------------*\n");
	printf("|  - Nome: %s\n",xgadget.nome_gadget);
	printf("|  - Descrizione: %s\n",xgadget.desc);
	printf("|  - Colore: %s\n",xgadget.colore);
	printf("|  - Prezzo: %.2f\n",xgadget.prezzo);
	printf("|  - Quantita: %d\n",xgadget.quantita);
	printf("|  - Venduti: %d\n",xgadget.venduti);
	printf("*---------------------------------------*\n");
	}
}


void visualizza_gadget_recap(gadget_t xgadget)
{
	printf("\n*---------------------------------------*\n");
	printf("|        COD: %s	        |\n",xgadget.cod_gadget);
	printf("*---------------------------------------*\n");
	printf("|  - Nome: %s\n",xgadget.nome_gadget);
	printf("|  - Colore: %s\n",xgadget.colore);
	printf("*---------------------------------------*\n");
}


void visualizza_ordine_recap(ordine_t xordine)
{

	cliente_t xcliente;
	gadget_t xgad;
	int esito=0;
	restituisci_cliente(xordine.username_cliente,&xcliente);

	printf("\n*---------------------------------------*\n");
	printf("|        COD: %s	        |\n",xordine.cod_ordine);
	printf("*---------------------------------------*\n");
	printf("|  - Cliente: %s\n",xcliente.ragione_sociale);

	for(int i=0; i<xordine.n_gadget;i++)
	{
		esito=restituisci_gadget(xordine.articoli_ordine[i].cod_gadget,&xgad,1);
		if(esito==1){
			visualizza_gadget_recap(xgad);
		}
		else{
			printf("Prodotto non disponibile\n");
		}

		printf("|  - Quantita' ordinata: %d\n",xordine.articoli_ordine[i].quantita);
		printf("|  - Prezzo CAD: %.2f\n", xordine.articoli_ordine[i].prezzo_CAD);

	}


	printf("|  - Totale: %.2f\n", xordine.totale);

	if(xordine.stato==1)
	{
		printf("| APPROVATO |\n");
	}
	else
	{
		if(xordine.stato==0){
			printf("| IN ATTESA |\n");
		}
		else{
			printf("| NON APPROVATO |\n");
		}
	}




	printf("*---------------------------------------*\n");
}


