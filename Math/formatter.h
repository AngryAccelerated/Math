#ifndef FORMATTER_H
#define FORMATTER_H

#include "spdlog/spdlog.h"
#include "spdlog/fmt/fmt.h"
#include "include/linear.h"

template<> struct fmt::formatter<Math::Vec2> : formatter<float> {
    template <typename FormatContext>
    auto format(const Math::Vec2& vec, FormatContext& ctx) {
        return fmt::format_to(ctx.out(), "Vec2({:.3f}, {:.3f})", vec.x, vec.y);
    }
};
template<> struct fmt::formatter<Math::Vec3> : formatter<float> {
    template <typename FormatContext>
    auto format(const Math::Vec3& vec, FormatContext& ctx) {
        return fmt::format_to(ctx.out(), "Vec3({:.3f}, {:.3f}, {:.3f})", vec.x, vec.y, vec.z);
    }
};
template<> struct fmt::formatter<Math::Vec4> : formatter<float> {
    template <typename FormatContext>
    auto format(const Math::Vec4& vec, FormatContext& ctx) {
        return fmt::format_to(ctx.out(), "Vec4({:.3f}, {:.3f}, {:.3f}, {:.3f})", vec.x, vec.y, vec.z, vec.w);
    }
};
template<> struct fmt::formatter<Math::Mat2> : formatter<float> {
    template <typename FormatContext>
    auto format(const Math::Mat2& mat, FormatContext& ctx) {
        return fmt::format_to(ctx.out(),
            "\n[{:.3f}, {:.3f}]"
            "\n[{:.3f}, {:.3f}]",
            mat[0][0], mat[1][0],
            mat[0][1], mat[1][1]);
    }
};
template<> struct fmt::formatter<Math::Mat3> : formatter<float> {
    template <typename FormatContext>
    auto format(const Math::Mat3& mat, FormatContext& ctx) {
        return fmt::format_to(ctx.out(),
            "\n[{:.3f}, {:.3f}, {:.3f}]"
            "\n[{:.3f}, {:.3f}, {:.3f}]"
            "\n[{:.3f}, {:.3f}, {:.3f}]",
            mat.e11(), mat.e12(), mat.e13(),
            mat.e21(), mat.e22(), mat.e23(),
            mat.e31(), mat.e32(), mat.e33());
    }
};
template<> struct fmt::formatter<Math::Mat4> : formatter<float> {
    template <typename FormatContext>
    auto format(const Math::Mat4& mat, FormatContext& ctx) {
        return fmt::format_to(ctx.out(),
            "\n[{:.3f}, {:.3f}, {:.3f}, {:.3f}]"
            "\n[{:.3f}, {:.3f}, {:.3f}, {:.3f}]"
            "\n[{:.3f}, {:.3f}, {:.3f}, {:.3f}]"
            "\n[{:.3f}, {:.3f}, {:.3f}, {:.3f}]",
            mat.e11(), mat.e12(), mat.e13(), mat.e14(),
            mat.e21(), mat.e22(), mat.e23(), mat.e24(),
            mat.e31(), mat.e32(), mat.e33(), mat.e34(),
            mat.e41(), mat.e42(), mat.e43(), mat.e44());
    }
};
template<> struct fmt::formatter<Math::Quat> : formatter<float> {
    template <typename FormatContext>
    auto format(const Math::Quat& quat, FormatContext& ctx) {
        return fmt::format_to(ctx.out(), "Quat[{:.3f}, ({:.3f}, {:.3f}, {:.3f})]", quat.s, quat.x, quat.y, quat.z);
    }
};

#endif