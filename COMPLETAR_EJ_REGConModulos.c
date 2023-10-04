/**Dados los siguientes datos: dni,nota,Apellido y Nombre de dos alumnos,
 realizar un programa que permita:
a) mostrar los datos del alumno con nota mas alta.
b) Dado un DNI mostrar, si existe, el Apellido y Nombre del alumno.
c) Dado un Apellido y Nombre mostrar, si existe, la nota del alumno.
d) Dado un DNI, modificar la nota del alumno con dicho DNI.
e) Dado un DNI, modificar el Apellido y Nombre del alumno con dicho DNI.*/


#include <stdio.h>
#include <string.h>
#define MAX_CAD 50
typedef char Tcadena[MAX_CAD];
typedef struct {
	long dni;
	unsigned nota;
	Tcadena ApellNom;	
}Talumno;

/** PROTOTIPOS */
Talumno carga_alumno();/*Carga datos de un registro */
int compara_alumnoxnota(Talumno,Talumno);/* Compara 2 registros, según el campo nota */
void muestra_alumno(Talumno); /* Muestra los datos de un registro*/
void modifica_nota(Talumno *,unsigned);/* Modifica el campo nota, de un registro */
void modifica_nombre(Talumno *,Tcadena );/* Modifica el campo ApellNom de un registro */
int menu (void);
void leeCad(Tcadena, int);

int main(void) {
	Talumno al1,al2;
	unsigned nota;
	Tcadena nombre;
	int op;
	long bus;
	op=menu();
	do{
		switch (op){
		case 1:
			if (compara_alumnoxnota(al1,al2)==1)
				muestra_alumno(al1);
			else if(compara_alumnoxnota(al1,al2)==0)
				printf ("\nLos alumnos tienen la misma nota");
				else
					muestra_alumno(al2);
		break;
		case 2:
			printf("\nIngrese DNI buscado: ");
			scanf("%ld", &bus);
			if(bus==al1.dni)
				printf("\n%s", al1.ApellNom);
			else if(bus==al2.dni)
				printf ("\n%s", al2.ApellNom);
				else
					printf("\nNo existe alumno con dicho DNI");
		break;
		case 3:
			printf("\nIngrese nombre y apellido a buscar");
			leeCad(nombre, MAX_CAD);
			if (strcmp(nombre,al1.ApellNom)==0)
				printf("\nEl alumno %s saco la nota: %u", nombre, al1.nota);
			else if (strcmp(nombre,al2.ApellNom)==0)
				printf("\nEl alumno %s saco la nota: %u", nombre, al2.nota);
				else
					printf("\nNo existe el nombre del alumno ingresado");
		break;
		case 4:
			printf("\nIngrese DNI del alumno para corregir su nota: ");
			scanf ("%ld", &bus);
			if(bus==al1.dni)
				printf("\n%s", al1.ApellNom);
			else if(bus==al2.dni)
				printf ("\n%s", al2.ApellNom);
				else
					printf("\nNo existe alumno con dicho DNI");
		}
	} while(op!=0);
	return 0;
}

/** IMPLEMENTACION DE MODULOS */
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
	
Talumno carga_alumno(){
	Talumno aux;
	printf("\nIngrese APELLIDO Y NOMBRE del alumno: ");
	fflush(stdin);
	leeCad(aux.ApellNom,MAX_CAD);
	printf("\nIngrese DNI del alumno");
	scanf ("%ld", &aux->dni);
	printf("\nIngrese nota del alumno");
	scanf("%u", &aux->nota);
	return aux;
}
	
int compara_alumnoxnota(Talumno a1,Talumno a2){
	if(a1.nota>a2.nota)
		return 1;
	else if(a1.nota<a2.nota)
		return -1;
	    else
		 return 0;	
}
	
void muestra_alumno(Talumno alu){
	printf("\nDNI: %ld",alu.dni);
	printf("\nNOTA: %u", alu.nota);
	printf("\nAPELLIDO Y NOMBRE: %s",alu.ApellNom);
}

void modifica_nota(Talumno *alu,unsigned n){
	alu->nota=n;
}
	
void modifica_nombre(Talumno *alu/*,Tcadena nom*/){
	Tcadena nuevo;
	int tmax;
	tmax=MAX_CAD;
	printf("\nIngrese nuevo nombre: ");
	leeCad(nuevo, tmax);
	alu->ApellNom=nuevo;
}
	
	
}

int menu (void){
	int opc;
	printf("\nIngrese una opcion deseada: ");
	printf("\n1.Mostrar los datos del alumno con nota mas alta");
	prinf("\n2.Dado un DNI mostrar el Apellido y Nombre del alumno);
	printf("\n3.Dado un Apellido y Nombre mostrar la nota del alumno");
	printf("\N4.Dado un DNI, modificar la nota del alumno con dicho DNI");
	printf("\n5.Dado un DNI, modificar el Apellido y Nombre del alumno con dicho DNI");
	prinf("\n0.Salir");
	scanf("%d", &opc);
	return opc;
}	
	
	
	
	
	
	
