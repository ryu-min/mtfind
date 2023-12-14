#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "findpatterns.h"

int main()
{
    std::string filePath = "C:\\Users\\ryu-min\\dev\\mtfind\\test.txt";
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
//    mtfind::QuestionPatternDetector("1", "mad");
    auto matches = mtfind::FindPattern(lines, "?ad", mtfind::QuestionPatternDetector, 10);
    std::cout << matches.size() << std::endl;
    for (const auto & match : matches) {
        std::cout << match.line << " "
                  << match.index << " "
                  << match.result << std::endl;
    }
    return 0;
}
