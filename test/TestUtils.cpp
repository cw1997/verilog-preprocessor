//
// Created by 86759 on 2021/6/22.
//

#include "testing_utils/testing_utils.h"
#include "gtest/gtest.h"

#include "utils/utils_string.h"
#include "utils/utils_debug.h"
#include "./VerilogPreProcessor.h"

#include <string>

using namespace std;

TEST(TestUtil, TestSplitByBreakLine) {
    string input("1\r\n2\r3\r4\n\r5\n");
    auto actual = split_by_break_line(input);
    dump_vector(actual);
    vector<string> except{"1", "2", "3", "4", "", "5"};
    VECTOR_EQUAL(actual, except);
}

TEST(TestVerilogPreProcessor, TestVerilogPreProcessor) {
    string input_file_path(R"(C:\my\GitHub\cw1997\verilog-parser\add2.v)");
    string output_file_path(R"(C:\my\GitHub\cw1997\verilog-parser\add2_preprocessed.c)");
    VerilogPreProcessor verilogPreProcessor(input_file_path, output_file_path);
    verilogPreProcessor.process();
}

