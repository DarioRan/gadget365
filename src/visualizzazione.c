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
	printf("|  1 - Per nome                         |\n");
	printf("|  2 - Per codice                       |\n");
	printf("|  3 - Per colore                       |\n");
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
	printf("|  5 - Indietro                         |\n");
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
	printf("|  6 - Log Out                          |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_ricerca_appartamento()
{

	printf("\n*---------------------------------------*\n");
	printf("|        Ricerca gadget	        |\n");
	printf("*---------------------------------------*\n");
	printf("|  1 - Ricerca per Nome                 |\n");
	printf("|  2 - Ricerca per Colore               |\n");
	printf("|  3 - Ricerca per codice               |\n");
	printf("|  4 - Indietro                         |\n");
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
	printf("\n*---------------------------------------*\n");
	printf("|        COD: %s	        |\n",xgadget.cod_gadget);
	printf("*---------------------------------------*\n");
	printf("|  - Nome: %s\n",xgadget.nome_gadget);
	printf("|  - Descrizione: %s\n",xgadget.desc);
	printf("|  - Colore: %s\n",xgadget.colore);
	printf("|  - Prezzo: %.2f\n",xgadget.prezzo);
	printf("|  - Quantita: %d\n",xgadget.quantita);
	printf("|  - Venduti: %d\n",xgadget.venduti);
	printf("*---------------------------------------*\n");
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
		printf("|  - Prezzo CAD: %d\n", xordine.articoli_ordine[i].prezzo_CAD);

	}


	printf("|  - Totale: %.2f\n", xordine.totale);

	if(xordine.stato==1)
	{
		printf("| APPROVATO |\n");
	}
	else
	{
		if(xordine.stato==2){
			printf("| IN ATTESA |\n");
		}
		else{
			printf("| NON APPROVATO |\n");
		}
	}




	printf("*---------------------------------------*\n");
}

