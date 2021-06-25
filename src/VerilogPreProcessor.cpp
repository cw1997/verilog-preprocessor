//
// Created by 86759 on 2021/6/15.
//

#include <sstream>
#include <regex>
#include "VerilogPreProcessor.h"

#include "utils/utils_string.h"
#include "utils/utils_io.h"
#include "utils/utils_debug.h"

using namespace std;

VerilogPreProcessor::VerilogPreProcessor(const std::string& input_file_path, const std::string& output_file_path) {
//    directory_path
    auto last_backlash = input_file_path.rfind('\\');
    if (last_backlash != -1) {
        directory_path = input_file_path.substr(0, last_backlash) + '\\';
    } else {
        auto last_slash = input_file_path.find('/');
        directory_path = input_file_path.substr(0, last_slash) + '/';
    }

    file_source_code.open(input_file_path);
    if (!file_source_code.is_open()) {
        cout << "Error opening file_source_code: " << input_file_path << endl; exit (1);
    }

    file_target_code.open(output_file_path);
    if (!file_target_code.is_open()) {
        cout << "Error opening file_target_code: " << output_file_path << endl; exit (1);
    }

//    std::stringstream buffer;
//    buffer << file_source_code.rdbuf();
//    std::string source_content(buffer.str());

//    std::ifstream in("some.file");
    std::ostringstream buffer;
    buffer << file_source_code.rdbuf();
    std::string source_content = buffer.str();

    auto source_content_lines = split_by_break_line(source_content);
    source_buffer.insert(source_buffer.begin(), source_content_lines.begin(), source_content_lines.end());
}

VerilogPreProcessor::~VerilogPreProcessor() {
    file_source_code.close();
    file_target_code.close();
}

int VerilogPreProcessor::process() {
    smatch result;
    regex regex_include("`include \"(.+)\"");
    for (auto iter = source_buffer.begin(); iter != source_buffer.end();) {
        auto source_line = *iter;
        if (regex_match(source_line, result, regex_include))  {
            string full_path;
            string include_path = result[1].str();
            if (include_path.substr(0, 1) != "/") {
//                relative path
                full_path += directory_path;
                if (include_path.substr(0, 2) == "./") {
                    full_path += include_path.substr(2);
                } else {
                    full_path += include_path;
                }
            } else {
//                absolute path
                full_path += include_path;
            }
            cout << "include full path: " << full_path << endl;
            vector<string> lines = get_file_lines(full_path);
            iter = source_buffer.erase(iter);
            iter = source_buffer.insert(iter, lines.begin(), lines.end());
        } else {
            ++iter;
        }

    }

    dump_vector(source_buffer, "source_buffer");

    return 0;
}
