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
    PlagiarismCheck();

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

    getInputSize();

    // Convert synonyms in input1 and input2 to the same synonym
    ConvertSynonym();

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

void PlagiarismChecker::ConvertSynonym() {
    
    std::string word = "";
    bool isSynonymFound = false;

    for (int i = 0; i < input1Size; ++i) {
        if (synonyms.find(input1[i]) != synonyms.end()) {
            if (isSynonymFound == false) {
                isSynonymFound = true;
                word = input1[i];
            }
            else {
                input1[i] = word;
            }
        }
    }

    for (int i = 0; i < input2Size; ++i) {
        if (synonyms.find(input2[i]) != synonyms.end()) {
            input2[i] = word; 
        }
    }

}

void PlagiarismChecker::toTupleSet() {
    
    std::string str = "";
    int k = 0;
    nTuple = 2;

    for (int i = 0; i < input2Size; ++i) {
        str = "";
        str += input2[i];
        k = i + 1;
        for (int j = 0; j < nTuple - 1 && k < input2Size; ++j, ++k) {
            // std::cout << i << ' ';
            // std::cout << j << ' ';
            // std::cout << k << std::endl;
            str += ' ' + input2[k];
        }
        // std::cout << str << std::endl;
        // std::cout << input2Size << std::endl;
        inputTuple.insert(str);
        if (k == input2Size) {
            return;
        }
    }



}

void PlagiarismChecker::PlagiarismCheck() {
    toTupleSet();
    // std::set<std::string>::iterator it;
    // int count = 0;
    // for (it = inputTuple.begin(); it != inputTuple.end(); ++it) {
    //     std::cout << *(it) << std::endl;
    //     ++count;
    // }
    // std::cout << nTuple << std::endl;
    // std::cout << count << std::endl;
}

void PlagiarismChecker::getInputSize() {
    input1Size = input1.size();
    input2Size = input2.size();
}