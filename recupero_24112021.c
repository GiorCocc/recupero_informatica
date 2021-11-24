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
    FILE *fp;        //puntatore al file (spazio in memoria)
    int numeroRighe; //numero di righe del file
    int numero;      //numero che si vuole inserire
    srand(time(NULL));
    numeroRighe = rand() % 50 + 1; //numero casuale di righe nel file

    if ((fp = fopen("numeri_casuali.txt", "w")) != NULL) //creazione di un file in scrittura e controllo dell'avvenuta operazione
    {
        for (int i = 0; i < numeroRighe; i++)
        {
            numero = rand() % 70 + 7;    //creazione di un numero casuale
            fprintf(fp, "%d\n", numero); //stampa nel file del numero appena creato
        }
        fclose(fp); //chiusura del file
    }
    else
        printf("Non sono riuscito a creare il file");
}

int contaRighe()
{
    FILE *fp;          //puntatore al file
    int cont = 0;      //contatore per le righe
    int carattere = 0; //variabile per la lettura dela carattere contenuto nella riga letta (sottoforma di codice ASCII)

    if ((fp = fopen("numeri_casuali.txt", "r")) != NULL) //apertura del file in lettura
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

int somma()
{
    FILE *fp;      //puntatore al file
    int somma = 0; //variabile che contiene la somma
    int numero;    //contiene il numero letto nella riga

    if ((fp = fopen("numeri_casuali.txt", "r")) != NULL) //apertura del file in lettura
    {
        do
        {
            fscanf(fp, "%d", &numero); //prelevo il numero dalla riga...
            somma += numero;           //...lo sommo agli altri valori
        } while (!feof(fp));           //controllo che non sia alla fine del file per ricominciare il processo
        fclose(fp);                    //chiusura del file
    }
    else
        printf("Non sono riuscito ad aprire il file\n");
    return somma;
}

void multipliSette()
{
    FILE *fp1, *fp2; //puntatori a due file
    int numero;      //contiene il numero che voglio controllare

    if ((fp1 = fopen("numeri_casuali.txt", "r")) != NULL) //apertura in lettura del primo file
    {
        if ((fp2 = fopen("multipli7.txt", "w")) != NULL) //creazione del secondo file
        {
            do
            {
                fscanf(fp1, "%d", &numero);       //prelevo il numero dalla riga...
                if ((numero % 7) == 0)            //...controllo che sia un multiplo di 7....
                    fprintf(fp2, "%d\n", numero); //...stampare sul secondo file il numero
            } while (!feof(fp1));                 //controllo che non sia alla fine del file per ricominciare il processo
            fclose(fp2);                          //chiusura del secondo file
        }
        else
            printf("Non sono riuscito a creare il file\n");

        fclose(fp1); //chiusura del primo file
    }
    else
        printf("Non sono riuscito ad aprire il file con i numeri casuali\n");
}

int main()
{
    int numeroRighe;

    scrivi();
    numeroRighe = contaRighe();

    if (numeroRighe == -1)
        printf("Non sono riuscito a contare le righe\n");
    else
        printf("Il numero di righe e\': %d\n", numeroRighe);

    printf("la somma e\': %d\n", somma());
    multipliSette();
}