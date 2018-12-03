#include <iostream>
#include "class-header.hpp"

int main(int argc, char* argv[]) {
    PlagiarismChecker obj1;
    double output = 0;

    obj1.Check(argc, argv);

    return 0;
}