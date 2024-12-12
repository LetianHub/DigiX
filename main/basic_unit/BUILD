cc_library(
    name = "basic_unit_lib",
    srcs = ["basic_unit.cc"],
    hdrs = ["basic_unit.h"],
    visibility = ["//visibility:public"],
)

# cc_test(
#     name = "basic_unit_test",
#     srcs = ["basic_unit_test.cc"],
#     deps = [
#         ":basic_unit",
#         "@com_google_googletest//:gtest_main",
#     ],
# )

cc_binary(
    name = "basic_unit_test",
    srcs = [
        "basic_unit.cc",
        "basic_unit.h",
        "test_basic_unit.cc",
    ],
    deps = [
    ],
)
