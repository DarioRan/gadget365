/*
 ============================================================================
 Name        : gadget365.c
 Author      : Dario Ranieri e Emanuele Romito
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "visualizzazione.h"
#include "gestione_file.h"
#include "gestione_utente.h"
#include "gestione_ordini.h"
#include "gestione_gadget.h"
#include "Utiles.h"

int main(void) {

	setvbuf(stdout, NULL,_IONBF,0);

	char nomeutente[CARATTERI];
	char pass[CARATTERI];
	char utente_corrente[CARATTERI];
	char codgadget[LUNG_CODICE];
	int menu1=0;
	int menu2=0;
	int menu3=0;
	int esito;

	int scelta;

	apertura_file();
	while(menu1==0)
	{
		inizializza_menu();
		printf("\n Inserire scelta: ");
		scelta=input_scelta();

		switch(scelta)
		{

		case 1:
			puts("|Inserire nome utente: ");
			get_stringa(nomeutente);
			puts("|Inserire password: ");
			get_stringa(pass);
			esito=accesso_cliente(nomeutente,pass);
			if(esito==1)
			{
				strcpy(utente_corrente,nomeutente);
				menu2=0;
				//MENU CLIENTE
				while(menu2==0){
					visualizza_menu();
					printf("\n Inserire scelta: ");
					scelta=input_scelta();

					switch(scelta)
					{
					case 1:
						restituisciALL_gadget();
						break;

					case 2:
						effettua_ricerca();
						break;

					case 3:
						effettua_ordine(utente_corrente);
						break;

					case 4:
						visualizza_ordini_cliente(utente_corrente);
						break;

					case 5:

						modifica_cliente(utente_corrente);
						break;

					case 6:
						esito=cancella_cliente(utente_corrente);
						if(esito==1)
						{
							printf("\n|Utente eliminato con successo!");
							menu2=1;
						}
						break;

					case 7:
						menu2=1;
						break;


					default:

						break;
					}
				}
				///////////////////////
			}
			else
			{
				if(esito==2)
				{
					//MENU GESTORE
					menu3=0;
					while(menu3==0){
						visualizza_menu_gestore();
						printf("\n Inserire scelta: ");
						scelta=input_scelta();

						switch(scelta){
						case 1:
							registrazione_gadget();
							break;
						case 2:
							modifica_gadget_utente();
							break;
						case 3:
							printf("\n|Inserire Codice Gadget: ");
							get_stringa(codgadget);
							esito=cancella_gadget(codgadget);
							if(esito==1){
								printf("|Gadget Cancellato!");
							}
							else
							{
								printf("\n|Gadget non trovato.\n");
							}
							break;

						case 4:
							restituisciALL_ordini();
							break;

						case 5:
							approva_ordini();
							break;

						case 6:
							restituisciALL_gadget();
							break;

						case 7:
							effettua_ricerca();
							break;

						case 8:
							menu3=1;
							break;
						}

					}
				}
			}
			break;

		case 2:
			registrazione_cliente();
			break;

		case 3:
			menu1=1;
			break;

		default:
			printf("\n|Inserire scelta valida. \n");
			break;

		}
	}
}
