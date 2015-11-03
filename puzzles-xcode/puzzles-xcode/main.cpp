#include <iostream>
#include "assert.h"
#include "base64_scheme1.h"
#include "base64_scheme2.h"
using namespace std;


int main(){

    const string s = "VGhpcyBpcyBhbiBBcnhhbiBzYW1wbGUgc3RyaW5nIHRoYXQgc2hvdWxkIGJlIGVhc2lseSBkZWNvZGVkIGZyb20gYmFzZTY0LiAgSXQgaW5jbHVkZXMgYSBudW1iZXIgb2YgVVRGOCBjaGFyYWN0ZXJzIHN1Y2ggYXMgdGhlIPEsIOksIOgsIOcgYW5kICYjOTYwOyBjaGFyYWN0ZXJzLg==";
    
    base64_scheme1 scheme1;
    base64_scheme2 scheme2;
    

    string decoded = scheme1.decode(s);
    string decoded2 = scheme2.decode(s);
    string encoded = scheme1.encode(decoded);
    string encoded2 = scheme2.encode(decoded2);
    
    
    cout << "Scheme1 Decoded: "  <<  decoded << std::endl;
    cout << "Scheme2 Decoded: " << decoded2 << endl;

    assert(strcmp(decoded.c_str(), decoded2.c_str())==0);
    assert(strcmp(encoded.c_str(), s.c_str())==0);
    assert(strcmp(encoded2.c_str(), s.c_str())==0);
    
    return 0;
}