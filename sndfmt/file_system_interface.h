// Copyright (C) 2025 The sndfmt authors. All rights reserved.
#ifndef SNDFMT_FILE_SYSTEM_INTERFACE_H_
#define SNDFMT_FILE_SYSTEM_INTERFACE_H_

#include <string_view>

#include "absl/status/statusor.h"
#include "sndfmt/file_interface.h"

namespace sndfmt {

class FileSystemInterface {
 public:
  virtual ~FileSystemInterface() = default;

 protected:
  FileSystemInterface() = default;
  FileSystemInterface(const FileSystemInterface&) = delete;
  FileSystemInterface& operator=(const FileSystemInterface&) = delete;
  FileSystemInterface(FileSystemInterface&&) = delete;
  FileSystemInterface& operator=(FileSystemInterface&&) = delete;
};

}  // namespace sndfmt

#endif  // SNDFMT_FILE_SYSTEM_INTERFACE_H_
