#include "PgScroll.h"
#include "PgSlice.h"

#include "common/common.h"
#include <sstream>

using namespace console;

PgScroll::PgScroll(std::string title_, std::string top_, std::string bottom_, std::shared_ptr<Page> body,
                   std::size_t lines)
    : title_(title_), top(top_), bottom(bottom_), body(body), lines(lines), endLine(lines) {
    if (!top.empty()) {
        top += '\n';
    }

    if (!bottom.empty()) {
        bottom += '\n';
    }
}

void PgScroll::handle(std::string cmd, Focus &f) {
    if (!f) {
        body->handle(cmd, f);
        return;
    }

    if (cmd == "s" && endLine < common::linesOf(body->page())) {
        ++endLine;
    } else if (cmd == "w" && endLine > lines) {
        --endLine;
    }
}

std::string PgScroll::page() const {
    auto allBodyLines = common::linesOf(body->page());
    int scroll = static_cast<int>(allBodyLines - common::linesOf(top) - common::linesOf(bottom));

    std::string middle;
    if (scroll > 0) {
        middle = std::make_shared<PgSlice>("_", endLine - lines, endLine, body)->page();
    }
    return top + middle + bottom;
}

std::string PgScroll::title() const { return title_; }
