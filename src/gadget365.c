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
	int scelta=0,esito,menu1=0,menu2=0;
	char nomeutente[CARATTERI],pass[CARATTERI],utentecorrente[CARATTERI];

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
    	while(menu2==0){

    	visualizza_menu();

    	printf("\n Inserire scelta: ");
    	scanf("%d",&scelta);

    	switch(scelta)
    	{
    	case 6:
    	menu2=1;
    	break;
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

	}

	}
}
