//
//  person.cpp
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 4/6/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "person.hpp"

person::person(std::string name){
        std::cout << "Person constructor" << std::endl;
        this->name = name;
}
    
void person::aboutMe(){
        std::cout << "I'm a person" << std::endl;
}
