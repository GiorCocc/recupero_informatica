#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void carica(int vet[50]){
    int i;
    for(i=0;i<50;i++)
        vet[i]=rand()%100;
}

void stampa(int vet[50]){
    int i;
    for(i=0;i<50;i++)
        printf("%d",vet[i]);
}

int somma(int vet[50]){
    int sum;
    int i;
    for(i=0;i<50;i++)
        sum+=vet[i];
    return sum;
}

int conta(int vet[50]){
    int i=0;
    int cont;
    for(i=0;i<50;i++){
        if(vet[i]==17)
            cont++;
    }
    return cont;
}

int main(){
    int a[50];
    int sum, cont;
    srand(time(NULL));
    carica(a);
    stampa(a);
    sum=somma(a);
    printf("La somma di tutti gli elementi del vettore e\': %d\n",sum);
    cont=conta(a);
    printf("Nel vettore ci sono %d valori uguali a 17\n",cont);
}