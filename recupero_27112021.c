#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carica()
{
    FILE *fp, *fp1;
    int numeroRighe;
    srand(time(NULL));
    if ((fp = fopen("prova.txt", "w")) != NULL)
    {
        numeroRighe = rand() % 255 + 1;
        // printf("%d", numeroRighe);
        for (int i = 0; i < numeroRighe; i++)
        {
            int numeroCasuale = rand() % 50 + 1;
            if (numeroCasuale % 11 == 0)
                fprintf(fp, "%d\n", numeroCasuale);
            else
            {
                if ((fp1 = fopen("prova1.txt", "a")) != NULL)
                {
                    fprintf(fp1, "%d\n", numeroCasuale);
                }
                fclose(fp1);
            }
        }
        fclose(fp);
    }
}

int contaRighe()
{
    FILE *fp;          //puntatore al file
    int cont = 0;      //contatore per le righe
    int carattere = 0; //variabile per la lettura dela carattere contenuto nella riga letta (sottoforma di codice ASCII)

    if ((fp = fopen("prova1.txt", "r")) != NULL) //apertura del file in lettura
    {
        while (!feof(fp)) //controllo che il file non sia finito
        {
            carattere = fgetc(fp); //prelevo il primo carattere letto nella riga
            if (carattere == '\n') //controllo che non sia un ritorno a capo
            {
                cont++; //conto a che riga sono arrivato
            }
        }
        fclose(fp); //chiusura del file
    }
    else
        printf("Non sono riuscito ad aprire il file\n");
    return cont;
}

void leggi()
{
    FILE *fp;
    int a;
    int numeroRighe = contaRighe();
    int cont3, cont5, cont7 = 0;
    if ((fp = fopen("prova1.txt", "r")) != NULL)
    {
        for (int i = 0; i < numeroRighe; i++)
        {
            fscanf(fp, "%d", &a);
            if (a % 3 == 0)
                cont3++;
            else if (a % 5 == 0)
                cont5++;
            else if (a % 7 == 0)
                cont7++;
        }
    }
    fclose(fp);
    printf("I multipli di 3 sono: %d\n", cont3);
    printf("I multipli di 5 sono: %d\n", cont5);
    printf("I multipli di 7 sono: %d\n", cont7);
}

int main()
{
    carica();
    leggi();
}