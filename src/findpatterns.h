#pragma once

#include "patterns.h"

#include <vector>
#include <string>

namespace mtfind
{
    /**
     * @brief The Match struct
     */
    struct Match {
        size_t line;
        size_t index;
        std::string result;
    };

    /**
     * @brief FindPattern
     * @param lines
     * @param pattern
     * @param detector
     * @param threadCount
     * @return
     */
    std::vector<Match> FindPattern(const std::vector<std::string> & lines,
                                   const std::string & pattern,
                                   PatternDetector detector,
                                   size_t threadCount);
}
