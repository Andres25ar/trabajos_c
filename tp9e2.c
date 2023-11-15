/*Escribir un programa que cree una lista enlazada considerando lo siguiente:
a) La lista debe ser de números enteros positivos al azar, respetando el criterio de que, si el
número es par se agrega al principio de la lista y si es impar se agrega al final de la lista.
b) Recorrer la lista para mostrar los elementos por pantalla.
c) Mostrar todos los números que superen un valor determinado*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo{
    int dato;
    struct nodo * sig;
}T_nodo;
typedef T_nodo * T_ptr;

void Carga_Lista (T_ptr *);
T_ptr Carga_Nodo (void);
void Mostrar_Lista (T_ptr);
void Mostrar_Dado_x (T_ptr, int);
void Agrega_ppio (T_ptr*, T_ptr);
void Agrega_fin (T_ptr*, T_ptr);

int main (void){
    T_ptr A;
    int x;
    A=NULL;
    srand(time(NULL));
    Carga_Lista(&A);
    Mostrar_Lista(A);
    printf("\nIngrese un valor minimo para mostrar: ");
    scanf("%d", &x);
    Mostrar_Dado_x(A, x);
    return 0;
}

T_ptr Carga_Nodo (void){
    T_ptr p;
    p=(T_ptr)malloc(sizeof(T_nodo));
    p->dato=rand()%(1-16000+1)+1;
    p->sig=NULL;
    return p;
}

void Carga_Lista (T_ptr *L){
    int n, i;
    T_ptr aux;
    printf("\nIngrese tamanio de la lista: ");
    scanf("%d", &n);
    for (i=1; i<=n; i++){
        aux=Carga_Nodo();
        if(aux->dato%2==0)
            Agrega_ppio(L, aux);
        else
            Agrega_fin(L, aux);
    }
}

void Agrega_ppio (T_ptr*L, T_ptr ndo){
    T_ptr aux;
    if(*L==NULL)
        *L=ndo;
    else{
        aux=*L;
        ndo->sig=aux;
        *L=ndo;
    }
}

void Agrega_fin (T_ptr*L, T_ptr ndo){
    T_ptr aux;
    if(*L==NULL)
        *L=ndo;
    else{
        aux=*L;
        while (aux->sig!=NULL)
            aux=aux->sig;
        aux->sig=ndo;
    }
}

void Mostrar_Lista (T_ptr L){
    /*T_ptr aux;*/
    while (L!=NULL){
        printf("\n%d", L->dato);
        L=L->sig;
    }
}

void Mostrar_Dado_x (T_ptr L, int x){
    while (L!=NULL){
        if (L->dato > x)
            printf("\n%d", L->dato);
        L=L->sig;
    }
}