#include <stdlib.h>

#include <iostream>
#include <memory>

#include "sndfmt/file_interface.h"
#include "sndfmt/local_file.h"
#include "sndfmt/logging_file_filter.h"

using sndfmt::FileInterface;
using sndfmt::LocalFile;
using sndfmt::LoggingFileFilter;
using std::cerr;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  auto result = LocalFile::Open("/etc/passwd", O_RDONLY);
  if (!result.ok()) {
    cerr << result << endl;
    return EXIT_FAILURE;
  }
  std::unique_ptr<FileInterface> tmp_file(result.value());
  auto file = std::make_unique<LoggingFileFilter>(std::move(tmp_file));

  ssize_t offset = 0;
  for (;;) {
    char buf[2] = {0};
    const ssize_t num_read = file->PRead(buf, 1, offset);
    if (num_read <= 0) {
      break;
    }
    buf[1] = 0;
    cout << buf;
    ++offset;
  }

  return 0;
}
