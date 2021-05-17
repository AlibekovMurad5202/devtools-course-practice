// Copyright 2021 Alibekov Murad

#include "include/dijkstras_algorithm.h"
#include "include/dijkstras_algorithm_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include <limits>
#include <vector>

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a graph's shortest paths finder application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <N> <source vertex> ... (N * N numbers)\n\n " +

          "Where all arguments are double-precision numbers or word 'inf'.\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else {
        int N = atoi(argv[1]);
        if (argc != N * N + 3) {
            help(argv[0], "ERROR: Should be (N * N + 3) arguments.\n\n");
            return false;
        }
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

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    double inf = std::numeric_limits<double>::infinity();
    try {
        args.N = atoi(argv[1]);
        args.source_vertex = atoi(argv[2]);
        if (args.source_vertex > args.N) {
            throw std::string("Index out of range!");
        }
        for (int i = 3; i < args.N * args.N + 3; i++) {
            if (strcmp(argv[i], "inf") == 0)
                args.values.push_back(inf);
            else
                args.values.push_back(parseDouble(argv[i]));
        }
    }
    catch(std::string& str) {
        return str;
    }

    std::vector<double> result = GraphAlgorithms::dijkstras_algorithm
        (args.values, args.N, args.source_vertex);

    std::ostringstream stream;
    for (int i = 0; i < std::static_cast<int>(result.size()); i++) {
        stream << "Result: [" << result[i] << " ";
    }
    stream << "]\n";

    message_ = stream.str();

    return message_;
}
