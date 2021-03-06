/*
 * Employee.c
 *
 *  Created on: Oct 15, 2021
 *      Author: hernan.j.corrado
 */

#include "Employee.h"
#include "Input.h"

/*La variable initEmployees nos inicia la lista en EMPTY en todos sus indices*/
int initEmployees(Employee list[], int len)
{

	int i;

	for (i = 0; i < len; i++)
	{
		list[i].isEmpty = 0;


	}
 return 0;
}

//Esta funcion busca el primer espacio libre en el array, luego mediante un break le indicamos que frene y nos va a retornar el primer numero de I que esta libre
//De esta forma podemos re utilizar el array sin necesidad de generar nuevos espacios
int searchFirstEmpty(Employee list[], int len)
{
    int i;
    int first;

    for (i = 0; i < len; i++)
    {
       if (list[i].isEmpty == 0)
       {

    	   first = i;
    	   break;
       }

    }

    return first;
}

/*Mediante variables que vamos a llamar dentro de la funcion, esta funcion nos permite
 * cargar empleados y completar la estructura dentro del array*/

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{

	int firstI;
	int retorno;
	firstI = searchFirstEmpty(list, len);

	if (firstI > -1)
	{
		list[firstI].id = id;
		strcpy(list[firstI].name, name);
		strcpy(list[firstI].lastName, lastName);
		list[firstI].salary = salary;
		list[firstI].sector = sector;
		list[firstI].isEmpty = 1;

		retorno = 0;

	}

	else {

		retorno = -1;

	}





 return retorno;
}

//Pasamos como variable un ID y lo buscamos dentro del array, si lo encuentra noes entrega el Index donde est? alojado

int findEmployeeById(Employee* list, int len,int id)
{

	int i;
	int retorno;


	retorno = -1;
	for (i = 0; i < len; i++)
	{
		if (list[i].id == id)
		{
			retorno = i;

		}

	}



 return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno;
	int i;

	retorno = -1;

	for (i = 0; i < len; i++)
	{
		if (list[i].id == id)
		{
			list[i].isEmpty = 0;
			retorno = 1;

		}

	}

 return retorno;
}

void sortAlpha(Employee* list, int len)
{

	 Employee auxiliar;

	  for (int i = 0; i < len - 1; i++)
	    {
	      for (int j = i + 1; j < len; j++)
		   {
	    	  if(strcmp(list[i].name,list[j].name)>0)
		       {
		      auxiliar = list[i];
		      list[i] = list[j];
		      list[j] = auxiliar;

		        }
		   }
	    }
}

void sortSalary(Employee* list, int len)
{
	 Employee auxiliar;

		  for (int i = 0; i < len - 1; i++)
		    {
		      for (int j = i + 1; j < len; j++)
			   {
		    	  if(list[i].sector > list[j].sector)
			       {
			      auxiliar = list[i];
			      list[i] = list[j];
			      list[j] = auxiliar;
			        }
			   }
		    }
}

void showLista(Employee* list, int len)
{
	int i;

	for (i = 0; i<len; i++)
	{

		if (list[i].isEmpty == 1)
		{
			printf("%d  ", list[i].id);
			printf("%s  ", list[i].name);
			printf("%s  ", list[i].lastName);
			printf("%f  ", list[i].salary);
			printf("%d  \n", list[i].sector);
		}

	}
}

float plusSalary(Employee* list, int len)
{
	int i;
	float acumSalary;

	acumSalary = 0;

	for (i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 1)
		{
			acumSalary = acumSalary + list[i].salary;
		}
	}

	return acumSalary;
}

float promSalary(Employee* list, int len)
{
	float totalSalary = 0;
	int i;
	int activeEmployee;
	int promSalary;
	activeEmployee = 0;
	totalSalary = plusSalary(list, len);

	for (i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 1)
		{
			activeEmployee++;
		}
	}
	promSalary = totalSalary / activeEmployee;

	return promSalary;

}

void salaryEmployeeProm(Employee* list, int len)
{
	int i;
	float promSalaries;
	int overSalaryEmployee;

	overSalaryEmployee = 0;

	promSalaries = promSalary(list, len);
	for (i = 0; i < len; i++)
	{
		if (list[i].salary > promSalaries && list[i].isEmpty == 1)
		{
			overSalaryEmployee++;
		}
	}

	printf("La cantitad de empleado encima del promedio es %d \n", overSalaryEmployee);
}

void modifySalary(Employee* list, int len, int id)
{
	int i;
	float nuevoSalario;
	int retorno;
	for (i = 0; i < len; i++)
	{
		if (list[i].id == id)
		{
			nuevoSalario = IngresarFlotante("Ingrese el nuevo salario \n");
			list[i].salary = nuevoSalario;
			retorno = 1;
		}

	}

	if (retorno == 1)
	{
		printf("Se ha modificado correctamente el salario \n");
	}
	else
	{
		printf("No se ha podido modificar \n");
	}
}
void modifySector(Employee* list, int len, int id)
{
	int i;
	int nuevoSector;
	int retorno;
	for (i = 0; i < len; i++)
	{
		if (list[i].id == id)
		{
			nuevoSector = PedirEntero("Ingrese el nuevo sector \n");
			list[i].sector = nuevoSector;
			retorno = 1;
		}

	}

	if (retorno == 1)
	{
		printf("Se ha modificado correctamente el sector \n");
	}
	else
	{
		printf("No se ha podido modificar el sector \n");
	}
}

void modifyName(Employee* list, int len, int id)
{
	int i;
	int retorno;
	for (i = 0; i < len; i++)
	{
		if (list[i].id == id)
		{
			PedirString(list[i].name, "Ingrese el nuevo nombre \n", 51);
			retorno = 1;
		}

	}

	if (retorno == 1)
	{
		printf("Se ha modificado correctamente el nombre \n");
	}
	else
	{
		printf("No se ha podido modificar el nombre \n");
	}
}
void modifySurname(Employee* list, int len, int id)
{
	int i;

	int retorno;
	for (i = 0; i < len; i++)
	{
		if (list[i].id == id)
		{
			PedirString(list[i].lastName, "Ingrese el nuevo apellido \n", 51);
			retorno = 1;
		}

	}

	if (retorno == 1)
	{
		printf("Se ha modificado correctamente el apellido \n");
	}
	else
	{
		printf("No se ha podido modificar el apellido \n");
	}
}

void MostrarSubMenu(Employee list[], int len, int id)
{
	int respuesta;

	respuesta = 0;
	printf("1. Modificar salario \n");
	printf("2. Modificar nombre \n");
	printf("3. Modificar apellido \n");
	printf("4. Modificar salario \n");


		respuesta = PedirEntero("Ingrese una opcion \n");
		switch (respuesta)
			{
			case 1:
				modifySalary(list, len, id);
				break;
			case 2:
				modifyName(list, len, id);
				break;
			case 3:
				modifySurname(list, len, id);
				break;
			case 4:
				modifySector(list, len, id);
				break;
			}

}
