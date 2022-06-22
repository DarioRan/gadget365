/*
 * visualizzazione.c
 *
 *  Created on: 10 giu 2022
 *      Author: ranie
 */

#include "strutture.h"

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
	printf("|  1 - Ricerca gadget                   |\n");
	printf("|  2 - Effettua Ordine                  |\n");
	printf("|  3 - Visualizza Oridni                |\n");
	printf("|  4 - Modifica Dati Personali          |\n");
	printf("|  5 - Cancella Account                 |\n");
	printf("|  6 - Log Out                          |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_menu_modifica()
{
	printf("\n*---------------------------------------*\n");
	printf("|             Menu Modifica             |\n");
	printf("*---------------------------------------*\n");
	printf("|  1 - Modifica Nome                    |\n");
	printf("|  2 - Modifica Cognome                 |\n");
	printf("|  3 - Modifica Data di Nascita         |\n");
	printf("|  4 - Indietro                         |\n");
	printf("*---------------------------------------*\n");

}

void visualizza_menu_gestore()
{
	printf("\n*---------------------------------------*\n");
	printf("|          Menu gestore 		        |\n");
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
	printf("|  - P.Iva: %s                          |\n",xcliente.piva);
	printf("|  - Ragione Sociale: %s                |\n",xcliente.ragione_sociale);
	printf("|  - Citta': %s                         |\n",xcliente.citta);
	printf("*---------------------------------------*\n");

}

//Completare
void visualizza_gadget(gadget_t xgadget)
{
		printf("\n*---------------------------------------*\n");
		printf("|        COD: %s	        |\n",xgadget.cod_gadget);
		printf("*---------------------------------------*\n");
		printf("|  1 - Ricerca per Nome                 |\n");
		printf("|  2 - Ricerca per Colore               |\n");
		printf("|  3 - Ricerca per codice               |\n");
		printf("|  4 - Indietro                         |\n");
		printf("*---------------------------------------*\n");
}
