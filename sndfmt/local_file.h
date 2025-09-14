// Copyright (C) 2025 The sndfmt authors. All rights reserved.
#ifndef SNDFMT_LOCAL_FILE_H_
#define SNDFMT_LOCAL_FILE_H_

#include <fcntl.h>

#include <string>

#include "absl/status/statusor.h"
#include "file_interface.h"

namespace sndfmt {

class LocalFile : public FileInterface {
 public:
  ~LocalFile();

  static absl::StatusOr<FileInterface*> Open(const std::string& path,
                                             int flags);
  static absl::StatusOr<FileInterface*> Open(const std::string& path, int flags,
                                             mode_t mode);

  ssize_t PRead(void* buf, size_t count, off_t offset) override;
  ssize_t PWrite(void* buf, size_t count, off_t offset) override;
  void Close() override;

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
