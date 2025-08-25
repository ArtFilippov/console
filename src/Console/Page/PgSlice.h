#pragma once

#include "Page.h"

#include <memory>
#include <vector>

namespace console {
class PgSlice;
}

class console::PgSlice : public Page {
    std::string title_;
    int from;
    int to;
    std::shared_ptr<Page> pg;

  public:
    PgSlice(std::string title_, int lineFrom, int lineTo, std::shared_ptr<Page> pg);

    void handle(std::string cmd, Focus &f) override;

    std::string page() const override;

    std::string title() const override;
};
