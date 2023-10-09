/**EJEMPLO 2 (sin menu)
Dada una lista de las notas de un parcial de N alumnos, de los cuales se almacena
la siguiente información:DNI,Nota obtenida, Apellido y Nombre. Se pide realizar
un programa que cargue una lista ordenada por dni, sin repetidos, y muestre la 
lista ingresada **/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_CAD 50
#define MAX_VEC 40
/*declaro TD cadena*/
typedef char Tcadena[MAX_CAD];
/*declaro TD registro*/
typedef struct {
	long dni;
	unsigned nota;
	Tcadena ApellNom;	
}Talumno;
/*declaro TD vector de registros*/
typedef Talumno Tlista[MAX_VEC];  

/****    PROTOTIPOS   ****/
/* Modulos que trabajan sobre el registro alumno */
/*Talumno carga_alumno();/* carga el registro */
Talumno carga_alumno2(Tcadena);
void muestra_alumno(Talumno);/* muestra los datos del registro */
int compara_alumnoxdni(Talumno,Talumno);/* compara el campo DNI de dos registros */

/* Modulos que trabajan sobre la lista de alumnos */
void mostrar_lista(Tlista,int );/* muestra la lista de registros */
void cargar_lista_sin_repetir(Tlista,int*);/* cargar vector de registros ordenado x dni (sin repetidos*/
int buscar_alumno(Tlista,int,Tcadena); /* busca posición de registro x dni */ 

/* Modulo Cadena */
void leeCad(Tcadena, int);

/* Programa Principal */
int main(void) {
	int tam;
	Tlista Curso;
	
	/* CARGAR LISTA ORDENADA - SIN REPETIDOS*/	
	cargar_lista_sin_repetir(Curso,&tam);
	
	/* MOSTRAR LISTA */	
	if(tam!=0){
		printf("\n\nlista Ordenada x Nombre y Apellido\n");
		mostrar_lista(Curso, tam);
	}
	  else printf("lista Vacia\n");	
	return 0;
}

/**** DEFINICIÓN DE MODULOS DEl REGISTRO   *****/
/*Talumno carga_alumno(){
	Talumno aux;
	printf("\nIngrese DNI del alumno: ");
	scanf("%ld",&aux.dni);
	printf("\nIngrese NOTA del alumno: ");
	scanf("%u",&aux.nota);
	printf("\nIngrese APELLIDO Y NOMBRE del alumno: ");
	fflush(stdin);
	leeCad(aux.ApellNom,MAX_CAD);
	return aux;	
}*/

Talumno carga_alumno2(Tcadena c){
	Talumno aux;
	strcpy(aux.ApellNom, c);
	/*aux.ApellNom=c;*/
	printf("\nIngrese DNI del alumno: ");
	scanf("%ld",&aux.dni);
	printf("\nIngrese NOTA del alumno: ");
	scanf("%u",&aux.nota);
	/*printf("\nIngrese APELLIDO Y NOMBRE del alumno: ");
	fflush(stdin);
	leeCad(aux.ApellNom,MAX_CAD);*/
	return aux;	
}

int compara_alumnoxdni(Talumno a1,Talumno a2){
	if(a1.dni>a2.dni)
		return 1;
	else if(a1.dni<a2.dni)
		return -1;
	else
		return 0;	
}

void muestra_alumno(Talumno alu){
	printf("\nDNI: %ld",alu.dni);
	printf("\nNOTA: %u",alu.nota);
	printf("\nAPELLIDO Y NOMBRE: %s",alu.ApellNom);	
}


/**** DEFINICIÓN DE MODULOS DE LA LISTA  *****/

/* CARGA VECTOR DE REGISTROS  (ordenado - sin repetidos) */		
void cargar_lista_sin_repetir(Tlista lis,int* n){	int i,j,pos;
	/*long dni;*/
	Tcadena ayn;
	//Talumno aux;
	
	printf("\ningrese tamanio de lista: ");
	scanf("%d",n);
	for (i=1;i<=*n;i++){
		/* verificar que NO exista un alumno con DNI repetido*/
		do{
			printf("\ningrese nombre y apellido: ");
			/*scanf("%ld",&dni);*/
			fflush(stdin);
			leeCad(ayn, MAX_CAD);
			pos=buscar_alumno(lis,i-1,ayn);
		}while(pos!=-1);
		
		/* Carga ordenada x dni */	
		lis[0]=carga_alumno2(ayn);  /* uso posición 0 del vector */
		j=i-1; /*cantidad de elementos cargados hasta el momento*/
		while(strcmp(lis[j].ApellNom,lis[0].ApellNom)==1){
			lis[j+1]=lis[j];
			j=j-1;
		}
		lis[j+1]=lis[0];
	}
		/*Para ordenar alfabeticamente debo usar
		strcmp(lis[j].ApellNom,lis[0].ApellNom):0-1-(-1)*/
}
		
int buscar_alumno(Tlista lis,int n, Tcadena cad){
	int i,b;
	i=1;
	while(i<=n && strcmp(lis[i].ApellNom,cad)!=0)
		i=i+1;
	if (i<=n)
		b=i;
	else
		b=-1;
	return b;
}

void mostrar_lista(Tlista lis,int n){
	int i;
	
	for (i=1;i<=n;i++)
		muestra_alumno(lis[i]);		
}
		
void leeCad(char * cadena, int tam){
	int j;
	char c;
	j=0;
	c=getchar();			
	while (c!=EOF && c!='\n' && j<tam-1)
	{
		cadena[j]=c;
		j++;
		c=getchar();
	}
	cadena[j]='\0';
			
	while(c!=EOF && c!='\n')
		c=getchar();
}
			
