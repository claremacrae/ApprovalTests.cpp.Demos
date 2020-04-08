#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

using namespace ApprovalTests;

// Approvals test - test static value, for demo purposes
TEST_CASE("TestFixedInput")
{
    Approvals::verify("Some\nMulti-line\noutput");
}
