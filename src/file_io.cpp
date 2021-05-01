#include <fstream>
#include <sstream>
#include "file_io.h"

using namespace winter;

std::string file_io::read_all_text(std::string filename) {
    std::ifstream ifs;
    ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    ifs.open(filename.c_str());
    std::stringstream ss;
    ss << ifs.rdbuf();
    return ss.str();
}
