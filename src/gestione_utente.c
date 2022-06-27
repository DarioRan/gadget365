/*
 * gestione_utente.c
 *
 *  Created on: 17 giu 2022
 *      Author: ranie
 */

#include "gestione_utente.h"


int registrazione_cliente()
{

	int esito=0;
	cliente_t xutente;
	printf("\n|Inserire ragione sociale: ");
	get_stringa(xutente.ragione_sociale);
	printf("\n|Inserire P. IVA: ");
	get_stringa(xutente.piva);
	printf("\n|Inserire citta': ");
	get_stringa(xutente.citta);
	printf("\n|Inserire email: ");
	get_stringa(xutente.email);
	printf("\n|Inserire username utente: ");
	get_stringa(xutente.username);
	printf("\n|Inserire password utente: ");
	get_stringa(xutente.pass);

	if(inserisci_cliente(xutente)==1)
	{
		printf("|Cliente Registrato Correttamente|"); //////////////////
		esito=1;
		//sleep(1);

	}

	return esito;

}


int accesso_cliente(char username[CARATTERI], char pass[CARATTERI])
{
	//INSERIMENTO USER PASS

	int res=0;
	int res2=0;
	int esito_accesso=0;
	res=strncmp(USERADMIN,username,9);
	res2=strncmp(PASSADMIN,pass,6);
	if(res==0)
	{

		if(res2==0)
		{
			printf("\n|Log-In Admin Avvenuto con Successo!|");
			esito_accesso=2;
		}
		else
		{
			printf("\n|Password Errata!|");
		}
	}
	else
	{
		cliente_t xutente;
		esito_accesso=restituisci_cliente(username,&xutente);
		if(esito_accesso==1)
		{
			if(strcmp(xutente.pass,pass)==0)
			{
				printf("\n|Log-In Avvenuto con Successo!|");
				//sleep(1);
			}
			else
			{
				esito_accesso=0;
				printf("\n|Password Errata!|");
				//sleep(1);
			}
		}
		else
		{
			printf("\n|Impossibile Trovare Username!|");
			//sleep(1);
		}
	}
	return esito_accesso;
}
//1 piva 2 ragsoc 3 citta
void modifica_cliente(char username_corrente[CARATTERI])
{
	char mod[CARATTERI];
	cliente_t xcliente;
	int esito2=0;
	int scelta=0;

	visualizza_menu_modifica();
	printf("\n Inserire scelta: ");
	scanf("%d",&scelta);

	switch(scelta){
	case 1:
		printf("\n|Inserire P. Iva: ");
		get_stringa(mod);
		restituisci_cliente(username_corrente, &xcliente);
		strcpy(xcliente.piva,mod);
		esito2=cancella_cliente(username_corrente);
		esito2=inserisci_cliente(xcliente);
		if(esito2==1)
		{
			printf("\n|Utente Modificato!|");
			visualizza_cliente(xcliente);
			//sleep(1);
		}
		else
		{
			printf("\n|Impossibile Trovare Username!|");
			//sleep(1);
		}
		break;

	case 2:
		printf("\n|Inserire Rag. Sociale: ");
		get_stringa(mod);
		restituisci_cliente(username_corrente, &xcliente);
		strcpy(xcliente.ragione_sociale,mod);
		esito2=cancella_cliente(username_corrente);
		esito2=inserisci_cliente(xcliente);
		if(esito2==1)
		{
			printf("\n|Utente Modificato!|");
			visualizza_cliente(xcliente);
			//sleep(1);
		}
		else
		{
			printf("\n|Impossibile Trovare Username!|");
			//sleep(1);
		}
		break;

	case 3:
		printf("\n|Inserire Citta': ");
		get_stringa(mod);
		restituisci_cliente(username_corrente, &xcliente);
		strcpy(xcliente.citta,mod);
		esito2=cancella_cliente(username_corrente);
		esito2=inserisci_cliente(xcliente);
		if(esito2==1)
		{
			printf("\n|Utente Modificato!|");
			visualizza_cliente(xcliente);
			//sleep(1);
		}
		else
		{
			printf("\n|Impossibile Trovare Username!|");
			//sleep(1);
		}
		break;

	default:
		if(scelta!=4)
		{
			printf("\n|Inserire scelta valida!|");
		}
		break;


	}
}
