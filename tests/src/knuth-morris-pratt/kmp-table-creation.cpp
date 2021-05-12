#include <criterion/criterion.h>

#include <string_view.h>

#include <vector>
#include <map>
#include <array>

using KmpTable = std::vector<int>;

extern auto create_kmp_table(const char *) -> KmpTable;
extern auto find_prefixes(const StringView&) -> std::vector<StringView>;
extern auto find_suffixes(const StringView&) -> std::vector<StringView>;
extern auto find_prefix_suffixes(const StringView&) -> std::vector<StringView>;

template<typename T>
auto are_vectors_equal(const std::vector<T>& lhs, const std::vector<T>& rhs) -> bool {
    if (lhs.size() != rhs.size())
        return false;

    for (size_t i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i])
            return false;
    }

    return true;
}

Test(knuth_morris_pratt, kmp_table_creation) {
    constexpr size_t test_samples = 6;

    const std::array<const char *, test_samples> patterns{ "aabc", "tooth", "pattern", "123123", "clear", "abcababc" };
    const std::array<KmpTable, test_samples> tables{ KmpTable{ -1, 0, -1, -1 }, { -1, -1, -1, 0, -1 }, { -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, 0, 1, 2 }, { -1, -1, -1, -1, -1 },  { -1, -1, -1, 0, 1, 0, 1, 2 }};

    for (size_t i = 0; i < test_samples; ++i) {
        const auto pattern = patterns[i];
        const auto& correct_table = tables[i];

        const auto table = create_kmp_table(pattern);

        cr_assert(are_vectors_equal<int>(table, correct_table));
    }
}

Test(knuth_morris_pratt, find_prefixes) {
    const std::map<StringView, std::vector<StringView>> prefixes{
        { "aabc", { "", "a", "aa", "aab" } },
        { "pattern", { "", "p", "pa", "pat", "patt", "patte", "patter" }}
    };

    for (const auto& kvp : prefixes) {
        const auto s = kvp.first;
        const auto correct = kvp.second;

        const auto pres = find_prefixes(s.start);

        cr_assert(are_vectors_equal<StringView>(correct, pres));
    }
}

Test(knuth_morris_pratt, find_suffixes) {
    const std::map<StringView, std::vector<StringView>> suffixes{
        { "aabc", { "", "c", "bc", "abc" } },
        { "pattern", { "", "n", "rn", "ern", "tern", "ttern", "attern" }}
    };

    for (const auto& kvp : suffixes) {
        const auto s = kvp.first;
        const auto correct = kvp.second;

        const auto suffs = find_suffixes(s);

        cr_assert(are_vectors_equal<StringView>(correct, suffs));
    }
}

Test(knuth_morris_pratt, find_prefix_suffixes) {
    const std::map<StringView, std::vector<StringView>> pss{
        { "aabc", { "" } },
        { "abca", { "", "a" } },
        { "abcabc", { "", "abc" } }
    };

    for (const auto& kvp : pss) {
        const auto s = kvp.first;
        const auto correct = kvp.second;

        const auto ps = find_prefix_suffixes(s);

        cr_assert(are_vectors_equal<StringView>(correct, ps));
    }
}