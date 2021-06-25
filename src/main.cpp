#include <iostream>
#include <string>

#include "./VerilogPreProcessor.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    string input_file_path(R"(C:\my\GitHub\cw1997\verilog-parser\add2.v)");
    string output_file_path(R"(C:\my\GitHub\cw1997\verilog-parser\add2_preprocessed.c)");
    VerilogPreProcessor verilogPreProcessor(input_file_path, output_file_path);
    verilogPreProcessor.process();
    return 0;
}
