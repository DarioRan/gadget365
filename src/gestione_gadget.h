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
#include "gestione_file.h"
#include "visualizzazione.h"


/**@brief
 *
 * Funzione incaricata di gestire l'input di dati riguardanti i gadget.
 * @param[OTPUT] esito: int
 * @retval "1" Se l'inserimento e' stato completato.
 * @retval "0" Se si e' presentato un errore.
 */
int registrazione_gadget();
/**@brief
 *
 * Procedura che a seconda del valore del parametro "scelta" e del codice gadget (entrambi inseriti da tastiera), modifica un determinato parametro del gadget: nome (1), descrizione (2), colore (3), prezzo (4),giacenza (5). La funzione utilizza "restituisci_gadget" per ricavare la struct da modificare, la quale verra' modificata e inserita nel file "file_gadget". Verra' inoltre invocata la funzione "modifica_gadget" per la modifica del prezzo o delle giacenze.
 */
void modifica_gadget_utente();
/**@brief
 *
 * Procedura che a seconda del valore del parametro "scelta" inserito da tastiera, chiama la funzione ricerca_gadget nelle seguenti modalita': ricerca per nome(0), ricerca per codice(1), ricerca per colore(2).
 */
void effettua_ricerca();
/**@brief
 *
 * Funzione che a seconda del valore del parametro "scelta" e del codice gadget , modifica un determinato parametro del gadget: quantita (o), prezzo(1), venduti(2). verra' dunque modificata la struct xgadget e inserita nel file "file_gadget".
 * @param[INPUT] xgadget: gadget_t
 * @param[INPUT] valore: float
 * @param[INPUT] scelta: int
 * @param[OTPUT] esito: int
 * @retval "0" Se l'inserimento e' stato completato.
 * @retval "1" Se si e' presentato un errore.
 */
int modifica_gadget(gadget_t xgadget,float valore, int scelta);





#endif /* GESTIONE_GADGET_H_ */
