#include "ApprovalTests.hpp"
#include "Catch.hpp"
#include "FakeCustomFile.h"

// This extends the previous version, this time including the file name in 
// the text being verified, which would be useful if testing the reading
// of multiple files.
struct WriteHeaders
{
    explicit WriteHeaders(
        const std::string& filename,
        const custom_file& test_file) : filename(filename), test_file(test_file)
    {
    }

    const std::string& filename;
    const custom_file& test_file;

    friend std::ostream &operator<<(std::ostream &os, const WriteHeaders& wrapper) {
        os << "filename: " << wrapper.filename << '\n';
        os << "size:     " << wrapper.test_file.size() << '\n';
        os << "header1:  " << wrapper.test_file.header1 << '\n';
        os << "header2:  " << wrapper.test_file.header2 << '\n';
        // ... and so on ...
        return os;
    }
};

// In this version, we provide a helper function that takes a file name,
// reads it, and verifies it.
// This aids readability of the test, and makes it easier to test
// multiple files.
void verify_custom_file_headers(const std::string& filename)
{
    using namespace ApprovalTests;
    custom_file big_file{filename};
    Approvals::verify( WriteHeaders(filename, big_file) );
}

TEST_CASE( "header fields are correct - with function to test headers", "[header]" )
{
    verify_custom_file_headers("filename");
}

// As an extension to this, you could write multiple different tests,
// each reading a different file.
// Or you could make this one test read multiple files, using one of the 
// approaches in:
//      https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/MultipleOutputFilesPerTest.md#top
