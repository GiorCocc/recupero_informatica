// Fare un programma che preveda le seguenti elaborazioni:
// 1 - Scrivere in un file (procedura) un numero casuale di valori interi (nell'intervallo tra 7 e 70); (punti 2)
// 2 - Lettura del file (funzione) per conoscere quanti valori sono stati inseriti; (punti 2)
// 3 - Lettura del file (funzione) per sommarne tutti i valori; (punti 2)
// 4 - Lettura del file (procedura) per scrivere, in un altro file, i valori multipli di 7; (punti 3)
// La chiamata corretta dei sottoprogrammi nel main vale 1 punto.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scrivi()
{
    FILE *fp;
    int numeroValori; //numero di righe del file
    int numero;
    srand(time(NULL));
    numeroValori = rand() % 50 + 1;

    if ((fp = fopen("numeri_casuali.txt", "w")) != NULL)
    {
        for (int i = 0; i < numeroValori; i++)
        {
            numero = rand() % 70 + 7;
            fprintf(fp, "%d\n", numero);
        }
        fclose(fp);
    }
    else
        printf("Non sono riuscito a creare il file");
}

int contaRighe()
{
    FILE *fp;
    int cont = 0;

    if ((fp = fopen("numeri_casuali.txt", "r")) != NULL)
    {
        do
        {
            cont++;
        } while (!feof(fp));
        fclose(fp);
    }
    else
        printf("NOn sono riuscito ad aprire il file\n");
    return cont;
}

int somma()
{
    FILE *fp;
    int somma = 0;
    int numero;

    if ((fp = fopen("numeri_casuali.txt", "r")) != NULL)
    {
        do
        {
            fscanf(fp, "%d", &numero);
            somma += numero;
        } while (!feof(fp));
        fclose(fp);
    }
    else
        printf("Non sono riuscito ad aprire il file\n");
    return somma;
}

void multipliSette()
{
    FILE *fp1, *fp2;
    int numero;

    if ((fp1 = fopen("numeri_casuali.txt", "r")) != NULL)
    {
        if ((fp2 = fopen("multipli7.txt", "w")) != NULL)
        {
            do
            {
                fscanf(fp1, "%d", &numero);
                if ((numero % 7) == 0)
                    fprintf(fp2,"%d\n", numero);
            } while (!feof(fp1));
            fclose(fp2);
        }
        else
            printf("Non sono riuscito a creare il file\n");

        fclose(fp1);
    }
    else
        printf("Non sono riuscito ad aprire il file con i numeri casuali\n");
}

int main()
{
    int numeroRighe;
    int sommaFile;
    scrivi();
    // numeroRighe = contaRighe();
    // if (numeroRighe == -1)
    //     printf("Non sono riuscito a contare le righe\n");
    // else
    //     printf("Il numero di righe e\': %d\n", numeroRighe);
    printf("la somma e\': %d\n", somma());
    multipliSette();
}