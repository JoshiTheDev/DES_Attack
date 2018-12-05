#include "des.hpp"

using std::bitset;
using std::vector;

void DES::f_function(bitset<32> xor_L0R1, bitset<32> R0, vector<bitset<48>> &generated_keys)
{

	bitset<32> inverse = inverse_permutation(xor_L0R1);
	bitset<48> expanded_r0 = expansion(R0);

	reverse_key(inverse, expanded_r0, generated_keys);

}


bitset<32> DES::inverse_permutation(bitset<32> input)
{
	bitset<32> result;


	for (size_t i = 0; i < input.size(); i++)
	{

		result[i] = input[P[i] - 1];

	}

	return result;
}

bitset<48> DES::expansion(bitset<32> &R0)
{
	bitset<48> res;

	for (int i = 0; i < 48; i++)
		res[i] = R0[E[i] - 1];

	return res;
}


void DES::reverse_key(bitset<32> &permutated, bitset<48> exp_R0, vector<bitset<48>> &generated_keys)
{
	vector<bitset<6>> output_s_boxes;
	vector<bitset<4>> input_for_reversing;
	std::string permutated_s = permutated.to_string();

	// Split 32 bits to 8*4 bits
	for (int i = 0; i < 32; i += 4)
	{
		input_for_reversing.push_back(bitset<4>(permutated_s.substr(i, i + 3)));
	}


	// 4^8 Schlüssel
	auto s_1 = reverse_s1(input_for_reversing.at(0));
	auto s_2 = reverse_s2(input_for_reversing.at(1));
	auto s_3 = reverse_s3(input_for_reversing.at(2));
	auto s_4 = reverse_s4(input_for_reversing.at(3));
	auto s_5 = reverse_s5(input_for_reversing.at(4));
	auto s_6 = reverse_s6(input_for_reversing.at(5));
	auto s_7 = reverse_s7(input_for_reversing.at(6));
	auto s_8 = reverse_s8(input_for_reversing.at(7));

	int i1, i2, i3, i4, i5, i6, i7, i8;


	for (i1 = 0; i1 < 4; i1++)
	{
		for (i2 = 0; i2 < 4; i2++)
		{
			for (i3 = 0; i3 < 4; i3++)
			{
				for (i4 = 0; i4 < 4; i4++)
				{
					for (i5 = 0; i5 < 4; i5++)
					{
						for (i6 = 0; i6 < 4; i6++)
						{
							for (i7 = 0; i7 < 4; i7++)
							{
								for (i8 = 0; i8 < 4; i8++)
								{
									std::string key = s_1.at(i1).to_string() + s_2.at(i2).to_string() + s_3.at(i3).to_string() + s_4.at(i4).to_string() +
										s_5.at(i5).to_string() + s_6.at(i6).to_string() + s_7.at(i7).to_string() + s_8.at(i8).to_string();

									bitset<48> bit_key = bitset<48>(key);
									bit_key ^= exp_R0;

									generated_keys.push_back(bit_key);
								}
							}
						}
					}
				}
			}
		}
	}

	std::cout << "Generated keys: " << generated_keys.size() << std::endl;

}


vector<bitset<6>> DES::reverse_s1(bitset<4>& out)
{
	vector<bitset<6>> bitsets;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			char akt = sbox::S1[i][j];
			if (akt == int(out.to_ullong()))
			{
				bitsets.push_back(pos_to_bitset(i, j, akt));
			}
		}
	}

	return bitsets;
}

vector<bitset<6>> DES::reverse_s2(bitset<4>& out)
{
	vector<bitset<6>> bitsets;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			char akt = sbox::S2[i][j];
			if (akt == int(out.to_ullong()))
			{
				bitsets.push_back(pos_to_bitset(i, j, akt));
			}
		}
	}
	return bitsets;
}

vector<bitset<6>> DES::reverse_s3(bitset<4>& out)
{
	vector<bitset<6>> bitsets;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			char akt = sbox::S3[i][j];
			if (akt == int(out.to_ullong()))
			{
				bitsets.push_back(pos_to_bitset(i, j, akt));
			}
		}
	}
	return bitsets;
}

vector<bitset<6>> DES::reverse_s4(bitset<4>& out)
{
	vector<bitset<6>> bitsets;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			char akt = sbox::S4[i][j];
			if (akt == int(out.to_ullong()))
			{
				bitsets.push_back(pos_to_bitset(i, j, akt));
			}
		}
	}
	return bitsets;
}

vector<bitset<6>> DES::reverse_s5(bitset<4>& out)
{
	vector<bitset<6>> bitsets;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			char akt = sbox::S5[i][j];
			if (akt == int(out.to_ullong()))
			{
				bitsets.push_back(pos_to_bitset(i, j, akt));
			}
		}
	}
	return bitsets;
}

vector<bitset<6>> DES::reverse_s6(bitset<4>& out)
{
	vector<bitset<6>> bitsets;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			char akt = sbox::S6[i][j];
			if (akt == int(out.to_ullong()))
			{
				bitsets.push_back(pos_to_bitset(i, j, akt));
			}
		}
	}
	return bitsets;
}

vector<bitset<6>> DES::reverse_s7(bitset<4>& out)
{
	vector<bitset<6>> bitsets;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			char akt = sbox::S7[i][j];
			if (akt == int(out.to_ullong()))
			{
				bitsets.push_back(pos_to_bitset(i, j, akt));
			}
		}
	}
	return bitsets;
}

vector<bitset<6>> DES::reverse_s8(bitset<4>& out)
{
	vector<bitset<6>> bitsets;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			char akt = sbox::S8[i][j];
			if (akt == int(out.to_ullong()))
			{
				bitsets.push_back(pos_to_bitset(i, j, akt));
			}
		}
	}
	return bitsets;
}


bitset<6> DES::pos_to_bitset(unsigned int row, unsigned int column, unsigned int val)
{

	bitset<2> b_z(row);
	bitset<4> b_s(column);

	std::string ret = b_z.to_string()[0] + b_s.to_string() + b_z.to_string()[1];

	return bitset<6>(ret);

}