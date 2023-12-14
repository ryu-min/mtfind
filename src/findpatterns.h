#pragma once

#include "patterns.h"

#include <vector>
#include <string>

namespace mtfind
{
    struct Match {
        size_t line;
        size_t index;
        std::string result;
    };

    std::vector<Match> FindPattern(const std::vector<std::string> & lines,
                                   const std::string & pattern,
                                   PatternDetector detector,
                                   size_t threadCount);
}
