#pragma once

#include <vector>

using GsrTable = std::vector<int>;

auto create_gsr_table(const char* pattern) -> GsrTable;
auto good_suffix_rule(const GsrTable& table, const int offset) -> int;