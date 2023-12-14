#pragma once

#include <functional>
#include <vector>
#include <string>

namespace mtfind
{
    /**
     * @brief The DetectorMatch struct
     */
    struct DetectorMatch {
        size_t index;
        std::string result;
    };

    /**
     *
     */
    using PatternDetector = std::function<std::vector<DetectorMatch>(const std::string &, const std::string &)>;

    /**
     * @brief QuestionPatternDetector
     * @param line
     * @param pattern
     * @return
     */
    std::vector<DetectorMatch> QuestionPatternDetector(const std::string & line,
                                                       const std::string & pattern);
}
