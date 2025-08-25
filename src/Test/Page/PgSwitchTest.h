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
    ASSERT_EQ(pg->page(), "nums\n1 - 0\n2 - 10\n3 - 20\n\n\n\n\n\n\n\nenter page: \n");
}
