#pragma once

#include <functional>
#include <vector>
#include <string>

namespace mtfind
{
    struct PatternMatch {
        int index;
        std::string result;
    };
    using Pattern = std::function<std::vector<PatternMatch>(const std::string &, const std::string &)>;

    std::vector<PatternMatch> QuestionPattern(const std::string & line,
                                              const std::string & pattern);
}
