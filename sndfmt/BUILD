cc_library(
    visibility = [
        "//visibility:public",
    ],
    name = "sndfmt",
    srcs = [
        "local_file.cc",
				"logging_file_filter.cc",
			  "sndfmt.cc",
    ],
    hdrs = [
        "file_interface.h",
				"file_system_interface.h",
        "local_file.h",
				"logging_file_filter.h",
				"sndfmt.h",
    ],
    deps = [
        "@abseil-cpp//absl/log:check",
        "@abseil-cpp//absl/log:log",
        "@abseil-cpp//absl/status:status",
				"@abseil-cpp//absl/status:statusor",
				"@abseil-cpp//absl/strings",
				"@abseil-cpp//absl/time:time",
    ],
)

cc_binary(
    visibility = [
        "//visibility:public",
    ],
    name = "demo",
    srcs = [
        "main.cc",
    ],
    deps = [
        "sndfmt",
    ],
)
