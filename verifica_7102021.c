#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define dim 50

void carica(int vet[dim]){
    int i;
    for(i=0;i<dim;i++)
        vet[i]=rand()%100+1;
}

void stampa(int vet[dim]){
    int i;
    for(i=0;i<dim;i++)
        printf("%d ",vet[i]);
}

int somma(int vet[dim]){
    int sum=0;
    int i;
    for(i=0;i<dim;i++)
        sum+=vet[i];
    return sum;
}

int conta(int vet[dim]){
    int i=0;
    int cont=0;
    for(i=0;i<dim;i++){
        if(vet[i]==17)
            cont++;
    }
    return cont;
}

int main(){
    int a[dim];
    int sum, cont;
    srand(time(NULL));
    carica(a);
    stampa(a);
    sum=somma(a);
    printf("\nLa somma di tutti gli elementi del vettore e\': %d\n",sum);
    cont=conta(a);
    printf("Nel vettore ci sono %d valori uguali a 17\n",cont);
}