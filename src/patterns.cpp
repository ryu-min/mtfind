#include "patterns.h"
#include <iostream>


std::vector<mtfind::PatternMatch>
mtfind::QuestionPattern(const std::string &line,
                        const std::string &pattern)
{
    std::vector<PatternMatch> results;
    size_t patternSize = pattern.size();
    size_t lineSize = line.size();
    for (int i = 0; i <= lineSize - patternSize; i++) {
        bool match = true;
        for (int j = 0; j < patternSize; j++) {
            if (pattern[j] != '?' && pattern[j] != line[i+j]) {
                match = false;
                break;
            }
        }
        if (match) {
            PatternMatch match;
            match.index = i;
            match.result = line.substr(i, patternSize);
            results.push_back(match);
            i += patternSize - 1;
        }
    }
    return results;
}
