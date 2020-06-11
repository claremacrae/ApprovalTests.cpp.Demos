#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

using namespace ApprovalTests;

TEST_CASE("UseSpecificReporter")
{
    Approvals::verify(
        "Some\nMulti-line\noutput",
        Options(Windows::AraxisMergeReporter{}));
}

TEST_CASE("UseCustomReporter")
{
    Approvals::verify("Some\nMulti-line\noutput",
        Options(GenericDiffReporter(
            R"(C:\Program Files\TortoiseHg\lib\kdiff3.exe)")));
}

TEST_CASE("UseQuietReporter")
{
    // QuietReporter does nothing if a failure occurs.
    // It may be useful for running on build servers, where starting
    // a graphical diff tool for human inspection is not appropriate.
    // Failing tests will still fail, but nothing will be launched.
    Approvals::verify(
        "Some\nMulti-line\noutput",
        Options(QuietReporter{}));
}