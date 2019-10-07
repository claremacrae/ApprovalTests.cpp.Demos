#include "ApprovalTests.hpp"
#include "Catch.hpp"
#include "FakeCustomFile.h"

std::ostream &operator<<(std::ostream &os, const custom_file& test_file)
{
    os << "size:    " << test_file.size() << '\n';
    os << "header1: " << test_file.header1 << '\n';
    os << "header2: " << test_file.header2 << '\n';
    return os;
}

TEST_CASE( "header fields are correct - with ostream operator", "[header]" )
{
    using namespace ApprovalTests;
    custom_file big_file{"filename"};
    Approvals::verify(big_file);
}
