/*
 * gestione_gadget.h
 *
 *  Created on: 22 giu 2022
 *      Author: ranie
 */

#ifndef GESTIONE_GADGET_H_
#define GESTIONE_GADGET_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "strutture.h"

int registrazione_gadget();
void modifica_gadget_utente(int scelta);
void effettua_ricerca();
int modifica_quant_prezz_venduti_gadget(char gadget[CARATTERI],float valore, int scelta);


#endif /* GESTIONE_GADGET_H_ */
