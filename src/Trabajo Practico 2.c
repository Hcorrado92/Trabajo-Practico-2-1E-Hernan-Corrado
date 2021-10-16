/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "Input.h"

#define TAM 5 //<-- Esta puesto en 5 porque la lista hardcodeada son 5 personas deberia ir en 100

int iCliente = 0;
int idElegido = 0;
int id = 0;

int GenerarId (int *idUltimo );
int idChecker (Employee list[], int len, int id);
Employee AltaCliente();


int main(void) {

	int id = 0;
	float salario;
	int sector;
	char apellido[51];
	char nombre[51];
	int respuesta;
	int idSelect;
	int idChecker2;
	int idSelect2;
	int aux;
	float aux2;
	Employee ListaEmpleados[TAM] ={ {1,"Hernan","Corrado",10000,1,1} , {2, "Ern", "Corrado", 1000, 2, 1}, {3, "Gis", "Digilio", 20000, 1, 1}, {4, "Sti", "Digilio", 5000, 2, 1}, {5, "Glo", "Fontana", 10000, 3, 1} };


	setbuf (stdout, NULL);

	respuesta = 0;



	//initEmployees(ListaEmpleados, TAM); //<-- Se debe descomentar esta linea para que inicie la lista cuando no está hardcodeada





			do{


				printf("1. Alta\n");
				printf("2. Imprimir Empleado por ID\n");
				printf("3. Borrar Empleado \n");
				printf("4. Ordenar Alfabeticamente y por Sector \n");
				printf("5. Imprimir lista \n");
				printf("6. Salario Total / Salario promedio / Cantidad de empleados con Salario promedio \n");
                printf("7. Salir \n");

				respuesta = PedirEntero("Ingrese respuesta \n");


				//agregamos al empleado, pidiendo primero los parametros para transladar a la funcion addEmployee

                switch(respuesta)
                {

                    case 1:
					id = GenerarId(&id);
					PedirString(nombre, "Ingrese el nombre \n", 51);
					PedirString(apellido, "Ingrese el apellido \n", 51);
					salario = IngresarFlotante("Ingrese el salario \n");
					sector = PedirEntero("Ingrese el sector \n");
					addEmployee(ListaEmpleados,TAM,id,nombre,apellido,salario,sector);
                    break;
                    case 2:
                    idSelect = PedirEntero("Ingrese el ID del empleado \n");
                    aux = findEmployeeById(ListaEmpleados, TAM, idSelect);
                    if (aux != -1)
                    {

                    	printf("NOMBRE\tAPELLIDO\tSALARIO\tSECTOR \n");
                    	printf("%s\t%s\t%f\t%d", ListaEmpleados[aux].name, ListaEmpleados[aux].lastName, ListaEmpleados[aux].salary, ListaEmpleados[aux].sector);
                    }else
                    {
                    	printf ("EL ID NO EXISTE \n");
                    }
                    break;
                    case 3:
                    	idSelect2 = PedirEntero("Ingrese el ID del empleado que desea eliminar \n");
                    	aux = removeEmployee(ListaEmpleados, TAM, idSelect2);
                    	if (aux != -1)
                    	{
                    		printf("Se ha borrado al empleado correctamente \n");
                    	}
                    	else
                    	{
                    		idSelect2 = PedirEntero("ID NO EXISTE - Ingrese nuevamente \n");
                    		idChecker2 = idChecker(ListaEmpleados, TAM, idSelect2);

                    		if (idChecker2 == 0)
                    		{
                    			printf("EL ID NO EXISTE \n");
                    		}
                    		else
                    		{
                    		printf("No se ha podido borrar al cliente \n");
                    		}

                    	}
                    	break;
                    case 4:
                    	sortAlpha(ListaEmpleados, TAM);
                    	sortSalary(ListaEmpleados, TAM);
                    	printf("Se ha ordenado correctamente");
                    	break;
                    case 5:
                    	showLista(ListaEmpleados, TAM);
                    	break;

                    case 6:
                    	aux2 = plusSalary(ListaEmpleados, TAM);
                    	printf("El total de todos los salarios es %f \n", aux2);
                        aux2 = promSalary(ListaEmpleados, TAM);
                        printf("El salario promedio es %f \n", aux2);
                        salaryEmployeeProm(ListaEmpleados, TAM);


                }




			}while (respuesta != 7);

			printf("GRACIAS!!");
			return EXIT_SUCCESS;

}

//Esta funcion chequea en el array si el ID existe y devuelve 1 en caso de que exista.
int idChecker (Employee list[], int len, int id)
{
	int i;
	int retorno;

	retorno = 0;
	for (i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 1 && list[i].id == id)
		{
			retorno = 1;
		}
	}

	return retorno;
}

//Generar ID automaticamente mediante un puntero
int GenerarId (int *idUltimo )
{
	//Pasamos como puntero una variable, que una vez que se completa el condicional es modificada.
	//La proxima vez que se utilice va a tomar el ultimo valor modificado, esto permite que se genere siempre el ID correcto
	int id;
		int idAuxiliar = *idUltimo;

		if (idAuxiliar > -1)
		{
			id =  *idUltimo+1;
		}

		*idUltimo = id;
		return id;

}


Employee AltaCliente()
{
   Employee Cliente;

   Cliente.id = GenerarId(&id);
   PedirString(Cliente.name, "Ingrese el nombre del cliente \n", 51);
   PedirString(Cliente.lastName, "Ingrese el apellido del cliente \n", 51);
   Cliente.salary = PedirEntero("Ingrese el salario del cliente \n");
   Cliente.sector = PedirEntero("Ingrese el sector \n");


   return Cliente;

}

