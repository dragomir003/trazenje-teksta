#include <map>
#include <cstring>

using BcrTable = std::map<char, int>;

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

	return move - offset <= 0 ? 1 : move - offset;
}

auto boyer_moore(const char* text, const char* pattern) -> int {
	const auto textlen = std::strlen(text);
	const auto pattlen = std::strlen(pattern);

	const auto bcr_table = create_bcr_table(pattern);

	for (int i = 0; i < textlen - pattlen + 1;) {
		for (int j = pattlen - 1; j >= 0; --j) {
			if (pattern[j] == text[i + j]) {
				if (j == 0) {
					return i;
				}
				continue;
			}
			const auto offset = pattlen - 1 - j;

			const auto shift = bad_character_rule(bcr_table, offset, text[i + j]);
			i += shift;
			break;
		}
	}
	return -1;
}
