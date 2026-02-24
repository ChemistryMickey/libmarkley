#pragma once
#include <eigen3/Eigen/Dense>
#include <ranges>
#include <numeric>

#include "utils/useful_concepts.hpp"

namespace markley {
    /// @brief The $L_{\inf}$ norm is defined as $\norm{f}_{\infty}$
    ///
    /// This is the "uniform norm" (or "sup norm") which assigns to real or complex-valued bounded functions, $f$, a non-negative number.
    /// For a vector $x_{i}$, this looks like $\norm{x_{i}}_{infty} = max(\abs{x_{0}}, \abs{x_{1}}, ..., \abs{x_{n}})$
    /// @tparam N The size of the vector. Default given as 3.
    /// @param v The vector whose norm you want to find
    /// @return The "L-infinity norm" of the input vector v.
    template<size_t N = 3, NumberLike T>
    T l_infinity_norm(const Eigen::Vector<T, N>& v) {
        if constexpr (N == 0) {
            // Dunno why you'd do that but you do you.
            return T{0};
        }

        if constexpr (std::is_unsigned_v<T>) {
            // std::abs is ambiguous w.r.t. unsigned types because it can implicity convert into any signed type so we gotta remove that.
            return std::ranges::max(v);
        }
        else {
            return std::ranges::max(v | std::views::transform([](T x) {return std::abs(x);}));
        }
    }

    template<size_t N = 3, NumberLike T>
    T l_2_norm(const Eigen::Vector<T, N>& v) {
        if constexpr (N == 0) {
            // Dunno why you'd do that but you do you.
            return T{0};
        }

        auto square_vec = v | std::views::transform([](T x) {return std::pow(x, T{2});});
        return std::accumulate(square_vec.begin(), square_vec.end(), 0);
    }
}