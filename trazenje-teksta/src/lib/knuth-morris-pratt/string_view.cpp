#include "../../include/string_view.h"

#include <cstring>

StringView::StringView(const char* s)
    : start(s), len(std::strlen(s)) {}

StringView::StringView(const char* s, const size_t len)
    : start(s), len(len) {}

auto operator==(const StringView& lhs, const StringView& rhs) -> bool {
    if (lhs.len != rhs.len)
        return false;
    return !std::memcmp(lhs.start, rhs.start, lhs.len);
}

auto operator!=(const StringView& lhs, const StringView& rhs) -> bool {
    return !(lhs == rhs);
}

auto operator>(const StringView& lhs, const StringView& rhs) -> bool {
    const auto sum = [](const StringView& x) {
        size_t sum = 0;
        for (size_t i = 0; i < x.len; ++i) {
            sum += *(x.start + i);
        }
        return sum;
    };

    const auto lhs_sum = sum(lhs);
    const auto rhs_sum = sum(rhs);

    return lhs_sum > rhs_sum;
}

auto operator<(const StringView& lhs, const StringView& rhs) -> bool {
    const auto sum = [](const StringView& x) {
        size_t sum = 0;
        for (size_t i = 0; i < x.len; ++i) {
            sum += *(x.start + i);
        }
        return sum;
    };

    const auto lhs_sum = sum(lhs);
    const auto rhs_sum = sum(rhs);

    return lhs_sum < rhs_sum;
}