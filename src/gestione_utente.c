/*
 * gestione_utente.c
 *
 *  Created on: 17 giu 2022
 *      Author: ranie
 */

#include "gestione_utente.h"



char USERADMIN[CARATTERI]="admin_365";
char PASSADMIN[CARATTERI]="gadget";


int registrazione_cliente()
{

	int esito=0;
	cliente_t xutente;
	printf("\n|Inserire ragione sociale: ");
	scanf("%s",xutente.ragione_sociale);
	printf("\n|Inserire P. IVA: ");
	scanf("%s",xutente.piva);
	printf("\n|Inserire citta': ");
	scanf("%s",xutente.citta);
	printf("\n|Inserire email: ");
	scanf("%s",xutente.email);
	printf("\n|Inserire username utente: ");
	scanf("%s",xutente.username);
	printf("\n|Inserire password utente: ");
	scanf("%s",xutente.pass);

	if(inserisci_cliente(xutente)==1)
	{
		printf("|Cliente Registrato Correttamente|"); //////////////////
		esito=1;
		sleep(1);

	}

	return esito;

}


int accesso_cliente(char username[CARATTERI], char pass[CARATTERI])
{
	//INSERIMENTO USER PASS

	int res=0,res2=0;
	int esito=0;
	res=strncmp(USERADMIN,username,9);
	res2=strncmp(PASSADMIN,pass,6);
    if(res==0)
    {

    	if(res2==0)
    	    {
    	     printf("\n|Log-In Admin Avvenuto con Successo!|");
    	     esito=2;
    	    }
    	else
    	{
    		 printf("\n|Password Errata!|");
    	}
    }
    else
    {
    	cliente_t xutente;
    		esito=restituisci_cliente(username,&xutente);
    		if(esito==1)
    		{
    			if(strcmp(xutente.pass,pass)==0)
    			{
    				printf("\n|Log-In Avvenuto con Successo!|");
    				sleep(1);
    			}
    			else
    			{
    				esito=0;
    				printf("\n|Password Errata!|");
    				sleep(1);
    			}
    		}
    		else
    		{
    			printf("\n|Impossibile Trovare Username!|");
    			sleep(1);
    		}
    }
	return esito;
}
//1 piva 2 ragsoc 3 citta
void modifica_cliente(char username_corrente[CARATTERI],char mod[CARATTERI],int scelta)
{
	cliente_t xcliente;
	int esito=0;
	int esito2=0;
	switch(scelta){

	case 1:
			esito=restituisci_cliente(username_corrente, &xcliente);
			strcpy(xcliente.piva,mod);
			esito2=cancella_cliente(username_corrente);
			esito2=inserisci_cliente(xcliente);
			if(esito2==1)
			{
				printf("\n|Utente Modificato!|");
				visualizza_cliente(xcliente);
				sleep(1);
			}
			else
			{
				printf("\n|Impossibile Trovare Username!|");
				sleep(1);
			}
			break;

	case 2:
		esito=restituisci_cliente(username_corrente, &xcliente);
		strcpy(xcliente.ragione_sociale,mod);
		esito2=cancella_cliente(username_corrente);
		esito2=inserisci_cliente(xcliente);
		if(esito2==1)
		{
			printf("\n|Utente Modificato!|");
			visualizza_cliente(xcliente);
			sleep(1);
		}
		else
		{
			printf("\n|Impossibile Trovare Username!|");
			sleep(1);
		}
		break;

	case 3:
		esito=restituisci_cliente(username_corrente, &xcliente);
		strcpy(xcliente.citta,mod);
		esito2=cancella_cliente(username_corrente);
		esito2=inserisci_cliente(xcliente);
		if(esito2==1)
		{
			printf("\n|Utente Modificato!|");
			visualizza_cliente(xcliente);
			sleep(1);
		}
		else
		{
			printf("\n|Impossibile Trovare Username!|");
			sleep(1);
		}
		break;

	}
}
