#include <stdio.h>
#include "metadati.h"

void aggiungiF(Contatto* x, int cont) {
    char mod;
    FILE *file;
    if (cont == 8)
        file = fopen("RUBRICA.TXT", "w");
    else
        file = fopen("RUBRICA.TXT", "a");

    if (file != NULL) {
        fprintf(file, "CONTATTO %d\n", cont);
        fprintf(file, "%s: \t\t%s\n","Nome", x->dati.nome);
        fprintf(file, "%s: \t%s\n","Cognome", x->dati.cognome);
        fprintf(file, "%s: \t%u\n","Telefono", x->dati.num);
        fprintf(file, "%s: \t\t%s\n", "Citta", x->casa.citta);
        fprintf(file, "%s: \t%s\n", "Provincia", x->casa.prov);
        fprintf(file, "%s: \t\t%d\n", "CAP", x->casa.CAP);
        fprintf(file, "%s: \t%s, %d\n\n", "Indirizzo", x->casa.via, x->casa.nc);

        fclose(file);
    }
    else { puts("Errore creazione file"); }
}

/** NON HO VOGLIA DI FARE IL RESTO */
