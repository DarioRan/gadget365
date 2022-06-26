/*
 * gestione_file.h
 *
 *  Created on: 9 giu 2022
 *      Author: ranie
 */

#ifndef GESTIONE_FILE_H_
#define GESTIONE_FILE_H_

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "strutture.h"
#include "visualizzazione.h"

#define FILE_CLIENTI "clienti.csv"
#define FILE_ORDINI "ordini.csv"
#define FILE_GADGET "gadget.csv"



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
 * La procedura ha come input una stringa "ricerca" contenente il nome/colore/codice del gadget da cui visualizzare le informazioni. A seconda del contenuto del parametro "scelta", la ricerca avverra' per nome (0) codice(1) o colore(2). La funzione visualizzera' ogni record nel file "file_gadget" che avra' in comune una sottostringa con il parametro dato in input.
 * @param[INPUT] ricerca: char[50]
 * @param[INPUT] scelta: int
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
/**@brief
 * Funzione che avendo come input una stringa "gadget" contenente il codice del gadget da cancellare, legge ogni record presente nel file "file_gadget" assegnandoli ad una struct di appoggioed in seguito riscrivendoli su un secondo file. Il record che avra' lo stesso codice del parametro dato in input non verra' riscritto. Verra' in seguito cancellato il vecchio "file_gadget" e verra' rinominato in "file_gadget" il nuovo file.
 * @param[INPUT] gadget: char[6]
 * @param[OTPUT] esito: int
 * @retval "1" Se l'inserimento e' stato completato.
 * @retval "0" Se si e' presentato un errore.
 */
int cancella_gadget(char* gadget);
/**@brief
 * Funzione che avendo come input una stringa "username" contenente l'username dell'utente da cancellare, legge ogni record presente nel file "file_clienti" assegnandoli ad una struct di appoggio ed in seguito riscrivendoli su un secondo file. Il record che avra' lo stesso username del parametro dato in input non verra' riscritto. Verra' in seguito cancellato il vecchio "file_clienti" e verra' rinominato in "file_clienti" il nuovo file.
 * @param[INPUT] username: char[50]
 * @param[OTPUT] esito: int
 * @retval "1" Se l'inserimento e' stato completato.
 * @retval "0" Se si e' presentato un errore.
 */
int cancella_cliente(char* username);
/**@brief
 * Procedura che avendo come input una stringa "username" contenente l'username dell'utente di cui visualizzare gli ordini, legge ogni record presente nel file "file_ordini" assegnandoli ad una struct di appoggio. Se il nome dell'ordine contenuto nella struct di appoggio e' uguale al parametro dato in input allora verranno visualizzati le informazioni di quell'ordine.
 * @param[INPUT] username: char[50]
 */
void visualizza_ordini_cliente(char* username);
/**@brief
 * Procedura che visualizza tutti i gadget presenti nel file "file_gadget".
 */
void restituisciALL_gadget();
/**@brief
 * Procedura che leggendo tutti i gadget presenti nel file "file_gadget" e assegnandoli ad una struct di appoggio, memorizza in 3 variabili d'appoggio i gadget con il valore piu' alto nel parametro "venduti" in maniera decrescente. Infine essi vengono visualizzati.
 */
void visualizza_piu_venduti();
/**@brief
 * La funzione ha come input (per riferimento) una struct ordine_t "risultato_ordine" e una stringa "codice_ordine" contenente il codice dell' ordine da cui ottenere le informazioni. La funzione legge ogni record contenente nel file "file_ordini" assegnando il valore letto a una struct ordine_t di appoggio, comparando il codice della struct ottenuta con quello da ricercare, finche' esso non viene trovato. Una volta trovato, la funzione interrompe la lettura, assegna la struct di appoggio a "risultato_ordine" e ritorna un valore pari ad "1".
 * @param[INPUT] codice_ordine: char[50]
 * @param[INPUT] *risultato_ordine: ordine_t
 * @param[OTPUT] trovato: int
 * @retval "1" Se l'inserimento e' stato completato.
 * @retval "0" Se si e' presentato un errore.
 */
int restituisci_ordine(char* codice_ordine, ordine_t* risultato_ordine);
/**@brief
 * Procedura legge tutti i record presenti nel file "file_ordini" assegnandoli ad una struct ordine_t di appoggio, visualizzando gli ordini che possiedono il parametro stato equivalente a "0". Successivamente inserendo il codice di un ordine puo' decidere se approvarlo (1) o rifiutarlo (2).
 */
void approva_ordini();
/**@brief
 * Funzione che avendo come input una stringa "cod_ordine" contenente il codice dell'ordine da modificare e il parametro "stato" contenente il valore del nuovo stato, legge ogni record presente nel file "file_ordini" assegnandoli ad una struct di appoggio. Il record che avra' lo stesso codice del parametro "cod_ordine" dato in input verra' modificato con il nuovo stato.
 * @param[INPUT] cod_ordine: char[50]
 * @param[INPUT] stato: int
 * @param[OTPUT] esito: int
 * @retval "1" Se l'inserimento e' stato completato.
 * @retval "0" Se si e' presentato un errore.
 */
int modifica_stato_ordine(char* cod_ordine, int stato);

int input_scelta();




#endif /* GESTIONE_FILE_H_ */
