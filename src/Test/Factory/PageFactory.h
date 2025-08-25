#pragma once
#include "Page/PgScroll.h"
#include "Page/PgSlice.h"
#include "Page/PgBase.h"
#include "Page/PgSwitch.h"
#include "common/common.h"

using namespace console;

class PageFactory {
    std::shared_ptr<Page> base;

  public:
    PageFactory(std::shared_ptr<Page> base) : base(base) {}

    PageFactory() : PageFactory(snew<PgBase>("_", "")) {}

    std::shared_ptr<Page> pureScroll() { return snew<PgScroll>("_", "", "", base, 10); }

    std::shared_ptr<Page> pureSlice(int from, int to) { return snew<PgSlice>("_", from, to, base); }

    std::shared_ptr<Page> pureSwitch(int pgNum) {
        std::vector<std::shared_ptr<Page>> pages;

        for (int i = 0; i < pgNum; ++i) {
            pages.push_back(snew<PgSlice>(std::to_string(i * 10), i * 10, (i + 1) * 10, base));
        }

        Lines::instance().update(10);

        return snew<PgSwitch>(base->title(), pages);
    }

    std::shared_ptr<Page> nums() {
        std::string n;

        for (int i = 0; i < 1000; ++i) {
            n += std::to_string(i) + '\n';
        };

        return snew<PgBase>("nums", n);
    }
};
