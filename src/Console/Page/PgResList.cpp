#include "PgResList.h"

#include "common/common.h"

using namespace console;

PgResList::PgResList(std::string title_, std::shared_ptr<Dialog> dlg) : title_(title_), dlg(dlg) {}

void PgResList::handle(std::string cmd, Focus &onMe) {}

std::string PgResList::page() const {
    auto update = [this](const std::vector<data_t> &responses) {
        for (; lastRes < responses.size(); ++lastRes) {
            auto req = responses[lastRes];
            pg += common::print(req->data(), req->size()).str() + '\n';
        }
    };

    dlg->responses(update);

    return pg;
}

std::string PgResList::title() const { return title_; }
