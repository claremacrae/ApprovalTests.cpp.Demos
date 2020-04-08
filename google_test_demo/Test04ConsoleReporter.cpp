#include "ApprovalTests.hpp"
#include <gtest/gtest.h>

using namespace ApprovalTests;

TEST(Test04, DISABLED_DUE_TO_INTENTIONAL_FAILURE_UseConsoleReporter)
{
    Approvals::verify("Some\nMulti-line\noutput", TextDiffReporter());
}
