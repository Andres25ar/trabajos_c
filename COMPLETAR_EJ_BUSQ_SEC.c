/* Problema 1: Dada una lista con las edades de N estudiantes y un n�mero natural X, 
ingresado por teclado, se solicita informar si dicho n�mero se encuentra en la 
lista ingresada y en qu� posici�n ( Suponer que la lista A, NO est� ordenada)*/

#include <stdio.h>
#define tamMax 30
typedef int Tlista[tamMax];       /* Definici�n tipo de dato arreglo */

/* �PROTOTIPOS */
void cargarLis(Tlista,int *);    /*Carga lista de edades*/
int buscaEdad(Tlista,int,int);  /* Busca un nro en una lista NO ordenada*/

int main(int argc, char *argv[]) {
	Tlista edades;  /* edades: variable de Tipo de Dato Arreglo */
	int N,X,bus;
	
	cargarLis(edades,&N);	
	printf("\nIngrese la edad a buscar: ");
	scanf("%d",&X);
	bus=buscaEdad(edades, N, bus);
	if(bus>0)
		printf("\nEl elemento %d esta en la lista", X);
	else
		printf("\nEl elemento %d esta en la lista", X);
	return 0;
}

/****** DEFINICION O IMPLEMENTACION DE MODULOS *****/
void cargarLis(Tlista v,int *n1){	
	int i;
	do{
		printf("\n Ingrese tama�o de lista: ");
		scanf("%d",n1);
	}while(*n1>=tamMax);
	
	for(i=1;i<=*n1;i++){
		printf("\n ingrese elemento %d: ",i);
		scanf("%d",&v[i]);
	}	
}
		
int buscaEdad(Tlista e,int n1,int eb){
	int j, rta;
	j=1;
	while(e[j]!=eb&&j<=n1)
		j++;
	if(j<=n1)
		rta=j;
	else 
		rta=-1;
	return rta;
}






















