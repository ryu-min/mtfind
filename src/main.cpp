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
    mtfind::SearchPattern(lines, mtfind::QuestionPattern, 4);
    return 0;
}
