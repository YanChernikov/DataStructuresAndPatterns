#include <iostream>
#include "polynomial.h"
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	Polynomial a; 
	cout << "Specify first polynomial equation degree, followed by coefficients: "; 
	cin >> a;
	cout << "A = " << a << endl;

	Polynomial b; 
	cout << "Specify second polynomial equation degree, followed by coefficients: "; 
	cin >> b; 
	cout << "B = " << b << endl; 

	Polynomial c = a * b; 
	cout << "C = A * B = " << c << endl; 
	system("PAUSE");

	return 0;
}