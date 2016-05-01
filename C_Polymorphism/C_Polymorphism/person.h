#ifndef person_h
#define person_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// forward declare
struct _person;

//pointers to function
typedef void    (*fptrDisplayInfo)(struct _person*);
typedef void    (*fptrWriteToFile)(struct _person*, const char*);
typedef void    (*fptrDelete)(struct _person*) ;

typedef struct _person
{
    void* pDerivedObj;
    char* pFirstName;
    char* pLastName;
    fptrDisplayInfo Display;
    fptrWriteToFile WriteToFile;
    fptrDelete        Delete;
}person;


person* new_Person(const char* const pFristName,
                   const char* const pLastName);    //constructor
void delete_Person(person* const pPersonObj);    //destructor

void Person_DisplayInfo(person* const pPersonObj);
void Person_WriteToFile(person* const pPersonObj, const char* const pFileName);


#endif /* person_h */
