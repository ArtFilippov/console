#pragma once

#include "Page.h"
#include "Dialog/Dialog.h"

#include <memory>
#include <vector>

namespace console {
class PgReqList;
}

class console::PgReqList : public Page {

    std::string title_;
    std::shared_ptr<Dialog> dlg;
    mutable std::size_t lastReq{0};
    mutable std::string pg;

  public:
    PgReqList(std::string title_, std::shared_ptr<Dialog> dlg);

    void handle(std::string cmd, Focus &f) override;

    std::string page() const override;

    std::string title() const override;
};
