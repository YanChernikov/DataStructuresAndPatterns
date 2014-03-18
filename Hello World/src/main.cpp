//
// Data Structures and Patterns (COS30008)
// Lab 1 - Yan Chernikov (9991379)
//

// Include the Input/Output library.
#include <iostream>

// Use the standard namespace.
using namespace std;

// The main function: this is where the program starts.
// The two parameters are for handling command line
// arguments: the argc integer specifies the number
// of command line arguments, while the char array
// contains all of the actual arguments.
int main(int argc, char* argv[]) {
	// This for loop interates through every argument
	// in the argv array and prints it to the console.
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << endl;
	}
	// Wait for input so that the console doesn't
	// immediately close after the program terminates.
	cin.get();

	// Return 0 (status OK) and terminate the application.
	return 0;
}