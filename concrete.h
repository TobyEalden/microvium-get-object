#ifndef MICROVIUMHOST_CONCRETE_H
#define MICROVIUMHOST_CONCRETE_H

#include "Experiment1_ffi.h"

class Concrete : public Experiment1 {
public:
    std::string intToString(int32_t val) override;

    std::string floatToString(double val) override;

    void floatLog(double val) override;

    void stringLog(std::string val) override;
};


#endif //MICROVIUMHOST_CONCRETE_H
