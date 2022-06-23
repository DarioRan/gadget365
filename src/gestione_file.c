/*
 * gestione_file.c
 *
 *  Created on: 9 giu 2022
 *      Author: ranie
 */
#include "gestione_file.h"

FILE *file_clienti;
FILE *file_gadget;
FILE *file_ordini;

void apertura_file()
{
	file_clienti=fopen("clienti.csv","r+b");
	file_gadget=fopen("gadget.csv","r+b");
	file_ordini=fopen("ordini.csv","r+b");

	if(file_clienti!=NULL)
	{
		printf ("File clienti aperto correttamente\n");
	}
	else
	{
		printf ("Errore apertura file clienti\n");
	}

	if(file_ordini!=NULL)
	{
		printf ("File ordini aperto correttamente\n");
	}
	else
	{
		printf ("Errore apertura file ordini\n");
	}

	if(file_gadget!=NULL)
	{
		printf ("File gadget aperto correttamente\n");
	}
	else
	{
		printf ("Errore gadget file prenotazioni\n");
	}

}

int inserisci_gadget(gadget_t xgadget)
{
	int esito=0;
	//rewind(file_utenti);
	fseek(file_gadget, sizeof(gadget_t), SEEK_END);
	fwrite(&xgadget,sizeof(gadget_t), 1, file_gadget);
	esito=1;
	return esito;
}


int inserisci_ordine(ordine_t xordine)
{
	int esito=0;
	//rewind(file_utenti);
	fseek(file_ordini, sizeof(ordine_t), SEEK_END);
	fwrite(&xordine,sizeof(ordine_t), 1, file_ordini);
	esito=1;
	return esito;
}


int inserisci_cliente(cliente_t xcliente)
{
	int esito=0;
	cliente_t xut;
	if(restituisci_cliente(xcliente.username, &xut)==0)
	{
		//rewind(file_utenti);
		fseek(file_clienti, sizeof(cliente_t), SEEK_END);
		fwrite(&xcliente,sizeof(cliente_t), 1, file_clienti);
		esito=1;
	}
	else
	{
		printf("Username già in uso");
		esito=0;
	}
	return esito;
}

//0 username 1 codice
int restituisci_cliente(char ricerca[CARATTERI], cliente_t* risultato_cliente )
{
	cliente_t xcliente;
	int trovato=0;
	rewind(file_clienti);
	fread(&xcliente,sizeof(cliente_t), 1, file_clienti);
	do
	{
		if(strcmp(xcliente.username,ricerca)==0)
		{
			trovato=1;
		}
		else
		{

			fread(&xcliente,sizeof(cliente_t), 1, file_clienti);
		}

	}while(!feof(file_clienti) && trovato==0);

	if(trovato==1)
	{/*
		strcpy(risultato_cliente->cod_cliente, xcliente.cod_cliente);
		strcpy(risultato_cliente->ragione_sociale, xcliente.ragione_sociale);
		strcpy(risultato_cliente->piva, xcliente.piva);
		strcpy(risultato_cliente->citta, xcliente.citta);
		strcpy(risultato_cliente->email, xcliente.email);
		strcpy(risultato_cliente->pass, xcliente.pass);
		strcpy(risultato_cliente->username, xcliente.username);*/
		*risultato_cliente=xcliente;
	}
	return trovato;
}


int restituisci_gadget(char ricerca[CARATTERI], gadget_t* risultato_gadget, int scelta )
{

	gadget_t xgadget;
	int trovato=0;
	rewind(file_gadget);
	fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
	do
	{

		if(scelta==0)
		{
			if(strcmp(xgadget.nome_gadget,ricerca)==0)
			{
				trovato=1;
			}
			else
			{

				fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
			}
		}

		if(scelta==1)
		{
			if(strcmp(xgadget.cod_gadget,ricerca)==0)
			{
				trovato=1;
			}
			else
			{
				fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
			}
		}


	}while(!feof(file_gadget) && trovato==0);

	if(trovato==1)
	{
		/*
		strcpy(risultato_gadget->cod_gadget, xgadget.cod_gadget);
		strcpy(risultato_gadget->nome_gadget, xgadget.nome_gadget);
		strcpy(risultato_gadget->colore, xgadget.colore);
		strcpy(risultato_gadget->desc, xgadget.desc);
		risultato_gadget->quantita=xgadget.quantita;
		risultato_gadget->prezzo = xgadget.prezzo;
		 */

		*risultato_gadget=xgadget;
	}
	return trovato;
}

//0 nome 1 codice 2 colore
int ricerca_gadget(char ricerca[CARATTERI], gadget_t* risultato_gadget, int scelta )
{
	gadget_t xgadget;
	int trovato=0;
	rewind(file_gadget);
	fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
	do
	{
		switch(scelta)
		{
		case 0:

			if(strstr(xgadget.nome_gadget,ricerca)!=NULL)
			{
				//STAMPA
			}
			fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
			break;

		case 1:

			if(strstr(xgadget.cod_gadget,ricerca)!=NULL)
			{
				//STAMPA
			}
			fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
			break;

		case 2:

			if(strstr(xgadget.colore,ricerca)!=NULL)
			{
				//STAMPA
			}
			fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
			break;

		}

	}while(!feof(file_gadget) && trovato==0);

	if(trovato==1)
	{
		/*
		strcpy(risultato_gadget->cod_gadget, xgadget.cod_gadget);
		strcpy(risultato_gadget->nome_gadget, xgadget.nome_gadget);
		strcpy(risultato_gadget->colore, xgadget.colore);
		strcpy(risultato_gadget->desc, xgadget.desc);
		risultato_gadget->quantita=xgadget.quantita;
		risultato_gadget->prezzo = xgadget.prezzo;
		 */

		*risultato_gadget=xgadget;
	}
	return trovato;
}

int cancella_cliente(char username[CARATTERI])
{
	int esito=0;
	cliente_t xcliente;
	FILE *temp;
	temp=fopen("temp.csv","wb");

	rewind(file_clienti);

	do{
		fread(&xcliente,sizeof(cliente_t), 1, file_clienti);
		if(strcmp(xcliente.username,username)!=0)
		{
			fwrite(&xcliente,sizeof(cliente_t), 1, temp);
		}
		else
		{
			esito=1;

		}
	}while(!feof(file_clienti));

	fclose(file_clienti);
	fclose(temp);
	remove("clienti.csv");
	rename("temp.csv","clienti.csv");
	file_clienti=fopen("clienti.csv","r+b");



	return esito;
}

int cancella_gadget(char gadget[CARATTERI])
{
	int esito=0;
	gadget_t xgadget;
	FILE *temp;
	temp=fopen("temp.csv","wb");

	rewind(file_gadget);

	do{
		fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
		if(strcmp(xgadget.nome_gadget,gadget)!=0)
		{
			fwrite(&xgadget,sizeof(gadget_t), 1, temp);
		}
		else
		{
			esito=1;

		}
	}while(!feof(file_gadget));

	fclose(file_gadget);
	fclose(temp);
	remove("gadget.csv");
	rename("temp.csv","gadget.csv");
	file_gadget=fopen("gadget.csv","r+b");



	return esito;
}



void restituisciALL_gadget()
{
	gadget_t xgadget;
	rewind(file_gadget);
	fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
	do{
		visualizza_gadget(xgadget);
		fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
	}while(!feof(file_gadget));

}

void visualizza_ordini_cliente(char* username)
{
	ordine_t xordine;
	rewind(file_ordini);
	fread(&xordine,sizeof(ordine_t), 1, file_ordini);
	do{
		if(strcmp(xordine.username_cliente,username)==0){
			visualizza_ordine_recap(xordine);
		}
		fread(&xordine,sizeof(ordine_t), 1, file_ordini);
	}while(!feof(file_ordini));

}





