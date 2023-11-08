#include <iostream>
#include <string>
#include <iomanip>
#include <cryptlib.h>
#include "sha.h"
#include "Sha1.h"
#include <ctime>

using namespace std;
using namespace CryptoPP;

void tests(string message) {
	SHA1 sha1;
	srand(time(0));
	byte digest[SHA1::DIGESTSIZE];
	sha1.CalculateDigest(digest, reinterpret_cast<const byte*>(message.c_str()), message.length());
	for (int i = 0; i < SHA1::DIGESTSIZE; i++) {
		cout << hex << setw(2) << setfill('0') << static_cast<int>(digest[i]);
	}
	cout << endl << "Execution time of the library solution: " << clock() / 1000.0 << " milliseconds" << endl << endl;


	srand(time(0));
	string res = mySha1(puddingBin(textToBin(message)));
	cout << res << endl;
	cout << "Execution time of my algorithm: " << clock() / 1000.0 << " milliseconds" << endl;
}