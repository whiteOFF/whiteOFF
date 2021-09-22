#include <stdio.h>
#include "metadati.h"
#include "funzioni.h"

// CONTATTO COSTRUTTORI NON UTILE
/*Contatto* newContatto(char *via, char *citta, char *prov, int CAP, int nc, char *nome, char *cognome, unsigned long long num) {
    Contatto *nuovo = malloc(sizeof(Contatto));

    strncpy( &(nuovo->casa.via), via, CH);
    strncpy( &(nuovo->casa.citta), citta, CH);
    strncpy( &(nuovo->casa.prov), prov, PR);

    nuovo->casa.CAP = CAP;
    nuovo->casa.nc = nc;

    strncpy( &(nuovo->dati.nome), nome, CH);
    strncpy( &(nuovo->dati.cognome), cognome, CH);

    nuovo->dati.num = num;
    nuovo->next = NULL;

    return nuovo;
}
Contatto *newContatto0() { return newContatto(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL); }
*/

void newContattoC(Contatto* x, char* stringa) {
    puts(stringa);
    printf("%s ", "Nome:");scanf("%s", x->dati.nome);
    printf("%s ", "Cognome:"); scanf("%s", x->dati.cognome);
    printf("%s ", "Telefono:"); scanf("%u", &(x->dati.num));
    printf("%s ", "Citta':"); scanf("%s", x->casa.citta);
    printf("%s ", "Provincia:"); scanf("%s", x->casa.prov);
    printf("%s ", "CAP:"); scanf("%d", &(x->casa.CAP));
    printf("%s ", "Via:"); scanf("%s", x->casa.via);
    printf("%s ", "Numero civico:"); scanf("%d", &(x->casa.nc));
}

Lista* newLista() {
    Lista *nuova = malloc(sizeof(Lista));
    nuova->cont = 0;
    nuova->head = NULL;
    nuova->tail = NULL;
    return nuova;
}

void aggiungi(Lista *lista, Contatto *nuovo) {
    if (lista->cont == 0) {
        lista->head = nuovo;
        lista->cont++;
    } else if (lista->cont == 1) {
        lista->tail = nuovo;
        lista->head->next = lista->tail;
        lista->cont++;
    } else {
        lista->tail->next = nuovo;
        lista->tail = nuovo;
        lista->cont++;
    }
}

_Bool isEqual(char* str1, char* str2) {
    int len1=0, len2=0;

    while (str1[len1]!='\0')
        len1++;
    while (str2[len2]!='\0')
        len2++;

    if (len1 != len2)
        return 0;
    else {
        _Bool flag = 1;
        for (size_t i=0; i<len1; i++)
            if (str1[i] != str2[i])
                flag = 0;
        return flag;
    }
}

// cerca
Contatto* cerca(Lista *lista, char* nome, char* cognome) {
    if (lista->cont == 0)
        return NULL;

    else if (lista->cont == 1) {
        if (isEqual(&(lista->head->dati.nome), nome) && isEqual(&(lista->head->dati.cognome), cognome))
            return lista->head;
        else return NULL;
    } else {
        int contatore = 0;
        Contatto *cursore = lista->head;

        while ((!(isEqual(&(cursore->dati.nome), nome)) && isEqual(&(cursore->dati.cognome), cognome)) && contatore < lista->cont - 1){
            cursore = cursore->next;
            contatore++;
        }
        if (contatore < lista->cont)
            return cursore;
        else return NULL;
    }
}

void rimuovi(Lista* lista, char *nome, char *cognome) {
    if (lista->cont == 0)
        return;

    else if (lista->cont == 1 && isEqual(&(lista->head->dati.nome), nome) && isEqual(&(lista->head->dati.cognome), cognome)) {
        free(lista->head);
        lista->cont--;
        puts("Contatto rimosso!");
        }

    else if (lista->cont > 1 && isEqual(&(lista->tail->dati.nome), nome) && isEqual(&(lista->tail->dati.cognome), cognome)) {
        free(lista->tail);
        lista->cont--;
        puts("Contatto rimosso!");
    }

    else {
        int contatore = 0;
        Contatto *cursore = lista->head;

        while ((!(isEqual(&(cursore->next->dati.nome), nome)) && isEqual(&(cursore->next->dati.cognome), cognome)) && contatore<lista->cont - 1){
            cursore = cursore->next;
            contatore++;
        }

        if (contatore < lista->cont - 1) {
            cursore->next = cursore->next->next;
            free(cursore->next);
            lista->cont--;
            puts("Contatto rimosso!");
        }
        else puts("Contatto non trovato");
        }
}

void toString(Contatto* x) {
    puts("Informazioni di contatto.");
    printf("%s: \t\t%s\n", "Nome", x->dati.nome);
    printf("%s: \t%s\n", "Cognome", x->dati.cognome);
    printf("%s: \t%u\n", "Telefono", x->dati.num);
    printf("%s: \t\t%s\n", "Citta", x->casa.citta);
    printf("%s: \t%s\n", "Provincia", x->casa.prov);
    printf("%s: \t\t%d\n", "CAP", x->casa.CAP);
    printf("%s: \t%s, %d\n", "Indirizzo", x->casa.via, x->casa.nc);
    return;
}
