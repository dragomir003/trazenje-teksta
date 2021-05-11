#include "./boyer-moore/bcr.h"
#include "./boyer-moore/gsr.h"

auto boyer_moore(const char* text, const char* pattern) -> int {
	const auto textlen = std::strlen(text);
	const auto pattlen = std::strlen(pattern);

	const auto bcr_table = create_bcr_table(pattern);
	const auto gsr_table = create_gsr_table(pattern);

	for (int i = 0; i < textlen - pattlen + 1;) {
		for (int j = pattlen - 1; j >= 0; --j) {
			if (pattern[j] == text[i + j]) {
				if (j == 0) {
					return i;
				}
				continue;
			}
			const auto offset = pattlen - 1 - j;

			const auto shift = std::max(good_suffix_rule(gsr_table, j), bad_character_rule(bcr_table, offset, text[i + j]));
			i += shift;
			break;
		}
	}
	return -1;
}
