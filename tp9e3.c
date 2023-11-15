/*Retomar el ejercicio 2 agregando un menú que permita seleccionar las operaciones b) y c) y además
las siguientes:
d) Modificar cada número primo, transformándolo en negativo;
e) Insertar, en la lista, delante de cada número par, el número cero*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo{
    int dato;
    struct nodo * sig;
}T_nodo;
typedef T_nodo * T_ptr;

void opciones (void);
void Menu_Recursivo (T_ptr*);
void Carga_Lista (T_ptr *);
T_ptr Carga_Nodo (void);
void Mostrar_Lista (T_ptr);
void Mostrar_Dado_x (T_ptr, int);
void Agrega_ppio (T_ptr*, T_ptr);
void Agrega_fin (T_ptr*, T_ptr);
void Cambia_Primos (T_ptr*);
void Agrega_Cero (T_ptr*);
int Det_Primo (int);

int main (void){
    T_ptr A;
    A=NULL;
    srand(time(NULL));
    Carga_Lista(&A);
    Menu_Recursivo(&A);
    /*Mostrar_Lista(A);
    printf("\nIngrese un valor minimo para mostrar: ");
    scanf("%d", &x);
    Mostrar_Dado_x(A, x);*/
    return 0;
}

void opciones (void){
    printf("\n=======Menu de opciones========");
	printf("\nIngrese 1: mostrar la lista");
	printf("\nIngrese 2: mostrar la lista dado un valor x");
	printf("\nIngrese 3: transformar los primos en negativos");
	printf("\nIngrese 4: colocar 0 antes de cada entero par");
	printf("\nIngrese 0: para salir del MENU");
}

void Menu_Recursivo (T_ptr*A){
    int rta, x;
    opciones();
    scanf("%d", &rta);
    switch (rta){
    case 1:
        if(*A!=NULL)
            Mostrar_Lista(*A);
        else
            printf("\nLista Vacia");
        Menu_Recursivo(A);
        break;
    case 2:
        if(*A!=NULL){
            printf("\nIngrese un valor minimo para mostrar: ");
            scanf("%d", &x);
            Mostrar_Dado_x(*A, x);
        }
        else
            printf("\nLista Vacia");
        Menu_Recursivo(A);
        break;
    case 3:
        if(*A!=NULL)
            Cambia_Primos(A);
        else
            printf("\nLista Vacia");
        Menu_Recursivo(A);
        break;
    case 4:
        if(*A!=NULL)
            Agrega_Cero(A);
        else
            printf("\nLista Vacia");
        Menu_Recursivo(A);
        break;
    case 0:
        printf("\nADIOS!");
        break;
    }
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

void Cambia_Primos (T_ptr*L){
    T_ptr aux;
    if(*L!=NULL)
        aux=*L;
        while (aux!=NULL){
            if(Det_Primo(aux->dato)==1)
                aux->dato=-(aux->dato);
            aux=aux->sig;
        }
}

void Agrega_Cero (T_ptr*L){
    T_ptr aux, ant, nvo;
    if (*L!=NULL){
        aux=*L;
        ant=NULL;
        while (aux!=NULL){
            if (aux->dato%2==0){
                nvo=(T_ptr)malloc(sizeof(T_nodo));
                nvo->dato=0;
                nvo->sig=NULL;
                if(ant==NULL){
                    nvo->sig=*L;
                    *L=nvo;
                }
                else{
                    nvo->sig=aux;
                    ant->sig=nvo;
                }
            }
            ant=aux;
            aux=aux->sig;
        }
    }
}

int Det_Primo (int x){
    int r, pd;
    pd=2;
    while (x%pd!=0 && pd<=x/2)
        pd++;
    if(pd>x/2 && x!=1)
        r=1;
    else
        r=0;
    return r;
}