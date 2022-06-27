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
	// con la modalità r+b si può scrivere e leggere file binari esistenti
	file_clienti=fopen(FILE_CLIENTI,"r+b");
	file_gadget=fopen(FILE_GADGET,"r+b");
	file_ordini=fopen(FILE_ORDINI,"r+b");

	if(file_clienti==NULL)
	{
		printf ("Errore apertura file clienti\n");
	}
	if(file_ordini==NULL)
	{
		printf ("Errore apertura file ordini\n");
	}

	if(file_gadget==NULL)
	{
		printf ("Errore apertura file gadget\n");
	}

}

int inserisci_gadget(gadget_t xgadget)
{

	int esito=0;
	fseek(file_gadget, sizeof(gadget_t), SEEK_END);
	esito=fwrite(&xgadget,sizeof(gadget_t), 1, file_gadget);
	return esito;
}


int inserisci_ordine(ordine_t xordine)
{
	int esito=0;
	fseek(file_ordini, sizeof(ordine_t), SEEK_END);
	esito=fwrite(&xordine,sizeof(ordine_t), 1, file_ordini);
	return esito;
}


int inserisci_cliente(cliente_t xcliente)
{
	int esito=0;
	cliente_t xut;
	//controlla che l'username del cliente, non è presente
	if(restituisci_cliente(xcliente.username, &xut)==0)
	{
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

int restituisci_cliente(char ricerca[CARATTERI], cliente_t* risultato_cliente )
{
	cliente_t xcliente;
	int trovato=0;
	rewind(file_clienti);
	//scorre i vari record e per ogni record effettua una strcmp per vedere se COINCIDONO
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
	{
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
		*risultato_gadget=xgadget;
	}
	return trovato;
}

//0 nome 1 codice 2 colore
void ricerca_gadget(char ricerca[CARATTERI], int scelta )
{
	gadget_t xgadget;
	char nome_gadget_LOW[CARATTERI];
	char colore_gadget_LOW[CARATTERI];
	char* codice;
	int a;
	rewind(file_gadget);
	fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
	do
	{
		//CONVERTE IN LOWER CASE (non case sensitive)
		for(int i = 0; ricerca[i]; i++)
		{
			ricerca[i] = tolower(ricerca[i]);
			nome_gadget_LOW[i] = tolower(xgadget.nome_gadget[i]);
			colore_gadget_LOW[i] = tolower(xgadget.colore[i]);
		}

		switch(scelta)
		{
		//ricerca su SOTTOSTRINGA
		case 0:
			a=strcmp(codice,xgadget.cod_gadget);
			if(strstr(nome_gadget_LOW,ricerca)!=NULL && a!=0)
			{
				visualizza_gadget(xgadget);
			}
			strcpy(codice,xgadget.cod_gadget);
			fread(&xgadget,sizeof(gadget_t), 1, file_gadget);

			break;

		case 1:
			a=strcmp(codice,xgadget.cod_gadget);
			if(strstr(xgadget.cod_gadget,ricerca)!=NULL && a!=0)
			{
				visualizza_gadget(xgadget);
			}
			strcpy(codice,xgadget.cod_gadget);
			fread(&xgadget,sizeof(gadget_t), 1, file_gadget);

			break;

		case 2:
			a=strcmp(codice,xgadget.cod_gadget);
			if(strstr(colore_gadget_LOW,ricerca)!=NULL && a!=0)
			{
				visualizza_gadget(xgadget);
			}
			strcpy(codice,xgadget.cod_gadget);
			fread(&xgadget,sizeof(gadget_t), 1, file_gadget);

			break;
		}

	}while(!feof(file_gadget));
}

int cancella_cliente(char* username)
{
	int esito=0;
	cliente_t xcliente;
	FILE *temp;
	temp=fopen("temp.csv","wb");

	rewind(file_clienti);

	//Genera file temporaneo e scrive sul file tutti i record il cui condice non coincide

	do{
		fread(&xcliente,sizeof(cliente_t), 1, file_clienti);
		if(strcmp(xcliente.username,username)!=0)
		{
			fwrite(&xcliente,sizeof(cliente_t), 1, temp);
		}
		else
		{
			//Se coincide, non lo scrive e con esito indica che è stato trovato
			esito=1;

		}
	}while(!feof(file_clienti));
	//Chiude entrambi i file e il file temporaneo viene rinominato
	fclose(file_clienti);
	fclose(temp);
	remove(FILE_CLIENTI);
	rename("temp.csv",FILE_CLIENTI);
	file_clienti=fopen(FILE_CLIENTI,"r+b");
	return esito;
}

int cancella_gadget(char* gadget)
{
	int esito=0;
	gadget_t xgadget;
	FILE *temp;
	temp=fopen("temp.csv","wb");

	rewind(file_gadget);

	do{
		fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
		if(strcmp(xgadget.cod_gadget,gadget)!=0)
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
	remove(FILE_GADGET);
	rename("temp.csv",FILE_GADGET);
	file_gadget=fopen(FILE_GADGET,"r+b");

	return esito;
}



void restituisciALL_gadget()
{
	gadget_t xgadget;
	rewind(file_gadget);
	char codice[LUNG_CODICE]="";
	int a=0;
	fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
	do{
		//viene inserita una strcmp poichè nei buffer rimane lo stesso gadget e dà problemi
		a=strcmp(codice,xgadget.cod_gadget);
		if(a!=0 && xgadget.prezzo!=0 )
		{
			visualizza_gadget(xgadget);
		}
		strcpy(codice,xgadget.cod_gadget);
		fread(&xgadget,sizeof(gadget_t), 1, file_gadget);

	}while(!feof(file_gadget));

}

void restituisciALL_ordini()
{
	ordine_t xordine;
	rewind(file_ordini);
	char codice[LUNG_CODICE]="";
	int a=0;
	fread(&xordine,sizeof(ordine_t), 1, file_ordini);
	do{

		a=strcmp(codice,xordine.cod_ordine);
		if(a!=0 && xordine.n_gadget!=0 )
		{
			visualizza_ordine_recap(xordine);
		}
		strcpy(codice,xordine.cod_ordine);
		fread(&xordine,sizeof(ordine_t), 1, file_ordini);

	}while(!feof(file_ordini));

}

void visualizza_ordini_cliente(char* username)
{
	ordine_t xordine;
	rewind(file_ordini);
	fread(&xordine,sizeof(ordine_t), 1, file_ordini);
	do{

		if(strcmp(xordine.username_cliente,username)==0)
		{
			visualizza_ordine_recap(xordine);
		}

		fread(&xordine,sizeof(ordine_t), 1, file_ordini);
	}while(!feof(file_ordini));

}

//visualizza i 3 più venduti
void visualizza_piu_venduti()
{
	gadget_t xgadget,xgadget1,xgadget2,xgadget3, xscambio,xscambio2;
	xgadget1.venduti=0;
	xgadget2.venduti=0;
	xgadget3.venduti=0;
	char codice[LUNG_CODICE]="";
	int a;
	rewind(file_gadget);
	fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
	do{

		a=strcmp(codice,xgadget.cod_gadget);
		if(a!=0 && xgadget.prezzo!=0 )
		{
			if(xgadget.venduti>xgadget1.venduti ||(xgadget.venduti==0 && xgadget1.venduti==0))
			{
				//scambio il primo con il nuovo
				xscambio=xgadget1;
				xgadget1=xgadget;

				//scambio il secondo con il primo
				xscambio2=xgadget2;
				xgadget2=xscambio;

				//scambio il terzo con il secondo
				xgadget3=xscambio2;

				//si shiftano gli elementi

			}
			else{
				if(xgadget.venduti>xgadget2.venduti)
				{
					//scambia il secondo con il nuovo e shifta
					xscambio=xgadget2;
					xgadget2=xgadget;
					xgadget3=xscambio;

				}
				else{
					if(xgadget.venduti>=xgadget3.venduti)
					{
						xgadget3=xgadget;
					}
				}
			}
		}
		strcpy(codice,xgadget.cod_gadget);
		fread(&xgadget,sizeof(gadget_t), 1, file_gadget);
	}while(!feof(file_gadget));

	visualizza_gadget(xgadget1);
	visualizza_gadget(xgadget2);
	visualizza_gadget(xgadget3);

}



int restituisci_ordine(char* codice_ordine, ordine_t* risultato_ordine)
{
	ordine_t xordine;
	int trovato=0;
	rewind(file_ordini);
	fread(&xordine,sizeof(ordine_t), 1, file_ordini);
	do{
		if(strcmp(xordine.cod_ordine,codice_ordine)==0){
			trovato=1;
		}
		else{
			fread(&xordine,sizeof(ordine_t), 1, file_ordini);
		}
	}while(!feof(file_ordini) && trovato==0);

	if(trovato==1)
	{
		*risultato_ordine=xordine;
	}
	return trovato;
}

void approva_ordini()
{
	ordine_t xordine;
	int esito=0;
	int approvazione=0;
	int stato=0;
	char codice_ordine[LUNG_CODICE];
	//VISUALIZZA ORDINI IN ATTESA
	rewind(file_ordini);
	fread(&xordine,sizeof(ordine_t), 1, file_ordini);
	do{
		if(xordine.stato==STATO_ATTESA && xordine.totale!=0)
		{
			visualizza_ordine_recap(xordine);
		}
		fread(&xordine,sizeof(ordine_t), 1, file_ordini);
	}while(!feof(file_ordini));

	printf("Inserire codice ordine da approvare o rifiutare: ");
	get_stringa(codice_ordine);

	esito=restituisci_ordine(codice_ordine,&xordine);

	if(esito==0)
	{
		printf("Ordine non trovato!\n");

	}
	else
	{
		//Se l'ordine non è in attesa, non fa niente
		if(xordine.stato==STATO_APPROVATO || xordine.stato==STATO_NON_APPROVATO)
		{
			printf("Ordine gia' valutato");
		}
		else
		{
			printf("%d - Approvare\n%d - Rifiutare ",STATO_APPROVATO, STATO_NON_APPROVATO);
			approvazione=input_scelta();

			if(approvazione==STATO_APPROVATO)
			{
				if(emetti_ordine(xordine)==1)
				{
					stato=STATO_APPROVATO;
				}
				else
				{
					printf("Errore durante l'emissione dell'ordine");
				}

			}
			else
			{
				if(approvazione==STATO_NON_APPROVATO)
				{
					stato=STATO_NON_APPROVATO;
				}

			}
			if(stato!=STATO_ATTESA)
			{
				modifica_stato_ordine(xordine.cod_ordine,stato);
				printf("Ordine aggiornato\n");
			}

		}
	}

}

int modifica_stato_ordine(char* cod_ordine, int stato)
{
	//Lo stesso della cancellazione e successivamente si riscrive il nuovo gadget modificato e
	//si rinomina il file temp

	ordine_t xordine, xordine_trovato;
	int esito=0;
	FILE *temp;
	temp=fopen("temp.csv","wb");

	rewind(file_ordini);

	do{
		fread(&xordine,sizeof(ordine_t), 1, file_ordini);
		if(strcmp(xordine.cod_ordine,cod_ordine)!=0)
		{
			fwrite(&xordine,sizeof(ordine_t), 1, temp);
		}
		else
		{
			xordine_trovato=xordine;
			esito=1;

		}
	}while(!feof(file_ordini));

	fclose(file_ordini);
	fclose(temp);
	remove(FILE_ORDINI);
	rename("temp.csv",FILE_ORDINI);
	file_ordini=fopen(FILE_ORDINI,"r+b");

	if(esito==1&&(stato==0 ||stato==1 || stato==2))
	{
		xordine_trovato.stato=stato;
		esito=inserisci_ordine(xordine_trovato);
	}
	return esito;
}



