// Copyright (C) 2025 The sndfmt authors. All rights reserved.
#include "sndfmt/local_file.h"

#include <unistd.h>

#include "absl/status/status.h"

namespace sndfmt {

LocalFile::LocalFile(int fd) : fd_(fd) {
  // TODO: CHECK() that fd >= 0
}

LocalFile::~LocalFile() { Close(); }

absl::StatusOr<FileInterface*> LocalFile::Open(std::string_view path) {
  return absl::UnimplementedError("not implemented");
}

ssize_t LocalFile::PRead(void* buf, size_t count, off_t offset) {
  // assert(fd_ >= 0);
  return pread(fd_, buf, count, offset);
}

ssize_t LocalFile::PWrite(void* buf, size_t count, off_t offset) {
  // assert(fd_ >= 0);
  return pwrite(fd_, buf, count, offset);
}

void LocalFile::Close() {
  // assert(fd_ >= 0);
  const int status = close(fd_);
  // TODO: log status if no zero
  (void)status;
  fd_ = -1;
}

}  // namespace sndfmt
