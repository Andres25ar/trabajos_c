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
#define T_CAD 70
#define T_LIST 100

typedef char tCad[T_CAD];
typedef struct{
	long num_cta;
	float sald;
	tCad ape_nom, dom; 
}TCliente;
typedef TCliente list[T_LIST];

void leeCad(tCad, int);
int Menu(void);	

void Carga_List (list, int*);

TCliente Carga_Cliente (void);

int main(void) {
	
	return 0;
}

int Menu(void){
	int op;
	printf("\n1. Actualizar domicilio");
	printf("\n2. Realizar deposito");
	printf("\n3. Realizar retiro");
	printf("\n4. Realizar transferencia");
	printf("\n0. Salir\n");
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
	leeCad(A.ape_nom, T_CAD);
	printf("\nIngrese numero de cuenta: ");
	scanf("%ld", &A.num_cta);
	printf("\nDomicilio: ");
	leeCad()
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
