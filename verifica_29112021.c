#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//definizione dei valori assegnati come costanti globali
#define MINIMO 65
#define MASSIMO 137
#define CERCA 81

void creaFile()
{
    FILE *fp;        //puntatore al file
    int numeroRighe; //contiene il numero di righe
    int numero;      //contiene il numero da salvare nel file
    srand(time(NULL));

    numeroRighe = rand() % 500 + 10;               //numero di righe sufficientemente grande per contenere dei multipli di 65
    if ((fp = fopen("verifica.txt", "w")) != NULL) //controllo della corretta creazione del file in scrittura
    {
        for (int i = 0; i < numeroRighe; i++)
        {
            numero = rand() % (MASSIMO - MINIMO + 1) + MINIMO; //generazione di un numero casuale nell'intervallo 65-137
            fprintf(fp, "%d\n", numero);                       //salvataggio su file del numero generato
        }
        fclose(fp); //chiusura del file
    }
    else
        printf("Non sono riuscito a creare il file");
}

void leggiMultipli()
{
    FILE *fp;   //puntatore al file
    int numero; //contiene il numero da leggere nel file

    if ((fp = fopen("verifica.txt", "r")) != NULL) //controllo della corretta apertura del file in lettura
    {
        printf("I multipli di %d nel file sono:\n", MINIMO);
        do
        {
            fscanf(fp, "%d", &numero);  //prelevo dal file un valore
            if (numero % MINIMO == 0)   //controllo che sia multiplo di 65
                printf("%d\t", numero); //stampo a video tale valore
        } while (!feof(fp));            //ciclo fino alla fine del file
        fclose(fp);                     //chiusura del file
    }
    else
        printf("Non sono riuscito ad aprire il file\n");
}

int leggiConta()
{
    FILE *fp;      //puntatore al file
    int count = 0; //contatore
    int numero;    //contiene il numero da leggere nel file

    if ((fp = fopen("verifica.txt", "r")) != NULL) //controllo della corretta apertura del file in lettura
    {
        do
        {
            fscanf(fp, "%d", &numero); //prelevo dal file un valore
            if (numero == CERCA)       //controllo che il numero sia uguale a quello da cercare
                count++;               //conto
        } while (!feof(fp));           //ciclo fino alla fine del file
        fclose(fp);                    //chiusura del file
    }
    else
        printf("Non sono riuscito ad aprire il file\n");
    return count;
}

void contaRighe()
{
    FILE *fp, *fp1;  //puntatori ai file, il primo il lettura, il secondo in scrittura
    int cont = 0;    //contatore
    char numero = 0; //contiene il carattere preso dal file

    if ((fp = fopen("verifica.txt", "r")) != NULL) //controllo della corretta apertura del file in lettura
    {
        while (!feof(fp)) //ciclo fino alla fine del file
        {
            fscanf(fp, "%c", &numero); //prelevo l'ultimo carattere della riga (ovvero /n)
            if (numero == '\n')        //controllo che sia un fine riga (altrimenti significa che sono arrivato alla fine del file perchè i numeri sono salvati come %d\n)
            {
                cont++; //conto
            }
        }
        if ((fp1 = fopen("mamaci.txt", "w")) != NULL) //controllo della corretta creazione del file in scrittura
        {
            fprintf(fp1, "Nel file sono presenti %d righe", cont); //stampo sul file il numero di righe del primo file
            fclose(fp1);                                           //chiudo il file
        }
        else
            printf("Non sono riuscito a creare il file");
        fclose(fp); //chiusura del file
    }
    else
        printf("Non sono riuscito ad aprire il file\n");
}

int main()
{
    creaFile();
    leggiMultipli();
    printf("\nNel file ci sono %d valori uguali a %d\n", leggiConta(), CERCA);
    contaRighe();
}