#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, status=1, num=3, count, c;
    // enter number of primes to print
    cout << "Enter the number of primes to print\n";
    cin >> n;
    
    // input is valid, display first prime
    if(n>=1)
        cout << "First " << n << " prime numbers are: \n" << 2 << endl;
    
    // iterate through n numbers 
    for(count=2; count<=n;){
        //cout << "Testing " << num << " for prime" << endl;
        for(c=2; c<=(int)sqrt(num) ; c++){
            // divisiblity test
            if(num%c == 0){
                status = 0;
                break;
            }
        }        
        // if its a prime, print it
        if(status != 0){
            cout << num << endl;
            // increment the count
            count++;        
        }
        status = 1;
        // test the next prime
        num+=2;
    }
    return 0; 
}
