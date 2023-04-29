// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include "../Global.h"
#include "VectorBase.hpp"

class Vec2 : public VectorBase<Vec2, float, float> {
public:
    float x, y;
    Vec2() = default;
    Vec2(float a, float b) : x(a), y(b){};

    template <typename T>
    [[nodiscard]] constexpr T& get(size_t index) {
        switch (index) {
            case 1:
                return y;
            default:
                return x;
        }
    }

    template <typename T>
    [[nodiscard]] constexpr T get(size_t index) const {
        switch (index) {
            case 1:
                return y;
            default:
                return x;
        }
    }

    MCAPI static class Vec2 const LOWEST;
    MCAPI static class Vec2 const MAX;
    MCAPI static class Vec2 const MIN;
    MCAPI static class Vec2 const NEG_UNIT_X;
    MCAPI static class Vec2 const NEG_UNIT_Y;
    MCAPI static class Vec2 const ONE;
    MCAPI static class Vec2 const UNIT_X;
    MCAPI static class Vec2 const UNIT_Y;
    MCAPI static class Vec2 const ZERO;
};

namespace std {

template <>
struct hash<Vec2> {
    std::size_t operator()(Vec2 const& pos) const noexcept {
        return pos.hash();
    }
};

} // namespace std
