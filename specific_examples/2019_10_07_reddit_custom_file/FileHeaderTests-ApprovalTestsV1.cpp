#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"
#include "FakeCustomFile.h"

// The simplest way to use Approval Tests for an object is to write an
// ostream operator.
// This works well if you only ever want to use a single output format
// for all uses of the type.
std::ostream& operator<<(std::ostream& os,
                         const custom_file& test_file)
{
    os << "size:    " << test_file.size() << '\n';
    os << "header1: " << test_file.header1 << '\n';
    os << "header2: " << test_file.header2 << '\n';
    // ... and so on ...
    return os;
}

TEST_CASE("header fields are correct - with ostream operator",
          "[header]")
{
    using namespace ApprovalTests;
    custom_file big_file{"filename"};
    Approvals::verify(big_file);
    // This uses Approval Tests to capture the state of big_file to disk,
    // rather than including all the state in tests in source code.
    //
    // This makes it really easy to add more tests, reading multiple
    // different files, for example.
    //
    // NOTE: The first time this test is run, the test will fail, and
    //       a differencing tool will be shown.
    //       For more information, see
    //       https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/Tutorial.md#top
    //
    // The output ("approved") file gets checked in to source control,
    // along with the corresponding test file.
}
