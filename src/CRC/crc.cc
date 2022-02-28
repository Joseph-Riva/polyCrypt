#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "Polynomial.h"
#include "IrreduciblePolynomial.h"

//const int BYTES = 8;

using namespace std;

/*
    * polynomial x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^3 + x^2 + x + 1
    * code found here: https://rosettacode.org/wiki/CRC-32#C 
*/
uint32_t crc32(const char* buffer, size_t buf_length){
    uint32_t crc = 0xFFFFFFFF;
    IrreduciblePolynomial field(0b100000100110000010001110110110111, pow(2, 32));

	for (size_t i = 0; i < buf_length; ++i) { //iterate over buffer one byte at a time
        //cout << "curP: " << p << "\n";
		uint8_t cur_char = buffer[i];

        uint8_t bottom_eight = crc & 0xff;

		long long table_index = bottom_eight ^ cur_char;
        cout << "myTable index: " << table_index << "\n";
		Polynomial p(table_index << 32,field);
        crc = (Polynomial(crc>>8, field) + p).value();
		cout << "cur CRC: " << crc << "\n\n";
	}

    return ~crc;
}

uint32_t rc_crc32(uint32_t crc, const char *buf, size_t len){
	static uint32_t table[256];
	static int have_table = 0;
	uint32_t rem;
	uint8_t octet;
	int i, j;
	const char *p, *q;
 
	/* This check is not thread safe; there is no mutex. */
	if (have_table == 0) {
		/* Calculate CRC table. */
		for (i = 0; i < 256; i++) {
			rem = i;  /* remainder from polynomial division */
			for (j = 0; j < 8; j++) {
				if (rem & 1) {
					rem >>= 1;
					rem ^= 0xedb88320;
				} else
					rem >>= 1;
			}
			table[i] = rem;
		}
		have_table = 1;
	}
 
	crc = ~crc;
	q = buf + len;
	for (p = buf; p < q; p++) {
		octet = *p;  /* Cast to unsigned octet. */
		cout << "octet: " << +octet << '\n';
		cout << "table index: " << ((crc & 0xff) ^ octet) << '\n';
        cout << "table: " << table[(crc & 0xff) ^ octet] << "\n";
		crc = (crc >> 8) ^ table[(crc & 0xff) ^ octet];
		cout << "cur CRC: " << crc << "\n\n";
	}
	return ~crc;
}

int main(int /*argc*/, char** /*argv*/){
    // ifstream file(argv[1], ios::binary);
    // if(!file){
    //     cerr << "failed to open file." << '\n';
    // }    
    // char buffer[BYTES];
    // int i = 0;

    // int crc = 0;

    //IrreduciblePolynomial p;
    // while(file.read(buffer, BYTES)){
        
    //     for(int j = 0; j < BYTES; ++j){
    //         cout << i << "th byte -> " << buffer[j] << '\n';
    //         ++i;
    //     }
    // }
    const char* s = "These are words to do a CRC on, let's see what happens";
    cout << "My CRC = " << crc32(s, strlen(s)) << '\n';
    cout << "Rosetta CRC = " << rc_crc32(0, s, strlen(s)) << '\n';
}