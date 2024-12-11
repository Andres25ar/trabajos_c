/*Un Almacen de Ramos Generales requiere de un programa que permita administrar
una lista con los N articulos que comercializa, la informacion de cada articulo a registrar es: Codigo
de Articulo, Nombre de Articulo, Stock, Precio de venta.
El programa debe permitir ingresar la lista y que la misma se ordene por Codigo de Articulo a medida
que se ingresan. Luego debe presentar un menu de opciones que permita las siguientes
operaciones:
● Agregar un nuevo articulo conservando el orden.
● Modificar el precio de venta de un Articulo, dado su Codigo de Articulo.
● Dado el Nombre de un Articulo mostrar Codigo de Articulo, Stock y Precio de venta de cada
artículo que tenga ese nombre.
● Eliminar un articulo, dado su Codigo de Articulo.
● Crear una nueva lista con los Articulos cuyo Stock es menor a K, donde K es un numero
natural generado aleatoriamente, entre los valores [prom, 2*prom], donde prom es el valor
promedio del Stock de los Articulos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define M_CAD 80

typedef char TCad [M_CAD];
typedef struct{
    int cod, stock;
    float precio;
    TCad nom;
}TArt;
typedef struct nodo{
    TArt dato;
    struct nodo* sig;
}TNodo;
typedef TNodo * TPtr;

/*modulos para registro TArt*/
TArt CargaArticulo (int);           /*carga un nuevo articulo. recibe el codigo que fue usado para control*/
void MuestraArticulo (TArt);        /*muestra los datos de un articulo*/
int RetornaCodigo (TArt);           /*dado un articulo, la funcion devuelve su codigo*/
void CambiaPrecio (TArt*, float);   /*toma un articulo y modifica su precio por el precio que recibe*/
int RetornaStock (TArt);            /*dado un articulo, la funcion devuelve su stock actual*/
int ComparaNombre (TArt, TCad);     /*toma un articulo y compara su nombre con un a cadena:1(nomArt>cad),0==,-1(nomArt<cad)*/
/*modulos para lista enlazada*/ 
TPtr CreaNodo (int);                /*genera un nuevo nodo y le paso el codigo del articulo*/
void CargaLista (TPtr*);            /*pide codigo, controla que no este repetido y llama a inserta ordenado*/
void MuestraLista (TPtr);           /*muestra todos los articulos de una lista*/
void InsetaOrdenado (TPtr*, TPtr);        /*acomoda ordenadamente los nodo segun su codigo*/
void CargaNuevo (TPtr*);            /*inseta un nuevo nodo, llama a inserta ordenado*/
void ModificaPrecio (TPtr);         /*pide el codigo del articulo, y llama a buscar y modificar*/
void MostrarxNombre (TPtr);         /*pide un nommbre y llama a compara nombre*/
void EliminaArticulo (TPtr*);       /*pide un codigo, llama a busca y elimina*/
void NuevaLista (TPtr, TPtr*, int); /*genera una nueva lista a partir de un entero*/
int GeneraK (TPtr);                 /*toma los stocks de la listan saca el promedio de estos y genera K*/
void Busca_Modifica (TPtr, int);    /*busca el articulo, muestra sus datos actuales y pide nuevo precio*/
void Busca_Elimina (TPtr*, int);    /*buca por el codigo y elimina*/
int ControlaCarga (TPtr, int);      /*controla que no haya articluos con codigos repetidos*/
/*otros mudulos*/
int menu (void);
void LeeCad (TCad, int);

int main (void){
    TPtr A, B;
    int op, k;
    A=NULL;
    B=NULL;
    CargaLista(&A);
    srand(time(NULL));
    do{
        op=menu();
        switch (op){
        case 1:
            CargaNuevo(&A);
            break;
        case 2:
            ModificaPrecio(A);
            break;
        case 3:
            MostrarxNombre(A);
            break;
        case 4:
            EliminaArticulo(&A);
            break;
        case 5:
            k=GeneraK(A);
            NuevaLista(A, &B, k);
            printf("\nLa lista nueva:\n");
            MuestraLista(B);
            break;
        case 6:
            MuestraLista(A);
            break;
        case 0:
            printf("\nADIOS!!!");
            break;
        }
    } while (op!=0);
    return 0;
}

/*IMPLEMENTACION DE MODULOS*/
int menu (void){
    int o;
    printf("\nINGRESE UNA OPCION");
    printf("\n1-Agregar nvo. articulo");
    printf("\n2-Cambia precio de un articulo");
    printf("\n3-Mostrar articulos por nombre");
    printf("\n4-Eliminar un articulo");
    printf("\n5-Lista de los articulos con stock bajo del promedio");
    printf("\n6-Muestra todos los articulos");
    printf("\n0-Salir");
    printf("\nSU OPCION: ");
    scanf("%d", &o);
    return o;
}
void LeeCad (TCad cad, int tam){
    char c;
    int i;
    i=0;
    c=getchar();
    while (c!=EOF && c!='\n' && i<tam-1){
        cad[i]=c;
        c=getchar();
        i++;
    }
    cad[i]='\0';
    while (c!=EOF && c!='\n')
        c=getchar();
}
/*modulos para registro TArt*/
TArt CargaArticulo (int cod){
    TArt A;
    A.cod=cod;
    printf("\nIngrese nombre del articulo: ");
    fflush(stdin);
    LeeCad(A.nom, M_CAD);
    printf("\nIngrese stock: ");
    scanf("%d", &A.stock);
    printf("\nPrecio unitario: ");
    scanf("%f", &A.precio);
    return A;
}
void MuestraArticulo (TArt A){
    printf("\nEl articulo: %s", A.nom);
    printf("\nCodigo del articulo: %d", A.cod);
    printf("\nUnidades del articulo disponibles: %d", A.stock);
    printf("\nPrecio: $%.2f", A.precio);
}
int RetornaCodigo (TArt A){
    return A.cod;
}         
void CambiaPrecio (TArt*A, float nvo){
    A->precio=nvo;
}
int RetornaStock (TArt A){
    return A.stock;
}
int ComparaNombre (TArt A, TCad cad){   /*1(nomArt>cad)  0(nomArt=cad)  1(nomArt<cad)*/
    /*int r;
    if(strcmp(A.nom, cad)==1)
        r=1;
    else if(strcmp(A.nom, cad)==-1)
            r=-1;
        else
            r=0;
    return r;*/
    return strcmp(A.nom, cad);
}

/*modulos para lista enlazada*/ 
TPtr CreaNodo (int cod){
    TPtr ndo;
    ndo=(TPtr)malloc(sizeof(TNodo));
    ndo->dato=CargaArticulo(cod);
    ndo->sig=NULL;
    return ndo;
}
void CargaLista (TPtr*L){
    int N, i, c;
    TPtr nvo;
    printf("\nIngrese Cantidad de Articulos a Cargar: ");
    scanf("%d", &N);
    i=0;
    while (i<N){
        /*podria usar el modulo CargaNuevo*/
        /*CargaNuevo(L);*/
        printf("\nIngrese codigo del articulo a cargar: ");
        scanf("%d", &c);
        if (*L==NULL){
            nvo=CreaNodo(c);
            *L=nvo;
            i++;
            /*InsetaOrdenado(L, nvo);*/
        }
        else if(ControlaCarga(*L, c)==0){
            nvo=CreaNodo(c);
            InsetaOrdenado(L, nvo);
            i++;
        }
            else
                printf("\tArticulo ya existente en la lista!!!");
    }
}
void MuestraLista (TPtr L){
    /*TPtr aux;*/
    if(L!=NULL){
        /*aux=L;*/
        while (L!=NULL){
            MuestraArticulo(L->dato);
            L=L->sig;
        }
    }
    else
        printf("\nLista VACIA!");
}
void InsetaOrdenado (TPtr*L, TPtr nd){  /*considero que la lista no esta vacia*/
    TPtr aux, ant;
    int cd_nvo;
    aux=*L; ant=NULL;
    cd_nvo=RetornaCodigo(nd->dato);
    while (aux!=NULL && cd_nvo>RetornaCodigo(aux->dato)){
        ant=aux;
        aux=aux->sig;
    }
    if (ant!=NULL){
        ant->sig=nd;
        nd->sig=aux;
        /* *L=nd;*/
    }
    else{
        /*ant->sig=nd;*/
        nd->sig=aux;
        *L=nd;
    }
}   
void CargaNuevo (TPtr*L){
    int c;
    TPtr nvo;
    printf("\nIngrese codigo del articulo a cargar: ");
    scanf("%d", &c);
    if (*L==NULL){
        nvo=CreaNodo(c);
        *L=nvo;
        /*InsetaOrdenado(L, nvo);*/
    }
    else if(ControlaCarga(*L, c)==0){
        nvo=CreaNodo(c);
        InsetaOrdenado(L, nvo);
    }
        else
            printf("\tArticulo ya existente en la lista!!!");
}
void ModificaPrecio (TPtr L){
    int cod;
    printf("\nIngrese codigo del articulo a modificar el precio: ");
    scanf("%d", &cod);
    Busca_Modifica(L, cod);
}
void MostrarxNombre (TPtr L){
    TCad nom;
    if(L!=NULL){
        printf("\nNombre de los articulos: ");
        fflush(stdin);
        LeeCad(nom, M_CAD);
        while (L!=NULL){
            if (ComparaNombre(L->dato, nom)==0)
                MuestraArticulo(L->dato);
            L=L->sig;
        }
    }
    else
        printf("\nNo ha articulos que mostrar!");
}
void EliminaArticulo (TPtr*L){
    int c;
    printf("\nIngrese codigo del articulo que desea eliminar: ");
    scanf("%d", &c);
    if (ControlaCarga(*L, c)!=0)
        Busca_Elimina(L, c);
    else
        printf("\nNo existe el articulo!");
}
void NuevaLista (TPtr L, TPtr*N, int k){
    TPtr nvo, aux;
    aux=L;
    if(aux!=NULL){
        while (aux!=NULL){
            if(RetornaStock(aux->dato)<k){
                if(*N!=NULL){
                    nvo=(TPtr)malloc(sizeof(TNodo));
                    nvo->dato=aux->dato;
                    nvo->sig=NULL;
                    InsetaOrdenado(N, aux);
                }
                else{
                    nvo=(TPtr)malloc(sizeof(TNodo));
                    nvo->dato=aux->dato;
                    nvo->sig=NULL;
                    *N=nvo;
                }
            }
            aux=aux->sig;
        }
    }
    else
        printf("\nNo existe lista generadora!");
}
int GeneraK (TPtr L){   /*lista no vacia. controlamos en NuevaLista*/
    int k, sum, cnt, prom;
    cnt=0;
    sum=0;
    while (L!=NULL){
        cnt++;
        sum=sum+RetornaStock(L->dato);
        L=L->sig;
    }
    prom=sum/cnt;
    /*printf("%d", prom);*/
    k=rand()%((2*prom)-prom+1)+prom; /*[prom, 2*prom]*/
    printf("\t%d", k);
    return k;
}
void Busca_Modifica (TPtr L, int cod){
    float nvo_pre;
    if (L!=NULL){
        while (RetornaCodigo(L->dato)!=cod && L!=NULL)
            L=L->sig;
        if(L!=NULL){
            MuestraArticulo(L->dato);
            printf("\nPrecio nuevo: $");
            scanf("%f", &nvo_pre);
            CambiaPrecio(&L->dato, nvo_pre);
        }
        else
        printf("\nNo existe el articulo!");
    }
    else
        printf("\nLista VACIA!");
}
void Busca_Elimina (TPtr*L, int cod){
    TPtr aux, ant;
    if (*L!=NULL){
        aux=*L;
        ant=NULL;
        while (aux!=NULL && RetornaCodigo(aux->dato)!=cod){
            ant=aux;
            aux=aux->sig;
        }
        if(aux!=NULL){
            if (ant!=NULL){
                ant->sig=aux->sig;
                free(aux);
            }
            else{
                *L=aux->sig;
                free(aux);
            }
        }
    }
    else
        printf("\nLista VACIA!");
}
int ControlaCarga (TPtr L, int cod){  /*devuelve 0 si el articulo no esta en la lista. considero lista cargada*/
    int rta;
    while (L!=NULL && RetornaCodigo(L->dato)!=cod)
        L=L->sig;
    if (L==NULL)
        rta=0;
    else
        rta=1;
    return rta;
}