#pragma once

#include "Page.h"

#include <memory>
#include <vector>

namespace console {
class PgBase;
}

class console::PgBase : public Page {
    std::string title_;
    std::string body;

  public:
    PgBase(std::string title_, std::string body);

    void handle(std::string cmd, Focus &f) override;

    std::string page() const override;

    std::string title() const override;
};
