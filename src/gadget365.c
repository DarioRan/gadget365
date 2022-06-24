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
	//int menu1=0,menu2=0,menu3=0,scelta;





	char nomeutente[CARATTERI],pass[CARATTERI],utente_corrente[CARATTERI],gadget[CARATTERI];
	int menu1=0,menu2=0,menu3=0;
	int esito;

	int scelta;

	apertura_file();
	while(menu1==0)
	{
		inizializza_menu();
		printf("\n Inserire scelta: ");
		scanf("%d",&scelta);
		//scelta=tolower(scelta);

		switch(scelta)
		{
//a
		case 1:
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
					scanf("%d",&scelta);
					//scelta=tolower(scelta);


					switch(scelta)
					{
	//a
					case 1:
						restituisciALL_gadget();
						break;
//b
					case 2:
						effettua_ricerca();
						break;
//c
					case 3:
						effettua_ordine(utente_corrente);
						break;
//d
					case 4:
						visualizza_ordini_cliente(utente_corrente);
						break;
//e
					case 5:
						visualizza_menu_modifica();
						printf("\n Inserire scelta: ");
						scanf("%c",&scelta);
						scelta=tolower(scelta);

						switch(scelta)
						{
						//a
						case 1:

							modifica_cliente(utente_corrente,1);
							break;
						//b
						case 2:

							modifica_cliente(utente_corrente,2);
							break;
						//c
						case 3:

							modifica_cliente(utente_corrente,3);
							break;
						}
						break;
					//f
						case 6:
							esito=cancella_cliente(utente_corrente);
							if(esito==1)
							{
								printf("\n|Utente eliminato con successo!");
								menu2=1;
							}
							break;
					//g
						case 7:
							menu2=1;
							break;
							//h
						case 8:
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
						scanf("%d",&scelta);
						//scelta=tolower(scelta);

						switch(scelta){
//a
						case 1:
							registrazione_gadget();
							break;
						case 2:
							visualizza_menu_modifica_gadget();
							printf("\n Inserire scelta: ");
							scanf("%d",&scelta);
							//scelta=tolower(scelta);

							switch(scelta){
							case 1:
								modifica_gadget(1);
								break;
							case 2:
								modifica_gadget(2);
								break;
							case 3:
								modifica_gadget(3);
								break;
							case 4:
								modifica_prezzo_gadget();
								break;


							default:
								break;

							}
							break;
							case 4:
								printf("\n|Inserire Nome Gadget: ");
								scanf("%s",gadget);
								esito=cancella_gadget(gadget);
								if(esito==1){
									printf("|Gadget Cancellato!");
								}
								break;
							case 5:
								approva_ordini();
								break;
							case 6:
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
			break;

		}

	}


}
