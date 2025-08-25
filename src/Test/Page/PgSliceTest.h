#pragma once

#include "Page/PgSlice.h"
#include "Factory/PageFactory.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class PgSliceTest : public ::testing::Test {
  protected:
    PgSliceTest() { fact = PageFactory(snew<PgBase>("nums", fact.nums()->page())); }

    PageFactory fact;
    Focus f{true};
};

TEST_F(PgSliceTest, SliceBegin) {
    auto pg = fact.pureSlice(0, 10);
    ASSERT_EQ(pg->page(), "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n");
}

TEST_F(PgSliceTest, SliceNext) {
    auto pg = fact.pureSlice(1, 11);
    ASSERT_EQ(pg->page(), "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n") << "slice = " << pg->page();
}
