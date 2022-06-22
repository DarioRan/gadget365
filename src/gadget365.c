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

	int scelta=0;

	inizializza_menu();
	scanf("%d",&scelta);
	switch(scelta)
	{

	case 1:
		//login
		break;
	case 2:
		registrazione_cliente();
		break;

	}

}
