#pragma once

#include "Page/PgScroll.h"
#include "Factory/PageFactory.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class PgScrollTest : public ::testing::Test {
  protected:
    PgScrollTest() {
        std::string nums;

        for (int i = 0; i < 1000; ++i) {
            nums += std::to_string(i) + '\n';
        };

        fact = std::make_unique<PageFactory>(snew<PgBase>("nums", nums));
    }

    std::unique_ptr<PageFactory> fact;
    Focus f{true};
};

TEST_F(PgScrollTest, Page) {
    auto pg = fact->pureScroll();
    ASSERT_EQ(pg->page(), "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n");
}

TEST_F(PgScrollTest, Scroll) {
    auto pg = fact->pureScroll();
    ASSERT_EQ(pg->page()[0], '0');
    pg->handle("s", f);
    ASSERT_EQ(pg->page()[0], '1');
    pg->handle("s", f);
    ASSERT_EQ(pg->page()[0], '2');
    pg->handle("w", f);
    ASSERT_EQ(pg->page()[0], '1');
}
