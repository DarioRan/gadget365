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
/**@brief
 *
 * Funzione incaricata di gestire l'input di dati riguardanti i gadget.
 * @param[OTPUT] esito: int
 */
int registrazione_gadget();
/**@brief
 *
 * Procedura che a seconda del valore del parametro "scelta", modifica un determinato parametro del gadget. **in progresso**
 * @param[INPUT] scelta: int
 */
void modifica_gadget_utente(int scelta);
/**@brief
 *
 * Procedura che a seconda del valore del parametro "scelta" inserito da tastiera, chiama la funzione ricerca_gadget nelle seguenti modalita': ricerca per nome(0), ricerca per codice(1), ricerca per colore(2).
 */
void effettua_ricerca();
int modifica_quant_prezz_venduti_gadget(char gadget[CARATTERI],float valore, int scelta);


#endif /* GESTIONE_GADGET_H_ */
