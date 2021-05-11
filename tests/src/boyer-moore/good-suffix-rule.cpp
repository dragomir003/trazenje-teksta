#include <criterion/criterion.h>

extern auto create_gsr_table(const char*) -> std::vector<int>;
extern auto good_suffix_rule(const std::vector<int>&, int) -> int;

Test(boyer_moore, good_suffix_rule) {
    const auto pattern = "ABC";

    const auto table = create_gsr_table(pattern);

    for (int i = -1; i < table.size() - 1; ++i) {
        cr_assert(good_suffix_rule(table, i) == 4);
    } 
}