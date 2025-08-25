#pragma once

#include "Page.h"
#include "PgSwitch.h"
#include "PgReqList.h"
#include "Dialog/Dialog.h"

#include <memory>
#include <vector>

namespace console {
class PgDlg;
}

class console::PgDlg : public Page {
    std::shared_ptr<Dialog> dlg;

    std::string title_;
    std::shared_ptr<Page> reqList;
    std::optional<PgSwitch::PgBack> frozen;
    Focus onFrozen;

  public:
    PgDlg(std::string title_, std::shared_ptr<Dialog> dlg);

    void handle(std::string cmd, Focus &f) override;

    std::string page() const override;

    std::string title() const override;
};
