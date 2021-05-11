#include "./gsr.h"

#include <cstring>

auto full_suffix_match(
    std::vector<int>& shift_array,
    std::vector<int>& border_array,
    const char* pattern) -> void
{
    const auto n = shift_array.size();

    border_array[n] = n + 1;

    for (int i = n, j = n + 1; i > 0;) {
        while (j <= n && pattern[i - 1] != pattern[j - 1]) {
            if (!shift_array[j])
                shift_array[j] = j - i;
            j = border_array[j];
        }
        --i, --j;
        border_array[i] = j;
    }
}

auto partial_suffix_match(
    std::vector<int>& shift_array,
    std::vector<int>& border_array,
    const char* pattern) -> void
{
    const auto n = shift_array.size();

    for (int i = 0, j = border_array[0]; i < n; ++i) {
        if (!shift_array[i])
            shift_array[i] = j;
        if (i == j)
            j = border_array[j];
    }
}

auto create_gsr_table(const char* pattern) -> GsrTable {
    const auto pattlen = std::strlen(pattern);
    std::vector<int> shift_array(pattlen, 0);
    std::vector<int> border_array(pattlen, 0);

    full_suffix_match(shift_array, border_array, pattern);
    partial_suffix_match(shift_array, border_array, pattern);

    return shift_array;
}

auto good_suffix_rule(const GsrTable& table, const int j) -> int {
    return table[j + 1];
}