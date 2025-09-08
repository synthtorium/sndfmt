// Copyright (C) 2025 The sndfmt authors. All rights reserved.
#ifndef SNDFMT_FILE_INTERFACE_H_
#define SNDFMT_FILE_INTERFACE_H_

namespace sndfmt {

class FileInterface {
 public:
  virtual ~FileInterface() = default;

 protected:
  FileInterface() = default;
  FileInterface(const FileInterface&) = delete;
  FileInterface& operator=(const FileInterface&) = delete;
  FileInterface(FileInterface&&) = delete;
  FileInterface& operator=(FileInterface&&) = delete;
};

}  // namespace sndfmt

#endif  // SNDFMT_FILE_INTERFACE_H_
