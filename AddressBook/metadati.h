#ifndef METADATI.H

#define METADATI.H
#define MAX 32
#define CH 25
#define PR 3

struct casa {
    char via[CH];
    char citta[CH];
    char prov[PR];
    int CAP;
    int nc;
};

struct dati {
    char nome[CH];
    char cognome[CH];
    unsigned long long num;
};

struct contatto {
    struct casa casa;
    struct dati dati;
    struct contatto *next;
};

struct lista {
    int cont;
    struct contatto *head;
    struct contatto *tail;
};

typedef struct contatto Contatto;
typedef struct lista Lista;

#endif
