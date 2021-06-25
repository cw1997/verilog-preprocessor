//
// Created by 86759 on 2021/6/22.
//

#include "utils_string.h"

#include <regex>
#include <algorithm>

using namespace std;

std::string replace_all(const std::string &text, const std::string &old_value, const std::string &new_value) {
    string str(text);
    while (true) {
        string::size_type pos(0);
        if ((pos = str.find(old_value)) != string::npos) {
            str.replace(pos, old_value.length(), new_value);
        } else {
            break;
        }
    }
    return str;
}

std::vector<std::string> split(const std::string &text, const std::string &delim) {
    regex re(delim);
    vector<string> v(std::sregex_token_iterator(text.begin(), text.end(), re, -1), std::sregex_token_iterator());
    return v;
}

std::vector<std::string> split_by_break_line(const std::string &text) {
    string text_with_lf(text);
//    std::replace(text.begin(), text.end(), '\r', '\n');
    text_with_lf = replace_all(text_with_lf, "\r\n", "\n");
    text_with_lf = replace_all(text_with_lf, "\r", "\n");
    return split(text_with_lf, "\n");
}
