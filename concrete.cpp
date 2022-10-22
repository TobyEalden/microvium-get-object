#include "concrete.h"
#include <iostream>

std::string Concrete::intToString(int32_t val) { return std::to_string(val); }

std::string Concrete::floatToString(double val) {
    return std::to_string(val);
}

void Concrete::floatLog(double val) {
    std::cout << "val is " << val << std::endl;
}

void Concrete::stringLog(std::string val) {
    std::cout << val << std::endl;
}
