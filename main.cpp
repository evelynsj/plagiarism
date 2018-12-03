#include <iostream>
#include "class-header.hpp"

int main(int argc, char* argv[]) {
    PlagiarismChecker obj1;
    int output = 0;

    output = obj1.Check(argc, argv);

    std::cout << output << "%" << std::endl;

    return 0;
}