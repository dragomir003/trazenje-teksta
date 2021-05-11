#pragma once

#include <map>
#include <cstring>

using BcrTable = std::map<char, int>;

auto create_bcr_table(const char* pattern) -> BcrTable;
auto bad_character_rule(const BcrTable& table, int offset, char c) -> int;