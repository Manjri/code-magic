//
//  base64_scheme2.h
//  puzzles-xcode
//
//  Created by Nikhil Jagdale on 11/1/15.
//  Copyright © 2015 Nikhil Jagdale. All rights reserved.
//

#ifndef base64_scheme2_h
#define base64_scheme2_h

#include "base64.h"
using namespace std;

class base64_scheme2: public base64{
    
public:
    string encode(string source);
    string decode(string const &source);
    
private:
    bool check_base64(unsigned char c);
    
};

#endif /* base64_scheme2_h */
