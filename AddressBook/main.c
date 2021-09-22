#include <stdio.h>
#include "funzioni.c"
#include "stream.c"

int main(void) {

    // DICHIARAZIONI - variabili operative
    Lista *lista = newLista();
    char via[CH];
    char citta[CH];
    char prov[PR];
    int CAP, nc;
    unsigned long long num;
    char nome[CH], cognome[CH];
    int comando = 0;

    // EVER GREEN
    while (comando != 5) {

        // Inserimento comando da eseguire
        puts("Premi 1 per AGGIUNGERE un contatto in rubrica");
        puts("Premi 2 per MODIFICARE un contatto della rubrica");
        puts("Premi 3 per RIMUOVERE un contatto dalla rubrica");
        puts("Premi 4 per LEGGERE un contatto della rubrica");
        puts("Premi 5 per USCIRE\n");
        scanf("%d", &comando);

        switch (comando) {
            //AGGIUNGERE
            case 1:
                if (lista->cont<MAX) {
                    Contatto* daAggiungere = malloc(sizeof(Contatto));
                    char* stringa = "Inserisci i dati richiesti del contatto da aggiungere";
                    newContattoC(daAggiungere, stringa);

                    aggiungi(lista, daAggiungere);
                    aggiungiF(daAggiungere, lista->cont);
                    puts("Contatto Aggiunto!");
                }
                else puts("La rubrica è piena");

                puts("______________________________________________________\n\n");
                break;

            //MODIFICARE
            case 2:
                puts("\nInserisci nome e cognome del contatto da modificare:");
                printf("%s ", "Nome:"); scanf("%s", nome);
                printf("%s ", "Cognome:"); scanf("%s", cognome);
                printf("%s\n%s\n", nome, cognome); //CONTROLLO

                // cerca contatto
                Contatto* daModificare = cerca(lista, &nome, &cognome);
                if (daModificare != NULL) {
                    char* stringa = "Inserisci i dati rinnovati del contatto";
                    newContattoC(daModificare, stringa);
                    puts("Contatto modificato !");
                }
                else puts("Nominativo non trovato!\n\n");

                puts("______________________________________________________\n\n");
                break;

            //RIMUOVERE
            case 3:
                puts("Inserisci nome e cognome del contatto da rimuovere:");
                printf("%s ", "Nome:"); scanf("%s", nome);
                printf("%s ", "Cognome:"); scanf("%s", cognome);
                rimuovi(lista, &nome, &cognome);

                puts("______________________________________________________\n\n");
                break;

            //LEGGERE
            case 4:
                puts("Inserisci nome e cognome del contatto da leggere:");
                printf("%s ", "Nome:"); scanf("%s", nome);
                printf("%s ", "Cognome:"); scanf("%s", cognome);
                puts("");

                Contatto* leggimi = cerca(lista, &nome, &cognome);
                if (leggimi != NULL)
                    toString(leggimi);
                else puts("Nominativo non trovato!\n\n");

                puts("______________________________________________________\n\n");
                break;

            //USCIRE
            case 5:
                puts("______________________________________________________\n\n");
                break;

            default:
                puts("Inserire un numero valido\n");
                break;
        }
    }
}
