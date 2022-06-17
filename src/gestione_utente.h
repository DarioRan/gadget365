/*
 * gestione_utente.h
 *
 *  Created on: 17 giu 2022
 *      Author: ranie
 */

#ifndef GESTIONE_UTENTE_H_
#define GESTIONE_UTENTE_H_
#include "strutture.h"

int registrazione_cliente();
int accesso_cliente(char username[CARATTERI], char pass[CARATTERI]);

#endif /* GESTIONE_UTENTE_H_ */
