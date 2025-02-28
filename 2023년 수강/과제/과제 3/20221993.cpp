#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool compareLines(const std::string& a, const std::string& b) {
    std::string rule = "mporqtsvuxwzybadcfehgjilkn";

    for (size_t i=0; i<std::min(a.length(), b.length()); ++i) {
        size_t word_01 = rule.find(a[i]);
        size_t word_02 = rule.find(b[i]);
      
        if (word_01!=word_02) {
            return word_01 < word_02;
        }
    }

    return a.length() < b.length();
}

int main(int argc, char* argv[]) {
    if (argc<2) {
        std::cerr << argv[0] << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    std::sort(lines.begin(), lines.end(), compareLines);

    for (const auto& sortedLine : lines) {
        std::cout << sortedLine << std::endl;
    }

    return 0;
}
