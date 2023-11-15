/* Considere una pequenia biblioteca que posee un solo ejemplar por cada libro y cree un
programa que, a traves de un menu de opciones, administre el registro de los libros. Es necesario
registrar por cada libro: ISBN, Nombre, Tipo_libro (de literatura, de consulta y referencia, artisticos,
divulgativos) y Descripcion. El programa debe permitir:
    Agregar un nuevo libro al inicio de la lista, considerar que el ISBN debe ser unico;
    Mostrar los datos de un libro, dado su numero de ISBN;
    Mostrar la lista de todos los libros;
    Modificar el campo Tipo_libro, dado su numero de ISBN.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M_CAD 180

typedef char TCad [M_CAD];
typedef struct{
    int isbn;
    TCad nom, tipo, des;
}T_Libro;
typedef struct nodo{
    T_Libro dato;
    struct nodo* sig;
}T_Nodo;
typedef T_Nodo* T_Ptr;

/*modulos para registro*/
T_Libro CargaReg (int);
int RetornaISBN (T_Libro);
void ModificaTipo (T_Libro*, TCad);
void MostrarDatos (T_Libro);
/*modulos para lista enlazada*/
T_Ptr CreaNodo (int);
void CargaLista (T_Ptr*);
void AgregaPpio (T_Ptr*);
void MostrarxISBN (T_Ptr, int);
void MostrarLista (T_Ptr);
void CambiaTipo (T_Ptr);
/*otros modulos*/
int menu (void);
void LeeCad (TCad, int);

int main (void){
    T_Ptr A;
    A=NULL;
}

T_Libro CargaReg (int x){
    T_Libro lib;
    lib.isbn=x;
    printf("\nIngrese nombre del libro: ");
    fflush(stdin);
    LeeCad(lib.nom, M_CAD);
    printf("\nIngrese tipo de libro: ");
    fflush(stdin);
    LeeCad(lib.tipo, M_CAD);
    printf("\nIngrese pequeña descripcion del libro: ");
    fflush(stdin);
    LeeCad(lib.des, M_CAD);
    return lib;
}

int RetornaISBN (T_Libro lib){
    return lib.isbn;
}
void ModificaTipo (T_Libro*lib, TCad nvo){
    strcpy(lib->tipo, nvo);
}
void MostrarDatos (T_Libro lib){
    printf("\nEl libro: %s", lib.nom);
    printf("\nCodigo ISNB: %d", lib.isbn);
    printf("\nTipo: %s", lib.tipo);
    printf("\n['%s']", lib.des);
}
/**/
T_Ptr CreaNodo (int cod){
    T_Ptr ndo;
    ndo=(T_Ptr)malloc(sizeof(T_Nodo));
    ndo->dato=CargaReg(cod);
    ndo->sig=NULL;
    return ndo;
}

void CargaLista (T_Ptr*L){}
void AgregaPpio (T_Ptr*L){}
void MostrarxISBN (T_Ptr L, int nvo){}
void MostrarLista (T_Ptr L){}
void CambiaTipo (T_Ptr L){}