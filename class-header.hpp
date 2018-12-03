#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

class PlagiarismChecker {
    public:
        PlagiarismChecker();
        void Check(int argc, char* argv[]);
    private:
        void Parse(int argc, char* argv[]);
        void PlagiarismCheck();
        void CalculateOutput();
        void PrintOutput();

        void ParseString(char* input, std::vector<std::string>& str);
        void ParseSynonym(char* synonymFile);
        void ConvertSynonym();
        void toTupleSet();
        
        void getInputSize();
        void toLowerCase();

        double percentage;
        int plagiarized;
        int nTuple;
        int input1Size;
        int input2Size;
        std::vector<std::string> input1;
        std::vector<std::string> input2;
        std::map<std::string, std::string> synonyms;
        std::set<std::string> inputTuple;

};