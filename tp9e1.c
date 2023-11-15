/*Cree un programa que declare tres pares ordenados (x,y) en variables de tipo puntero con
asignación de memoria en forma dinámica e indique cual par ordenado retorna el mínimo valor al
ser evaluado en la expresión (x²-10y)*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x, y;
}T_pto;
typedef struct nodo{
    T_pto dato;
    struct nodo * sig;
}T_nodo;
typedef T_nodo * T_ptr;

T_pto Carga_Punto(void);
void Muestra_Punto (T_pto);
T_ptr Carga_Nodo (void);
int Comp_Puntos (T_ptr, T_ptr); /*Comp_Puntos(p1,p2)=-1[si p1>p2], 0[si p1=p2] o 1[si p1<p2]*/
float Reto_x (T_pto);
float Reto_y (T_pto);


int main (void){
    T_ptr A, B, C;
    A=Carga_Nodo();
    B=Carga_Nodo();
    C=Carga_Nodo();
    if (Comp_Puntos(A,B)==1)/*A menor que B*/
        if(Comp_Puntos(A,C)==1)/*A menor que C*/
            Muestra_Punto(A->dato);
        else /*A<B y C<A => C<B*/
            Muestra_Punto(C->dato);
    else /*B menor que A*/
        if(Comp_Puntos(B,C)==1)/*B menor que C*/
            Muestra_Punto(B->dato);
        else /*B<A y C<B => C<A*/
            Muestra_Punto(C->dato);
    return 0;
}

T_pto Carga_Punto(void){
    T_pto p;
    printf("\nIngrese x: ");
    scanf("%f", &p.x);
    printf("\tIngrese y: ");
    scanf("%f", &p.y);
    return p;
}

void Muestra_Punto (T_pto p){
    printf("\n%.2f, %.2f", p.x, p.y);
}

T_ptr Carga_Nodo (void){
    T_ptr ndo;
    ndo=(T_ptr)malloc(sizeof(T_nodo));
    ndo->dato=Carga_Punto();
    ndo->sig=NULL;
    return ndo;
}

int Comp_Puntos (T_ptr p1, T_ptr p2){ /*compara segun: (x²-10y): -1[si p1>p2], 0[si p1=p2] o 1[si p1<p2]*/
    int rta;
    float res1, res2;
    res1=(pow(Reto_x(p1->dato), 2))-10*Reto_y(p1->dato);
    res2=(pow(Reto_x(p2->dato), 2))-10*Reto_y(p2->dato);
    if (res1<res2)
        rta = 1;
    else if (res1==res2)
        rta = 0;
        else
            rta = -1;
    return rta;
}

float Reto_x (T_pto p){
    float a;
    a=p.x;
    return a;
}
float Reto_y (T_pto p){
    float b;
    b=p.y;
    return b;
}
