config_setting(
    name="unit_testing",
    define_values = {"UNIT_TESTING": "true"}
)
config_setting(
    name="benchmarking",
    define_values = {"BENCHMARKING": "true"}
)
config_setting(
    name="optimized",
    define_values = {"OPTIMIZED": "true"}
)
config_setting(
    name="debug",
    define_values = {"DEBUG": "true"}
)

config_setting(
    name="profile",
    define_values = {"PROFILE": "true"}
)
config_setting(
    name="profile_optimized",
    define_values = {"PROFILE_OPTIMIZED": "true"}
)

load("//:common_copts.bzl", "copts", "linkopts")

cc_library(
    name = "libmarkley",
    srcs = glob([
        "src/**/*.cpp",
        "src/*.cpp",
        "include/*.hpp"
    ]),
    includes = ["include", "src"],
    strip_include_prefix = "include",
    copts = copts(),
    linkopts = linkopts(),
    deps = [
        "@eigen//:eigen"
    ],
    visibility= ["//visibility:public"],
    linkstatic=True
)