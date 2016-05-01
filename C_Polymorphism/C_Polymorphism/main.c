#include <stdio.h>
#include "person.h"
#include "employee.h"

int main(int argc, const char * argv[]) {

    person* p = new_Person("Nikhil", "Jagdale");
    p->Display(p);
    person* p1 = new_Employee("John", "Smith",
                              "HR", "QCOM", 100);

    p1->Display(p1);
    return 0;
}
