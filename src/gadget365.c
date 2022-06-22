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

int main(void) {

	setbuf(stdout, NULL);
	int scelta=0,esito,menu1=0,menu2=0,menu3=0;
	char nomeutente[CARATTERI],pass[CARATTERI],utentecorrente[CARATTERI],mod[CARATTERI],gadget[CARATTERI];

	apertura_file();

	while(menu1==0)
	{
		inizializza_menu();
		printf("\n Inserire scelta: ");
		scanf("%d",&scelta);

		switch(scelta)
		{

		case 1:
			printf("\n|Inserire nome utente: ");
			scanf("%s",nomeutente);
			printf("\n|Inserire password: ");
			scanf("%s",pass);
			esito=accesso_cliente(nomeutente,pass);

			if(esito==1)
			{

				strcpy(utentecorrente,nomeutente);
				menu2=0;
				while(menu2==0){
					visualizza_menu();

					printf("\n Inserire scelta: ");
					scanf("%d",&scelta);

					switch(scelta)
					{
					case 1:
						restituisciALL_gadget();

						break;
					case 5:
						visualizza_menu_modifica();
						printf("\n Inserire scelta: ");
						scanf("%d",&scelta);
						switch(scelta)
						{
						case 1:
							printf("\n|Inserire P. Iva: ");
							scanf("%s",mod);
							modifica_cliente(utentecorrente,mod,1);
							break;
						case 2:
							printf("\n|Inserire Rag. Sociale: ");
							scanf("%s",mod);
							modifica_cliente(utentecorrente,mod,2);
							break;
						case 3:
							printf("\n|Inserire Citta': ");
							scanf("%s",mod);
							modifica_cliente(utentecorrente,mod,3);
							break;
						}
						break;
						case 6:
							esito=cancella_cliente(utentecorrente);
							if(esito==1)
							{
								printf("\n|Utente eliminato con successo!");
								menu2=1;
							}
							break;
						case 7:
							menu2=1;
							break;


							//TEST GESTORE
							/*
						case 10:
							registrazione_gadget();
							break;*/
					}


				}
			}
			else
			{
				if(esito==2)
				{

					menu3=0;

					while(menu3==0){
					visualizza_menu_gestore();
				    printf("\n Inserire scelta: ");
					scanf("%d",&scelta);
					switch(scelta){

					case 1:
						registrazione_gadget();
						break;
					case 2:
						visualizza_menu_modifica_gadget();
						printf("\n Inserire scelta: ");
						scanf("%d",&scelta);
						switch(scelta){
						case 1:
							printf("\n|Inserire Nome Gadget: ");
							scanf("%s",gadget);
							printf("\n|Inserire Nome Gadget: ");
							scanf("%s",mod);
							modifica_gadget(gadget[CARATTERI],mod,1);
							                        break;
						case 2:
													break;
						case 3:
													break;
						case 4:
													break;
						}
						break;
					case 3:
						printf("\n|Inserire Nome Gadget: ");
						scanf("%s",gadget);
						esito=cancella_gadget(gadget);
						if(esito==1){
							printf("cancellato.");
						}
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

		case 4:
			//modifica_utente;
			break;



		}

	}
}
