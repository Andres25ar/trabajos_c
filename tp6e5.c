/*Ejercicio 5: Se necesita crear un programa que maneje una Agenda telefónica de amigos, que almacena
los siguientes datos de cada persona: “Apellidos, Nombres, Dirección, Celular, Fecha de nacimiento”.
Realizar un programa que permita cargar la lista de amigos y que la misma se ordene alfabéticamente
por Apellidos y Nombres a medida que cargan los registros. Utilizando un menú permita realizar las
siguientes operaciones:
a) Añadir un nuevo contacto, considerando que cada contacto es único. (Mantener ordenada la lista
por apellido y nombres).
a) Borrar un contacto. (Mantener ordenada la lista por apellido y nombres).
b) Dado el apellido y el nombre, modificar su dirección o su teléfono
c) Dado un apellido y el nombre, mostrar sus datos.
d) Mostrar la agenda telefónica completa.
e) Dado un apellido, mostrar todos los datos de las personas con ese apellido.
f) Dado un mes, mostrar todas las personas que cumplen años en ese mes.*/

#include <stdio.h>
#define Max_Cad 60
#define Max_Lis 200

typdef char T_Cad[Max_Cad];
typedef struct {
	int dd, mm, aaaa;
} t_fecha;
typedef struct {
	T_Cad ap, no, di;
	long num_tel;
	t_fecha nac;
}T_Contacto;
typedef T_Contacto List[Max_Lis];

/*otros modulos*/
void LeeCad (T_Cad, int);

/*operaciones sobre el vector*/
void CargaLista (List, int*);

/*operaciones sobre los registros*/
t_fecha Carga_Fecha (void);
T_Contacto Carga_Contacto (void);

int main(void) {
	
	return 0;
}

/*implementaciones*/
t_fecha Carga_Fecha (void){/*modificar para controlar fecha*/
	t_fecha nac;
	printf("ingrese dia de nacimiento");
	scanf("%d", &nac.dd);
	printf("ingrese mes de nacimiento");
	scanf("%d", &nac.mm);
	printf("ingrese anio de nacimiento");
	scanf("%d", &nac.aaaa);
	return nac;
}

T_Contacto Carga_Contacto (void){
	T_Contacto A;
	printf("ingrese apellido: ");
	fflush(stdin);
	LeeCad (A.ap, Max_Cad);
	printf("ingrese nombre: ");
	fflush(stdin);
	LeeCad (A.no, Max_Cad);
	printf("ingrese direccion: ");
	fflush(stdin);
	LeeCad (A.di, Max_Cad);
	printf("ingrese numero de telefono: ");
	scanf ("%ld", &A.num_tel);
	A.nac=Carga_Fecha();
	return A;
}

void LeeCad (T_Cad cadena, int tam){
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

	
	
	
	
	
