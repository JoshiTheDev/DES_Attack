#include "utils.hpp"

void split_bitset(std::bitset<64> &src, std::bitset<32> &left_key, std::bitset<32> &right_key)
{
	std::bitset<64> divider(0b0000000000000000000000000000000011111111111111111111111111111111);

	right_key = std::bitset<32>((src & divider).to_ulong());
	left_key = std::bitset<32>(((src >> 32) & divider).to_ulong());

}

void cmp_keys(std::vector<std::bitset<48>> &first_generated_keys, std::vector<std::bitset<48>> &second_generated_keys)
{
	int counter = 0;

	for (int i = 0; i < first_generated_keys.size(); i++)
	{
		if (first_generated_keys.at(i) == second_generated_keys.at(i))
			counter++;

	}
	std::cout << "Identical Keys: " << counter << std::endl;
}