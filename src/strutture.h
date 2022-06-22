/*
 * strutture.h
 *
 *  Created on: 9 giu 2022
 *      Author: ranieromito
 */

#ifndef STRUTTURE_H_
#define STRUTTURE_H_
#define CARATTERI 50


typedef struct
{
	char ragione_sociale[CARATTERI];
	char piva[CARATTERI];
	char citta[CARATTERI];
	char email[CARATTERI];

	char username[CARATTERI];
	char pass[CARATTERI];

	float valutazione;

}cliente_t;

typedef struct
{
	char cod_gadget[6];
	char nome_gadget[CARATTERI];
	char desc[CARATTERI];
	char colore[CARATTERI];
	//Tipologia
	float prezzo;
	int quantita;
	int venduti;

}gadget_t;

typedef struct
{
	char cod_ordine[6];
	char codice_prodotto[CARATTERI];
	int quantita;
	int stato;  //0 non confermata 1 confermata
	float totale;
	char cod_cliente[CARATTERI];

}ordine_t;


#endif /* STRUTTURE_H_ */
