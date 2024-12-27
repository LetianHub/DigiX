cc_binary(
    name = "program_counter_test",
    srcs = [
        "program_counter.cc",
        "program_counter.h",
        "test_program_counter.cc",
    ],
    deps = [
        "//main/basic_unit:basic_unit_lib",
    ],
)

cc_library(
    name = "program_counter_lib",
    srcs = [
        "program_counter.cc",
        "program_counter.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//main/basic_unit:basic_unit_lib",
    ],
)
