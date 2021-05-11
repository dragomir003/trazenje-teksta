#include "./bcr.h"

auto create_bcr_table(const char* pattern) -> BcrTable {
	BcrTable table;

	const auto len = std::strlen(pattern);
	auto assigned_to_last = false;
	const auto last = *(pattern + len - 1);

	for (int i = 0; i < len - 1; ++i) {
		const auto c = pattern[i];

		if (c == last)
			assigned_to_last = true;
		
		table[c] = len - i - 1;
	}

	if (!assigned_to_last)
		table[last] = len;
	table[0] = len;

	return table;
}

auto bad_character_rule(const BcrTable& table, int offset, char c) -> int {
	const auto move = [table, c] {
		try {
			return table.at(c);
		} catch (std::exception e) {
			return table.at(0);
		}
	}();

	return move - offset;
}
