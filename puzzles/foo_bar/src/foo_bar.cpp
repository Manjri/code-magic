//============================================================================
// Name        : foo_bar.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{

	typedef int A[4];
	typedef const int CA[4];

	const A a = { 1, 2, 3, 4 };
	CA ca = { 1, 2, 3, 4 };

	//a[0] = 0;
	//ca[0] = 0;
	//a = ca;
	//ca = a;

	cout << "" << endl; // prints 
	return 0;
}
