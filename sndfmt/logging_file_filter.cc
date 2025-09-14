// Copyright (C) 2025 The sndfmt authors. All rights reserved.
#include "sndfmt/logging_file_filter.h"

#include <sys/types.h>

#include <memory>

#include "absl/log/log.h"
#include "absl/strings/str_format.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"

namespace sndfmt {

LoggingFileFilter::LoggingFileFilter(std::unique_ptr<FileInterface> file)
    : file_(std::move(file)) {}

LoggingFileFilter::~LoggingFileFilter() {}

ssize_t LoggingFileFilter::PRead(void* buf, size_t count, off_t offset) {
  const absl::Time start = absl::Now();

  const ssize_t result = file_->PRead(buf, count, offset);

  const absl::Duration elapsed = absl::Now() - start;

  LOG(INFO) << "LoggingFileFilter::PRead() buf: " << absl::StrFormat("%p", buf)
            << " count: " << count << " offset: " << offset
            << " result: " << result << " (elapsed time: " << elapsed << ")";
  return result;
}

ssize_t LoggingFileFilter::PWrite(void* buf, size_t count, off_t offset) {
  const absl::Time start = absl::Now();

  const ssize_t result = file_->PWrite(buf, count, offset);

  const absl::Duration elapsed = absl::Now() - start;

  LOG(INFO) << "LoggingFileFilter::PWrite() buf: " << absl::StrFormat("%p", buf)
            << " count: " << count << " offset: " << offset
            << " result: " << result << " (elapsed time: " << elapsed << ")";

  return result;
}

void LoggingFileFilter::Close() {
  const absl::Time start = absl::Now();

  file_->Close();

  const absl::Duration elapsed = absl::Now() - start;

  LOG(INFO) << "LoggingFileFilter::Close() (elapsed time: " << elapsed << ")";
}

}  // namespace sndfmt
