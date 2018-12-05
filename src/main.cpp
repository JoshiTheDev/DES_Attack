#include <bitset>
#include <string>
#include <iostream>

#include "tables.hpp"
#include "des.hpp"
#include "utils.hpp"


using std::bitset;

bitset<64> X1(0xF57DDDB12EAA799D);
bitset<64> X2(0x2EAA799D332924D8);
bitset<64> Y1(0x15837977D5202437);
bitset<64> Y2(0xD5202437B5D8FC31);


int main()
{
	vector<bitset<48>> generated_keys_pair1, generated_keys_pair2;
	bitset<32> encrypted_L0, encrypted_R0;
	bitset<32> decrypted_L1, decrypted_R1;

	split_bitset(X1, encrypted_L0, encrypted_R0);
	split_bitset(Y1, decrypted_L1, decrypted_R1);
	DES::f_function(encrypted_L0 ^ decrypted_R1, encrypted_R0, generated_keys_pair1);

	split_bitset(X2, encrypted_L0, encrypted_R0);
	split_bitset(Y2, decrypted_L1, decrypted_R1);
	DES::f_function(encrypted_L0 ^ decrypted_R1, encrypted_R0, generated_keys_pair2);

	cmp_keys(generated_keys_pair1, generated_keys_pair2);
	std::cin.ignore();
}