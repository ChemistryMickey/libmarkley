load("//:common_copts.bzl", "copts", "linkopts") 
load("//:generate_tests.bzl", "generate_tests")

deps = [
    "@googletest//:gtest",
    "@googletest//:gtest_main",
    "@eigen//:eigen",
    "//:libmarkley"
]
# Unit tests
UT_test_glob_matcher = "UT_*.cpp"
UT_test_names = generate_tests("UT_*.cpp", deps, [])

# Integration tests
IT_test_glob_matcher = "IT_*.cpp"
IT_test_names = generate_tests("IT_*.cpp", deps, [])

test_suite(
    name = "cached",
    tests = UT_test_names + IT_test_names
)

cc_test(
    name = "all",
    size = "small",
    srcs = [file for file in glob([UT_test_glob_matcher, IT_test_glob_matcher], allow_empty=True)],
    copts = copts(),
    linkopts = linkopts(),
)