

#ifndef employee_h
#define employee_h

#include "person.h"

typedef struct _Employee Employee;

//Note: interface for this class is in the base class
//object since all functions are virtual.
//If there is any additional functions in employee add
//interface for those functions in this structure
typedef struct _Employee
{
    person* pBaseObj;
    char* pDepartment;
    char* pCompany;
    int nSalary;
    //If there is any employee specific functions; add interface here.
}Employee;

//constructor
person* new_Employee(const char* const pFirstName,
                     const char* const pLastName,
                     const char* const pDepartment,
                     const char* const pCompany,
                     int nSalary);

//destructor
void delete_Employee(person* const pPersonObj);

void Employee_DisplayInfo(person* const pPersonObj);

void Employee_WriteToFile(person* const pPersonObj,
                          const char* const pFileName);

#endif /* employee_h */
