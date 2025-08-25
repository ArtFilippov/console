#include "PgReqSwitch.h"
#include "PgScroll.h"
#include "PgResList.h"
#include "PgBase.h"

#include "common/common.h"

using namespace console;

PgReqSwitch::PgReqSwitch(std::string title_, std::shared_ptr<Dialog> dlg) : title_(title_) {
    std::vector<std::shared_ptr<Page>> pages;
    auto f = [&pages](const std::vector<std::shared_ptr<Dialog>> dialogs) {
        for (auto dlg : dialogs) {
            auto tit = common::print(dlg->request()->data(), dlg->request()->size()).str();

            if (tit.size() > 50) {
                tit = tit.substr(50);
            }

            pages.push_back(snew<PgResList>(tit, dlg));
        }
    };

    dlg->subDialogs(f);

    pg = snew<PgSwitch>(title_, pages);
}

void PgReqSwitch::handle(std::string cmd, Focus &onMe) { pg->handle(cmd, onMe); }

std::string PgReqSwitch::page() const { return pg->page(); }

std::string PgReqSwitch::title() const { return title_; }
