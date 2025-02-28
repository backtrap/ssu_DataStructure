#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool compareLines(const std::string& a, const std::string& b) {
    std::string rule = "mporqtsvuxwzybadcfehgjilkn";

    // 각 문자를 정렬 규칙의 인덱스로 변환하여 비교
    for (size_t i=0; i<std::min(a.length(), b.length()); ++i) {
        size_t indexA = rule.find(a[i]);
        size_t indexB = rule.find(b[i]);
        if (indexA!=indexB) {
            return indexA < indexB;
        }
    }

    // 길이가 다른 경우, 길이가 짧은 것이 더 작은 것으로 처리
    return a.length() < b.length();
}

int main() {
    std::ifstream inputFile("test.txt");

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    // 주어진 규칙에 따라 오름차순으로 정렬
    std::sort(lines.begin(), lines.end(), compareLines);

    // 정렬된 줄 출력
    for (const auto& sortedLine : lines) {
        std::cout << sortedLine << std::endl;
    }

    return 0;
}
