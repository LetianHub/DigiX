cc_binary(
    name = "register_test",
    srcs = [
        "register.cc",
        "register.h",
        "test_register.cc",
    ],
    deps = [
        "//main/basic_unit:basic_unit_lib",
    ],
)

cc_library(
    name = "register_lib",
    srcs = [
        "register.cc",
        "register.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//main/basic_unit:basic_unit_lib",
    ],
)
