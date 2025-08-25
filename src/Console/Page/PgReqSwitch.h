#pragma once

#include "Page.h"
#include "PgSwitch.h"
#include "Dialog/Dialog.h"

#include <memory>
#include <vector>

namespace console {
class PgReqSwitch;
}

class console::PgReqSwitch : public Page {

    std::string title_;
    std::shared_ptr<PgSwitch> pg;

  public:
    PgReqSwitch(std::string title_, std::shared_ptr<Dialog> dlg);

    void handle(std::string cmd, Focus &f) override;

    std::string page() const override;

    std::string title() const override;
};
