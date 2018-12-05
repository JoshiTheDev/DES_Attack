#pragma once

#include <bitset>
#include <iostream>
#include <vector>

#include "tables.hpp"

using std::bitset;
using std::vector;

class DES
{
	DES();
	~DES();

public:

	static void f_function(bitset<32> xor_L0R1, bitset<32> R0, vector<bitset<48>> &generated_keys);


private:

	static bitset<32> inverse_permutation(bitset<32> input);
	static bitset<48> expansion(bitset<32>& R0);

	static void reverse_key(bitset<32> &permutated, bitset<48> exp_R0, vector<bitset<48>> &generated_keys);
	static vector<bitset<6>> reverse_s1(bitset<4>& out);
	static vector<bitset<6>> reverse_s2(bitset<4>& out);
	static vector<bitset<6>> reverse_s3(bitset<4>& out);
	static vector<bitset<6>> reverse_s4(bitset<4>& out);
	static vector<bitset<6>> reverse_s5(bitset<4>& out);
	static vector<bitset<6>> reverse_s6(bitset<4>& out);
	static vector<bitset<6>> reverse_s7(bitset<4>& out);
	static vector<bitset<6>> reverse_s8(bitset<4>& out);
	static bitset<6> pos_to_bitset(unsigned int zeile, unsigned int spalte, unsigned int val);



};