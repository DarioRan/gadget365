/*
 * visualizzazione.h
 *
 *  Created on: 10 giu 2022
 *      Author: ranie
 */

#ifndef VISUALIZZAZIONE_H_
#define VISUALIZZAZIONE_H_

#include <stdlib.h>
#include <stdio.h>
#include "strutture.h"
#include "gestione_file.h"
/**@brief
 *
 * Funzione incaricata di stampare a schermo il menu' principale.
 */
void inizializza_menu();
/**@brief
 *
 * Funzione incaricata di stampare a schermo il menu' clienti.
 */
void visualizza_menu();
/**@brief
 *
 * Funzione incaricata di stampare a schermo il menu' modifica clienti.
 */
void visualizza_menu_modifica();
/**@brief
 *
 * Funzione incaricata di stampare a schermo il menu' gestore.
 */
void visualizza_menu_gestore();
/**@brief
 *
 * Funzione incaricata di stampare a schermo il menu' ricerca.
 */
void visualizza_menu_ricerca();
/**@brief
 *
 * Funzione incaricata di stampare a schermo informazioni riguardanti il gadget.
 */
void visualizza_gadget(gadget_t xgadget);
/**@brief
 *
 * Funzione incaricata di stampare a schermo informazioni riguardanti il cliente.
 */
void visualizza_cliente(cliente_t xcliente);
/**@brief
 *
 * Funzione incaricata di stampare a schermo il menu' modifica gadget.
 */
void visualizza_menu_modifica_gadget();
/**@brief
 *
 * Funzione incaricata di stampare a schermo informazioni basilari riguardanti il gadget.
 */
void visualizza_gadget_recap(gadget_t xgadget);
/**@brief
 *
 * Funzione incaricata di stampare a schermo informazioni riguardanti l'ordine.
 */
void visualizza_ordine_recap(ordine_t xordine);





#endif /* VISUALIZZAZIONE_H_ */
