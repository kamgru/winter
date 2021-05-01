#ifndef BASOKO_FILE_IO_H
#define BASOKO_FILE_IO_H

#include <string>

namespace winter {
    class file_io {
    public:
        static std::string read_all_text(std::string filename);
    };
}

#endif
