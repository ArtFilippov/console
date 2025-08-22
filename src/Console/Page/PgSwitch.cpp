#include "PgSwitch.h"
#include "PgScroll.h"
#include "PgBase.h"

#include "common/common.h"

using namespace console;

PgSwitch::PgSwitch(std::string title_, std::vector<std::shared_ptr<Page>> pgs) : title_(title_) {
    std::string options;
    for (std::size_t i = 0; i < pgs.size(); ++i) {
        options += std::to_string(i + 1) + " - " + pgs[i]->title() + '\n';
    }
    // clang-format off
    auto mainPg = snew<PgScroll>(
        title_,
        "enter page: ",
        snew<PgBase>(
            options
        ),
        50
    );
    // clang-format on

    pages.push_back(mainPg);
    pages.insert(pages.end(), pgs.begin(), pgs.end());
}

void PgSwitch::handle(std::string cmd, Focus &f) {
    my = std::move(f);

    if (my) {
        if (cmd == "b") {
            pgIt = 0;
            return;
        } else {
            pgIt = common::stoi(cmd).value_or(pgIt);
            return;
        }
    }

    if (pgIt == 0) {
        pgIt = common::stoi(cmd).value_or(pgIt);
    } else {
        pages[pgIt]->handle(cmd);
    }
}

std::string PgSwitch::page() const { return pages[pgIt]->page(); }

std::string PgSwitch::title() const { return title_; }
