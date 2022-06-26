/*
 * gestione_utente.h
 *
 *  Created on: 17 giu 2022
 *      Author: ranie
 */

#ifndef GESTIONE_UTENTE_H_
#define GESTIONE_UTENTE_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "strutture.h"
#include "gestione_file.h"


#define USERADMIN "admin_365"

#define PASSADMIN "gadget"


/**@brief
 *
 * Funzione incaricata di gestire l'input di dati riguardanti i clienti.
 * @param[OUTPUT] esito: int
 * @retval "1" Se l'inserimento e' stato completato.
 * @retval "0" Se si e' presentato un errore.
 */
int registrazione_cliente();
/**@brief
 *
 * Funzione incaricata di gestire il log-in utente. Se le credenziali date in input sono equivalenti a quelle dell'admin allora verra' restituito il valore "2", altrimenti utilizzando la funzione "restituisci_cliente", si controlla se e' presente un cliente nel file "file_clienti" con determinate credenziali. Se le credenziali sono corrette, verra' restituito il valore "1".
 * @param[INPUT] username: char[50]
 * @param[INPUT] pass: char[50]
 * @param[OUTPUT] esito_accesso: int
 * @retval "2" Se l'inserimento e' stato completato da gestore.
 * @retval "1" Se l'inserimento e' stato completato da cliente.
 * @retval "0" Se si e' presentato un errore.
 */
int accesso_cliente(char username[CARATTERI], char pass[CARATTERI]);
/**@brief
 *
 * Procedura incaricata di gestire la modifica utente. A seconda del valore del parametro "scelta" inserito da tastiera verranno modificati diversi parametri: p.iva (1), rag. sociale (2), citta' (3). Tramite la stringa "username_corrente" data in input siamo in grado, tramite la funzione "restituisci_cliente" di risalire al cliente da modificare. Una volta ottenuta la struct del cliente da modificare verra' modificato il parametro desiderato in una struct di appoggio e verra' cancellato il record dal file, in seguito verra' dunque caricato il record con la struct aggiornata.
 * @param[INPUT] username_corrente: char[50]
 */
void modifica_cliente(char username_corrente[CARATTERI]);




#endif /* GESTIONE_UTENTE_H_ */
