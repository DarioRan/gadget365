/*
 * utiles.c
 *
 *  Created on: 27 giu 2022
 *      Author: ranie
 */
#include "utiles.h"

int input_scelta()
{
	char scelta[CARATTERI];
	char a;
	int scelta_intero;
	fflush(stdin);
	scanf("%s",scelta);
	while(strlen(scelta)>1)
	{
		printf("\n|Inserire scelta valida. \n");
		fflush(stdin);
		printf("\nInserire scelta: ");
		scanf("%s",scelta);
	}
	scelta_intero=(int)scelta[0];
	while(48>=scelta_intero || scelta_intero>=57)
	{
		printf("\n|Inserire scelta valida. \n");
		fflush(stdin);
		printf("\nInserire scelta: ");
		scanf("%s",scelta);
		while(strlen(scelta)>1)
		{
			printf("Inserire scelta valida! \n");
			fflush(stdin);
			scanf("%s",scelta);
		}
		a=scelta[0];
		scelta_intero=(int)a;

	}
	scelta_intero-=48;
	return scelta_intero;


}

void get_stringa(char stringa[CARATTERI])
{
	char c;
	fflush(stdin);
	fgets(stringa, CARATTERI, stdin);
	stringa[strcspn(stringa, "\n")] = 0;



}
