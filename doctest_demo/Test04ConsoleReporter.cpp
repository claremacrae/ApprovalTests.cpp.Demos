#include "ApprovalTests.hpp"
#include "doctest/doctest.h"

using namespace ApprovalTests;

TEST_CASE("UseConsoleReporter" * doctest::should_fail(true))
{
    // The intention of this is to show the text-based diff output next to the
    // output reporting the test failure.
    // However, catch2 separates the two, so that the diff output appears a long
    // way before the FAILED output.
    Approvals::verify("Some\nMulti-line\noutput", Options(TextDiffReporter()));
}
