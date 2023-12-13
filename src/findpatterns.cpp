#include "findpatterns.h"

#include <cassert>
#include <iostream>

using VecConstIt = std::vector<std::string>::const_iterator;
using VecConstRange = std::pair<VecConstIt, VecConstIt>;
using VecConstRanges = std::vector<VecConstRange>;

std::vector<std::string> FindPatternInRange(const VecConstRange & range,
                                            mtfind::Pattern pattern)
{
    std::vector<std::string> res;
    for (VecConstIt it = range.first; it != range.second; ++it) {
        res.push_back(*it);
    }
    return res;
}

VecConstRanges LinesToRanges(const std::vector<std::string> & lines,
                             size_t threadCount)
{
    assert(threadCount != 0);
    size_t chunkSize = lines.size() / threadCount;
    if (chunkSize == 0) {
        return {std::make_pair(lines.begin(), lines.end())};
    }
    VecConstRanges ranges;
    VecConstIt start = lines.begin();
    for (int i = 0; i < threadCount - 1; i++) {
        VecConstIt end = start + chunkSize;
        ranges.emplace_back(start, end);
        start = end;
    }
    ranges.emplace_back(start, lines.end());
    return ranges;
}

void mtfind::FindPattern(const std::vector<std::string> &lines,
                         Pattern pattern,
                         size_t threadCount)
{
    assert(threadCount != 0);
    if (lines.empty()) return;
    VecConstRanges ranges = LinesToRanges(lines, threadCount);
    for (int i = 0; i < ranges.size(); i++) {
        std::cout << "range " << i << " res: " << std::endl;
        auto rangeRes = FindPatternInRange(ranges[i], pattern);
        for (const auto & r : rangeRes) {
            std::cout << r << std::endl;
        }
    }
}
