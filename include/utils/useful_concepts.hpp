#pragma once
#include <concepts>
#include <type_traits>

namespace markley {
    /// @brief A concept for "pure numbers" (i.e. no bools, strings, user-defined types, etc.)
    template <typename T>
    concept NumberLike =
        std::is_arithmetic_v<std::remove_cvref_t<T>> &&
        !std::same_as<std::remove_cvref_t<T>, bool>;
}