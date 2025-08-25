#pragma once

#include "Page.h"

#include <memory>
#include <vector>

namespace console {
class PgSwitch;
}

class console::PgSwitch : public Page {

    class PgBack : public Page {
        std::shared_ptr<Page> pg;
        Focus onMe;

      public:
        PgBack(std::shared_ptr<Page> pg) : pg(pg) {}

        void handle(std::string cmd, Focus &f) {
            if (f) {
                onMe = std::move(f);
            }

            if (onMe) {
                if (cmd == "b") {
                    f = std::move(onMe);
                    return;
                } else {
                    pg->handle(cmd, onMe);
                }
            } else {
                pg->handle(cmd, onMe);
            }
        }

        std::string page() const override { return pg->page(); }

        std::string title() const override { return pg->title(); }
    };

    std::string title_;
    std::vector<PgBack> pages;
    std::size_t pgIt{0};
    Focus onMyPages;

  public:
    PgSwitch(std::string title_, std::vector<std::shared_ptr<Page>> pages);

    void handle(std::string cmd, Focus &f) override;

    std::string page() const override;

    std::string title() const override;
};
