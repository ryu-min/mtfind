#pragma once

#include <functional>

namespace mtfind
{
    using Pattern = std::function<void()>;

    void QuestionPattern();
}
