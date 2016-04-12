//
//  person.hpp
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 4/6/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#ifndef person_hpp
#define person_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class person{
    
    std::string name;
    
public:
    person(std::string name);
    virtual void aboutMe();
};


#endif /* person_hpp */