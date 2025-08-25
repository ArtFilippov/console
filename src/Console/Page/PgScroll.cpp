#include "PgScroll.h"
#include "PgSlice.h"

#include "common/common.h"
#include <sstream>

using namespace console;

PgScroll::PgScroll(std::string title_, std::string top, std::string bottom, std::shared_ptr<Page> body,
                   std::size_t lines)
    : title_(title_), top(top), bottom(bottom), body(body), lines(lines), endLine(lines),
      bodyLines(common::linesOf(body->page())) {}

void PgScroll::handle(std::string cmd, Focus &f) {
    if (!f) {
        body->handle(cmd, f);
        return;
    }

    if (cmd == "s" && endLine < bodyLines) {
        ++endLine;
    } else if (cmd == "w" && endLine > lines) {
        --endLine;
    }
}

std::string PgScroll::page() const {
    auto allBodyLines = common::linesOf(body->page());
    int scroll = bodyLines - common::linesOf(top) - common::linesOf(bottom);
    std::string middle;
    if (scroll > 0) {
        middle = std::make_shared<PgSlice>("_", endLine - lines, endLine, body)->page();
    }
    return top + middle + bottom;
}

std::string PgScroll::title() const { return title_; }
