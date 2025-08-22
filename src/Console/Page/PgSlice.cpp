#include "PgSlice.h"
#include <sstream>

using namespace console;

PgSlice::PgSlice(std::string title_, int lineFrom, int lineTo, std::shared_ptr<Page> pg)
    : title_(title_), from(lineFrom), to(lineTo), pg(pg) {}

void PgSlice::handle(std::string cmd, Focus &f) { pg->handle(cmd, f); }

std::string PgSlice::page() const {
    std::string original = pg->page();
    std::string window;
    window.reserve(original.size());
    std::istringstream iss(original);
    std::string line;
    for (int i = 0; i < to; ++i) {

        if (i >= from) {
            if (std::getline(iss, line)) {
                window += line;
            } else {
                window += '\n';
            }
        }
    }

    return window;
}

std::string PgSlice::title() const { return title_; }
