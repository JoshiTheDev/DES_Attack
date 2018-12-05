#pragma once
#include <bitset>
#include <iostream>
#include <vector>
#include <string>


void split_bitset(std::bitset<64> &src, std::bitset<32> &des_1, std::bitset<32> &des_2);
void cmp_keys(std::vector<std::bitset<48>> &first_generated_keys, std::vector<std::bitset<48>> &second_generated_keys);