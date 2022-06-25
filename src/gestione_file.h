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
/**@brief
 *
 * Procedura incaricata di aprire i file del programma, comunicando eventualmente delle criticita'.
 *
 */
void apertura_file();
/**@brief
 * Funzione che avendo come input una struct gadget_t, inserisce un record nel file "file_gadget". Ritorna come valore "1" se e' stato inserito con successo.
 * @param[INPUT] xgadget: gadget_t
 * @param[OTPUT] esito: int
 * @retval "1" Se l'inserimento e' stato completato.
 * @retval "0" Se si e' presentato un errore.
 */
int inserisci_gadget(gadget_t xgadget);
/**@brief
 * Funzione che avendo come input una struct cliente_t, inserisce un record nel file "file_clienti". Ritorna come valore "1" se e' stato inserito con successo.
 * @param[INPUT] xcliente: cliente_t
 * @param[OTPUT] esito: int
 * @retval "1" Se l'inserimento e' stato completato.
 * @retval "0" Se si e' presentato un errore.
 */
int inserisci_cliente(cliente_t xcliente);
/**@brief
 * Funzione che avendo come input una struct ordine_t, inserisce un record nel file "file_ordini". Ritorna come valore "1" se e' stato inserito con successo.
 * @param[INPUT] xordine: ordine_t
 * @param[OTPUT] esito: int
 * @retval "1" Se l'inserimento e' stato completato.
 * @retval "0" Se si e' presentato un errore.
 */
int inserisci_ordine(ordine_t xordine);
/**@brief
 * La funzione ha come input (per riferimento) una struct cliente_t "risultato_cliente" e una stringa "ricerca" contenente il nome del cliente da cui ottenere le informazioni. La funzione legge ogni record contenente nel file "file_utenti" assegnando il valore letto a una struct cliente_t di appoggio, comparando il nome della struct ottenuta con quello da ricercare, finche' esso non viene trovato. Una volta trovato, la funzione interrompe la lettura, assegna la struct di appoggio a "risultato_cliente" e ritorna un valore pari ad "1".
 * @param[INPUT] ricerca: char[50]
 * @param[INPUT] *risultato_cliente: cliente_t
 * @param[OTPUT] trovato: int
 * @retval "1" Se l'inserimento e' stato completato.
 * @retval "0" Se si e' presentato un errore.
 */
int restituisci_cliente(char ricerca[CARATTERI], cliente_t* risultato_cliente );
/**@brief
 * La funzione ha come input una stringa "ricerca" contenente il nome/colore/codice del gadget da cui visualizzare le informazioni.
 * @param[INPUT] ricerca: char[50]
 * @param[INPUT] scelta:int
 */
void ricerca_gadget(char ricerca[CARATTERI], int scelta );
/**@brief
 * La funzione ha come input (per riferimento) una struct gadget_t "risultato_gadget" e una stringa "ricerca" contenente il nome del gadget da cui ottenere le informazioni. A seconda del valore del parametro "scelta", la ricerca puo' avvenire per nome(0) o per codice(1). La funzione legge ogni record contenente nel file "file_gadget" assegnando il valore letto a una struct gadget_t di appoggio, comparando il nome o il codice della struct ottenuta con quello da ricercare, finche' esso non viene trovato. Una volta trovato, la funzione interrompe la lettura, assegna la struct di appoggio a "risultato_gadget" e ritorna un valore pari ad "1".
 * @param[INPUT] ricerca: char[50]
 * @param[INPUT] *risultato_gadget: gadget_t
 * @param[INPUT] scelta: int
 * @param[OTPUT] trovato: int
 * @retval "1" Se l'inserimento e' stato completato.
 * @retval "0" Se si e' presentato un errore.
 */
int restituisci_gadget(char ricerca[CARATTERI], gadget_t* risultato_gadget, int scelta );
int cancella_gadget(char gadget[CARATTERI]);
int cancella_cliente(char* username);
void visualizza_ordini_cliente(char* username);
void restituisciALL_gadget();
void visualizza_piu_venduti();
int modifica_stato_ordine(char* cod_ordine, int stato);






#endif /* GESTIONE_FILE_H_ */
