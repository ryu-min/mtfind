#include "patterns.h"
#include <iostream>


std::vector<mtfind::PatternMatch>
mtfind::QuestionPattern(const std::string &line,
                        const std::string &pattern)
{
    std::vector<PatternMatch> results;
    int patternLength = pattern.size();
    int lineLength = line.size();
    for (int i = 0; i <= lineLength - patternLength; i++) {
        bool match = true;
        for (int j = 0; j < patternLength; j++) {
            if (pattern[j] != '?' && pattern[j] != line[i+j]) {
                match = false;
                break;
            }
        }
        if (match) {
            PatternMatch match;
            match.index = i;
            match.pattern = line.substr(i, patternLength);
            results.push_back(match);
            i += patternLength - 1;
        }
    }
    return results;
}
