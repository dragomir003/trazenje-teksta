#pragma once

#include <vector>

using KmpTable = std::vector<int>;

auto create_kmp_table(const char* pattern) -> KmpTable;

auto knuth_morris_pratt(const char* text, const char* pattern) -> int;