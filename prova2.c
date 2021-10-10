#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define dim 100

void caricamento(int vet[dim]){
    int val;
    srand(time(NULL));
    for(int i=0;i<dim;i++){
        // printf("Quale valore? ");
        // scanf("%d",&val);
        // vet[i]=val;
        vet[i]=rand()%50+1;
    }    
}

void stampa(int vet[dim], int dimensione){
    for(int i=0; i<dimensione; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int somma(int vet[dim]){
    int somma=0;
    int i=0;
    while(i<dim){
        somma+=vet[i];
        i++;
    }
    // for(int i=0;i<dim;i++)
    //     somma+=vet[i];
    return somma;
}

void conta(int vet[dim]){
    int i;
    int cont=0;
    int posizione[dim];
    for(i=0;i<dim;i++){
        if(vet[i]==17){
            posizione[cont]=i;
            cont++;
        }
            
    }
    printf("Gli elementi uguali a 17 sono: %d\n e si trovano in posizione ", cont);
    stampa(posizione, cont);
}


int main(){
    int vet[dim];
    int sommavettore; 
    caricamento(vet);   //procedure
    stampa(vet,dim);
    sommavettore=somma(vet);
    printf("\nLa somma e\' uguale a: %d\n",sommavettore);
    conta(vet);
}