#pragma once

#include "Page.h"

#include <memory>
#include <vector>

namespace console {
class PgScroll;
}

class console::PgScroll : public Page {
    std::string title_;
    std::string top;
    std::string bottom;
    std::shared_ptr<Page> body;

    std::size_t lines;
    std::size_t endLine;

  public:
    PgScroll(std::string title_, std::string top, std::string bottom, std::shared_ptr<Page> body, std::size_t lines);

    void handle(std::string cmd, Focus &f) override;

    std::string page() const override;

    std::string title() const override;
};
