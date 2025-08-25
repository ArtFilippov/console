#pragma once
#include "Page/PgScroll.h"
#include "Page/PgBase.h"
#include "common/common.h"

using namespace console;

class PageFactory {
    std::shared_ptr<Page> base;

  public:
    PageFactory(std::shared_ptr<Page> base) : base(base) {}

    std::shared_ptr<Page> pureScroll() { return snew<PgScroll>("_", "", "", base, 10); }
};
