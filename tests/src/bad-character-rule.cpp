#include <utility>
#include <iostream>

#include <map>
#include <set>

#include <criterion/criterion.h>

using BcrTable = std::map<char, int>;

extern auto create_bcr_table(const char*) -> BcrTable;
extern auto bad_character_rule(const BcrTable&, int, char) -> int;

Test(boyer_moore, bad_character_rule) {
	const char* pattern = "annpmanm";
	const auto table = create_bcr_table(pattern);

	const std::set<std::tuple<char, int, int>> correct_values{
		// Bad character, offset from the end, correct move
		{ 'a', 0, 2 },
		{ 'n', 0, 1 },
		{ 'p', 0, 4 },
		{ 'k', 3, 5 },
		{ 'm', 4, 1 } // Correct move is 1 because bad_character_rule should return 0 or less
	};

	for (const auto& t : correct_values) {
		const auto mismatch = std::get<0>(t);
		const auto offset = std::get<1>(t);
		const auto correct_result = std::get<2>(t);

		const auto result = bad_character_rule(table, offset, mismatch);

		cr_assert(result == correct_result);
	}
}
