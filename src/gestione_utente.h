/*
 * gestione_utente.h
 *
 *  Created on: 17 giu 2022
 *      Author: ranie
 */

#ifndef GESTIONE_UTENTE_H_
#define GESTIONE_UTENTE_H_
#include "strutture.h"
#include "gestione_file.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



int registrazione_cliente();
int accesso_cliente(char username[CARATTERI], char pass[CARATTERI]);
void modifica_cliente_RagSoc(char username_corrente[CARATTERI],char rag[CARATTERI]);


#endif /* GESTIONE_UTENTE_H_ */
