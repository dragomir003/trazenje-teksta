#include "./knuth-morris-pratt/kmp.h"

#include <cstring>

auto knuth_morris_pratt(const char* text, const char* pattern) -> int {
    const auto table = create_kmp_table(pattern);

    const auto text_len = std::strlen(text);
    const auto patt_len = table.size();

    for (int i = 0, j = -1; i < text_len;) {
        if (text[i] != pattern[j + 1]) {
            j = table[j + 1];
            ++i;
            continue;
        }
        if (j + 1 == patt_len - 1) {
            return i - j - 1;
        }
        ++i, ++j;
    }
    return -1;
}