#include <criterion/criterion.h>

extern auto create_gsr_table(const char*) -> std::vector<int>;

Test(boyer_moore, gsr_table_creation) {
    const auto pattern = "ABC";

    const std::array<int, 3> correct_results { 3, 3, 3 };

    const auto table = create_gsr_table(pattern);

    for (int i = 0; i < correct_results.size(); ++i) {
        cr_assert(table[i] == correct_results[i]);
    } 
}