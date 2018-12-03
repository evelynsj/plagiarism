#include <string>
#include <vector>
#include <set>

class PlagiarismChecker {
    public:
        PlagiarismChecker();
        double Check(int argc, char* argv[]);
    private:
        void Parse(int argc, char* argv[]);
        void ParseString(char* input, std::vector<std::string>& str);
        void ConvertSynonym();
        void toTupleSet();
        void getInputSize();
        void PlagiarismCheck();
        void CalculateOutput();
        double percentage;
        int plagiarized;
        int nTuple;
        int input1Size;
        int input2Size;
        std::vector<std::string> input1;
        std::vector<std::string> input2;
        std::set<std::string> synonyms;
        std::set<std::string> inputTuple;

};