// Copyright 2019 Balynin Alexey

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/length_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class LengthCalculatorTest : public ::testing::Test {
protected:
    void Act(vector<string> args_) {
        vector<const char*> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }
        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;
        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
private:
    LengthCalculator app_;
    string output_;
};

TEST_F(LengthCalculatorTest, Can_Print_Advice_For_User_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a length calculator application\\..*");
}

TEST_F(LengthCalculatorTest, Can_Check_Number_Of_Arguments) {
    vector<string> args = { "5.5" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(LengthCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "two", "Millimeters_To_Meters" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(LengthCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "1.0", "garbage" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(LengthCalculatorTest, Can_Centimeters_To_Millimeters) {
    vector<string> args = { "1", "Centimeters_To_Millimeters" };

    Act(args);

    Assert("Millimeters: 10");
}

TEST_F(LengthCalculatorTest, Can_Millimeters_To_Decimeters) {
    vector<string> args = { "1", "Millimeters_To_Decimeters" };

    Act(args);

    Assert("Decimeters: 0.01");
}

TEST_F(LengthCalculatorTest, Can_Millimeters_To_Meters) {
    vector<string> args = { "1.0", "Millimeters_To_Meters" };

    Act(args);

    Assert("Meters: 0.001");
}

TEST_F(LengthCalculatorTest, Can_Millimeters_To_Kilometers) {
    vector<string> args = { "1000.0", "Millimeters_To_Kilometers" };

    Act(args);

    Assert("Kilometers: 0.001");
}

TEST_F(LengthCalculatorTest, Can_Centimeters_To_Decimeters) {
    vector<string> args = { "1.0", "Centimeters_To_Decimeters" };

    Act(args);

    Assert("Decimeters: 0.1");
}

TEST_F(LengthCalculatorTest, Can_Centimeters_To_Meters) {
    vector<string> args = { "1", "Centimeters_To_Meters" };

    Act(args);

    Assert("Meters: 0.001");
}

TEST_F(LengthCalculatorTest, Can_Centimeters_To_Kilometers) {
    vector<string> args = { "100.0", "Centimeters_To_Kilometers" };

    Act(args);

    Assert("Kilometers: 0.001");
}

TEST_F(LengthCalculatorTest, Can_Decimeters_To_Millimeters) {
    vector<string> args = { "1", "Decimeters_To_Millimeters" };

    Act(args);

    Assert("Millimeters: 100");
}

TEST_F(LengthCalculatorTest, Can_Decimeters_To_Centimeters) {
    vector<string> args = { "1.0", "Decimeters_To_Centimeters" };

    Act(args);

    Assert("Centimeters: 10");
}

TEST_F(LengthCalculatorTest, Can_Decimeters_To_Meters) {
    vector<string> args = { "1.0", "Decimeters_To_Meters" };

    Act(args);

    Assert("Meters: 0.1");
}

TEST_F(LengthCalculatorTest, Can_Decimeters_To_Kilometers) {
    vector<string> args = { "1.0", "Decimeters_To_Kilometers" };

    Act(args);

    Assert("Kilometers: 0.0001");
}

TEST_F(LengthCalculatorTest, Can_Meters_To_Millimeters) {
    vector<string> args = { "1", "Meters_To_Millimeters" };

    Act(args);

    Assert("Millimeters: 1000");
}

TEST_F(LengthCalculatorTest, Can_Meters_To_Centimeters) {
    vector<string> args = { "1", "Meters_To_Centimeters" };

    Act(args);

    Assert("Centimeters: 100");
}

TEST_F(LengthCalculatorTest, Can_Meters_To_Decimeters) {
    vector<string> args = { "1", "Meters_To_Decimeters" };

    Act(args);

    Assert("Decimeters: 10");
}

TEST_F(LengthCalculatorTest, Can_Meters_To_Kilometers) {
    vector<string> args = { "1000.0", "Meters_To_Kilometers" };

    Act(args);

    Assert("Kilometers: 1.0");
}

TEST_F(LengthCalculatorTest, Can_Kilometers_To_Millimeters) {
    vector<string> args = { "0.00001", "Kilometers_To_Millimeters" };

    Act(args);

    Assert("Millimeters: 10");
}

TEST_F(LengthCalculatorTest, Can_Kilometers_To_Centimeters) {
    vector<string> args = { "1", "Kilometers_To_Centimeters" };

    Act(args);

    Assert("Centimeters: 100000");
}

TEST_F(LengthCalculatorTest, Can_Kilometers_To_Decimeters) {
    vector<string> args = { "1", "Kilometers_To_Decimeters" };

    Act(args);

    Assert("Decimeters: 10000");
}

TEST_F(LengthCalculatorTest, Can_Kilometers_To_Meters) {
    vector<string> args = { "1", "Kilometers_To_Meters" };

    Act(args);

    Assert("Meters: 100");
}
