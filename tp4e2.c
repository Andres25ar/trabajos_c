/*Dada una lista A de N números enteros, que puede contener números repetidos,
calcular el promedio de los números que se encuentran en posiciones impares del
arreglo y crear otra lista B conteniendo los elementos de A que sean mayores al
promedio calculado. Mostrar ambas listas.*/

#include <stdio.h>
#define max 50

typedef int t_Vect [max];

float Calc_Prom_lista (t_Vect, int);
void Carga_Vector_Inc (t_Vect, int*);
void Nuevo_Vector (t_Vect, int, t_Vect, int*, float);
void Mostrar_Vector (t_Vect, int);

int main (void){
    t_Vect A, B;
    int N, tamB;
    float prom;
    Carga_Vector_Inc(A, &N);
    prom=Calc_Prom_lista(A, N);
    Nuevo_Vector(A, N, B, &tamB, prom);
    printf("\nAsi queda conformado el primer vector:\n");
    Mostrar_Vector(A, N);
    printf("\nAsi queda conformado el segundo vector:\n");
    Mostrar_Vector(B, tamB);
    return 0;
}

void Carga_Vector_Inc (t_Vect list, int*tam){
    int i;
    printf("\nIngrese dimension de la lista: ");
    scanf("%d", tam);
    for (i = 1; i<=*tam; i++){
        printf("\nIngrese %dº numero de la lista: ", i);
        scanf("%d", &list[i]);
    }
}

float Calc_Prom_lista (t_Vect V, int N){
    int i, sum, cnt;
    sum=0;
    cnt=0;
    float prom;
    for (i = 1; i <= N; i+=2){
        sum=sum+V[i];
        cnt++;
    }
    prom=(float)sum/cnt;
    return prom;
}

void Nuevo_Vector (t_Vect A, int tamA, t_Vect B, int*tamB, float min){
    int j, t;
    t=0;
    /*tamB=0;*/
    for ( j = 1; j <= tamA; j++){
        if(A[j]>min){
            t++;
            /*tamB++;*/
            B[t]=A[j];
        }
    }
    *tamB=t;
}

void Mostrar_Vector (t_Vect V, int t){
    int i;
    for (i = 1; i <= t; i++)
        printf("\nVect[%d]=%d", i, V[i]);
}