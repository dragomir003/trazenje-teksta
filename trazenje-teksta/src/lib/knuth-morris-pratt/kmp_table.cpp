#include "./kmp.h"

#include "../../include/string_view.h"

#include <cstring>

auto find_prefixes(const StringView& s) -> std::vector<StringView> {    
    std::vector<StringView> prefixes;

    for (size_t i = 0; i < s.len; ++i) {
        prefixes.emplace_back(s.start, i);
    }

    return prefixes;
}

auto find_suffixes(const StringView& s) -> std::vector<StringView> {    
    std::vector<StringView> suffixes;

    for (size_t i = s.len; i > 0; --i) {
        suffixes.emplace_back(s.start + i, s.len - i);
    }

    return suffixes;
}

auto find_prefix_suffixes(const StringView& pattern) -> std::vector<StringView> {
    const auto prefixes = find_prefixes(pattern);
    const auto suffixes = find_suffixes(pattern);

    std::vector<StringView> pss;
    for (size_t i = 0; i < prefixes.size(); ++i) {
        if (prefixes[i] == suffixes[i])
            pss.push_back(prefixes[i]);
    }

    return pss;
}

auto create_kmp_table(const char* pattern) -> KmpTable {
    const auto len = std::strlen(pattern);
    
    KmpTable result;
    result.push_back(-1);

    for (size_t i = 1; i < len; ++i) {
        const StringView s(pattern, i + 1);
        const auto longest_prefix_suffix = find_prefix_suffixes(s).back().len;

        result.push_back(longest_prefix_suffix - 1);
    }

    return result;
}