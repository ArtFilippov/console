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
        "_",
        title_,
        "enter page: ",
        snew<PgBase>(
            "_",
            options
        ),
        Lines::instance().lines()
    );
    // clang-format on
    pages.emplace_back(mainPg);
    for (auto pg : pgs) {
        pages.emplace_back(pg);
    }
}

void PgSwitch::handle(std::string cmd, Focus &onMe) {
    if (onMe) {
        std::size_t newPgIt = static_cast<std::size_t>(common::stoi(cmd).value_or(pgIt));
        if (newPgIt < pages.size() && newPgIt > 0) {
            pgIt = newPgIt;
        }

        if (pgIt != 0) {
            onMyPages = std::move(onMe);
        }

        return;
    }

    pages[pgIt].handle(cmd, onMyPages);
    onMe = std::move(onMyPages);

    if (onMe) {
        pgIt = 0;
    }
}

std::string PgSwitch::page() const { return pages[pgIt].page(); }

std::string PgSwitch::title() const { return title_; }
