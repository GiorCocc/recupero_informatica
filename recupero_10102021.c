//correzione della verifica del 7 ottobre 2021
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define dim 100

//procedura per il caricamento di un vettore con valori interi compresi tra 1 e 100
void caricamento(int vet[dim]){
    // int val;
    srand(time(NULL));
    for(int i=0;i<dim;i++){
        // possibilità di caricare il vettore con valori scelti dall'utente
        // printf("Quale valore? ");
        // scanf("%d",&val);
        // vet[i]=val;
        vet[i]=rand()%100+1;
    }    
}

//procedura per la stampa del vettore (modificata per stampare anche vettori di lunghezza diversa)
void stampa(int vet[dim], int dimensione){
    for(int i=0; i<dimensione; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

//funzione per la somma di tutti gli elementi del vettore 
int somma(int vet[dim]){
    int somma=0;
    int i=0;
    while(i<dim){
        somma+=vet[i];
        i++;
    }
    //alternativa per l'esecuzione della somma con lo scorrimento del vettore con un ciclo while
    // for(int i=0;i<dim;i++)
    //     somma+=vet[i];
    return somma;
}

// procedura per il conteggio di tutti gli elementi uguali a 17 
// bonus: salvataggio in un vettore di cont elementi delle posizioni dei singoli elementi
void conta(int vet[dim]){
    int i;
    int cont=0;
    int posizione[dim]; //parte dell'esercizio bonus
    for(i=0;i<dim;i++){
        if(vet[i]==17){
            posizione[cont]=i;  //salvataggio nel vettore posizione in indice count della posizione dell'elemento uguale a 17
            cont++;
        }
            
    }
    printf("Gli elementi uguali a 17 sono: %d\ne si trovano in posizione ", cont);
    stampa(posizione, cont); //stampa del vettore delle posizioni
}


int main(){
    int vet[dim];
    int sommavettore; 
    caricamento(vet);   //chiamata di una procedura
    stampa(vet,dim);    //chiamata di una procedura
    sommavettore=somma(vet); //chiamata di una funzione
    printf("\nLa somma e\' uguale a: %d\n",sommavettore);
    conta(vet);
}