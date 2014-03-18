#include "polynomial.h"

using namespace std;

int main() {
	Polynomial a;
	cout << "Specify polynomial:" << endl;
	cin >> a;
	cout << "A = " << a << endl;

	double x;
	cout << "Specific value of x:" << endl;
	cin >> x;

	cout << "A(x) = " << a.calculate(x) << endl;

	cout << "Indefinite integral of A = " << a.indefiniteIntegral() << endl;
	
	cout << "Definite integral of A(xlow=0, xhigh=12.0) = " << a.definiteIntegral(0, 12.0) << endl;
	
	system("PAUSE");
	return 0;
}