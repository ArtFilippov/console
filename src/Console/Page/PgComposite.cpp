#include "PgComposite.h"

#include <sstream>

using namespace console;

PgComposite::PgComposite(std::string title_, std::initializer_list<std::shared_ptr<Page>> pages)
    : title_(title_), pages(pages) {}

void PgComposite::handle(std::string cmd, Focus &f) {
    for (auto pg : pages) {
        pg->handle(cmd, f);
    }
}

std::string PgComposite::page() const {
    std::string window;

    for (auto pg : pages) {
        window += pg->page();
    }

    return window;
}

std::string PgComposite::title() const { return title_; }
