// 
// Data Structures and Patterns - Assignment 2: Solution Design in C++
// Yan Chernikov (9991379)
// 

#include "polynomial.h"

using namespace std;

Polynomial::Polynomial() {
	fDegree = 0;
	for (int i = 0; i < MAX_DEGREE; i++) {
		fCoeffs[i] = 0.0;
	}
}

Polynomial Polynomial::operator*(const Polynomial& aRight) const {
	Polynomial result;
	result.fDegree = aRight.fDegree + fDegree;
	for (int y = 0; y <= fDegree; y++) {
		for (int x = 0; x <= aRight.fDegree; x++) {
			result.fCoeffs[x + y] += fCoeffs[y] * aRight.fCoeffs[x];
		}
	}
	return result;
}

istream& operator>>(istream& aIStream, Polynomial& aObject) {
	aIStream >> aObject.fDegree;
	while (aObject.fDegree > MAX_DEGREE / 2 - 1) {
		cout << "Max Degree too large! Please enter a degree less than " << MAX_DEGREE / 2 - 1 << endl;
		aIStream >> aObject.fDegree;
	}
	for (int i = 0; i <= aObject.fDegree; i++) {
		aIStream >> aObject.fCoeffs[i];
	}
	return aIStream;
}

ostream& operator<<(ostream& aOStream, const Polynomial& aObject) {
	for (int i = 0; i <= aObject.fDegree; i++) {
		aOStream << aObject.fCoeffs[i] << "x^" << i;
		if (i <= aObject.fDegree - 1) aOStream << " + ";
	}
	return aOStream;
}

double Polynomial::calculate(double aX) const {
	double result = 0;
	for (int i = 0; i <= fDegree; i++) {
		result += fCoeffs[i] * (pow(aX, i));
	}
	return result;
}

Polynomial Polynomial::indefiniteIntegral() const {
	Polynomial result;
	for (int i = 0; i <= fDegree; i++) {
		result.fCoeffs[i + 1] = fCoeffs[i] / (i + 1);
	}
	result.fDegree = fDegree + 1;
	return result;
}

double Polynomial::definiteIntegral(double aXLow, double aXHigh) const {
	Polynomial polynomial = indefiniteIntegral();
	return polynomial.calculate(aXHigh) - polynomial.calculate(aXLow);
}