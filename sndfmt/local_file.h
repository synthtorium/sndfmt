// Copyright (C) 2025 The sndfmt authors. All rights reserved.
#ifndef SNDFMT_LOCAL_FILE_H_
#define SNDFMT_LOCAL_FILE_H_

#include <string_view>

#include "absl/status/statusor.h"
#include "file_interface.h"

namespace sndfmt {

class LocalFile {
 public:
  ~LocalFile();

  static absl::StatusOr<FileInterface*> Open(std::string_view path);

  virtual ssize_t PRead(void* buf, size_t count, off_t offset);
  virtual ssize_t PWrite(void* buf, size_t count, off_t offset);
  virtual void Close();

 protected:
  LocalFile(int fd);

  LocalFile(const LocalFile&) = delete;
  LocalFile& operator=(const LocalFile&) = delete;
  LocalFile(LocalFile&&) = delete;
  LocalFile& operator=(LocalFile&&) = delete;

  int fd_;
};

}  // namespace sndfmt

#endif  // SNDFMT_LOCAL_FILE_H_
