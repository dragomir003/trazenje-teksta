#include <criterion/criterion.h>

#include <vector>
#include <map>

using KmpTable = std::vector<int>;

extern auto knuth_morris_pratt(const char*, const char*) -> int;

#include <iostream>

Test(knuth_morris_pratt, knuth_morris_pratt_search) {
    const std::map<std::pair<const char*, const char*>, int> results{
        { { "abcd", "a" }, 0 },
        { { "hello", "ll" }, 2 },
        { { "There is something to be found.", "some" }, 9 },
        { { "There is nothing to be found.", "some" }, -1 },
    };

    for (const auto& kvp : results) {
        const char *text, *pattern;
        std::pair<const char*, const char*> tp;
        int correct_result;

        std::tie(tp, correct_result) = kvp;
        std::tie(text, pattern) = tp;

        const auto result = knuth_morris_pratt(text, pattern);

        std::cout << result << ' ' << correct_result << '\n';

        cr_assert(result == correct_result);
    }
}