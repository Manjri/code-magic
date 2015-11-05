//
//  base64_scheme1.h
//  puzzles-xcode
//
//  Created by Nikhil Jagdale on 11/1/15.
//  Copyright © 2015 Nikhil Jagdale. All rights reserved.
//

#ifndef base64_scheme1_h
#define base64_scheme1_h

#include "base64.h"
#include <string>
using namespace std;

class base64_scheme1: public base64{
    
public:
    string encode(string source);
    string decode(string const &source);

private:
    string mapping;
    bool check_base64(unsigned char c);
    
};

#endif /* base64_scheme1_h */
