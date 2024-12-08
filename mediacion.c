#include <stdio.h>
#include <stdlib.h>

#define T_CAD 50
#define T_VEC 30

typedef char Cad[T_CAD];

typedef struct
{
	int cod;
	Cad dmnte;
	Cad dmndo;
	Cad mddor;
	Cad obj;
	long f_ini;
	long f_fin;
}Med;

typedef Med List_Med[T_VEC];

typedef struct
{
	List_Med list;
	int tam;
}List;


/*Modulos para cadenas*/

void Lee_Cad (Cad, int);
int Compara_Cadena (Cad, Cad);

/*Modulos para registros*/

Med Carga_Mediacion (int);
int Retorna_Cod (Med);
int Compara_Mediacion (Med, Med);
int Compara_Mediacion_X_Cod (Med, int);
int Compara_Mediacion_X_FFin (Med, long);
void Modif_Fecha_Fin (Med*, long);
void Mostrar_Mediacion (Med);

/*Modulos para listas de mediacion*/

List Carga_Lista();			/*carga, pero devuelve un registro*/
void Mostrar_Lista(List);	/*muestra, no modifica la lista*/
void Busca_Modifica(List);	/*solo busca y modifica un registro, no la lista*/
void Elimina_x_Fecha(List*);/*Eliminara un registro o mas, la lista si sera modificada*/
int Retorna_Tam (List);/**/

void Menu (List*);	/*para el menu la lista pasa por freferencia ya que dicha lista puede ser modificada en un futuro*/


int main(int argc, char *argv[]) {
	
	return 0;
}


Med Carga_Mediacion (int cod){
	Med aux;
	aux.cod = cod;
	printf("\nIngrese nombre del demandante");
	printf("\nIngrese nombre del demandado");
	printf("\nIngrese nombre del mediador");
	printf("\nIngrese objeto de la madiacion");
	printf("\nIngrese fecha de inicio");
	scanf("%d", &aux.f_ini);
	return aux;
}

/*modulo simple, que retoran el codigo de la mediacion para utilizarlo en comparaciones u otros ojetivos*/
int Retorna_Cod (Med m){
	return m.cod;
}

/*este modulo comparara cada campo del registro y determinara si son iguales
un solo campo distinto anula la posibilidad de que ambos registros sean iguales segun la teoria
retorna 1 si son iguales, sino retornara 0*/
int Compara_Mediacion (Med med1, Med med2){
	if (med1.cod==med2.cod && Compara_Cadena(med1.dmnte, med1.dmnte)==0 && Compara_Cadena(med1.dmndo, med1.dmndo)==0 && Compara_Cadena(med1.mddor, med1.mddor)==0 &&Compara_Cadena(med1.obj, med1.obj)==0 && med1.f_ini==med2.f_ini)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

/*dado un registro y un codigo, este modulo realizara la comparacion del 
codigo de mediacion con el entero pasado
retornando 1 si son iguales o 0 si no lo son*/
int Compara_Mediacion_X_Cod (Med med, int cod){
	if (med.cod == cod)
	{
		return 1;
	}
	else{
		return 0;
	}
}

/*dado un registro y un long que represena una fecha,
este modulo realizara la comparacion de la fecha de finalizacion de la mediacion con el long pasado
retornando 1 si son iguales o 0 si no lo son*/
int Compara_Mediacion_X_FFin (Med med, long ffin){
	if (med.f_fin == ffin)
	{
		return 1;
	}
	else{
		return 0;
	}
}

/*dado un registro y un long que represena una fecha,
este modulo modificara la fecha de finalizacion de la mediacion*/
void Modif_Fecha_Fin (Med* med, long ffin){
	med->f_fin = ffin;
}

/*este modulo deberia mostrar todos los campos del registro... COMPLETAR*/
void Mostrar_Mediacion (Med med){

}


/*---------Codigo correspondiente al menu recursivo---------*/
void Opciones(){
	printf("\n=======Menu de opciones========");
	printf("\nIngrese 1: Mostrar lista de mediaciones");
	printf("\nIngrese 2: Modificar fecha de finalizacion de mediacion por codigo");
	printf("\nIngrese 3: Eliminar registro de mediacion por fecha de finalizacion");
	printf("\nIngrese 0: para salir del MENU");
}

void Menu (List* lis){
	int rta;
	Opciones();
	printf("\nIngrese su eleccion: ");
	scanf("%d", &rta);
	switch(rta){
	case 0: 
		printf("\nA elegido Salir del Programa"); 
		break;
	case 1: /*muestra la lista con todas las mediaciones*/
		if(Retorna_Tam(*lis)>0)
		{
			Mostrar_Lista(*lis);
		}
		else
		{
			printf("\nLista vacia... Nada que mostrar...");
		}
		Menu(lis);		
		break;
	case 2:	/*moificar una fecha de fin por codigo*/
		if(Retorna_Tam(*lis)>0)
		{
			Busca_Modifica(*lis);
			printf("\nSe modifico exitosamente la fecha de fin de la mediacion");
		}
		else
		{
			printf("\nLista vacia...");
		}
		Menu(lis);
		break;
	case 3: 
		if(Retorna_Tam(*lis)>0)
		{ 
			Elimina_x_Fecha(lis);
			printf("\nSe elimino exitosamente la mediacion");
		}
		else
		{
			printf("\nLista vacia... Nada que eliminar");
		}
		Menu(lis);
		break;
	}
}

/*busca recursiva de manera secuencial, ya que al momento de cargar los registros no estan ordenados*/
int Busca_x_Cod_S (List_Med vec, int tam, int bus){
	if (tam > 0)
	{
		if (Compara_Mediacion_X_Cod(vec[tam], bus) != 1){
			return Busca_x_Cod_S(vec, tam-1, bus);
		}
		else{
			return tam;
		}
	}
	else
	{
		return -1;
	}
}

/*el modulo del Q-Sort no esta realizado
------COMPLETAR!!!!------
*/
void Q_Sort (){}

/*creo que este codigo recursivo podria optimizarse
------REVISAR!!!------
*/
void Carga_Recursivo (List_Med vec, int tam){
	if (tam>0)
	{
		Carga_Recursivo(vec, tam-1);
		int cod_aux;
		int b;
		Med aux;
		do
		{
			printf("\nPor favor ingrese en codigo de la nueva mediacion: ");
			scanf("%d", &cod_aux);
			/*Busca_x_Cod(vec, tam, cod_aux);*/
			aux = Carga_Mediacion(cod_aux);
			if (Busca_x_Cod_S(vec, tam, cod_aux) == -1 || Compara_Mediacion(vec[tam], aux) != 1)
			{
				vec[tam] = aux;
				b = 1;
			}
			else
			{
				printf("\nNo se admiten repetidos");
				b = 0;
			}
		}while (b == 0);
		
	}
	
}

/*el modulo de cargar retornara un registro del tipo List
primero lo creara, y accediendo a sus campos lo cargara utilizando los modulos recursivos vistos anteriormente*/
List Carga_Lista(){
	List new_lis;
	int n;
	printf("\nIngrese cantidad de mediaciones a cargar: ");
	scanf("%d", &new_lis.tam);
	Carga_Recursivo(new_lis.list, new_lis.tam);
	Q_Sort(new_lis.list, new_lis.tam);	/*Completar primero el q-sort*/
	return new_lis;
}

/*modulo para recorrer la lista de manera racursiva in-order y mostrar sus elementos*/
void Muestra_Recursivo (List_Med vec, int tam){
	if (tam > 0)
	{
		Muestra_Recursivo(vec, tam-1);
		Mostrar_Mediacion(vec[tam]);
	}
}

/*modulo creado para no violar el encapsulamiento del registro List y acceder si problemas al modulo anterior*/
void Mostrar_Lista(List lis){
	Muestra_Recursivo(lis.list, lis.tam);
}

/*una vez cargado, el programa ordenara la lista segun lo pedido en la consigna,
por lo tanto si se desea realizar una busqueda por medio del campo por el cual se ordeno la
lista de registro, seria poco eficiente, hacerlo de forma secuencial, por ende, usaremos una busqueda binaria*/
/*¡¡¡ATENCION!!! posibles errores ¡¡¡ATENCION!!!
------CORREGIR!!!------
*/
int Busca_x_Cod_B (List_Med vec, int ini, int fin, int bus){
	int med;
	if (ini <= fin)
	{
		med = (ini + fin) / 2;
		if (Compara_Mediacion_X_Cod(vec[med], bus) != 1){
			if (Retorna_Cod(vec[med]) < bus)
			{
				return Busca_x_Cod_B(vec, ini, med-1, bus);
			}
			else
			{
				return Busca_x_Cod_B(vec, med+1, fin, bus);
			}
			
		}
		else{
			return med;
		}
	}
	else
	{
		return -1;
	}
	
}

/*modulo creado para no violar el encapsulamiento del registro List y poder realizar la busqueda sin problemas*/
void Busca_Modifica(List lis){
	int bus;
	int pos;
	int new_date;
	printf ("\nIngrese codigo de la mediacion la cual sera modificada: ");
	scanf("%d", &bus);
	pos = Busca_x_Cod_B(lis.list, 1, lis.tam, bus);
	if (pos != -1)
	{
		printf("\nESTA EN LA LISTA");
		Mostrar_Mediacion(lis.list[pos]);
		printf("\nIngrese fecha de finalizacion: ");
		scanf("%d", &new_date);
		Modif_Fecha_Fin(lis.list[pos], new_date);	/*posible violacion de encapsulamiento "???"*/
	}
	else
	{
		printf("\nNO ESTA EN LA LISTA");
	}
}

/*el modulo "eliminar por fecha" no esta realizado
------COMPLETAR!!!!------
*/
void Elimina_x_Fecha(List* lis){

}

/**/
int Retorna_Tam (List lis){
	return lis.tam;
}

/*---------COMPOLETAR CON LOS MODULOS FALTANTES---------*/

void Lee_Cad (Cad cad, int tam){}
int Compara_Cadena (Cad cad1, Cad cad2){}