// Copyright (C) 2025 The sndfmt authors. All rights reserved.
#ifndef SNDFMT_FILE_INTERFACE_H_
#define SNDFMT_FILE_INTERFACE_H_

#include <sys/types.h>

namespace sndfmt {

class FileInterface {
 public:
  virtual ~FileInterface() = default;

  virtual ssize_t PRead(void* buf, size_t count, off_t offset) = 0;
  virtual ssize_t PWrite(void* buf, size_t count, off_t offset) = 0;
  virtual void Close() = 0;

 protected:
  FileInterface() = default;
  FileInterface(const FileInterface&) = delete;
  FileInterface& operator=(const FileInterface&) = delete;
  FileInterface(FileInterface&&) = delete;
  FileInterface& operator=(FileInterface&&) = delete;
};

}  // namespace sndfmt

#endif  // SNDFMT_FILE_INTERFACE_H_
