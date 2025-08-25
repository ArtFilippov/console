#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Page/PgSliceTest.h"
#include "Page/PgScrollTest.h"
#include "Page/PgSwitchTest.h"

int main(int argc, char *argv[]) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
