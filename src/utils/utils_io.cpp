//
// Created by 86759 on 2021/6/24.
//

#include "utils_io.h"
#include "utils_string.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

std::vector<std::string> get_file_lines(const std::string& path) {
    ifstream file_stream(path);
//    file_stream.open(path);
    if (!file_stream.is_open()) {
        cout << "Error opening file_stream: " << path << endl; exit (1);
    }
    std::ostringstream buffer;
    buffer << file_stream.rdbuf();
    std::string source_content = buffer.str();
    std::vector<std::string> v = split_by_break_line(source_content);
    return v;
}
