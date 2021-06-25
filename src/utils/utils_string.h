//
// Created by 86759 on 2021/6/22.
//

#ifndef VERILOG_PREPROCESSOR_UTILS_STRING_H
#define VERILOG_PREPROCESSOR_UTILS_STRING_H

#include <vector>
#include <string>

std::string replace_all(const std::string &text, const std::string &old_value, const std::string &new_value);
std::vector<std::string> split(const std::string &text, const std::string &delim);
std::vector<std::string> split_by_break_line(const std::string &text);

#endif //VERILOG_PREPROCESSOR_UTILS_STRING_H
