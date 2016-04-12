//
//  student.hpp
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 4/6/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include "person.hpp"


class student:public person{
    int grade;
    
public:
    student(std::string name);
    virtual void aboutMe();
};


#endif /* student_hpp */
