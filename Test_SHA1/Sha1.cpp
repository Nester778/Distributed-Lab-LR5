#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;


inline uint32_t leftRotate(uint32_t value, int shift) {
	return (value << shift) | (value >> (32 - shift));
}

string textToBin(string message) {
	string result = "";
	for (int i = 0; i < message.size(); i++)
		result += bitset<8>(message[i]).to_string();
	return result;
}

string puddingBin(string message) {

	string result = message;
	const bitset<64> binMassageSize = bitset<64>(message.size());
	result += "1";
	while (result.size() % 512 != 448)
		result += "0";

	return result += binMassageSize.to_string();
}

string decToHex(int dec) {
	string res = "";
	while (dec > 0) {
		string str = to_string(dec % 16);
		dec /= 16;
		switch (stoi(str))
		{
		case 10:
			res = "a" + res;
			break;

		case 11:
			res = "b" + res;
			break;

		case 12:
			res = "c" + res;
			break;

		case 13:
			res = "d" + res;
			break;

		case 14:
			res = "e" + res;
			break;

		case 15:
			res = "f" + res;
			break;

		default:
			res = str + res;
			break;
		}
	}
	return res;
}

string binToHex(string bin) {
	string res = "";
	int hex = 0;
	int j = 0;
	for (int i = 3; i >= 0; i--) {
		hex += (bin[j] - '0') * pow(2, i);
		j++;
	}
	switch (hex)
	{
	case 10:
		res += "a";
		break;

	case 11:
		res += "b";
		break;

	case 12:
		res += "c";
		break;

	case 13:
		res += "d";
		break;

	case 14:
		res += "e";
		break;

	case 15:
		res += "f";
		break;

	default:
		res += to_string(hex);
		break;
	}

	return res;
}

string binMessageToHexMessage(string bin) {
	string hex = "";
	bitset<64> binMassageSize(bin.substr(bin.size() - 64));

	while (bin.size() > 64)
	{
		hex += binToHex(bin.substr(0, 4));
		bin = bin.substr(4);
	}

	string hexMassageSize = decToHex(binMassageSize.to_ulong());
	while (hex.size() % 128 < 128 - hexMassageSize.size())
		hex += "0";

	return hex + hexMassageSize;
}

const uint32_t K[] = {
	0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6
};

string mySha1(string binMessage) {

	string hexMassage = binMessageToHexMessage(binMessage);

	uint32_t h0 = 0x67452301;
	uint32_t h1 = 0xEFCDAB89;
	uint32_t h2 = 0x98BADCFE;
	uint32_t h3 = 0x10325476;
	uint32_t h4 = 0xC3D2E1F0;

	for (size_t i = 0; i < hexMassage.length(); i += 128) {
		uint32_t w[80];
		for (int j = 0; j < 16; ++j) {
			string str = hexMassage.substr(i + j * 8, 8);
			int word[4];
			for (int k = 0; k < 4; k++) {
				string subsubstr = str.substr(k * 2, 2);
				istringstream stream(subsubstr);
				stream >> hex >> word[k];
			}

			w[j] = static_cast<uint32_t>(
				(static_cast<uint8_t>(word[0]) << 24) |
				(static_cast<uint8_t>(word[1]) << 16) |
				(static_cast<uint8_t>(word[2]) << 8) |
				(static_cast<uint8_t>(word[3]))
				);
		}

		for (int j = 16; j < 80; ++j) {
			w[j] = leftRotate(w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16], 1);
		}

		uint32_t a = h0;
		uint32_t b = h1;
		uint32_t c = h2;
		uint32_t d = h3;
		uint32_t e = h4;

		for (int j = 0; j < 80; ++j) {
			uint32_t f, k;
			if (j < 20) {
				f = (b & c) | ((~b) & d);
				k = K[0];
			}
			else if (j < 40) {
				f = b ^ c ^ d;
				k = K[1];
			}
			else if (j < 60) {
				f = (b & c) | (b & d) | (c & d);
				k = K[2];
			}
			else {
				f = b ^ c ^ d;
				k = K[3];
			}

			uint32_t temp = leftRotate(a, 5) + f + e + k + w[j];
			e = d;
			d = c;
			c = leftRotate(b, 30);
			b = a;
			a = temp;
		}
		h0 += a;
		h1 += b;
		h2 += c;
		h3 += d;
		h4 += e;
	}

	stringstream result;
	result << hex << setfill('0')
		<< setw(8) << h0
		<< setw(8) << h1
		<< setw(8) << h2
		<< setw(8) << h3
		<< setw(8) << h4;

	return result.str();
}