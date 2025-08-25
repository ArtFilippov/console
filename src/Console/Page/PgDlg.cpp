#include "PgDlg.h"
#include "PgScroll.h"
#include "PgBase.h"
#include "PgReqSwitch.h"

#include "common/common.h"

using namespace console;

PgDlg::PgDlg(std::string title_, std::shared_ptr<Dialog> dlg)
    : title_(title_), dlg(dlg), reqList(snew<PgScroll>(title_, "", "", snew<PgReqList>(title_, dlg), 50)) {}

void PgDlg::handle(std::string cmd, Focus &onMe) {
    if (onMe) {
        if (cmd == "freeze") {
            onFrozen = std::move(onMe);
            frozen = PgSwitch::PgBack{snew<PgReqSwitch>("frozen " + title_, dlg)};
        }

        return;
    }

    frozen.value().handle(cmd, onFrozen);
    onMe = std::move(onFrozen);

    if (onMe) {
        frozen = {};
    }
}

std::string PgDlg::page() const {
    if (frozen.has_value()) {
        return frozen.value().page();
    }

    return reqList->page();
}

std::string PgDlg::title() const { return title_; }
