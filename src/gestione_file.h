/*
 * gestione_file.h
 *
 *  Created on: 9 giu 2022
 *      Author: ranie
 */

#ifndef GESTIONE_FILE_H_
#define GESTIONE_FILE_H_
#include "strutture.h"
#include "visualizzazione.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void apertura_file();
int inserisci_gadget(gadget_t xgadget);
int inserisci_cliente(cliente_t xcliente);
int inserisci_ordine(ordine_t xordine);
int restituisci_cliente(char ricerca[CARATTERI], cliente_t* risultato_cliente );
void ricerca_gadget(char ricerca[CARATTERI], int scelta );
int restituisci_gadget(char ricerca[CARATTERI], gadget_t* risultato_gadget, int scelta );
int cancella_gadget(char gadget[CARATTERI]);
int cancella_cliente(char username[CARATTERI]);
void visualizza_ordini_cliente(char* username);
void restituisciALL_gadget();
void visualizza_piu_venduti();





#endif /* GESTIONE_FILE_H_ */
