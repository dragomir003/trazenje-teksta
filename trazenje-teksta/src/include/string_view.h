#pragma once

#include <cstddef>

struct StringView {
    const char* start;
    size_t len;

    StringView(const char* s);
    StringView(const char* s, const size_t len);

    StringView(const StringView& other) = default;
    StringView(StringView&& other) = default;

    auto operator=(const StringView& other) -> StringView& = default;
    auto operator=(StringView&& other) -> StringView& = default;

    friend auto operator==(const StringView& lhs, const StringView& rhs) -> bool;
    friend auto operator!=(const StringView& lhs, const StringView& rhs) -> bool;
    friend auto operator<(const StringView& lhs, const StringView& rhs) -> bool;
    friend auto operator>(const StringView& lhs, const StringView& rhs) -> bool;
};
