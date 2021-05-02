#ifndef WINTER_FILE_IO_H
#define WINTER_FILE_IO_H

#include <string>

namespace winter {
    class file_io {
    public:
        static std::string read_all_text(std::string filename);
    };
}

#endif
