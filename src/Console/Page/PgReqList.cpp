#include "PgReqList.h"

#include "common/common.h"

using namespace console;

PgReqList::PgReqList(std::string title_, std::shared_ptr<Dialog> dlg) : title_(title_), dlg(dlg) {}

void PgReqList::handle(std::string, Focus &) {}

std::string PgReqList::page() const {
    auto update = [this](const std::vector<std::shared_ptr<Dialog>> &dialogs) {
        for (; lastReq < dialogs.size(); ++lastReq) {
            auto req = dialogs[lastReq]->request();
            pg += common::print(req->data(), req->size()).str() + '\n';
        }
    };

    dlg->subDialogs(update);

    return pg;
}

std::string PgReqList::title() const { return title_; }
