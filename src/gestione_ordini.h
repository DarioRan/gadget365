/*
 * gestione_ordini.h
 *
 *  Created on: 23 giu 2022
 *      Author: ranie
 */

#ifndef GESTIONE_ORDINI_H_
#define GESTIONE_ORDINI_H_

#include "strutture.h"
#include "gestione_file.h"
#include "gestione_gadget.h"
#include "gestione_ordini.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**@brief
 *
 * Procedura incaricata di assemblare ed inserire nel file "file_ordini" un nuovo ordine. Tramite una struct di appoggio gadget_t, utilizzando la funzione "restituisci_gadget" ottiene le informazioni dei gadget acquistati utilizzandole per comporre l'ordine. Verranno dunque aggiornati i parametri della struct ordine_t la quale verra' inserita sotto forma di record nel file "file_ordini".
 * @param[INPUT] username: char*
 */
void effettua_ordine(char* username);
/**@brief
 *
 * Funzione che a seconda dei gadget presenti nell'ordine, utilizza la funzione "restituisci_gadget" per ottenere i gadget desitderati in una struct di appoggio gadget_t per poi andare a modificare le giacenze e il numero di gadget venduti. Quindi in seguito cancella il gadget dal file "file_gadget" e inserisce la struct con le modifiche.
 * @param[INPUT] xordine: ordine_t
 * @param[OUTPUT] esitofinale: int
 * @retval "0" Se l'inserimento e' stato completato.
 * @retval "1" Se si e' presentato un errore.
 */
int emetti_ordine(ordine_t xordine);



#endif /* GESTIONE_ORDINI_H_ */
