//
//  student.cpp
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 4/6/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "student.hpp"

student::student(std::string name) : person(name){
    std::cout << "Student constructor" << std::endl;
}

void student::aboutMe(){
    std::cout << "I'm a student" << std::endl;
}