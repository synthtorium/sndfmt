// Copyright (C) 2025 The sndfmt authors. All rights reserved.
#ifndef SNDFMT_LOGGING_FILE_FILTER_H_
#define SNDFMT_LOGGING_FILE_FILTER_H_

#include <sys/types.h>

#include <memory>

#include "sndfmt/file_interface.h"

namespace sndfmt {

class LoggingFileFilter : public FileInterface {
 public:
  LoggingFileFilter(std::unique_ptr<FileInterface> file);
  virtual ~LoggingFileFilter();

  ssize_t PRead(void* buf, size_t count, off_t offset) override;
  ssize_t PWrite(void* buf, size_t count, off_t offset) override;
  void Close() override;

 protected:
  LoggingFileFilter(const LoggingFileFilter&) = delete;
  LoggingFileFilter& operator=(const LoggingFileFilter&) = delete;
  LoggingFileFilter(LoggingFileFilter&&) = delete;
  LoggingFileFilter& operator=(LoggingFileFilter&&) = delete;

  std::unique_ptr<FileInterface> file_;
};

}  // namespace sndfmt

#endif  // SNDFMT_LOGGING_FILE_FILTER_H_
