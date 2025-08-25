#pragma once

#include "Page.h"
#include "Dialog/Dialog.h"

#include <memory>
#include <vector>

namespace console {
class PgResList;
}

class console::PgResList : public Page {

    std::string title_;
    std::shared_ptr<Dialog> dlg;
    mutable std::size_t lastRes{0};
    mutable std::string pg;

  public:
    PgResList(std::string title_, std::shared_ptr<Dialog> dlg);

    void handle(std::string cmd, Focus &f) override;

    std::string page() const override;

    std::string title() const override;
};
