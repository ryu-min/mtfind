#pragma once

#include <string>
#include <vector>

namespace mtfind
{
    /**
     * @brief GetLinesFromFile
     * @param filePath
     * @param ok
     * @return
     */
    std::vector<std::string> GetLinesFromFile(const std::string & filePath, bool & ok);
}
