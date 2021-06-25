//
// Created by 86759 on 2021/6/15.
//

#ifndef VERILOG_PREPROCESSOR_VERILOGPREPROCESSOR_H
#define VERILOG_PREPROCESSOR_VERILOGPREPROCESSOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <regex>

class VerilogPreProcessor {
private:
    std::string directory_path;
    std::ifstream file_source_code;
    std::ofstream file_target_code;
//    TODO: use linked list to improving performance
    std::vector<std::string> source_buffer;
    std::vector<std::string> target_buffer;
    uint32_t line_number = 0;
//    int preprocess_include(const std::string& path);
public:
    VerilogPreProcessor(const std::string& input_file_path, const std::string& output_file_path);
    ~VerilogPreProcessor();

    int process();
};


#endif //VERILOG_PREPROCESSOR_VERILOGPREPROCESSOR_H
