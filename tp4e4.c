/*Se tiene una lista de las edades de N alumnos de una escuela, se solicita ingresar la lista y a continuación,
mediante un menú:
a) Determinar la edad con mayor cantidad de repeticiones, sabiendo que existe y es única.
b) Mostrar la primera sublista creciente, de al menos dos números, conformada sólo por elementos pares.*/

#include <stdio.h>
#define max 100

typedef int vec[max];

int menu (void);
void Carga_Vector_Inc (vec, int*);
int Mas_Rep (vec, int);
/*void Det_Sublista_Pares (vec, int, int*, int*);
void Mostrar_Sublista (vec, int);*/

int main (){
    int op, tam, rep;
    vec list;
    Carga_Vector_Inc(list, &tam);
    op=menu();
    switch (op){
    case 1:
        rep=Mas_Rep(list, tam);
        printf("\nLa edad mas repetida es: %d", rep);
        break;
    /*case 2:
        Mostrar_Sublista(list, tam);
        break;*/
    default:
        printf("\nLa opcion ingresada es incorrecta");
        break;
    }
    return 0;
}

void Carga_Vector_Inc (vec list, int*tam){
    int i;
    printf("\nIngrese cantidad de alumnos: ");
    scanf("%d", tam);
    for (i = 1; i<=*tam; i++){
        printf("\nIngrese edad de alumno %d: ", i);
        scanf("%d", &list[i]);
    }
}

int menu (){
    int op;
    printf ("\nDigite 1 para determinar la edad con mayor cantidad de repeticiones: ");
    printf ("\nDigite 2 para mostrar la primera sublista creciente conformada solo por elementos pares: ");
    printf ("\nDigite 0 para salir del menu: ");
    scanf("%d", &op);
    return op;
}

int Mas_Rep (vec A, int tA){
    int rep, /*Pos_Rep,*/Nueva_Rep, Cant_Rep, i, j;
    Nueva_Rep=1;
    for (i=1; i<tA; i++){
        Cant_Rep=0;
        for (j=i+1; i<=tA; j++){
            if (A[i]==A[j]){
                Cant_Rep++;
            }
            if(Cant_Rep>Nueva_Rep){
                Nueva_Rep=Cant_Rep;
                rep=A[i];
            }
        }
    }
    /*if (Nueva_Rep=1)
        rep=0;*/
    return rep;
}
/*void Det_Sublista_Pares (vec, int, int*, int*);
void Mostrar_Sublista (vec, int)*/