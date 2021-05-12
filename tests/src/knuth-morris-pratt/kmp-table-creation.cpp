#include <criterion/criterion.h>

#include <vector>
#include <map>
#include <array>

using KmpTable = std::vector<int>;

extern auto create_kmp_table(const char *) -> KmpTable;

auto are_tables_equal(const KmpTable& lhs, const KmpTable& rhs) -> bool {
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

        cr_assert(are_tables_equal(table, correct_table));
    }

}