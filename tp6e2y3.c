/*Un banco mantiene la información de sus clientes en un array de registros (Lista de clientes).
	De cada Cliente se almacena la siguiente información: “Número de cuenta, Apellido y Nombre del cliente,
	Domicilio del cliente, Saldo de la cuenta. “
	Se solicita escribir un programa que permita realizar la carga de las cuentas de N Clientes de un banco y
	luego mediante un menú realizar las siguientes operaciones:
	a) Permitir actualizar el domicilio de un cliente, dado su número de cuenta
	b) Realizar un depósito (es decir, dado un monto a depositar y una cuenta, actualizar el saldo).
	c) Realizar un retiro (es decir, dado un monto a retirar y una cuenta, actualizar el saldo si es que el
saldo es mayor o igual al importe a retirar).
	d) Realizar una transferencia entre cuentas (es decir, dado un monto a transferir, una cuenta origen
y una cuenta destino, actualizar el saldo destino si es que el saldo origen es mayor o igual al
importe a transferir).*/

#include <stdio.h>
#include <stdlib.h>
#define T_CAD 70
#define T_LIST 100

/*Definicion de tipos de datos*/
typedef char tCad[T_CAD];
typedef struct{
	long num_cta;
	float sald;
	tCad ape_nom, dom; 
}TCliente;
typedef TCliente list[T_LIST];

/*Declaracion de modulos*/
void leeCad(tCad, int);
int Menu(void);	

/*Modulos de lista de registros*/
void Carga_List (list, int*);
int Busca_Cta (list, int, long);
void Transferencias (list, int);

/*Modulo de los registros*/
TCliente Carga_Cliente (void);
void Modi_Domicilio (TCliente*);
void Mostrar_Cliente (TCliente);
void Modif_Saldo (TCliente*, float);
void Retiro (TCliente*, float);

int main(void) {
	list vec;
	int op, pos, tam;
	float dep;
	long bus;
	Carga_List (vec, &tam);
	do{
		op=Menu();
		switch (op){
		case 1:
			printf("\nIngrese el numero de cuenta: ");
			scanf ("%ld", &bus);
			pos=Busca_Cta(vec, tam, bus);
			Modi_Domicilio(&vec[pos]);
			Mostrar_Cliente(vec[pos]);
		break;
		case 2:
			printf("\nIngrese el numero de cuenta: ");
			scanf ("%ld", &bus);
			pos=Busca_Cta(vec, tam, bus);
			if (pos!=-1){
				printf("\nIngrese el monto a depositar: ");
				scanf("%f", &dep);
				Modif_Saldo(&vec[pos], dep);
			}
			else
				printf ("\nCuenta no encontrada");
			Mostrar_Cliente(vec[pos]);
		break;
		case 3:
			printf("\nIngrese el numero de cuenta: ");
			scanf ("%ld", &bus);
			pos=Busca_Cta(vec, tam, bus);
			if (pos!=-1){
				printf("\nIngrese el monto a retirar anteponiendo el signo - (menos): ");
				scanf("%f", &dep);
				Retiro(&vec[pos], dep);
			}
			else
				printf ("\nCuenta no encontrada");
			Mostrar_Cliente(vec[pos]);
		break;
		case 4:
			Transferencias (vec, tam);
		break;
		}
	} while (op!=0);
	
	return 0;
}

/*Implementaciones: */
int Menu(void){
	int op;
	printf("\n1. Actualizar domicilio");
	printf("\n2. Realizar deposito");
	printf("\n3. Realizar retiro");
	printf("\n4. Realizar transferencia");
	printf("\n0. Salir\n");
	printf("\nIngrese opcion deseada: ");
	scanf("%d", &op);
	return op;
}

void Carga_List (list l, int*t){
	int i;
	printf("\nIngrese cantidad de clientes a cargar: ");
	scanf("%d", t);
	for(i=1; i<=*t; i++)
		l[i]=Carga_Cliente();
}

TCliente Carga_Cliente (void){
	TCliente A;
	printf("\nIngrese Apellido y Nombre: ");
	fflush(stdin);
	leeCad(A.ape_nom, T_CAD);
	printf("\nIngrese numero de cuenta: ");
	scanf("%ld", &A.num_cta);
	printf("\nDomicilio: ");
	fflush(stdin);
	leeCad(A.dom, T_CAD);
	printf("\nSaldo de la cuenta: ");
	scanf ("%f", &A.sald);
	return A;
}
	
void leeCad(tCad cadena, int tam){
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

int Busca_Cta (list V, int t, long bus){
	int i, pos;
	i=1;
	while (V[i].num_cta!=bus && i<=t)
		i++;
	if(i<=t)
		pos=i;
	else 
		pos=-1;
	return pos;
}

void Modi_Domicilio (TCliente*A){
	printf("\nIngrese nuevo Domicilio: ");
	fflush(stdin);
	leeCad(A->dom, T_CAD);
}

void Mostrar_Cliente (TCliente cli){
	printf("\nEl cliente %s", cli.ape_nom);
	printf("\nNumero de cuenta %ld", cli.num_cta);
	printf("\nSaldo: %.2f", cli.sald);
	printf("\nSu domicilio es: %s", cli.dom);
}

void Modif_Saldo (TCliente*A, float sal){
	A->sald=A->sald+sal;
}

void Retiro (TCliente * A, float ret){
	/*float ret;
	printf("\nIngrese el monto a retirar anteponiendo el signo - (menos): ");
	scanf("%f", &ret);*/
	if(abs(ret)<=A->sald && ret<0)
		Modif_Saldo(A, ret);
	else 
		printf("\nMonto incorrecto");
}

void Transferencias (list L, int tam){
	int c1, c2;
	long bus;
	float tran;
	c1=-1;c2=-1;
	while (c1==-1){
		printf("\nIngrese el numero de cuenta origen: ");
		scanf ("%ld", &bus);
		c1=Busca_Cta(L, tam, bus);
	}
	while (c2==-1){
		printf("\nIngrese el numero de cuenta destino: ");
		scanf ("%ld", &bus);
		c2=Busca_Cta(L, tam, bus);
	}
	do{
		printf("\nIngrese el monto a transferir, anteponiendo el signo - (menos): ");
		scanf("%f", &tran);
	}while (tran>0);
	if (abs(tran)<=L[c1].sald){
		Retiro(&L[c1], tran);
		tran=abs(tran);
		Modif_Saldo(&L[c2], tran);
	}
	Mostrar_Cliente (L[c1]);
	Mostrar_Cliente (L[c2]);
}
