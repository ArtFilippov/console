#pragma once

#include "Factory/PageFactory.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class PgSwitchTest : public ::testing::Test {
  protected:
    PgSwitchTest() { fact = PageFactory(snew<PgBase>("nums", fact.nums()->page())); }

    PageFactory fact;
    Focus f{true};
};

TEST_F(PgSwitchTest, SwitchMain) {
    auto pg = fact.pureSwitch(3);
    ASSERT_EQ(pg->page(), "nums\n1 - 0\n2 - 10\n3 - 20\n\n\n\n\n\n\n\nenter page: ");
}

TEST_F(PgSwitchTest, SwitchPage) {
    auto pg = fact.pureSwitch(3);
    pg->handle("1", f);
    ASSERT_EQ(pg->page(), "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n");
}

TEST_F(PgSwitchTest, SwitchBack) {
    auto pg = fact.pureSwitch(3);
    pg->handle("1", f);
    ASSERT_EQ(pg->page(), "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n");
    pg->handle("b", f);
    ASSERT_EQ(pg->page(), "nums\n1 - 0\n2 - 10\n3 - 20\n\n\n\n\n\n\n\nenter page: ");
    pg->handle("2", f);
    ASSERT_EQ(pg->page(), "10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n");
    pg->handle("b", f);
    ASSERT_EQ(pg->page(), "nums\n1 - 0\n2 - 10\n3 - 20\n\n\n\n\n\n\n\nenter page: ");
    pg->handle("3", f);
    ASSERT_EQ(pg->page(), "20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n");
    pg->handle("b", f);
    ASSERT_EQ(pg->page(), "nums\n1 - 0\n2 - 10\n3 - 20\n\n\n\n\n\n\n\nenter page: ");
}

TEST_F(PgSwitchTest, SwitchNestedBack) {
    auto pg3 = PageFactory{snew<PgBase>("pg3", "")}.pureSwitch(3);
    auto pg2 = PageFactory{snew<PgBase>("pg2", "")}.pureSwitch(2);
    auto pg1 = PageFactory{snew<PgBase>("pg1", "")}.pureSwitch(1);
    auto pg = snew<PgSwitch>("_", std::vector<std::shared_ptr<Page>>{pg1, pg2, pg3});

    ASSERT_EQ(pg->page(), "_\n1 - pg1\n2 - pg2\n3 - pg3\n\n\n\n\n\n\n\nenter page: ");
    pg->handle("1", f);
    ASSERT_EQ(pg->page(), "pg1\n1 - 0\n\n\n\n\n\n\n\n\n\nenter page: ");
    pg->handle("1", f);
    ASSERT_EQ(pg->page(), "\n\n\n\n\n\n\n\n\n\n");
    pg->handle("b", f);
    ASSERT_EQ(pg->page(), "pg1\n1 - 0\n\n\n\n\n\n\n\n\n\nenter page: ");
    pg->handle("b", f);
    ASSERT_EQ(pg->page(), "_\n1 - pg1\n2 - pg2\n3 - pg3\n\n\n\n\n\n\n\nenter page: ");
}
