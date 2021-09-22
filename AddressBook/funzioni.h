#ifndef FUNZINONI.H
#define FUNZIONI.H

// DICHIARAZIONE DI FUNZIONI
//Contatto* newContatto(char *via, char *citta, char *prov, int CAP, int nc, char *nome, char *cognome, unsigned long long num);
//Contatto* newContatto0();
void newContattoC(Contatto* x, char* stringa);
Lista* newLista();
void aggiungi(Lista *lista, Contatto *nuovo);
_Bool isEqualS(char* str1, char* str2);
Contatto* cerca(Lista *lista, char *nome, char *cognome);
void rimuovi(Lista* lista, char *nome, char *cognome);
void toString(Contatto* cont);

#endif
