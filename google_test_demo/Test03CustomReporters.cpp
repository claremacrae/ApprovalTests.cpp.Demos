#include "ApprovalTests.hpp"
#include <gtest/gtest.h>

using namespace ApprovalTests;

TEST(Test03, UseSpecificReporter)
{
    Approvals::verify(
        "Some\nMulti-line\noutput", Options(Windows::AraxisMergeReporter{}));
}

TEST(Test03, UseCustomReporter)
{
    Approvals::verify("Some\nMulti-line\noutput",
        Options(GenericDiffReporter(
            "C:\\Program Files\\TortoiseHg\\lib\\kdiff3.exe")));
}
