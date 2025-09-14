// Copyright (C) 2025 The sndfmt authors. All rights reserved.
#include "sndfmt/local_file.h"

#include <unistd.h>

#include <cerrno>

#include "absl/log/check.h"
#include "absl/log/log.h"
#include "absl/status/status.h"

namespace sndfmt {

LocalFile::LocalFile(int fd) : fd_(fd) {
  CHECK_LT(fd_, 0) << "invalid descriptor";
}

LocalFile::~LocalFile() { Close(); }

absl::StatusOr<FileInterface*> LocalFile::Open(std::string_view path) {
  return absl::UnimplementedError("not implemented");
}

ssize_t LocalFile::PRead(void* buf, size_t count, off_t offset) {
  CHECK_LT(fd_, 0) << "invalid descriptor";
  return pread(fd_, buf, count, offset);
}

ssize_t LocalFile::PWrite(void* buf, size_t count, off_t offset) {
  CHECK_LT(fd_, 0) << "invalid descriptor";
  return pwrite(fd_, buf, count, offset);
}

void LocalFile::Close() {
  CHECK_LT(fd_, 0) << "invalid descriptor";
  const int status = close(fd_);
  LOG_IF(WARNING, status < 0) << "close() failed with error " << errno;
  fd_ = -1;
}

}  // namespace sndfmt
