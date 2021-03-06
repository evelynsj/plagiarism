#include "class-header.hpp"

// Constructor
PlagiarismChecker::PlagiarismChecker() :
    percentage(0),
    plagiarized(0),
    nTuple(3),
    input1Size(0),
    input2Size(0) {}

void PlagiarismChecker::Check(int argc, char* argv[]) {

    Parse(argc, argv);
    PlagiarismCheck();
    CalculateOutput();
    PrintOutput();
}

void PlagiarismChecker::Parse(int argc, char* argv[]) {

    if (argc < 4) {
        std::cout << "Invalid input. Please enter with the following format: ./main synonym-file.txt file1.txt file2.txt n-tuple (n-tuple is optional)" << std::endl;
        exit(0);
    }
    
    ParseSynonym(argv[1]);

    ParseString(argv[2], input1);
    ParseString(argv[3], input2);

    getInputSize();
    
    if (argc == 5) { // if optional file is included
        nTuple = atoi(argv[4]);
    }

    ConvertSynonym();

    toLowerCase();

    toTupleSet(); 
}

void PlagiarismChecker::PlagiarismCheck() {

    std::string str = "";
    int k = 0;

    for (int i = 0; i < input1Size; ++i) {
        str = "";
        str += input1[i];
        k = i + 1;
        for (int j = 0; j < nTuple - 1 && k < input1Size; ++j, ++k) {
            str += ' ' + input1[k];
        }
        if (inputTuple.find(str) != inputTuple.end()) {
            ++plagiarized;
        }
        if (k == input2Size) {
            return;
        }
    }
}

void PlagiarismChecker::CalculateOutput() {
    int inputTupleSize = inputTuple.size();
    percentage = ((double)plagiarized / (double)inputTupleSize) * 100;
}

void PlagiarismChecker::PrintOutput() {
    std::cout << (int)percentage << "%" << std::endl;
}

// Parse files containing strings to be compared into string vectors
void PlagiarismChecker::ParseString(char* input, std::vector<std::string>& str) {

    std::ifstream file;
    std::string word;
    file.open(input);

    while (file >> word) {
        str.push_back(word);   
    }

    file.close();
}

// Parse synonym file to a hash map, with each word as a key and value set to a common word in the list
void PlagiarismChecker::ParseSynonym(char* synonymFile) {

    std::ifstream syn;
    std::string line;
    std::string word;
    syn.open(synonymFile);

    while (getline(syn, line)) {
        
        std::istringstream iss(line);
        std::string setToWord = "";
        int i = 0;
        while (iss >> word) {
            if (i == 0) {
                setToWord = word;
            }
            synonyms[word] = setToWord;
            ++i;
        }
    }
    syn.close();
}

// Converts word in synonym list to a common word
void PlagiarismChecker::ConvertSynonym() {
    
    for (int i = 0, j = 0; i < input1Size || j < input2Size; ++i, ++j) {
        if (synonyms.find(input1[i]) != synonyms.end() && i < input1Size) {
            input1[i] = synonyms.at(input1[i]);
        }
        if (synonyms.find(input2[i]) != synonyms.end() && i < input2Size) {
            input2[i] = synonyms.at(input2[i]);
        }
    }
}

// Inserts input2 into a hash set in N-tuple form
void PlagiarismChecker::toTupleSet() {
    
    std::string str = "";
    int k = 0;

    for (int i = 0; i < input2Size; ++i) {
        str = "";
        str += input2[i];
        k = i + 1;
        for (int j = 0; j < nTuple - 1 && k < input2Size; ++j, ++k) {
            str += ' ' + input2[k];
        }
        inputTuple.insert(str);
        if (k == input2Size) {
            return;
        }
    }
}

void PlagiarismChecker::getInputSize() {
    input1Size = input1.size();
    input2Size = input2.size();
}

void PlagiarismChecker::toLowerCase() {
    for (int i = 0, j = 0; i < input1Size || j < input2Size; ++i, ++j) {
        if (i < input1Size) {
            std::transform(input1[i].begin(), input1[i].end(), input1[i].begin(), ::tolower);
        }
        if (i < input2Size) {
            std::transform(input1[i].begin(), input1[i].end(), input1[i].begin(), ::tolower);
        }
    }
}