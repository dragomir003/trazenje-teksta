#include <utility>
#include <iostream>

#include <map>
#include <set>

#include <criterion/criterion.h>

using BcrTable = std::map<char, int>;

extern auto create_bcr_table(const char* pattern) -> BcrTable;

Test(boyer_moore, bcr_table_creation) {
	const char* pattern = "babac";
	const auto table = create_bcr_table(pattern);

	const std::set<std::pair<char, int>> correct_values{
		{ 'b', 2 },
		{ 'a', 1 },
		{ 'c', 5 },
		{  0 , 5 },
	};

	for (const auto& kvp : table) {
		const auto correct_value = correct_values.find(kvp);
		cr_assert(correct_value != end(correct_values));
	}
}
