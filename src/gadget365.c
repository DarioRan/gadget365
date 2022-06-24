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

int main(void) {

	setbuf(stdout, NULL);
	int esito,menu1=0,menu2=0,menu3=0;
	char nomeutente[CARATTERI],pass[CARATTERI],utente_corrente[CARATTERI],gadget[CARATTERI];
	char scelta;

	apertura_file();

	while(menu1==0)
	{
		inizializza_menu();
		printf("\n Inserire scelta: ");
		scanf("%c",&scelta);
		scelta=tolower(scelta);

		switch(scelta)
		{

		case 'a':
			printf("\n|Inserire nome utente: ");
			scanf("%s",nomeutente);
			printf("\n|Inserire password: ");
			scanf("%s",pass);
			esito=accesso_cliente(nomeutente,pass);

			if(esito==1)
			{

				strcpy(utente_corrente,nomeutente);
				menu2=0;
				//MENU CLIENTE
				while(menu2==0){
					visualizza_menu();
					printf("\n Inserire scelta: ");
					scanf("%c",&scelta);
					scelta=tolower(scelta);


					switch(scelta)
					{
					case 'a':
						restituisciALL_gadget();
						break;

					case 'b':
						effettua_ricerca();
						break;

					case 'c':
						effettua_ordine(utente_corrente);
						break;

					case 'd':
						visualizza_ordini_cliente(utente_corrente);
						break;

					case 'e':
						visualizza_menu_modifica();
						printf("\n Inserire scelta: ");
						scanf("%c",&scelta);
						scelta=tolower(scelta);

						switch(scelta)
						{
						case 'a':

							modifica_cliente(utente_corrente,1);
							break;
						case 'b':

							modifica_cliente(utente_corrente,2);
							break;
						case 'c':

							modifica_cliente(utente_corrente,3);
							break;
						}
						break;
						case 'f':
							esito=cancella_cliente(utente_corrente);
							if(esito==1)
							{
								printf("\n|Utente eliminato con successo!");
								menu2=1;
							}
							break;
						case 'g':
							menu2=1;
							break;
						case 'h':
							visualizza_piu_venduti();
							break;

						default:

							break;

					}


				}
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
						scanf("%c",&scelta);
						scelta=tolower(scelta);

						switch(scelta){

						case 'a':
							registrazione_gadget();
							break;
						case 'b':
							visualizza_menu_modifica_gadget();
							printf("\n Inserire scelta: ");
							scanf("%c",&scelta);
							scelta=tolower(scelta);

							switch(scelta){
							case 'a':
								modifica_gadget(1);
								break;
							case 'b':
								modifica_gadget(2);
								break;
							case 'c':
								modifica_gadget(3);
								break;
							case 'd':
								modifica_prezzo_gadget();
								break;
							default:
								break;
							}
							break;
							case 'd':
								printf("\n|Inserire Nome Gadget: ");
								scanf("%s",gadget);
								esito=cancella_gadget(gadget);
								if(esito==1){
									printf("|Gadget Cancellato!");
								}
								break;
							case 'f':
								menu3=1;
								break;


						}

					}
				}
			}
			break;

		case 'b':
			registrazione_cliente();
			break;

		case 'c':
			menu1=1;
			break;


		}

	}
}
