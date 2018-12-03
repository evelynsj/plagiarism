#include <fstream>
#include <iostream> // TODO delete after?
#include <set> // TODO delete after?
#include <iterator> // TODO delete after?

#include "class-header.hpp"

// set constructor
PlagiarismChecker::PlagiarismChecker() :
    percentage(0),
    output(0),
    nTuple(3) {}

/*TODO*/
int PlagiarismChecker::Check(int argc, char* argv[]) {

    Parse(argc, argv);

    return 0; // placeholder
}

void PlagiarismChecker::Parse(int argc, char* argv[]) {

    // TODO: CHECK NO ARGS
    
    // Put synonyms into a hash set
    std::ifstream syn;
    std::string word;
    syn.open(argv[1]);
    
    while (syn >> word) {
        synonyms.insert(word);
    }

    syn.close();

    // Put file1 and file2 into vector string
    ParseString(argv[2], input1);
    ParseString(argv[3], input2);

    // Assign N-tuple variable
    if (argc == 5) {
        nTuple = atoi(argv[4]);
    }

}

void PlagiarismChecker::ParseString(char* input, std::vector<std::string>& str) {

    std::ifstream file;
    std::string word;
    file.open(input);

    while (file >> word) {
        str.push_back(word);
    }

    file.close();

}