#include <iostream>
#include <string>
#include "Tests.h"

using namespace std;

int main()
{
	string message;
	cout << "Enter your message" << endl;
	cin >> message;
	cout << endl;

	tests(message);
	
	cout << " - Test messages:" << endl;
	cout << "-----------------------------------------" << endl;
	cout << " - Up to one block" << endl;
	cout << "Test message - abcde" << endl << endl;
	tests("abcde");
	cout << "-----------------------------------------" << endl;

	cout << "-----------------------------------------" << endl;
	cout << " - More than one block" << endl;
	cout << "Test message - ajhsgcbdjkeuhsgdtwndkslanxmchdpeudhsgxnsjdhfyqpskdhcbzmskao" << endl << endl;
	tests("ajhsgcbdjkeuhsgdtwndkslanxmchdpeudhsgxnsjdhfyqpskdhcbzmskao");
	cout << "-----------------------------------------" << endl;

	cout << "-----------------------------------------" << endl;
	cout << " - Several blocks" << endl;
	cout << "Test message - ajhsgcbdjkeuhsgdtwndkslanxmchdpeudhsgxnsjdhfyqpskdhcbzmskaoajhsgcbdjkeuhsgdtwndkslanxmchdpeudhsgxnsjdhfyqpskdhcbzmskao" << endl << endl;
	tests("ajhsgcbdjkeuhsgdtwndkslanxmchdpeudhsgxnsjdhfyqpskdhcbzmskaoajhsgcbdjkeuhsgdtwndkslanxmchdpeudhsgxnsjdhfyqpskdhcbzmskao");
	cout << "-----------------------------------------" << endl;

	return 0;
}
