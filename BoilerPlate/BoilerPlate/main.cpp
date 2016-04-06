//
//  main.cpp
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 4/5/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include <iostream>
#include "foo.h"
#include "person.hpp"
#include "student.hpp"

int main(int argc, const char * argv[]) {
    
#if 0
    // insert code here...
    //std::cout << "Hello, World!\n";
    char str[] = "nikhil";
    printNothing();
    std::cout << "Before: " << str << std::endl;  
    strReverse(str);
    std::cout << "After: " << str << std::endl;
#endif
    //person p("nikhil");
    //p.aboutMe();
    //student s("shruti");
    //s.aboutMe();
    person *q = new student("nivu");
    q->aboutMe();
    return 0;
}
