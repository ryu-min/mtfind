#pragma once

#include <functional>
#include <vector>
#include <string>

namespace mtfind
{
    struct DetectorMatch {
        size_t index;
        std::string result;
    };
    using PatternDetector = std::function<std::vector<DetectorMatch>(const std::string &, const std::string &)>;

    std::vector<DetectorMatch> QuestionPatternDetector(const std::string & line,
                                                       const std::string & pattern);
}
