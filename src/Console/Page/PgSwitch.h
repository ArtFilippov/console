#pragma once

#include "Page.h"

#include <memory>
#include <vector>

namespace console {
class PgSwitch;
}

class console::PgSwitch : public Page {
    std::string title_;

    std::vector<std::shared_ptr<Page>> pages;

    std::size_t pgIt{0};

    Focus my;

  public:
    PgSwitch(std::string title_, std::vector<std::shared_ptr<Page>> pages);

    void handle(std::string cmd, Focus &f) override;

    std::string page() const override;

    std::string title() const override;
};
