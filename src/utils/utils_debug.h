//
// Created by 86759 on 2021/6/25.
//

#ifndef VERILOG_PREPROCESSOR_UTILS_DEBUG_H
#define VERILOG_PREPROCESSOR_UTILS_DEBUG_H

#include <vector>
#include <iostream>

template<typename T> void dump_vector(std::vector<T> arrays) {
    for(int i = 0; i < arrays.size(); ++i) {
        std::cout << "========              " << i << ":" << arrays[i] << std::endl;
    }
}

template<typename T> void dump_vector(std::vector<T> arrays, const std::string& name) {
    std::cout << "======== dump_vector: " << name << " start" << std::endl;
    dump_vector(arrays);
    std::cout << "======== dump_vector: " << name << " end" << std::endl;
}

#endif //VERILOG_PREPROCESSOR_UTILS_DEBUG_H
