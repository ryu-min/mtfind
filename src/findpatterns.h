#pragma once

#include "patterns.h"

#include <vector>
#include <string>

namespace mtfind
{
    /**
     * @brief SearchPattern
     * @param lines
     * @param pattern
     * @param threadCount
     */
    void SearchPattern(const std::vector<std::string> & lines,
                       Pattern pattern,
                       size_t threadCount);
}

