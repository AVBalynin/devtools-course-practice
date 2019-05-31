// Copyright 2019 Balynin Alexey

#ifndef MODULES_CONVECTOR_LENGTH_INCLUDE_LENGTH_CALCULATOR_H_
#define MODULES_CONVECTOR_LENGTH_INCLUDE_LENGTH_CALCULATOR_H_

#include <string>

class LengthCalculator {
 public:
    LengthCalculator() = default;
    std::string operator()(int argc, const char** argv);
 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArgs(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double value;
        std::string operation;
    } Arguments;
};

#endif  // MODULES_CONVECTOR_LENGTH_INCLUDE_LENGTH_CALCULATOR_H_
