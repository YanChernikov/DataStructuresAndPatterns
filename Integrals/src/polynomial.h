#pragma once 
 
#include <iostream> 
#include <cmath>
 
#define MAX_DEGREE 20 + 1 // max degree = 10 + 10 + 1, 0 to 20 
 
class Polynomial { 
private: 
	int fDegree; // the maximum degree of the polynomial 
	double fCoeffs[MAX_DEGREE]; // the coefficients (0..10, 0..20) 
public: 
	// the default constructor (initializes all member variables) 
	Polynomial(); 
 
	// binary operator * to multiple to polynomials 
	// arguments are read-only, signified by const 
	// the operator * returns a fresh polynomial with degree i+j 
	Polynomial operator*(const Polynomial& aRight) const; 
 
	// input operator for polynomials 
	friend std::istream& operator>>(std::istream& aIStream, Polynomial& aObject);
 
	// output operator for polynomials 
	friend std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject); 

	// calculate polynomial for a given x (i.e., parameter aX)
	double calculate(double aX) const;

	// build indefinite integral
	// the indefinite integral is a fresh polynomial with degree fDegree+1
	// the method does not change the current object
	Polynomial indefiniteIntegral() const;

	// build definite integral
	// the method does not change the current object
	// the method computes the indefinite integral and then calculates it
	// for xlow and xhigh and returns the difference
	double definiteIntegral(double aXLow, double aXHigh) const;
};
