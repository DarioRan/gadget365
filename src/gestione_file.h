/*
 * gestione_file.h
 *
 *  Created on: 9 giu 2022
 *      Author: ranie
 */

#ifndef GESTIONE_FILE_H_
#define GESTIONE_FILE_H_
#include "strutture.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void apertura_file();
int inserisci_gadget(gadget_t xgadget);
int resituisci_cliente(char ricerca[CARATTERI], cliente_t* risultato_cliente, int scelta );

#endif /* GESTIONE_FILE_H_ */
