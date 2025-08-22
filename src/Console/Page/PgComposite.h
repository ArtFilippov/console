#pragma once

#include "Page.h"

#include <memory>
#include <vector>

namespace console {
class PgComposite;
}

class console::PgComposite : public Page {
    std::string title_;
    std::vector<std::shared_ptr<Page>> pages;

  public:
    PgComposite(std::string title_, std::initializer_list<std::shared_ptr<Page>> pages);

    void handle(std::string cmd, Focus &f) override;

    std::string page() const override;

    std::string title() const override;
};
