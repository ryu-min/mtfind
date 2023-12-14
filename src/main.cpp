#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>

#include "findpatterns.h"

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cout << "Error: Incorrect number of parameters." << std::endl;
        std::cout << "Usage: mtfind <file_path> <pattern>" << std::endl;
        return -1;
    }
    std::string filePath = argv[1];
    std::string pattern = argv[2];

    std::ifstream fStream(filePath);
    if (!fStream) {
        std::cout << "can't open file";
        return -1;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(fStream, line)) {
        lines.push_back(line);
    }
    auto matches = mtfind::FindPattern(lines, pattern, mtfind::QuestionPatternDetector, 8);
    std::cout << matches.size() << std::endl;
    for (const auto & match : matches) {
        std::cout << match.line << " "
                  << match.index << " "
                  << match.result << std::endl;
    }
    return 0;
}
