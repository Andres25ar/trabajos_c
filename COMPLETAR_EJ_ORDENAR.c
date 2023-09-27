-/* Problema 2: Dada una lista con las edades de N estudiantes y un número 
natural X, ingresado por teclado, se solicita ordenar la lista y luego informar
si dicho número se encuentra en la lista A ingresada.
*/
#include <stdio.h>
typedef int Tlista[30];           /* Definición tipo de dato arreglo */

/* ´PROTOTIPOS */
void cargarLis(Tlista,int *);    /*Carga lista de edades*/
void ordenaLis(Tlista,int);      /* Ordena lista */
int busqBinaria(Tlista,int,int); /* Busca un nro en una lista ordenada*/

int main(int argc, char *argv[]) {
	Tlista edades;             /* edades: variable de Tipo de Dato Arreglo */
	int N,X,pos;
	
	cargarLis(edades,&N);	
	ordenaLis(........);
	printf("\nIngrese la edad a buscar: ");
	scanf("%d",&X);
	pos=busqBinaria(........);
	if(pos!=-1)
	    printf("\nLa edad ingresada se encuentra el la posición %d", pos);
	else
		printf("\nNo se encontró la edad ingresada");
			
	return 0;
}

/****** DEFINICION O IMPLEMENTACION DE MODULOS *****/

void cargarLis(Tlista v,int *n1){
	
	
	/** COMPLETAR **/
}

void ordenaLis(Tlista v,int n1){
	/* ...COMPLETAR ...*/
}


int busqBinaria(Tlista v,int n1,int b){
	int ini,fin,med, ret;
		
	ini=1;fin=n1;med=(ini+fin)/2;
		
	while(ini<=fin && v[med]!=b){
			if(v[med]<b)
				ini=med+1;
			else fin=med-1;
			med=(ini+fin)/2;
	}
	if(ini<=fin) ret= med;
	else ret -1;	
	return ret;
}
		
		
 


