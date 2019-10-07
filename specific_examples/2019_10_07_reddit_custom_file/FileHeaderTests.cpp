#include "ApprovalTests.hpp"
#include "Catch.hpp"
#include "FakeCustomFile.h"

TEST_CASE( "header fields are correct", "[header]" ){
    custom_file big_file{"filename"};
    REQUIRE(big_file.size() == "100MB");

    SECTION("header1 should be 42") {
        REQUIRE(big_file.header1 == 42);
    }

    SECTION("header2 should be FOO") {
        REQUIRE(big_file.header2 == "FOO");
    }
}

//std::ostream &operator<<(std::ostream &os, const custom_file& test_file)
//{
//    os << "size:    " << test_file.size() << '\n';
//    os << "header1: " << test_file.header1 << '\n';
//    os << "header2: " << test_file.header2 << '\n';
//    return os;
//}
//
//TEST_CASE( "header fields are correct - with Approval Tests 1", "[header]" )
//{
//    using namespace ApprovalTests;
//    custom_file big_file{"filename"};
//    Approvals::verify(big_file);
//}

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

TEST_CASE( "header fields are correct - with Approval Tests 2", "[header]" )
{
    using namespace ApprovalTests;
    custom_file big_file{"filename"};
    Approvals::verify( WriteHeaders(big_file) );
}

void verify_custom_file_headers(const std::string& filename)
{
    using namespace ApprovalTests;
    custom_file big_file{"filename"};
    Approvals::verify( WriteHeaders(big_file) );
}

TEST_CASE( "header fields are correct - with Approval Tests 3", "[header]" )
{
    verify_custom_file_headers("filename");
}
