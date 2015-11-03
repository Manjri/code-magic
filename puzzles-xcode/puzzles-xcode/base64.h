//
//  base_64.h
//  puzzles-xcode
//
//  Created by Nikhil Jagdale on 11/1/15.
//  Copyright © 2015 Nikhil Jagdale. All rights reserved.
//

#ifndef base64_h
#define base64_h
#include <string>
using namespace std;


/** 
base_64 is an abstract class containing interfaces for encode & decode
These pure virtual functions will be defined by derived classes of base_64
with their versions of encode() and decode() schemes
*/

class base64{
    
private:
    string mapping;
    
public:
    virtual string encode(string source) = 0;
    virtual string decode(string const &source) = 0;
};


#endif /* base64_h */
