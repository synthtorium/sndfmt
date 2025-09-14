cc_library(
    visibility = [
        "//visibility:public",
    ],
    name = "sndfmt",
    srcs = [
        "local_file.cc",
			  "sndfmt.cc",
    ],
    hdrs = [
        "file_interface.h",
				"file_system_interface.h",
        "local_file.h",
				"sndfmt.h",
    ],
    deps = [
        "@abseil-cpp//absl/log:check",
        "@abseil-cpp//absl/log:log",
        "@abseil-cpp//absl/status:status",
				"@abseil-cpp//absl/status:statusor",
    ],
)
