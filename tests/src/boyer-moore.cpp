#include <utility>
#include <iostream>

#include <map>
#include <set>

#include <criterion/criterion.h>

using BcrTable = std::map<char, int>;

extern auto boyer_moore(const char* text, const char* pattern) -> int;

Test(boyer_moore, search) {
	const std::set<std::tuple<const char*, const char*, int>> testing_data{
		{ "abcd", "a", 0 },
		{ "aabcdae", "ae", 5 },
		{ "Ovo je prost test", "prost", 7 },
		{ "Ovde ne treba nista da se nadje.", "nasao", -1 }
	};

	for (const auto& test : testing_data) {
		const auto text = std::get<0>(test);
		const auto pattern = std::get<1>(test);
		const auto correct_result = std::get<2>(test);

		const auto result = boyer_moore(text, pattern);

		std::cout
			<< text << " // " << pattern << " // "
			<< correct_result << ", " << result << '\n';

		cr_assert(result == correct_result);
	}
}
