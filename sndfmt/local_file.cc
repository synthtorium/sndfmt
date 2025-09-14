// Copyright (C) 2025 The sndfmt authors. All rights reserved.
#include "sndfmt/local_file.h"

#include <fcntl.h>
#include <unistd.h>

#include <cerrno>
#include <cstring>

#include "absl/log/check.h"
#include "absl/log/log.h"
#include "absl/status/status.h"
#include "absl/strings/str_cat.h"

namespace sndfmt {

LocalFile::LocalFile(int fd) : fd_(fd) {
  CHECK_GE(fd_, 0) << "invalid descriptor";
}

LocalFile::~LocalFile() { Close(); }

absl::StatusOr<FileInterface*> LocalFile::Open(const std::string& path,
                                               int flags) {
  const int fd = open(path.c_str(), flags);
  if (fd < 0) {
    const int error_num = errno;
    return absl::NotFoundError(
        absl::StrCat("Failed to open '", path, "': ", strerror(error_num)));
  }
  return new LocalFile(fd);
}

absl::StatusOr<FileInterface*> LocalFile::Open(const std::string& path,
                                               int flags, mode_t mode) {
  const int fd = open(path.c_str(), flags, mode);
  if (fd < 0) {
    const int error_num = errno;
    return absl::NotFoundError(
        absl::StrCat("Failed to open '", path, "': ", strerror(error_num)));
  }
  return new LocalFile(fd);
}

ssize_t LocalFile::PRead(void* buf, size_t count, off_t offset) {
  CHECK_GE(fd_, 0) << "invalid descriptor";
  return pread(fd_, buf, count, offset);
}

ssize_t LocalFile::PWrite(void* buf, size_t count, off_t offset) {
  CHECK_GE(fd_, 0) << "invalid descriptor";
  return pwrite(fd_, buf, count, offset);
}

void LocalFile::Close() {
  CHECK_GE(fd_, 0) << "invalid descriptor";
  const int status = close(fd_);
  LOG_IF(WARNING, status < 0) << "close() failed with error " << errno;
  fd_ = -1;
}

}  // namespace sndfmt
