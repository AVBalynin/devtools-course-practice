// Copyright 2019 Balynin Alexey

#include "include/Convector.h"
#include "include/length_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

void LengthCalculator::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a length calculator application.\n" +
        "Please provide arguments in the following format:\n" +
        "  $ " + appname + " <value> <operation>\n" +
        "Value have to be a double-precision number, " +
        "and number operation is one of the following:\n" +
	    "'Kilometers_To_Meters',\n" +
	    "'Kilometers_To_Decimeters',\n" +
        "'Kilometers_To_Centimeters',\n" +
        "'Kilometers_To_Millimeters',\n" +
        "'Meters_To_Kilometers',\n" +
        "'Meters_To_Decimeters',\n" +
        "'Meters_To_Centimeters',\n" +
        "'Meters_To_Millimeters',\n" +
        "'Decimeters_To_Kilometers',\n" +
        "'Decimeters_To_Meters',\n" +
        "'Decimeters_To_Centimeters',\n" +
        "'Decimeters_To_Millimeters',\n" +
        "'Centimeters_To_Kilometers',\n" +
        "'Centimeters_To_Kilometers',\n" +
        "'Centimeters_To_Kilometers',\n" +
        "'Centimeters_To_Meters',\n" +
        "'Centimeters_To_Decimeters',\n" +
        "'Centimeters_To_Millimeters',\n" +
        "'Millimeters_To_Kilometers',\n" +
        "'Millimeters_To_Meters',\n" +
        "'Millimeters_To_Decimeters',\n" +
        "'Millimeters_To_Centimeters',\n";
}

bool LengthCalculator::ValidateNumberOfArgs(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    }
    else if (argc != 3) {
        Help(argv[0], "ERROR: Should be 2 arguments.\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);
    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}

std::string parseOperation(const char* arg) {
    std::string op;
    enum {
        Kilometers_To_Meters = 1,
        Kilometers_To_Decimeters,
        Kilometers_To_Centimeters,
        Kilometers_To_Millimeters,
        Meters_To_Kilometers,
        Meters_To_Decimeters,
        Meters_To_Centimeters,
        Meters_To_Millimeters,
        Decimeters_To_Kilometers,
        Decimeters_To_Meters,
        Decimeters_To_Centimeters,
        Decimeters_To_Millimeters,
        Centimeters_To_Kilometers,
        Centimeters_To_Meters,
        Centimeters_To_Decimeters,
        Centimeters_To_Millimeters,
        Millimeters_To_Kilometers,
        Millimeters_To_Meters,
        Millimeters_To_Decimeters,
        Millimeters_To_Centimeters,
    };

    if (strcmp(arg, "Kilometers_To_Meters") == 0) {
        op = std::to_string(static_cast<int>(Kilometers_To_Meters));
    }
    else if (strcmp(arg, "Kilometers_To_Decimeters") == 0) {
        op = std::to_string(static_cast<int>(Kilometers_To_Decimeters));
    }
    else if (strcmp(arg, "Kilometers_To_Centimeters") == 0) {
        op = std::to_string(static_cast<int>(Kilometers_To_Centimeters));
    }
    else if (strcmp(arg, "Kilometers_To_Millimeters") == 0) {
        op = std::to_string(static_cast<int>(Kilometers_To_Millimeters));
    }
    else if (strcmp(arg, "Meters_To_Kilometers") == 0) {
        op = std::to_string(static_cast<int>(Meters_To_Kilometers));
    }
    else if (strcmp(arg, "Meters_To_Decimeters") == 0) {
        op = std::to_string(static_cast<int>(Meters_To_Decimeters));
    }
    else if (strcmp(arg, "Meters_To_Centimeters") == 0) {
        op = std::to_string(static_cast<int>(Meters_To_Centimeters));
    }
    else if (strcmp(arg, "Meters_To_Millimeters") == 0) {
        op = std::to_string(static_cast<int>(Meters_To_Millimeters));
    }
    else if (strcmp(arg, "Decimeters_To_Kilometers") == 0) {
        op = std::to_string(static_cast<int>(Decimeters_To_Kilometers));
    }
    else if (strcmp(arg, "Decimeters_To_Meters") == 0) {
        op = std::to_string(static_cast<int>(Decimeters_To_Meters));
    }
    else if (strcmp(arg, "Decimeters_To_Centimeters") == 0) {
        op = std::to_string(static_cast<int>(Decimeters_To_Centimeters));
    }
    else if (strcmp(arg, "Decimeters_To_Millimeters") == 0) {
        op = std::to_string(static_cast<int>(Decimeters_To_Millimeters));
    }
    else if (strcmp(arg, "Centimeters_To_Kilometers") == 0) {
        op = std::to_string(static_cast<int>(Centimeters_To_Kilometers));
    }
    else if (strcmp(arg, "Centimeters_To_Meters") == 0) {
        op = std::to_string(static_cast<int>(Centimeters_To_Meters));
    }
    else if (strcmp(arg, "Centimeters_To_Decimeters") == 0) {
        op = std::to_string(static_cast<int>(Centimeters_To_Decimeters));
    }
    else if (strcmp(arg, "Centimeters_To_Millimeters") == 0) {
        op = std::to_string(static_cast<int>(Centimeters_To_Millimeters));
    }
    else if (strcmp(arg, "Millimeters_To_Kilometers") == 0) {
        op = std::to_string(static_cast<int>(Millimeters_To_Kilometers));
    }
    else if (strcmp(arg, "Millimeters_To_Meters") == 0) {
        op = std::to_string(static_cast<int>(Millimeters_To_Meters));
    }
    else if (strcmp(arg, "Millimeters_To_Decimeters") == 0) {
        op = std::to_string(static_cast<int>(Millimeters_To_Decimeters));
    }
    else if (strcmp(arg, "Millimeters_To_Centimeters") == 0) {
        op = std::to_string(static_cast<int>(Millimeters_To_Centimeters));
    }
    else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string LengthCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArgs(argc, argv)) {
        return message_;
    }
    try {
        args.value = parseDouble(argv[1]);
        args.operation = parseOperation(argv[2]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    if (args.operation == "1") {
        stream << "Meters: " << Convector::KMinM(args.value);
    }
    else if (args.operation == "2") {
        stream << "Decimeters: " << Convector::KMinDM(args.value);
    }
    else if (args.operation == "3") {
        stream << "Centimeters: " << Convector::KMinCM(args.value);
    }
    else if (args.operation == "4") {
        stream << "Millimeters: " << Convector::KMinMM(args.value);
    }
    else if (args.operation == "5") {
        stream << "Kilometers: " << Convector::MinKM(args.value);
    }
    else if (args.operation == "6") {
        stream << "Decimeters: " << Convector::MinDM(args.value);
    }
    else if (args.operation == "7") {
        stream << "Centimeters: " << Convector::MinCM(args.value);
    }
    else if (args.operation == "8") {
        stream << "Millimeters: " << Convector::MinMM(args.value);
    }
    else if (args.operation == "9") {
        stream << "Kilometers: ";
        stream << Convector::DMinKM(args.value);
    }
    else if (args.operation == "10") {
        stream << "Meters: " << Convector::DMinM(args.value);
    }
    else if (args.operation == "11") {
        stream << "Centimeters: " << Convector::DMinCM(args.value);
    }
    else if (args.operation == "12") {
        stream << "Millimeters: " << Convector::DMinMM(args.value);
    }
    else if (args.operation == "13") {
        stream << "Kilometers: ";
        stream << Convector::CMinKM(args.value);
    }
    else if (args.operation == "14") {
        stream << "Meters: " << Convector::CMinM(args.value);
    }
    else if (args.operation == "15") {
        stream << "Decimeters: " << Convector::CMinDM(args.value);
    }
    else if (args.operation == "16") {
        stream << "Millimeters: " << Convector::CMinMM(args.value);
    }
    else if (args.operation == "17") {
        stream << "Kilometers: " << Convector::MMinKM(args.value);
    }
    else if (args.operation == "18") {
        stream << "Meters: " << Convector::MMinM(args.value);
    }
    else if (args.operation == "19") {
        stream << "Decimeters: ";
        stream << Convector::MMinDM(args.value);
    }
    else if (args.operation == "20") {
        stream << "Centimeters: " << Convector::MMinCM(args.value);
    }
    message_ = stream.str();
    return message_;
}
