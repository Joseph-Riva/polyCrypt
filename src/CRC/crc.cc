#include <iostream>
#include <fstream>
#include "Polynomial.h"
#include "IrreduciblePolynomial.h"

const int BYTES = 8;

using namespace std;

/*
    * polynomial x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^3 + x^2 + x + 1
    * code found here: https://rosettacode.org/wiki/CRC-32#C 
*/
uint32_t crc32(const char buffer[], size_t buf_length){

    uint32_t crc = 0xFFFFFFFF;
    const char *p, *q;
    IrreduciblePolynomial field(0xEDB88320);

    q = buffer + buf_length;
	for (p = buffer; p < q; p++) { //iterate over buffer one byte at a time
		Polynomial current_byte((long long) *p, field);
		Polynomial shifted(crc >> 8, field); // shift CRC over one byte
        Polynomial bottom_eight(crc & 0xff, field);

        Polynomial result = shifted + ((bottom_eight + current_byte) % field);
        crc = result.value();
	}

    return ~crc;
}

int main(int argc, char** argv){
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
    cout << "CRC = " << crc32(s, strlen(s)) << '\n';
}