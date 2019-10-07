#include "ApprovalTests.hpp"
#include "Catch.hpp"
#include "FakeCustomFile.h"

struct WriteHeaders
{
    explicit WriteHeaders(const custom_file& test_file) : test_file(test_file)
    {
    }

    const custom_file& test_file;

    friend std::ostream &operator<<(std::ostream &os, const WriteHeaders& wrapper) {
        os << "size:    " << wrapper.test_file.size() << '\n';
        os << "header1: " << wrapper.test_file.header1 << '\n';
        os << "header2: " << wrapper.test_file.header2 << '\n';
        return os;
    }
};

TEST_CASE( "header fields are correct - with adaptor to write headers", "[header]" )
{
    using namespace ApprovalTests;
    custom_file big_file{"filename"};
    Approvals::verify( WriteHeaders(big_file) );
}
