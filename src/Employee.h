/*
 * Employee.h
 *
 *  Created on: Oct 15, 2021
 *      Author: hernan.j.corrado
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;

 int isEmpty;


}typedef Employee;

int initEmployees(Employee list[], int len);
int searchFirstEmpty(Employee list[], int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
void sortAlpha(Employee* list, int len);
void showLista(Employee* list, int len);
void sortSalary(Employee* list, int len);
float plusSalary(Employee* list, int len);
float promSalary(Employee* list, int len);
void salaryEmployeeProm(Employee* list, int len);
#endif /* EMPLOYEE_H_ */
